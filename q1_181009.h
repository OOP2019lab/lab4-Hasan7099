#pragma once
#include <string>
using namespace std;

class cricket_team
{
private:
	int members_set = 0;
	int scores_set = 0;
	string * members;
	int total_members;
	char * team_name;
	int last10score[10];
	int rank;
	string captain;
public:
	cricket_team();
	cricket_team(string name, int total_members);
	cricket_team(string file_name);
	void set_member(string member);
	void set_score(int score);
	double get_average();
	void get_latest_score();
	void get_team_info();
	void destructor();
};
