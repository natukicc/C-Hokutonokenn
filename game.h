#pragma once
#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

/*===Constant Definition===*/
#define GAME_FLOOR_Y 480
enum _GameStat
{
	GAME_STAT_NULL,
	GAME_STAT_PLAYING
};
enum _GameObjectDirection
{
	GAME_OBJECT_DIRECTION_LEFT,
	GAME_OBJECT_DIRECTION_RIGHT
};
enum _GamePlayerStat
{
	GAME_PLAYER_STAT_STAND,
	GAME_PLAYER_STAT_MOVE,
	GAME_PLAYER_STAT_BACK,
	GAME_PLAYER_STAT_CORUCH_DEFENCE,
	GAME_PLAYER_STAT_JUMPUP,
	GAME_PLAYER_STAT_JUMPDOWN,
	GAME_PLAYER_STAT_PUNCH,
	GAME_PLAYER_STAT_KICK
};

#define GAME_CREEP_NUM 4
#define GAME_CREEP_WALK_DISTANCE 160
enum _GameCreepType
{
	GAME_CREEP_TYPE_OCTOPUS
};
enum _GameCreepStat
{
	GAME_CREEP_STAT_WALK,
	GAME_CREEP_STAT_ATTACK,
	GAME_CREEP_STAT_BACK
};

/*===Structure Definition===*/
typedef struct _GamePlayer
{
	int HP;
	int x;
	int y;
	double ySpeed;
	int direction;
	int stat;
} GamePlayer;

typedef struct _GameCreep
{
	int creepType;
	int HP;
	int x;
	int xSpeed;
	int y;
	int ySpeed;
	int direction;
	BOOL isAlert;
	int walkDistance;
	int stat;
} GameCreep;

/*===Global Definition===*/
static int Game_Global_Stat = GAME_STAT_NULL;
static GamePlayer Game_Global_Player;
static GameCreep Game_Global_CreepArr[GAME_CREEP_NUM];
/*===Function Reference===*/
void GameInit();
void GameUninit();
void GameEntry();
//Player Operation
void GamePlayerStatListener();
void GameKeyListener();
//Background
void GameDrawBackground();
//Creep
void GameCreepStatListener();
void GameDrawCreep();
void GameDrawCreepOctopus(int index);
//Player
void GameDrawPlayer();
void GameDrawPlayerStatStand();
void GameDrawPlayerStatMoveSlowly();
void GameDrawPlayerStatBackSlowly();
void GameDrawPlayerStatCrouchGuard(BOOL isReset);
void GameDrawPlayerPunch();
void GameDrawPlayerJump();
void GameDrawPlayerKick();
/*===Function Definition===*/
void GameInit()
{
	int i, rnd = 0;
	//Player
	Game_Global_Stat = GAME_STAT_PLAYING;
	Game_Global_Player.HP = 100;
	Game_Global_Player.x = 0;
	Game_Global_Player.y = GAME_FLOOR_Y - 54;
	Game_Global_Player.direction = GAME_OBJECT_DIRECTION_RIGHT;
	Game_Global_Player.stat = GAME_PLAYER_STAT_STAND;
	//Creep
	srand((unsigned)time(NULL));
	for(i = 0; i < GAME_CREEP_NUM; i++)
	{
		Game_Global_CreepArr[i].creepType = GAME_CREEP_TYPE_OCTOPUS;
		Game_Global_CreepArr[i].HP = 10;
		rnd = rand()%150;
		Game_Global_CreepArr[i].x = (int)(NTK_WINDOW_WIDTH * (4/5.0)) - rnd;
		Game_Global_CreepArr[i].xSpeed = 0;
		Game_Global_CreepArr[i].y = GAME_FLOOR_Y + 18;
		Game_Global_CreepArr[i].ySpeed = 0;
		rnd = rand()%2;
		Game_Global_CreepArr[i].direction = rnd;
		Game_Global_CreepArr[i].isAlert = FALSE;
		Game_Global_CreepArr[i].walkDistance = GAME_CREEP_WALK_DISTANCE;
		Game_Global_CreepArr[i].stat = GAME_CREEP_STAT_WALK;
	}
}
void GameUninit()
{
	Game_Global_Stat = GAME_STAT_NULL;
}
void GameEntry()
{
	while(Game_Global_Stat == GAME_STAT_PLAYING)
	{
		GameDrawBackground();
		GameDrawPlayer();
		GamePlayerStatListener();
		GameKeyListener();
		GameCreepStatListener();
		GameDrawCreep();
		
		NtkGDI_update();
		Sleep(100);
	}
}

