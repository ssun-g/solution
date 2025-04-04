"""
XOR의 성질을 알면 쉽게 풀 수 있다.
- X ^ X = 0
- X ^ 0 = X
"""
import sys

input = sys.stdin.readline


def main() -> None:
    N, Q = map(int, input().rstrip('\n').split(' '))
    arr = list(map(int, input().rstrip('\n').split(' ')))

    # 구간 합(XOR) 구하기
    psum = [0] * (N + 1)
    for i in range(N):
        psum[i + 1] = psum[i] ^ arr[i]

    # 출력
    answer = 0
    for _ in range(Q):
        s, e = map(int, input().rstrip('\n').split(' '))
        answer ^= (psum[e] ^ psum[s - 1])

    print(answer)


if __name__ == "__main__":
    main()
