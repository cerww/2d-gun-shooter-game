#include "player.h"

texture player::kText = {};

void player::load(){
	kText = imgLoader::loadPNG("player.png");
}

bullet player::shoot(){
	return m_guns.getGun().shoot().setAngle(m_angle).setPos(getPos()+glm::vec2{ math::cos(m_angle) * 40,math::sin(m_angle) * 40 });//30+9+1, 30 is player,9 is bullet, 1 is buffer
}

void player::updateAngle(glm::vec2 mousePos) {
	const auto temp = mousePos - getPos();
	m_angle = math::atan2(temp.y, temp.x);
}

void player::addGun(gun t_newGun){
	m_guns.addGun(std::move(t_newGun));
}

void player::dropGun(){
	m_guns.dropGun();
}

void player::draw(drawRenderer & renderer){
	renderer.draw(m_dims - glm::vec4{15,15,0,0}, fullPicUV, kText.id, Color{ 255,255,255,255 }, 1, m_angle);
}
