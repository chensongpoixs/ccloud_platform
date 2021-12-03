/***********************************************************************************************
				created: 		2019-05-06

				author:			chensong

				purpose:		ctime_mgr
************************************************************************************************/

#include "ctime_mgr.h"
//#include <openssl/evp.h>
//#include <openssl/ssl.h>
//#include <openssl/md5.h>
//#include <openssl/sha.h>
//#include <openssl/hmac.h>
//#include <openssl/rand.h>
//#include <openssl/evp.h>
//#include <openssl/aes.h>
namespace chen {
	ctime_mgr g_timer_mgr;

	ctime_mgr::ctime_mgr()
	{
	
		
	}
	ctime_mgr::~ctime_mgr()
	{
	}
	bool ctime_mgr::init()
	{
		return true;
	}
	void ctime_mgr::destroy()
	{
	}
} //namespace chen
