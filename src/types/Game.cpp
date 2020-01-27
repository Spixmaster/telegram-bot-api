#include "tgbot/types/Game.h"
#include "tools/Tools.h"
#include <iostream>

namespace tgbot
{
	Game::Game() : title(), description(), photo(), text(), text_entities(), animation()
	{}

	Game::Game(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			if(doc.HasMember("title"))
			{
				if(doc["title"].IsString())
					title = doc["title"].GetString();
				else
					std::cerr << "Error: Field \"title\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("description"))
			{
				if(doc["description"].IsString())
					description = doc["description"].GetString();
				else
					std::cerr << "Error: Field \"description\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("photo"))
			{
				if(doc["photo"].IsArray())
				{
					photo.resize(doc["photo"].GetArray().Size());

					for(std::size_t j = 0; j < doc["photo"].GetArray().Size(); ++j)
					{
						if(doc["photo"][j].IsObject())
							photo.at(j) = std::make_shared<PhotoSize>(tools::Tools::get_json_as_string(doc["photo"][j]));
						else
							std::cerr << "Error: Field \"photo\"'s json array's element is not a json object." << std::endl;
					}
				}
				else
					std::cerr << "Error: Field \"photo\" does not contain a json array." << std::endl;
			}

			if(doc.HasMember("text"))
			{
				if(doc["text"].IsString())
					text = doc["text"].GetString();
				else
					std::cerr << "Error: Field \"text\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("text_entities"))
			{
				if(doc["text_entities"].IsArray())
				{
					text_entities.resize(doc["text_entities"].GetArray().Size());

					for(std::size_t j = 0; j < doc["text_entities"].GetArray().Size(); ++j)
					{
						if(doc["text_entities"][j].IsObject())
							text_entities.at(j) = std::make_shared<MessageEntity>(tools::Tools::get_json_as_string(doc["text_entities"][j]));
						else
							std::cerr << "Error: Field \"text_entities\"'s json array's element is not a json object." << std::endl;
					}
				}
				else
					std::cerr << "Error: Field \"text_entities\" does not contain a json array." << std::endl;
			}

			if(doc.HasMember("animation"))
			{
				if(doc["animation"].IsObject())
					animation = std::make_shared<Animation>(tools::Tools::get_json_as_string(doc["animation"]));
				else
					std::cerr << "Error: Field \"animation\" does not contain a json object." << std::endl;
			}
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
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

		/*
		 * if size() == 0 pop_back() would crash the programme
		 * photo and not photo_cont in condition as in that case we would destroy the json array
		 */
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

		/*
		 * if size() == 0 pop_back() would crash the programme
		 * text_entities and not text_entities_cont in condition as in that case we would destroy the json array
		 */
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
