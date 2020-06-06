#ifndef TGBOT_TYPES_INPUTMEDIAAUDIO_H
#define TGBOT_TYPES_INPUTMEDIAAUDIO_H

#include <string>
#include "tgbot/types/InputMedia.h"
#include <memory>
#include <variant>
#include "tools/http/InputFile.h"

namespace tgbot
{
	/**
	 * @struct InputMediaAudio
	 * @brief Represents an audio file to be treated as music to be sent.
	 */
	struct InputMediaAudio : public InputMedia
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InputMediaAudio> ptr;

		//Member variables
		/**
		 * @var type
		 * @brief Type of the result, must be audio
		 */
		std::string type;
		/**
		 * @var media
		 * @brief File to send.
		 * @details Pass a file_id to send a file that exists on the Telegram servers (recommended), pass an HTTP URL for Telegram to get a file from the Internet, or pass “attach://\<file_attach_name\>” to upload a new one using multipart/form-data under \<file_attach_name\> name.
		 */
		std::variant<std::string, tools::InputFile::ptr> media;
		/**
		 * @var thumb
		 * @brief Optional. Thumbnail of the file sent; can be ignored if thumbnail generation for the file is supported server-side.
		 * @details The thumbnail should be in JPEG format and less than 200 kB in size. A thumbnail‘s width and height should not exceed 320.
		 * @details Ignored if the file is not uploaded using multipart/form-data.
		 * @details Thumbnails can’t be reused and can be only uploaded as a new file, so you can pass “attach://\<file_attach_name\>” if the thumbnail was uploaded using multipart/form-data under \<file_attach_name\>.
		 */
		std::variant<std::string, tools::InputFile::ptr> thumb;
		/**
		 * @var caption
		 * @brief Optional. Caption of the audio to be sent, 0-1024 characters after entities parsing
		 */
		std::string caption;
		/**
		 * @var parse_mode
		 * @brief Optional. Mode for parsing entities in the audio caption. See formatting options for more details.
		 */
		std::string parse_mode;
		/**
		 * @var duration
		 * @brief Optional. Duration of the audio in seconds
		 */
		int duration;
		/**
		 * @var performer
		 * @brief Optional. Performer of the audio
		 */
		std::string performer;
		/**
		 * @var title
		 * @brief Optional. Title of the audio
		 */
		std::string title;

		//Constructors
		InputMediaAudio();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		InputMediaAudio(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
