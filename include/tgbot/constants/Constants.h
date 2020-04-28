#ifndef TGBOT_CONSTANTS_CONSTANTS_H
#define TGBOT_CONSTANTS_CONSTANTS_H

#include <string>
#include <memory>

namespace tgbot
{
	/**
	 * @struct Constants
	 * @brief A container of all constants in the programme.
	 * @details It is a monostate.
	 */
	struct Constants
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<Constants> ptr;

		//Member variables
		/**
		 * @var version
		 * @brief The version of the software.
		 */
		static const std::string version;
		/**
		 * @var release
		 * @breif The release date of the current version.
		 */
		static const std::string release;
	};
}

#endif
