//
// Created by Eva Poluliakhov on 23/01/2023.
//

#include "Well.h"
#include "../Players/Ninja.h"

std::string Well::getType()const{
    return "Well";
}

Card *Well::clone(){
    return new Well();
}

void Well::applyEncounter(Player& player) const {
    bool isNinja= true;
    Ninja* test = dynamic_cast<Ninja*>(&player);
    if (test == nullptr)
    {
        isNinja = false;
        player.damage(DEFAULT_HP_DEMAGE);
    }
    printWellMessage(isNinja);
}


