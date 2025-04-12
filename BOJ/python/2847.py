import sys

input = sys.stdin.readline


def main() -> None:
    N = int(input().rstrip('\n'))
    score = [int(input().rstrip('\n')) for _ in range(N)]

    answer = 0
    comp_score = score[-1] - 1  # 이전 레벨의 점수가 comp_score가 되어야 함.
    for i in range(len(score) - 2, -1, -1):
        if comp_score < score[i]:  # 점수가 비교 대상보다 높으면 -> 점수를 감소시켜야 함
            answer += abs(comp_score - score[i])
            comp_score -= 1
        else:  # 점수가 이미 낮은 경우 감소 시킬 필요가 없음
            comp_score = score[i] - 1

    print(answer)


if __name__ == "__main__":
    main()
