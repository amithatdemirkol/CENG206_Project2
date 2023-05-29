#ifndef _ASCENE_H_
#define _ASCENE_H_

#include "IScene.h"
#include <wx/wx.h>

class Game;

enum E_SCENE : unsigned int
{
	SCENE_MENU = 0,
	SCENE_GAME,
};


class AScene : public IScene
{	
	friend class Game;
	public:

		virtual ~AScene() { };

		const E_SCENE scene_id;
	
	protected:

		Game* game;
		wxFrame* main_frame;
		wxPanel* m_panel;
		

		AScene(Game* game, wxFrame& frame, E_SCENE scene_id) : game(game), scene_id(scene_id) {
			this->main_frame = &frame;
		}

};

#include "../../Window/include/Game.hpp"


#endif