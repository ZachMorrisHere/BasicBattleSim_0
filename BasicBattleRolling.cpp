#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>

//function for rolling dice
int rollDice() {
   int dice = rand()%(8-0+1);
return dice;
}

//returns random value to input for stat
int ranStatNum() {
   int val = rand()%10+1;
return val;
}

//returns a varying attack damage
int rollVar(){
   int val= rand()&2+1;
return val;
}