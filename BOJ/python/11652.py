import sys

input = sys.stdin.readline


def main() -> None:
    N = int(input().rstrip("\n"))

    cards = {}
    for _ in range(N):
        n = int(input().rstrip("\n"))
        if n in cards:
            cards[n] += 1
        else:
            cards[n] = 1

    cards = sorted(cards.items(), key=lambda x: (-x[1], x[0]))
    print(cards[0][0])

if __name__ == "__main__":
    main()
