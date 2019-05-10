#include <bits/stdc++.h>
using namespace std;
int main()
{
	string base = "BCG";
	vector<string> v; v.push_back(base);
	while (next_permutation(base.begin(), base.end())) v.push_back(base);
	sort(v.begin(), v.end());
	map<char, vector<int>> m;
	m['B'].resize(3); m['C'].resize(3); m['G'].resize(3);
	while (cin >> m['B'][0] >> m['G'][0] >> m['C'][0] >> m['B'][1] >> m['G'][1] >> m['C'][1] >> m['B'][2] >> m['G'][2] >> m['C'][2]){
		string opt = "";
		int sum = INT_MAX;
		for (int i = 0; i < v.size(); i++){
			int cur = 0;
			for (int j = 0; j < 3; j++){
				for (int k = 0; k < 3; k++){
					if (j != k) cur += m[v[i][j]][k];
				}
			}
			if (cur < sum){
				opt = v[i];
				sum = cur;
			}
		}
		cout << opt << " " << sum << endl;
	}
}
