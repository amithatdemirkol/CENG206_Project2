#ifndef _MENUSCENE_H_
#define _MENUSCENE_H_

#include "AScene.h"
#include "../../Dialog/include/ConfigDialog.hpp"

class MenuScene : public AScene
{
	public:
		MenuScene(Game* game, wxFrame& frame);
		~MenuScene();

		void Render();
		void Hide();

		void ShowConfigDialog();
		void OnDialogConfirm();

		wxString dialog_player_name1;
		wxString dialog_player_name2;
		int dialog_enemy_count;

	private:
		Game* game;
		ConfigDialog* dialog;
};


#endif



