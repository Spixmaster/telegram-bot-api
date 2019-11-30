#ifndef TGBOT_TYPES_INPUTMEDIADOCUMENT_H
#define TGBOT_TYPES_INPUTMEDIADOCUMENT_H

#include <string>
#include "tgbot/types/InputMedia.h"
#include <memory>
#include <variant>
#include "tools/http/InputFile.h"

namespace tgbot
{
	struct InputMediaDocument : public InputMedia
	{
		//pointer of itself
		typedef std::shared_ptr<InputMediaDocument> ptr;

		//member variables
		const std::string type = "document";
		std::variant<std::string, tools::InputFile::ptr> media;
		std::variant<std::string, tools::InputFile::ptr> thumb;
		std::string caption;
		std::string parse_mode;

		//constructors
		InputMediaDocument();

		//@param json: json object of InputMediaDocument
		InputMediaDocument(const std::string &json);

		//@param media: source of the document
		//@param thumb: source of the thumb
		//@param caption: caption under document
		//@param parse_mode: how caption is parsed
		InputMediaDocument(const std::variant<std::string, tools::InputFile::ptr> &media, const std::variant<std::string, tools::InputFile::ptr> &thumb, const std::string &caption = "",
				const std::string &parse_mode = "");

		//member functions

		/*
		 * @brief parses itself into json equivalent
		 * @return json object of itself as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
