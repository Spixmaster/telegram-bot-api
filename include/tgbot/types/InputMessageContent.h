#ifndef TGBOT_TYPES_INPUTMESSAGECONTENT_H
#define TGBOT_TYPES_INPUTMESSAGECONTENT_H

#include <memory>

namespace tgbot
{
	/**
	 * @struct InputMessageContent
	 */
	struct InputMessageContent
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InputMessageContent> ptr;

		//Constructors
		InputMessageContent();

		//@param json: json object of InputMessageContent
		InputMessageContent(const std::string &json);

		//Destructors
		virtual ~InputMessageContent();

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		virtual std::string parse_to_json() const noexcept;
	};
}

#endif
