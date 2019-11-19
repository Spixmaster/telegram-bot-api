#include <rapidjson/document.h>
#include "tgbot/types/MaskPosition.h"
#include "tgbot/Tools.h"

namespace tgbot
{
	MaskPosition::MaskPosition() : point(), x_shift(), y_shift(), number()
	{}

	MaskPosition::MaskPosition(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(Tools::is_json(json))
		{
			//assignments
			if(doc.HasMember("point"))
				point = doc["point"].GetString();

			if(doc.HasMember("x_shift"))
				x_shift = doc["x_shift"].GetFloat();

			if(doc.HasMember("y_shift"))
				y_shift = doc["y_shift"].GetFloat();

			if(doc.HasMember("number"))
				number = doc["number"].GetFloat();
		}
	}

	std::string MaskPosition::parse_to_json() const
	{
		std::string json = "{";

		//field point
		json.append("\"point\": \"" + point + "\"");
		json.append(", ");

		//field x_shift
		json.append("\"x_shift\": " + std::to_string(x_shift));
		json.append(", ");

		//field y_shift
		json.append("\"y_shift\": " + std::to_string(y_shift));
		json.append(", ");

		//field number
		json.append("\"number\": " + std::to_string(number));

		json.append("}");

		return json;
	}
}
