#include "tgbot/types/ChatMember.h"
#include "tgbot/Tools.h"

namespace tgbot
{
	ChatMember::ChatMember() : user(), status(), until_date(), can_be_edited(), can_post_messages(), can_edit_messages(), can_delete_messages(), can_restrict_members(),
			can_promote_members(), can_change_info(), can_invite_users(), is_member(), can_send_messages(), can_send_media_messages(), can_send_polls(),
			can_send_other_messages(), can_add_web_page_previews()
	{}

	ChatMember::ChatMember(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("user"))
				user = std::make_shared<User>(SpecialTools::get_json_as_string(doc["user"]));

			if(doc.HasMember("status"))
				status = doc["status"].GetString();

			if(doc.HasMember("until_date"))
				until_date = doc["until_date"].GetInt();

			if(doc.HasMember("can_be_edited"))
				can_be_edited = doc["can_be_edited"].GetBool();

			if(doc.HasMember("can_post_messages"))
				can_post_messages = doc["can_post_messages"].GetBool();

			if(doc.HasMember("can_edit_messages"))
				can_edit_messages = doc["can_edit_messages"].GetBool();

			if(doc.HasMember("can_delete_messages"))
				can_delete_messages = doc["can_delete_messages"].GetBool();

			if(doc.HasMember("can_restrict_members"))
				can_restrict_members = doc["can_restrict_members"].GetBool();

			if(doc.HasMember("can_promote_members"))
				can_promote_members = doc["can_promote_members"].GetBool();

			if(doc.HasMember("can_change_info"))
				can_change_info = doc["can_change_info"].GetBool();

			if(doc.HasMember("can_invite_users"))
				can_invite_users = doc["can_invite_users"].GetBool();

			if(doc.HasMember("is_member"))
				is_member = doc["is_member"].GetBool();

			if(doc.HasMember("can_send_messages"))
				can_send_messages = doc["can_send_messages"].GetBool();

			if(doc.HasMember("can_send_media_messages"))
				can_send_media_messages = doc["can_send_media_messages"].GetBool();

			if(doc.HasMember("can_send_polls"))
				can_send_polls = doc["can_send_polls"].GetBool();

			if(doc.HasMember("can_send_other_messages"))
				can_send_other_messages = doc["can_send_other_messages"].GetBool();

			if(doc.HasMember("can_add_web_page_previews"))
				can_add_web_page_previews = doc["can_add_web_page_previews"].GetBool();
		}
	}

	std::string ChatMember::parse_to_json() const
	{
		std::string json = "{";

		//field user
		json.append("\"user\": " + user->parse_to_json());
		json.append(", ");

		//field status
		json.append("\"status\": \"" + status + "\"");
		json.append(", ");

		//field until_date
		json.append("\"until_date\": " + until_date);
		json.append(", ");

		//field can_be_edited
		std::string can_be_edited_bool = can_be_edited ? "true" : "false";
		json.append("\"can_be_edited\": " + can_be_edited_bool);
		json.append(", ");

		//field can_post_messages
		std::string can_post_messages_bool = can_post_messages ? "true" : "false";
		json.append("\"can_post_messages\": " + can_post_messages_bool);
		json.append(", ");

		//field can_edit_messages
		std::string can_edit_messages_bool = can_edit_messages ? "true" : "false";
		json.append("\"can_edit_messages\": " + can_edit_messages_bool);
		json.append(", ");

		//field can_delete_messages
		std::string can_delete_messages_bool = can_delete_messages ? "true" : "false";
		json.append("\"can_delete_messages\": " + can_delete_messages_bool);
		json.append(", ");

		//field can_restrict_members
		std::string can_restrict_members_bool = can_restrict_members ? "true" : "false";
		json.append("\"can_restrict_members\": " + can_restrict_members_bool);
		json.append(", ");

		//field can_restrict_members
		std::string can_promote_members_bool = can_promote_members ? "true" : "false";
		json.append("\"can_promote_members\": " + can_promote_members_bool);
		json.append(", ");

		//field can_change_info
		std::string can_change_info_bool = can_change_info ? "true" : "false";
		json.append("\"can_change_info\": " + can_change_info_bool);
		json.append(", ");

		//field can_invite_users
		std::string can_invite_users_bool = can_invite_users ? "true" : "false";
		json.append("\"can_invite_users\": " + can_invite_users_bool);
		json.append(", ");

		//field is_member
		std::string is_member_bool = is_member ? "true" : "false";
		json.append("\"is_member\": " + is_member_bool);
		json.append(", ");

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

		//field can_send_other_messages
		std::string can_add_web_page_previews_bool = can_add_web_page_previews ? "true" : "false";
		json.append("\"can_add_web_page_previews\": " + can_add_web_page_previews_bool);

		json.append("}");

		return json;
	}
}
