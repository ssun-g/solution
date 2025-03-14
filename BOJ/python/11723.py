import sys


def main() -> None:
    input = sys.stdin.readline

    M = int(input().rstrip('\n'))

    S = 0
    for _ in range(M):
        order = input().rstrip('\n').split(' ')
        cmd = order[0]
        x = int(order[1]) if len(order) == 2 else None

        if cmd == "add":
            S |= (1 << x)
        elif cmd == "remove":
            S &= ~(1 << x)
        elif cmd == "check":
            if S & (1 << x):  # 해당 숫자가 있으면
                print(1)
            else:
                print(0)
        elif cmd == "toggle":
            S ^= (1 << x)
        elif cmd == "all":
            S = (1 << 21) - 2  # 0은 제외
        elif cmd == "empty":
            S = 0


if __name__ == "__main__":
    main()
