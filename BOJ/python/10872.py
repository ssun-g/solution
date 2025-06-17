import sys

input = sys.stdin.readline


def main() -> None:
    N = int(input().rstrip('\n'))

    result = 1
    for i in range(1, N + 1):
        result *= i

    print(result)


if __name__ == "__main__":
    main()
