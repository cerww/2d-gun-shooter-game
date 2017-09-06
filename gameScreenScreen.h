#pragma once
#include "cw/iGameScreen.h"
class mainGameScreen;

class gameScreen :public iGameScreen{
public:
	gameScreen(mainGameScreen& t_parent) :parent(t_parent){};
	//uint64_t flags = UPDATE_FLAG | DRAW_FLAG;
protected:
	mainGameScreen& parent;
};