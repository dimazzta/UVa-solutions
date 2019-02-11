#include <bits/stdc++.h>
using namespace std;

struct team{
	int id;
	int problem_solved;
	int penalty;
	vector< pair<int, int> > problems;
};

int main() {
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d\n\n", &n);
	int id, pr, tm;
	char L;
	bool endline = false;
	for (int i = 0; i < n; ++i) {
		if (endline) cout << endl;
		vector<team> teams;
		string s;
		while (getline(cin, s)) {
			if (s.empty()) break;
			sscanf(s.c_str(), "%d %d %d %c", &id, &pr, &tm, &L);
			bool new_team = true;
			for (int j = 0; j < teams.size(); j++) {
				if (teams[j].id == id) {
					new_team = false;
					if (L == 'I' && teams[j].problems[pr].second == 0) teams[j].problems[pr].first += 20;
					else if (L == 'C' && teams[j].problems[pr].second == 0) teams[j].problems[pr].second = tm;
					break;
				}
			}
			if (new_team) {
				team t;
				t.id = id;
				t.problem_solved = 0;
				t.penalty = 0;
				t.problems.resize(10);
				if (L == 'I' && t.problems[pr].second == 0) t.problems[pr].first += 20;
				else if (L == 'C' && t.problems[pr].second == 0) t.problems[pr].second = tm;
				teams.push_back(t);
			}
		}
		for (int j = 0; j < teams.size(); j++) {
			for (int k = 1; k <= 9; k++) {
				if (teams[j].problems[k].second != 0) {
					teams[j].problem_solved++;
					teams[j].penalty += teams[j].problems[k].first + teams[j].problems[k].second;
				}
			}
		}


		sort(teams.begin(), teams.end(), [](team & a, team & b) -> bool {
			if (a.problem_solved != b.problem_solved) {
				return a.problem_solved > b.problem_solved;
			}
			else {
				if (a.penalty != b.penalty) {
					return a.penalty < b.penalty;
				}
				else {
					return a.id < b.id;
				}
			}
		});
		for (auto team : teams) {
			cout << team.id << " " << team.problem_solved << " " << team.penalty << endl;
		}
		endline = true;
	}
}
