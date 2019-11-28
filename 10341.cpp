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


const double eta = 1e-9;
double p, r, q, s, t, u;
double f(double x){
	double res = p * exp(-x) + q*sin(x) + r * cos(x) + s * tan(x) + t * x * x + u; 
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   	#ifdef DEBUG
		freopen("out.txt", "w", stdout);
	#endif
	
	while(cin >> p >> q >> r >> s >> t >> u){
        if (f(0) * f(1) <= 0){
        	double lo = 0, hi = 1;
        	double y = f(lo);
        	while(abs(f(lo)) > eta){
        		double mid = lo + (hi - lo) / 2.0;
        		if (f(mid) < 0){
        			hi = mid;
        		}
        		else{
        			lo = mid;
        		}
        	}
        	cout << setprecision(4) << fixed << lo << endl;
        }
        else{
        	cout << "No solution" << endl;
        }
	}


	return 0;
}

