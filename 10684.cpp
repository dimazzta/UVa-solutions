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

	int n;
	while(cin >> n, n){
		int mx = -INT_MAX;
		int cur = 0;
		for (int i = 0; i < n; i++){
			int x; cin >> x;
			cur += x;
			mx = max(cur, mx);
			if (cur < 0){
				cur = 0;
			}
		}
		if (mx > 0){
			cout << "The maximum winning streak is " << mx << "." << endl;
		}
		else{
			cout << "Losing streak." << endl;
		}
	}


	return 0;
}

