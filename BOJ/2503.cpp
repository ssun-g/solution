#include<bits/stdc++.h>
using namespace std;

int baseball[100][3];
int arr[3];
int arr2[3];

int main() {
	int tc;
	int num, strike, ball;
	int answer = 0;
	scanf("%d", &tc);
	for (int t = 0; t < tc; t++) { // input
		scanf("%d %d %d", &num, &strike, &ball);
		baseball[t][0] = num;
		baseball[t][1] = strike;
		baseball[t][2] = ball;
	}

	for (int i = 123; i <= 987; i++) { // play the game
		arr[0] = i / 100;
		arr[1] = (i / 10) % 10;
		arr[2] = i % 10;
		if (arr[0] == arr[1] || arr[0] == arr[2] || arr[1] == arr[2]
			|| arr[0] == 0 || arr[1] == 0 || arr[2] == 0)
			continue;

		bool flag = true;
		for (int j = 0; j < tc; j++) {
			int num_of_strike = 0;
			int num_of_ball = 0;
			arr2[0] = baseball[j][0] / 100;
			arr2[1] = (baseball[j][0] / 10) % 10;
			arr2[2] = baseball[j][0] % 10;
			for (int k = 0; k < 3; k++) {
				for (int l = 0; l < 3; l++) {
					if (arr[k] == arr2[l]) {
						if (k == l) num_of_strike++;
						else num_of_ball++;
					}
				}
			}
			if (baseball[j][1] != num_of_strike || baseball[j][2] != num_of_ball) {
				flag = false;
				break;
			}
		}
		if (flag) answer++;
	}

	printf("%d\n", answer);

	return 0;
}