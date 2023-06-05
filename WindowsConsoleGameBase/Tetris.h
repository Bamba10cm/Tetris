#pragma once
#include "Engine.h"
#include "GameField.h"
#include "Figure.h"
#include "IBlock.h"

class Tetris : public Engine
{
private:
	GameField m_GameField;
	const size_t m_Width = 14;
	const size_t m_Height = 26;
	Figure* m_Figure;
	bool m_End = false;

public:
	Tetris();
	
	virtual bool end() const;
	virtual void on_button_press(const int button);
	virtual void update(const int dt);
	virtual void render(PaintDevice& paintDevice);

	
	
};

