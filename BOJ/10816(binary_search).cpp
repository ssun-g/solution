#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int tmp[500001];
vector<pair<int, int> > card;

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp[i]);
	}
	sort(tmp, tmp + N);

	card.push_back(make_pair(tmp[0], 1));
	for (int i = 1; i < N; i++) {
		if (tmp[i] == card.back().first) card.back().second++;
		else card.push_back(make_pair(tmp[i], 1));
	}

	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int mcard;
		scanf("%d", &mcard);

		int left = 0;
		int right = card.size() - 1;
		int mid;
		bool flag = false;
		while (left <= right) {
			mid = (left + right) / 2;
			if (card[mid].first < mcard) left = mid + 1;
			else if (card[mid].first > mcard) right = mid - 1;
			else {
				flag = true;
				break;
			}
		}
		if (flag) printf("%d ", card[mid].second);
		else printf("0 ");
	}

	return 0;
}