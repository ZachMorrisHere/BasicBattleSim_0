/*
*  stats.h
*/
#ifndef STATS_H_
#define STATS_H_
class stats{
   private:
   int turn = 0;
   int attbuff = 5;
   int defbuff = 5;
   int hastebuff = 2;
   int defaultAtt;
   int defaultSpeed;
   int defaultDef;
   
   public:
   //setters
   void setAttBuff(int i){attbuff = i;}
   void setDefBuff(int i){attbuff = i;}
   void setHasteBuff(int i){hastebuff = i;}
   void setDefaultAtt(int i){defaultAtt = i;}
   void setDefaultSpeed(int i){defaultSpeed = i;}
   void setDefaultDef(int i){defaultDef = i;}
   void upTurn(){turn++;}
   //getters
   int getAttBuff(){return attbuff;}
   int getDefBuff(){return defbuff;}
   int getHasteBuff(){return hastebuff;}
   int getDefaultAtt(){return defaultAtt;}
   int getDefaultSpeed(){return defaultSpeed;}
   int getDefaultDef(){return defaultDef;}
   int getTurn(){return turn;}
   
};
#endif