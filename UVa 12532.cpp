#include <bits/stdc++.h>
using namespace std;

class ST{
	public:
		int left(int p) {
			return p << 1;
		}
		int right(int p){
			return (p << 1) + 1;
		}
		vector<int> st; int n;
		ST(int n){
			this->n = n;
			st.assign(4 * n, 0);
		}
		void build(int p, int L, int R, vector<int> & val){
			if (L == R){
				st[p] = val[L];
			}
			else{
				build(left(p), L, (L + R) / 2, val);
				build(right(p), (L + R) / 2 + 1, R, val);
				st[p] = st[left(p)] * st[right(p)];
			}
		}
		void update(int p, int L, int R, int idx, int val){
			if (L > idx || R < idx) return;
			if (L == R){
				st[p] = val;
				return;
			}
			update(left(p), L, (L + R) / 2, idx, val);
			update(right(p), (L + R) / 2 + 1, R, idx, val);
			st[p] = st[left(p)] * st[right(p)];
		}
		int rpq(int p, int L, int R, int UL, int UR){
			if (L > UR || R < UL) return 1;
			if (L >= UL && R <= UR){
				return st[p];
			}
			return rpq(left(p), L, (L + R) / 2, UL, UR) * rpq(right(p), (L + R) / 2 + 1, R, UL, UR);
		}
};


int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, k;
	while (cin >> n >> k){
		vector<int> values( n + 1);
		for (int i = 1; i <= n; i++){
			int v; cin >> v;
			if (v < 0) v = -1;
			else if (v > 0) v = 1;
			values[i] = v;
		}
		ST st(n + 5); st.build(1, 1, n, values);
		string result;
		for (int i = 0; i < k; i++){
			char type; int a, b;
			cin >> type >> a >> b;
			if (type == 'C'){
				int what = 0;
				if (b < 0) what = -1;
				else if (b > 0) what = 1;
				st.update(1, 1, n, a, what);
			}
			if (type == 'P'){
				int ans = st.rpq(1, 1, n, a, b);
				if (ans < 0){
					result += '-';
				}
				else if (ans > 0){
					result += '+';
				}
				else{
					result += '0';
				}
			}
		}
		cout << result << endl;
	}
}
