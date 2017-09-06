#pragma once
#include "gun.h"
#include <glm/glm.hpp>
#include <memory>
#include "player.h"
#include "enemy.h"
#include "shooterSpawner.h"


struct world {
	glm::vec4 worldBorders = { -500,-500,1000,1000 };
	std::vector<std::unique_ptr<enemy>> enemies;
	std::vector<bullet> bullets;
	std::vector<shooterSpawner> spawners;
};

