/*
*  buff.h
*/
#ifndef BUFF_H_
#define BUFF_H_
#include "Player.h"
class buff{
   public:
   void inflame(Player& x) {x.setAtt((x.getAtt() + 5)); x.setInflame(true);}
   void block(Player& x) {x.setDef((x.getDef() + 5)); x.setBlock(true);}
   void haste(Player& x) {x.setSpeed(x.getSpeed() + 5); x.setHaste(true);}
};
#endif