#include <rapidjson/document.h>
#include "tgbot/types/MaskPosition.h"
#include "tools/Tools.h"
#include <iostream>

namespace tgbot
{
	MaskPosition::MaskPosition() : point(), x_shift(), y_shift(), scale()
	{}

	MaskPosition::MaskPosition(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("point"))
				if(doc["point"].IsString())
					point = doc["point"].GetString();
				else
					std::cerr << "Error: Field \"point\" does not contain a string." << std::endl;

			if(doc.HasMember("x_shift"))
				if(doc["x_shift"].IsFloat())
					x_shift = doc["x_shift"].GetFloat();
				else
					std::cerr << "Error: Field \"x_shift\" does not contain a float." << std::endl;

			if(doc.HasMember("y_shift"))
				if(doc["y_shift"].IsFloat())
					y_shift = doc["y_shift"].GetFloat();
				else
					std::cerr << "Error: Field \"y_shift\" does not contain a float." << std::endl;

			if(doc.HasMember("scale"))
				if(doc["scale"].IsFloat())
					scale = doc["scale"].GetFloat();
				else
					std::cerr << "Error: Field \"scale\" does not contain a float." << std::endl;
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
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

		//field scale
		json.append("\"scale\": " + std::to_string(scale));

		json.append("}");

		return json;
	}
}
