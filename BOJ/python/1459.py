"""
1. 가로, 세로 이동 시간 W
2. 대각선 이동 시간 S

조건 분기
1. 2W <= S 이면 대각선으로 이동할 필요가 없음
2. W > S 이면 가로, 세로로 이동할 필요가 없음
2-1. 이동 횟수가 짝수인 경우 대각선 이동만으로 목적지에 도달 가능
2-2. 이동 횟수가 홀수인 경우 대각선 이동으로 (X, Y-1) 또는 (X-1, Y)까지만 도달 가능
3. 2W > S 이면 대각선으로 이동하는 것이 더 빠름. 대각선 이동 후 가로 or 세로로 이동하는 것을 한 세트로 본다.
"""
import sys

input = sys.stdin.readline


def main() -> None:
    X, Y, W, S = map(int, input().rstrip('\n').split(' '))
    if 2 * W <= S:  # 가로, 세로로만 이동
        print((X + Y) * W)
    elif W > S:  # 대각선으로만 이동
        if abs(X - Y) % 2 == 0:  # 이동 거리가 짝수
            diag_move = max(X, Y) * S  # 짝수인 경우 max(X, Y)만큼 대각선으로 이동하면 목적지 도달 가능
            print(diag_move)
        else:
            diag_move = (max(X, Y) - 1) * S
            print(diag_move + W)  # 가로, 세로로 1번 이동하면 목적지에 도달 가능
    elif 2 * W > S:  # 대각선, 가로, 세로로 모두 이동해야 함.
        diag_move = min(X, Y) * S  # min(X, Y) 만큼 대각선으로 이동 가능
        cross_move = abs(X - Y) * W  # abs(X - Y) 만큼 가로, 세로로 이동 가능
        print(diag_move + cross_move)


if __name__ == "__main__":
    main()
