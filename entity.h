#pragma once
#include "cw/drawableObj.h"
#include "cw/texture.h"
#include <glm/common.hpp>

enum DeadOrNot {dead, notDead };

class entity: public drawableObj{
public:
	entity(glm::vec4 t_pos,texture t_text) :drawableObj(t_pos, t_text, { 255,255,255,255 }) {}
	void move(glm::vec2 t, const glm::vec4 b) {
		setPos(glm::clamp({ b.x,b.y }, { b.z + b.x,b.w + b.y }, getPos() + t));
	};
	glm::vec2 getPos()const { return { m_dims.x,m_dims.y }; };
	void setPos(glm::vec2 newPos) {
		m_dims.x = newPos.x;
		m_dims.y = newPos.y;
	}
	DeadOrNot loseHP(int c) {
		m_hp -= c;
		return m_hp <= 0? dead :notDead;
	}
	int getHP()const { return m_hp; };
	bool isDead()const {
		return m_hp <= 0;
	}
protected:
	int m_hp = 200;
};