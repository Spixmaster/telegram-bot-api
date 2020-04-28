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
		 * @var
		 */
		const std::string type = "photo";
		/**
		 * @var
		 */
		std::variant<std::string, tools::InputFile::ptr> media;
		/**
		 * @var
		 */
		std::string caption;
		/**
		 * @var
		 */
		std::string parse_mode;

		//Constructors
		InputMediaPhoto();

		//@param json: json object of InputMediaPhoto
		InputMediaPhoto(const std::string &json);

		//@param media: source of the photo
		//@param caption: caption under photo
		//@param parse_mode: how caption is parsed
		InputMediaPhoto(const std::variant<std::string, tools::InputFile::ptr> &media, const std::string &caption = "", const std::string &parse_mode = "");

		//Member functions
		/*
		 * @brief parses itself into json equivalent
		 * @return json object of the itself as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
