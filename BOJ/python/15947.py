song = [
    "baby", "sukhwan", "tururu", "turu", "very", "cute", "tururu", "turu", 
    "in", "bed", "tururu", "turu", "baby", "sukhwan"
]

n = int(input())
checkTuru = n%14
verse = n//14
if checkTuru == 3 or checkTuru == 7 or checkTuru == 11:
    if verse >= 3:
        print(f"tu+ru*{verse+2}")
    else:
        print("tururu"+"ru"*verse)
elif checkTuru == 4 or checkTuru == 8 or checkTuru == 12:
    if verse >= 4:
        print(f"tu+ru*{verse+1}")
    else:
        print("turu"+"ru"*verse)
else:
    print(f"{song[checkTuru-1]}")