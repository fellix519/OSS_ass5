#include "InGame.h"
#include "Cursor.h"
#include "Character.h"
#include "Model.h"
#include "UI.h"
#include "Root.h"
#include<mmsystem.h>//p;aysound  �Լ� ���� ���
#include<conio.h>
#pragma comment(lib,"winmm.lib")

//InGame Ư�����
int InGame() {

	int startButton = printStartScreen();


	if (startButton/* == SPACE*/)
		return PlayGame();
}


int PlayGame() {}


//ĳ���� ���� �Լ�
int doMotion(int stage) {}
int detectCollision() {}

//��ֹ� ���� �Լ�
void shiftScreenLeft() {}
int printObstacle() {}
void deleteObstacle(int type, int tx, int para) {}

// ��ũ�� ���� ���� �Լ�
void clearScreen() {
	if (rotatedStage % 2 == 0) {
		for (int tx = 0; tx < GBOARD_WIDTH; tx++) {
			int info = gameBoardInfoHorizon[tx];
			if (info != -1) {
				int jump = jumpInfoHorizon[tx];
				if (jump >= 1) {
					deleteObstacle(info, tx + 1, jumpArray[(jump - 1) % 16]);
				}
				else {
					deleteObstacle(info, tx + 1, -1);
				}
			}
		}
	}
	else {
		for (int ty = 0; ty < GBOARD_HEIGHT; ty++) {
			int info = gameBoardInfoVertical[ty];
			if (info != -1) {
				int jump = jumpInfoVertical[ty];
				if (jump >= 1) {
					//printf("cs:%d", jumpArray[(jump - 1) % 16]); Sleep(500);
					deleteObstacle(info, ty + 1, jumpArray[(jump - 1) % 16]);
				}
				else {
					deleteObstacle(info, ty + 1, -1);
				}
			}
		}
	}
}
void deleteScreen(int x1, int y1, int x2, int y2) {
	for (int y = y1; y <= y2; y++) {
		for (int x = x1; x <= x2; x++) {
			SetCurrentCursorPos(GBOARD_ORIGIN_X + x * 2, GBOARD_ORIGIN_Y + y);
			printf("  ");
		}
	}
}

//UI ���� �Լ�
void printEndingScreen() {}
int printStartScreen() {
	DrawGameBoard(0);

	Showcharacter(Character[0], GBOARD_ORIGIN_X + STARTING_POINT_WIDTH * 2, GBOARD_ORIGIN_Y + GBOARD_HEIGHT - STARTING_POINT_HEIGHT);

	SetCurrentCursorPos(GBOARD_ORIGIN_X + 4, GBOARD_ORIGIN_Y + GBOARD_HEIGHT / 3);
	printf("Press \'SPACE\' Start!");

	int startButton;
	while (1) {
		startButton = _getch();
		if (startButton == SPACE) {
			break;
		}
	}
	deleteScreen(2, GBOARD_HEIGHT / 3, 32, GBOARD_HEIGHT / 3);

	return startButton;
}

//�ʵ� ���� �Լ�
//void dropPlayer() {}
//int JumpToNextStage() {}
void DrawGameBoard(int rotatedStage) {
	int HorV = GBOARD_WIDTH;
	int* p=NULL;
	if (rotatedStage % 2 == 0) {
		HorV = GBOARD_WIDTH;
		p = gameBoardInfoHorizon;
	}
	else if (rotatedStage % 2 == 1) {
		HorV = GBOARD_HEIGHT;
		p = gameBoardInfoVertical;
	}
	for (int i = 0; i < HorV; i++) {
		p[i] = -1;
	}
	system("cls");
	switch (rotatedStage) {
	case 0:
		RATE = 40;
		for (int i = 0; i < GBOARD_WIDTH; i++) {
			SetCurrentCursorPos(GBOARD_ORIGIN_X + i * 2, GBOARD_ORIGIN_Y + GBOARD_HEIGHT);
			printf("��");
		}
		break;
	case 1:
		RATE = 30;
		for (int i = 0; i < GBOARD_HEIGHT; i++) {
			SetCurrentCursorPos(GBOARD_ORIGIN_X + (GBOARD_WIDTH - 1) * 2, GBOARD_ORIGIN_Y + i);
			printf("��");
		}
		break;
	case 2:
		RATE = 25;
		for (int i = 0; i < GBOARD_WIDTH; i++) {
			SetCurrentCursorPos(GBOARD_ORIGIN_X + i * 2, GBOARD_ORIGIN_Y);
			printf("��");
		}
		break;
	case 3:
		RATE = 20;
		for (int i = 0; i < GBOARD_HEIGHT; i++) {
			SetCurrentCursorPos(GBOARD_ORIGIN_X, GBOARD_ORIGIN_Y + i);
			printf("��");
		}
		break;
	default:
		break;
	}
}
//void CreateWall() {}






//��Ÿ �Լ�
//void check(int n)
//void setCurrentPlayerPos(int x1, int y1) {}