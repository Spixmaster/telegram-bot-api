#include "tgbot/types/InputMessageContent.h"
#include <rapidjson/document.h>
#include <iostream>

namespace tgbot
{
	InputMessageContent::InputMessageContent()
	{}

	InputMessageContent::InputMessageContent(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
	}

	InputMessageContent::~InputMessageContent()
	{}

	std::string InputMessageContent::parse_to_json() const
	{
		std::string json = "{";

		json.append("}");

		return json;
	}
}
