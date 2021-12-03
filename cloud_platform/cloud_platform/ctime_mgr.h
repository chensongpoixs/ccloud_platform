/***********************************************************************************************
			created: 		2019-05-06

			author:			chensong

			purpose:		ctime_mgr
************************************************************************************************/


#ifndef _C_TIME_MGR_H_
#define _C_TIME_MGR_H_

#include "cnoncopyable.h"
namespace chen {
	class ctime_mgr :private cnoncopyable
	{
	public:
		explicit ctime_mgr();
		~ctime_mgr();
	public:
		bool init();
		void destroy();
	};
	extern ctime_mgr g_timer_mgr;
}//namespace chen 

#endif //!#define _C_TIME_MGR_H_