//
// Created by Eva Poluliakhov on 23/01/2023.
//

#include "Barfight.h"
#include "../Players/Warrior.h"

std::string Barfight::getType()const{
    return "Barfight";
}

Card *Barfight::clone(){
    return new Barfight();
}

void Barfight::applyEncounter(Player& player) const {
    bool isWarrior= true;
    Warrior* test = dynamic_cast<Warrior*>(&player);
    if (test == nullptr) {
        isWarrior = false;
        player.damage(DEFAULT_HP_DEMAGE);
    }
    printBarfightMessage(isWarrior);
}
