cmake_minimum_required(VERSION "3.18.1")

if ("${CMAKE_BINARY_DIR}" STREQUAL "${CMAKE_SOURCE_DIR}")
  message(FATAL_ERROR "In-source builds are not allowed!")
endif ()

#Build libraries
add_subdirectory("./tools-cpp/")

#General
project("telegram-bot-api")
set(CMAKE_CXX_STANDARD "17")

#Target
add_library(${PROJECT_NAME}
    "./src/constants/Constants.cpp"
    "./src/constants/Messages.cpp"
    
    "./src/types/Animation.cpp"
    "./src/types/Audio.cpp"
    "./src/types/BotCommand.cpp"
    "./src/types/CallbackGame.cpp"
    "./src/types/CallbackQuery.cpp"
    "./src/types/Chat.cpp"
    "./src/types/ChatMember.cpp"
    "./src/types/ChatPermissions.cpp"
    "./src/types/ChatPhoto.cpp"
    "./src/types/ChosenInlineResult.cpp"
    "./src/types/Contact.cpp"
    "./src/types/Dice.cpp"
    "./src/types/Document.cpp"
    "./src/types/EncryptedCredentials.cpp"
    "./src/types/EncryptedPassportElement.cpp"
    "./src/types/File.cpp"
    "./src/types/ForceReply.cpp"
    "./src/types/Game.cpp"
    "./src/types/GameHighScore.cpp"
    "./src/types/InlineKeyboardButton.cpp"
    "./src/types/InlineKeyboardMarkup.cpp"
    "./src/types/InlineQuery.cpp"
    "./src/types/InlineQueryResult.cpp"
    "./src/types/InlineQueryResultArticle.cpp"
    "./src/types/InlineQueryResultAudio.cpp"
    "./src/types/InlineQueryResultCachedAudio.cpp"
    "./src/types/InlineQueryResultCachedDocument.cpp"
    "./src/types/InlineQueryResultCachedGif.cpp"
    "./src/types/InlineQueryResultCachedMpeg4Gif.cpp"
    "./src/types/InlineQueryResultCachedPhoto.cpp"
    "./src/types/InlineQueryResultCachedSticker.cpp"
    "./src/types/InlineQueryResultCachedVideo.cpp"
    "./src/types/InlineQueryResultCachedVoice.cpp"
    "./src/types/InlineQueryResultContact.cpp"
    "./src/types/InlineQueryResultDocument.cpp"
    "./src/types/InlineQueryResultGame.cpp"
    "./src/types/InlineQueryResultGif.cpp"
    "./src/types/InlineQueryResultLocation.cpp"
    "./src/types/InlineQueryResultMpeg4Gif.cpp"
    "./src/types/InlineQueryResultPhoto.cpp"
    "./src/types/InlineQueryResultVenue.cpp"
    "./src/types/InlineQueryResultVideo.cpp"
    "./src/types/InlineQueryResultVoice.cpp"
    "./src/types/InputContactMessageContent.cpp"
    "./src/types/InputLocationMessageContent.cpp"
    "./src/types/InputMedia.cpp"
    "./src/types/InputMediaAnimation.cpp"
    "./src/types/InputMediaAudio.cpp"
    "./src/types/InputMediaDocument.cpp"
    "./src/types/InputMediaPhoto.cpp"
    "./src/types/InputMediaVideo.cpp"
    "./src/types/InputMessageContent.cpp"
    "./src/types/InputTextMessageContent.cpp"
    "./src/types/InputVenueMessageContent.cpp"
    "./src/types/Invoice.cpp"
    "./src/types/KeyboardButton.cpp"
    "./src/types/KeyboardButtonPollType.cpp"
    "./src/types/LabeledPrice.cpp"
    "./src/types/Location.cpp"
    "./src/types/LoginUrl.cpp"
    "./src/types/MaskPosition.cpp"
    "./src/types/Message.cpp"
    "./src/types/MessageEntity.cpp"
    "./src/types/OrderInfo.cpp"
    "./src/types/PassportData.cpp"
    "./src/types/PassportElementError.cpp"
    "./src/types/PassportElementErrorDataField.cpp"
    "./src/types/PassportElementErrorFile.cpp"
    "./src/types/PassportElementErrorFiles.cpp"
    "./src/types/PassportElementErrorFrontSide.cpp"
    "./src/types/PassportElementErrorReverseSide.cpp"
    "./src/types/PassportElementErrorSelfie.cpp"
    "./src/types/PassportElementErrorTranslationFile.cpp"
    "./src/types/PassportElementErrorTranslationFiles.cpp"
    "./src/types/PassportElementErrorUnspecified.cpp"
    "./src/types/PassportFile.cpp"
    "./src/types/PhotoSize.cpp"
    "./src/types/Poll.cpp"
    "./src/types/PollAnswer.cpp"
    "./src/types/PollOption.cpp"
    "./src/types/PreCheckoutQuery.cpp"
    "./src/types/Reply.cpp"
    "./src/types/ReplyKeyboardMarkup.cpp"
    "./src/types/ReplyKeyboardRemove.cpp"
    "./src/types/ResponseParameters.cpp"
    "./src/types/ShippingAddress.cpp"
    "./src/types/ShippingOption.cpp"
    "./src/types/ShippingQuery.cpp"
    "./src/types/Sticker.cpp"
    "./src/types/StickerSet.cpp"
    "./src/types/SuccessfulPayment.cpp"
    "./src/types/Update.cpp"
    "./src/types/User.cpp"
    "./src/types/UserProfilePhotos.cpp"
    "./src/types/Venue.cpp"
    "./src/types/Video.cpp"
    "./src/types/VideoNote.cpp"
    "./src/types/Voice.cpp"
    "./src/types/WebhookInfo.cpp"
    
    "./src/Bot.cpp"
    "./src/Endpoints.cpp"
    "./src/EventHandler.cpp"
    )

    #Headers
target_include_directories("${PROJECT_NAME}" PUBLIC "./include/")

    #Link libraries
target_link_libraries("${PROJECT_NAME}" PUBLIC "PocoFoundation")
target_link_libraries("${PROJECT_NAME}" PUBLIC "PocoNet")
target_link_libraries("${PROJECT_NAME}" PUBLIC "PocoNetSSL")
target_link_libraries("${PROJECT_NAME}" PUBLIC "PocoCrypto")
target_link_libraries("${PROJECT_NAME}" PUBLIC "boost_iostreams")
target_link_libraries("${PROJECT_NAME}" PUBLIC "boost_filesystem")
target_link_libraries("${PROJECT_NAME}" PUBLIC "boost_locale")

target_link_libraries("${PROJECT_NAME}" PUBLIC "tools-cpp")

    #Options
        #Optimization
target_compile_options("${PROJECT_NAME}" PUBLIC "-O3")
        #Warnings
target_compile_options("${PROJECT_NAME}" PUBLIC "-Wall")
target_compile_options("${PROJECT_NAME}" PUBLIC "-Wextra")
        #Preprocessor
target_compile_options("${PROJECT_NAME}" PUBLIC "-MD")
target_compile_options("${PROJECT_NAME}" PUBLIC "-MP")
