#include "Event/MoneyEvent/MoneyAddEvent.h"

#include <ll/api/service/Bedrock.h>
#include <mc/world/level/Level.h>

namespace TLEvent::inline MoneyEvent {
Player* MoneyAddEvent::tryGetPlayer() { return ll::service::getLevel()->getPlayer(mPlayerUUID); }

const mce::UUID& MoneyAddEvent::getPlayerUUID() { return mPlayerUUID; }

int MoneyAddEvent::getMoney() { return mMoney; }

const std::string& MoneyAddEvent::getNote() { return mNote; }
} // namespace TEvent::inline MoneyEvent