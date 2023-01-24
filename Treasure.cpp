//
// Created by Eva Poluliakhov on 21/01/2023.
//

#include "Treasure.h"


std::string Treasure::getType()const{
    return "Treasure";
}

Card *Treasure::clone(){
    return new Treasure();
}

void Treasure::applyEncounter(Player& player) const {
    printTreasureMessage();
    return player.addCoins(DEFAULT_COINS_TO_ADD);
}
