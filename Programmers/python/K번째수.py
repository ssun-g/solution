def solution(array, commands):
    answer = [ sorted(array[s-1:e])[idx-1] for s, e, idx in commands ]
    return answer