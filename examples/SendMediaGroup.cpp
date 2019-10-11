#include <iostream>
#include "tgbot/types/Update.h"
#include "tgbot/types/User.h"
#include "Bot.h"
#include "tgbot/types/Message.h"
#include "tgbot/types/ReplyKeyboardRemove.h"
#include <fstream>

int main()
{
	Bot bot("your-bot-token");

	//files
	InputFile::ptr file0 = std::make_shared<InputFile>("/path/to/a/file");
	InputFile::ptr file1 = std::make_shared<InputFile>("/path/to/a/file");

	//create media group
	std::vector<std::variant<InputMediaPhoto::ptr, InputMediaVideo::ptr>> v;

	InputMediaPhoto::ptr photo0 = std::make_shared<InputMediaPhoto>();
	photo0->media = file0;

	InputMediaPhoto::ptr photo1 = std::make_shared<InputMediaPhoto>();
	photo1->media = file1;

	v.push_back(photo0);
	v.push_back(photo1);

	bot.get_endpnts()->sendMediaGroup(proper-chat-id, v);


	return EXIT_SUCCESS;
}
