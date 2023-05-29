#include "../include/GameScene.hpp"


GameScene::GameScene(Game* game, wxFrame& frame) : AScene(game, frame, SCENE_GAME)
{
	this->frame = &frame;
	isGameStarted = false;
	memset(players, 0, sizeof(players));

	m_panel = new wxPanel(&frame, wxID_ANY, wxDefaultPosition, frame.GetSize(), wxBORDER_NONE);
	m_panel->SetBackgroundColour(wxColor(0, 0, 0, 255));
	m_panel->SetWindowStyleFlag(wxFULL_REPAINT_ON_RESIZE);

	wxTimer* timer = new wxTimer();
	timer->Bind(wxEVT_TIMER, &GameScene::OnTimer, this);
	timer->Start(10);

	sound = new wxSound(_T("./assets/ghost.wav"), false);

	m_panel->Hide();

}


void GameScene::Render()
{
 	m_panel->Bind(wxEVT_KEY_DOWN, &GameScene::onKeyDown, this);
	m_panel->Show();
}

void GameScene::Hide()
{
	m_panel->Hide();
}

void GameScene::StartGame(const char* player1_name, const char* player2_name, int enemy_count)
{
	try
	{
		for (int i = 0; i < enemy_count; i++)
			enemies.push_back(new Enemy(m_panel, "enemy.png", Vector2(rand() % (frame->GetSize().x - 100) + 100, rand() % (frame->GetSize().y - 100) + 100)));
		memset(players, 0, sizeof(players));
		players[0] = new Player(m_panel, "player_1.png", player1_name, Vector2(0, 0));
		players[1] = new Player(m_panel, "player_2.png", player2_name, Vector2(frame->GetSize().x - 120, frame->GetSize().y - 130));
		isGameStarted = true;
	}
	catch (const std::exception& e)
	{
		wxMessageBox(e.what());
		exit(1);
	}
}

void GameScene::Clear()
{
	isGameStarted = false;
	for (auto enemy : enemies)
		delete enemy;
	for (auto player : players)
		delete player;
	enemies.clear();
	memset(players, 0, sizeof(players));
}

void GameScene::onUpdate(wxIdleEvent& event)
{
	static auto tick = wxGetLocalTimeMillis();

	
	if (tick < wxGetLocalTimeMillis())
	{
		Vector2 pos;

		for (auto player : players)
		{
			if (!player) {
				continue;
			}
			if (player->get_updown_flag() == E_UPDOWN_FLAG::DOWN || player->get_updown_flag() == E_UPDOWN_FLAG::UP) {
				pos = player->get_updown_flag() == E_UPDOWN_FLAG::DOWN ? player->GetPosition().Down() : player->GetPosition().Up();
				if (player->IsPositionInside(pos))
					player->SetPosition(pos);
			}
			if (player->get_leftright_flag() == E_LEFTRIGHT_FLAG::LEFT || player->get_leftright_flag() == E_LEFTRIGHT_FLAG::RIGHT) {
				pos = player->get_leftright_flag() == E_LEFTRIGHT_FLAG::LEFT ? player->GetPosition().Left() : player->GetPosition().Right();
				if (player->IsPositionInside(pos))
					player->SetPosition(pos);
			}
		}
		#ifdef WIN32
				FixMovement();
		#endif
		tick = wxGetLocalTimeMillis() + 10;
	}
}

inline void GameScene::FixMovement()
{
	if (GetForegroundWindow() == main_frame->GetHandle())
	{
		for (int i = 0; players[i] && i < 2; i++)
		{
			if (GetAsyncKeyState(KEY_A))
				players[0]->set_leftright_flag(E_LEFTRIGHT_FLAG::LEFT);
			else if (players[0]->get_leftright_flag() == E_LEFTRIGHT_FLAG::LEFT)
				players[0]->set_leftright_flag(0);
			if (GetAsyncKeyState(KEY_D))
				players[0]->set_leftright_flag(E_LEFTRIGHT_FLAG::RIGHT);
			else if (players[0]->get_leftright_flag() == E_LEFTRIGHT_FLAG::RIGHT)
				players[0]->set_leftright_flag(0);
			if(GetAsyncKeyState(KEY_LEFT))
				players[1]->set_leftright_flag(E_LEFTRIGHT_FLAG::LEFT);
			else if (players[1]->get_leftright_flag() == E_LEFTRIGHT_FLAG::LEFT)
				players[1]->set_leftright_flag(0);
			if (GetAsyncKeyState(KEY_RIGHT))
				players[1]->set_leftright_flag(E_LEFTRIGHT_FLAG::RIGHT);
			else if (players[1]->get_leftright_flag() == E_LEFTRIGHT_FLAG::RIGHT)
				players[1]->set_leftright_flag(0);
		}
	}
}

