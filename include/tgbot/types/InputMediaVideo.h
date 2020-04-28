#ifndef TGBOT_TYPES_INPUTMEDIAVIDEO_H
#define TGBOT_TYPES_INPUTMEDIAVIDEO_H

#include <string>
#include "InputMedia.h"
#include <memory>
#include <variant>
#include "tools/http/InputFile.h"

namespace tgbot
{
	/**
	 * @struct InputMediaVideo
	 */
	struct InputMediaVideo : public InputMedia
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InputMediaVideo> ptr;

		//Member variables
		/**
		 * @var
		 */
		const std::string type = "video";
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
		/**
		 * @var
		 */
		int width = -1;
		/**
		 * @var
		 */
		int height = -1;
		/**
		 * @var
		 */
		int duration = -1;
		/**
		 * @var
		 */
		bool supports_streaming;

		//Constructors
		InputMediaVideo();

		//@param json: json object of InputMediaVideo
		InputMediaVideo(const std::string &json);

		/**
		 * @param media: source of the video
		 * @param thumb: source of the thumb
		 * @param caption: caption under video
		 * @param parse_mode: how caption is parsed
		 * @param width: video's width
		 * @param height: video's height
		 * @param duration: video's duration
		 * @param supports_streaming: whether video can be streamed
		 */
		InputMediaVideo(const std::variant<std::string, tools::InputFile::ptr> &media, const std::variant<std::string, tools::InputFile::ptr> &thumb,
				const std::string &caption = "", const std::string &parse_mode = "", const int &width = -1, const int &height = -1, const int &duration = -1,
				const bool & supports_streaming = false);

		//Member functions
		/*
		 * @brief parses itself into json equivalent
		 * @return json object of itself as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
