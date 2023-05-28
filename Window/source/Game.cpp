#include "../include/Game.hpp"

Game::Game()
{

}

void Game::Render(wxPaintEvent& event)
{
	for (auto scene : scenes) {
		if(current_scene == scene.first)
			scene.second->Render();
	}
}

void Game::StartGame(const char* player1_name, const char* player2_name, int enemy_count)
{
	if (current_scene == SCENE_MENU)
	{
		current_scene = SCENE_GAME;
		game->StartGame(player1_name, player2_name, enemy_count);
	}
}

bool Game::OnInit() 
{
	current_scene = SCENE_MENU;

	wxSize size(1024, 768);

	frame = new wxFrame(nullptr, wxID_ANY, "Game", wxDefaultPosition, size, wxCAPTION | wxCLOSE_BOX);
	wxInitAllImageHandlers();
	
	MenuScene* menu = new MenuScene(this, *frame);

	game = new GameScene(this, *frame);
	scenes.insert(std::make_pair(menu->scene_id, menu));
	scenes.insert(std::make_pair(game->scene_id, game));
	
	frame->Center();
	frame->Show();
	frame->Bind(wxEVT_PAINT, &Game::Render, this);
	frame->Bind(wxEVT_CHAR_HOOK, &Game::OnKeyDown, this);
	frame->Bind(wxEVT_KEY_UP, &Game::OnKeyUp, this);
	frame->Bind(wxEVT_IDLE, &Game::OnIdle, this);

	return true;
}

void Game::OnIdle(wxIdleEvent& event)
{
	if (current_scene == SCENE_GAME) {
		GameScene* game_scene = (GameScene*)scenes[current_scene];
		if (game_scene->IsGameStarted())
		{
			game_scene->onUpdate(event);
			if (game_scene->get_enemies().size() == 0)
			{

				char buffer[256];
				if(((game_scene->get_players()[0])->get_score() > (game_scene->get_players()[1])->get_score()))
					sprintf_s(buffer, "%s wins", (game_scene->get_players()[0])->get_name());
				else if ((game_scene->get_players()[0])->get_score() < (game_scene->get_players()[1])->get_score())
					sprintf_s(buffer, "%s wins", (game_scene->get_players()[1])->get_name());
				else
					sprintf_s(buffer, "Draw!");
				wxMessageBox(buffer,"Message", wxOK | wxICON_INFORMATION);
				game_scene->Clear();
				auto tmp = scenes[current_scene];
				current_scene = SCENE_MENU;
				tmp->Hide();
				scenes[current_scene]->Render();
			}
		}
	}
	event.RequestMore();
}

void Game::OnKeyUp(wxKeyEvent& event)
{
	if (current_scene == SCENE_GAME)
		((GameScene*)scenes[current_scene])->onKeyUp(event);
}

void Game::OnKeyDown(wxKeyEvent& event)
{
	E_SCENE old_scene = current_scene;
	if (current_scene == SCENE_MENU) {
		((MenuScene*)scenes[current_scene])->ShowConfigDialog();
	}
	else if (current_scene == SCENE_GAME) 
		((GameScene*)scenes[current_scene])->onKeyDown(event);
	scenes[old_scene]->Hide();
	scenes[current_scene]->Render();
}



Game::~Game()
{
	for (auto scene : scenes)
		delete scene.second;
}

wxIMPLEMENT_APP(Game);
