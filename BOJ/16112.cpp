/*

최대 활성화 할 수 있는 아케인스톤은 k개 이다.
경험치를 가장 많이 얻으려면 경험치를 적게 얻을 수 있는 먼저 깨면서 아케인스톤을 바로바로 활성화 해줘야 한다.
퀘스트를 통해 얻을 수 있는 경험치를 기준으로 오름차순 정렬을 하고
k개까지 아케인스톤을 활성화 하면서 경험치를 쌓아주었다.

!주의!
활성화 된 아케인스톤의 개수를 세어주는 변수도 long long으로 처리를 해주자.

*/
#include<bits/stdc++.h>
using namespace std;

int stone[300001];

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> stone[i];
	}
	sort(stone, stone + n);

	long long answer = 0;
	int act_stone = 0;
	for (int i = 0; i < n; i++) {
		answer += act_stone*(long long)stone[i]; // 퀘스를 깨고 아케인스톤에 경험치를 저장하자.
		if (act_stone < k) act_stone++; // 활성화 된 아케인스톤이 k개 보다 적다면 아케인스톤을 활성화 시켜준다.
	}
	cout << answer << '\n';

	return 0;
}
