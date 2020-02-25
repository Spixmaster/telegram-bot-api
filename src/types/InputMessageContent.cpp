#include "tgbot/types/InputMessageContent.h"
#include <rapidjson/document.h>
#include <iostream>
#include "tgbot/constants/Messages.h"

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
			std::cerr << Messages::constructor_not_get_json_object << std::endl;
	}

	InputMessageContent::~InputMessageContent()
	{}

	std::string InputMessageContent::parse_to_json() const noexcept
	{
		std::string json = "{";

		json.append("}");

		return json;
	}
}
