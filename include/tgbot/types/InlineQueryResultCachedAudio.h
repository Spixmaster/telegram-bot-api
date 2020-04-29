#ifndef TGBOT_TYPES_INLINEQUERYRESULTCACHEDAUDIO_H
#define TGBOT_TYPES_INLINEQUERYRESULTCACHEDAUDIO_H

#include <string>
#include "InlineKeyboardMarkup.h"
#include "InputMessageContent.h"
#include "InlineQueryResult.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct InlineQueryResultCachedAudio
	 * @brief Represents a link to an MP3 audio file stored on the Telegram servers.
	 * @brief By default, this audio file will be sent by the user.
	 * @brief Alternatively, you can use input_message_content to send a message with the specified content instead of the audio.
	 * @note This will only work in Telegram versions released after 9 April, 2016. Older clients will ignore them.
	 */
	struct InlineQueryResultCachedAudio : public InlineQueryResult
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InlineQueryResultCachedAudio> ptr;

		//Member variables
		/**
		 * @var type
		 * @brief Type of the result, must be audio
		 */
		const std::string type = "audio";
		/**
		 * @var id
		 * @brief Unique identifier for this result, 1-64 bytes
		 */
		std::string id;
		/**
		 * @var audio_file_id
		 * @brief A valid file identifier for the audio file
		 */
		std::string audio_file_id;
		/**
		 * @var caption
		 * @brief Optional. Caption, 0-1024 characters after entities parsing
		 */
		std::string caption;
		/**
		 * @var parse_mode
		 * @brief Optional. Mode for parsing entities in the audio caption. See formatting options for more details.
		 */
		std::string parse_mode;
		/**
		 * @var reply_markup
		 * @brief Optional. Inline keyboard attached to the message
		 */
		InlineKeyboardMarkup::ptr reply_markup;
		/**
		 * @var input_message_content
		 * @brief Optional. Content of the message to be sent instead of the audio
		 */
		InputMessageContent::ptr input_message_content;

		//Constructors
		InlineQueryResultCachedAudio();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		InlineQueryResultCachedAudio(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
