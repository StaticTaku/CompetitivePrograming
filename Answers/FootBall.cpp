#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <ctype.h>
#include <stdio.h>

int strcmp_ignorecase(const char* s1, const char* s2)
{
	while (tolower(*s1) == tolower(*s2)) {
		if (*s1 == '\0') {
			return 0;
		}

		++s1;
		++s2;
	}
	return tolower(*s1) - tolower(*s2);
}

using namespace std;

#define SIZE (int)1e5

#define FOR(i,a,b) for(i = (a); i < (b); ++i)
#define REP(i,a)   for(i = 0;i < (a);++i)

class Team
{
public:
	string teamName;
	int data[7] = {0};

	int getGoalDifference() const
	{
		return data[5] - data[6];
	}
};


bool cmp(const Team& a, const Team& b)
{
	if (a.data[0] != b.data[0])
		return a.data[0] < b.data[0];
	if (a.data[2] != b.data[2])
		return a.data[2] < b.data[2];
	if (a.getGoalDifference() != b.getGoalDifference())
		return a.getGoalDifference() < b.getGoalDifference();
	if (a.data[5] != b.data[5])
		return a.data[5] < b.data[5];
	if (a.data[1] != b.data[1])
		return a.data[1] > b.data[1];
	return strcmp_ignorecase(a.teamName.c_str(), b.teamName.c_str()) > 0;
}

void output(const Team& a, int rank)
{
	cout << rank << ") " << a.teamName << " " << a.data[0] << "p, " << a.data[1] << "g " << "(" << a.data[2] << "-" << a.data[3] << "-" << a.data[4] << "), " << a.getGoalDifference() << "gd " << "(" << a.data[5] << "-" << a.data[6] << ")" << '\n';
}

int k, l, m;
string score;

void split(const string& result,string& teamName, string& teamName2, int& g1, int& g2)
{
	teamName.clear();
	teamName2.clear();

	k = 0;
	while (true)
	{
		if (result[k] != '#')
			teamName.push_back(result[k++]);
		else
			break;
	}

	l = ++k;
	while (true)
	{
		if (result[l] != '@')
			score.push_back(result[l++]);
		else
			break;
	}

	g1 = atoi(score.c_str());
	score.clear();

	m = ++l;

	while (true)
	{
		if (result[m] != '#')
			score.push_back(result[m++]);
		else
			break;
	}

	++m;

	g2 = atoi(score.c_str());
	score.clear();

	FOR(k, m, result.size())
	{
		teamName2.push_back(result[k]);
	}
}
vector<Team> teams(30);
map<string, int> index;
int i,j,teamNum,N,T, G,g1,g2;
string torName,result, teamName,teamName2;
void solve()
{
	cin >> N;
	cin.ignore();
	FOR(j, 0, N)
	{
		if (j != 0)
		{
			cout << "\n";
		}
		getline(cin, torName);
		cin >> T;
		cin.ignore();
		teams.clear();
		teams.resize(T);
		index.clear();
		int index1, index2;
		REP(i, T)
		{
			getline(cin, teamName);
			index[teamName] = i;
			teams[i].teamName = teamName;
		}

		cin >> G; cin.ignore();
		REP(i, G)
		{
			getline(cin, result);
			split(result, teamName, teamName2, g1, g2);
			index1 = index[teamName];
			index2 = index[teamName2];

			teams[index1].data[5] += g1;
			teams[index1].data[6] += g2;

			teams[index2].data[5] += g2;
			teams[index2].data[6] += g1;

			++teams[index1].data[1];
			++teams[index2].data[1];

			if (g1 < g2)
			{
				teams[index2].data[0] += 3;
				++teams[index2].data[2];

				++teams[index1].data[4];

			}
			else if (g1 == g2)
			{
				++teams[index1].data[0];
				++teams[index2].data[0];

				++teams[index1].data[3];
				++teams[index2].data[3];
			}
			else
			{

				teams[index1].data[0] += 3;
				++teams[index1].data[2];

				++teams[index2].data[4];
			}


		}

		sort(teams.begin(), teams.end(), cmp);

		cout << torName << '\n';
		
		REP(i,T)
			output(teams[T-1-i],i+1);
	
	}
}

int main()
{
	solve();
}