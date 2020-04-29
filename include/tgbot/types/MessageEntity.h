#ifndef TGBOT_TYPES_MESSAGEENTITY_H
#define TGBOT_TYPES_MESSAGEENTITY_H

#include <string>
#include <memory>
#include "tgbot/types/User.h"

namespace tgbot
{
	/**
	 * @struct MessageEntity
	 * @brief This object represents one special entity in a text message. For example, hashtags, usernames, URLs, etc.
	 */
	struct MessageEntity
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<MessageEntity> ptr;

		//Member variables
		/**
		 * @var type
		 * @brief Type of the entity.
		 * @details Can be “mention” (@username), “hashtag” (#hashtag), “cashtag” ($USD), “bot_command” (/start@jobs_bot), “url” (https://telegram.org), “email” (do-not-reply@telegram.org), “phone_number” (+1-212-555-0123), “bold” (bold text), “italic” (italic text), “underline” (underlined text), “strikethrough” (strikethrough text), “code” (monowidth string), “pre” (monowidth block), “text_link” (for clickable text URLs), “text_mention” (for users without usernames)
		 */
		std::string type;
		/**
		 * @var offset
		 * @brief Offset in UTF-16 code units to the start of the entity
		 */
		int offset = -1;
		/**
		 * @var length
		 * @brief Length of the entity in UTF-16 code units
		 */
		int length = -1;
		/**
		 * @var url
		 * @brief Optional. For “text_link” only, url that will be opened after user taps on the text
		 */
		std::string url;
		/**
		 * @var user
		 * @brief Optional. For “text_mention” only, the mentioned user
		 */
		User::ptr user;
		/**
		 * @var language
		 * @brief Optional. For “pre” only, the programming language of the entity text
		 */
		std::string language;

		//Constructors
		MessageEntity();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		MessageEntity(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
