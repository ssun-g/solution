import sys

input = sys.stdin.readline


def main() -> None:
    N = int(input().rstrip("\n"))
    arr = sorted([int(input().rstrip("\n")) for _ in range(N)])

    for a in arr:
        print(a)


if __name__ == "__main__":
    main()
