#include <bits/stdc++.h>
using namespace std;
int main() {
	int h, d, f;
	double u;
	while (true) {
		cin >> h >> u >> d >> f;
		if (h == 0) break;
		int day = 1;
		double rate = (double)u * f / 100;
		double cur_h = 0;
		while (true) {
			cur_h += u;
			if (cur_h > h) {
				cout << "success on day " + to_string(day) << endl;
				break;
			}
			cur_h -= d;
			if (cur_h < 0) {
				cout << "failure on day " + to_string(day) << endl;
				break;
			}
			u -= rate;
			if (u < 0) u = 0;
			day++;
		}
	}
}
