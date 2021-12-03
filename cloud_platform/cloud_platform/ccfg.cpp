/***********************************************************************************************
				created: 		2019-05-01

				author:			chensong

				purpose:		ccfg
************************************************************************************************/
#include "ccfg.h"

namespace chen {
	ccfg g_cfg;
	
	ccfg::ccfg()
	{
	}


	ccfg::~ccfg()
	{
	}
	bool ccfg::init(const char * file_name)
	{
		if (!cconfig::init(ECI_Max, file_name))
		{
			return false;
		}
		// 默认值
		 
		set_int32(ECI_TimeZone, "time_zone", 8);
		set_int32(ECI_TimeAdjust, "time_adjust", 0);
		//Wan
		set_uint32(ECI_WanClientMaxNum, "wan_client_max_num", 64);
		//单位 MB
		set_uint32(ECI_WanInputBufSize, "wan_input_buf_size", 10 * 1024);
		//单位 MB
		set_uint32(ECI_WanOutputBufSize, "wan_output_buf_size", 20  * 1024);

		set_string(ECI_WanIp, "wan_ip", "0.0.0.0");
		set_uint16(ECI_WanPort, "wan_port", 8001);
		//配置表的值
		load_cfg_file();

		return true;
	}
	void ccfg::destroy()
	{
		cconfig::destroy();
	}
}//namespace chen 
