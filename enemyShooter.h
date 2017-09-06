#pragma once
#include "enemy.h"
class enemyShooter :
	public enemy
{
public:
	enemyShooter(glm::vec4);
	static void load();
	void update(player&);
	void draw(drawRenderer&);
private:
	static gun s_Gun;
	static texture s_Text;
};

