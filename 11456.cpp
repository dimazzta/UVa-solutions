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
        if (n == 0){
        	cout << 0 << endl;
        	continue;
        }
        vi lis(n), lds(n);
        lis[n - 1] = 1;
        lds[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
        {
        	int max_lds = 1, max_lis = 1;
        	for (int j = n - 1; j > i; j--){
        		if (a[i] < a[j]){
        			max_lds = max(max_lds, lds[j] + 1);
        		}
        		else{
        			max_lis = max(max_lis, lis[j] + 1);
        		}
        	}
        	lds[i] = max_lds;
			lis[i] = max_lis; 
        }
        int mx = 0;
        for (int i = 0; i < n; i++){
        	mx = max(mx, lds[i] + lis[i] - 1);
        }
        cout << mx << endl;
	}
	
	return 0;
}

