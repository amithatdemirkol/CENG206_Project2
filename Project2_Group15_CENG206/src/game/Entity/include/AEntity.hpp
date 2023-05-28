#ifndef _AENTITY_H_
#define _AENTITY_H_

#include <wx/wx.h>
#include "IEntity.hpp"
#include "../../Utils/include/Vector2.hpp"

class AEntity : public IEntity
{
	public:
		AEntity(wxPanel* panel, const char* image_path, Vector2 position);
		virtual ~AEntity();

		void SetPosition(Vector2 position);
		Vector2 GetPosition();
		Vector2 GetSize();

		bool IsPositionInside(Vector2 position);

		void MoveUp();
		void MoveDown();
		void MoveLeft();
		void MoveRight();

	protected:

		Vector2 position;
		Vector2 size;
		const Vector2 border_size;

		wxPanel* panel;
		wxStaticBitmap* image;


		AEntity() : image(nullptr) , panel(nullptr), border_size(10,45) { };

		class ImageNotFoundException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Image Not Found";
				}
		};

};

#endif

