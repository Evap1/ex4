//
// Created by Eva Poluliakhov on 23/01/2023.
//

#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H
#include "Card.h"

enum Choose {
    LEAVE,
    ADD_HEALTH,
    ADD_FORCE,
    COUNT
};

class Merchant : public Card{
public:
    Merchant();
    std::string getType() const override;
    Card *clone() override;
    void applyEncounter(Player& player) const override;

    Merchant(const Merchant &) = default;
    ~Merchant() = default;
    Merchant &operator=(const Merchant & other) = default;

private:

    int m_addHP = DEFAULT_ADD_FORCE;
    int m_costHP = DEFAULT_HP_COST;
    int m_addForce = DEFAULT_ADD_FORCE;
    int m_costForce = DEFAULT_FORCE_COST;

    static const int DEFAULT_ADD_HP = 1;
    static const int DEFAULT_HP_COST = 5;
    static const int DEFAULT_ADD_FORCE = 1;
    static const int DEFAULT_FORCE_COST = 10;
};


#endif //EX4_MERCHANT_H
