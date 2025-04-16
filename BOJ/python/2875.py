import sys

input = sys.stdin.readline


def main() -> None:
    N, M, K = map(int, input().rstrip('\n').split(' '))
    max_team = min(N // 2, M)
    remain = (N + M) - max_team * 3

    if K <= remain:
        print(max_team)
    else:
        if ((K - remain) % 3) == 0:
            except_team = ((K - remain) // 3)
        else:
            except_team = ((K - remain) // 3) + 1

        print(max_team - except_team)


if __name__ == "__main__":
    main()
