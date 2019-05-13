#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct bld{
	int l; int r; int h;
};

int main() {
	int l, h, r;
	vector<bld> a;
	while(cin >> l >> h >> r){
		bld b; b.l = l; b.h = h; b.r = r;
		a.push_back(b);
	}
	int ch = 0, sp = 1;
	bool d = false;
	for (int i = 1; i <= 1e4; i++){
		int max_height = 0;
		for (int j = 0; j < a.size(); j++){
			if (a[j].l > i) break;
			if (a[j].l <= i && a[j].r > i){
				max_height = max(max_height, a[j].h);
			}
		}
		if (max_height != ch){
			if (d) cout << " ";
			cout << i << " " << max_height;
			ch = max_height;
			d = true;
		}
	}
	cout << endl;
}
