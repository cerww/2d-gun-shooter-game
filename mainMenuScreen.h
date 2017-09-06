#pragma once
#include "rawrGameScreen.h"
#include "cw/button.h"
#include "cw/UIRenderer.h"
using namespace std::string_literals;

class mainMenuScreen :public rawrGameScreen {
public:
	mainMenuScreen(rawrGamey& g,UIRenderer& t_UIRenderer) :		
		m_startGameButton(
			glm::vec4{ 200,260,200,80 },
			std::array<texture,3>{ buttonText,buttonText,buttonText },
			std::array<Color, 3>{ { { 255, 255, 255, 255 }, { 255,255,255,255 }, { 255,255,255,255 } }},
			[this]() {m_clicked = 1; }, ""s) ,
		rawrGameScreen(g),
		m_UIRenderer(t_UIRenderer){
	}
	std::pair<std::vector<int>, std::vector<int>> update()override final;
	void draw() override final;
	static void load();
private:
	button m_startGameButton;
	static texture buttonText;
	UIRenderer& m_UIRenderer;
	size_t m_clicked = 0;
};