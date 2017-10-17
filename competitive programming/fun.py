# at http://codeforces.com/contest/841

def sol():
    n, k = [int(num) for num in input().split(" ")]
    inp = input()
    d = {}
    for st in inp:
        try:
            d[st]
            d[st] += 1
        except:
            d[st] = 1
    for key in d:
        if d[key] > k:
            print("NO")
            return
    print("YES")
    return

sol()



















