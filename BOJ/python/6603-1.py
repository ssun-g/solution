"""

재귀 방식

"""
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

def comb(lottery: list, pick: list, init: int, cnt: int):
    if cnt == 6: # 6개의 수를 뽑았으면 출력해준다.
        print(' '.join(pick))
        return    
    
    for i in range(init, len(lottery)): # 숫자를 순서대로 뽑아준다.
        pick[cnt] = lottery[i]
        comb(lottery, pick, i+1, cnt+1)


while True:
    lottery = list(map(str, input().rstrip('\n').split(' ')))
    pick = [0 for _ in range(6)]
    if lottery[0] == '0': # 0이 입력되면 종료
        break

    del lottery[0]
    
    comb(lottery, pick, 0, 0)
    print()