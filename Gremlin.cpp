//
// Created by Eva Poluliakhov on 22/01/2023.
//

#include "Gremlin.h"


Gremlin::Gremlin() : BattleCard(DEFAULT_FORCE, DEFAULT_LOOT, DEFAULT_HP){}

std::string Gremlin::getType() const {
    return "Gremlin";
}


Card *Gremlin::clone() {
    return new Gremlin();
}