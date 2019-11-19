#include <tgbot/SpecialTools.h>
#include "tgbot/types/VideoNote.h"
#include "tgbot/Tools.h"

namespace tgbot
{
	VideoNote::VideoNote() : file_id(), length(), duration(), thumb(), file_size()
	{}

	VideoNote::VideoNote(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(Tools::is_json(json))
		{
			//assignments
			if(doc.HasMember("file_id"))
				file_id = doc["file_id"].GetString();

			if(doc.HasMember("length"))
				length = doc["length"].GetInt();

			if(doc.HasMember("duration"))
				duration = doc["duration"].GetInt();

			if(doc.HasMember("thumb"))
				thumb = std::make_shared<PhotoSize>(SpecialTools::get_json_as_string(doc["thumb"]));

			if(doc.HasMember("file_size"))
				file_size = doc["file_size"].GetInt();
		}
	}

	std::string VideoNote::parse_to_json() const
	{
		std::string json = "{";

		//field file_id
		json.append("\"file_id\": \"" + file_id + "\"");
		json.append(", ");

		//field length
		json.append("\"length\": " + length);
		json.append(", ");

		//field duration
		json.append("\"duration\": " + duration);
		json.append(", ");

		//field thumb
		json.append("\"thumb\": " + thumb->parse_to_json());
		json.append(", ");

		//field file_size
		json.append("\"file_size\": " + file_size);

		json.append("}");

		return json;
	}
}
