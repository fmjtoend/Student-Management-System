#pragma once
#include"vectors.h"
class Usefstream
{
public:
	void addToFile(vectors *v, int choice);
	void readFile(vectors* v, int choice);

	Usefstream() = default;
	bool operator==(const Usefstream& other) const;
};

