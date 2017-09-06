#pragma once
#include "rawrGameScreen.h"
#include "player.h"
#include "gameScreenScreen.h"
#include "cw/UIRenderer.h"
#include <array>
#include "world.h"
#include "cw\app.h"



class mainGameScreen :
	public rawrGameScreen,
	public world {
public:
	mainGameScreen(rawrGamey& t_game, camera2D&, drawRenderer&, UIRenderer&);
	std::pair<std::vector<int>, std::vector<int>> update()override final;
	void loadWorld(const std::string&);
	void draw() override final;
	camera2D& mainCam;
	drawRenderer& renderer;
	UIRenderer& UIrenderer;
	player& getPlayer() { return m_player; }
	const player& getPlayer()const { return m_player; }
	const app& getWindow()const;// { return m_game.window; };
	app& getWindow();// { return m_game.window; };
	std::vector<bullet> bullets;
private:
	player m_player;
	std::array<std::unique_ptr<gameScreen>, 3> m_screens = {};
	void addScreen(uint64_t);
};

