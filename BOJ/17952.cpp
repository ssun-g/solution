/*

과제는 가장 최근에 나온 순서대로 진행하며,
새로운 과제가 나오면 하던 과제를 중단하고 새로운 과제를 진행하므로 stack 구조를 사용해야 한다는 것을 알 수 있다.

알고리즘은 다음과 같다.
1. 학기의 모든 timestep마다(1분마다) 과제가 주어졌는지 그렇지 않은지 확인한다.
2. 과제가 주어졌다면 받은 즉시 1분간 과제를 수행하고 해당 과제를 끝내면 과제 점수를 더해주고 stack에 넣지 않는다.
3. 과제가 주어지지 않았다면 가장 최근에 받은 과제를 stack에서 꺼낸 후 1분간 과제를 수행한다. 과제를 끝내면 과제 점수를 더해주고 stack에 넣지 않는다.

*/

#include<bits/stdc++.h>
using namespace std;

// 과제의 점수, 과제를 끝내는 데에 걸리는 시간을 포함하는 class
class Assignment {
public:
	int score;
	int time;

	Assignment(int score, int time) {
		this->score = score;
		this->time = time;
	}
};

stack<Assignment> st;


int main() {
	int answer = 0;
	int N;
	cin >> N;

	// 모든 timestep(1분마다)에 대해서 탐색.
	for (int i = 0; i < N; i++) {
		int flag, score, time;
		cin >> flag;

		// 과제가 주어 졌을 때
		if (flag) {
			cin >> score >> time;

			// 과제를 끝내는 데 1분이 걸린다면 받자마다 끝낼 수 있으므로 바로 과제를 완료한다.
			if (time == 1) answer += score;

			// 그렇지 않으면 과제를 받은 즉시 1분간 과제를 수행하고 stack에 넣어준다.
			else st.push(Assignment(score, time - 1));
		}

		// 과제가 주어지지 않고, stack이 비지 않은 경우
		else if (!st.empty()) {

			// stack에서 가장 최근 과제를 꺼내서 1분간 수행한다.
			Assignment prev = st.top();
			st.pop();
			prev.time--;

			// 과제를 끝냈을 경우 점수를 더해준다.
			if (prev.time == 0) answer += prev.score;

			// 과제를 못 끝낸 경우 다시 과제를 넣어준다.
			else st.push(prev);
		}
	}
	cout << answer << '\n';

	return 0;
}