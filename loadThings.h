#pragma once
#include "player.h"
#include "enemyShooter.h"
#include "mainMenuScreen.h"
#include "gun.h"
#include "shooterSpawner.h"


inline void loadEverything() {
	player::load();
	enemyShooter::load();
	mainMenuScreen::load();
	bullet::load();
	shooterSpawner::load();
}