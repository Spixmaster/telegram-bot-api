#ifndef TGBOT_TYPES_INPUTMEDIAANIMATION_H
#define TGBOT_TYPES_INPUTMEDIAANIMATION_H

#include <string>
#include "tgbot/types/InputMedia.h"
#include <memory>
#include <variant>
#include "tools/http/InputFile.h"

namespace tgbot
{
	/**
	 * @struct InputMediaAnimation
	 * @brief Represents an animation file (GIF or H.264/MPEG-4 AVC video without sound) to be sent.
	 */
	struct InputMediaAnimation : public InputMedia
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InputMediaAnimation> ptr;

		//Member variables
		/**
		 * @var type
		 * @brief Type of the result, must be animation
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
		 * @details The thumbnail should be in JPEG format and less than 200 kB in size. A thumbnail‘s width and height should not exceed 320. Ignored if the file is not uploaded using multipart/form-data. Thumbnails can’t be reused and can be only uploaded as a new file, so you can pass “attach://\<file_attach_name\>” if the thumbnail was uploaded using multipart/form-data under \<file_attach_name\>.
		 */
		std::variant<std::string, tools::InputFile::ptr> thumb;
		/**
		 * @var caption
		 * @brief Optional. Caption of the animation to be sent, 0-1024 characters after entities parsing
		 */
		std::string caption;
		/**
		 * @var parse_mode
		 * @brief Optional. Mode for parsing entities in the animation caption. See formatting options for more details.
		 */
		std::string parse_mode;
		/**
		 * @var width
		 * @brief Optional. Animation width
		 */
		int width;
		/**
		 * @var height
		 * @brief Optional. Animation height
		 */
		int height;
		/**
		 * @var duration
		 * @brief Optional. Animation duration
		 */
		int duration;

		//Constructors
		InputMediaAnimation();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		InputMediaAnimation(const std::string &json);

		/**
		 * @param[in] media Passed to the member variable.
		 * @param[in] thumb Passed to the member variable.
		 * @param[in] caption Passed to the member variable.
		 * @param[in] parse_mode Passed to the member variable.
		 * @param[in] width Passed to the member variable.
		 * @param[in] height Passed to the member variable.
		 * @param[in] duration Passed to the member variable.
		 */
		InputMediaAnimation(const std::variant<std::string, tools::InputFile::ptr> &media, const std::variant<std::string, tools::InputFile::ptr> &thumb,
				const std::string &caption = "", const std::string &parse_mode = "", const int &width = -1, const int &height = -1, const int &duration = -1);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
