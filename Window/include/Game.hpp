#ifndef _GAME_H_
#define _GAME_H_

#include "../../Scene/include/MenuScene.hpp"
#include "../../Scene/include/GameScene.hpp"
#include <wx/wx.h>
#include <map>
#include <functional>

class AScene;
class GameScene;

class Game : public wxApp
{
	private:

		wxFrame* frame;
		wxPanel* panel;
		GameScene* game;
		E_SCENE current_scene;

		std::map<E_SCENE, AScene*> scenes;


		void Render(wxPaintEvent& event);

		void OnKeyDown(wxKeyEvent& event);
		void OnKeyUp(wxKeyEvent& event);
		void OnIdle(wxIdleEvent& event);
		

	public:
		Game();
		~Game();

		void StartGame(const char* player1_name, const char* player2_name, int enemy_count);


		bool OnInit();

};


#endif


