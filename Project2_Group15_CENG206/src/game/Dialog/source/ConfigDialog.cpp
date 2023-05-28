#include "../include/ConfigDialog.hpp"

ConfigDialog::ConfigDialog() : ConfigDialog(nullptr, "Window")
{
   
}

ConfigDialog::ConfigDialog(wxWindow* parent, wxString title) : ADialog(parent, title), playerName1(nullptr), playerName2(nullptr), enemySlider(nullptr)
{
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

    sub = &(MenuScene::OnDialogConfirm);
    
    wxStaticText* staticText1 = new wxStaticText(this, wxID_ANY, "Player Name");
    sizer->Add(staticText1, 0, wxALIGN_LEFT | wxALL, 10);

    playerName1 = new wxTextCtrl(this, wxID_ANY, "Player1", wxDefaultPosition, wxSize(200,20));
    sizer->Add(playerName1, 0, wxEXPAND | wxALL, 10);

   
    wxStaticText* staticText2 = new wxStaticText(this, wxID_ANY, "Player Name");
    sizer->Add(staticText2, 0, wxALIGN_LEFT | wxALL, 10);

    playerName2 = new wxTextCtrl(this, wxID_ANY, "Player2", wxDefaultPosition, wxSize(200,20));
    sizer->Add(playerName2, 0, wxEXPAND | wxALL, 10);

    sliderLabel = new wxStaticText(this, wxID_ANY, "Enemy Count: 1");
    sizer->Add(sliderLabel, 0, wxALIGN_LEFT | wxALL, 1);

    enemySlider = new wxSlider(this, wxID_ANY, 0, 0, 9, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
    sizer->Add(enemySlider, 0, wxEXPAND | wxALL, 10);

    enemySlider->Bind(wxEVT_SLIDER, &ConfigDialog::OnSlider, this);

    wxButton* button = new wxButton(this, wxID_OK, "Ok");
    sizer->Add(button, 0, wxALIGN_CENTRE_HORIZONTAL | wxALL, 10);

    button->Bind(wxEVT_BUTTON, &ConfigDialog::onButtonClick, this);

    SetSizerAndFit(sizer);

    Centre();
}



void ConfigDialog::Show()
{
    ShowModal();
}

void ConfigDialog::Hide()
{
    wxDialog::Hide();
}

void ConfigDialog::onButtonClick(wxCommandEvent& event)
{
    if (menu_scene != nullptr)
    {
	   (menu_scene->*sub)();
    }
    Hide();
}

void ConfigDialog::OnSlider(wxCommandEvent& event)
{
	wxString label = wxString::Format(wxT("Enemy Count: %d"), event.GetInt() + 1);
	sliderLabel->SetLabel(label);
}

wxString ConfigDialog::getPlayerName1()
{
    return wxString(playerName1->GetValue());
}

wxString ConfigDialog::getPlayerName2()
{
    return wxString(playerName2->GetValue());
}

int ConfigDialog::getEnemyCount()
{
	return enemySlider->GetValue() + 1;
}

ConfigDialog::~ConfigDialog()
{

}