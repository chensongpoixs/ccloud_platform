/***********************************************************************************************
				created: 		2019-05-12

				author:			chensong

				purpose:		palyer
************************************************************************************************/


#ifndef _C_PLAYER_H_
#define _C_PLAYER_H_
#include "cnoncopyable.h"
#include "cnet_types.h"
#include "ccmd_param.h"
//#include "csession.h"
//#include "cmgr_base.h"
#include <google/protobuf/message_lite.h>
//#include "cfriend_circle_table_mgr.h" //头文件在包含顺序上不要成闭合的环状，他们结构顺序最好应该是树。
namespace chen {
	class csession;   //告诉编译编译器 要先编译clan_session文件再编译cplayer
	//class cmgr_base;
	class cfriend_circle_table_mgr; // C++ 里面编译是比较奇葩的事情
	class ctest_case_mgr;
	class cmatch_game_mgr;
	class cplayer : private cnoncopyable
	{
	public:
		explicit cplayer();
		~cplayer();
	public:
		bool init(csession *lan_session_ptr, uint32 index);
		void destroy();
		void update(uint32 msleep);
	public:
		void reset();

		void on_logined(const std::string &user_name, int32 score, const std::string& token , int32 uid, uint32 login_session_id);
	
	public:
		uint32 get_player_id() const { return m_web_user_id; }
		std::string get_player_name() {
			return m_user_name;
		};
        const std::string get_player_name() const {
            return m_user_name;
        };
	public:
		//得到玩家id
		const uint32 get_session_id() const { return m_session_index; }
		const csession * get_session() const {return m_session_ptr;}
        csession * get_session()  {return m_session_ptr;}
	public:
		/*cfriend_circle_table_mgr* get_friend_circle_table_mgr() { return (cfriend_circle_table_mgr*)(m_mgrs[MGR_FIRENDCIRCLE]); }
		cmatch_game_mgr* get_match_game_mgr() { return (cmatch_game_mgr*)(m_mgrs[MGR_MATCH_GAME]); }
		ctest_case_mgr* get_test_case_mgr() { return (ctest_case_mgr*)(m_mgrs[MGR_TEST_CASE]); }*/
		
	public:
		/*const cfriend_circle_table_mgr* get_friend_circle_table_mgr() const { return (const cfriend_circle_table_mgr*)(m_mgrs[MGR_FIRENDCIRCLE]); }
		const cmatch_game_mgr* get_match_game_mgr()const { return (const cmatch_game_mgr*)(m_mgrs[MGR_MATCH_GAME]); }
		const ctest_case_mgr* get_test_case_mgr() const  { return (const ctest_case_mgr*)(m_mgrs[MGR_TEST_CASE]); }*/
	public:
		bool send_msg(uint16_t msg_id, const ::google::protobuf::MessageLite& msg) const;
		bool send_msg(uint16 msg_id, const ::google::protobuf::MessageLite& msg, int32 match_id);
		bool send_gm(const char* buf) const;
		void on_msg(uint16_t msg_id, int32 result);
	public:
		void 	handle_code(const void* packet, uint32 msg_size);
		//void	handle_announce(const void* packet, uint32 msg_size);
		//void	handle_breatheart(const void* packet, uint32 msg_size);
		//void    handle_login(const void *packet, uint32 msg_size);
		//void	handle_match_list(const void *packet, uint32 msg_size);
		//void	handle_player_joinlist(const void *packet, uint32 msg_size);
		//void	handle_match_run_list(const void *packet, uint32 msg_size);
		//
		//// friend circle
		//void	handle_create_table(const void *packet, uint32 msg_size);
		//void	handle_delete_table(const void *packet, uint32 msg_size);
		//void    handle_modify_table(const void *packet, uint32 msg_size);


		//// game
		//void	handle_join_table(const void *packet, uint32 msg_size);
		//void	handle_leave_table(const void *packet, uint32 msg_size);