void GamePlayerStatListener()
{
	const double g = 9.8;
	//Stat listener
	if(Game_Global_Player.stat == GAME_PLAYER_STAT_MOVE || Game_Global_Player.stat == GAME_PLAYER_STAT_BACK || Game_Global_Player.stat ==  GAME_PLAYER_STAT_CORUCH_DEFENCE || Game_Global_Player.stat ==  GAME_PLAYER_STAT_PUNCH || Game_Global_Player.stat == GAME_PLAYER_STAT_KICK)
	{
		Game_Global_Player.stat = GAME_PLAYER_STAT_STAND;
	}
	else if (Game_Global_Player.stat == GAME_PLAYER_STAT_JUMPUP)
	{
		Game_Global_Player.ySpeed -= g;
		Game_Global_Player.y -= (int)(Game_Global_Player.ySpeed);
		if(Game_Global_Player.ySpeed <= 0)
		{
			Game_Global_Player.stat = GAME_PLAYER_STAT_JUMPDOWN;
		}
	}
	else if(Game_Global_Player.stat == GAME_PLAYER_STAT_JUMPDOWN)
	{
		Game_Global_Player.ySpeed += g;
		Game_Global_Player.y += (int)(Game_Global_Player.ySpeed);
		if(Game_Global_Player.y >= GAME_FLOOR_Y - 54)
		{
			Game_Global_Player.y = GAME_FLOOR_Y - 54;
			Game_Global_Player.ySpeed = 0;
			Game_Global_Player.stat = GAME_PLAYER_STAT_STAND;
		}
	}
}
void GameKeyListener()
{
	//Key listener
	if(GetAsyncKeyState(0x57) & 0x8000) //W
	{

		if(Game_Global_Player.stat != GAME_PLAYER_STAT_JUMPUP && Game_Global_Player.stat != GAME_PLAYER_STAT_JUMPDOWN)
		{
			Game_Global_Player.ySpeed = 65;
			Game_Global_Player.stat = GAME_PLAYER_STAT_JUMPUP;
		}
	}
	if(GetAsyncKeyState(0x53) & 0x8000) //S
	{
		if(Game_Global_Player.direction = GAME_OBJECT_DIRECTION_RIGHT)
		{
			if(Game_Global_Player.stat == GAME_PLAYER_STAT_STAND)
			{
				Game_Global_Player.stat = GAME_PLAYER_STAT_CORUCH_DEFENCE;
			}
		}
	}
	if(GetAsyncKeyState(0x41) & 0x8000) //A
	{
		if(Game_Global_Player.direction = GAME_OBJECT_DIRECTION_RIGHT)
		{
			Game_Global_Player.x -= 10;
			if(Game_Global_Player.stat == GAME_PLAYER_STAT_STAND)
			{
				Game_Global_Player.stat = GAME_PLAYER_STAT_BACK;
			}
		}
	}
	if(GetAsyncKeyState(0x44) & 0x8000) //D
	{
		if(Game_Global_Player.direction = GAME_OBJECT_DIRECTION_RIGHT)
		{
			Game_Global_Player.x += 10;
			if(Game_Global_Player.stat == GAME_PLAYER_STAT_STAND)
			{
				Game_Global_Player.stat = GAME_PLAYER_STAT_MOVE;
			}
		}
	}
	if(GetAsyncKeyState(0x4A) & 0x8000) //J
	{
		if(Game_Global_Player.stat != GAME_PLAYER_STAT_JUMPUP && Game_Global_Player.stat != GAME_PLAYER_STAT_JUMPDOWN)
		{
			Game_Global_Player.stat = GAME_PLAYER_STAT_PUNCH;
			Game_Global_Player.x += 1;
		}
	}
	if(GetAsyncKeyState(0x4B) & 0x8000) //J
	{
		if(Game_Global_Player.stat != GAME_PLAYER_STAT_JUMPUP && Game_Global_Player.stat != GAME_PLAYER_STAT_JUMPDOWN)
		{
			Game_Global_Player.stat = GAME_PLAYER_STAT_KICK;
			Game_Global_Player.x += 1;
		}
	}
}

