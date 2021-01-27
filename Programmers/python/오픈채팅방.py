def solution(record):
    name = {} # id로 닉네임을 찾을 수 있도록 한다.(dict type)
    print_inout = {"Enter":"님이 들어왔습니다.", "Leave":"님이 나갔습니다."} # 들어오고 나가는 것을 키워드로 찾고 출력하기 위해 dict type으로 선언
    for st in record:
        inout = st.split(' ') # 문장을 공백을 기준으로 나눠서
        if inout[0] in ["Enter", "Change"]: # 입장하거나(닉네임 설정가능) 닉네임을 교체하면
            name[inout[1]] = inout[2] # 닉네임을 변경시켜 준다.
    
    # 모든 문장에 대해 처리를 했으니 answer에 입, 퇴장 문장을 저장해주자.
    answer = [ (name[st.split(' ')[1]]+print_inout[st.split(' ')[0]]) \
              for st in record if (st.split(' ')[0] != "Change") ]

    return answer