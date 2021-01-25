def solution(answers):
    supo1 = [1, 2, 3, 4, 5]
    supo2 = [2, 1, 2, 3, 2, 4, 2, 5]
    supo3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    score = [0, 0, 0]
    
    for i in range(len(answers)):
        if answers[i] == supo1[i%5]:
            score[0] += 1
        if answers[i] == supo2[i%8]:
            score[1] += 1
        if answers[i] == supo3[i%10]:
            score[2] += 1
            
    answer = []
    for i in range(3):
        if score[i] == max(score):
            answer.append(i+1)
            
    return answer