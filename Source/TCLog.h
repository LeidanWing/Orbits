#pragma once
#ifndef TCLOG_H
#define TCLOG_H
#include "string"
#include <iostream>
#include <sstream>


// This should maybe defined in the main project (thus the logger should be a class), 
// but since this logger is not going to be ported to other projects, it doesn't really matter.

#define LOGLEVEL 2

#define LOG(level, caller, message) {\
		if (level <= LOGLEVEL){\
			std::ostringstream stringStream; \
			std::string messageString; \
			stringStream << "[" << caller << "] " << message; messageString = stringStream.str(); \
			Logging::TCLog(level, messageString); \
		} \
	}

namespace Logging
{
	enum Level
	{
		ERROR,
		WARNING,
		STATUS,
		DEBUG
	};

	int TCLog(Logging::Level i_level, const std::string &i_message);
}


#endif //TCLOG_H
