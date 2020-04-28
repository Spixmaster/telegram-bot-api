#ifndef TGBOT_TYPES_REPLY_H
#define TGBOT_TYPES_REPLY_H

#include <memory>

namespace tgbot
{
	/**
	 * @struct Reply
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
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		virtual std::string parse_to_json() const noexcept;
	};
}

#endif
