#ifndef TGBOT_TYPES_INPUTLOCATIONMESSAGECONTENT_H
#define TGBOT_TYPES_INPUTLOCATIONMESSAGECONTENT_H

#include "tgbot/types/InputMessageContent.h"
#include <string>
#include <memory>

namespace tgbot
{
	/**
	 * @struct InputLocationMessageContent
	 */
	struct InputLocationMessageContent : public InputMessageContent
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InputLocationMessageContent> ptr;

		//Member variables
		/**
		 * @var
		 */
		float latitude = -1;
		/**
		 * @var
		 */
		float longitude = -1;
		/**
		 * @var
		 */
		int live_period = -1;

		//Constructors
		InputLocationMessageContent();

		//@param json: json object of InputLocationMessageContent
		InputLocationMessageContent(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
