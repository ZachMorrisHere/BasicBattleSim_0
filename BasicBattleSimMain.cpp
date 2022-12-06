#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "Player.h"

using namespace std;

//declares all needed functions from other files
int newTurn(Player& User, Player& Enemy);
int ranStatNum();

//assign random stats for player object
void assignPlayerStats(Player& User) {
   User.setAtt(ranStatNum() + 5);
   User.setSpeed(ranStatNum() + 2);
   User.setDef(ranStatNum());
   User.setHealth(400);
   User.setNum(1);
}

//assign random stats for enemy object
void assignEnemyStats(Player& Enemy) {
   Enemy.setAtt(ranStatNum());
   Enemy.setSpeed(ranStatNum());
   Enemy.setDef(ranStatNum());
   Enemy.setHealth(100);
   Enemy.setNum(2);
}

//main function
int main() {
   cout << "Welcome to basic battle sim" << endl;
   //initialize variables
   Player User;
   Player Enemy;
   unsigned seed = time(0);
   srand(seed);
   
   //assign player stats
   assignPlayerStats(User);
   assignEnemyStats(Enemy);

   //start turn
   newTurn(User, Enemy);
return 0;
}