void GameDrawBackground()
{
	const int BG_MAX_STAT = 8;
	static BOOL isFirstEntry = TRUE;
	static int bgStat = 0;
	static NImage imgBg;
	if(isFirstEntry)
	{
		isFirstEntry = FALSE;
		bgStat = 0;
		NtkGDI_LoadImage(&imgBg, "images/background.bmp", 0, 0);
	}
	NtkGDI_PutImageEx(&imgBg, 0, 0, NTK_WINDOW_WIDTH, NTK_WINDOW_HEIGHT, 0, bgStat*336, 800, 336, FALSE, NOTRANSPARENT, SRCCOPY);
	if(bgStat < BG_MAX_STAT)
	{
		bgStat++;
	}
	else
	{
		bgStat = 0;
	}
}

void GameCreepStatListener()
{
	int i;
	const double g = 9.8, af = 3;
	for(i = 0; i < GAME_CREEP_NUM; i++)
	{
		if(Game_Global_CreepArr[i].HP <= 0)
		{
			continue;
		}
		if(Game_Global_CreepArr[i].isAlert == FALSE)
		{
			if(Game_Global_CreepArr[i].direction == GAME_OBJECT_DIRECTION_LEFT)
			{
				Game_Global_CreepArr[i].x -= 10;
				//is change direction
				Game_Global_CreepArr[i].walkDistance -= 10;
				if(Game_Global_CreepArr[i].walkDistance <= 0)
				{
					Game_Global_CreepArr[i].direction = GAME_OBJECT_DIRECTION_RIGHT;
					Game_Global_CreepArr[i].walkDistance = GAME_CREEP_WALK_DISTANCE;
				}
			}
			else if(Game_Global_CreepArr[i].direction == GAME_OBJECT_DIRECTION_RIGHT)
			{
				Game_Global_CreepArr[i].x += 10;
				//is change direction
				Game_Global_CreepArr[i].walkDistance -= 10;
				if(Game_Global_CreepArr[i].walkDistance <= 0)
				{
					Game_Global_CreepArr[i].direction = GAME_OBJECT_DIRECTION_LEFT;
					Game_Global_CreepArr[i].walkDistance = GAME_CREEP_WALK_DISTANCE;
				}
			}
		}
	}
}
void GameDrawCreep()
{
	int i;
	for(i = 0; i < GAME_CREEP_NUM; i++)
	{
		if(Game_Global_CreepArr[i].HP <= 0)
		{
			continue;
		}
		switch(Game_Global_CreepArr[i].creepType)
		{
			case GAME_CREEP_TYPE_OCTOPUS:
				GameDrawCreepOctopus(i);
				break;
		}
		NtkGDI_DrawSolidLine(Game_Global_CreepArr[i].x, Game_Global_CreepArr[i].y, Game_Global_CreepArr[i].x, Game_Global_CreepArr[i].y+1, RGB(255,0,0), 5);
	}
}
void GameDrawCreepOctopus(int index)
{
	const double GAME_CREEP_ZOOM = 1.8;
	const int MOVE_MAX_STAT = 5;
	const int MOVE_IMG_OFFSET_X = 50, MOVE_IMG_OFFSET_Y = 46;
	static BOOL isFirstEntry = TRUE;
	static int moveStat = 0;
	static NImage imgCreep, imgCreep_right;
	if(isFirstEntry)
	{
		isFirstEntry = FALSE;
		moveStat = 0;
		NtkGDI_LoadImage(&imgCreep, "images/figure/creep/octopus.bmp", 0, 0);
		NtkGDI_LoadImage(&imgCreep_right, "images/figure/creep/octopus_right.bmp", 0, 0);
	}
	if(Game_Global_CreepArr[index].direction == GAME_OBJECT_DIRECTION_LEFT)
	{
		NtkGDI_PutImageEx(
			&imgCreep, 
			Game_Global_CreepArr[index].x - (int)(MOVE_IMG_OFFSET_X*GAME_CREEP_ZOOM), Game_Global_CreepArr[index].y - (int)(MOVE_IMG_OFFSET_Y*GAME_CREEP_ZOOM), (int)(110*GAME_CREEP_ZOOM), (int)(imgCreep.height*GAME_CREEP_ZOOM),
			moveStat*110, 0, 110, imgCreep.height,
			FALSE, RGB(255,0,255), SRCCOPY
		);
	}
	else
	{
		NtkGDI_PutImageEx(
			&imgCreep_right, 
			Game_Global_CreepArr[index].x - (int)(MOVE_IMG_OFFSET_X*GAME_CREEP_ZOOM), Game_Global_CreepArr[index].y - (int)(MOVE_IMG_OFFSET_Y*GAME_CREEP_ZOOM), (int)(110*GAME_CREEP_ZOOM), (int)(imgCreep_right.height*GAME_CREEP_ZOOM),
			moveStat*110, 0, 110, imgCreep_right.height,
			FALSE, RGB(255,0,255), SRCCOPY
		);
	}
	
	if(moveStat < MOVE_MAX_STAT)
	{
		moveStat++;
	}
	else
	{
		moveStat = 0;
	}
}

