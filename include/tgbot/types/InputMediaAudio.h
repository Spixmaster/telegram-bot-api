#ifndef TGBOT_TYPES_INPUTMEDIAAUDIO_H
#define TGBOT_TYPES_INPUTMEDIAAUDIO_H

#include <string>
#include "tgbot/types/InputMedia.h"
#include <memory>
#include <variant>
#include "tools/http/InputFile.h"

namespace tgbot
{
	struct InputMediaAudio : public InputMedia
	{
		//pointer of itself
		typedef std::shared_ptr<InputMediaAudio> ptr;

		//member variables
		const std::string type = "audio";
		std::variant<std::string, tools::InputFile::ptr> media;
		std::variant<std::string, tools::InputFile::ptr> thumb;
		std::string caption;
		std::string parse_mode;
		int duration = -1;
		std::string performer;
		std::string title;

		//constructors
		InputMediaAudio();

		//@param json: json object of InputMediaAudio
		InputMediaAudio(const std::string &json);

		//@param media: source of the audio
		//@param thumb: source of the thumb
		//@param caption: caption under audio
		//@param parse_mode: how caption is parsed
		//@param duration: audio's duration
		//@param performer: audio's performer
		//@param title: audio's title
		InputMediaAudio(const std::variant<std::string, tools::InputFile::ptr> &media, const std::variant<std::string, tools::InputFile::ptr> &thumb, const std::string &caption = "",
				const std::string &parse_mode = "", const int &duration = -1, const std::string &performer = "", const std::string &title = "");

		//member functions

		/*
		 * @brief parses itself into json equivalent
		 * @return json object of itself as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
