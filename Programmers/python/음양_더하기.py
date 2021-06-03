def solution(absolutes, signs):
    answer = 0
    for i in range(len(signs)):
        if signs[i]: # true이면 양수
            answer += absolutes[i]
        else: # false이면 음수
            answer -= absolutes[i]
    
    return answer