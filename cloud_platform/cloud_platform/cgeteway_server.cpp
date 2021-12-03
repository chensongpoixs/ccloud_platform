/***********************************************************************************************
			created: 		2019-05-06

			author:			chensong

			purpose:		cgeteway_server
************************************************************************************************/
#include "cgeteway_server.h"
#include "clog.h"
#include "ccfg.h"
#include "ctime_api.h"
#include "ctime_mgr.h"
#include "cwan_server.h"
 
#include "ctime_elapse.h"
#include "clib_util.h"
#include <array>
#include <random>
#include <array>
#include <string>
#include <iostream>
#include <algorithm> //std::generate_n
#include <type_traits>// std::ref
#include <functional>  // std::ref



 
namespace chen {

	


	cgeteway_server g_cgeteway_server;

	cgeteway_server::cgeteway_server() 
		: m_stop(false)
	{
	}
	cgeteway_server::~cgeteway_server()
	{
	}
	bool cgeteway_server::init(const char * log_path, const char *config_file)
	{
		printf("Log init ...\n");
		if (!LOG::init(log_path, "cgeteway"))
		{
			return false;
		}
		if (!g_cfg.init(config_file))
		{
			return false;
		}

		ctime_base_api::set_time_zone(g_cfg.get_int32(ECI_TimeZone));
		ctime_base_api::set_time_adjust(g_cfg.get_int32(ECI_TimeAdjust));

		if (!g_timer_mgr.init())
		{
			return false;
		}
		if (!g_wan_server.init())
		{
			return false;
		}

		if (!g_wan_server.startup())
		{
			return false;
		}
		SYSTEM_LOG("cgeteway_server init ok");

		return true;
	}
	bool cgeteway_server::Loop()
	{
		static const unsigned int TICK_TIME = 100;


		ctime_elapse time_elapse;
		unsigned int uDelta = 0;
		while (!m_stop)
		{
			uDelta += time_elapse.get_elapse();

			g_wan_server.update(uDelta);

			uDelta = time_elapse.get_elapse();

			if (uDelta < TICK_TIME)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(TICK_TIME - uDelta));
				//csleep(TICK_TIME - uDelta);
			}
			
		}
	
		SYSTEM_LOG("Leave main loop");
		return true;
	}
	void cgeteway_server::destroy()
	{
		//g_wan_server.destroy();
		//g_cfg.destroy();
		//LOG::destroy();


		/*g_wan_server.shutdown();
		g_wan_server.destroy();*/
		SYSTEM_LOG("g_wan_server Destroy OK!");
		g_cfg.destroy();

		//1 log
		LOG::destroy();
		printf("Log Destroy OK!\n");

		printf("cgeteway_server Destroy End\n");

	}
	void cgeteway_server::stop()
	{
		m_stop = true;
	}
} // namespace chen