#include "tgbot/types/ChatPermissions.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	ChatPermissions::ChatPermissions() : can_send_messages(), can_send_media_messages(), can_send_polls(), can_send_other_messages(), can_add_web_page_preview(),
			can_change_info(), can_invite_users(), can_pin_messages()
	{}

	ChatPermissions::ChatPermissions(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//Assignments
			if(doc.HasMember("can_send_messages"))
			{
				if(doc["can_send_messages"].IsBool())
					can_send_messages = doc["can_send_messages"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("can_send_messages"));
			}

			if(doc.HasMember("can_send_media_messages"))
			{
				if(doc["can_send_media_messages"].IsBool())
					can_send_media_messages = doc["can_send_media_messages"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("can_send_media_messages"));
			}

			if(doc.HasMember("can_send_polls"))
			{
				if(doc["can_send_polls"].IsBool())
					can_send_polls = doc["can_send_polls"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("can_send_polls"));
			}

			if(doc.HasMember("can_send_other_messages"))
			{
				if(doc["can_send_other_messages"].IsBool())
					can_send_other_messages = doc["can_send_other_messages"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("can_send_other_messages"));
			}

			if(doc.HasMember("can_add_web_page_preview"))
			{
				if(doc["can_add_web_page_preview"].IsBool())
					can_add_web_page_preview = doc["can_add_web_page_preview"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("can_add_web_page_preview"));
			}

			if(doc.HasMember("can_change_info"))
			{
				if(doc["can_change_info"].IsBool())
					can_change_info = doc["can_change_info"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("can_change_info"));
			}

			if(doc.HasMember("can_invite_users"))
			{
				if(doc["can_invite_users"].IsBool())
					can_invite_users = doc["can_invite_users"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("can_invite_users"));
			}

			if(doc.HasMember("can_pin_messages"))
			{
				if(doc["can_pin_messages"].IsBool())
					can_pin_messages = doc["can_pin_messages"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("can_pin_messages"));
			}
		}
		else
			tools::Tools::write_err_log(Messages::constructor_not_get_json_object);
	}

	std::string ChatPermissions::parse_to_json() const noexcept
	{
		std::string json = "{";

		//Field can_send_messages
		std::string can_send_messages_bool = can_send_messages ? "true" : "false";
		json.append("\"can_send_messages\": " + can_send_messages_bool);
		json.append(", ");

		//Field can_send_media_messages
		std::string can_send_media_messages_bool = can_send_media_messages ? "true" : "false";
		json.append("\"can_send_media_messages\": " + can_send_media_messages_bool);
		json.append(", ");

		//Field can_send_polls
		std::string can_send_polls_bool = can_send_polls ? "true" : "false";
		json.append("\"can_send_polls\": " + can_send_polls_bool);
		json.append(", ");

		//Field can_send_other_messages
		std::string can_send_other_messages_bool = can_send_other_messages ? "true" : "false";
		json.append("\"can_send_other_messages\": " + can_send_other_messages_bool);
		json.append(", ");

		//Field can_add_web_page_preview
		std::string can_add_web_page_preview_bool = can_add_web_page_preview ? "true" : "false";
		json.append("\"can_add_web_page_preview\": " + can_add_web_page_preview_bool);
		json.append(", ");

		//Field can_change_info
		std::string can_change_info_bool = can_change_info ? "true" : "false";
		json.append("\"can_change_info\": " + can_change_info_bool);
		json.append(", ");

		//Field can_invite_users
		std::string can_invite_users_bool = can_invite_users ? "true" : "false";
		json.append("\"can_invite_users\": " + can_invite_users_bool);
		json.append(", ");

		//Field can_pin_messages
		std::string can_pin_messages_bool = can_pin_messages ? "true" : "false";
		json.append("\"can_pin_messages\": " + can_pin_messages_bool);

		json.append("}");
		return json;
	}
}
