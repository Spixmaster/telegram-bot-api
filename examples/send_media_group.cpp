#include "tgbot/Bot.h"
#include <memory>

int main()
{
	tgbot::Bot::ptr bot = std::make_shared<tgbot::Bot>("your-bot-token");

	//files
	tgbot::InputFile::ptr file0 = std::make_shared<tgbot::InputFile>("/path/to/a/file");
	tgbot::InputFile::ptr file1 = std::make_shared<tgbot::InputFile>("/path/to/a/file");

	//create media group
	std::vector<std::variant<tgbot::InputMediaPhoto::ptr, tgbot::InputMediaVideo::ptr>> v;

	tgbot::InputMediaPhoto::ptr photo0 = std::make_shared<tgbot::InputMediaPhoto>();
	photo0->media = file0;

	tgbot::InputMediaPhoto::ptr photo1 = std::make_shared<tgbot::InputMediaPhoto>();
	photo1->media = file1;

	v.push_back(photo0);
	v.push_back(photo1);

	bot->get_endpnts()->sendMediaGroup(proper-chat-id, v);

	return EXIT_SUCCESS;
}
