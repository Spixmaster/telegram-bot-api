#ifndef SPECIAL_TOOLS_H
#define SPECIAL_TOOLS_H

#include <string>
#include <rapidjson/document.h>

namespace tgbot
{
	namespace special_tools
	{
		std::string get_json_obj_as_string(const rapidjson::Value &val);
		std::string get_file_binaries(const std::string &file);
	}
}

#endif
