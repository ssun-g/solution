import re

def solution(phone_book):
    temp_ = sorted(phone_book)
    p = re.compile(temp_[0])
    for i in range(1, len(temp_)):
        if p.search(temp_[i]) != None:
            return False

    return True
