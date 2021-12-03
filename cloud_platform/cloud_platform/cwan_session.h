/********************************************************************
			created:	2019-05-07

			author:		chensong

			level:		网络层

			purpose:	网络数据的收发
*********************************************************************/


#ifndef _C_WAN_SESSION_H_
#define _C_WAN_SESSION_H_
#include "cnoncopyable.h"
#include "cnet_types.h"
namespace chen {
	class cwan_session :private cnoncopyable
	{
	public:
		explicit cwan_session();
		~cwan_session();
	public:
		bool init();
		void destroy();
	public:
		void update(uint32 uDeltaTime);
	public:
		uint32 get_session_id() const { return m_session_id; }
		void	set_session_id(uint32 session_id) { m_session_id = session_id; }
		void	close();
	public:
		bool is_used();
	private:
		uint32					m_session_id; //会话id
	};
}//namespace chen

#endif // !#define _C_WAN_SESSION_H_