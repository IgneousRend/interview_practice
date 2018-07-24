def MaxTip(A, X, Y):
    s = []
    for _ in A:
        s.append([_[0], _[1], _[0] - _[1]])
    s.sort(key=lambda y: y[-1], reverse=True)
    res, i = int(0), int(0)
    print(s)
    while X > 0 and Y > 0 and i < len(s):
        if s[i][-1] > 0:
            X -= 1
            res += s[i][0]
        elif s[i][-1] < 0:
            Y -= 1
            res += s[i][1]
        else:
            res += s[i][1]
        i = i+1
    if X == 0:
        res += sum([z[1] for z in s[i:]])
    else:
        res += sum([z[0] for z in s[i:]])
    return res


a = int(input())
for i in range(a):  
    n, x, y = list(map(int, input().split()))
    z = list(map(int, input().split()))
    w = list(map(int, input().split()))
    q = MaxTip(zip(z,w),x,y)
    e = MaxTip(zip(w,z),y,x)
    print(max([q,e]))
