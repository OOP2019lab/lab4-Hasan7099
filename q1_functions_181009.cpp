#include "q1_181009.h"
#include <iostream>
#include <string>
#include<fstream>

using namespace std; 

//this constructor sets every value accordingly without arguements. Default Constructor
cricket_team::cricket_team()
{
	members = nullptr;
	total_members = -1;
	team_name = nullptr;
	last10score[10] = { -1};
	rank = -1;
	captain = "";
}
//this is a parametrized constructor. With 2 arguements
cricket_team::cricket_team(string name, int total_members)
{
	int length;
	members = nullptr;
	total_members = total_members;
	length = strlen(name.c_str());
	team_name = new char[length+1];				//length plus 1 to store the null character
	strcpy(team_name, name.c_str());
	//team_name = name.c_str();
	last10score[10] = { -1};
	rank = -1;
	captain = "";
}
//this constructor reads from file
cricket_team::cricket_team(string file_name)
{
	string str;
	int length;
	ifstream load;
	load.open(file_name);
	getline(load, str, ':');
	getline(load, str);
	length = strlen(str.c_str());
	team_name = new char[length + 1];
	strcpy(team_name, str.c_str());
	getline(load, str, ':');
	getline(load, str);
	total_members = atoi(str.c_str());
	members_set = total_members;
	members = new string[total_members];
	for (int i = 0; i < total_members; i++)
	{
		getline(load, str);
		members[i] = str;
	}
	getline(load, str, ':');
	getline(load, str);
	rank = atoi(str.c_str());
	getline(load, str, ':');
	getline(load, str);
	captain = str;
	getline(load, str, ':');
	scores_set = 10;
	for (int i = 0; i < 10; i++)
	{
		getline(load, str, ',');
		last10score[i] = atoi(str.c_str());
	}
}
//sets team members one by one...fills team member array
void cricket_team:: set_member(string member)
{
	if (members_set < total_members)
	{
		members[members_set] = member;
		members_set++;
	}
	else
		cout << " \nTeam is Full. There's no space left...\n";
}
//sets score one by one and fills last 10 matches array
void cricket_team::set_score(int score)
{
	if (scores_set < 10)
	{
		last10score[scores_set] = score;
		scores_set++;
	}
	else
	{
		for (int i = 0; i < 9;i++)
		{
			last10score[i] = last10score[i + 1];
		}
		last10score[9] = score;
	}
}
//returns the average 
double cricket_team::get_average()
{
	int total = 0;
	for (int i = 0; i < 10; i++)
	{
		total = total + last10score[i];
	}
	cout << (total / 10);
	return (total / 10);
}
//returns some of informations i.e. Latest Score, Captain and Team Name
void cricket_team::get_latest_score()
{
	cout << "Latest Score : " << last10score[scores_set];
	cout << endl << "Team Name : " << team_name << "	Captain Name : " << captain << endl;
}
//returns all  of team's info
void cricket_team::get_team_info()
{
	cout << "Team Name : " << team_name << endl;
	cout << "Total Members : " << total_members << endl;
	for (int i = 0; i < total_members;i++)
		cout << members[i] << endl;
	cout << "Rank : " << rank << endl;
	cout << "Captain : " << captain << endl;
	for (int i = 0; i < scores_set;i++)
		cout << last10score[i] << " , ";
	cout << endl;
}
//deletes everything and gives them null values
void cricket_team::destructor()
{
	delete[] members;
	delete[] team_name;
	delete[] last10score;
	rank = NULL;
	captain = "";
	scores_set = NULL;
	members_set = NULL;
}
//this functions tells if team A is better or Not
bool is_better(cricket_team A, cricket_team B)			//A is input team (the team to be compared
{
	if (A.get_average() > B.get_average())
		return true;
	else
		return false;
}


