#include "tgbot/types/Reply.h"

namespace tgbot
{
	Reply::~Reply()
	{}

	std::string Reply::parse_to_json() const
	{
		std::string json = "{";

		json.append("}");

		return json;
	}
}
