"""
구간 합 범위에 주의
"""
import sys

input = sys.stdin.readline


def main() -> None:
    N, Q = map(int, input().rstrip('\n').split(' '))
    arr = list(map(int, input().rstrip('\n').split(' ')))

    # 구간 합 구하기
    psum = [0] * (N + 1)
    for i in range(1, N):
        psum[i] = abs(arr[i] - arr[i - 1]) + psum[i - 1]

    # 출력
    for _ in range(Q):
        i, j = map(int, input().rstrip('\n').split(' '))
        if j - 1 < i:
            print(0)
        else:
            print(psum[j - 1] - psum[i - 1])


if __name__ == "__main__":
    main()
