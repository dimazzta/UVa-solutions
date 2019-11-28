#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

int result(int n){
	deque<int> dq;
	for (int i = 1; i <= n; i++){
		dq.push_back(i);
	}
	while(dq.size() > 1){
		dq.pop_front();
		int el = dq.front();
		dq.push_back(el);
		dq.pop_front();
	}
	return dq.front();
}

int main(){
	
	int n; 
	while(cin >> n, n){
		int dif = 0;
		int k = 0;
		while ((1 << k++) < n);
		k--;
		dif = (1 << k) - n;
		cout << (1 << k) - dif * 2 << endl; 
	}
	
	//for (int  i = 1; i <= 60; i++){
//		cout << "n = " << i << ": " << result(i) << endl;
//	}
	return 0;
}

