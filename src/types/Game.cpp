#include "tgbot/types/Game.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

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
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("title"));
			}

			if(doc.HasMember("description"))
			{
				if(doc["description"].IsString())
					description = doc["description"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("description"));
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
							tools::Tools::write_err_log(Messages::field_element_does_not_contain_json_obj("photo"));
					}
				}
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_arr("photo"));
			}

			if(doc.HasMember("text"))
			{
				if(doc["text"].IsString())
					text = doc["text"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("text"));
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
							tools::Tools::write_err_log(Messages::field_element_does_not_contain_json_obj("text_entities"));
					}
				}
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_arr("text_entities"));
			}

			if(doc.HasMember("animation"))
			{
				if(doc["animation"].IsObject())
					animation = std::make_shared<Animation>(tools::Tools::get_json_as_string(doc["animation"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("animation"));
			}
		}
		else
			tools::Tools::write_err_log(Messages::constructor_not_get_json_object);
	}

	std::string Game::parse_to_json() const noexcept
	{
		std::string json = "{";

		//Field title
		json.append("\"title\": \"" + title + "\"");
		json.append(", ");

		//Field description
		json.append("\"description\": \"" + description + "\"");
		json.append(", ");

		//Field photo
		std::string photo_cont = "[";

		for(std::size_t j = 0; j < photo.size(); ++j)
		{
			photo_cont.append(photo.at(j)->parse_to_json());

			if(j != photo.size() -1)
				photo_cont.append(", ");
		}

		photo_cont.append("]");

		json.append("\"photo\": " + photo_cont);
		json.append(", ");

		//Field text
		json.append("\"text\": \"" + text + "\"");
		json.append(", ");

		//Field text_entities
		std::string text_entities_cont = "[";

		for(std::size_t j = 0; j < text_entities.size(); ++j)
		{
			text_entities_cont.append(text_entities.at(j)->parse_to_json());

			if(j != text_entities.size() - 1)
				text_entities_cont.append(", ");
		}

		text_entities_cont.append("]");

		json.append("\"text_entities\": " + text_entities_cont);
		json.append(", ");

		//Field animation
		json.append("\"animation\": " + animation->parse_to_json());

		json.append("}");
		return json;
	}
}
