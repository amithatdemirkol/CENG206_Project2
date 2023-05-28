#ifndef _VECTOR2_H_
#define _VECTOR2_H_

#include <wx/wx.h>

class Vector2
{

	public:
		Vector2();
		Vector2(int x, int y);
		~Vector2();

		Vector2 Up();
		Vector2 Down();
		Vector2 Left();
		Vector2 Right();

		Vector2& operator=(Vector2& rhs);
		Vector2& operator=(Vector2 rhs);
		Vector2& operator=(wxSize& rhs);
		Vector2& operator=(wxSize rhs);
		
		bool operator==(Vector2& rhs);

		int x;
		int y;

};

#endif

