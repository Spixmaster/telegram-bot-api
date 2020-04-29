#include "tgbot/types/InputMedia.h"

namespace tgbot
{
	InputMedia::~InputMedia()
	{}

	std::string InputMedia::parse_to_json() const noexcept
	{
		std::string json = "{";

		json.append("}");
		return json;
	}
}

