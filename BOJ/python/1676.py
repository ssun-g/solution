import sys

input = sys.stdin.readline


def main() -> None:
    N = int(input().rstrip('\n'))

    result = 1
    for i in range(1, N + 1):
        result *= i

    cnt = 0
    while result % 10 == 0:  # (10으로 나눈 나머지가 0) == (마지막 자리가 0)
        result //= 10
        cnt += 1

    print(cnt)


if __name__ == "__main__":
    main()
