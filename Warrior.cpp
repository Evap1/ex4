//
// Created by Eva Poluliakhov on 22/01/2023.
//

#include "Warrior.h"

Player *Warrior::clone (const std::string &name){
    return new Warrior(name);
}

Warrior::Warrior(const std::string &name) : Player(name){}

std::string Warrior::getType() const{
    return "Warrior";
}

int Warrior::getAttackStrength() const{
    int force = Player::getForce();
    int level = Player::getLevel();

    return ((2*force)+level);
}