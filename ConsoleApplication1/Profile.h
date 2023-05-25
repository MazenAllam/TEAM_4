#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include<fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Profile
{
private:
	string p_Name;
	int p_BestScore;
	vector <int> p_OldScores;
	vector <Profile> profiles;
	string line;

public:
	Profile();
	Profile(string name, int score);
	string getName() const;
	int getBestScore() const;
	vector<int> getOldScores() const;
	void setBestScore(int bestScore);
	void addoldScore(int oldScore);

//loading profiles from files
	vector <Profile> loadProfiles();

	void SaveProfiles(const vector <Profile>& profiles);    // used to pass a vector of Profile objects by reference to a function

//Comparing scores of 2 profiles by score for the leaderboard
	bool CompareScoreInProfiles(const Profile& p1, const Profile& p2);
	void SortProfilesByScore();

};


//Drawing Leaderboard on screen

//Text.t_Leader;
//t_Leader.setFont(creditfont);
//t_Leader.setCharacterSize(24);
//t_Leader.setStrinng("Leaderboard");
//t_Leader.setPosition(200, 200);
