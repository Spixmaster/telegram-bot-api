#include "tgbot/types/PhotoSize.h"
#include "tgbot/Tools.h"

namespace tgbot
{
	PhotoSize::PhotoSize() : file_id(), width(), height(), file_size()
	{}

	PhotoSize::PhotoSize(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("file_id"))
				file_id = doc["file_id"].GetString();

			if(doc.HasMember("width"))
				width = doc["width"].GetInt();

			if(doc.HasMember("height"))
				height = doc["height"].GetInt();

			if(doc.HasMember("file_size"))
				file_size = doc["file_size"].GetInt();
		}
	}

	std::string PhotoSize::parse_to_json() const
	{
		std::string json = "{";

		//field file_id
		json.append("\"file_id\": \"" + file_id + "\"");
		json.append(", ");

		//field width
		json.append("\"width\": " + width);
		json.append(", ");

		//field height
		json.append("\"height\": " + height);
		json.append(", ");

		//field file_size
		json.append("\"file_size\": " + file_size);

		json.append("}");

		return json;
	}
}
