import sys

input = sys.stdin.readline


def main() -> None:
    S = input().rstrip('\n')
    arr = [S[i:] for i in range(len(S))]
    arr.sort()
    for a in arr:
        print(a)


if __name__ == "__main__":
    main()
