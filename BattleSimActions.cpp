#include <iostream>
#include "Player.h"

using namespace std;

int rollVar();

//will scan enemy and show stats to the player
void scan(Player& En){
   cout << "Enemy Health: " << En.getHealth() << endl;
   cout << "Enemy Attack: " << En.getAtt() << endl;
   cout << "Enemy Speed: " << En.getSpeed() << endl;
   cout << "Enemy Defense: " << En.getDef() << endl;
}

//attacks enemy dealing damage to it
void attack(Player x, Player& y){
   cout << "You attack!" << endl;
   int pDamage = rollVar() + x.getAtt() - y.getDef();
   if (pDamage <= 0){ pDamage = 1; cout << "It's defense is too strong!" << endl;}
   int Damage = y.getHealth()-pDamage;
   y.setHealth(Damage);
   cout << "You dealt " << pDamage << " Damage" << endl;
}

//Makes it so the player endures next hit next turn
void block(Player& x){
   cout << "you endure the next hit"<< endl;
   int i = x.getDef() + 5;
   x.setDef(i);
}