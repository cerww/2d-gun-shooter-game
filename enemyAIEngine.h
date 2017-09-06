#pragma once
#include "player.h"
#include "gun.h"
#include "enemy.h"
class mainGameScreen;

class enemyAIEngineBase
{
public:
	enemyAIEngineBase(mainGameScreen&);
	virtual void doStuff() = 0;
protected:
	mainGameScreen& parent;
};

//easy normal hard
class easyAIEngine :public enemyAIEngineBase {
public:
	easyAIEngine(mainGameScreen&);
	void doStuff();
};


class normalAIEngine :public enemyAIEngineBase {
public:
	normalAIEngine(mainGameScreen&);
	void doStuff();
};

class hardAIEngine :public enemyAIEngineBase {
public:
	hardAIEngine(mainGameScreen&);
	void doStuff();
};