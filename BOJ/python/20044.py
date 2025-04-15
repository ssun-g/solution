"""
코딩 역량의 합을 일정하게 유지
=> 코딩역량이 가장 낮은 학생과 가장 높은 학생이 팀을 이루어야 함
"""
import sys

input = sys.stdin.readline


def main() -> None:
    n = int(input().rstrip('\n'))
    ability = list(map(int, input().rstrip('\n').split(' ')))
    ability.sort()

    min_sum = 200001
    for i in range(2 * n):
        min_sum = min(min_sum, ability[i] + ability[2 * n - (i + 1)])

    print(min_sum)


if __name__ == "__main__":
    main()
