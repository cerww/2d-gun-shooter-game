#include "shooterSpawner.h"

texture shooterSpawner::kText = {};

shooterSpawner::shooterSpawner(glm::vec2 t_pos):m_pos(t_pos){

}

void shooterSpawner::load() {
	kText = imgLoader::loadPNG("enemySpawner.png");
}

void shooterSpawner::draw(drawRenderer& renderer){
	renderer.draw({ m_pos.x - radius / 2.0,m_pos.y - radius / 2.0,radius * 2,radius * 2 }, fullPicUV, kText.id, { 255,255,255,255 }, 1.0f);
}
