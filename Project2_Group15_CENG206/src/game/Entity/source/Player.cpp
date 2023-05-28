#include "../include/Player.hpp"

Player::Player(wxPanel* panel, const char* image_path, const char* player_name, Vector2 position) : AEntity(panel, image_path, position)
{
	x = 0;
	y = 0;
	updown_flag = 0;
	leftright_flag = 0;
	score = 0;
	this->player_name = player_name;
}

E_UPDOWN_FLAG Player::get_updown_flag()
{
	return (E_UPDOWN_FLAG)updown_flag;
}

void Player::set_updown_flag(int flag)
{
	updown_flag = flag;
}

E_LEFTRIGHT_FLAG Player::get_leftright_flag()
{
	return (E_LEFTRIGHT_FLAG)leftright_flag;
}

void Player::set_leftright_flag(int flag)
{
	leftright_flag = flag;
}

int Player::get_score() const
{
	return score;
}

void Player::set_score(int score)
{
	this->score = score;
}

void Player::set_name(std::string name)
{
	this->player_name = name;
}

const char* Player::get_name() const
{
	return player_name.c_str();
}

Player::~Player()
{
	if(this->image)
		this->image->Destroy();
}

