import sys

input = sys.stdin.readline


def main() -> None:
    N = int(input().rstrip('\n'))
    rope = [int(input().rstrip('\n')) for _ in range(N)]
    rope.sort(reverse=True)

    weights = [0] * N
    for i in range(N):
        weights[i] = rope[i] * (i + 1)

    print(max(weights))


if __name__ == "__main__":
    main()
