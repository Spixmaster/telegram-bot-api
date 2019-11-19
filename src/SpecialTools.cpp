#include "tgbot/SpecialTools.h"
#include <string>
#include <rapidjson/document.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>
#include <tgbot/http/HttpArg.h>
#include <vector>
#include <iostream>
#include <fstream>

namespace tgbot
{
	std::string SpecialTools::get_json_as_string(const rapidjson::Value &val)
	{
		rapidjson::StringBuffer sb;
		rapidjson::Writer<rapidjson::StringBuffer> writer(sb);
		val.Accept(writer);
		return sb.GetString();
	}
}
