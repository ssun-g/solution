from itertools import *
from bisect import bisect_left


def dice_cases(picked: list) -> list:
    d = [0, 1, 2, 3, 4, 5]  # 가능한 주사위 번호
    result = {}
    for comb in product(d, repeat=len(picked)):
        s = 0
        for i, c in enumerate(comb):
            s += picked[i][c]

        if s in result:
            result[s] += 1
        else:
            result[s] = 1

    return result


def simulation(a_score, b_score):
    a_items = sorted(a_score.items())  # [(score, count)]
    b_items = sorted(b_score.items())  # [(score, count)]

    # b_score의 누적합 계산 (score 오름차순)
    b_scores = [score for score, _ in b_items]
    b_counts = [count for _, count in b_items]

    b_psum = [0] * len(b_counts)
    b_psum[0] = b_counts[0]
    for i in range(1, len(b_counts)):
        b_psum[i] = b_psum[i - 1] + b_counts[i]

    total = 0
    win = 0

    for a_val, a_cnt in a_items:
        # b_score에서 a_val보다 작은 점수의 총합(a가 이기는 횟수)
        idx = bisect_left(b_scores, a_val)
        if idx > 0:
            win += a_cnt * b_psum[idx - 1]
        total += a_cnt * sum(b_counts)

    return win / total


def solution(dice):
    answer = []
    max_winning_rate = 0

    # 주사위 고르기
    for comb in combinations(range(len(dice)), len(dice) // 2):
        # a의 주사위 조합 구하기
        a_pick = [dice[i] for i in comb]
        a_score = dice_cases(a_pick)

        # b의 주사위 조합 구하기
        b_pick = [dice[i] for i in range(len(dice)) if i not in comb]
        b_score = dice_cases(b_pick)

        # 승패 구하기
        p_win_rate = simulation(a_score, b_score)

        # 가장 높은 승률일 때, A가 고른 주사위 구하기
        if max_winning_rate < p_win_rate:
            max_winning_rate = p_win_rate
            answer = list(comb)

    for i in range(len(answer)):
        answer[i] += 1

    return answer
