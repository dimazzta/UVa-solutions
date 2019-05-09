#include <bits/stdc++.h>
using namespace std;

class BIT{
	public:
		int LBIT(int p){
			return p & (-p);
		}
		vector<int> ft; int n;
		BIT(int n){
			ft.assign(n + 1, 0);
			this->n = n;
		}
		void update(int idx, int value){
			int current = rsq(idx, idx);
			int diff = value - current;
			for (int i = idx; i <= n; i += LBIT(i)){
				ft[i] += diff;
			}
		}
		int rsq (int b){
			if (b == 0) return 0;
			int sum = 0;
			for (int i = b; i >= 1; i -= LBIT(i)){
				sum += ft[i];
			}
			return sum;
		}
		int rsq(int a, int b){
			return rsq(b) - rsq(a - 1);
		}
		void print(){
			for (int i = 1; i <= n; i++){
				cout << ft[i] << " ";
			}
		}
};

int main(){
	int n;
	int c = 1;
	while (true){
		cin >> n;
		
		if (n == 0) break;
		
		if (c > 1) cout << endl;
		cout << "Case " << c++ << ":" << endl;
		BIT bit(n);
		for (int i = 1; i <= n; i++){
			int v;
			cin >> v;
			bit.update(i, v);
		}
		for (; ; ){
			string t; int a, b;
			cin >> t;
			if (t == "END") break;
			cin >> a >> b;
			if (t == "M"){
				int ans = bit.rsq(a, b);
				cout << ans << endl;
			}
			else {
				bit.update(a, b);
			}
		}
	}
}
