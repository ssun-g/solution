// 전체를 세 부분으로 나누어 최댓값을 계산한다.
// 1. 왼쪽, 2. 오른쪽, 3. 왼쪽, 오른쪽에 걸치는 중간 부분
#include<bits/stdc++.h>
using namespace std;

int N;
long long arr[100001];

long long dnc(int left, int right) {
	if (left == right) return arr[left] * arr[left];

	// 왼쪽 부분, 오른쪽 부분에서 구한 최댓값을 ret에 저장한다.
	int mid = (left + right) / 2;
	long long ret = max(dnc(left, mid), dnc(mid + 1, right));

	// 왼쪽, 오른쪽에 걸쳐 있는 부분중 가장 크기가 작은 부분 배열을 계산해본다.
	int lo = mid, hi = mid + 1;
	long long sum = arr[mid] + arr[mid + 1];
	long long minValue = min(arr[mid], arr[mid + 1]);
	ret = max(ret, sum * minValue);

	// 점점 부분 배열의 크기를 늘려가며 최댓값을 찾는다.
	// 항상 값이 커지는 쪽으로 증가하기 때문에 여러번 탐색할 필요가 없다.
	while (left < lo || hi < right) {
		// 왼쪽 끝까지 도달했거나 현재 노드의 오른쪽 노드가 왼쪽 노드보다 클 경우
		// 오른쪽 노드를 추가해본다.
		if (hi < right && (lo == left || arr[lo - 1] < arr[hi + 1])) {
			sum += arr[++hi];
			minValue = min(minValue, arr[hi]);
		}

		// 아닐 경우 왼쪽 노드를 추가해본다.
		else {
			sum += arr[--lo];
			minValue = min(minValue, arr[lo]);
		}
		ret = max(ret, sum * minValue);
	}

	return ret;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	cout << dnc(0, N);

	return 0;
}