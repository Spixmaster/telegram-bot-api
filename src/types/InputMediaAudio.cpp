#include <rapidjson/document.h>
#include "tgbot/types/InputMediaAudio.h"
#include "tools/Tools.h"
#include <iostream>

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
			{
				if(doc["media"].IsString())
					media = doc["media"].GetString();
				else
					std::cerr << "Error: Field \"media\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("thumb"))
			{
				if(doc["thumb"].IsString())
					thumb = doc["thumb"].GetString();
				else
					std::cerr << "Error: Field \"thumb\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("caption"))
			{
				if(doc["caption"].IsString())
					caption = doc["caption"].GetString();
				else
					std::cerr << "Error: Field \"caption\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("parse_mode"))
			{
				if(doc["parse_mode"].IsString())
					parse_mode = doc["parse_mode"].GetString();
				else
					std::cerr << "Error: Field \"parse_mode\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("duration"))
			{
				if(doc["duration"].IsInt())
					duration = doc["duration"].GetInt();
				else
					std::cerr << "Error: Field \"duration\" does not contain an int." << std::endl;
			}

			if(doc.HasMember("performer"))
			{
				if(doc["performer"].IsString())
					performer = doc["performer"].GetString();
				else
					std::cerr << "Error: Field \"performer\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("title"))
			{
				if(doc["title"].IsString())
					title = doc["title"].GetString();
				else
					std::cerr << "Error: Field \"title\" does not contain a string." << std::endl;
			}
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
	}

	InputMediaAudio::InputMediaAudio(const std::variant<std::string, tools::InputFile::ptr> &media, const std::variant<std::string, tools::InputFile::ptr> &thumb,
			const std::string &caption, const std::string &parse_mode, const int &duration, const std::string &performer, const std::string &title) :
					media(media), thumb(thumb), caption(caption), parse_mode(parse_mode), duration(duration), performer(performer), title(title)
	{}

	std::string InputMediaAudio::parse_to_json() const noexcept
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
		else if(std::holds_alternative<tools::InputFile::ptr>(media))
		{
			json.append("\"media\": \"attach://" + std::get<tools::InputFile::ptr>(media)->m_path + "\"");
			json.append(", ");
		}

		//field thumb
		if(std::holds_alternative<std::string>(thumb))
		{
			json.append("\"thumb\": \"" + std::get<std::string>(thumb) + "\"");
			json.append(", ");
		}
		else if(std::holds_alternative<tools::InputFile::ptr>(thumb))
		{
			json.append("\"thumb\": \"attach://" + std::get<tools::InputFile::ptr>(thumb)->m_path + "\"");
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
