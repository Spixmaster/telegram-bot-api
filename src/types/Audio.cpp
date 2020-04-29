#include "tgbot/types/Audio.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	Audio::Audio(): file_id(), file_unique_id(), duration(), performer(), title(), mime_type(), file_size(), thumb()
	{}

	Audio::Audio(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//Assignments
			if(doc.HasMember("file_id"))
			{
				if(doc["file_id"].IsString())
					file_id = doc["file_id"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("file_id"));
			}

			if(doc.HasMember("file_unique_id"))
			{
				if(doc["file_unique_id"].IsString())
					file_unique_id = doc["file_unique_id"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("file_unique_id"));
			}

			if(doc.HasMember("duration"))
			{
				if(doc["duration"].IsInt())
					duration = doc["duration"].GetInt();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_int("duration"));
			}

			if(doc.HasMember("performer"))
			{
				if(doc["performer"].IsString())
					performer = doc["performer"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("performer"));
			}

			if(doc.HasMember("title"))
			{
				if(doc["title"].IsString())
					title = doc["title"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("title"));
			}

			if(doc.HasMember("mime_type"))
			{
				if(doc["mime_type"].IsString())
					mime_type = doc["mime_type"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("mime_type"));
			}

			if(doc.HasMember("file_size"))
			{
				if(doc["file_size"].IsInt())
					file_size = doc["file_size"].GetInt();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_int("file_size"));
			}

			if(doc.HasMember("thumb"))
			{
				if(doc["thumb"].IsObject())
					thumb = std::make_shared<PhotoSize>(tools::Tools::get_json_as_string(doc["thumb"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("thumb"));
			}
		}
		else
			tools::Tools::write_err_log(Messages::constructor_not_get_json_object);
	}

	std::string Audio::parse_to_json() const noexcept
	{
		std::string json = "{";

		//Field file_id
		json.append("\"file_id\": \"" + file_id + "\"");
		json.append(", ");

		//Field file_unique_id
		json.append("\"file_unique_id\": \"" + file_unique_id + "\"");
		json.append(", ");

		//Field duration
		json.append("\"duration\": " + duration);
		json.append(", ");

		//Field performer
		json.append("\"performer\": \"" + performer + "\"");
		json.append(", ");

		//Field title
		json.append("\"title\": \"" + title + "\"");
		json.append(", ");

		//Field mime_type
		json.append("\"mime_type\": \"" + mime_type + "\"");
		json.append(", ");

		//Field file_size
		json.append("\"file_size\": " + file_size);
		json.append(", ");

		//Field thumb
		json.append("\"thumb\": " + thumb->parse_to_json());

		json.append("}");
		return json;
	}
}
