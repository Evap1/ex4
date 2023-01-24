//
// Created by Eva Poluliakhov on 21/01/2023.
//

#include "Player.h"

Player::Player(const std::string &name) :
    m_name(name),
    m_level(DEFAULT_LEVEL),
    m_HP(MAX_HP),
    m_coins(DEFAULT_COINS),
    m_force(DEFAULT_FORCE)
{}


void Player::printInfo(std::ostream &os) const
{
    printPlayerDetails(os, m_name, getType(), m_level, m_force, m_HP, m_coins);
}

void Player::levelUp()
{
    if (m_level < 10) m_level++;
}
int Player::getCoins() const{
    return m_coins;
}
int Player::getLevel() const
{
    return m_level;
}

int Player::getForce() const{
    return m_force;
}

void Player::buff(const int add)
{
    m_force+=add;
}

void Player::heal(const int add)
{
    if (add < 0) return;

    if ((m_HP+add) <= MAX_HP){
        m_HP += add;
    }
    else m_HP = MAX_HP;

}

void Player::damage(const int substruct)
{
    if (substruct < 0) return;

    if (m_HP - substruct >= 0){
        m_HP -= substruct;
    }
    else m_HP = 0;
}

bool Player::isKnockedOut() const
{
    if (m_HP == 0) return true;
    else return false;
}

void Player::addCoins(const int add)
{
    if ( add < 0 ) return;
    m_coins += add;
}

bool Player::pay(int payment)
{
    if (payment < 0) return true;
    if (m_coins - payment >= 0){
        m_coins -= payment;
        return true;
    }
    return false;
}


int Player::getAttackStrength() const {
    return (m_force + m_level);
}

std::string Player::getName() const {
    return this->m_name;
}


std::ostream& operator<<(std::ostream &os, const Player &player)
{
    player.printInfo(os);
    return os;
}