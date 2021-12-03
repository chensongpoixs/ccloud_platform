/***********************************************************************************************
				created: 		2019-05-06

				author:			chensong

				purpose:		gateway_server
************************************************************************************************/

#ifndef _C_GATEWAY_SERVER_H_
#define _C_GATEWAY_SERVER_H_
#include "cnoncopyable.h"
namespace chen {
	class cgeteway_server :private cnoncopyable
	{
	public:
		explicit cgeteway_server();
		~cgeteway_server();
	public:
		bool init(const char * log_path,const char *config_file);
		bool Loop();
		void destroy();
		void stop();
	private:
		volatile bool m_stop;
	};
	extern cgeteway_server g_cgeteway_server;
}//namespace chen
#endif // !#define _C_SELECT_PROACTOR_SERVER_H_