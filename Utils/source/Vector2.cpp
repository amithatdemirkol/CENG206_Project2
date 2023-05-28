#include "../include/Vector2.hpp"

Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(int x, int y)
{
	this->x = x;
	this->y = y;
}

Vector2 Vector2::Up()
{
	return Vector2(x, y - 1);
}

Vector2 Vector2::Down()
{
	return Vector2(x, y + 1);
}

Vector2 Vector2::Left()
{
	return Vector2(x - 1, y);
}

Vector2 Vector2::Right()
{
	return Vector2(x + 1, y);
}

Vector2& Vector2::operator=(Vector2& rhs)
{
	x = rhs.x;
	y = rhs.y;
	return *this;
}

Vector2& Vector2::operator=(Vector2 rhs)
{
	x = rhs.x;
	y = rhs.y;
	return *this;
}

Vector2& Vector2::operator=(wxSize& rhs)
{
	x = rhs.GetWidth();
	y = rhs.GetHeight();
	return *this;
}

Vector2& Vector2::operator=(wxSize rhs)
{
	x = rhs.GetWidth();
	y = rhs.GetHeight();
	return *this;
}

bool Vector2::operator==(Vector2& rhs)
{
	return (x == rhs.x && y == rhs.y);
}

Vector2::~Vector2()
{

}