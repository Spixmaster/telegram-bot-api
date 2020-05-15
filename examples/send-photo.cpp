#include "tgbot/Bot.h"
#include <memory>

int main(int argc, const char *argv[])
{
	tgbot::Bot::ptr bot = std::make_shared<tgbot::Bot>("your-bot-token");

	tools::InputFile::ptr file = std::make_shared<tools::InputFile>("/path/to/the/file");

	tgbot::Message::ptr msg = bot->get_endpnts()->sendPhoto(proper-chat-id, file, "Hey, <b>there</b>.", "HTML");

	return EXIT_SUCCESS;
}
