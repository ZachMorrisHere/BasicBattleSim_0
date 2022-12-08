#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "Player.h"
#include "stats.h"

using namespace std;

//declares all needed functions from other files
int newTurn(Player& User, Player& Enemy, stats& UserStats);
int ranStatNum();

//assign random stats for player object
void assignPlayerStats(Player& User) {
   User.setAtt(ranStatNum() + 5);
   User.setSpeed(ranStatNum() + 2);
   User.setDef(ranStatNum());
   User.setHealth(200);
   User.setNum(1);
   User.setInflame(false);
   User.setBlock(false);
   User.setHaste(false);
}

//assign random stats for enemy object
void assignEnemyStats(Player& Enemy) {
   Enemy.setAtt(ranStatNum());
   Enemy.setSpeed(ranStatNum());
   Enemy.setDef(ranStatNum());
   Enemy.setHealth(50);
   Enemy.setNum(2);
}

//main function
int main() {
   cout << "Welcome to basic battle sim" << endl;
   //initialize variables
   Player User;
   Player Enemy;
   stats UserStats;
   //starts random number generator
   unsigned seed = time(0);
   srand(seed);
   
   //assign player stats
   assignPlayerStats(User);
   assignEnemyStats(Enemy);

   //start turn
   newTurn(User, Enemy, UserStats);
   return 0;
}
