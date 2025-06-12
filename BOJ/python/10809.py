import sys

input = sys.stdin.readline


def main() -> None:
    S = input().rstrip("\n")

    alpha = [-1] * 26
    for i, c in enumerate(S):
        if alpha[ord(c) - ord("a")] == -1:
            alpha[ord(c) - ord("a")] = i

    print(*alpha)


if __name__ == "__main__":
    main()
