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
	while(t--){
		int n; cin >> n;
		vi a(n);
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		int cnt = 0;
		bool up = true;
		for (int i = 0; i < n;){
			if (up){
				do{
					i++;
				}
				while(i != n && a[i] > a[i - 1]);
			}
			else{
				do{
					i++;
				}
				while(i != n && a[i] < a[i - 1]);
			}
			up ^= 1;
			cnt++;
		}
		cout << cnt << endl;
	}


	return 0;
}

