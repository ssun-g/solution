"""
1. 같은 숫자를 받았으면 상대방의 패는 1~10중 받은 숫자를 제외하고 모두 가능
2. 다른 숫자를 받았으면 상대방의 패는 1~10까지 가능
3. 상대방 패가 가능한 모든 조합을 확인
"""
import sys
from itertools import combinations

input = sys.stdin.readline


def main() -> None:
    A, B = map(int, input().rstrip('\n').split(' '))
    card = []

    # 전체 패 만들기
    for i in range(1, 11):
        card += [i] * 2

    # 받은 패 지우기
    card.remove(A)
    card.remove(B)

    win = 0
    lose = 0
    draw = 0
    for comb in combinations(card, 2):
        C, D = comb
        # 땡 vs 땡
        if A == B and C == D:
            if A < C:
                lose += 1
            else:
                win += 1

        # 땡 vs 끗
        elif A == B and C != D:
            win += 1

        # 끗 vs 땡
        elif A != B and C == D:
            lose += 1

        # 끗 vs 끗
        else:
            if ((A + B) % 10) < ((C + D) % 10):
                lose += 1
            elif ((A + B) % 10) == ((C + D) % 10):
                draw += 1
            else:
                win += 1

    print(f"{win / (win + draw + lose):.3f}")


if __name__ == "__main__":
    main()
