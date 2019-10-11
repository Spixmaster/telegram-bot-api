#ifndef HTTP_INPUTFILE_H
#define HTTP_INPUTFILE_H

#include <memory>

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
