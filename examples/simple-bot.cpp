#include "tgbot/Bot.h"
#include <memory>

int main(int argc, const char *argv[])
{
	tgbot::Bot::ptr bot = std::make_shared<tgbot::Bot>("your-bot-token");

	//Command "/test"
	bot->get_event_handler()->on_cmd("test", [&bot](const tgbot::Message::ptr &msg)
	{
		bot->get_endpnts()->sendMessage(msg->chat->id, "Hey, <b>there</b>.", "HTML");
	});

	//Test listener
	bot->get_event_handler()->on_non_cmd_msg([&bot](const tgbot::Message::ptr &msg)
	{
		bot->get_endpnts()->sendMessage(msg->chat->id, "I hear you.");
	});

	while(true)
	{
		bot->get_event_handler()->long_poll();
	}

	return EXIT_SUCCESS;
}
