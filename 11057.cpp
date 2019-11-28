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
	
	while(cin >> n){
		
		vector<int> a(n);
		for (int i = 0; i < n;i++) cin >> a[i];
		int m; cin >> m;
		sort(a.begin(), a.end());
		int b1 = 0, b2 = 0;
		int mdiff = INT_MAX;
		for (int i = 0; i < n; i++){
			if (binary_search(a.begin(), a.end(), m - a[i])){
				if (a[i] != m - a[i] || (a[i] == m - a[i] && count(a.begin(), a.end(), a[i]) > 1)){
					int df = abs(2 * a[i] - m);
					if (df < mdiff){
						b1 = a[i]; b2 = m - a[i];
						mdiff = df;
					}
				}			
			}
		}
		if (b1 > b2) swap(b1, b2);
		cout << "Peter should buy books whose prices are " << b1 << " and " << b2 << "." << endl << endl;
	}
	


	return 0;
}

