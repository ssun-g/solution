import sys

input = sys.stdin.readline


def bruteforce(init: int, cnt: int, sum: int):
    """
    4개의 그룹으로 나눌 수 있는 모든 경우의 수를 탐색하고
    그 중 가장 큰 값을 answer에 저장 한다.

    Args:
        init (int): 그룹의 시작 지점.
        cnt (int): 그룹을 나눈 횟수 (e.g. 3번 나누면 4개의 그룹이 생성)
        sum (int): 4개 그룹의 곱을 더해준 값(문제에서는 이 값을 P라고 한다.)을 구한다.
    """

    global N, cb, check, answer

    tmp = 1

    # 그룹을 3번 나누었다는 것은 4개의 그룹이 만들어 졌다는 의미이다.
    if cnt == 3:
        is_correct = False
        for i in range(init, N):
            is_correct = True  # 그룹을 정확히 4개의 그룹으로 나누었는지 체크한다.
            tmp *= cb[i]  # 마지막 그룹의 P값을 tmp에 저장해준다.
        if is_correct:
            answer = max(answer, sum + tmp)
        return

    for i in range(init, N):
        if not check[i]:
            check[i] = 1
            tmp *= cb[i]  # 우선 모두 같은 그룹으로 가정하고 계속 곱해준다.
            bruteforce(i + 1, cnt + 1, sum + tmp)  # 현재 위치에서 그룹을 나누어 본다. 나눌 때마다 '+'연산
            check[i] = 0


global N, cb, check, answer
answer = 0
N = int(input().rstrip("\n"))
cb = list(map(int, input().rstrip("\n").split(" ")))
check = [0 for _ in range(N)]

bruteforce(0, 0, 0)
print(answer)
