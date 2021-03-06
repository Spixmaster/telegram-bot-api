#include <rapidjson/document.h>
#include "tgbot/types/MaskPosition.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

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
			//Assignments
			if(doc.HasMember("point"))
			{
				if(doc["point"].IsString())
					point = doc["point"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("point"));
			}

			if(doc.HasMember("x_shift"))
			{
				if(doc["x_shift"].IsFloat())
					x_shift = doc["x_shift"].GetFloat();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_float("x_shift"));
			}

			if(doc.HasMember("y_shift"))
			{
				if(doc["y_shift"].IsFloat())
					y_shift = doc["y_shift"].GetFloat();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_float("y_shift"));
			}

			if(doc.HasMember("scale"))
			{
				if(doc["scale"].IsFloat())
					scale = doc["scale"].GetFloat();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_float("scale"));
			}
		}
		else
			tools::Tools::write_err_log(Messages::constructor_not_get_json_object);
	}

	std::string MaskPosition::parse_to_json() const noexcept
	{
		std::string json = "{";

		//Field point
		json.append("\"point\": \"" + point + "\"");
		json.append(", ");

		//Field x_shift
		json.append("\"x_shift\": " + std::to_string(x_shift));
		json.append(", ");

		//Field y_shift
		json.append("\"y_shift\": " + std::to_string(y_shift));
		json.append(", ");

		//Field scale
		json.append("\"scale\": " + std::to_string(scale));

		json.append("}");
		return json;
	}
}
