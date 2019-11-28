#include "tgbot/types/ChatPermissions.h"
#include "tgbot/Tools.h"

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
			//assignments
			if(doc.HasMember("can_send_messages"))
				can_send_messages = doc["can_send_messages"].GetBool();

			if(doc.HasMember("can_send_media_messages"))
				can_send_media_messages = doc["can_send_media_messages"].GetBool();

			if(doc.HasMember("can_send_polls"))
				can_send_polls = doc["can_send_polls"].GetBool();

			if(doc.HasMember("can_send_other_messages"))
				can_send_other_messages = doc["can_send_other_messages"].GetBool();

			if(doc.HasMember("can_add_web_page_preview"))
				can_add_web_page_preview = doc["can_add_web_page_preview"].GetBool();

			if(doc.HasMember("can_change_info"))
				can_change_info = doc["can_change_info"].GetBool();

			if(doc.HasMember("can_invite_users"))
				can_invite_users = doc["can_invite_users"].GetBool();

			if(doc.HasMember("can_pin_messages"))
				can_pin_messages = doc["can_pin_messages"].GetBool();
		}
	}

	std::string ChatPermissions::parse_to_json()
	{
		std::string json = "{";

		//field can_send_messages
		std::string can_send_messages_bool = can_send_messages ? "true" : "false";
		json.append("\"can_send_messages\": " + can_send_messages_bool);
		json.append(", ");

		//field can_send_media_messages
		std::string can_send_media_messages_bool = can_send_media_messages ? "true" : "false";
		json.append("\"can_send_media_messages\": " + can_send_media_messages_bool);
		json.append(", ");

		//field can_send_polls
		std::string can_send_polls_bool = can_send_polls ? "true" : "false";
		json.append("\"can_send_polls\": " + can_send_polls_bool);
		json.append(", ");

		//field can_send_other_messages
		std::string can_send_other_messages_bool = can_send_other_messages ? "true" : "false";
		json.append("\"can_send_other_messages\": " + can_send_other_messages_bool);
		json.append(", ");

		//field can_add_web_page_preview
		std::string can_add_web_page_preview_bool = can_add_web_page_preview ? "true" : "false";
		json.append("\"can_add_web_page_preview\": " + can_add_web_page_preview_bool);
		json.append(", ");

		//field can_change_info
		std::string can_change_info_bool = can_change_info ? "true" : "false";
		json.append("\"can_change_info\": " + can_change_info_bool);
		json.append(", ");

		//field can_invite_users
		std::string can_invite_users_bool = can_invite_users ? "true" : "false";
		json.append("\"can_invite_users\": " + can_invite_users_bool);
		json.append(", ");

		//field can_pin_messages
		std::string can_pin_messages_bool = can_pin_messages ? "true" : "false";
		json.append("\"can_pin_messages\": " + can_pin_messages_bool);

		json.append("}");

		return json;
	}
}
