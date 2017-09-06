#pragma once
#include "cw\drawableObj.h"
#include "entity.h"
#include <vector>
#include "cw/mathStuff.h"
#include "gun.h"

class player :public entity {
public:
	static void load();
	static constexpr int radius = 30;
	player() :entity({ 0,0,60,60}, kText) {
		m_hp = 300;
		m_guns.setMaxSize(5);
		addGun(gun( 100,100,100,2,100,10 ));
		m_guns.setGun(1);
	}bullet shoot();
	void updateAngle(glm::vec2);
	void addGun(gun);
	void dropGun();
	math::radians getAngle()const { return m_angle; }
	void draw(drawRenderer&);
	void lowerCD() { m_guns.getGun().lowerCD(); };
private:
	math::radians m_angle = {};
	gunHolder m_guns;
	static texture kText;
};