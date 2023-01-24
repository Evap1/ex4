//
// Created by Eva Poluliakhov on 23/01/2023.
//

#include "Dragon.h"

Dragon::Dragon() : BattleCard(DEFAULT_FORCE, DEFAULT_LOOT, DEFAULT_HP){}

std::string Dragon::getType() const {
    return "Dragon";
}

Card *Dragon::clone() {
    return new Dragon();
}