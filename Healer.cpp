//
// Created by Eva Poluliakhov on 21/01/2023.
//

#include "Healer.h"

Player *Healer::clone (const std::string &name){
    return new Healer(name);
}

Healer::Healer(const std::string &name) : Player(name){}

std::string Healer::getType() const{
    return "Healer";
}

void Healer::heal(const int add)
{
    Player::heal(2*add);
}


