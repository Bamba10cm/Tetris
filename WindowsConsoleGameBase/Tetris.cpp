#include "Tetris.h"

Tetris::Tetris()
{
	paint_device().resize(Size(m_Width + 6, m_Height));
	m_GameField.resize(m_Width, m_Height);
	m_Figure = new Figure(Point(0,0));
	m_Figure = new IBlock(Point(5, 1));
	track_key(VK_LEFT);
	track_key(VK_RIGHT);
	track_key(VK_DOWN);
	track_key(VK_SPACE);
}

bool Tetris::end() const
{
	return m_End;
}

void Tetris::on_button_press(const int button)
{
	m_Figure->backup();
	switch (button)
	{
	case VK_LEFT:
		m_Figure->move_left();
		break;
	case VK_RIGHT:
		m_Figure->move_right();
		break;
	case VK_DOWN:
		m_Figure->boost();
		break;
	case VK_SPACE:
		m_Figure->rotate();
		break;
	default:
		break;
	}
	if (m_GameField.has_collision(*m_Figure))
		m_Figure->restore();

}

void Tetris::update(const int dt)
{
	m_Figure->backup();
	m_Figure->update(dt);
	if (m_GameField.has_collision(*m_Figure))
	{
		m_Figure->restore();
		m_GameField.merge(*m_Figure);
		m_Figure = new IBlock(Point(5, 1));
		if (m_GameField.has_collision(*m_Figure))
			m_End = true;

	}


}

void Tetris::render(PaintDevice& paintDevice)
{

	m_GameField.render(paintDevice);
	m_Figure->render(paintDevice);
}

//bool Tetris::has_collision(const Figure& figure)
//{
//	Point position = figure.get_position();
//	for (const Point& point : figure.get_body()) {
//		if (point.x + position.x < 1 || point.x + position.x > m_Width - 2)
//			return true;
//		if (point.y + position.y < 1 || point.y + position.y > m_Height - 2)
//			return true;
//	}
//	return false;
//}
