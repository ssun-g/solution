#include<cstdio>
using namespace std;

long long mul(long long A, long long B, long long C) {
	if (B == 0) return 1;

	long long ret = mul(A, B / 2, C);
	ret = ret*ret%C;
	if (B % 2 == 0) return ret;
	else return (ret*A) % C;
}

int main() {
	long long A, B, C;
	scanf("%lld %lld %lld", &A, &B, &C);
	printf("%lld", mul(A, B, C));

	return 0;
}