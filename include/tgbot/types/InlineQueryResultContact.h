#ifndef TGBOT_TYPES_INLINEQUERYRESULTCONTACT_H
#define TGBOT_TYPES_INLINEQUERYRESULTCONTACT_H

#include <string>
#include "InlineKeyboardMarkup.h"
#include "InputMessageContent.h"
#include "InlineQueryResult.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct InlineQueryResultContact
	 * @brief Represents a contact with a phone number.
	 * @details By default, this contact will be sent by the user.
	 * @details Alternatively, you can use input_message_content to send a message with the specified content instead of the contact.
	 * @note This will only work in Telegram versions released after 9 April, 2016. Older clients will ignore them.
	 */
	struct InlineQueryResultContact : public InlineQueryResult
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InlineQueryResultContact> ptr;

		//Member variables
		/**
		 * @var type
		 * @brief Type of the result, must be contact
		 */
		const std::string type = "contact";
		/**
		 * @var id
		 * @brief Unique identifier for this result, 1-64 Bytes
		 */
		std::string id;
		/**
		 * @var phone_number
		 * @brief Contact's phone number
		 */
		std::string phone_number;
		/**
		 * @var first_name
		 * @brief Contact's first name
		 */
		std::string first_name;
		/**
		 * @var last_name
		 * @brief Optional. Contact's last name
		 */
		std::string last_name;
		/**
		 * @var vcard
		 * @brief Optional. Additional data about the contact in the form of a vCard, 0-2048 bytes
		 */
		std::string vcard;
		/**
		 * @var reply_markup
		 * @brief Optional. Inline keyboard attached to the message
		 */
		InlineKeyboardMarkup::ptr reply_markup;
		/**
		 * @var input_message_content
		 * @brief Optional. Content of the message to be sent instead of the contact
		 */
		InputMessageContent::ptr input_message_content;
		/**
		 * @var thumb_url
		 * @brief Optional. Url of the thumbnail for the result
		 */
		std::string thumb_url;
		/**
		 * @var thumb_width
		 * @brief Optional. Thumbnail width
		 */
		int thumb_width = -1;
		/**
		 * @var thumb_height
		 * @brief Optional. Thumbnail height
		 */
		int thumb_height = -1;

		//Constructors
		InlineQueryResultContact();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		InlineQueryResultContact(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
