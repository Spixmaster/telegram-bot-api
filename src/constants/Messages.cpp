#include "tgbot/constants/Messages.h"
#include <iostream>
#include <boost/format.hpp>
#include <boost/locale.hpp>

#define _(STRING) boost::locale::translate(STRING)

namespace tgbot
{
	const std::string Messages::constructor_not_get_json_object = _("The to the constructor passed string is not a JSON object.");
	const std::string Messages::server_resp_not_json_object = _("The server response is not a JSON object.");

	std::string Messages::field_does_not_contain_string(const std::string &field) noexcept
	{
		return boost::str(boost::format(_("The field \"%1%\" does not contain a string.")) % field);
	}

	std::string Messages::field_does_not_contain_int(const std::string &field) noexcept
	{
		return boost::str(boost::format(_("The field \"%1%\" does not contain an integer.")) % field);
	}

	std::string Messages::field_does_not_contain_int64(const std::string &field) noexcept
	{
		return boost::str(boost::format(_("The field \"%1%\" does not contain a 64 bits integer.")) % field);
	}

	std::string Messages::field_does_not_contain_json_obj(const std::string &field) noexcept
	{
		return boost::str(boost::format(_("The field \"%1%\" does not contain a JSON object.")) % field);
	}

	std::string Messages::field_does_not_contain_json_arr(const std::string &field) noexcept
	{
		return boost::str(boost::format(_("The field \"%1%\" does not contain a JSON array.")) % field);
	}

	std::string Messages::field_element_does_not_contain_json_arr(const std::string &field) noexcept
	{
		return boost::str(boost::format(_("The element of field \"%1%\" does not contain a JSON array.")) % field);
	}

	std::string Messages::field_element_does_not_contain_json_obj(const std::string &field) noexcept
	{
		return boost::str(boost::format(_("The element of field \"%1%\" does not contain a JSON object.")) % field);
	}

	std::string Messages::field_non_existent(const std::string &field) noexcept
	{
		return boost::str(boost::format(_("There is no field \"%1%\" in the JSON object.")) % field);
	}

	std::string Messages::field_does_not_contain_bool(const std::string &field) noexcept
	{
		return boost::str(boost::format(_("The field \"%1%\" does not contain a boolean.")) % field);
	}

	std::string Messages::field_does_not_contain_float(const std::string &field) noexcept
	{
		return boost::str(boost::format(_("The field \"%1%\" does not contain a float.")) % field);
	}

	std::string Messages::field_element_element_does_not_contain_json_obj(const std::string &field) noexcept
	{
		return boost::str(boost::format(_("The element's element of field \"%1%\" does not contain a JSON object.")) % field);
	}

	std::string Messages::field_element_does_not_contain_string(const std::string &field) noexcept
	{
		return boost::str(boost::format(_("The element of field \"%1%\" does not contain a string.")) % field);
	}

	std::string Messages::field_element_does_not_contain_int(const std::string &field) noexcept
	{
		return boost::str(boost::format(_("The element of field \"%1%\" does not contain an integer.")) % field);
	}
}
