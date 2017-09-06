#include <iostream>
#include "game.h"
#include <glm/common.hpp>
#include <glm/glm.hpp>

int main() {
	glfwInit();
	rawrGamey g;
	g.run();
	glfwTerminate();
}