		//// game logic
		//void	handle_game_info(const void *packet, uint32 msg_size);
		//void	handle_game_timer_info(const void *packet, uint32 msg_size);
		//void	handle_game_bonus(const void *packet, uint32 msg_size);
		//void	handle_game_action(const void *packet, uint32 msg_size);
		//void	handle_game_player_ranking(const void *packet, uint32 msg_size);
		//void	handle_game_show_hand_card(const void *packet, uint32 msg_size);
		//void	handle_match_add_chip(const void *packet, uint32 msg_size);
		//void    handle_match_free_signup_num(const void *packet, uint32 msg_size);
		//void	handle_game_lookon(const void *packet, uint32 msg_size);
		//void	handle_game_player_back_chair(const void *packet, uint32 msg_size);
		//void	handle_game_add_score(const void *packet, uint32 msg_size);
		//void    handle_game_add_operationtimes(const void *packet, uint32 msg_size);
  //      void    handle_game_lookon_players(const void *packet, uint32 msg_size);
  //      void    handle_match_game_device(const void *packet, uint32 msg_size);
		////        void    handle_game_player_operationtimes(const void *packet, uint32 msg_size);

		//void	handle_match_info_update_notify(const void *packet, uint32 msg_size);
		//void	handle_ante_blind_change_notify(const void *packet, uint32 msg_size);
		//void	handle_match_start_notify(const void *packet, uint32 msg_size);
		//void	handle_match_finish_notify(const void *packet, uint32 msg_size);
		//void	handle_match_wait_notify(const void *packet, uint32 msg_size);
		//void	handle_match_result_notify(const void *packet, uint32 msg_size);
		//void	handle_match_cancle_notify(const void *packet, uint32 msg_size);
		//void	handle_match_status_change_notify(const void *packet, uint32 msg_size);
		//void	handle_match_add_chip_notify(const void * packet, uint32 msg_size);
		//void	handle_game_ready_start_notify(const void *packet, uint32 msg_size);
		//void	handle_game_start_notify(const void *packet, uint32 msg_size);
		//void	handle_game_flop_cards_notify(const void *packet, uint32 msg_size);
		//void	handle_game_turn_cards_notify(const void *packet, uint32 msg_size);
		//void	handle_game_river_cards_notify(const void *packet, uint32 msg_size);
		//void	handle_game_user_action_notify(const void *packet, uint32 msg_size);
		//void	handle_game_user_handcard_notify(const void *packet, uint32 msg_size);
		//void	handle_game_end_info_notify(const void *packet, uint32 msg_size);
		//void	handle_game_show_hand_card_notify(const void *packet, uint32 msg_size);
		//void	handle_game_user_sitedown_notify(const void *packet, uint32 msg_size);
		//void	handle_game_user_leaveseat_notify(const void *packet, uint32 msg_size);
		//void	handle_game_user_reservestandup_notify(const void *packet, uint32 msg_size);
		//void	handle_match_player_cash_chage_notify(const void *packet, uint32 msg_size);
		//void    handle_game_user_add_operationtimes_notify(const void * packet, uint32 msg_size);
		//void    handle_match_operationtimes_status_notify(const void * packet, uint32 msg_size);
		//void    handle_match_multianguage_notify(const void * packet, uint32 msg_size);
  //      void    handle_game_lookon_players_num_notify(const void * packet, uint32 msg_size);
  //      void    handle_match_table_count_notify(const void * packet, uint32 msg_size);
  //      void    handle_game_device_notify(const void * packet, uint32 msg_size);

  //      void    handle_game_end_add_chip_notice(const void *packet, uint32 msg_size);



	private:
		csession *				m_session_ptr;
		//cmgr_base*				m_mgrs[MGR_MAX];
		uint32					m_session_index;
		std::string				m_user_name;
		int32					m_score;
		std::string				m_token;
		int32					m_web_user_id;
		uint32					m_login_session_id; //http 登录时回话id
	};

}// namespace chen

#endif // !#define _C_PLAYER_H_