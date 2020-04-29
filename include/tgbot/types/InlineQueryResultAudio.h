#ifndef TGBOT_TYPES_INLINEQUERYRESULTAUDIO_H
#define TGBOT_TYPES_INLINEQUERYRESULTAUDIO_H

#include <string>
#include "tgbot/types/InlineKeyboardMarkup.h"
#include "tgbot/types/InputMessageContent.h"
#include "tgbot/types/InlineQueryResult.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct InlineQueryResultAudio
	 * @brief Represents a link to an MP3 audio file.
	 * @details By default, this audio file will be sent by the user.
	 * @details Alternatively, you can use input_message_content to send a message with the specified content instead of the audio.
	 * @note This will only work in Telegram versions released after 9 April, 2016. Older clients will ignore them.
	 */
	struct InlineQueryResultAudio : public InlineQueryResult
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InlineQueryResultAudio> ptr;

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
		 * @var audio_url
		 * @brief A valid URL for the audio file
		 */
		std::string audio_url;
		/**
		 * @var title
		 * @brief Title
		 */
		std::string title;
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
		 * @var performer
		 * @brief Optional. Performer
		 */
		std::string performer;
		/**
		 * @var audio_duration
		 * @brief Optional. Audio duration in seconds
		 */
		int audio_duration = -1;
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
		InlineQueryResultAudio();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		InlineQueryResultAudio(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
