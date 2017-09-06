#include "mainGameScreen.h"
#include "game.h"
#include "game1.h"

mainGameScreen::mainGameScreen(rawrGamey & t_game, camera2D& t_mainCam, drawRenderer& t_renderer,UIRenderer& t_uiRenderer) :
	rawrGameScreen(t_game),
	mainCam(t_mainCam),
	renderer(t_renderer),
	UIrenderer(t_uiRenderer){
	m_screens[game1Index] = std::make_unique<game1>(*this);
	spawners.emplace_back(glm::vec2(80,80));
}

std::pair<std::vector<int>, std::vector<int>> mainGameScreen::update(){
	m_player.updateAngle(mainCam.scrnToWorld(m_game.window.getMousePos()));
	for (auto& i : m_screens) {
		if (i) {
			auto[toKill, toAdd] = i->update();
			for (auto& index : toKill) {
				m_screens[index] = nullptr;
			}for (auto& index : toAdd)
				addScreen(index);
		}
	}return std::pair<std::vector<int>, std::vector<int>>();
}

void mainGameScreen::loadWorld(const std::string& data){
	size_t currentIndex = 0;
}

void mainGameScreen::draw(){
	for (auto& i : m_screens) 
		if (i)
			i->draw();
}

const app & mainGameScreen::getWindow() const{
	return m_game.window;
}

app & mainGameScreen::getWindow() {
	return m_game.window;
}

void mainGameScreen::addScreen(uint64_t index){
	if (m_screens[index]) return;
	switch (index)	{
	case game1Index:
		m_screens[index] = std::make_unique<game1>(*this);
		break;
	case pauseMenuIndex:
		//m_screens[index] = std::make_unique<
		break;

	default:
		break;
	}
}

