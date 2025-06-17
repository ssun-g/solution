import sys

input = sys.stdin.readline


def main() -> None:
    N = int(input().rstrip('\n'))

    result = []
    for i in range(2, N + 1):
        # i로 나누어 떨어지는 경우
        while N % i == 0:
            result.append(i)
            N //= i

    for r in sorted(result):
        print(r)


if __name__ == "__main__":
    main()
