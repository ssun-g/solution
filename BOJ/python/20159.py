import sys

input = sys.stdin.readline


def main() -> None:
    N = int(input().rstrip("\n"))
    cards = list(map(int, input().rstrip("\n").split(" ")))

    total = sum(cards[::2])

    val1 = val2 = total
    for i in range(N - 1, 0, -1):
        # 내 차례에 밑장 빼기
        if i % 2 != 0:
            val1 += cards[i]
            val1 -= cards[i - 1]

        # 상대 차례에 밑장 빼기
        else:
            val2 -= cards[i]
            val2 += cards[i - 1]

        total = max(val1, val2, total)

    print(total)


if __name__ == "__main__":
    main()
