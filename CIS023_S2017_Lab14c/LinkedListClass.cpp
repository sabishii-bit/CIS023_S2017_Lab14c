#include "stdafx.h"
#include "LinkedListClass.h"


LinkedListClass::LinkedListClass()
{
	firstStar = nullptr;
	lastStar = nullptr;
	currentStar = nullptr;
}


LinkedListClass::~LinkedListClass()
{
	while (firstStar != nullptr)
	{
		StarClass* tempStar = new StarClass;
		tempStar = firstStar;
		firstStar = firstStar->GetNextStar();
		delete tempStar;
	}
}


// add a new star to the end of the list
void LinkedListClass::Add(HWND hWnd)
{
	StarClass* newStar = new StarClass(hWnd);	// create new Star of type StarClass

	newStar->SetNextStar(nullptr);
	newStar->SetPrevStar(lastStar);

	if (firstStar == nullptr)
		firstStar = newStar;
	else
		lastStar->SetNextStar(newStar);		// old bottom Star points to new Star

	lastStar = newStar;						// append new Star to bottom of list
}

void LinkedListClass::Delete()
{
	StarClass* tempStar = new StarClass;
	tempStar = currentStar;

	if (currentStar == firstStar)			// special consideration for 1st node
	{
		firstStar = currentStar->GetNextStar();
		firstStar->SetPrevStar(nullptr);
		currentStar = firstStar;

	}
	else if (currentStar == lastStar)		// special consideration for last node
	{
		lastStar = currentStar->GetPrevStar();
		lastStar->SetNextStar(nullptr);
		currentStar = lastStar;
	}
	else									// node in the middle of the list
	{
		currentStar->GetPrevStar()->SetNextStar(currentStar->GetNextStar());
		currentStar->GetNextStar()->SetPrevStar(currentStar->GetPrevStar());

		currentStar = currentStar->GetNextStar();
	}
	delete tempStar;
}

void LinkedListClass::First()
{
	currentStar = firstStar;
}

void LinkedListClass::Next()
{
	currentStar = currentStar->GetNextStar();
}

StarClass * LinkedListClass::GetCurrentStar()
{
	return currentStar;
}
