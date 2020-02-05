#include "tgbot/types/ChatMember.h"
#include "tools/Tools.h"
#include <iostream>

namespace tgbot
{
	ChatMember::ChatMember() : user(), status(), custom_title(), until_date(), can_be_edited(), can_post_messages(), can_edit_messages(), can_delete_messages(),
			can_restrict_members(), can_promote_members(), can_change_info(), can_invite_users(), can_pin_messages(), is_member(), can_send_messages(), can_send_media_messages(),
			can_send_polls(), can_send_other_messages(), can_add_web_page_previews()
	{}

	ChatMember::ChatMember(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("user"))
			{
				if(doc["user"].IsObject())
					user = std::make_shared<User>(tools::Tools::get_json_as_string(doc["user"]));
				else
					std::cerr << "Error: Field \"user\" does not contain a json object." << std::endl;
			}

			if(doc.HasMember("status"))
			{
				if(doc["status"].IsString())
					status = doc["status"].GetString();
				else
					std::cerr << "Error: Field \"status\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("custom_title"))
			{
				if(doc["custom_title"].IsString())
					custom_title = doc["custom_title"].GetString();
				else
					std::cerr << "Error: Field \"custom_title\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("until_date"))
			{
				if(doc["until_date"].IsInt())
					until_date = doc["until_date"].GetInt();
				else
					std::cerr << "Error: Field \"until_date\" does not contain an int." << std::endl;
			}

			if(doc.HasMember("can_be_edited"))
			{
				if(doc["can_be_edited"].IsBool())
					can_be_edited = doc["can_be_edited"].GetBool();
				else
					std::cerr << "Error: Field \"can_be_edited\" does not contain a bool." << std::endl;
			}

			if(doc.HasMember("can_post_messages"))
			{
				if(doc["can_post_messages"].IsBool())
					can_post_messages = doc["can_post_messages"].GetBool();
				else
					std::cerr << "Error: Field \"can_post_messages\" does not contain a bool." << std::endl;
			}

			if(doc.HasMember("can_edit_messages"))
			{
				if(doc["can_edit_messages"].IsBool())
					can_edit_messages = doc["can_edit_messages"].GetBool();
				else
					std::cerr << "Error: Field \"can_edit_messages\" does not contain a bool." << std::endl;
			}

			if(doc.HasMember("can_delete_messages"))
			{
				if(doc["can_delete_messages"].IsBool())
					can_delete_messages = doc["can_delete_messages"].GetBool();
				else
					std::cerr << "Error: Field \"can_delete_messages\" does not contain a bool." << std::endl;
			}

			if(doc.HasMember("can_restrict_members"))
			{
				if(doc["can_restrict_members"].IsBool())
					can_restrict_members = doc["can_restrict_members"].GetBool();
				else
					std::cerr << "Error: Field \"can_restrict_members\" does not contain a bool." << std::endl;
			}

			if(doc.HasMember("can_promote_members"))
			{
				if(doc["can_promote_members"].IsBool())
					can_promote_members = doc["can_promote_members"].GetBool();
				else
					std::cerr << "Error: Field \"can_promote_members\" does not contain a bool." << std::endl;
			}

			if(doc.HasMember("can_change_info"))
			{
				if(doc["can_change_info"].IsBool())
					can_change_info = doc["can_change_info"].GetBool();
				else
					std::cerr << "Error: Field \"can_change_info\" does not contain a bool." << std::endl;
			}

			if(doc.HasMember("can_invite_users"))
			{
				if(doc["can_invite_users"].IsBool())
					can_invite_users = doc["can_invite_users"].GetBool();
				else
					std::cerr << "Error: Field \"can_invite_users\" does not contain a bool." << std::endl;
			}

			if(doc.HasMember("can_pin_messages"))
			{
				if(doc["can_pin_messages"].IsBool())
					can_pin_messages = doc["can_pin_messages"].GetBool();
				else
					std::cerr << "Error: Field \"can_pin_messages\" does not contain a bool." << std::endl;
			}

			if(doc.HasMember("is_member"))
			{
				if(doc["is_member"].IsBool())
					is_member = doc["is_member"].GetBool();
				else
					std::cerr << "Error: Field \"is_member\" does not contain a bool." << std::endl;
			}

			if(doc.HasMember("can_send_messages"))
			{
				if(doc["can_send_messages"].IsBool())
					can_send_messages = doc["can_send_messages"].GetBool();
				else
					std::cerr << "Error: Field \"can_send_messages\" does not contain a bool." << std::endl;
			}

			if(doc.HasMember("can_send_media_messages"))
			{
				if(doc["can_send_media_messages"].IsBool())
					can_send_media_messages = doc["can_send_media_messages"].GetBool();
				else
					std::cerr << "Error: Field \"can_send_media_messages\" does not contain a bool." << std::endl;
			}

			if(doc.HasMember("can_send_polls"))
			{
				if(doc["can_send_polls"].IsBool())
					can_send_polls = doc["can_send_polls"].GetBool();
				else
					std::cerr << "Error: Field \"can_send_polls\" does not contain a bool." << std::endl;
			}

			if(doc.HasMember("can_send_other_messages"))
			{
				if(doc["can_send_other_messages"].IsBool())
					can_send_other_messages = doc["can_send_other_messages"].GetBool();
				else
					std::cerr << "Error: Field \"can_send_other_messages\" does not contain a bool." << std::endl;
			}

			if(doc.HasMember("can_add_web_page_previews"))
			{
				if(doc["can_add_web_page_previews"].IsBool())
					can_add_web_page_previews = doc["can_add_web_page_previews"].GetBool();
				else
					std::cerr << "Error: Field \"can_add_web_page_previews\" does not contain a bool." << std::endl;
			}
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
	}

	std::string ChatMember::parse_to_json() const noexcept
	{
		std::string json = "{";

		//field user
		json.append("\"user\": " + user->parse_to_json());
		json.append(", ");

		//field status
		json.append("\"status\": \"" + status + "\"");
		json.append(", ");

		//field custom_title
		json.append("\"custom_title\": \"" + custom_title + "\"");
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

		//field can_pin_messages
		std::string can_pin_messages_bool = can_pin_messages ? "true" : "false";
		json.append("\"can_pin_messages\": " + can_pin_messages_bool);
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
