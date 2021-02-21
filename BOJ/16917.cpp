#include <bits/stdc++.h>
using namespace std;

int main() {
	int result = 0;
	int sauce, fried, halfnhalf, X, Y;
	cin >> sauce >> fried >> halfnhalf >> X >> Y;

	if (sauce + fried < 2 * halfnhalf) result += sauce*X + fried*Y;
	else {
		result += halfnhalf * 2 * min(X, Y);
		if (X - Y > 0) {
			if (sauce < 2 * halfnhalf) result += (X - Y)*sauce;
			else result += (X - Y) * 2 * halfnhalf;
		}
		else if (Y - X > 0) {
			if (fried < 2 * halfnhalf) result += (Y - X)*fried;
			else result += (Y - X) * 2 * halfnhalf;
		}
	}
	cout << result << '\n';

	return 0;
}