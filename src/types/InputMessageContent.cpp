#include "tgbot/types/InputMessageContent.h"

namespace tgbot
{
	InputMessageContent::~InputMessageContent()
	{}

	std::string InputMessageContent::parse_to_json() const
	{
		std::string json = "{";

		json.append("}");

		return json;
	}
}
