def solution(progresses, speeds):
    answer = []
    
    # 각 progresses마다 며칠 후에 배포 가능한 지 저장해주었다.
    days = [ ((100-p)//s) if ((100-p)%s) == 0 else (100-p)//s+1 for p, s in zip(progresses, speeds)]
    
    # 그 후 먼저 배포 되어야 하는 값을 stack에 넣어 주었다.
    cnt = 1
    stack = [days[0]]
    for i in range(1, len(days)):
        cur = stack[0] # 현재 값을 기준으로 비교한다.
        if days[i] <= cur: # 현재 기능과 같이 배포할 수 있는 경우
            cnt += 1
        else: # 현재 기능보다 나중에 배포해야 하는 경우
            answer.append(cnt)
            cnt = 1
            stack.pop()
            stack.append(days[i]) # 현재값을 pop하고 새로운 값으로 업데이트 한다.
    
    answer.append(cnt) # 반복문을 다 돌고 append 하지 않은 cnt를 넣어준다.
    
    return answer