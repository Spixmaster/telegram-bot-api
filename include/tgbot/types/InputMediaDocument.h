#ifndef TGBOT_TYPES_INPUTMEDIADOCUMENT_H
#define TGBOT_TYPES_INPUTMEDIADOCUMENT_H

#include <string>
#include "tgbot/types/InputMedia.h"
#include <memory>
#include <variant>
#include "tools/http/InputFile.h"

namespace tgbot
{
	/**
	 * @struct InputMediaDocument
	 */
	struct InputMediaDocument : public InputMedia
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InputMediaDocument> ptr;

		//Member variables
		/**
		 * @var
		 */
		const std::string type = "document";
		/**
		 * @var
		 */
		std::variant<std::string, tools::InputFile::ptr> media;
		/**
		 * @var
		 */
		std::variant<std::string, tools::InputFile::ptr> thumb;
		/**
		 * @var
		 */
		std::string caption;
		/**
		 * @var
		 */
		std::string parse_mode;

		//Constructors
		InputMediaDocument();

		//@param json: json object of InputMediaDocument
		InputMediaDocument(const std::string &json);

		/**
		 * @param media: source of the document
		 * @param thumb: source of the thumb
		 * @param caption: caption under document
		 * @param parse_mode: how caption is parsed
		 */
		InputMediaDocument(const std::variant<std::string, tools::InputFile::ptr> &media, const std::variant<std::string, tools::InputFile::ptr> &thumb,
				const std::string &caption = "", const std::string &parse_mode = "");

		//Member functions
		/*
		 * @brief parses itself into json equivalent
		 * @return json object of itself as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
