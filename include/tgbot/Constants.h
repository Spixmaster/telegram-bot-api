#ifndef TGBOT_CONSTANTS_H
#define TGBOT_CONSTANTS_H

#include <string>
#include <memory>

namespace tgbot
{
	struct Constants
	{
		//pointer of itself
		typedef std::shared_ptr<Constants> ptr;

		//member variables
		static std::string version;
		static std::string release;

		//member functions

		/*
		 * @brief put an error message out to stderr
		 * @param file: the filename which is included in the error message
		 */
		static void file_non_existent(const std::string &file);
	};
}

#endif
