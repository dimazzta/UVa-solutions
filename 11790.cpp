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

	int t; cin >> t;

	for (int test = 1; test <= t; test++){
		int n; cin >> n;
		vi h(n), w(n), lis(n), lds(n);
		for (int i = 0; i < n; i++) cin >> h[i];
		for (int i = 0; i < n; i++) cin >> w[i];
		lis[0] = w[0];
		lds[0] = w[0];
		for (int i = 1; i < n; i++){
			int max_lis = w[i], max_lds = w[i];
			for (int j = 0; j < i; j++){
				if (h[i] > h[j]){
					max_lis = max(max_lis, lis[j] + w[i]);
				}
				else if (h[i] < h[j]){
					max_lds = max(max_lds, lds[j] + w[i]);
				}
			}
			lis[i] = max_lis; lds[i] = max_lds;
			
		}
		int max_lis = 0, max_lds = 0;
		for (int i = 0; i < n; i++){
			max_lis = max(max_lis, lis[i]);
			max_lds = max(max_lds, lds[i]);
		}
		if (max_lis >= max_lds){
			cout << "Case " << test << ". Increasing (" << max_lis << "). Decreasing (" << max_lds << ")." << endl;
		}
		else{
			cout << "Case " << test << ". Decreasing (" << max_lds << "). Increasing (" << max_lis << ")." << endl;
		}
	}


	return 0;
}

