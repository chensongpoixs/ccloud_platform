#include <iostream>
#include <iostream>
#include <string>
#include "ctime_const.h"
#include "ctime_api.h"
#include <algorithm>
#include <vector>
#include "cgeteway_server.h"
#include <signal.h>
#include <casync_log.h>
void Stop(int i)
{
	chen::g_cgeteway_server.stop();
}

void RegisterSignal()
{
	signal(SIGINT, Stop);
	signal(SIGTERM, Stop);
}

int main(int argc, char *argv[])
{
	RegisterSignal();
	const char* config_filename = "server.cfg";
	if (argc > 1)
	{
		config_filename = argv[1];
	}
	const char* log_path = "./";
	if (argc > 2)
	{
		log_path = argv[2];
	}

	bool init = chen::g_cgeteway_server.init(log_path, config_filename);

	if (init)
	{
		init = chen::g_cgeteway_server.Loop();
	}
	
	chen::g_cgeteway_server.destroy();
	
	return EXIT_SUCCESS;
}