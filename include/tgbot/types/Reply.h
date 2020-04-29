#ifndef TGBOT_TYPES_REPLY_H
#define TGBOT_TYPES_REPLY_H

#include <memory>

namespace tgbot
{
	/**
	 * @struct Reply
	 * @brief The super class of all reply classes.
	 */
	struct Reply
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<Reply> ptr;

		//Destructors
		virtual ~Reply();

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		virtual std::string parse_to_json() const noexcept;
	};
}

#endif
