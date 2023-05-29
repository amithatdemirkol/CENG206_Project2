#include "../include/MenuScene.hpp"

MenuScene::MenuScene(Game* game, wxFrame& frame) : AScene(game, frame,SCENE_MENU), dialog(nullptr) {

    this->game = game;
    m_panel = new wxPanel(&frame, wxID_ANY, wxDefaultPosition,frame.GetSize());

    int textY = (frame.GetSize().y / 2) - 20 - (frame.GetFont().GetPixelSize().y / 2);

    wxStaticText *text = new wxStaticText(m_panel, wxID_ANY,"Press Any Key To Start", wxPoint(wxDefaultPosition.x, textY), frame.GetSize(), wxALIGN_CENTRE_HORIZONTAL);
    text->SetForegroundColour(wxColor(255, 255, 255, 255));
    text->SetCanFocus(false);
    dialog = new ConfigDialog(&frame, "Settings");
    dialog->menu_scene = this;   

    m_panel->SetBackgroundColour(wxColor(0,0,0,255));
    m_panel->Hide();

}

void MenuScene::Render()
{
	m_panel->Show();
}

void MenuScene::Hide()
{
	m_panel->Hide();
}

void MenuScene::ShowConfigDialog()
{
	dialog->Show();
}

void MenuScene::OnDialogConfirm()
{
    dialog_player_name1 = dialog->getPlayerName1();
    dialog_player_name2 = dialog->getPlayerName2();
    dialog_enemy_count = dialog->getEnemyCount();
    game->StartGame(dialog_player_name1, dialog_player_name2, dialog_enemy_count);
}

MenuScene::~MenuScene()
{
    
}

