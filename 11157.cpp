#include <bits/stdc++.h>
#include <cstdlib>
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

	int t; cin >> t;
	for (int test = 1; test <= t; test++){
		int n; ll d;
		cin >> n >> d;
		vector<pair<char, ll>> rocks(n);
		for (int i = 0; i < n; i++){
			string q; cin >> q;
			rocks[i].first = q[0];
			string mys = q.substr(2);
			rocks[i].second = atoll(mys.c_str());
		}
		ll max_leap = 0;
		ll cur_point = 0;
		bool skip = false;
		for (int i = 0; i < n; i++){
			if (rocks[i].first == 'B'){
				max_leap = max(max_leap, rocks[i].second - cur_point);
				cur_point = rocks[i].second;
			}
			else if (rocks[i].first == 'S'){
				if (!skip){
					max_leap = max(max_leap, rocks[i].second - cur_point);
					cur_point = rocks[i].second;
					rocks[i].first = 'D';
				}
				skip ^= 1;
			}
		}
		
		max_leap = max(max_leap, d - cur_point);
		for (int i = 0; i < n; i++){
			rocks[i].second = d - rocks[i].second;
		}
		reverse(rocks.begin(), rocks.end());
		cur_point = 0;
		for (int i = 0; i < n; i++){
			if (rocks[i].first == 'B'){
				max_leap = max(max_leap, rocks[i].second - cur_point);
				cur_point = rocks[i].second;
			}
			else if (rocks[i].first == 'S'){
				max_leap = max(max_leap, rocks[i].second - cur_point);
				cur_point = rocks[i].second;
			}
		}
		
		max_leap = max(max_leap, d - cur_point);
		cout << "Case " << test << ": " << max_leap << endl;
	}
	

	return 0;
}

