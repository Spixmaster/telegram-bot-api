#include <tgbot/SpecialTools.h>
#include "tgbot/types/Video.h"
#include "tools/Tools.h"

namespace tgbot
{
	Video::Video() : file_id(), width(), height(), duration(), thumb(), mime_type(), file_size()
	{}

	Video::Video(const std::string &json)
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

			if(doc.HasMember("duration"))
				duration = doc["duration"].GetInt();

			if(doc.HasMember("thumb"))
				thumb = std::make_shared<PhotoSize>(SpecialTools::get_json_as_string(doc["thumb"]));

			if(doc.HasMember("mime_type"))
				mime_type = doc["mime_type"].GetString();

			if(doc.HasMember("file_size"))
				file_size = doc["file_size"].GetInt();
		}
	}

	std::string Video::parse_to_json() const
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

		//field duration
		json.append("\"duration\": " + duration);
		json.append(", ");

		//field thumb
		json.append("\"thumb\": " + thumb->parse_to_json());
		json.append(", ");

		//field mime_type
		json.append("\"mime_type\": \"" + mime_type + "\"");
		json.append(", ");

		//field file_size
		json.append("\"file_size\": " + file_size);

		json.append("}");

		return json;
	}
}
