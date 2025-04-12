"""
1. 꽃이 피는 날짜를 오름차순으로 정렬. (먼저 피는 꽃부터 탐색)
2. 가능한 꽃중 가장 늦게 지는 꽃 선택하기.
3. 12월 1일을 포함하여 그 이후에 꽃이 지는 경우에만 정답
"""
import sys

input = sys.stdin.readline


def main() -> None:
    N = int(input().rstrip('\n'))
    blossom = []
    for _ in range(N):
        sm, sd, em, ed = map(int, input().rstrip('\n').split(' '))
        blossom.append([sm * 100 + sd, em * 100 + ed])

    blossom.sort(key=lambda x: (x[0], x[1]))  # 먼저 피는 꽃 순서로 정렬

    i = 0
    count = 0
    is_possible = False
    latest_date = 301
    while i < N:
        start_date, end_date = blossom[i]

        # 다음 꽃을 선택할 수 있는 경우
        if start_date <= latest_date < end_date:
            new_latest_date = end_date

            while i < N - 1:
                new_start_date, new_end_date = blossom[i + 1]
                # 마지막으로 선택한 꽃이 지기 전에 피는 꽃이 있는지 확인
                if new_start_date <= latest_date:
                    # 선택 가능한 꽃중 가장 늦게 지는 꽃 선택
                    if new_latest_date < new_end_date:
                        new_latest_date = new_end_date
                    i += 1
                else:  # 선택 가능한 꽃이 없는 경우
                    break

            # 마지막 꽃이 지는 날짜 업데이트
            latest_date = new_latest_date
            count += 1

        # 마지막으로 선택한 꽃이 12월 1일 이후에 진다면 성공
        if 1201 <= latest_date:
            is_possible = True
            break

        i += 1

    if is_possible:
        print(count)
    else:
        print(0)


if __name__ == "__main__":
    main()
