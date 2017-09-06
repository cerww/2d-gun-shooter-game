#include "gun.h"

texture bullet::bulletText = {};

bullet gun::shoot() {
	if (currentBullets&&!currentCD) {
		--currentBullets;
		currentCD = bulletFireRate;
		return { dmg,bulletSpeed,bulletLife };
	}return { 0,0,0 };//bullet dies insta
}

bullet& bullet::setAngle(math::radians r) {
	angle = {cos(r),sin(r)};
	return *this;
}

bullet & bullet::setPos(glm::vec2 newPos){
	pos = newPos;
	return *this;
}

void bullet::move(){
	pos += glm::vec2{ angle.x*speed,angle.y*speed };
}

gunHolder::gunHolder(){
	m_guns.push_back(gun(0,0,0,0,0,10000));
}

void bullet::load() {
	bulletText = imgLoader::loadPNG("bullet.png");
}