#ifndef TGBOT_TYPES_INPUTMEDIAPHOTO_H
#define TGBOT_TYPES_INPUTMEDIAPHOTO_H

#include <string>
#include "tgbot/types/InputMedia.h"
#include <memory>
#include <variant>
#include "tools/http/InputFile.h"

namespace tgbot
{
	/**
	 * @struct InputMediaPhoto
	 * @brief Represents a photo to be sent.
	 */
	struct InputMediaPhoto : public InputMedia
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InputMediaPhoto> ptr;

		//Member variables
		/**
		 * @var type
		 * @brief Type of the result, must be photo
		 */
		const std::string type = "photo";
		/**
		 * @var media
		 * @brief File to send.
		 * @details Pass a file_id to send a file that exists on the Telegram servers (recommended), pass an HTTP URL for Telegram to get a file from the Internet, or pass “attach://<file_attach_name>” to upload a new one using multipart/form-data under <file_attach_name> name.
		 */
		std::variant<std::string, tools::InputFile::ptr> media;
		/**
		 * @var caption
		 * @brief Optional. Caption of the photo to be sent, 0-1024 characters after entities parsing
		 */
		std::string caption;
		/**
		 * @var parse_mode
		 * @brief Optional. Mode for parsing entities in the photo caption. See formatting options for more details.
		 */
		std::string parse_mode;

		//Constructors
		InputMediaPhoto();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		InputMediaPhoto(const std::string &json);

		InputMediaPhoto(const std::variant<std::string, tools::InputFile::ptr> &media, const std::string &caption = "", const std::string &parse_mode = "");

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
