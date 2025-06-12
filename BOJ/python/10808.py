import sys

input = sys.stdin.readline


def main() -> None:
    S = input().rstrip("\n")

    alpha = [0] * 26
    for c in S:
        alpha[ord(c) - ord("a")] += 1

    print(*alpha)


if __name__ == "__main__":
    main()
