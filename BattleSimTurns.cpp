#include <iostream>
#include "Player.h"
#include "buff.h"
#include "stats.h"
using namespace std;

//declares all functions needed
int rollDice();
void scan(Player& En);
void attack(Player x, Player& y);
void enemyDec(Player& User, Player& Enemy);

//player turn method
void playerTurn(Player& User, Player& Enemy) {
   int playerInput;
   buff playerBuff;
   //display menu
   cout << "1: Scan" << endl << "2: Attack" << endl << "3: Boost" << endl;
   cout << "What do you choose?" << endl;
   //waits for input
   cin >> playerInput;
   while (playerInput <=0){ //while loop for verification of input
      cout << "Error please input proper number" << endl;
      //display menu
      cout << "1: scan" << endl << "2: Attack" << endl << "3: Boost" << endl;
      cout << "What do you choose?" << endl;
      //waits for input
      cin >> playerInput;     
   }
   //will carry out action the user requests
   switch (playerInput) { //navigates menu for user
      case 1: scan(Enemy); break;
      case 2: attack(User, Enemy); break;
      case 3: int input; //creates menu for boosting
              cout << "What will you boost?" << endl << "1: Inflame" << endl << "2: Block" << endl << "3: Haste" << endl << "4: Go back" << endl;
              cin >> input;
              while (input <= 0) {
                  cout << "What will you boost?" << endl << "1: Inflame" << endl << "2: Block" << endl << "3: Haste" << endl << "4: Go back" << endl; 
                  cin >> input;}
              switch(input){
                 case 1: playerBuff.inflame(User); cout << "You inflame your weapon" << endl; break;
                 case 2: playerBuff.block(User); cout << "You ready your defenses" << endl; break;
                 case 3: playerBuff.haste(User); cout << "You feel light and nimble" << endl; break;
                 case 4: playerTurn(User, Enemy); break;
              }
   }
}

//Starts enemy Turn
void enemyTurn(Player& User, Player& Enemy){
   enemyDec(User, Enemy);
}

//will check buffs and reset them as well as count turns taken
void restartTurn(Player& User, stats& UserStats){
   if (UserStats.getTurn() == 0){ //will fill in default stats for stat reversion
      UserStats.setDefaultAtt(User.getAtt());
      UserStats.setDefaultDef(User.getDef());
      UserStats.setDefaultSpeed(User.getSpeed());
   } else {
      if(User.getInflame() == true){ //checks if user is inflamed
         int k = UserStats.getAttBuff() - 1;
         UserStats.setAttBuff(k); //subtracts 1 from buff counter and then will reset if needed
         if(UserStats.getAttBuff() < 0) {User.setInflame(false); UserStats.setAttBuff(5); User.setAtt(UserStats.getDefaultAtt()); cout << "Inflame has worn off" << endl;}
      }
      if(User.getBlock() == true){ //checks if user is blocking
         int k = UserStats.getDefBuff() - 1;
         UserStats.setDefBuff(k); //subtracts 1 from buff counter and then will reset if needed
         if(UserStats.getDefBuff() < 0) {User.setBlock(false); UserStats.setDefBuff(5); User.setDef(UserStats.getDefaultDef()); cout << "Block has worn off" << endl;}
      }
      if(User.getHaste() == true){ //checks if user is in haste
         int k = UserStats.getHasteBuff() - 1;
         UserStats.setHasteBuff(k); //subtracts 1 from buff counter and then will reset if needed
         if(UserStats.getHasteBuff() < 0) {User.setHaste(false); UserStats.setHasteBuff(2); User.setSpeed(UserStats.getDefaultSpeed()); cout << "Haste has worn off" << endl;}
      }
   }
   UserStats.upTurn();
   cout << "Turn: " << UserStats.getTurn() << endl;
}

//Starts a new turn
int newTurn(Player& User, Player& Enemy, stats& UserStats) {
   //roll both player and enemy dice
   int pSpeed = User.getSpeed() + rollDice();
   int eSpeed = Enemy.getSpeed() + rollDice();
   cout << '\n' << pSpeed << '\t' << eSpeed << endl;
   int pTurnCounter, eTurnCounter; // turn counter so the other will always be guenteed a turn
   
   //Turn decision
   while (Enemy.getHealth() > 0) {
   restartTurn(User, UserStats);
      if (pSpeed > eSpeed || pSpeed == eSpeed) {
         if (pTurnCounter == 4) {
            cout << "Player counter is full" << endl;
            eTurnCounter++; pTurnCounter = 0;
            enemyTurn(User, Enemy);
         } else {
            pTurnCounter++; eTurnCounter = 0;
            cout << "\nIt's your turn" << endl << "Your health is: " << User.getHealth() << endl;
            playerTurn(User, Enemy); //starts player turn
         }
      } else {
      //checks if player or enemy counter is full
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