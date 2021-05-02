s = input()
li = []
for i in range(len(s)):
    for j in range(i, len(s)+1):
        li.append(s[i:j])
print(len(set(li))-1) # 공백때문에 -1 빼줬음. 근데 왜 공백이 들어가지? #set으로 중복요소 삭제

# a
# ab
# aba
# abab
# ababc
#  b
#  ba
#  bab
#  babc
#   a(중복)
#   ab(중복)
#   abc
#    b(중복)
#    bc
#     c
