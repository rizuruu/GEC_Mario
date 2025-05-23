#pragma once

#ifndef _TEXTURE2D_H
#define _TEXTURE2D_H

#include <SDL_mixer.h>
#include <iostream>

#include "Texture2D.h"
#include "LevelMap.h"

class Character
{
public:
	Character(SDL_Renderer* renderer, string imagePath, Vector2D startPosition, LevelMap* map);
	~Character();

	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);

	bool LoadAudio();
	Mix_Chunk* jumpSound;

	void SetPosition(Vector2D newPosition);
	Vector2D GetPosition();

	FACING mFacingDirection;
	bool mMovingLeft;
	bool mMovingRight;
	float mMovementSpeedRight;
	float mMovementSpeedLeft;

	float GetCollisionRadius();
	Rect2D GetCollisionBox() { return Rect2D(mPosition.x, mPosition.y, mTexture->GetWidth(), mTexture->GetHeight()); }

	bool IsJumping();
	void CancelJump();

	void SetAlive(bool isAlive);
	bool GetAlive() { return alive; }

private:
	LevelMap* mCurrentLevelMap;

protected:
	SDL_Renderer* mRenderer;
	Vector2D mPosition;
	Texture2D* mTexture;

	virtual void MoveLeft(float deltaTime);
	virtual void MoveRight(float deltaTime);
	virtual void AddGravity(float deltaTime);
	virtual void Jump();

	bool mJumping;
	bool mCanJump;
	float mJumpForce;

	float mCollisionRadius;

	bool alive = true;
};

#endif //_TEXTURE2D_H