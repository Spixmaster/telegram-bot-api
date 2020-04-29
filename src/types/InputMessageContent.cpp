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
			//Assignments
		}
		else
			tools::Tools::write_err_log(Messages::constructor_not_get_json_object);
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
