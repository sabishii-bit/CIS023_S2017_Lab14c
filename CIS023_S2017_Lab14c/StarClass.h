#pragma once
class StarClass
{
public:
	StarClass();
	StarClass(HWND);				// override constructor
	~StarClass();

	StarClass* GetNextStar();		// movement along linked list
	StarClass* GetPrevStar();
	void SetNextStar(StarClass*);
	void SetPrevStar(StarClass*);

	void Draw(HDC);					// draw the rectangle
	bool Move();					// move the rectangle (change coordinates)
	RECT GetInvalidateRect();		// return rReturn


private:

	RECT rDim;						// dimensions of rectangle
	RECT rReturn;					// dimensions of invalidate rectangle

	int r, g, b;					// red, green, blue, for color definition

	RECT rClient;					// client region
	POINT pCenter;					// center of the client region
	int iFrame;						// how many times the star has moved

	StarClass* nextStar;			// pointer to next node in list
	StarClass* prevStar;			// pointer to previous node in list
};

