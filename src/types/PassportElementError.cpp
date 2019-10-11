#include "tgbot/types/PassportElementError.h"

namespace tgbot
{
	PassportElementError::~PassportElementError()
	{}

	std::string PassportElementError::parse_to_json() const
	{
		std::string json = "{";

		json.append("}");

		return json;
	}
}
