/***********************************************************************************************
				created: 		2019-04-30

				author:			chensong

				purpose:		wan_server

************************************************************************************************/

#ifndef _C_WAN_SERVER_H_
#define _C_WAN_SERVER_H_
#include "cnoncopyable.h"
#include "cnet_types.h"
#include "cnet_mgr.h"
#include "cwan_session.h"
namespace chen {
	class cwan_server : private cnoncopyable
	{
	public:
		cwan_server();
		~cwan_server();

	public:
		bool init();

		void destroy();
	public:
		bool startup();
	public: 
		void update(uint32 uDeltaTime);
		void shutdown();
	public:
		void on_connect(uint32 session_id, uint32 para, const char* buf);
		void on_msg_receive(cnet_msg &msg_ptr);
		void on_disconnect(uint32 session_id);
	public:
		void send_msg(uint32 session_id, uint16 msg_id, const void *p, uint32 size);
	public:
	
		cwan_session* get_session(uint32 index);
		cwan_session*  get_session(uint32 index, uint32 session_id);
	public:
		/**
		* 关闭指定连接
		* @param session_id	连接id
		*/
		void close(uint32 session_id);
	private:
		bool index_valid(uint32 index) { return index < m_max_session_num; }
	private:
		cnet_mgr	*				m_net_ptr;
//		bool						m_stoped;
		uint32						m_max_session_num;
		cwan_session*				m_session_ptr;
		uint32						m_update_timer;
	};
	extern cwan_server   g_wan_server;
}//namespace chen 
#endif // !#define _C_WAN_SERVER_H_