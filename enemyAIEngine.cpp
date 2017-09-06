#include "enemyAIEngine.h"
#include "mainGameScreen.h"
#include "cw/things.h"
#include "enemyShooter.h"
#include "shooterSpawner.h"



enemyAIEngineBase::enemyAIEngineBase(mainGameScreen& t_parent):
	parent(t_parent){

}

easyAIEngine::easyAIEngine(mainGameScreen&t):enemyAIEngineBase(t){
}

void easyAIEngine::doStuff(){
	//walk toward player,
	//if player is withing 800px, shoot
	for (auto& spawner : parent.spawners) {
		if (!spawner.cd) {
			parent.enemies.emplace_back(std::make_unique<enemyShooter>(glm::vec4{ spawner.getPos().x + 90,spawner.getPos().y + 90,30.0f,30.0f }));
		}else{
			--spawner.cd;
		}
	}
	for (auto& Enemy : parent.enemies) {
		Enemy->lowerCD();
		Enemy->update(parent.getPlayer());
		if (glm::distance(parent.getPlayer().getPos(), Enemy->getPos()) < 800) {
			parent.bullets.push_back(Enemy->shoot());
		}else {
			Enemy->move(unitVec(Enemy->angle)*5.0f, parent.worldBorders);
		}
	}
}

normalAIEngine::normalAIEngine(mainGameScreen&t ) :enemyAIEngineBase(t){
}

void normalAIEngine::doStuff(){

}

hardAIEngine::hardAIEngine(mainGameScreen& t) :enemyAIEngineBase(t){
}

void hardAIEngine::doStuff(){

}
