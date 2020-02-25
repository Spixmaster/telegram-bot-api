#include "tgbot/types/PassportFile.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	PassportFile::PassportFile() : file_id(), file_unique_id(), file_size(), file_date()
	{}

	PassportFile::PassportFile(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("file_id"))
			{
				if(doc["file_id"].IsString())
					file_id = doc["file_id"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("file_id") << std::endl;
			}

			if(doc.HasMember("file_unique_id"))
			{
				if(doc["file_unique_id"].IsString())
					file_unique_id = doc["file_unique_id"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("file_unique_id") << std::endl;
			}

			if(doc.HasMember("file_size"))
			{
				if(doc["file_size"].IsInt())
					file_size = doc["file_size"].GetInt();
				else
					std::cerr << Messages::field_does_not_contain_int("file_size") << std::endl;
			}

			if(doc.HasMember("file_date"))
			{
				if(doc["file_date"].IsInt())
					file_date = doc["file_date"].GetInt();
				else
					std::cerr << Messages::field_does_not_contain_int("file_date") << std::endl;
			}
		}
		else
			std::cerr << Messages::constructor_not_get_json_object << std::endl;
	}

	std::string PassportFile::parse_to_json() const noexcept
	{
		std::string json = "{";

		//field file_id
		json.append("\"file_id\": \"" + file_id + "\"");
		json.append(", ");

		//field file_unique_id
		json.append("\"file_unique_id\": \"" + file_unique_id + "\"");
		json.append(", ");

		//field file_size
		json.append("\"file_size\": " + file_size);
		json.append(", ");

		//field file_date
		json.append("\"file_date\": " + file_date);

		json.append("}");

		return json;
	}
}
