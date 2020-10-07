#include<cstdio>
#include<utility>
using namespace std;

pair<long long, long long> zero(int n) {
	long long two = 0, five = 0;
	for (long long i = 2; i <= n; i *= 2) two += n / i;
	for (long long i = 5; i <= n; i *= 5) five += n / i;

	return make_pair(two, five);
}

int main() {
	pair<long long, long long> nz, mz, nmz;
	int n, m;
	scanf("%d %d", &n, &m);

	nz = zero(n);
	mz = zero(m);
	nmz = zero(n - m);

	long long two = nz.first - (mz.first + nmz.first);
	long long five = nz.second - (mz.second + nmz.second);
	long long answer = (two < five) ? two : five;
	printf("%lld\n", answer);

	return 0;
}