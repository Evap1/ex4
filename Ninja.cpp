//
// Created by Eva Poluliakhov on 22/01/2023.
//

#include "Ninja.h"


Player *Ninja::clone (const std::string &name){
    return new Ninja(name);
}

Ninja::Ninja(const std::string &name) : Player(name){}


std::string Ninja::getType() const{
    return "Ninja";
}

void Ninja::addCoins(const int add) {
    Player::addCoins(2*add);
}
