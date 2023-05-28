#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "AEntity.hpp"


enum E_UPDOWN_FLAG
{
	UP = 1,
	DOWN = 2,
};

enum E_LEFTRIGHT_FLAG
{
	LEFT = 1,
	RIGHT = 2,
};

class Player : public AEntity
{
	public:
		Player(wxPanel* panel, const char* image_path, const char* player_name, Vector2 position);
		~Player();

		void set_updown_flag(int flag);
		void set_leftright_flag(int flag);
		E_UPDOWN_FLAG get_updown_flag();
		E_LEFTRIGHT_FLAG get_leftright_flag();
		int get_score() const;
		void set_score(int score);
		void set_name(std::string name);
		const char* get_name() const;

	private:
		int x;
		int y;
		int updown_flag;
		int leftright_flag;
		std::string player_name;
		int score;
};


#endif

