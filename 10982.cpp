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


int calc(set<int> & A, set<int> & B, vector<vector<int>> & G){
	int cnt = 0;
	for (int i = 1; i < G.size(); i++){
		for (int j = 0; j < G[i].size(); j++){
			if ((A.find(G[i][j]) != A.end() && A.find(i) != A.end()) || ((B.find(G[i][j]) != B.end() && B.find(i) != B.end()))) cnt++;
		}
	}
	return cnt / 2;
}

int maxG(set<int> & A, vector<vector<int>> & G){
	int mx_cnt = 0;
	int mx_i = -1;
	for (int i = 1; i < G.size(); i++){
		if (A.find(i) != A.end()){
			int cnt = 0;
			for (int j = 0; j < G[i].size(); j++){
				if (A.find(G[i][j]) != A.end()) {
					cnt++;
				}
			}
			if (cnt > mx_cnt){
				mx_i = i;
				mx_cnt = cnt;
			}
		}
		
	}
	return mx_i;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   	#ifdef DEBUG
		freopen("out.txt", "w", stdout);
	#endif

	int t; cin >> t;
	for (int test = 1; test <= t; test++){
		int n, m; cin >> n >> m;
		vector<vector<int>> G(n + 1);
		set<int> A, B;
		for (int i = 1; i <= n; i++){
			A.insert(i);
		}
		for (int i = 0; i < m; i++){
			int x, y;
			cin >> x >> y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		
		int cur_cnt = m;
		int k = m / 2;
		while (cur_cnt > k){
			int v = maxG(A, G);
			assert(v != -1);
			A.erase(A.find(v));
			B.insert(v);
			cur_cnt = calc(A, B, G);
		}	
		cout << "Case #" << test << ": " << A.size() << endl;
		bool q = false;
		for (auto f : A){
			if (q) cout << " ";
			cout << f;
			q = true;
		}
		cout << endl;
	}
	return 0;
}

