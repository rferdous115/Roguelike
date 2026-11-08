#pragma once

#include <string>
#include <bits/stdc++.h>

using namespace std;

class Player
{
public:
	Player(string name);

	void setName(string name);
	string getName();
private: 
	string _name;
};