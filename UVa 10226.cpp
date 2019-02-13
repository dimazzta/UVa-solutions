#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d\n\n", &n);
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		map<string, int> mapper;

		while (true) {
			string s;
			getline(cin, s);
			if (s == "") break;
			mapper[s]++;
			cnt++;
		}
		for (map<string, int>::iterator it = mapper.begin(); it != mapper.end(); it++) {
			cout << it->first << " " << fixed << setprecision(4) << (double)it->second / cnt * 100 << endl;
		}
		if (i != n - 1)
			cout << endl;
	}
}
