#include<cstdio>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;

int r, c, k;
int r_length = 3;
int c_length = 3;
int arr[100][100];
vector<vector<int> > nArr;


bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

void R_cal(int rlen, int clen) {
	int c_len = -1;
	vector<int> v;
	vector<pair<int, int> > vp;
	vector<vector<pair<int, int> > > vvp;
	for (int i = 0; i < rlen; i++) {
		int zero_cnt = 0;
		int cnt = 0;
		for (int j = 0; j < clen; j++) {
			if (arr[i][j] == 0) {
				zero_cnt++;
				continue;
			}
			v.push_back(arr[i][j]);
		}
		sort(v.begin(), v.end());

		int tmp = v[0];
		for (int j = 0; j < clen - zero_cnt; j++) {
			if (tmp != v[j]) {
				vp.push_back(make_pair(tmp, cnt));
				tmp = v[j];
				cnt = 0;
			}
			cnt++;
		}
		vp.push_back(make_pair(tmp, cnt));

		int vp_size = vp.size();
		c_len = max(c_len, vp_size * 2);
		if (c_len > 50) c_len = 50;

		sort(vp.begin(), vp.end(), cmp);
		vvp.push_back(vp);
		vp.clear();
		v.clear();
	}

	for (int i = 0; i < rlen; i++) {
		int vvpsize = vvp[i].size();
		for (int j = 0; j < vvpsize; j++) {
			v.push_back(vvp[i][j].first);
			v.push_back(vvp[i][j].second);
		}
		for (int k = vvpsize * 2; k < c_len; k++) {
			v.push_back(0);
		}
		nArr.push_back(v);
		v.clear();
	}

	for (int i = 0; i < nArr.size(); i++) {
		for (int j = 0; j < nArr[i].size(); j++) {
			arr[i][j] = nArr[i][j];
		}
	}

	c_length = c_len;
}

void C_cal(int rlen, int clen) {
	int r_len = -1;
	vector<int> v;
	vector<pair<int, int> > vp;
	vector<vector<pair<int, int> > > vvp;

	for (int i = 0; i < clen; i++) {
		int zero_cnt = 0;
		int cnt = 0;
		for (int j = 0; j < rlen; j++) {
			if (arr[j][i] == 0) {
				zero_cnt++;
				continue;
			}
			v.push_back(arr[j][i]);
		}
		sort(v.begin(), v.end());

		int tmp = v[0];
		for (int j = 0; j < rlen - zero_cnt; j++) {
			if (tmp != v[j]) {
				vp.push_back(make_pair(tmp, cnt));
				tmp = v[j];
				cnt = 0;
			}
			cnt++;
		}
		vp.push_back(make_pair(tmp, cnt));

		int vp_size = vp.size();
		r_len = max(r_len, vp_size * 2);
		if (r_len > 50) r_len = 50;

		sort(vp.begin(), vp.end(), cmp);
		vvp.push_back(vp);
		vp.clear();
		v.clear();
	}

	for (int i = 0; i < clen; i++) {
		int vvpsize = vvp[i].size();
		for (int j = 0; j < vvpsize; j++) {
			v.push_back(vvp[i][j].first);
			v.push_back(vvp[i][j].second);
		}
		for (int k = vvpsize * 2; k < r_len; k++) {
			v.push_back(0);
		}
		nArr.push_back(v);
		v.clear();
	}

	for (int i = 0; i < nArr.size(); i++) {
		for (int j = 0; j < nArr[i].size(); j++) {
			arr[j][i] = nArr[i][j];
		}
	}

	r_length = r_len;
}

int main() {
	int cnt = 0;
	scanf("%d %d %d", &r, &c, &k);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	while (cnt <= 100) {
		if (arr[r - 1][c - 1] == k) break;
		if (c_length <= r_length) R_cal(r_length, c_length);
		else C_cal(r_length, c_length);
		nArr.clear();
		cnt++;
	}

	(cnt > 100) ? printf("-1\n") : printf("%d\n", cnt);

	return 0;
}