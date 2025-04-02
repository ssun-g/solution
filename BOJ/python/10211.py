import sys

input = sys.stdin.readline


def main() -> None:
    T = int(input().rstrip('\n'))
    for _ in range(T):
        N = int(input().rstrip('\n'))
        arr = list(map(int, input().rstrip('\n').split(' ')))

        # 구간 합 구하기
        psum = [0] * (N + 1)
        for i in range(N):
            psum[i + 1] = psum[i] + arr[i]

        # 최대 부분배열 구하기
        max_sub = -1001
        for i in range(N + 1):
            for j in range(i + 1, N + 1):
                max_sub = max(max_sub, psum[j] - psum[i])

        print(max_sub)


if __name__ == "__main__":
    main()
