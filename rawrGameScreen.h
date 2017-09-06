#pragma once
#include "cw/iGameScreen.h"
#include "constants.h"

class rawrGamey;

class rawrGameScreen:public iGameScreen {
public:
	rawrGameScreen(rawrGamey& t_game) :m_game(t_game) {};
protected:
	rawrGamey& m_game;
};
