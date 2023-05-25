#include "Profile.h"


Profile::Profile(string name= "Visitor", int score= 0)
{
    name = p_Name;
    score= p_BestScore;

}

string Profile::getName() const
{
     return p_Name;
}

int Profile::getBestScore() const
{

    return p_BestScore;
}

vector<int> Profile::getOldScores() const
{
    return p_OldScores;
}

void Profile::setBestScore(int bestScore)
{
    p_BestScore = bestScore;
}

void Profile::addoldScore(int oldScore)
{
    p_OldScores.push_back(oldScore);
}

vector<Profile> Profile::loadProfiles()
{
    vector <Profile> profiles;
    ifstream file("Profiles.txt");
    if (file.is_open())
    {
        while (getline(file, line))
        {
            istringstream iss(line);
            string name;
            int bestscore;
            iss >> name >> bestscore;
            Profile profile(name);
            profile.setBestScore(bestscore);
            while (iss >> bestscore)
            {
                profile.addoldScore(bestscore);
            }
            profiles.push_back(profile);
        }
        file.close();
    }
    return profiles;
}

void Profile::SaveProfiles(const vector <Profile>& profiles)
{
    ofstream file("Profiles.txt");
    if (file.is_open())
    {
        for (const auto& profile : profiles)
        {
            file << profile.getName() << " " << profile.getBestScore() << endl;
            for (int oldScore : profile.getOldScores())
            {
                file << " " << oldScore;
            }
            file << endl;
        }
        file.close();
    }

}

bool Profile::CompareScoreInProfiles(const Profile& p1, const Profile& p2)
{
    return p1.getBestScore() < p2.getBestScore();
}

void Profile::SortProfilesByScore()
{
    //sort(profiles.begin(), profiles.end(), CompareScoreInProfiles);
}
