def solution(price, money, count):
    total = 0
    total = price * count * (count+1) // 2
    
    if total < money:
        return 0
    else:
        return total - money