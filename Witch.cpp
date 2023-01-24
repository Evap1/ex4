//
// Created by Eva Poluliakhov on 23/01/2023.
//

#include "Witch.h"


void Witch::applyEncounter(Player& player) const{
    if (!isPlayerWon(player)){
        player.buff(DEFAULT_FORCE_LOSS);
    }
    BattleCard::applyEncounter(player);
}

Witch::Witch() : BattleCard(DEFAULT_FORCE, DEFAULT_LOOT, DEFAULT_HP){}

std::string Witch::getType() const {
    return "Witch";
}


Card *Witch::clone() {
    return new Witch();
}