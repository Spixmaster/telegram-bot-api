#include "tgbot/types/Chat.h"
#include "tgbot/types/ChatPhoto.h"
#include "tgbot/types/Message.h"
#include <memory>
#include "tools/Tools.h"
#include <iostream>

namespace tgbot
{
	Chat::Chat() : id(), type(), title(), username(), first_name(), last_name(), photo(), description(), invite_link(), pinned_message(), permissions(), slow_mode_delay(),
			sticker_set_name(), can_set_sticker_set()
	{}

	Chat::Chat(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("id"))
				if(doc["id"].IsInt64())
					id = doc["id"].GetInt64();
				else
					std::cerr << "Error: Field \"id\" does not contain an int 64." << std::endl;
			else
				std::cerr << "Error: There is no field \"id\"." << std::endl;

			if(doc.HasMember("type"))
				if(doc["type"].IsString())
					type = doc["type"].GetString();
				else
					std::cerr << "Error: Field \"type\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"type\"." << std::endl;

			if(doc.HasMember("title"))
				if(doc["title"].IsString())
					title = doc["title"].GetString();
				else
					std::cerr << "Error: Field \"title\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"title\"." << std::endl;

			if(doc.HasMember("username"))
				if(doc["username"].IsString())
					username = doc["username"].GetString();
				else
					std::cerr << "Error: Field \"username\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"username\"." << std::endl;

			if(doc.HasMember("first_name"))
				if(doc["first_name"].IsString())
					first_name = doc["first_name"].GetString();
				else
					std::cerr << "Error: Field \"first_name\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"first_name\"." << std::endl;

			if(doc.HasMember("last_name"))
				if(doc["last_name"].IsString())
					last_name = doc["last_name"].GetString();
				else
					std::cerr << "Error: Field \"last_name\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"last_name\"." << std::endl;

			if(doc.HasMember("photo"))
				if(doc["photo"].IsObject())
					photo = std::make_shared<ChatPhoto>(tools::Tools::get_json_as_string(doc["photo"]));
				else
					std::cerr << "Error: Field \"photo\" does not contain a json object." << std::endl;
			else
				std::cerr << "Error: There is no field \"photo\"." << std::endl;

			if(doc.HasMember("description"))
				if(doc["description"].IsString())
					description = doc["description"].GetString();
				else
					std::cerr << "Error: Field \"description\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"description\"." << std::endl;

			if(doc.HasMember("invite_link"))
				if(doc["invite_link"].IsString())
					invite_link = doc["invite_link"].GetString();
				else
					std::cerr << "Error: Field \"invite_link\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"invite_link\"." << std::endl;

			if(doc.HasMember("pinned_message"))
				if(doc["pinned_message"].IsObject())
					pinned_message = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["pinned_message"]));
				else
					std::cerr << "Error: Field \"pinned_message\" does not contain a json object." << std::endl;
			else
				std::cerr << "Error: There is no field \"pinned_message\"." << std::endl;

			if(doc.HasMember("permissions"))
				if(doc["permissions"].IsObject())
					permissions = std::make_shared<ChatPermissions>(tools::Tools::get_json_as_string(doc["permissions"]));
				else
					std::cerr << "Error: Field \"permissions\" does not contain a json object." << std::endl;
			else
				std::cerr << "Error: There is no field \"permissions\"." << std::endl;

			if(doc.HasMember("slow_mode_delay"))
				if(doc["slow_mode_delay"].IsInt())
					slow_mode_delay = doc["slow_mode_delay"].GetInt();
				else
					std::cerr << "Error: Field \"slow_mode_delay\" does not contain an int." << std::endl;
			else
				std::cerr << "Error: There is no field \"slow_mode_delay\"." << std::endl;

			if(doc.HasMember("sticker_set_name"))
				if(doc["sticker_set_name"].IsString())
					sticker_set_name = doc["sticker_set_name"].GetString();
				else
					std::cerr << "Error: Field \"sticker_set_name\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"sticker_set_name\"." << std::endl;

			if(doc.HasMember("can_set_sticker_set"))
				if(doc["can_set_sticker_set"].IsBool())
					can_set_sticker_set = doc["can_set_sticker_set"].GetBool();
				else
					std::cerr << "Error: Field \"can_set_sticker_set\" does not contain a bool." << std::endl;
			else
				std::cerr << "Error: There is no field \"can_set_sticker_set\"." << std::endl;
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
	}

	std::string Chat::parse_to_json() const
	{
		std::string json = "{";

		//field id
		json.append("\"id\": " + id);
		json.append(", ");

		//field type
		json.append("\"type\": \"" + type + "\"");
		json.append(", ");

		//field title
		json.append("\"title\": \"" + title + "\"");
		json.append(", ");

		//field username
		json.append("\"username\": \"" + username + "\"");
		json.append(", ");

		//field first_name
		json.append("\"first_name\": \"" + first_name + "\"");
		json.append(", ");

		//field last_name
		json.append("\"last_name\": \"" + last_name + "\"");
		json.append(", ");

		//field photo
		json.append("\"photo\": " + photo->parse_to_json());
		json.append(", ");

		//field description
		json.append("\"description\": \"" + description + "\"");
		json.append(", ");

		//field invite_link
		json.append("\"invite_link\": \"" + invite_link + "\"");
		json.append(", ");

		//field pinned_message
		json.append("\"pinned_message\": " + pinned_message->parse_to_json());
		json.append(", ");

		//field permissions
		json.append("\"permissions\": " + permissions->parse_to_json());
		json.append(", ");

		//field slow_mode_delay
		json.append("\"slow_mode_delay\": \"" + std::to_string(slow_mode_delay) + "\"");
		json.append(", ");

		//field sticker_set_name
		json.append("\"sticker_set_name\": \"" + sticker_set_name + "\"");
		json.append(", ");

		//field can_set_sticker_set
		std::string can_set_sticker_set_bool = can_set_sticker_set ? "true" : "false";
		json.append("\"can_set_sticker_set\": " + can_set_sticker_set_bool);

		json.append("}");

		return json;
	}
}
