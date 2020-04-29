#ifndef TGBOT_TYPES_INPUTMESSAGECONTENT_H
#define TGBOT_TYPES_INPUTMESSAGECONTENT_H

#include <memory>

namespace tgbot
{
	/**
	 * @struct InputMessageContent
	 * @brief This object represents the content of a message to be sent as a result of an inline query. Telegram clients currently support the following 4 types: ...
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

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		InputMessageContent(const std::string &json);

		//Destructors
		virtual ~InputMessageContent();

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		virtual std::string parse_to_json() const noexcept;
	};
}

#endif
