import sys

input = sys.stdin.readline


def main() -> None:
    word = input().rstrip("\n")
    print(len(word))


if __name__ == "__main__":
    main()
