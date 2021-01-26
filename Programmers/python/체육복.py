def solution(n, lost, reserve):
    clothes = [1 for i in range(n + 1)]
    for i in lost:
        clothes[i] -= 1

    for i in reserve:
        clothes[i] += 1

    for i in range(1, n):
        if clothes[i] == 0 and clothes[i - 1] == 2:
            clothes[i] += 1
            clothes[i - 1] -= 1
        elif clothes[i] == 0 and clothes[i + 1] == 2:
            clothes[i] += 1
            clothes[i + 1] -= 1

    answer = 0
    for i in range(1, n + 1):
        if clothes[i] > 0:
            answer += 1

    return answer
