#include "enemyShooter.h"
#include "player.h"

gun enemyShooter::s_Gun = gun( 15,100,100,600,8,10 );
texture enemyShooter::s_Text = {};

void enemyShooter::load() {
	s_Text = imgLoader::loadPNG("enemyShooter.png");//everything should be a circle!
}

enemyShooter::enemyShooter(glm::vec4 t_pos) :enemy(t_pos, s_Text, s_Gun){}

void enemyShooter::update(player& thePlayer) {	
	angle.angle = glm::atan((thePlayer.getPos() - getPos()).x, (thePlayer.getPos() - getPos()).y);
}

void enemyShooter::draw(drawRenderer & renderer){
	renderer.draw(m_dims, fullPicUV, s_Text.id, { 255,255,255,255 }, 1.0, angle);
}