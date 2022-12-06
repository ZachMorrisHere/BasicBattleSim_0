/*
* Player.h
*/
#ifndef PLAYER_H_
#define PLAYER_H_
class Player {
   private:
   int health;
   int att;
   int speed;
   int def;
   int num;
   bool isInflame;
   bool isBlock;
   bool isHaste;
   
   public:
   //Setters
   void setHealth(int i) {health = i;}
   void setAtt(int i) {att = i;}
   void setSpeed(int i) {speed = i;}
   void setDef(int i) {def = i;}
   void setNum(int i) {num = i;}
   //Getters
   int getHealth() {return health;}
   int getAtt() {return att;}
   int getSpeed() {return speed;}
   int getDef() {return def;}
   int getNum() {return num;}
};
#endif