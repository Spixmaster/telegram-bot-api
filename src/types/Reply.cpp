#include "tgbot/types/Reply.h"
#include <string>

namespace tgbot
{
	Reply::~Reply()
	{}

	std::string Reply::parse_to_json() const noexcept
	{
		std::string json = "{";

		json.append("}");
		return json;
	}
}
