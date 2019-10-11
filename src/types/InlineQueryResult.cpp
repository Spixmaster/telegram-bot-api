#include "tgbot/types/InlineQueryResult.h"

namespace tgbot
{
	InlineQueryResult::~InlineQueryResult()
	{}

	std::string InlineQueryResult::parse_to_json() const
	{
		std::string json = "{";

		json.append("}");

		return json;
	}
}
