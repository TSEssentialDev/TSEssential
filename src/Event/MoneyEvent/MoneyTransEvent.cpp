#include "Event/MoneyEvent/MoneyTransEvent.h"

#include <ll/api/service/Bedrock.h>

#include <mc/world/level/Level.h>
namespace TEvent::inline MoneyEvent {
Player* MoneyTransEvent::tryGetPlayer() { return ll::service::getLevel()->getPlayer(mPlayerUUID); }

Player* MoneyTransEvent::tryGetTarget() { return ll::service::getLevel()->getPlayer(mTargetPlayerUUID); }

mce::UUID& MoneyTransEvent::getPlayerUUID() { return mPlayerUUID; }

mce::UUID& MoneyTransEvent::getTargetUUID() { return mTargetPlayerUUID; }

int MoneyTransEvent::getMoney() { return mMoney; }

std::string& MoneyTransEvent::getNote() { return mNote; }
} // namespace TEvent::inline MoneyEvent