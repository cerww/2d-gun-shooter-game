#pragma once
#include "player.h"
#include "gun.h"
#include "entity.h"
#include "enemy.h"
#include <array>
class mainGameScreen;

class bulletEngine{
public:
	bulletEngine(mainGameScreen& t_parent) :m_parent(t_parent){};
	void doStuff();
private:
	mainGameScreen& m_parent;
	//std::array<std::array<std::vector<entity*>, 50>, 50> partitionThings() {}
	//too much space D:
	void bulletCollision();
	int m_ticks = 0;
};

