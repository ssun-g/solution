"""
<해당 티어에 도달하기 위한 조건>

지는 횟수 : lose
이기는 횟수 : win

브론즈: lose-win >= 11. 즉, 1000 ~ 501점을 잃어야 함.
실버: 1 <= lose-win < 11. 즉, 500 ~ 1점을 잃어야 함.
골드 :  0 <= win - lose < 10. 즉, 0 ~ 499점을 얻어야 함.
플래티넘 : 10 <= win-lose < 20. 즉, 500 ~ 999점을 얻어야 함.
다이아 : 20판 모두 이겨야 됨.

"""
import sys

input = sys.stdin.readline


def factorial(num):
    if num == 1 or num == 0:
        return 1
    return num * factorial(num - 1)


W, L, D = map(float, input().split(" "))
bronze = 0.0
silver = 0.0
gold = 0.0
platinum = 0.0
dia = W ** 20

for draw in range(21):
    for win in range(21 - draw):
        total_game = 20 - draw  # 무승부일 경우 점수를 얻지 못하므로 무승부 횟수만큼 경기 수를 적게한 것과 같다.
        lose = total_game - win  # 진 횟수 = 전체 경기 - 이긴 경기

        # win, lose, draw를 고르는 경우의 수. win + lose + draw = 20을 만족하는 해의 집합의 개수
        comb = factorial(20) // factorial(win) // factorial(lose) // factorial(draw)

        # 해당 티어에 도달하기 위한 승리, 패배 횟수에 만족하면 확률 값을 계산 후 더해 준다.
        if lose - win >= 11:
            bronze += comb * (W ** win) * (L ** lose) * (D ** draw)
        if (1 <= lose - win) and (lose - win < 11):
            silver += comb * (W ** win) * (L ** lose) * (D ** draw)
        if (0 <= win - lose) and (win - lose < 10):
            gold += comb * (W ** win) * (L ** lose) * (D ** draw)
        if (10 <= win - lose) and (win - lose < 20):
            platinum += comb * (W ** win) * (L ** lose) * (D ** draw)

print(f"{bronze:.8f}")
print(f"{silver:.8f}")
print(f"{gold:.8f}")
print(f"{platinum:.8f}")
print(f"{dia:.8f}")
