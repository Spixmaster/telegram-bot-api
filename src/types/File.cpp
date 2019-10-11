#include "tgbot/types/File.h"

namespace tgbot
{
	File::File() : file_id(), file_size(), file_path()
	{}

	File::File(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		//assignments
		if(doc.HasMember("file_id"))
			file_id = doc["file_id"].GetString();

		if(doc.HasMember("file_size"))
			file_size = doc["file_size"].GetInt();

		if(doc.HasMember("file_path"))
			file_path = doc["file_path"].GetString();
	}

	std::string File::parse_to_json() const
	{
		std::string json = "{";

		//field file_id
		json.append("\"file_id\": \"" + file_id + "\"");
		json.append(", ");

		//field file_size
		json.append("\"file_size\": " + file_size);
		json.append(", ");

		//field file_path
		json.append("\"file_path\": \"" + file_path + "\"");

		json.append("}");

		return json;
	}
}
