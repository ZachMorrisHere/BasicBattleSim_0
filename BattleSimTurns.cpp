#include <iostream>
#include "Player.h"
using namespace std;

//declares all functions needed
int rollDice();
void scan(Player& En);
void attack(Player x, Player& y);
void enemyDec(Player& User, Player& Enemy);

//player turn method
void playerTurn(Player& User, Player& Enemy) {
   int playerInput;
   //display menu
   cout << "1: Scan" << endl << "2: Attack" << endl;
   cout << "What do you choose?" << endl;
   //waits for input
   cin >> playerInput;
   while (playerInput <=0){ //while loop for verification of input
      cout << "Error please input proper number" << endl;
      //display menu
      cout << "1: scan" << endl;
      cout << "What do you choose?" << endl;
      //waits for input
      cin >> playerInput;     
   }
   switch (playerInput) { //navigates menu for user
      case 1: scan(Enemy); break;
      case 2: attack(User, Enemy); break;
   }
}

//Starts enemy Turn
void enemyTurn(Player& User, Player& Enemy){
   enemyDec(User, Enemy);
}

void restartTurn(Player& User){
   int i = 0;
   int defaultAtt, defaultSpeed, defaultDef;
   if (i == 0){
      defaultAtt = User.getAtt();
      defaultSpeed = User.getSpeed();
      defaultDef = User.getDef();
   } else {
      User.setAtt(defaultAtt);
      User.setSpeed(defaultSpeed);
      User.setDef(defaultDef);
   }
   i++;
   cout << "Turn: " << i << endl;
}

//Starts a new turn
int newTurn(Player& User, Player& Enemy) {
   //roll both player and enemy dice
   int pSpeed = User.getSpeed() + rollDice();
   int eSpeed = Enemy.getSpeed() + rollDice();
   cout << pSpeed << '\t' << eSpeed << endl;
   int pTurnCounter, eTurnCounter; // turn counter so the other will always be guenteed a turn
   
   while (Enemy.getHealth() > 0) {
   restartTurn(User);
      if (pSpeed > eSpeed || pSpeed == eSpeed) {
         if (pTurnCounter == 4) {
            cout << "Player counter is full" << endl;
            eTurnCounter++; pTurnCounter = 0;
            enemyTurn(User, Enemy);
         } else {
            pTurnCounter++; eTurnCounter = 0;
            cout << "\nIt's your turn" << endl << "Your health is: " << User.getHealth() << endl;
            playerTurn(User, Enemy);
         }
      } else {
         if (eTurnCounter == 4){
            cout << "Enemy Counter is Full" << endl;
            pTurnCounter++; eTurnCounter = 0;
            cout << "\nIt's your turn" << endl << "Your health is: " << User.getHealth() << endl;
            playerTurn(User, Enemy);
         } else {
            eTurnCounter++; pTurnCounter = 0;
            cout << "you missed your turn :(" << endl;
            enemyTurn(User, Enemy);
         }
      }
      pSpeed = User.getSpeed() + rollDice();
      eSpeed = Enemy.getSpeed() + rollDice();
      cout << pSpeed << '\t' << eSpeed << endl;
   }
}