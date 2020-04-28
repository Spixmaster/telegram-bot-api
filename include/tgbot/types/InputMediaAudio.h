#ifndef TGBOT_TYPES_INPUTMEDIAAUDIO_H
#define TGBOT_TYPES_INPUTMEDIAAUDIO_H

#include <string>
#include "tgbot/types/InputMedia.h"
#include <memory>
#include <variant>
#include "tools/http/InputFile.h"

namespace tgbot
{
	/**
	 * @struct InputMediaAudio
	 */
	struct InputMediaAudio : public InputMedia
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InputMediaAudio> ptr;

		//Member variables
		/**
		 * @var
		 */
		const std::string type = "audio";
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
		int duration = -1;
		/**
		 * @var
		 */
		std::string performer;
		/**
		 * @var
		 */
		std::string title;

		//Constructors
		InputMediaAudio();

		//@param json: json object of InputMediaAudio
		InputMediaAudio(const std::string &json);

		/**
		 * @param media: source of the audio
		 * @param thumb: source of the thumb
		 * @param caption: caption under audio
		 * @param parse_mode: how caption is parsed
		 * @param duration: audio's duration
		 * @param performer: audio's performer
		 * @param title: audio's title
		 */
		InputMediaAudio(const std::variant<std::string, tools::InputFile::ptr> &media, const std::variant<std::string, tools::InputFile::ptr> &thumb,
				const std::string &caption = "", const std::string &parse_mode = "", const int &duration = -1, const std::string &performer = "", const std::string &title = "");

		//Member functions
		/*
		 * @brief parses itself into json equivalent
		 * @return json object of itself as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
