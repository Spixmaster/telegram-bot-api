#include <tgbot/SpecialTools.h>
#include "tgbot/types/Chat.h"
#include "tgbot/types/ChatPhoto.h"
#include "tgbot/types/Message.h"
#include <memory>
#include "tgbot/Tools.h"

namespace tgbot
{
	Chat::Chat() : id(), type(), title(), username(), first_name(), last_name(), photo(), description(), invite_link(), pinned_message(), permissions(),
			sticker_set_name(), can_set_sticker_set()
	{}

	Chat::Chat(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(Tools::is_json(json))
		{
			//assignments
			if(doc.HasMember("id"))
				id = doc["id"].GetInt64();

			if(doc.HasMember("type"))
				type = doc["type"].GetString();

			if(doc.HasMember("title"))
				title = doc["title"].GetString();

			if(doc.HasMember("username"))
				username = doc["username"].GetString();

			if(doc.HasMember("first_name"))
				first_name = doc["first_name"].GetString();

			if(doc.HasMember("last_name"))
				last_name = doc["last_name"].GetString();

			if(doc.HasMember("photo"))
				photo = std::make_shared<ChatPhoto>(SpecialTools::get_json_as_string(doc["photo"]));

			if(doc.HasMember("description"))
				description = doc["description"].GetString();

			if(doc.HasMember("invite_link"))
				invite_link = doc["invite_link"].GetString();

			if(doc.HasMember("pinned_message"))
				pinned_message = std::make_shared<Message>(SpecialTools::get_json_as_string(doc["pinned_message"]));

			if(doc.HasMember("permissions"))
				permissions = std::make_shared<ChatPermissions>(SpecialTools::get_json_as_string(doc["permissions"]));

			if(doc.HasMember("sticker_set_name"))
				sticker_set_name = doc["sticker_set_name"].GetString();

			if(doc.HasMember("can_set_sticker_set"))
				can_set_sticker_set = doc["can_set_sticker_set"].GetBool();
		}
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
