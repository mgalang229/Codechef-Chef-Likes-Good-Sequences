#include <bits/stdc++.h>
using namespace std;

void TestCase() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int len = 1; // initial value is 1 because it has no previous adjacent element
	for(int i = 1; i < n; i++) { // find the initial longest good subsequence
		len += (a[i] != a[i-1]);
	}
	for(int i = 0; i < q; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		// formula below: length = length - previous contributions + new contributions
		if(x != 0) { // not the first element (a[i] != a[0])
			len = len - (a[x] != a[x-1]); // remove contributions
			len = len + (y != a[x-1]); // add new contributions (if there are)
		}
		if(x != n - 1) { // not the last element (a[i] != a[n-1])
			len = len - (a[x] != a[x+1]); // remove contributions
			len = len + (y != a[x+1]); // add new contributions (if there are)
		}
		a[x] = y; // update the value at index x
		cout << len << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc = 1;
	cin >> tc;
	for(int t = 0; t < tc; t++) {
		TestCase();
	}
	return 0;
}

