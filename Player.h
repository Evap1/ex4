//
// Created by Eva Poluliakhov on 21/01/2023.
//

#ifndef EX4_PLAYER_H
#define EX4_PLAYER_H
#include "string"
#include "../utilities.h"
#include <list>

class Player {
public:

    explicit Player(const std::string &name);
    virtual ~Player() = default;
    virtual std::string getType() const = 0;
    std::string getName()const ;
    virtual Player* clone(const std::string &name) = 0;
    /*
    * Prints the details of the player, using function from utility.h
    */
    void printInfo( std::ostream &os) const;


    int getCoins() const;
    /*
    * Increases player's level by one level with a limit of 10.
    */
    void levelUp();
    /*
    * @return:
    * Player's current level.
    */
    int getLevel() const;
    /*
  * @return:
  * Player's current force.
  */
    int getForce() const;
    /*
    * Increases the player's force by the argument value.
    * @param add - the amount of force to add to player's m_force.
    */
    void buff(const int add);
    /*
    * Increases the player's HP by the argument value with a limit of m_maxHP.
    * @param add - the amount of HP to add to player's m_HP.
    */
    void heal(const int add);
    /*
    * Decreases the player's HP by the argument value with a limit of 0.
    * @param substruct - the amount of HP to substruct from player's m_HP.
    */
    void damage(const int substruct);
    /*
    * @return: True - in case the player has positive m_HP.
    *          False - in case the player has 0 m_HP.
    */
    bool isKnockedOut() const;
    /*
    * Increases the player's coins by the argument value.
    * @param add - the amount of coins to add to player's m_coins.
    */
    void addCoins(const int add);
    /*
    * Decreases the player's coins by the argument value.
    * @param add - the amount of coins to add to player's m_coins.
    * @return: True - if payment has been accomplished.
    *          False - if payment failed (meaning player has not enough coins).
    */
    bool pay (const int payment);
    /*
    * Sums player's force and level to an attack param.
    * @return: Player's attack strength.
    */
    virtual int getAttackStrength() const;


private:
    const std::string m_name;
    int m_HP;
    int m_coins;
    int m_level;
    int m_force;
    static const int DEFAULT_FORCE = 5;
    static const int DEFAULT_LEVEL = 1;
    static const int MAX_HP = 100;
    static const int DEFAULT_COINS = 10;

};

std::ostream& operator<<(std::ostream &os,const Player &player);





#endif //EX4_PLAYER_H
