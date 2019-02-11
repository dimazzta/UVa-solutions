#include <bits/stdc++.h>
using namespace std;

int main() {
	long long a;
	vector<long long> vec;
	while (scanf("%lld", &a) == 1) {
		vec.push_back(a);
		sort(vec.begin(), vec.end());
		if (vec.size() % 2 == 0) {
			cout << (vec[vec.size() / 2 - 1] + vec[vec.size() / 2]) / 2 << endl;
		}
		else {
			cout << vec[vec.size() / 2] << endl;
		}
	}

}
