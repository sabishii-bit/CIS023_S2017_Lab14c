#pragma once
class LinkedListClass
{
public:
	LinkedListClass();
	~LinkedListClass();

	void Add(HWND);						// append a start to the list
	void Delete();						// delete the currentStar
	void First();						// make currentStar the 1st star in the list
	void Next();						// advance currentStar to next star in list
	StarClass* GetCurrentStar();		// return the current star

private:
	StarClass* firstStar;				// first node in list
	StarClass* lastStar;				// last node in list
	StarClass* currentStar;				// current node

};

