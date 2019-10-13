#ifndef TGBOT_HTTP_INPUTFILE_H
#define TGBOT_HTTP_INPUTFILE_H

#include <memory>

//@brief represents a file which shall be uploaded by a http request via multipart/form

namespace tgbot
{
	struct InputFile
	{
		//pointer of itself
		typedef std::shared_ptr<InputFile> ptr;

		//member variables
		std::string m_path;

		//constructors
		//@param path: stats the path where the file is located
		InputFile(const std::string &path);
	};
}

#endif
