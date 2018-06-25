#pragma once
#include <string>

using namespace std;

class Score
{

public:

	string name;
	float score;

	Score(string _name, float _score);

	Score(char* _name, float _score);

	Score();

	~Score();

};
