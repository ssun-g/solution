#include<bits/stdc++.h>
using namespace std;

priority_queue<int> pq; // ������ ��ġ������ �������� ����
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > jewel; // ������ ���� ���� (���԰� ������ ������ �������� ����)
vector<int> bags; // ������ ���� ���� (���԰� ������ ������ �������� ����)

int main() {
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) { // ���� ���� �Է�
		int m, v;
		cin >> m >> v;
		jewel.push(make_pair(m, v));
	}

	for (int i = 0; i < K; i++) { // ���� ���� �Է�
		int bag;
		cin >> bag;
		bags.push_back(bag);
	}
	sort(bags.begin(), bags.end());

	long long answer = 0;
	for (int i = 0; i < K; i++) {
		while (!jewel.empty() && jewel.top().first <= bags[i]) { // ���� ���溸�� ������ ������� �켱����ť�� �־��ش�.
			pq.push(jewel.top().second);
			jewel.pop();
		}

		if (!pq.empty()) { // �켱����ť���� ������ �ϳ��� ������ ��ġ�� �����ش�.
			answer += pq.top();
			pq.pop();
		}

		else if (jewel.empty()) break; // ���� ������ ������ ����
	}

	cout << answer << '\n';

	return 0;
}