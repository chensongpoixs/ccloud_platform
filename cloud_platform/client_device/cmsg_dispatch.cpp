/***********************************************************************************************
					created: 		2019-05-13

					author:			chensong

					purpose:		msg_dipatch
************************************************************************************************/

#include "cmsg_dispatch.h"
#include "clog.h"
//#include "GameClient.pb.h"
//#include "LS2GC.pb.h"
//#include "CS2GC.pb.h"
//#include "MS2GC.pb.h"
namespace chen {
	cmsg_dispatch::cmsg_dispatch()
	{
	}
	cmsg_dispatch::~cmsg_dispatch()
	{
	}
	bool cmsg_dispatch::init()
	{
		//_register_msg_handler(0, "S2C_Code", &cplayer::handle_code);
	//	_register_msg_handler(GameClient::eMsgToGSFromGC_BeatHeart, "S2C_BeatHeart", &cplayer::handle_breatheart);
	//	_register_msg_handler(GameClient::eMsgToGCFromGS_Announce, "S2C_Announce", &cplayer::handle_announce);
	//	_register_msg_handler(LS2GC::eMsgToGCFromLS_LoginRS, "S2C_Login", &cplayer::handle_login);


 //       // match information
	//	_register_msg_handler(CS2GC::eMsgToGCFromCS_MatchListRS, "S2C_Match_List", &cplayer::handle_match_list);
	//	_register_msg_handler(CS2GC::eMsgToGCFromCS_MatchPlayerJoinedListRS, "S2C_Match_PlayerJoin_list", &cplayer::handle_player_joinlist);
	//	_register_msg_handler(CS2GC::eMsgToGCFromCS_MTTMatchRuleList, "S2C_Match_run_list", &cplayer::handle_match_run_list);
 //       _register_msg_handler(CS2GC::eMsgToGCFromCS_MultilanguageNotify, "S2C_match_multianguage_notify", &cplayer::handle_match_multianguage_notify);
 //       //_register_msg_handler(CS2GC::eMsgToGCFromCS_MultilanguageNotify, "S2C_multilanguage_notify", &cplayer::handle_multilanguage_notify);

	//	// friend circle table
	//	_register_msg_handler(CS2GC::eMsgToGCFromCS_CreateFriendTableRS, "S2C_Create_Friend_table", &cplayer::handle_create_table);
	//	_register_msg_handler(CS2GC::eMsgToGCFromCS_DeleteFriendTableRS, "S2C_Delete_Friend_table", &cplayer::handle_delete_table);
	//	_register_msg_handler(MS2GC::eMsgToGCFromMS_ModifyFriendTableRS, "S2C_Modify_Friend_table", &cplayer::handle_modify_table);


	//	// game

	//	_register_msg_handler(MS2GC::eMsgToGCFromMS_JoinMatchRS, "S2C_Join_table", &cplayer::handle_join_table);
	//	_register_msg_handler(MS2GC::eMsgToGCFromMS_LeaveMatchRS, "S2C_Leave_table", &cplayer::handle_leave_table);


	//	// game logic
	//	_register_msg_handler(MS2GC::eMsgToGCFromMS_MatchGameInfoRS, "S2C_Game_Info", &cplayer::handle_game_info);
	//	_register_msg_handler(MS2GC::eMsgToGCFromMS_MatchTimerInfoRS, "S2C_Game_Timer_Info", &cplayer::handle_game_timer_info);
	//	_register_msg_handler(MS2GC::eMsgToGCFromMS_MatchBonusRS, "S2C_Game_Bonus", &cplayer::handle_game_bonus);
	//	_register_msg_handler(MS2GC::eMsgToGCFromMS_GameUserActionRS, "S2C_Game_Action", &cplayer::handle_game_action);
	//	_register_msg_handler(MS2GC::eMsgToGCFromMS_MatchPlayerRankingRS, "S2C_Game_Player_Ranking", &cplayer::handle_game_player_ranking);
	//	_register_msg_handler(MS2GC::eMsgToGCFromMS_GameShowHandCardRS, "S2C_Game_Show_Hand_Card", &cplayer::handle_game_show_hand_card);
	//	_register_msg_handler(MS2GC::eMsgToGCFromMS_MatchAddChipRS, "S2C_Match_Add_Chip", &cplayer::handle_match_add_chip);
	//	//_register_msg_handler(MS2GC::eMsgToGCFromMS_Match_Free_Signup_NumRS, "S2C_Match_Free_Signup_Num", &cplayer::handle_match_free_signup_num);
	//	// lookon
	//	_register_msg_handler(MS2GC::eMsgToGCFromMS_MatchLookonRS, "S2C_Game_Lookon", &cplayer::handle_game_lookon);
	//	
	//	_register_msg_handler(MS2GC::eMsgToGCFromMS_GameBackChairRS, "S2C_Game_Player_Back_Chair", &cplayer::handle_game_player_back_chair);
	//	
	//	_register_msg_handler(MS2GC::eMsgToGCFromMS_GameManualAddScoreRS, "S2C_Game_Player_Add_Score", &cplayer::handle_game_add_score);
 ////       _register_msg_handler(MS2GC::eMsgToGCFromMS_MatchPlayerOperationtimesRS, "S2C_Game_Player_Operationtimes", &cplayer::handle_game_player_operationtimes);
 //       _register_msg_handler(MS2GC::eMsgToGCFromMS_MatchPlayerAddOperationtimeRS, "S2C_Game_Player_Add_Operationtimes", &cplayer::handle_game_add_operationtimes);
 //       _register_msg_handler(MS2GC::eMsgToGCFromMS_Match_Lookon_PlayersRS, "S2C_game_lookon_players", &cplayer::handle_game_lookon_players);


	//	// match notify 
	//	_register_msg_handler(MS2GC::eMsgToGCFromMS_AnteBlindChangeNotify, "S2C_Ante_Blind_Change", &cplayer::handle_ante_blind_change_notify);
	//	_register_msg_handler(CS2GC::eMsgToGCFromCS_MatchInfoUpdateNotify, "S2C_Match_info_update_notify", &cplayer::handle_match_info_update_notify);
	//	_register_msg_handler(MS2GC::eMsgToGCFromMS_MatchStartNotify, "S2C_match_start_notify", &cplayer::handle_match_start_notify);
	//	_register_msg_handler(MS2GC::eMsgToGCFromMS_MatchFinishNotify, "S2C_match_finish_notify", &cplayer::handle_match_finish_notify);
	//	_register_msg_handler(MS2GC::eMsgToGCFromMS_MatchWaitTableNotify, "S2C_match_wait_notify", &cplayer::handle_match_wait_notify);
	//	_register_msg_handler(MS2GC::eMsgToGCFromMS_MatchResultNotify, "S2C_match_result_notify", &cplayer::handle_match_result_notify);
	//	_register_msg_handler(MS2GC::eMsgToCSFromMS_MatchCancelNotify, "S2C_match_cancle_notify", &cplayer::handle_match_cancle_notify);
	//	_register_msg_handler(MS2GC::eMsgToCSFromMS_MatchStatusChangedNotify, "S2C_match_status_change_notify", &cplayer::handle_match_status_change_notify);
	//	_register_msg_handler(MS2GC::eMsgToGCFromMS_Match_Add_Chip_Notify, "S2C_match_add_chip_notify", &cplayer::handle_match_add_chip_notify);
	//	// game notify
	//	_register_msg_handler(MS2GC::eMsgToGCFromMS_GameReadyStartNotify, "S2C_game_ready_start_notify", &cplayer::handle_game_ready_start_notify);
	//	_register_msg_handler(MS2GC::eMsgToGCFromMS_GameStartNotify, "S2C_game_start_notify", &cplayer::handle_game_start_notify);
	//	_register_msg_handler(MS2GC::eMsgToGCFromMS_GamePublicFlopCardsNotify, "S2C_game_public_flop_cards_notify", &cplayer::handle_game_flop_cards_notify);
	//	_register_msg_handler(MS2GC::eMsgToGCFromMS_GamePublicTurnCardsNotify, "S2C_game_public_turn_cards_notify", &cplayer::handle_game_turn_cards_notify);
	//	_register_msg_handler(MS2GC::eMsgToGCFromMS_GamePublicRiverCardsNotify, "S2C_game_public_river_cards_notify", &cplayer::handle_game_river_cards_notify);
	//	_register_msg_handler(MS2GC::eMsgToGCFromMS_GameUserActionNotify, "S2C_game_user_action_notify", &cplayer::handle_game_user_action_notify);
	//	_register_msg_handler(MS2GC::eMsgToGCFromMS_GameUserHandcardNotify, "S2C_game_user_handcard_notify", &cplayer::handle_game_user_handcard_notify);
	//	_register_msg_handler(MS2GC::eMsgToGCFromMS_GameEndInfoNotify, "S2C_game_end_info_notify", &cplayer::handle_game_end_info_notify);
	//	_register_msg_handler(MS2GC::eMsgToGCFromMS_GameShowHandCardNotify, "S2C_game_show_hand_card_notify", &cplayer::handle_game_show_hand_card_notify);
	//	_register_msg_handler(MS2GC::eMsgToGCFromMS_GameUserSiteDownNotify, "S2C_game_user_sitedown_notify", &cplayer::handle_game_user_sitedown_notify);
	//	_register_msg_handler(MS2GC::eMsgToGCFromMS_GameUserLeaveSeatNotify, "S2C_game_user_leaveseat_notify", &cplayer::handle_game_user_leaveseat_notify);
	//	_register_msg_handler(MS2GC::eMsgToGCFromMS_GameUserstateNotify, "S2C_game_user_reservestandup_notify", &cplayer::handle_game_user_reservestandup_notify);
 //       _register_msg_handler(MS2GC::eMsgToGCFromMS_MatchAddOperationTimerNotify, "S2C_game_player_add_operationtimes_notify", &cplayer::handle_game_user_add_operationtimes_notify);
 //       _register_msg_handler(MS2GC::eMsgToGCFromMS_MatchOperationStatusNotify, "S2C_match_operationtimes_status_notify", &cplayer::handle_match_operationtimes_status_notify);
 //       _register_msg_handler(MS2GC::eMsgToGCFromMS_Game_End_Add_Chip_Notice, "S2C_game_end_add_chip_notice", &cplayer::handle_match_operationtimes_status_notify);
 //       _register_msg_handler(MS2GC::eMsgToGCFromMS_NoticeTableCount, "S2C_match_table_count_notity", &cplayer::handle_match_operationtimes_status_notify);

 //       //
	//	_register_msg_handler(MS2GC::eMsgToGCFromMS_MatchPlayerCashChangedNotify, "S2C_match_player_cash_change_notify", &cplayer::handle_match_player_cash_chage_notify);

 //       _register_msg_handler(MS2GC::eMsgToGCFromMS_Game_Lookon_Players_NumNotify, "S2C_game_lookon_players_num_notify", &cplayer::handle_game_lookon_players_num_notify);
 //       _register_msg_handler(MS2GC::eMsgToGCFromMS_Game_Device_Notify, "S2C_match_device_notify", &cplayer::handle_game_device_notify);
 //       _register_msg_handler(MS2GC::eMsgToGCFromMS_Match_DeviceRS, "S2C_match_device_notify", &cplayer::handle_match_game_device);




        return true;
	}
	void cmsg_dispatch::destroy()
	{
	}
	cmsg_handler * cmsg_dispatch::get_msg_handler(uint16 msg_id)
	{
		if (static_cast<int> (msg_id) >= Msg_Client_Max)
		{
			return NULL;
		}

		return &(m_msg_handler[msg_id]);
	}
	void cmsg_dispatch::_register_msg_handler(uint16 msg_id, const std::string & msg_name, handler_type handler)
	{
		if (static_cast<int> (msg_id) >= Msg_Client_Max || m_msg_handler[msg_id].handler)
		{
			ERROR_LOG("[%s] register msg error, msg_id = %u, msg_name = %s", __FUNCTION__, msg_id, msg_name.c_str());
			return;
		}

		m_msg_handler[msg_id].msg_name = msg_name;//   数据统计
		m_msg_handler[msg_id].handle_count = 0;
		m_msg_handler[msg_id].handler = handler;
	}


	cmsg_dispatch g_msg_dispatch;
} //namespace chen