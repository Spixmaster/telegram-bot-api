#include "tgbot/types/PassportElementError.h"

namespace tgbot
{
	PassportElementError::~PassportElementError()
	{}

	std::string PassportElementError::parse_to_json() const noexcept
	{
		std::string json = "{";

		json.append("}");
		return json;
	}
}
