#include "tgbot/types/CallbackQuery.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	CallbackQuery::CallbackQuery() : id(), from(), message(), inline_message_id(), chat_instance(), data(), game_short_name()
	{}

	CallbackQuery::CallbackQuery(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//Assignments
			if(doc.HasMember("id"))
			{
				if(doc["id"].IsString())
					id = doc["id"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("id"));
			}

			if(doc.HasMember("from"))
			{
				if(doc["from"].IsObject())
					from = std::make_shared<User>(tools::Tools::get_json_as_string(doc["from"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("from"));
			}

			if(doc.HasMember("message"))
			{
				if(doc["message"].IsObject())
					message = std::make_shared<Message>(tools::Tools::get_json_as_string(doc["message"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("message"));
			}

			if(doc.HasMember("inline_message_id"))
			{
				if(doc["inline_message_id"].IsString())
					inline_message_id = doc["inline_message_id"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("inline_message_id"));
			}

			if(doc.HasMember("chat_instance"))
			{
				if(doc["chat_instance"].IsString())
					chat_instance = doc["chat_instance"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("chat_instance"));
			}

			if(doc.HasMember("data"))
			{
				if(doc["data"].IsString())
					data = doc["data"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("data"));
			}

			if(doc.HasMember("game_short_name"))
			{
				if(doc["game_short_name"].IsString())
					game_short_name = doc["game_short_name"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("game_short_name"));
			}
		}
		else
			tools::Tools::write_err_log(Messages::constructor_not_get_json_object);
	}

	std::string CallbackQuery::parse_to_json() const noexcept
	{
		std::string json = "{";

		//Field id
		json.append("\"id\": \"" + id + "\"");
		json.append(", ");

		//Field from
		json.append("\"from\": " + from->parse_to_json());
		json.append(", ");

		//Field message
		json.append("\"message\": " + message->parse_to_json());
		json.append(", ");

		//Field inline_message_id
		json.append("\"inline_message_id\": \"" + inline_message_id + "\"");
		json.append(", ");

		//Field chat_instance
		json.append("\"chat_instance\": \"" + chat_instance + "\"");
		json.append(", ");

		//Field data
		json.append("\"data\": \"" + data + "\"");
		json.append(", ");

		//Field game_short_name
		json.append("\"game_short_name\": \"" + game_short_name + "\"");

		json.append("}");

		return json;
	}
}
