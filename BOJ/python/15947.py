# 노래 가사를 list에 넣어주었다.
song = [
    "baby", "sukhwan", "tururu", "turu", "very", "cute", "tururu", "turu", 
    "in", "bed", "tururu", "turu", "baby", "sukhwan"
]

n = int(input())
checkTuru = n%14 # 현재 index가 어느 word를 가리키는지 확인
verse = n//14 # 노래가 몇 절인지 확인
if checkTuru == 3 or checkTuru == 7 or checkTuru == 11: # 1절 기준 'tururu'위치
    if verse >= 3: # 3절 이상일 경우 'ru'가 5번 이상 등장하므로 'tu+ru*5'와 같은 형식으로 출력
        print(f"tu+ru*{verse+2}")
    else: # 아닐경우 turururu와 같이 'ru'를 이어붙여 출력
        print("tururu"+"ru"*verse)
elif checkTuru == 4 or checkTuru == 8 or checkTuru == 12: # 1절 기준 'turu'위치
    if verse >= 4: # 4절 이상일 경우 'ru'가 5번 이상 등장하므로 'tu+ru*5'와 같은 형식으로 출력
        print(f"tu+ru*{verse+1}")
    else: # 아닐 경우 'ru'를 이어붙여 출력
        print("turu"+"ru"*verse)
else: # 1절을 기준으로 'tururu' or 'turu'의 위치가 아니라면 해당 word를 출력
    print(f"{song[checkTuru-1]}")