void GameDrawPlayer()
{
	static int lastAction = GAME_PLAYER_STAT_STAND;
	switch(Game_Global_Player.stat)
	{
	case GAME_PLAYER_STAT_STAND:
		GameDrawPlayerStatStand();
		break;
	case GAME_PLAYER_STAT_MOVE:
		GameDrawPlayerStatMoveSlowly();
		break;
	case GAME_PLAYER_STAT_BACK:
		GameDrawPlayerStatBackSlowly();
		break;
	case GAME_PLAYER_STAT_CORUCH_DEFENCE:
		if(lastAction != GAME_PLAYER_STAT_CORUCH_DEFENCE)
		{
			GameDrawPlayerStatCrouchGuard(TRUE);
		}
		else
		{
			GameDrawPlayerStatCrouchGuard(FALSE);
		}
		break;
	case GAME_PLAYER_STAT_PUNCH:
		GameDrawPlayerPunch();
		break;
	case GAME_PLAYER_STAT_JUMPUP:
	case GAME_PLAYER_STAT_JUMPDOWN:
		GameDrawPlayerJump();
		break;
	case GAME_PLAYER_STAT_KICK:
		GameDrawPlayerKick();
		break;
	}
	lastAction = Game_Global_Player.stat;
	NtkGDI_DrawSolidLine(Game_Global_Player.x, Game_Global_Player.y, Game_Global_Player.x, Game_Global_Player.y+1, RGB(255,0,0), 5);
}
void GameDrawPlayerStatStand()
{
	const double GAME_PLAYER_ZOOM = 1.9;
	const int STAND_MAX_STAT = 6;
	const int STAND_IMG_OFFSET_X = 10, STAND_IMG_OFFSET_Y = 38;
	static BOOL isFirstEntry = TRUE, isActionReverse = FALSE;
	static int standStat = 0;
	static NImage imgPlayer;
	if(isFirstEntry)
	{
		isFirstEntry = FALSE;
		standStat = 0;
		NtkGDI_LoadImage(&imgPlayer, "images/figure/main/Stand.bmp", 0, 0);
	}
	NtkGDI_PutImageEx(
		&imgPlayer, 
		Game_Global_Player.x - (int)(STAND_IMG_OFFSET_X*GAME_PLAYER_ZOOM), Game_Global_Player.y - (int)(STAND_IMG_OFFSET_Y*GAME_PLAYER_ZOOM), (int)(68*GAME_PLAYER_ZOOM), (int)(imgPlayer.height*GAME_PLAYER_ZOOM),
		standStat*68, 0, 68, imgPlayer.height,
		FALSE, RGB(255,0,255), SRCCOPY
		);
	if(isActionReverse)
	{
		if(standStat > 0)
		{
			standStat--;
		}
		else
		{
			isActionReverse = FALSE;
		}
	}
	else
	{
		if(standStat < STAND_MAX_STAT)
		{
			standStat++;
		}
		else
		{
			isActionReverse = TRUE;
		}
	}
}
void GameDrawPlayerStatMoveSlowly()
{
	const int GAME_PLAYER_ZOOM = 2;
	const int MOVE_MAX_STAT = 4;
	const int MOVE_IMG_OFFSET_X = 26, MOVE_IMG_OFFSET_Y = 41;
	static BOOL isFirstEntry = TRUE;
	static int moveStat = 0;
	static NImage imgPlayer;
	if(isFirstEntry)
	{
		isFirstEntry = FALSE;
		moveStat = 0;
		NtkGDI_LoadImage(&imgPlayer, "images/figure/main/MoveSlowly.bmp", 0, 0);
	}
	NtkGDI_PutImageEx(
		&imgPlayer, 
		Game_Global_Player.x - MOVE_IMG_OFFSET_X*GAME_PLAYER_ZOOM, Game_Global_Player.y - MOVE_IMG_OFFSET_Y*GAME_PLAYER_ZOOM, 56*GAME_PLAYER_ZOOM, imgPlayer.height*GAME_PLAYER_ZOOM,
		moveStat*56, 0, 56, imgPlayer.height,
		FALSE, RGB(255,0,255), SRCCOPY
		);
	if(moveStat < MOVE_MAX_STAT)
	{
		moveStat++;
	}
	else
	{
		moveStat = 0;
	}
}
void GameDrawPlayerStatBackSlowly()
{
	const int GAME_PLAYER_ZOOM = 2;
	const int MOVE_MAX_STAT = 4;
	const int MOVE_IMG_OFFSET_X = 26, MOVE_IMG_OFFSET_Y = 41;
	static BOOL isFirstEntry = TRUE;
	static int moveStat = 0;
	static NImage imgPlayer;
	if(isFirstEntry)
	{
		isFirstEntry = FALSE;
		moveStat = 0;
		NtkGDI_LoadImage(&imgPlayer, "images/figure/main/MoveBackSlowly.bmp", 0, 0);
	}
	NtkGDI_PutImageEx(
		&imgPlayer, 
		Game_Global_Player.x - MOVE_IMG_OFFSET_X*GAME_PLAYER_ZOOM, Game_Global_Player.y - MOVE_IMG_OFFSET_Y*GAME_PLAYER_ZOOM, 49*GAME_PLAYER_ZOOM, imgPlayer.height*GAME_PLAYER_ZOOM,
		moveStat*49, 0, 49, imgPlayer.height,
		FALSE, RGB(255,0,255), SRCCOPY
		);
	if(moveStat < MOVE_MAX_STAT)
	{
		moveStat++;
	}
	else
	{
		moveStat = 0;
	}
}
void GameDrawPlayerStatCrouchGuard(BOOL isReset)
{
	const int GAME_PLAYER_ZOOM = 2;
	const int DEFENCE_MAX_STAT = 3;
	const int DEFENCE_IMG_OFFSET_X = 17, DEFENCE_IMG_OFFSET_Y = 33;
	static BOOL isFirstEntry = TRUE;
	static int defenceStat = 0;
	static NImage imgPlayer;
	if(isFirstEntry)
	{
		isFirstEntry = FALSE;
		defenceStat = 0;
		NtkGDI_LoadImage(&imgPlayer, "images/figure/main/CrouchDefence.bmp", 0, 0);
	}
	if(isReset)
	{
		defenceStat = 0;
	}
	NtkGDI_PutImageEx(
		&imgPlayer, 
		Game_Global_Player.x - DEFENCE_IMG_OFFSET_X*GAME_PLAYER_ZOOM, Game_Global_Player.y -(DEFENCE_IMG_OFFSET_Y)*GAME_PLAYER_ZOOM + 65, 45*GAME_PLAYER_ZOOM, imgPlayer.height*GAME_PLAYER_ZOOM,
		defenceStat*45, 0, 45, imgPlayer.height,
		FALSE, RGB(255,0,255), SRCCOPY
		);
	if(defenceStat < DEFENCE_MAX_STAT)
	{
		defenceStat++;
	}
}
void GameDrawPlayerJump()
{
	const int GAME_PLAYER_ZOOM = 2;
	const int JUMP_IMG_OFFSET_X = 17, JUMP_IMG_OFFSET_Y = 70;
	static BOOL isFirstEntry = TRUE;
	static int jumpStat = 0;
	static NImage imgPlayer;
	if(isFirstEntry)
	{
		isFirstEntry = FALSE;
		NtkGDI_LoadImage(&imgPlayer, "images/figure/main/Jump.bmp", 0, 0);
	}
	if(Game_Global_Player.stat == GAME_PLAYER_STAT_JUMPUP)
	{
		if(Game_Global_Player.y >= GAME_FLOOR_Y - 54)
		{
			jumpStat = 0;
		}
		else
		{
			jumpStat = 1;
		}
	}
	else if(Game_Global_Player.stat == GAME_PLAYER_STAT_JUMPDOWN)
	{
		if(Game_Global_Player.y >= GAME_FLOOR_Y - 54)
		{
			jumpStat = 0;
		}
		else if(Game_Global_Player.ySpeed >= 30)
		{
			jumpStat = 3;
		}
		else
		{
			jumpStat = 2;
		}
	}
	NtkGDI_PutImageEx(&imgPlayer,
		Game_Global_Player.x - JUMP_IMG_OFFSET_X*GAME_PLAYER_ZOOM, Game_Global_Player.y - JUMP_IMG_OFFSET_Y*GAME_PLAYER_ZOOM, 66*GAME_PLAYER_ZOOM, imgPlayer.height*GAME_PLAYER_ZOOM,
		jumpStat*66, 0, 66,imgPlayer.height,
		FALSE, RGB(255,0,255), SRCCOPY
		);
}
void GameDrawPlayerPunch()
{
	const int GAME_PLAYER_ZOOM = 2;
	const int MOVE_MAX_STAT = 10;
	const int MOVE_IMG_OFFSET_X = 26, MOVE_IMG_OFFSET_Y = 41;
	static BOOL isFirstEntry = TRUE;
	static int coverStat = 0, moveStat = 0;
	static NImage imgPlayer1, imgPlayer2;
	if(isFirstEntry)
	{
		isFirstEntry = FALSE;
		moveStat = 0;
		NtkGDI_LoadImage(&imgPlayer1,"images/figure/main/Attack1.bmp",0,0);
		NtkGDI_LoadImage(&imgPlayer2,"images/figure/main/Attack2.bmp",0,0);
	}
	if(coverStat == 0)
	{
		NtkGDI_PutImageEx(&imgPlayer1,
			Game_Global_Player.x - MOVE_IMG_OFFSET_X*GAME_PLAYER_ZOOM - 65, Game_Global_Player.y - MOVE_IMG_OFFSET_Y*GAME_PLAYER_ZOOM -35, 162*GAME_PLAYER_ZOOM, imgPlayer1.height*GAME_PLAYER_ZOOM,
			moveStat*162,0,162,imgPlayer1.height,
			FALSE, RGB(255,0,255), SRCCOPY
			);
	}
	else
	{
		NtkGDI_PutImageEx(&imgPlayer2,
			Game_Global_Player.x - MOVE_IMG_OFFSET_X*GAME_PLAYER_ZOOM - 65, Game_Global_Player.y - MOVE_IMG_OFFSET_Y*GAME_PLAYER_ZOOM -35, 162*GAME_PLAYER_ZOOM, imgPlayer2.height*GAME_PLAYER_ZOOM,
			moveStat*162,0,162,imgPlayer2.height,
			FALSE, RGB(255,0,255), SRCCOPY
			);
	}

	if(moveStat < MOVE_MAX_STAT)
	{
		moveStat++;
	}
	else
	{
		if(coverStat == 0)
		{
			coverStat = 1;
		}
		else
		{
			coverStat = 0;
		}
		moveStat = 0;
	}
}
void GameDrawPlayerKick()
{
	const int GAME_PLAYER_ZOOM = 2;
	const int MOVE_MAX_STAT = 10;
	const int MOVE_IMG_OFFSET_X = 26, MOVE_IMG_OFFSET_Y = 41;
	static BOOL isFirstEntry = TRUE;
	static int coverStat = 0, moveStat = 0;
	static NImage imgPlayer1, imgPlayer2;
	if(isFirstEntry)
	{
		isFirstEntry = FALSE;
		moveStat = 0;
		NtkGDI_LoadImage(&imgPlayer1,"images/figure/main/Attack3.bmp",0,0);
		NtkGDI_LoadImage(&imgPlayer2,"images/figure/main/Attack4.bmp",0,0);
	}
	if(coverStat == 0)
	{
		NtkGDI_PutImageEx(&imgPlayer1,
			Game_Global_Player.x - MOVE_IMG_OFFSET_X*GAME_PLAYER_ZOOM - 65, Game_Global_Player.y - MOVE_IMG_OFFSET_Y*GAME_PLAYER_ZOOM -35, 162*GAME_PLAYER_ZOOM, imgPlayer1.height*GAME_PLAYER_ZOOM,
			moveStat*162,0,162,imgPlayer1.height,
			FALSE, RGB(255,0,255), SRCCOPY
			);
	}
	else
	{
		NtkGDI_PutImageEx(&imgPlayer2,
			Game_Global_Player.x - MOVE_IMG_OFFSET_X*GAME_PLAYER_ZOOM - 65, Game_Global_Player.y - MOVE_IMG_OFFSET_Y*GAME_PLAYER_ZOOM -35, 162*GAME_PLAYER_ZOOM, imgPlayer2.height*GAME_PLAYER_ZOOM,
			moveStat*162,0,162,imgPlayer2.height,
			FALSE, RGB(255,0,255), SRCCOPY
			);
	}

	if(moveStat < MOVE_MAX_STAT)
	{
		moveStat++;
	}
	else
	{
		if(coverStat == 0)
		{
			coverStat = 1;
		}
		else
		{
			coverStat = 0;
		}
		moveStat = 0;
	}
}
#endif