"""
1, 2, 3 세 가지 경우만 등장하며, 개수를 누적합으로 카운팅 해준다.
"""
import sys

input = sys.stdin.readline


def main() -> None:
    N, Q = map(int, input().rstrip('\n').split(' '))
    cows = [int(input().rstrip('\n')) for _ in range(N)]

    # 구간 합 구하기
    holsteins = [0] * (N + 1)
    guernseys = [0] * (N + 1)
    jerseys = [0] * (N + 1)
    for i in range(N):
        if cows[i] == 1:
            holsteins[i + 1] = holsteins[i] + 1
            guernseys[i + 1] = guernseys[i]
            jerseys[i + 1] = jerseys[i]
        elif cows[i] == 2:
            holsteins[i + 1] = holsteins[i]
            guernseys[i + 1] = guernseys[i] + 1
            jerseys[i + 1] = jerseys[i]
        else:
            holsteins[i + 1] = holsteins[i]
            guernseys[i + 1] = guernseys[i]
            jerseys[i + 1] = jerseys[i] + 1

    # 출력
    for _ in range(Q):
        a, b = map(int, input().rstrip('\n').split(' '))
        print(holsteins[b] - holsteins[a - 1], guernseys[b] - guernseys[a - 1], jerseys[b] - jerseys[a - 1])


if __name__ == "__main__":
    main()
