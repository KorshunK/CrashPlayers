//
// Created by admin on 19.08.2025.
//

#include "utils.h"


bool CrashPlayers::getModSettingsBoolValue(std::string path) {
    return geode::prelude::Mod::get()->getSettingValue<bool>(path);
}