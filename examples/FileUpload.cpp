#include <iostream>
#include "tgbot/types/Update.h"
#include "tgbot/types/User.h"
#include <cpr/cpr.h"
#include "Bot.h"
#include "tgbot/types/Message.h"
#include "tgbot/types/ReplyKeyboardRemove.h"
#include <fstream>

int main()
{
	Bot bot("your-own-bot-token");

	InputFile::ptr file = std::make_shared<InputFile>("/path/to/the/file");

	for(int j = 0; j < 1; ++j)
		bot.get_endpnts()->sendPhoto(proper-chat-id, file, "Hey, <b>there</b>.", "HTML", false, 0);


	return EXIT_SUCCESS;
}
