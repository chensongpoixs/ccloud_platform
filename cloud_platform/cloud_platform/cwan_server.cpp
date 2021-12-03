/***********************************************************************************************
			created: 		2019-04-30

			author:			chensong

			purpose:		wan_server

************************************************************************************************/

#include "cwan_server.h"
#include "clog.h"
#include "ccfg.h"
namespace chen {
	cwan_server   g_wan_server;
	cwan_server::cwan_server() 
		: m_net_ptr(NULL)
//		, m_stoped(false)
		, m_max_session_num(0)
		, m_session_ptr(NULL)
		, m_update_timer(0)
	{
	}
	cwan_server::~cwan_server()
	{
	}
	bool cwan_server::init()
	{
		m_net_ptr = cnet_mgr::construct();
		if (!m_net_ptr)
		{
			ERROR_EX_LOG("new cnet_mgr fail");
			return false;
		}
		m_max_session_num = g_cfg.get_uint32(ECI_WanClientMaxNum);

		const uint32 recv_buf_size = g_cfg.get_uint32(ECI_WanInputBufSize);
		const uint32 send_buf_size = g_cfg.get_uint32(ECI_WanOutputBufSize);
		if (!m_net_ptr->init("cgateway", 0, m_max_session_num, send_buf_size, recv_buf_size))
		{
			return false;
		}

		m_net_ptr->set_connect_callback(
			std::bind(&cwan_server::on_connect, this, std::placeholders::_1, std::placeholders::_2
				, std::placeholders::_3)
		);

		m_net_ptr->set_msg_callback(
			std::bind(&cwan_server::on_msg_receive, this, std::placeholders::_1)
		);

		m_net_ptr->set_disconnect_callback(
			std::bind(&cwan_server::on_disconnect, this, std::placeholders::_1)
		);

		m_session_ptr = new cwan_session[m_max_session_num];
		if (!m_session_ptr)
		{
			ERROR_EX_LOG("new faild session max num =%lu", m_max_session_num);
			return false;
		}

		for (uint32 i = 0; i < m_max_session_num; ++i)
		{
			m_session_ptr[i].init();
		}
		return true;
	}
	void cwan_server::destroy()
	{
		if (m_session_ptr)
		{
			for (uint32 i = 0; i < m_max_session_num; ++i)
			{
				m_session_ptr[i].destroy();
			}
			delete[] m_session_ptr;
			m_session_ptr = NULL;
		}
		if (m_net_ptr)
		{
			m_net_ptr->destroy();
			if (m_net_ptr)
			{
				cnet_mgr::destroy( m_net_ptr);
				m_net_ptr = NULL;
			}
			
		}
		m_max_session_num = 0;
	}
	bool cwan_server::startup()
	{
		if (!m_net_ptr)
		{
			return false;
		}
		if (!m_net_ptr->startup(1, g_cfg.get_string(ECI_WanIp).c_str(), g_cfg.get_uint16(ECI_WanPort)))
		{
			return false;
		}
		return true;
	}
	void cwan_server::update(uint32 uDeltaTime)
	{
		static const uint32 UPDATE_TIMER = 15 * 1000;

		m_net_ptr->process_msg();

		m_update_timer += uDeltaTime;

		if (m_update_timer >= UPDATE_TIMER)
		{
			m_update_timer -= UPDATE_TIMER;

			for (uint32 i = 0; i < m_max_session_num; ++i)
			{
				if (m_session_ptr[i].is_used())
				{
					m_session_ptr[i].update(UPDATE_TIMER);
				}
			}
			if (m_net_ptr)
			{
				//m_net_ptr->show_info();
			}
		}
		
	}
	void cwan_server::shutdown()
	{
		if (m_net_ptr)
		{
			m_net_ptr->shutdown();
		}
	}
	void cwan_server::on_connect(uint32 session_id, uint32 para, const char * buf)
	{
		m_session_ptr[session_id].is_used();
		DEBUG_LOG("connect session_id = %lu", session_id);
	}
	void cwan_server::on_msg_receive(cnet_msg &msg_ptr)
	{
		DEBUG_LOG("recv session_id = %u, msg_id =%u,  size = %u data = %s", msg_ptr.get_session_id(), msg_ptr.get_msg_id(), msg_ptr.get_size(), msg_ptr.get_buf());
		send_msg(msg_ptr.get_session_id(), msg_ptr.get_msg_id(), msg_ptr.get_buf(), msg_ptr.get_size());
		//	  static char* buf_ptr =  NULL;
//	   if (!buf_ptr)
//	   {
//		   //ERROR_EX_LOG("alloc failed ");
//		   buf_ptr = new  char[10000];
//		   if (!buf_ptr)
//		   {
//			   return;
//		   }
//	   }
//  //    //  DEBUG_LOG("send size = %u", sizeof(buf));
//	 //  // memset(buf, 0XFF, sizeof(buf));
//		send_msg(msg_ptr.get_session_id(), 100, buf_ptr, 10000);
//	   m_net_ptr->show_info();
	}
	void cwan_server::on_disconnect(uint32 session_id)
	{
		DEBUG_LOG("disconnect session_id = %lu", session_id);
	}

	void cwan_server::send_msg(uint32 session_id, uint16 msg_id, const void * p, uint32 size)
	{
		if (!m_net_ptr->send_msg(session_id, msg_id,  p, size))
		{
			WARNING_LOG("send session_id = %u", session_id);
		}
	}

	cwan_session * cwan_server::get_session(uint32 index)
	{
		if (!index_valid(index))
		{
			ERROR_LOG("[%s] invalid session index, index = %u", __FUNCTION__, index);
			return NULL;
		}

		return &(m_session_ptr[index]);
	}

	cwan_session * cwan_server::get_session(uint32 index, uint32 session_id)
	{
		if (!index_valid(index))
		{
			ERROR_LOG("[%s] invalid session index, index = %u, session id = %u", __FUNCTION__, index, session_id);
			return NULL;
		}

		if (m_session_ptr[index].get_session_id() != session_id)
		{
			return NULL;
		}


		return &(m_session_ptr[index]);
	}

	void cwan_server::close(uint32 session_id)
	{
		if (m_net_ptr)
		{
			m_session_ptr[session_id].close();
		}
	}
	
}//namespace chen 