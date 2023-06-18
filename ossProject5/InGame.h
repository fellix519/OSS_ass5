#pragma once
#include "Root.h"
#include "Model.h"
//aa
#define STARTING_POINT_HEIGHT 10
#define STARTING_POINT_WIDTH 5

COORD curPos;
static int flag = 1;
static int obstacleCount = 0;
static int score = 0;
static int life = 1;
static int currentTime = 0;
static int eog = 0;
static int rotatedStage = 0;
static int RATE = 50;
static int gameBoardInfoHorizon[GBOARD_WIDTH] = { 0 };
static int jumpInfoHorizon[GBOARD_WIDTH] = { 0 };
static int playerInfo = 0;
static int gameBoardInfoVertical[GBOARD_HEIGHT] = { 0 };
static int jumpInfoVertical[GBOARD_HEIGHT] = { 0 };

static int jumpArray[] = { 0,0,2,2,3,3,4,4,4,4,4,4,3,3,2,2 };

static int gameInfoByStage[4][MaxObstacle][3] = {//일차원을 3개씩-y축 높이가 추가됨 [3]
   //{time, type, isJumpAvailable //false = -1, true <= 0}
   //마지막 배열은 벽을 의미한다.(---,100} 타이밍은 앞 배열 타이밍 +@으로 정한다.15정도면 쉽다? 12부터는 진짜 타이밍이다. 10밑으로 떨어지면 음...
   //아이템은 5
   {
		//1   {타이밍,장애물종류}
		// 0 1 2 3 4 ♥5 (6 7)  새 신호등 자동차 (버스  행인 하트) x x
		{0, 1,-1},{15, 0,-1},{30, 2,-1},{45, 3,-1},{60, 4,-1},{75, 5,1},{90, 1,1},{91, 1,1},{92, 1,1},{93, 1,1},{94, 1,1},{95, 1,1},{96, 1,1},{97, 1,1},{98, 1,1},{99, 1,1},{100, 1,1},{101, 1,1},{102, 1,1},{103, 1,1},{104, 1,1},
	{160, 100,-1}
	/* {0, 1,-1},{15, 2,0},{23,1,4} ,{30, 1,8},{45,1,-1},{60, 4,-1},{70, 1,-1},{80, 1,-1},{90, 4,-1},{110, 1,-1},{125, 1,-1},{133,2,-1}, {140,0,-1},{155,4,-1},{180,1,-1},{195,4,-1},{210,1,-1},{220,1,-1},{230,2,-1}, {240,0,-1},{250,1,1},{251,1,1},{252,1,1},{253,1,1},{254,1,1},{255,1,1},{256,1,1},{257,1,1},{258,1,1},{259,1,1},{260,1,1},{261,1,1},{262,1,1},{263,1,1},{264,1,1},{265,1,1},
	{330,100,-1}*/
	},{
		//2
		  //8새 9신호등 10자동차 11버스 12행인 13♥ (14 15) 새 신호등 자동차 (버스  행인 하트) x x
	   {0, 10, -1}, {14, 9,6},{28, 9,12},{42, 9,2},{56,10,4}, {70, 9,-1},{77, 12,-1},{90, 11,6},{100, 9,-1},{112, 12,-1},{123, 10,-1},{135,9,-1}, {136,8,-1}, {146,9,-1},{157,8,-1},{170,10,-1},{180,9,6},{190,8,2},{210,9,12},{221,10,-1},{233,12,-1},{245,8,-1},{260,9,-1},{270,10,-1},{285,9,-1},{297,8,-1},
		{300,9,1},{301,9,1},{302,9,1},{303,9,1},{304,9,1},{305,9,1},{306,9,1},{307,9,1},{308,9,1},{309,9,1},{310,9,1},{311,9,1},{312,9,1},{313,9,1},{314,9,1},{315,9,1},
		{380,100,-1}
	  },{
		  //1-3
		  // 16 17 18 19 20 ♥21 (22 23) 새 신호등 자동차 버스  행인 하트 x x
		  {0, 19,-1},{10,17,-1},{22, 17,4},{30,16,0},{40, 18,-1},{54,19,-1},{66, 20,-1},{76,17,12},{88,21,6},{98,17,4},{110, 17,-1},{122, 17,6},{134,17,4},{144, 20,-1},{152,16,-1},
			 {160,17,12},{162,17,-1},{178,19,-1},{184,20,-1},{190,16,-1},{200,17,12},{215,17,-1},{223,16,-1},{231,18,-1},{246,19,-1},{260,17,-1},{270,20,-1},
			 {276,17,1},{277,17,1},{278,17,1},{279,17,1},{280,17,1},{281,17,1},{282,17,1},{283,17,1},{284,17,1},{285,17,1},{286,17,1},{287,17,1},{288,17,1},{289,17,1},{290,17,1},
 {350,100,0}
		  },{
			  //1-4
			  //24 25 26 27 28 ♥29( 31 32) 새 신호등 자동차 버스  행인 하트 x x
			   {0,25,-1},{10, 26,-1}, {21, 25,-1}, {31, 25,4}, {42,28,12}, {52, 24,4},{62, 25,-1},{72, 27,-1},{83, 28,-1},{93, 27,-1},{104, 25,1},{114,25,-1},{125,24,6},{135,27,-1},{146,29,0},
			   {157,25,-1},{166,25,12},{175,24,-1},{185,26,-1},{195,27,30},{210,28,-1},{220,24,8},{231,26,-1},{240,25,-1},{250,27,-1},{270,28,0},
 {340,100,-1}
			  }
};

int printStartScreen();
void printEndingScreen();
void shiftScreenLeft();
int printObstacle();
void clearScreen();
void deleteObstacle(int, int);
void updateScore();
int InGame();
int doMotion(int);
void dropPlayer();
void deleteScreen(int, int, int, int);
void DrawGameBoard(int);
void setCurrentPlayerPos(int, int);
int detectCollision();
int JumpToNextStage();
int PlayGame();
int printGameOver();
void CreateWall();
void resetGame();
void check(int n);
void VibObstacle();
void checkArray();