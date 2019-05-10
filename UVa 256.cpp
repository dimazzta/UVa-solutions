#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int dn(int p){
	int a = 0;
	while (p){
		a++;
		p /= 10;
	}
	return a;
}
bool check(ll p, int b){
	ll p1, p2;
	p1 = 0; p2 = 0;
	p1 = p;
	for (int i = 0; i < b; ++i){
		ll md = p1 % 10; p2 += md * pow(10, i);
		p1 /= 10;
	}
	return (p1 + p2)*(p1 + p2) == p;
}

int main()
{
	
	int maxN = 1e9;
	vector<ll> psq;
	for (int i = 0; i * i < maxN; i++){
		psq.push_back(i * i);
	}
	vector<vector<int>> nums(9);
	
	for (int k = 2; k <= 8; k++){
		int b = k / 2;
		for (int i = 0; psq[i] < pow(10, k); i++){
			if (check(psq[i], b)){
				nums[k].push_back(psq[i]);
			}
		}
	}
	int n;
	while (cin >> n){
		for (int i = 0; i < nums[n].size(); i++) cout << setfill('0') << setw(n) << nums[n][i] << endl;
	}
	

}
