#include "tgbot/types/InlineQueryResult.h"
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	InlineQueryResult::~InlineQueryResult()
	{}

	std::string InlineQueryResult::parse_to_json() const noexcept
	{
		std::string json = "{";

		json.append("}");

		return json;
	}
}
