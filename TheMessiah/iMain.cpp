#include "iGraphics.h"
#include "bitmap_loader.h"
#include"variables.h"
#include "menu.h"
#include "heroMovement.h"
#include "villian1.h"


struct renderBackground{
	int x, y;
} background[8];
void bgShow(){
	for (int i = 0; i < 8; i++)
		iShowBMP(background[i].x, background[i].y, backGround1[i]);
}


void iDraw()
{
	iClear();

	if (gameState == -1){
		menuShow();
	}
	else if (gameState == 0)

	{
		if (!level1){
			iShowImage(0, 0, screenWidth, screenHeigth, iLoadImage(frames[frameIndex]));
		}
		else if(level1&&level==1){
			bgShow();
			lifeBar();
			villian1Movement();
			villian12Movement();
			if (jump){
				Jump();
			}
			else{
				Character();
			}
		}
}
	else if (gameState == 1)
	{
		iShowImage(0, 0, screenWidth, screenHeigth, iLoadImage(pages[2]));
	}
	else if (gameState == 2)
	{
		iShowImage(0, 0, screenWidth, screenHeigth, iLoadImage(pages[3]));
	}
	else if (gameState == 3)
	{
		iShowImage(0, 0, screenWidth, screenHeigth, iLoadImage(pages[4]));
	}
	else if (gameState == 4)
	{
		exit(0);
	}
	
	
}
void changeBackground()
{
	if (level1){
		if (standPosition == false){
			for (int i = 0; i < 8; i++)
			{
				background[i].x -= backGroundSpeed;
				if (background[i].x < 0)
					background[i].x = screenWidth - 200;
			}
		}
	}
	
}

void iPassiveMouse(int x, int y)
{
	;
}


/*
 function iMouseMove() is called when the user presses and drags the mouse.
 (mx, my) is the position where the mouse pointer is.
 */
void iMouseMove(int mx, int my){}

/*
 function iMouse() is called when the user presses/releases the mouse.
 (mx, my) is the position where the mouse pointer is.
 */
void iMouse(int button, int state, int mx, int my){

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){

		for (int i = 0; i < 5; i++){
			if (mx >= buttonCordinate[i].x && mx <= buttonCordinate[i].x + 434 && my >= buttonCordinate[i].y && my <= buttonCordinate[i].y + 104)
			{
				gameState = i;
				if (gameState == 0){
					level1 = false;
				}
			}
		}
	}


}
/*function iKeyboard() is called whenever the user hits a key in keyboard.key- holds the ASCII value of the key pressed.*/
void iKeyboard(unsigned char key){

	if (key =='\t' )
	{
		if (!level1){
			gameState = -1;
		}
	}
	else if (key == ' '){
		if (!jump){
			jump = true;
			jumpUp = true;
		}
	}
	else if (key == 'd' || key == 'D'){
		standPosition = false;
		reverseStand = false;
		front = true;
		heroCoordinateX += 20;
		if (heroCoordinateX >= screenWidth){

			heroCoordinateX = 0;
		}
		heroIndex++;
		if (heroIndex >= 8)
			heroIndex = 0;
		if (heroCoordinateX >= screenWidth - 150)

			heroCoordinateX = screenWidth - 150;


	}
	else if (key == 'a' || key == 'A'){
		standPosition = false;
		heroCoordinateX -= 10;
		reverseStand = true;
		front = false;
		if (heroCoordinateX <= 20){
			heroCoordinateX = 10;
		}
		heroReverseIndex++;

		if (heroReverseIndex >= 8)
		{
			heroReverseIndex = 0;
		}
	}
	else if (key == 's' || key == 'S'){
		standPosition = false;
		heroCoordinateY -= 15;
		front = true;
		if (heroCoordinateY <=0){
			heroCoordinateY = 0;
		}
		heroIndex++;
		if (heroIndex >= 8)
		{
			heroIndex = 0;
		}
	}
	else if (key == 'w' || key == 'W'){
		standPosition = false;
		reverseStand = false;
		front = true;
		heroCoordinateY += 15;
		if (heroCoordinateY >= 110){
			heroCoordinateY = 110;
		}
		heroIndex++;
		if (heroIndex >= 8)
			heroIndex = 0;
		if (heroCoordinateX >= screenWidth - 150)
			heroCoordinateX = screenWidth - 150;
	}
	else if (key == 'e' || key == 'E'){
		heroFire = true;
		if (!firing){
			firing = true;
			if (level1){
				shurikenX = heroCoordinateX;
				if (jumpUp) shurikenY = heroCoordinateY + heroCoordinateJump + 100;
				else shurikenY = heroCoordinateY + 100;
			}
		}
	}
}


void iSpecialKeyboard(unsigned char key)
{
	if (key == GLUT_KEY_F2){

		if (frameShowed&&!level1){
			frameIndex++;
			level1 = false;
			if (frameIndex == 5){
				frameIndex = 0;
				level1 = true;
				level = 1;
				}
		}
	}
}
void setbackground()
{
	int sum = 0;
	for (int i = 0; i < 8; i++)
	{
		background[i].x = sum;
		background[i].y = 0;
		sum += 200;
	}
}
int main()
{
	setVillianVariables1();
	setVillianVariables12();
	setbackground();
	iSetTimer(400, changeBackground);
	iSetTimer(20, fire_shuriken);
	iSetTimer(100, villian1Show);
	iSetTimer(100, villian1Show1);
	iSetTimer(20, fireCharacter);
	iSetTimer(20, jumpchange);

	showButton();

	iInitialize(screenWidth, screenHeigth, projectName);

	iStart(); // it will start drawing

	return 0;
}

