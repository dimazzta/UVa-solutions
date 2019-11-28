#include <bits/stdc++.h>
using namespace std;
#define DEBUG

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
	int a, u, v;
	while(cin >> a >> u >> v){
		ii cop_speed = {0, 0}, cop_pos = {0, 0};
		ii thief_speed = {u, v}, thief_pos = {a, 0};
		int k = 0;
		while(cop_pos.first < thief_pos.first || cop_pos.second < thief_pos.second){
			thief_pos.first += thief_speed.first;
			thief_pos.second += thief_speed.second;
			
			cop_speed.first += 1;
			cop_speed.second += 1;
			cop_pos.first += cop_speed.first;
			cop_pos.second += cop_speed.second;
			
			k++;
		}
		cout << k << endl;
	}


	return 0;
}

