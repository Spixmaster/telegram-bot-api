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
	namespace special_tools
	{
		std::string get_json_obj_as_string(const rapidjson::Value &val)
		{
			rapidjson::StringBuffer sb;
			rapidjson::Writer<rapidjson::StringBuffer> writer(sb);
			val.Accept(writer);
			return sb.GetString();
		}
	}
}