void GameScene::onKeyUp(wxKeyEvent& event)
{
	if (event.GetRawKeyCode() == KEY_W || event.GetRawKeyCode() == KEY_S)
		players[0]->set_updown_flag(0);
	if (event.GetRawKeyCode() == KEY_A || event.GetRawKeyCode() == KEY_D)
		players[0]->set_leftright_flag(0);
	if (event.GetRawKeyCode() == KEY_UP || event.GetRawKeyCode() == KEY_DOWN)
		players[1]->set_updown_flag(0);
	if (event.GetRawKeyCode() == KEY_LEFT || event.GetRawKeyCode() == KEY_RIGHT)
		players[1]->set_leftright_flag(0);
}

void GameScene::onKeyDown(wxKeyEvent& event)
{
	if (event.GetRawKeyCode() == KEY_W)
		players[0]->set_updown_flag(E_UPDOWN_FLAG::UP);
	else if (event.GetRawKeyCode() == KEY_S)
		players[0]->set_updown_flag(E_UPDOWN_FLAG::DOWN);
	if (event.GetRawKeyCode() == KEY_A)
		players[0]->set_leftright_flag(E_LEFTRIGHT_FLAG::LEFT);
	else if (event.GetRawKeyCode() == KEY_D)
		players[0]->set_leftright_flag(E_LEFTRIGHT_FLAG::RIGHT);
	if(event.GetRawKeyCode() == KEY_UP)
		players[1]->set_updown_flag(E_UPDOWN_FLAG::UP);
	else if (event.GetRawKeyCode() == KEY_DOWN)
		players[1]->set_updown_flag(E_UPDOWN_FLAG::DOWN);
	if (event.GetRawKeyCode() == KEY_LEFT)
		players[1]->set_leftright_flag(E_LEFTRIGHT_FLAG::LEFT);
	else if (event.GetRawKeyCode() == KEY_RIGHT)
		players[1]->set_leftright_flag(E_LEFTRIGHT_FLAG::RIGHT);

	else if (event.GetUnicodeKey() == wxChar('R')) {
		for(auto enemy : enemies)
			if(enemy->GetTimeToDelete() == 0)
				enemy->SetVisible(!enemy->IsVisible());
	}
}


void GameScene::OnTimer(wxTimerEvent& event)
{

	auto time = wxGetLocalTimeMillis();

	for (auto enemy : enemies)
	{
		auto posX = enemy->GetPosition().x;
		auto posY = enemy->GetPosition().y;
		auto sizeX = enemy->GetSize().x;
		auto sizeY = enemy->GetSize().y;
		enemy->Move();		

		for (auto player : players) {
			if (player && (player->GetPosition().x > posX || player->GetPosition().x + player->GetSize().x > posX) && player->GetPosition().x < posX + sizeX &&
				(player->GetPosition().y > posY || player->GetPosition().y + player->GetSize().y > posY) && player->GetPosition().y < posY + sizeY)
			{
				if (enemy->GetTimeToDelete() == 0)
				{
					enemy->SetVisible(true);
					enemy->SetTimeToDelete(time + 1000);
					player->set_score(player->get_score() + 1);
					sound->Play(wxSOUND_ASYNC);
				}
			}			
		}
	}
	enemies.erase(std::remove_if(enemies.begin(), enemies.end(), [time](Enemy* enemy) {
		if (enemy->GetTimeToDelete() > 0 && enemy->GetTimeToDelete() < time)
		{
			delete enemy;
			return true;
		}
		return false;
	}), enemies.end());
	
}

Player** GameScene::get_players()
{
	return players;
}

std::vector<Enemy*>& GameScene::get_enemies()
{
	return enemies;
}

bool GameScene::IsGameStarted()
{
	return isGameStarted;
}

GameScene::~GameScene()
{
	for(int i = 0; players[i] && i < sizeof(players) / sizeof(Player*); i++)
		delete players[i];
	for(auto enemy : enemies)
		delete enemy;
}

