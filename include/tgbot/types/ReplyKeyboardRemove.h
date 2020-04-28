#ifndef TGBOT_TYPES_REPLYKEYBOARDREMOVE_H
#define TGBOT_TYPES_REPLYKEYBOARDREMOVE_H

#include <rapidjson/document.h>
#include <memory>
#include "tgbot/types/Reply.h"

namespace tgbot
{
	/**
	 * @struct ReplyKeyboardRemove
	 */
	struct ReplyKeyboardRemove : public Reply
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<ReplyKeyboardRemove> ptr;

		//Member variables
		/**
		 * @var
		 */
		bool remove_keyboard;
		/**
		 * @var
		 */
		bool selective;

		//Constructors
		ReplyKeyboardRemove();

		//@param json: json object of ReplyKeyboardRemove
		ReplyKeyboardRemove(const std::string &json);

		//Member functions
		/*
		 * @brief parses the itself into its json equivalent
		 * @return return a string which represents a itself
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
