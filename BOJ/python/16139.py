"""
출력 시, 구간 합의 범위(l, r)에 주의하자.
"""
import sys
import string

input = sys.stdin.readline


# 구간 합 배열 구하기
def make_psum(S: str) -> list:
    psum = {a: [0] * (len(S) + 1) for a in string.ascii_lowercase}
    for i in range(len(S)):
        alpha = S[i]
        for k in psum.keys():
            if k == alpha:
                psum[k][i + 1] = psum[k][i] + 1
            else:
                psum[k][i + 1] = psum[k][i]

    return psum


def main() -> None:
    S = input().rstrip('\n')
    psum = make_psum(S)

    q = int(input().rstrip('\n'))
    for _ in range(q):
        alpha, l, r = input().rstrip('\n').split(' ')
        l = int(l)
        r = int(r)

        print(psum[alpha][r + 1] - psum[alpha][l])


if __name__ == "__main__":
    main()
