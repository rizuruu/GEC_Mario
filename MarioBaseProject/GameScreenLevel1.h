#pragma once

#include "Commons.h"
#include "GameScreen.h"
#include "LevelMap.h"

#include "CharacterKoopa.h"
#include "CharacterCoin.h"
#include "CharacterGoomba.h"
#include "CharacterPeach.h"

#include <Windows.h>
#include <vector>

class Texture2D;
class Character;
class PowBlock;

class GameScreenLevel1 : GameScreen
{
public:
	GameScreenLevel1(SDL_Renderer* renderer);
	~GameScreenLevel1();

	void Render();
	void Update(float deltaTime, SDL_Event e);

	Character* characterMario;
	Character* characterLuigi;

	bool playersDead;

private:
	bool SetUpLevel();
	Texture2D* mBackgroundTexture;
	Texture2D* mLevelTexture;
	Texture2D* mTransparency;
	Texture2D* mBlackBackground;

	void SetLevelMap();
	LevelMap* mLevelMap;

	void WallWrapping(Character* character);

	HANDLE hConsole;
	int redFont, greenFont, pinkFont, whiteFont;

	// GAME OBJECTS
	CharacterPeach* characterPeach;
	void UpdatePeach(float deltaTime, SDL_Event e);
	void SpawnPeach(Vector2D position, FACING direction);

	void UpdateCoin(float deltaTime, SDL_Event e);
	void SpawnCoin(Vector2D position);
	vector<CharacterCoin*> mCoins;

	PowBlock* mPowBlock;
	bool hitPowBlock;
	float hitTimer;
	void UpdatePOWBlock();

	bool mScreenshake;
	float mScreenshakeTime;
	float mWobble;
	float mBackgroundYPos;
	void DoScreenShake();

	// ENEMIES
	void UpdateKoopas(float deltaTime, SDL_Event e);
	void SpawnKoopa(Vector2D position, FACING direction);
	vector<CharacterKoopa*> mEnemyKoopa;

	void UpdateGoombas(float deltaTime, SDL_Event e);
	void SpawnGoomba(Vector2D position, FACING direction);
	vector<CharacterGoomba*> mEnemyGoomba;

	float enemyTimer;
};