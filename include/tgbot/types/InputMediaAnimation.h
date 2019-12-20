#ifndef TGBOT_TYPES_INPUTMEDIAANIMATION_H
#define TGBOT_TYPES_INPUTMEDIAANIMATION_H

#include <string>
#include "tgbot/types/InputMedia.h"
#include <memory>
#include <variant>
#include "tools/http/InputFile.h"

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct InputMediaAnimation : public InputMedia
	{
		//pointer of itself
		typedef std::shared_ptr<InputMediaAnimation> ptr;

		//member variables
		const std::string type = "animation";
		std::variant<std::string, tools::InputFile::ptr> media;
		std::variant<std::string, tools::InputFile::ptr> thumb;
		std::string caption;
		std::string parse_mode;
		int width = -1;
		int height = -1;
		int duration = -1;

		//constructors
		InputMediaAnimation();

		//@param json: json object of InputMediaAnimation
		InputMediaAnimation(const std::string &json);

		//@param media: source of the animation
		//@param thumb: source of the thumb
		//@param caption: caption under animation
		//@param parse_mode: how caption is parsed
		//@param width: animation's width
		//@param height: animation's height
		//@param duration: animation's duration
		InputMediaAnimation(const std::variant<std::string, tools::InputFile::ptr> &media, const std::variant<std::string, tools::InputFile::ptr> &thumb, const std::string &caption = "",
				const std::string &parse_mode = "", const int &width = -1, const int &height = -1, const int &duration = -1);

		//member functions
		/*
		 * @brief parses itself into json equivalent
		 * @return json object of itself as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
