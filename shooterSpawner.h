#pragma once
#include "enemy.h"

class shooterSpawner
{
public:
	shooterSpawner(glm::vec2 t_pos);
	int cd = 600;
	static void load();
	static constexpr double radius = 50.0;
	void draw(drawRenderer&);
	glm::vec2 getPos()const { return m_pos; }
private:
	static texture kText;
	glm::vec2 m_pos;
};

