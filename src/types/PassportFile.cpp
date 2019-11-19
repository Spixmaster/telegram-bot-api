#include "tgbot/types/PassportFile.h"
#include "tgbot/Tools.h"

namespace tgbot
{
	PassportFile::PassportFile() : file_id(), file_size(), file_date()
	{}

	PassportFile::PassportFile(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(Tools::is_json(json))
		{
			//assignments
			if(doc.HasMember("file_id"))
				file_id = doc["file_id"].GetString();

			if(doc.HasMember("file_size"))
				file_size = doc["file_size"].GetInt();

			if(doc.HasMember("file_date"))
				file_date = doc["file_date"].GetInt();
		}
	}

	std::string PassportFile::parse_to_json() const
	{
		std::string json = "{";

		//field file_id
		json.append("\"file_id\": \"" + file_id + "\"");
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
