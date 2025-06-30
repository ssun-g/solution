import sys

input = sys.stdin.readline


def main() -> None:
    x = int(input().rstrip('\n'))
    y = int(input().rstrip('\n'))
    print(x + y + 3)


if __name__ == "__main__":
    main()
