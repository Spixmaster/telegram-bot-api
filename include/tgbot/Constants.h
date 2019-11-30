#ifndef TGBOT_CONSTANTS_H
#define TGBOT_CONSTANTS_H

#include <string>
#include <memory>

/*
 * @brief container of all constants in the programme
 * @brief it is a monostate
 */

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
		 * @brief puts an error message out to stderr
		 * @param file: the filename which is included in the error message
		 */
		static void file_non_existent(const std::string &file);
	};
}

#endif
