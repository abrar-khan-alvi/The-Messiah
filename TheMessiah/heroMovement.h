#ifndef HEROMOVEMENT_INCLUDED
#define HEROMOVEMENT_INCLUDED
#include "variables.h"

void Jump(){
	
	if (firing&&front){
	iShowBMP2(shurikenX, shurikenY-50, shuriken[0], 255);
	}
	
	

	if (jumpUp)
	{

		if (reverseStand){

			iShowBMP2(heroCoordinateX, heroCoordinateY + heroCoordinateJump, herorevjump[0], 255);
			
		}
		else if (heroFire){
			iShowBMP2(heroCoordinateX, heroCoordinateY + heroCoordinateJump, heroattack[fireIndex], 255);
		}
		else{
			iShowBMP2(heroCoordinateX, heroCoordinateY + heroCoordinateJump, herojump[0], 255);
		}
	


	}


	else
	{
		if (reverseStand){
			iShowBMP2(heroCoordinateX, heroCoordinateY + heroCoordinateJump, herorevjump[1], 255);
		}
		else if (heroFire){
			iShowBMP2(heroCoordinateX, heroCoordinateY + heroCoordinateJump, heroattack[fireIndex], 255);
		}
		else{
			iShowBMP2(heroCoordinateX, heroCoordinateY + heroCoordinateJump, herojump[1], 255);
		}
	}

}

void Character(){
	if (firing&&front){
		iShowBMP2(shurikenX, shurikenY-50, shuriken[0], 255);
	}

	if (!standPosition){
		if (reverseStand)
		{
			iShowBMP2(heroCoordinateX, heroCoordinateY, herorevwalk[heroReverseIndex], 255);
		}
		else if (heroFire){
			iShowBMP2(heroCoordinateX, heroCoordinateY, heroattack[fireIndex], 255);
		}
		else
		{
			iShowBMP2(heroCoordinateX, heroCoordinateY, herowalk[heroIndex], 255);
		}

		standCounter++;
		if (standCounter >= 10){
			standCounter = 0;
			standPosition = true;
			heroIndex = 0;
		}
	}
	else
	{
		if (reverseStand)
		{
			iShowBMP2(heroCoordinateX, heroCoordinateY, heroidle[1], 255);
		}
		else if (heroFire){
			iShowBMP2(heroCoordinateX, heroCoordinateY, heroattack[fireIndex], 255);
		}
		else
		{
			iShowBMP2(heroCoordinateX, heroCoordinateY, heroidle[0], 255);
		}

	}
}


void jumpchange(){

	if (jump){

		if (jumpUp){

			heroCoordinateJump += 10;
			if (heroCoordinateJump >= JUMPLIMIT){

				jumpUp = false;

			}
		}
		else{
			heroCoordinateJump -= 10;

			if (heroCoordinateJump < 0){

				jump = false;

				heroCoordinateJump = 0;
			}
		}
	}


}


void fire_shuriken(){
	if (firing&&front){
		for (int i = 0; i < 152; i++){
			shurikenX++;
			if (shurikenX>screenWidth){
				firing = false;
				if (level1) shurikenX = heroCoordinateX + 10000000000000000000;

			}
		}
	}
}
void fireCharacter(){
	if (heroFire){
		fireIndex++;
		if (fireIndex >= 4){
			fireIndex = 0;
			heroFire = false;
		}
	}

}



#endif