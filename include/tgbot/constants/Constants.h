#ifndef TGBOT_CONSTANTS_CONSTANTS_H
#define TGBOT_CONSTANTS_CONSTANTS_H

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
		static const std::string version;
		static const std::string release;
	};
}

#endif
