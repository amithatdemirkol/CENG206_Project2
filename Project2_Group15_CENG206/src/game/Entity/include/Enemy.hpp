#include "AEntity.hpp"


class Enemy : public AEntity
{
	
	private:
		Vector2 direction;
		Vector2 target;

		bool isVisible;
		wxMilliClock_t timeToDelete;

	public:
		Enemy(wxPanel* panel, const char* image_path, Vector2 position);
		~Enemy();


		bool IsVisible();
		void SetVisible(bool visible);
		void SetTimeToDelete(wxMilliClock_t time);
		wxMilliClock_t GetTimeToDelete();

		void Move();
		void setTarget();

	

};

