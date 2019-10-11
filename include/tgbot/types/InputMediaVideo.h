#ifndef TGBOT_TYPES_INPUTMEDIAVIDEO_H
#define TGBOT_TYPES_INPUTMEDIAVIDEO_H

#include <string>
#include "InputMedia.h"
#include <memory>
#include <variant>
#include "tgbot/http/InputFile.h"

namespace tgbot
{
	struct InputMediaVideo : public InputMedia
	{
		//pointer of itself
		typedef std::shared_ptr<InputMediaVideo> ptr;

		//member variables
		const std::string type = "video";
		std::variant<std::string, InputFile::ptr> media;
		std::variant<std::string, InputFile::ptr> thumb;
		std::string caption;
		std::string parse_mode;
		int width = -1;
		int height = -1;
		int duration = -1;
		bool supports_streaming;

		//constructors
		InputMediaVideo();

		//@param json: json object of InputMediaVideo
		InputMediaVideo(const std::string &json);

		//@param media: source of the video
		//@param thumb: source of the thumb
		//@param caption: caption under video
		//@param parse_mode: how caption is parsed
		//@param width: video's width
		//@param height: video's height
		//@param duration: video's duration
		//@param supports_streaming: whether video can be streamed
		InputMediaVideo(const std::variant<std::string, InputFile::ptr> &media, const std::variant<std::string, InputFile::ptr> &thumb, const std::string &caption = "",
				const std::string &parse_mode = "", const int &width = -1, const int &height = -1, const int &duration = -1, const bool & supports_streaming = false);

		//member functions

		/*
		 * @brief parses itself into json equivalent
		 * @return json object of itself as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
