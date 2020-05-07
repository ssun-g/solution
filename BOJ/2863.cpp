#include<cstdio>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;

vector<pair<double, int>> v;
pair <double, int> p;

double arr[2][2];
double Max;
int idx;

int main() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			scanf("%lf", &arr[i][j]);
		}
	}
	p.first = (arr[0][0] / arr[1][0]) + (arr[0][1] / arr[1][1]);
	p.second = 0;
	v.push_back(p);

	p.first = (arr[1][0] / arr[1][1]) + (arr[0][0] / arr[0][1]);
	p.second = 1;
	v.push_back(p);

	p.first = (arr[1][1] / arr[0][1]) + (arr[1][0] / arr[0][0]);
	p.second = 2;
	v.push_back(p);

	p.first = (arr[0][1] / arr[0][0]) + (arr[1][1] / arr[1][0]);
	p.second = 3;
	v.push_back(p);

	Max = v[0].first;
	idx = v[0].second;
	for (int i = 1; i < v.size(); i++) {
		if (Max < v[i].first) {
			Max = v[i].first;
			idx = v[i].second;
		}
	}
	printf("%d\n", idx);

	return 0;
}
