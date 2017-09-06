#pragma once
#include "gameScreenScreen.h"
#include "world.h"
#include "constants.h"
#include "bulletEngine.h"
#include "enemyAIEngine.h"

class game1 :
	public gameScreen
{
public:
	static constexpr int screenIndex = 0;
	game1(mainGameScreen&);
	std::pair<std::vector<int>, std::vector<int>> update()override final;
	void draw() override final;
private:
	std::unique_ptr<bulletEngine> bullety;
	std::unique_ptr<enemyAIEngineBase> AIEngine;
	void movePlayer();
};

