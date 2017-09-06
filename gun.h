#pragma once
#include <vector>
#include <glm/glm.hpp>
#include <glm/common.hpp>
#include "cw/mathStuff.h"
#include <string_view>
#include "cw/imgLoader.h"

struct bullet;

struct gun {
	gun() = default;
	gun(int t_dmg, int t_currentBullets, int t_maxBullets, float t_bulletSpeed, int t_bulletLife, int t_bulletFireRate) :
	dmg(t_dmg),
	currentBullets(t_currentBullets),
	maxBullets(t_maxBullets),
	bulletSpeed(t_bulletSpeed),
	bulletLife(t_bulletLife),
	bulletFireRate(t_bulletFireRate){}
	int dmg;
	int currentBullets;
	int maxBullets;
	float bulletSpeed;
	int bulletLife;
	int bulletFireRate;
	bullet shoot();//returns bullet but angle is 0, change angle after
	void refill() { currentBullets = maxBullets; }
	int currentCD = 0;
	void lowerCD() { if (currentCD)--currentCD; }
private:
};

struct bullet {
	static texture bulletText;
	static void load();
	static constexpr int radius = 9;
	int dmg;
	float speed;
	int life;
	glm::vec2 angle;
	glm::vec2 pos;
	bullet& setAngle(math::radians t_angle);
	bullet& setPos(glm::vec2 newPos);
	void move();
};

class gunHolder{
public:
	gunHolder();
	size_t getMaxSize()const { return m_maxSize; };
	void setMaxSize(size_t n) { m_maxSize = n; };
	gun& operator[](size_t n) { return m_guns[n]; };
	const gun& operator[](size_t n) const { return m_guns[n]; };
	bool addGun(gun g) {
		if (m_guns.size() < m_maxSize) {
			m_guns.push_back(std::move(g));
			return true;
		}return false;
	};

	const gun& getGun()const { return m_guns[m_currentGunIndex]; }
	gun& getGun() { return m_guns[m_currentGunIndex]; }
	void setGun(size_t n) { m_currentGunIndex = n; };
	size_t getGunIndex()const { return m_currentGunIndex; };
	void dropGun() {
		if (m_currentGunIndex == 0)return;
		m_guns.erase(m_guns.begin() + m_currentGunIndex);
		m_currentGunIndex = 0;
	};
private:
	size_t m_currentGunIndex = 0;//0 is no gun
	std::vector<gun> m_guns;
	size_t m_maxSize;
};




