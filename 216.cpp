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

ii coords[10];
int n;
double dp[10][1 << 10];
int path[10][1 << 10];

double calc(ii a, ii b){
	return sqrt(pow(b.first - a.first, 2) + pow(b.second - a.second, 2));
}


double solve(int idx, int mask){
	if (mask == (1 << n) - 1){
		return 0;
	}
	if (dp[idx][mask] != -1) return dp[idx][mask];
	double mn = INT_MAX;
	for (int i = 0; i < n; i++){
		if (((mask & (1 << i)) == 0) && (idx != i)){
			double d = calc(coords[idx], coords[i]);
			double pret = d + solve(i, mask | (1 << i));
			if (pret < mn){
				mn = pret;
				path[idx][mask] = i;
			}
		}
	}
	return dp[idx][mask] = mn;
}

void init(){
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < (1 << 10); j++){
			dp[i][j] = -1;
			path[i][j] = -1;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   	#ifdef DEBUG
		freopen("out.txt", "w", stdout);
	#endif

	int tc = 1;
	while(cin >> n, n){	
       
		for (int i = 0; i < n; i++) cin >> coords[i].first >> coords[i].second;
		double ans = 1e20;
		vi seq;
		for (int i = 0; i < n; i++){
			init();
			double a = solve(i, (1 << i));
			if (a < ans){
				ans = a;
				seq.clear();
				int j = i, mask = (1 << i);
				seq.push_back(j);
				while(path[j][mask] != -1){
					seq.push_back(path[j][mask]);
					j = path[j][mask];
					mask |= (1 << j);
			   }
			}
		}
		
		
		ans += (n - 1) * 16;
		cout << "**********************************************************" << endl;
		cout << "Network #" << tc++ << endl;
		for (int i = 0; i < seq.size() - 1; i++){
			double d = sqrt(pow(coords[seq[i]].first - coords[seq[i + 1]].first, 2) + pow(coords[seq[i]].second - coords[seq[i + 1]].second, 2));
			d += 16;
			cout << "Cable requirement to connect (" << coords[seq[i]].first << "," << coords[seq[i]].second << ") to (" << coords[seq[i + 1]].first << "," << coords[seq[i + 1]].second << ") is " << setprecision(2) << fixed << d << " feet." << endl;
		}
		cout << "Number of feet of cable required is " << setprecision(2) << fixed << ans << "." << endl;
	}


	return 0;
}

