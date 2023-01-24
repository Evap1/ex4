//
// Created by Eva Poluliakhov on 22/01/2023.
//

#ifndef EX4_BATTLECARD_H
#define EX4_BATTLECARD_H
#include "Card.h"

class BattleCard : public Card{
public:
    BattleCard(int force, int coins, int hp);
    virtual std::string getType() const= 0;
    void applyEncounter(Player& player) const override;
    virtual void printInfo(std::ostream &os) const override;
    bool isPlayerWon (const Player& player) const;
    void playerVictory (Player& player) const;
    void playerLoss (Player& player) const;

    BattleCard(const BattleCard &) = default;
    virtual ~BattleCard() = default;
    BattleCard &operator=(const BattleCard & other) = default;

private:
    int m_force;
    int m_loot;
    int m_hp;
};


#endif //EX4_BATTLECARD_H
