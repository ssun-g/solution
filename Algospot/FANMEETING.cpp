#include<bits/stdc++.h>
using namespace std;

// 단순 곱셈. a*b의 결과 값이 reverse되어 vector에 저장.
// ex) 123*456 = 56088 = [8, 8, 0, 6, 5]
vector<int> multiply(const vector<int>& a, const vector<int>& b) {
	vector<int> ret(a.size() + b.size() + 1, 0);
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			ret[i + j] += (a[i] * b[j]);
		}
	}

	return ret;
}

// a += b*(10^k)
void addTo(vector<int>& a, const vector<int>& b, int k) {
	a.resize(max(a.size(), b.size() + k));
	for (int i = 0; i < b.size(); i++) {
		a[i + k] += b[i];
	}
}

// a -= b
void subFrom(vector<int>& a, const vector<int>& b) {
	a.resize(max(a.size(), b.size()));
	for (int i = 0; i < b.size(); i++) {
		a[i] -= b[i];
	}
}


vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
	int alen = a.size();
	int blen = b.size();
	if (alen < blen) return karatsuba(b, a);
	if (alen == 0 || blen == 0) return vector<int>();
	if (alen <= 50) return multiply(a, b);

	int mid = alen / 2;
	vector<int> a0(a.begin(), a.begin() + mid);
	vector<int> a1(a.begin() + mid, a.end());
	vector<int> b0(b.begin(), b.begin() + min((int)b.size(), mid));
	vector<int> b1(b.begin() + min((int)b.size(), mid), b.end());

	vector<int> z2 = karatsuba(a1, b1);
	vector<int> z0 = karatsuba(a0, b0);
	addTo(a0, a1, 0);
	addTo(b0, b1, 0);
	vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);

	vector<int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, mid);
	addTo(ret, z2, mid + mid);

	return ret;
}

int hugs(const string& members, const string& fans) {
	int n = members.size();
	int m = fans.size();
	int ret = 0;
	vector<int> mem(n), fan(m);
	for (int i = 0; i < n; i++) {
		if (members[i] == 'M') mem[i] = 1;
		else mem[i] = 0;
	}

	for (int i = 0; i < m; i++) {
		if (fans[i] == 'M') fan[m - (i + 1)] = 1;
		else fan[m - (i + 1)] = 0;
	}

	vector<int> kar = karatsuba(mem, fan);
	for (int i = n - 1; i < m; i++) {
		if (kar[i] == 0) ret++;
	}

	return ret;
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		string members, fans;
		cin >> members >> fans;
		cout << hugs(members, fans) << '\n';
	}

	return 0;
}