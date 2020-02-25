#include "tgbot/constants/Messages.h"
#include <iostream>

namespace tgbot
{
	const std::string Messages::constructor_not_get_json_object = "Error: The to the constructor passed string is not a json object.";
	const std::string Messages::server_resp_not_json_object = "Error: The server response is not a json object.";

	std::string Messages::field_does_not_contain_string(const std::string &field) noexcept
	{
		return "Error: Field \"" + field + "\" does not contain a string.";
	}

	std::string Messages::field_does_not_contain_int(const std::string &field) noexcept
	{
		return "Error: Field \"" + field + "\" does not contain an int.";
	}

	std::string Messages::field_does_not_contain_int64(const std::string &field) noexcept
	{
		return "Error: Field \"" + field + "\" does not contain an int64.";
	}

	std::string Messages::field_does_not_contain_json_obj(const std::string &field) noexcept
	{
		return "Error: Field \"" + field + "\" does not contain a json object.";
	}

	std::string Messages::field_does_not_contain_json_arr(const std::string &field) noexcept
	{
		return "Error: Field \"" + field + "\" does not contain a json array.";
	}

	std::string Messages::field_element_does_not_contain_json_arr(const std::string &field) noexcept
	{
		return "Error: Field \"" + field + "\"'s element does not contain a json array.";
	}

	std::string Messages::field_element_does_not_contain_json_obj(const std::string &field) noexcept
	{
		return "Error: Field \"" + field + "\"'s element does not contain a json object.";
	}

	std::string Messages::field_non_existent(const std::string &field) noexcept
	{
		return "Error: There is no field \"" + field +  "\" in the json object.";
	}

	std::string Messages::field_does_not_contain_bool(const std::string &field) noexcept
	{
		return "Error: Field \"" + field + "\" does not contain a bool.";
	}

	std::string Messages::field_does_not_contain_float(const std::string &field) noexcept
	{
		return "Error: Field \"" + field + "\" does not contain a float.";
	}

	std::string Messages::field_element_element_does_not_contain_json_obj(const std::string &field) noexcept
	{
		return "Error: Field \"" + field + "\"'s element's element does not contain a json object.";
	}

	std::string Messages::field_element_does_not_contain_string(const std::string &field) noexcept
	{
		return "Error: Field \"" + field + "\"'s element does not contain a string.";
	}

	std::string Messages::field_element_does_not_contain_int(const std::string &field) noexcept
	{
		return "Error: Field \"" + field + "\"'s element does not contain an int.";
	}
}
