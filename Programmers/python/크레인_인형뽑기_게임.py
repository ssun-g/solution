"""

단순하게 인형뽑기 게임을 구현하는 문제.
크게 어렵지 않은 문제이다.            

"""
def solution(board, moves):
    answer = 0
    bucket = [0] # 인형을 담을 바구니. top을 설정해주기 위해 0값을 하나 넣는다.
    for idx in moves: # 인형을 뽑는 index를 기준으로 반복문을 탐색한다.
        top = bucket[-1]
        for i in range(len(board)):
            if board[i][idx-1] != 0: # 행 탐색을 하면서 가장 위에 있는 인형을 찾는다.
                bucket.append(board[i][idx-1]) # 일단 바구니에 넣어 준다.
                board[i][idx-1] = 0 # 인형을 뽑았으므로 기계에서 없애 줘야 한다.
                
                if top == bucket[-1]: # 원래 바구니의 가장 위에 있던 인형과 방금 뽑은 인형이 같은 종류라면
                    bucket.pop() # 둘 다 삭제해준다.
                    bucket.pop() 
                    answer += 2

                break # 한 번 뽑았으면 반복문을 탈출해야 같은 곳에서 여러번 뽑지 않는다.
    
    return answer