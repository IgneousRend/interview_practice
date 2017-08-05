def isomorphic(s,t):
    if len(s) != len(t) or len(set(s)) != len(set(t)):
        return False
    D = {}
    for i in range(len(s)):
        if s[i] not in D:
            D[s[i]] = t[i]
        else:
            if D[s[i]] != t[i]:
                return False
    return True


a = "abb"
b = "bab"
print (isomorphic(a,b)) 
