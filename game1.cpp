#include "game1.h"
#include "mainGameScreen.h"
#include "cw/things.h"

game1::game1(mainGameScreen & t_gamey):
	gameScreen(t_gamey) {
	bullety = std::make_unique<bulletEngine>(parent);
	AIEngine = std::make_unique<easyAIEngine>(parent);
}

std::pair<std::vector<int>, std::vector<int>> game1::update(){
	std::pair<std::vector<int>, std::vector<int>> retVal;
	if (parent.getWindow().getMouseButton(mouseB::LEFT))
		parent.bullets.push_back(parent.getPlayer().shoot());
	parent.getPlayer().lowerCD();
	movePlayer();
	bullety->doStuff();
	AIEngine->doStuff();

	return retVal;
}

void game1::draw(){
	parent.getPlayer().draw(parent.renderer);
	for (const auto& Bullet : parent.bullets) {
		parent.renderer.draw({ Bullet.pos.x - bullet::radius,Bullet.pos.y - bullet::radius,bullet::radius * 2,bullet::radius * 2 }, fullPicUV, bullet::bulletText.id, {255,255,255,255},2.0f);
	}for (auto& enemy : parent.enemies) {
		enemy->draw(parent.renderer);
	}for (auto& i : parent.spawners) {
		i.draw(parent.renderer);
	}
}

void game1::movePlayer(){
	bool playerMoved = false;
	if (parent.getWindow().getKey(Keys::W)) {
		parent.getPlayer().move({ 0, 2.5 }, parent.worldBorders);
		playerMoved = true;
	}if (parent.getWindow().getKey(Keys::A)) {
		parent.getPlayer().move({ -2.5,0 }, parent.worldBorders);
		playerMoved = true;
	}if (parent.getWindow().getKey(Keys::S)) {
		parent.getPlayer().move({ 0,-2.5 }, parent.worldBorders);
		playerMoved = true;
	}if (parent.getWindow().getKey(Keys::D)) {
		parent.getPlayer().move({ 2.5,0 }, parent.worldBorders);
		playerMoved = true;
	}if(playerMoved)
		parent.mainCam.setPos(parent.getPlayer().getPos());
}


