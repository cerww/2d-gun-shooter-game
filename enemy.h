#pragma once
#include "entity.h"
#include "gun.h"

class player;

class enemy :
	public entity
{
public:
	static constexpr int radius = 30;
	enemy(glm::vec4 t_pos, texture t_text, gun t_gun);
	bullet shoot() {
		return m_gun.shoot().setAngle(angle).setPos(40.0f*glm::vec2{ math::cos(angle),math::sin(angle)} + getPos());//30+9+1, 30 is player,9 is bullet, 1 is buffer };
	}
	math::radians angle;
	virtual void update(player&) = 0;
	void lowerCD() { m_gun.lowerCD(); };
protected:
	gun m_gun;
	int m_moveingBuffer = 0;
	friend class enemyAIEngine;
};

