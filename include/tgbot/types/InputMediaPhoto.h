#ifndef TGBOT_TYPES_INPUTMEDIAPHOTO_H
#define TGBOT_TYPES_INPUTMEDIAPHOTO_H

#include <string>
#include "tgbot/types/InputMedia.h"
#include <memory>
#include <variant>
#include "tools/http/InputFile.h"

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct InputMediaPhoto : public InputMedia
	{
		//pointer of itself
		typedef std::shared_ptr<InputMediaPhoto> ptr;

		//member variables
		const std::string type = "photo";
		std::variant<std::string, tools::InputFile::ptr> media;
		std::string caption;
		std::string parse_mode;

		//constructors
		InputMediaPhoto();

		//@param json: json object of InputMediaPhoto
		InputMediaPhoto(const std::string &json);

		//@param media: source of the photo
		//@param caption: caption under photo
		//@param parse_mode: how caption is parsed
		InputMediaPhoto(const std::variant<std::string, tools::InputFile::ptr> &media, const std::string &caption = "", const std::string &parse_mode = "");

		//member functions
		/*
		 * @brief parses itself into json equivalent
		 * @return json object of the itself as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
