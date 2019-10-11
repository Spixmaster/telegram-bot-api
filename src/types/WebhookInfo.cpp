#include "tgbot/types/WebhookInfo.h"

namespace tgbot
{
	WebhookInfo::WebhookInfo() : url(), has_custom_certificate(), pending_update_count(), last_error_date(), last_error_message(), max_connections(),
	allowed_updates()
	{}

	WebhookInfo::WebhookInfo(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		//assignments
		if(doc.HasMember("url"))
			url = doc["url"].GetString();

		if(doc.HasMember("has_custom_certificate"))
			has_custom_certificate = doc["has_custom_certificate"].GetBool();

		if(doc.HasMember("pending_update_count"))
			pending_update_count = doc["pending_update_count"].GetInt();

		if(doc.HasMember("last_error_date"))
			last_error_date = doc["last_error_date"].GetInt();

		if(doc.HasMember("last_error_message"))
			last_error_message = doc["last_error_message"].GetString();

		if(doc.HasMember("max_connections"))
			max_connections = doc["max_connections"].GetInt();

		if(doc.HasMember("allowed_updates"))
			for(std::size_t j = 0; j < doc["allowed_updates"].GetArray().Size(); ++j)
			{
				allowed_updates.resize(doc["allowed_updates"].GetArray().Size());

				allowed_updates.at(j) = doc["photo"][j].GetString();
			}
	}

	std::string WebhookInfo::parse_to_json() const
	{
		std::string json = "{";

		//field url
		json.append("\"url\": \"" + url + "\"");
		json.append(", ");

		//field has_custom_certificate
		std::string has_custom_certificate_bool = has_custom_certificate ? "true" : "false";
		json.append("\"has_custom_certificate\": \"" + has_custom_certificate_bool + "\"");
		json.append(", ");

		//field pending_update_count
		json.append("\"pending_update_count\": " + pending_update_count);
		json.append(", ");

		//field last_error_date
		json.append("\"last_error_date\": " + last_error_date);
		json.append(", ");

		//field last_error_message
		json.append("\"last_error_message\": \"" + last_error_message + "\"");
		json.append(", ");

		//field max_connections
		json.append("\"max_connections\": " + max_connections);
		json.append(", ");

		//field allowed_updates
		std::string allowed_updates_cont = "[";
		for(std::size_t j = 0; j < allowed_updates.size(); ++j)
		{
			allowed_updates_cont.append(allowed_updates.at(j));
			allowed_updates_cont.append(", ");
		}

		//if size() == 0 pop_back() would crash the programme
		if(allowed_updates.size() > 0)
		{
			//finish json array
			allowed_updates_cont.pop_back();
			allowed_updates_cont.pop_back();
		}
		allowed_updates_cont.append("]");

		json.append("\"allowed_updates\": " + allowed_updates_cont);

		json.append("}");

		return json;
	}
}
