#include "tgbot/types/Game.h"

namespace tgbot
{
	Game::Game() : title(), description(), photo(), text(), text_entities(), animation()
	{}

	Game::Game(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		//assignments
		if(doc.HasMember("title"))
			title = doc["title"].GetString();

		if(doc.HasMember("description"))
			description = doc["description"].GetString();

		if(doc.HasMember("photo"))
			for(std::size_t j = 0; j < doc["photo"].GetArray().Size(); ++j)
			{
				photo.resize(doc["photo"].GetArray().Size());

				photo.at(j) = std::make_shared<PhotoSize>(SpecialTools::get_json_obj_as_string(doc["thumb"][j]));
			}

		if(doc.HasMember("text"))
			text = doc["text"].GetString();

		if(doc.HasMember("text_entities"))
			for(std::size_t j = 0; j < doc["text_entities"].GetArray().Size(); ++j)
			{
				text_entities.resize(doc["text_entities"].GetArray().Size());

				text_entities.at(j) = std::make_shared<MessageEntity>(SpecialTools::get_json_obj_as_string(doc["text_entities"][j]));
			}

		if(doc.HasMember("animation"))
			animation = std::make_shared<Animation>(SpecialTools::get_json_obj_as_string(doc["animation"]));
	}

	std::string Game::parse_to_json() const
	{
		std::string json = "{";

		//field title
		json.append("\"title\": \"" + title + "\"");
		json.append(", ");

		//field description
		json.append("\"description\": \"" + description + "\"");
		json.append(", ");

		//field photo
		std::string photo_cont = "[";
		for(std::size_t j = 0; j < photo.size(); ++j)
		{
			photo_cont.append(photo.at(j)->parse_to_json());
			photo_cont.append(", ");
		}

		//if size() == 0 pop_back() would crash the programme
		if(photo.size() > 0)
		{
			//finish json array
			photo_cont.pop_back();
			photo_cont.pop_back();
		}
		photo_cont.append("]");

		json.append("\"photo\": " + photo_cont);
		json.append(", ");

		//field text
		json.append("\"text\": \"" + text + "\"");
		json.append(", ");

		//field text_entities
		std::string text_entities_cont = "[";
		for(std::size_t j = 0; j < text_entities.size(); ++j)
		{
			text_entities_cont.append(text_entities.at(j)->parse_to_json());
			text_entities_cont.append(", ");
		}

		//if size() == 0 pop_back() would crash the programme
		if(text_entities.size() > 0)
		{
			//finish json array
			text_entities_cont.pop_back();
			text_entities_cont.pop_back();
		}
		text_entities_cont.append("]");

		json.append("\"text_entities\": " + text_entities_cont);
		json.append(", ");

		//field animation
		json.append("\"animation\": " + animation->parse_to_json());

		json.append("}");

		return json;
	}
}
