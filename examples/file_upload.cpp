#include "tgbot/Bot.h"
#include <memory>

int main()
{
	tgbot::Bot::ptr bot = std::make_shared<tgbot::Bot>("your-own-bot-token");

	tools::InputFile::ptr file = std::make_shared<tools::InputFile>("/path/to/the/file");

	bot->get_endpnts()->sendPhoto(proper-chat-id, file, "Hey, <b>there</b>.", "HTML", false, 0);

	return EXIT_SUCCESS;
}
