/********************************************************************
				created:	2019-05-07

				author:		chensong

				level:		网络层

				purpose:	网络数据的收发
*********************************************************************/
#include "cwan_session.h"

namespace chen {
	cwan_session::cwan_session()
		:m_session_id(0)
	{
	}
	cwan_session::~cwan_session()
	{
	}
	bool cwan_session::init()
	{
		return true;
	}
	void cwan_session::destroy()
	{
	}
	void cwan_session::update(uint32 uDeltaTime)
	{
	}
	void cwan_session::close()
	{
	}
	bool cwan_session::is_used()
	{
		return true;
	}
}//namespace chen
