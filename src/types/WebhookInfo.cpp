#include "tgbot/types/WebhookInfo.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	WebhookInfo::WebhookInfo() : url(), has_custom_certificate(), pending_update_count(), last_error_date(), last_error_message(), max_connections(),
	allowed_updates()
	{}

	WebhookInfo::WebhookInfo(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//Assignments
			if(doc.HasMember("url"))
			{
				if(doc["url"].IsString())
					url = doc["url"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("url"));
			}

			if(doc.HasMember("has_custom_certificate"))
			{
				if(doc["has_custom_certificate"].IsBool())
					has_custom_certificate = doc["has_custom_certificate"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("has_custom_certificate"));
			}

			if(doc.HasMember("pending_update_count"))
			{
				if(doc["pending_update_count"].IsInt())
					pending_update_count = doc["pending_update_count"].GetInt();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_int("pending_update_count"));
			}

			if(doc.HasMember("last_error_date"))
			{
				if(doc["last_error_date"].IsInt())
					last_error_date = doc["last_error_date"].GetInt();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_int("last_error_date"));
			}

			if(doc.HasMember("last_error_message"))
			{
				if(doc["last_error_message"].IsString())
					last_error_message = doc["last_error_message"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("last_error_message"));
			}

			if(doc.HasMember("max_connections"))
			{
				if(doc["max_connections"].IsInt())
					max_connections = doc["max_connections"].GetInt();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_int("max_connections"));
			}

			if(doc.HasMember("allowed_updates"))
			{
				if(doc["allowed_updates"].IsArray())
				{
					for(std::size_t j = 0; j < doc["allowed_updates"].GetArray().Size(); ++j)
					{
						if(doc["allowed_updates"][j].IsObject())
							allowed_updates.push_back(doc["allowed_updates"][j].GetString());
						else
							tools::Tools::write_err_log(Messages::field_element_does_not_contain_json_obj("allowed_updates"));
					}
				}
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_arr("allowed_updates"));
			}
		}
		else
			tools::Tools::write_err_log(Messages::constructor_not_get_json_object);
	}

	std::string WebhookInfo::parse_to_json() const noexcept
	{
		std::string json = "{";

		//Field url
		json.append("\"url\": \"" + url + "\"");
		json.append(", ");

		//Field has_custom_certificate
		std::string has_custom_certificate_bool = has_custom_certificate ? "true" : "false";
		json.append("\"has_custom_certificate\": " + has_custom_certificate_bool);
		json.append(", ");

		//Field pending_update_count
		json.append("\"pending_update_count\": " + pending_update_count);
		json.append(", ");

		//Field last_error_date
		json.append("\"last_error_date\": " + last_error_date);
		json.append(", ");

		//Field last_error_message
		json.append("\"last_error_message\": \"" + last_error_message + "\"");
		json.append(", ");

		//Field max_connections
		json.append("\"max_connections\": " + max_connections);
		json.append(", ");

		//Field allowed_updates
		std::string allowed_updates_cont = "[";

		for(std::size_t j = 0; j < allowed_updates.size(); ++j)
		{
			allowed_updates_cont.append(allowed_updates.at(j));

			if(j != allowed_updates.size() - 1)
				allowed_updates_cont.append(", ");
		}

		allowed_updates_cont.append("]");

		json.append("\"allowed_updates\": " + allowed_updates_cont);

		json.append("}");
		return json;
	}
}
