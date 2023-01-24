//
// Created by Eva Poluliakhov on 22/01/2023.
//

#include "BattleCard.h"
#include "Dragon.h"

BattleCard::BattleCard(int force, int coins, int hp) :
    Card(),
    m_force(force),
    m_loot(coins),
    m_hp(hp)
    {}

bool BattleCard::isPlayerWon(const Player &player) const{
    if (player.getAttackStrength() >= m_force)
    {
        return true;
    }
    return false;
}

void BattleCard::playerVictory(Player &player) const{
    player.levelUp();
    player.addCoins(m_loot);
    printWinBattle(player.getName(), getType());
}

void BattleCard::playerLoss(Player &player)const {
    player.damage(m_hp);
    printLossBattle(player.getName(), getType());
}

void BattleCard::applyEncounter(Player& player) const{
    if (isPlayerWon(player))
    {
        playerVictory(player);
    }
    else playerLoss(player);
}

void BattleCard::printInfo(std::ostream &os) const{
    printCardDetails(os, getType());
    bool isDragon = getType() == "Dragon";
    printMonsterDetails(os, m_force, m_hp, m_loot, isDragon);
    printEndOfCardDetails(os);
}

