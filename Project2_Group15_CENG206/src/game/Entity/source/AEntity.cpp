#include "../include/AEntity.hpp"

AEntity::AEntity(wxPanel* panel, const char* image_path, Vector2 position) : border_size(10,45) , image(nullptr)
{
	wxImage image("./assets/" + std::string(image_path), wxBITMAP_TYPE_PNG);
	if (!image.IsOk())
		throw ImageNotFoundException();

	wxBitmap bitmap(image);
	this->image = new wxStaticBitmap(panel, wxID_ANY, bitmap);
	this->image->SetCanFocus(false);
	this->size = image.GetSize();
	this->panel = panel;
	SetPosition(position);
}

void AEntity::MoveUp()
{
	SetPosition(position.Up());
	image->SetPosition(wxPoint(position.x, position.y));
}

void AEntity::MoveDown()
{
	SetPosition(position.Down());
	image->SetPosition(wxPoint(position.x, position.y));
}

void AEntity::MoveLeft()
{
	SetPosition(position.Left());
	image->SetPosition(wxPoint(position.x, position.y));
}

void AEntity::MoveRight()
{
	SetPosition(position.Right());
	image->SetPosition(wxPoint(position.x, position.y));
}

void AEntity::SetPosition(Vector2 position)
{
	this->position = static_cast<Vector2>(position);
	image->SetPosition(wxPoint(position.x, position.y));
}

Vector2 AEntity::GetPosition()
{
	return position;
}

Vector2 AEntity::GetSize()
{
	return size;
}

bool AEntity::IsPositionInside(Vector2 position)
{
	return (position.x >= 0 && position.x + size.x + border_size.x < panel->GetSize().x && position.y >= 0 && position.y + size.y + border_size.y < panel->GetSize().y);
}

AEntity::~AEntity() 
{
	
}
