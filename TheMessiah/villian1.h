#ifndef VILLIAN1_INCLUDED
#define VILLIAN1_INCLUDED
#include "variables.h"

struct villian{
	int villianX;
	int villianY;
	int villian_index;
	bool villian_show;
};

villian villian1[numbersOfVillian];
villian villian12[numbersOfVillian];

void villian1Movement(){
	for (int i = 0; i < numbersOfVillian; i++){
		if (villian1[i].villian_show){
			iShowBMP2(villian1[i].villianX, villian1[i].villianY, level_1_villianattack[villian1[i].villian_index], 255);

		}
	}
}

void villian12Movement(){
	for (int i = 0; i < numbersOfVillian; i++){
		if (villian12[i].villian_show){
			iShowBMP2(villian12[i].villianX, villian12[i].villianY, level_1_villianattack[villian12[i].villian_index], 255);

		}
	}
}



void setVillianVariables1(){
	int sum = 0;
	for (int i = 0; i < numbersOfVillian; i++){
		villian1[i].villianX = screenWidth + sum;
		villian1[i].villianY = 100;
		villian1[i].villian_index = rand() % 4;
		villian1[i].villian_show = true;
		sum += 100;
	}
}

void setVillianVariables12(){
	int sum = 0;
	for (int i = 0; i < numbersOfVillian; i++){
		villian12[i].villianX = screenWidth + sum;
		villian12[i].villianY = 50;
		villian12[i].villian_index = rand() % 4;
		villian12[i].villian_show = true;
		sum += 100;
	}
}
void villian1Show(){
	for (int i = 0; i < numbersOfVillian; i++){
		villian1[i].villianX -= 10;
		int sum = 0;
		if (villian1[i].villianX <= 0){
			villian1[i].villianX = screenWidth + sum;
			sum += 100;
		}
		villian1[i].villian_index++;

		if (villian1[i].villian_index >= 3){
			villian1[i].villian_index = 0;
		}
		if (shurikenX >= villian1[i].villianX && shurikenX <= villian1[i].villianX + 87 && shurikenY >= villian1[i].villianY&&shurikenY <= villian1[i].villianY + 76){
			villian1[i].villian_show = false;
		}
		if (villian1[i].villian_show){
			if (villian1[i].villianX >= heroCoordinateX&&villian1[i].villianX <= heroCoordinateX + 174)
			{
				attacked++;
				if (attacked >= 10)
				{
					life++;
					attacked = 0;
				}
				if (life >= 6){
					//gameState = -1;
					life = 0;
				}
			}
		}
	}
}
void villian1Show1(){
	for (int i = 0; i < numbersOfVillian; i++){
		villian12[i].villianX -= 20;
		int sum = 0;
		if (villian12[i].villianX <= 0){
			villian12[i].villianX = screenWidth + sum;
			sum += 100;
		}
		villian12[i].villian_index++;

		if (villian12[i].villian_index >= 3){
			villian12[i].villian_index = 0;
		}
		if (shurikenX >= villian12[i].villianX && shurikenX <= villian12[i].villianX + 90 && shurikenY >= villian12[i].villianY&&shurikenY <= villian12[i].villianY + 80){
			villian12[i].villian_show = false;
		}
		if (villian12[i].villian_show){
			if (villian12[i].villianX >= heroCoordinateX&&villian12[i].villianX <= heroCoordinateX + 174)
			{
				attacked++;
				if (attacked >= 10)
				{
					life++;
					attacked = 0;
				}
				if (life >= 6){
					//gameState = -1;
					life = 0;
				}
			}
		}
	}
}

#endif