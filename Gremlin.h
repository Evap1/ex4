//
// Created by Eva Poluliakhov on 22/01/2023.
//

#ifndef EX4_GREMLIN_H
#define EX4_GREMLIN_H
#include "BattleCard.h"

class Gremlin : public BattleCard {
public:
    Gremlin();
    std::string getType() const override;
    Card *clone() override;

    Gremlin(const Gremlin &) = default;
    ~Gremlin() override = default;
    Gremlin &operator=(const Gremlin & other) = default;


private:
    static const int DEFAULT_FORCE = 5;
    static const int DEFAULT_LOOT = 2;
    static const int DEFAULT_HP = 10;
};


#endif //EX4_GREMLIN_H
