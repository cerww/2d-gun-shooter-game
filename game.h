#pragma once
#include <vector>
#include "cw\app.h"
#include "cw/camera2D.h"
#include "cw/iGameScreen.h"
#include "cw/drawableObj.h"
#include "rawrGameScreen.h"
#include "cw/UIRenderer.h"
#include "mainMenuScreen.h"
#include "loadThings.h"

class rawrGamey {
public:
	rawrGamey() {
		glfwMakeContextCurrent(window.getWindowPtr());
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
		if (glewInit() != GLEW_OK) {
			std::cout << "glew failed to init" << std::endl;
			glfwTerminate();
		}
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		loadEverything();
		m_mainCam.update();
		m_screens[0] = std::make_unique<mainMenuScreen>(*this,m_UIrenderer);
	}
	app window = app(glfwCreateWindow(600, 600, "", NULL, NULL));
	void run();
private:
	camera2D m_mainCam = camera2D(600, 600);
	std::array<std::unique_ptr<rawrGameScreen>,3> m_screens;
	drawRenderer m_renderer;
	UIRenderer m_UIrenderer = UIRenderer({600,600});
	void m_addScreen(int);
};
