#include <wx/wx.h>
#include <vector>
#include <algorithm>
#include "Player.hpp"
#include "HikeAndSeekGame.hpp"

class HikeAndSeekFrame : public wxFrame {
private:
    wxListBox* listBox;
    HikeAndSeekGame game;

public:
    HikeAndSeekFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title) {
        wxPanel* panel = new wxPanel(this, wxID_ANY);

        listBox = new wxListBox(panel, wxID_ANY, wxPoint(10, 10), wxSize(300, 200));

        wxButton* startButton = new wxButton(panel, wxID_ANY, "Start Game", wxPoint(10, 220));
        startButton->Bind(wxEVT_BUTTON, &HikeAndSeekFrame::OnStartGame, this);

        wxSizer* sizer = new wxBoxSizer(wxVERTICAL);
        sizer->Add(panel, 1, wxEXPAND);
        SetSizerAndFit(sizer);
    }

private:
    void OnStartGame(wxCommandEvent& event) {
        Player* player1 = new Player("Alice");
        Player* player2 = new Player("Bob");

        game.addPlayer(player1);
        game.addPlayer(player2);

        game.playGame();

        UpdateListBox();

        delete player1;
        delete player2;
    }

    void UpdateListBox() {
        listBox->Clear();
        const std::vector<Player*>& players = game.getPlayers();
        for (const Player* player : players) {
            wxString playerName = player->getName();
            wxString playerScore = wxString::Format("%d", player->getScore());
            listBox->Append(playerName + " - Score: " + playerScore);
        }
    }

    wxDECLARE_EVENT_TABLE();
};

wxBEGIN_EVENT_TABLE(HikeAndSeekFrame, wxFrame)
EVT_CLOSE(HikeAndSeekFrame::OnClose)
wxEND_EVENT_TABLE()

class HikeAndSeekApp : public wxApp {
public:
    virtual bool OnInit() {
        HikeAndSeekFrame* frame = new HikeAndSeekFrame("Hike and Seek Game");
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(HikeAndSeekApp);

