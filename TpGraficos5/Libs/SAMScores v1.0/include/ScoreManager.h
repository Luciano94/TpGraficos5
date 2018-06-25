#pragma once
#include <string>
#include <list>
#include <vector>
#include "Score.h"

using namespace std;

class ScoreManager
{
public:

	ScoreManager();
	~ScoreManager();

	void CreateScore(const string& name);
	void UpdateScore(const string& name, float newValue);
	void PlusScore(const string& name, float value);

	void GetSortedDescending(vector<Score>& scoreVector);
	void GetSortedAscending(vector<Score>& scoreVector);

	float GetHigher();
	float GetLower();
	float GetScoreValueByName(const string& name);

private:

	list<Score> scores;

	void SortDescending();

};

