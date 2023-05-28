#ifndef _CONFIGDIALOG_H_
#define _CONFIGDIALOG_H_

#include "ADialog.hpp"

class MenuScene;

class ConfigDialog : public ADialog
{
	public:

		typedef void (MenuScene::*fn)();

		fn sub;
		MenuScene* menu_scene;
		
		ConfigDialog(wxWindow* parent, wxString title);
		ConfigDialog();
		~ConfigDialog();

		wxString getPlayerName1();
		wxString getPlayerName2();
		int getEnemyCount();

		void Show();
		void Hide();

		void onButtonClick(wxCommandEvent& event);
		void OnSlider(wxCommandEvent& event);


	private:
		wxTextCtrl* playerName1;
		wxTextCtrl* playerName2;
		wxSlider* enemySlider;
		wxStaticText* sliderLabel;


};

#include "../../Scene/include/MenuScene.hpp"

#endif

