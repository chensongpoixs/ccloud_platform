#include <iostream>
#include <string>
#include <signal.h>
#include "crobot.h"

void Stop(int i)
{
	chen::g_rotbot.stop();
}

void RegisterSignal()
{
	signal(SIGINT, Stop);
	signal(SIGTERM, Stop);
}

int main(int argc, char *argv[])
{
	RegisterSignal();
	const char* config_filename = "crobot.cfg";
	if (argc > 1)
	{
		config_filename = argv[1];
	}
	const char* log_path = "./";
	if (argc > 2)
	{
		log_path = argv[2];
	}
#if defined(_MSC_VER)
	system("CHCP 65001");
#endif
	bool init = chen::g_rotbot.init(log_path, config_filename);

	if (init)
	{
		init = chen::g_rotbot.Loop();
	}

	chen::g_rotbot.destroy();
 
	return EXIT_SUCCESS;
}

