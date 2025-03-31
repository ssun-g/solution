"""
11659번과 거의 똑같은 문제
"""
import sys

input = sys.stdin.readline


def main() -> None:
    N = int(input().rstrip('\n'))
    arr = list(map(int, input().rstrip('\n').split(' ')))
    M = int(input().rstrip('\n'))

    psum = [0] * (N + 1)
    for i in range(N):
        psum[i + 1] = psum[i] + arr[i]

    for _ in range(M):
        i, j = map(int, input().rstrip('\n').split(' '))
        print(psum[j] - psum[i - 1])


if __name__ == "__main__":
    main()
