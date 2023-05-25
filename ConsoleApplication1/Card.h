#pragma once
#include<iostream>
using namespace std;


class Card
{private: 
	string Name; 

public:
	Card();
	void printname()
	{
		cout << Name; 
	}

};

