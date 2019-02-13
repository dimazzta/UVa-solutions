#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n), n) {
		map<string, int> mapper;
		string s;
		for (int i = 0; i < n; i++) {
			int courses[5];
			s = "";
			scanf("%d %d %d %d %d", courses, courses + 1, courses + 2, courses + 3, courses + 4);
			sort(courses, courses + 5);
			
			for (int j = 0; j < 5; j++) {
				s += to_string(courses[j]);
				if (j != 4) s += " ";
			}
			mapper[s]++;
		}
		int max = 0, max_c = 0;
		for (map<string, int>::iterator it = mapper.begin(); it != mapper.end(); it++) {
			if (it->second > max) {
				max = it->second;
				max_c = 1;
			}
			else if (it->second == max) {
				max_c++;
			}
		}
		cout << max * max_c << endl;
	}
}
