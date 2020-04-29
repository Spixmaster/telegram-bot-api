#include "tgbot/types/File.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	File::File() : file_id(), file_unique_id(), file_size(), file_path()
	{}

	File::File(const std::string &json)
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

			if(doc.HasMember("file_size"))
			{
				if(doc["file_size"].IsInt())
					file_size = doc["file_size"].GetInt();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_int("file_size"));
			}

			if(doc.HasMember("file_path"))
			{
				if(doc["file_path"].IsString())
					file_path = doc["file_path"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("file_path"));
			}
		}
		else
			tools::Tools::write_err_log(Messages::constructor_not_get_json_object);
	}

	std::string File::parse_to_json() const noexcept
	{
		std::string json = "{";

		//Field file_id
		json.append("\"file_id\": \"" + file_id + "\"");
		json.append(", ");

		//Field file_unique_id
		json.append("\"file_unique_id\": \"" + file_unique_id + "\"");
		json.append(", ");

		//Field file_size
		json.append("\"file_size\": " + file_size);
		json.append(", ");

		//Field file_path
		json.append("\"file_path\": \"" + file_path + "\"");

		json.append("}");

		return json;
	}
}
