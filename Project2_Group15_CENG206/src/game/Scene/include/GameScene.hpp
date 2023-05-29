#ifndef _GAMESCENE_H_
#define _GAMESCENE_H_

#include "../include/AScene.h"
#include "../../Entity/include/Player.hpp"
#include "../../Entity/include/Enemy.hpp"
#include <wx/sound.h>


enum E_KEY
{
	KEY_W = 87,
	KEY_S = 83,
	KEY_A = 65,
	KEY_D = 68,
	KEY_UP = 38,
	KEY_DOWN = 40,
	KEY_LEFT = 37,
	KEY_RIGHT = 39,
	KEY_R = 82
};


class GameScene : public AScene
{
	public:
		GameScene(Game* game, wxFrame& frame);
		~GameScene();


		void Render();
		void Hide();
		void StartGame(const char* player1_name, const char* player2_name, int enemy_count = 2);
		void Clear();

		void onKeyDown(wxKeyEvent& event);
		void onKeyUp(wxKeyEvent& event);
		void onUpdate(wxIdleEvent& event);


		Player** get_players();
		std::vector<Enemy*>& get_enemies();
		bool IsGameStarted();

		inline void FixMovement();
		
		void OnTimer(wxTimerEvent& event);


	private:
		wxFrame* frame;
		wxBoxSizer* sizer;
		wxStaticText* text;
		wxSound* sound;

		bool isGameStarted;
		Player* players[2];
		std::vector<Enemy*> enemies;




};


#endif

