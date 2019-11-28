#include <bits/stdc++.h>
using namespace std;
//#define DEBUG

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<int>> mi;
typedef vector<vector<pair<int, int>>> w_graph;
typedef vector<vector<int>> uw_graph;






int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   	#ifdef DEBUG
		freopen("out.txt", "w", stdout);
	#endif


	map<char, vector<int>> pos;
	string s; cin >> s;
	int q; cin >> q;
	for (int i = 0; i < s.size(); i++){
		pos[s[i]].push_back(i);
	}
	while(q--){
		string qs; cin >> qs;
		int cp = -1;
		int sp = -1;
		int ep = -1;
		bool f = true;
		for (int i = 0; i < qs.size(); i++){
			char t = qs[i];
			auto lb = lower_bound(pos[t].begin(), pos[t].end(), cp);
			if (lb != pos[t].end()){
				cp = *lb + 1;
				if (i == 0) sp = *lb;
				if (i == qs.size() - 1) ep = *lb;
			}
			else {
				f = false;
				break;
			}
		}
		if (f){
			cout << "Matched " << sp << " " << ep << endl;
		}
		else{
			cout << "Not matched" << endl;
		}
	}

	return 0;
}

