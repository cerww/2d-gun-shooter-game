#include "game.h"
#include "constants.h"
#include "mainGameScreen.h"

void rawrGamey::run() {


	glClearColor(1,1,1,1);
	while (!glfwWindowShouldClose(window.getWindowPtr())) {
		window.update();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//for (auto& screen : m_screens) {
		for (size_t i = 0; i < m_screens.size();++i){
			if (m_screens[i]) {
				auto[toKill, toAdd] = m_screens[i]->update();
				for (int screenNum : toAdd)
					m_addScreen(screenNum);
				for (auto n : toKill)
					m_screens[n] = nullptr;
				//if n==i then m_screens[i] == nullptr
				if (m_screens[i])
					m_screens[i]->draw();
			}
		}
		m_mainCam.update();
		m_renderer.render(m_mainCam);
		m_UIrenderer.renderUI();
		window.wait();
	}
}

void rawrGamey::m_addScreen(int screenNumber){
	if (m_screens[screenNumber]) return;
	switch (screenNumber){
	case mainGameIndex:
		m_screens[mainGameIndex] = std::make_unique<mainGameScreen>(*this,m_mainCam,m_renderer,m_UIrenderer);
		break;
	default:
		break;
	}
}
