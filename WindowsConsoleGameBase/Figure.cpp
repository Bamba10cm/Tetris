#include "Figure.h"

Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

Figure::Figure(Point position)
{
	this->m_Position = position;
}

void Figure::update(double dt)
{
	m_TimeFromLastUpdatec += dt;
	if (m_TimeFromLastUpdatec > m_TimeForUpdate) {
		m_TimeFromLastUpdatec = 0;
		++m_Position.y;
	}
	

}

void Figure::render(PaintDevice& paintDevice)
{
	for (const Point& point : m_Body[m_CurrentRotate])
	{
		Vector2 v(point.x + m_Position.x, point.y + m_Position.y);
		paintDevice.set_char(v, 0x25D8);
	}

}

void Figure::move_right()
{
	++m_Position.x;
}

void Figure::move_left()
{
	--m_Position.x;
}

const vector<Point>& Figure::get_body() const
{
	return m_Body[m_CurrentRotate];
}

Point Figure::get_position() const
{
	return m_Position;
}

void Figure::set_position(Point position)
{
	this->m_Position = position;
}

void Figure::backup()
{
	m_CurrentRotateBackup = m_CurrentRotate;
	m_PositionBackup = m_Position;
}

void Figure::restore()
{
	m_CurrentRotate = m_CurrentRotateBackup;
	m_Position = m_PositionBackup;
}

void Figure::boost()
{
	m_TimeForUpdate = 80;
}

void Figure::rotate()
{
	++m_CurrentRotate;
	if (m_CurrentRotate >= m_Body.size())
	{
		m_CurrentRotate = 0;
	}
}




