#include "TCLog.h"

int Logging::TCLog(Logging::Level i_level, const std::string & i_message)
{
	std::string levelString;
	switch (i_level)
	{
	case ERROR:
		levelString = "ERROR";
		break;
	case WARNING:
		levelString = "WARNING";
		break;
	case STATUS:
		levelString = "STATUS";
		break;
	case DEBUG:
		levelString = "DEBUG";
		break;
	default:
		levelString = "";
	}
	std::cout << "[" << levelString << "]" << i_message;
	return 0;
}
