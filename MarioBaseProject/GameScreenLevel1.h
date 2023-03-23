#pragma once
#include "Commons.h"
#include "GameScreen.h"

class Texture2D;
class GameScreenLevel1 : GameScreen 
{
private:
	Texture2D* m_background_texture;
public:
	GameScreenLevel1(SDL_Renderer* renderer);
	~GameScreenLevel1();

	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;
private:
	bool SetUpLevel();
};

