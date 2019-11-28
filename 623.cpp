#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

const int nax = 5000;

int main(){
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	vector<vi> nums(1001, vi(nax));
	nums[0][0] = 1;
	for (int i = 1; i <= 1000; i++){
		for (int j = 0; j < nax; j++){
			nums[i][j] = nums[i - 1][j] * i;
		}
		for (int j = 0; j < nax - 1; j++){
			nums[i][j + 1] += nums[i][j] / 10;
			nums[i][j] %= 10;
		}
	}
	
	int n; 
	while(cin >> n){
		int st = 4999;
		cout << n << "!" << endl;
		while(nums[n][st] == 0) st--;
		for (; st >= 0; st--) cout << nums[n][st];
		cout << endl;
	}
	return 0;
}


