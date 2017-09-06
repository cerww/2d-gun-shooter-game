#include "mainMenuScreen.h"
#include "game.h"
#include "constants.h"

texture mainMenuScreen::buttonText = {};

std::pair<std::vector<int>, std::vector<int>> mainMenuScreen::update(){
	m_startGameButton.update(m_game.window.getMousePos(),m_game.window.getMouseButton(mouseB::LEFT));
	if (m_clicked) return { {0},{1} };
	return { {},{} };
}

void mainMenuScreen::draw(){
	m_startGameButton.draw(m_UIRenderer);
}

void mainMenuScreen::load(){
	buttonText = imgLoader::loadPNG("startGame.png");
}
