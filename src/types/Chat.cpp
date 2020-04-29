#include "tgbot/types/Chat.h"
#include "tgbot/types/ChatPhoto.h"
#include "tgbot/types/Message.h"
#include <memory>
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

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
			//Assignments
			if(doc.HasMember("id"))
			{
				if(doc["id"].IsInt64())
					id = doc["id"].GetInt64();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_int64("id"));
			}

			if(doc.HasMember("type"))
			{
				if(doc["type"].IsString())
					type = doc["type"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("type"));
			}

			if(doc.HasMember("title"))
			{
				if(doc["title"].IsString())
					title = doc["title"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("title"));
			}

			if(doc.HasMember("username"))
			{
				if(doc["username"].IsString())
					username = doc["username"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("username"));
			}

			if(doc.HasMember("first_name"))
			{
				if(doc["first_name"].IsString())
					first_name = doc["first_name"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("first_name"));
			}

			if(doc.HasMember("last_name"))
			{
				if(doc["last_name"].IsString())
					last_name = doc["last_name"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("last_name"));
			}

			if(doc.HasMember("photo"))
			{
				if(doc["photo"].IsObject())
					photo = std::make_shared<ChatPhoto>(tools::Tools::get_json_as_string(doc["photo"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("photo"));
			}

			if(doc.HasMember("description"))
			{
				if(doc["description"].IsString())
					description = doc["description"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("description"));
			}

			if(doc.HasMember("invite_link"))
			{
				if(doc["invite_link"].IsString())
					invite_link = doc["invite_link"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("invite_link"));
			}

			if(doc.HasMember("pinned_message"))
			{
				if(doc["pinned_message"].IsObject())
					pinned_message = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["pinned_message"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("pinned_message"));
			}

			if(doc.HasMember("permissions"))
			{
				if(doc["permissions"].IsObject())
					permissions = std::make_shared<ChatPermissions>(tools::Tools::get_json_as_string(doc["permissions"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("permissions"));
			}

			if(doc.HasMember("slow_mode_delay"))
			{
				if(doc["slow_mode_delay"].IsInt())
					slow_mode_delay = doc["slow_mode_delay"].GetInt();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_int("slow_mode_delay"));
			}

			if(doc.HasMember("sticker_set_name"))
			{
				if(doc["sticker_set_name"].IsString())
					sticker_set_name = doc["sticker_set_name"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("sticker_set_name"));
			}

			if(doc.HasMember("can_set_sticker_set"))
			{
				if(doc["can_set_sticker_set"].IsBool())
					can_set_sticker_set = doc["can_set_sticker_set"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("can_set_sticker_set"));
			}
		}
		else
			tools::Tools::write_err_log(Messages::constructor_not_get_json_object);
	}

	std::string Chat::parse_to_json() const noexcept
	{
		std::string json = "{";

		//Field id
		json.append("\"id\": " + id);
		json.append(", ");

		//Field type
		json.append("\"type\": \"" + type + "\"");
		json.append(", ");

		//Field title
		json.append("\"title\": \"" + title + "\"");
		json.append(", ");

		//Field username
		json.append("\"username\": \"" + username + "\"");
		json.append(", ");

		//Field first_name
		json.append("\"first_name\": \"" + first_name + "\"");
		json.append(", ");

		//Field last_name
		json.append("\"last_name\": \"" + last_name + "\"");
		json.append(", ");

		//Field photo
		json.append("\"photo\": " + photo->parse_to_json());
		json.append(", ");

		//Field description
		json.append("\"description\": \"" + description + "\"");
		json.append(", ");

		//Field invite_link
		json.append("\"invite_link\": \"" + invite_link + "\"");
		json.append(", ");

		//Field pinned_message
		json.append("\"pinned_message\": " + pinned_message->parse_to_json());
		json.append(", ");

		//Field permissions
		json.append("\"permissions\": " + permissions->parse_to_json());
		json.append(", ");

		//Field slow_mode_delay
		json.append("\"slow_mode_delay\": \"" + std::to_string(slow_mode_delay) + "\"");
		json.append(", ");

		//Field sticker_set_name
		json.append("\"sticker_set_name\": \"" + sticker_set_name + "\"");
		json.append(", ");

		//Field can_set_sticker_set
		std::string can_set_sticker_set_bool = can_set_sticker_set ? "true" : "false";
		json.append("\"can_set_sticker_set\": " + can_set_sticker_set_bool);

		json.append("}");
		return json;
	}
}
