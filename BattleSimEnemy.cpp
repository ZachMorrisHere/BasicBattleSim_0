#include <iostream>
#include "Player.h"
using namespace std;

int rollVar();
int rollDice();
void enemyAtt(Player& y, Player x);

//will determine which course of action via random number
void enemyDec(Player& User, Player& Enemy){
   cout << "Enemy Turn:" << endl;
   int dec = rollDice();
   enemyAtt(User, Enemy);
}

//enemy attacks
void enemyAtt(Player& y, Player x){
   cout << "They attack!" << endl;
   int pDamage = rollVar() + x.getAtt() - y.getDef();
   if (pDamage <= 0){ pDamage = 1;}
   int Damage = y.getHealth()-pDamage;
   y.setHealth(Damage);
   cout << "They dealt " << pDamage << " Damage" << endl;
}