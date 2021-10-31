#include "stdafx.h"
#include "StarClass.h"


StarClass::StarClass()
{
}

StarClass::StarClass(HWND hWnd)
{
	// get client window dimensions
	GetClientRect(hWnd, &rClient);
	pCenter.x = rClient.right / 2;								// set center
	pCenter.y = rClient.bottom / 2;
	iFrame = 0;

	// random number generator, run these three lines once at the beginning of the program
	random_device rd;											// non-deterministic generator
	mt19937 gen(rd());											// to seed mersenne twister.
	uniform_int_distribution<> distX(0, rClient.right - 1);		// distribute results between 0 and max X
	uniform_int_distribution<> distY(0, rClient.bottom - 1);	// distribute results between 0 and max Y
	uniform_int_distribution<> distC(0, 255);					// distribute results between 0 and max color

	// insert dist(gen) everywhere you need a random number
	rDim.left = distX(gen);										// set random horizontal values
	rDim.right = rDim.left + 20;

	rDim.top = distY(gen);										// set random vertical values
	rDim.bottom = rDim.top + 20;

	r = distC(gen);												// set random color values
	g = distC(gen);
	b = distC(gen);

}

StarClass::~StarClass()
{
}

StarClass * StarClass::GetNextStar()
{
	return nextStar;
}

StarClass * StarClass::GetPrevStar()
{
	return prevStar;
}

void StarClass::SetNextStar(StarClass* star)
{
	nextStar = star;
}

void StarClass::SetPrevStar(StarClass * star)
{
	prevStar = star;
}

void StarClass::Draw(HDC hdc)
{
	HBRUSH brush = CreateSolidBrush(RGB(r, g, b));				// color brush for flood file
	HBRUSH oldBrush;
	oldBrush = (HBRUSH)SelectObject(hdc, brush);				// set brush

	FillRect(hdc, &rDim, brush);								// draw filled rectangle

	SelectObject(hdc, oldBrush);								// reset brush
	DeleteObject(brush);
}

bool StarClass::Move()
{
	if (rDim.left < pCenter.x)
	{
		rDim.left++;
		rDim.right++;											// move one pixel right
	}
	else
	{
		rDim.left--;
		rDim.right--;											// move one pixel left
	}
	if (rDim.top < pCenter.y)
	{
		rDim.top++;
		rDim.bottom++;
	}
	else
	{
		rDim.top--;
		rDim.bottom--;
	}

	if (iFrame % 50 == 0)
	{
		rDim.right++;
		rDim.bottom++;
	}

	// made it to the center (or at least 3 pixels of the center)
	if (rDim.left > pCenter.x - 3 && rDim.left < pCenter.x + 3 &&
		rDim.top > pCenter.y - 3 && rDim.top < pCenter.y + 3)
		return false;

	return true;
}

RECT StarClass::GetInvalidateRect()
{
	rReturn = rDim;												// return value is rectangle

	rReturn.left--;												// add a pixel around to account for movement
	rReturn.top--;
	rReturn.right++;
	rReturn.bottom++;

	return rReturn;												// return bigger rectangle
}

