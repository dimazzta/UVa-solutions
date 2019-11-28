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

	int d[101];
	for (int i = 0; i < 101; i++) d[i] = 0;
	int k; cin >> k;
	for (int i = 0; i < k; i++){
		int n; cin >> n;
		for (int j = 0; j < n; j++){
			int a; cin >> a;
			d[a]++;
		}
	}
	for (int i = 0; i < 101; i++){
		for (int j = 0; j < d[i]; j++){
			cout << i << " ";
		}
	}
}

