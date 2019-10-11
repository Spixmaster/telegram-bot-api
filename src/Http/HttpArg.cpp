#include <tgbot/http/HttpArg.h>

namespace tgbot
{
	HttpArg::HttpArg(const std::string &key, const std::variant<long long, std::string, InputFile::ptr> &value)
	{
		m_key = key;

		if(std::holds_alternative<long long>(value))
			m_value = std::get<long long>(value);
		else if(std::holds_alternative<std::string>(value))
			m_value = std::get<std::string>(value);
		else
			m_value = std::get<InputFile::ptr>(value);
	}
}
