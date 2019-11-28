#include <rapidjson/document.h>
#include "tgbot/types/InputMediaAudio.h"
#include "tgbot/Tools.h"

namespace tgbot
{
	InputMediaAudio::InputMediaAudio() : media(), thumb(), caption(), parse_mode(), duration(), performer(), title()
	{}

	InputMediaAudio::InputMediaAudio(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("media"))
				media = doc["media"].GetString();

			if(doc.HasMember("thumb"))
				thumb = doc["thumb"].GetString();

			if(doc.HasMember("caption"))
				caption = doc["caption"].GetString();

			if(doc.HasMember("parse_mode"))
				parse_mode = doc["parse_mode"].GetString();

			if(doc.HasMember("duration"))
				duration = doc["duration"].GetInt();

			if(doc.HasMember("performer"))
				performer = doc["performer"].GetString();

			if(doc.HasMember("title"))
				title = doc["title"].GetString();
		}
	}

	InputMediaAudio::InputMediaAudio(const std::variant<std::string, InputFile::ptr> &media, const std::variant<std::string, InputFile::ptr> &thumb, const std::string &caption,
				const std::string &parse_mode, const int &duration, const std::string &performer, const std::string &title) :
					media(media), thumb(thumb), caption(caption), parse_mode(parse_mode), duration(duration), performer(performer), title(title)
	{}

	std::string InputMediaAudio::parse_to_json() const
	{
		std::string json = "{";

		//field type
		json.append("\"type\": \"" + type + "\"");
		json.append(", ");

		//field media
		if(std::holds_alternative<std::string>(media))
		{
			json.append("\"media\": \"" + std::get<std::string>(media) + "\"");
			json.append(", ");
		}
		//of type InputFile
		else
		{
			json.append("\"media\": \"attach://" + std::get<InputFile::ptr>(media)->m_path + "\"");
			json.append(", ");
		}

		//field thumb
		if(std::holds_alternative<std::string>(thumb))
		{
			json.append("\"thumb\": \"" + std::get<std::string>(thumb) + "\"");
			json.append(", ");
		}
		//of type InputFile
		else
		{
			json.append("\"thumb\": \"attach://" + std::get<InputFile::ptr>(thumb)->m_path + "\"");
			json.append(", ");
		}

		//field caption
		json.append("\"caption\": \"" + caption + "\"");
		json.append(", ");

		//field parse_mode
		json.append("\"parse_mode\": \"" + parse_mode + "\"");
		json.append(", ");

		//field duration
		json.append("\"duration\": " + std::to_string(duration));
		json.append(", ");

		//field performer
		json.append("\"performer\": \"" + performer + "\"");
		json.append(", ");

		//field title
		json.append("\"title\":  \"" + title + "\"");

		json.append("}");

		return json;
	}
}
