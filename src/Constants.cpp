#include "tgbot/Constants.h"
#include <string>
#include <iostream>

namespace tgbot
{
	std::string Constants::version = "1.0.52";
	std::string Constants::release = "19.Nov.2019";

	void Constants::file_non_existent(const std::string &file)
	{
		std::cerr << "Error. The file \"" + file + "\" does not exist." << std::endl;
	}
}
