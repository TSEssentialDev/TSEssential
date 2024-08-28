#include "Entry.h"
#include "Config/Config.h"
#include "Global.h"
#include "Utils/I18n/I18n.h"

#include <ll/api/Versions.h>
#include <ll/api/mod/RegisterHelper.h>
#include <memory>

ll::Logger logger("Tellurium");

namespace Tellurium {

void printWelcomeMsg() {
    auto lock = logger.lock();
    logger.info("");
    logger.info(R"(   _______     _  _               _                       )");
    logger.info(R"(  |__   __|   | || |             (_)                      )");
    logger.info(R"(     | |  ___ | || | _   _  _ __  _  _   _  _ __ ___      )");
    logger.info(R"(     | | / _ \| || || | | || '__|| || | | || '_ ` _ \     )");
    logger.info(R"(     | ||  __/| || || |_| || |   | || |_| || | | | | |    )");
    logger.info(R"(     |_| \___||_||_| \__,_||_|   |_| \__,_||_| |_| |_|    )");
    logger.info("");
    logger.info("Tellurium is a free mod under GPL Version 3 License.");
    logger.info("Help us improve Tellurium! -> https://github.com/TelluriumDev/Tellurium");
    logger.info("Copyright (C) 2024 TelluriumDev");
}

static std::unique_ptr<Entry> instance;

Entry& Entry::getInstance() { return *instance; }

bool Entry::load() {
    TSConfig::initConfig(getSelf());
    I18n::initI18n(getSelf());
    printWelcomeMsg();
    if (TARGET_PROTOCOL != ll::getNetworkProtocolVersion()) {
        logger.warn("You are running on an unsupport protocol version! This may result in crash!");
        logger.warn(
            "Support protocol {0}, current protocol {1}.",
            std::to_string(TARGET_PROTOCOL),
            std::to_string(ll::getNetworkProtocolVersion())
        );
    }
    // logger.info(I18n::translate("test","zh_CN"));
    // logger.info(I18n::translate("test","en_US"));
    return true;
}

bool Entry::enable() {
    logger.info("Tellurium Enabled!");
    logger.info("Repository: {0}", "https://github.com/TelluriumDev/Tellurium");
    return true;
}

bool Entry::disable() { return true; }

bool Entry::unload() { return true; }

} // namespace Tellurium

LL_REGISTER_MOD(Tellurium::Entry, Tellurium::instance);
