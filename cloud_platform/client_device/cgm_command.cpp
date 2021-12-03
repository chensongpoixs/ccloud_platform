/***********************************************************************************************
					created: 		2019-05-13

					author:			chensong

					purpose:		gm_command
************************************************************************************************/

#include "cgm_command.h"
#include "clog.h"
//#include "csend_msgc2s.h"
//#include "cfriend_circle_table_mgr.h"
namespace chen {
	cgm_command::cgm_command()
	{
	}
	cgm_command::~cgm_command()
	{
	}
	bool cgm_command::init()
	{
		//using namespace csend_msgc2s;
		//_register_command("help", &help, "[cmd]");
		//_register_command("gm", &send_gm, "<cmd>");
		//_register_command("login", &send_login, "<login>");

		//// friend circle
		//_register_command("friend_create_table", &send_friend_create_table, "<user_id> <circle_id> <room_name> <smallblind> <buyin> <maxplayers> <operatetime> <tabletype> <ante> <privatetable>  <privatekey>");
		//_register_command("friend_delete_table", &send_friend_delete_table, "<user_id> <circle_id> <table_id> <table_type>");
		//_register_command("friend_modify_table_info", &send_friend_modify_table, "<extra> <user_id> <circle_id> <table_id> <room_name> <small_blind> <maxplayers> <operatetime> <tabletype> <tablekey> <private_table> <game_type>");
		//_register_command("match_player_joined_list", &send_match_player_joined_list, "<user_id>");

  //      // join_table 35103  133741  35103 2 chensong 35103 9 2 2 1
		////game 
		//_register_command("join_table", &send_join_table, "<extra> <user_id> <game_id> <match_type> <game_user_name> <proxy_user_id> <circle_id> <private_key> <game_type> <join_type>");
		//_register_command("leave_table", &send_leave_table, "<extra> <user_id> <game_id> <match_type> <circle_id>  <game_type>");

		//// game logic game_info 30809  131857  30809 2  robot100 2
		//_register_command("game_info", &send_game_info, "<extra> <user_id> <game_id> <match_type> <user_name> <game_type>");
		//_register_command("game_timer_info", &send_game_timer_info, "<extra> <user_id> <game_id> <match_type> <game_type>");
		//_register_command("game_bonus", &send_game_bonus, "<extra> <user_id> <game_id> <game_type>");
		//_register_command("game_action", &send_game_action, "<extra> <user_id> <game_id> <match_type> <chair_id> <action_type> <coin_count> <game_type>");
		//_register_command("game_player_ranking", &send_game_player_ranking, "<extra> <user_id> <game_id> <match_type> <game_type>");
		//_register_command("game_player_deregister_push_match_info", &send_game_player_deregister_push_match_info, "<extra> <user_id> <game_id> <game_type>");
		//_register_command("game_show_hand_card", &send_game_show_hand_card, "<extra> <user_id> <game_id> <game_type> <count> <hand_cardss>");

		//// lookon
		//_register_command("game_lookon", &send_game_lookon, "<extra> <user_id> <game_id> <game_type>  <game_type>");
		//_register_command("game_cancal_lookon", &send_game_cancal_lookon, "<extra> <user_id> <game_id> <match_type> <game_type>");

		//_register_command("game_player_back_chair", &send_game_player_back_chair, "<extra> <user_id> <game_id> <game_type> <chair_id>");
		//_register_command("game_add_score", &send_game_add_score, "<extra> <user_id> <game_id> <game_type> <multiple>");
		//_register_command("game_lookon_players_data", &send_game_lookon_players_data, "<extra> <user_id> <match_id> <match_type>");
		////game_player_device 30809  131857  30809 2   2
  //      _register_command("game_player_device", &send_game_player_device, "<extra> <player_id> <match_id> <match_type><web_device>");
//		_register_command("match_add_chip", &send_match_add_chip, "<extra> <user_id> <match_id> <match_type> <num>");
	//	_register_command("match_player_signup", &send_match_player_signup, "<extra> <player_id>");
     //   _register_command("match_player_operationtimes", &send_match_player_operationtimes, "<extra> <player_id><match_id><match_type>");
    //    _register_command("match_player_add_operationtimes", &send_match_player_add_operationtimes, "<extra> <player_id><match_id><match_type>");
		return true;
	}
	void cgm_command::destroy()
	{
		m_gm_commands.clear();
	}
	void cgm_command::parse_commands(const char * text, csession * session_ptr)
	{
		if (text == NULL || text[0] == 0)
		{
			return;
		}
		SYSTEM_LOG("[commands]cmd = %s", text);
		ccmd_param params;
		params.parse_cmd(text);
		
		if (_execute_command(params.get_cmd(), params, session_ptr))
		{
			NORMAL_LOG("gm command: %s" , text);
		}
	}
	void cgm_command::print_command(const std::string & cmd) const
	{
		for (NCOMMAND_MAP::const_iterator cit = m_gm_commands.begin(); cit != m_gm_commands.end(); ++cit)
		{
			if (cmd.empty() || cit->second.name.find(cmd) != std::string::npos)
			{
				NORMAL_LOG("%s, %s", cit->second.name.c_str() , cit->second.desc.c_str());
			}
		}
	}
	void cgm_command::_register_command(const std::string & cmd_name, gm_cmd_handler_type handler, const std::string & desc)
	{
		ncommand cmd(cmd_name, handler, desc);

		if (false == m_gm_commands.insert(std::make_pair(cmd_name, cmd)).second)
		{
			ERROR_LOG("%s, insert command error");
			return;
		}
	}
	bool cgm_command::_execute_command(const std::string & cmd_name, const ccmd_param & param, csession * session_ptr)
	{
		//SYSTEM_LOG("find name = %s", cmd_name.c_str());
		NCOMMAND_MAP::const_iterator ncmd = m_gm_commands.find(cmd_name);

		if (ncmd == m_gm_commands.end())
		{
			ERROR_LOG(  "unknown command ");
			return false;
		}

		if (!(ncmd->second.handler(param, session_ptr)))
		{
			ERROR_LOG( "execute failed " );
			return false;
		}

		return true;
	}
}//namespace chen 