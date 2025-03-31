import sys

input = sys.stdin.readline


def main() -> None:
    N, M = map(int, input().rstrip('\n').split(' '))
    arr = list(map(int, input().rstrip('\n').split(' ')))

    psum = [0] * (N + 1)
    for i in range(1, N + 1):
        psum[i] = psum[i - 1] + arr[i - 1]  # 구간 합 저장

    for _ in range(M):
        i, j = map(int, input().rstrip('\n').split(' '))
        print(psum[j] - psum[i - 1])


if __name__ == "__main__":
    main()
