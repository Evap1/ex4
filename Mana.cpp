//
// Created by Eva Poluliakhov on 23/01/2023.
//

#include "Mana.h"
#include "../Players/Healer.h"

std::string Mana::getType()const{
    return "Mana";
}

Card *Mana::clone(){
    return new Mana();
}

void Mana::applyEncounter(Player& player) const {
    bool isHealer = true;
    Healer* test = dynamic_cast<Healer*>(&player);
    if (test == nullptr)
    {
        isHealer = false;
        player.damage(DEFAULT_HP_DEMAGE);
    }
    printManaMessage(isHealer);
}

