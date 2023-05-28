#include "../include/Enemy.hpp"
#include <time.h> 
#include <wx/sound.h>

Enemy::Enemy(wxPanel* panel, const char* image_path, Vector2 position) : AEntity(panel, image_path, position)
{
	srand(time(NULL));

	this->image->Hide();
	this->size = image->GetSize();
	this->timeToDelete = 0;
	isVisible = false;

	setTarget();
}



void Enemy::setTarget()
{
	this->target = Vector2(rand() % (1024 - 100) + 100, rand() % (768 - 100) + 100);
}

void Enemy::Move()
{
	if (this->timeToDelete > 0)
		return;

	int x = 0;
	int y = 0;

	if(this->position.x < this->target.x)
		x = 1;
	else if (this->position.x > this->target.x)
		x = -1;
	if(this->position.y < this->target.y)
		y = 1;
	else if (this->position.y > this->target.y)
		y = -1;

	SetPosition(Vector2(position.x + x, position.y + y));

	if (position.x >= target.x - 50 && position.x <= target.x + 50 && position.y >= target.y - 50 && position.y < target.y + 50)
		setTarget();
}

bool Enemy::IsVisible()
{
	return this->isVisible;
}

void Enemy::SetVisible(bool visible)
{
	this->isVisible = visible;
	if (visible) {
		this->image->Show();
		this->image->SetBackgroundColour(wxColor(238, 238, 0, 255));
	}
	else
		this->image->Hide();
}

void Enemy::SetTimeToDelete(wxMilliClock_t time)
{
	this->timeToDelete = time;
}

wxMilliClock_t Enemy::GetTimeToDelete()
{
	return this->timeToDelete;
}

Enemy::~Enemy()
{
	if(this->image)
		this->image->Destroy();
}
