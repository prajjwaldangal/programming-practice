import sys

if __name__ == "__main__":

    n = int(input().strip())
    m = int(input().strip())
    arr = [ [0 for i in range(n)] for j in range(n) ]
    for a0 in range(m):
        x, y, w = input().strip().split(' ')
        x, y, w = [int(x), int(y), int(w)]
        sx = x                  
        sy = y
        ex = x
        ey = y
        c = 0
        seen = {}
        while w > 0:
            if sx < 0:
                sx = 0
            if ex > n-1:
                ex = n-1
            if sy < 0:
                sy = 0
            if ey > n-1:
                ey = n-1
            i = sx
            while i <= ex:
                j = sy
                while j <= ey:
                    if not seen.get((i, j), False):
                        arr[i][j] += w
                        seen[(i, j)] = True
                    j += 1
                i += 1
            w -= 1
            sx -= 1
            sy -= 1
            ex += 1
            ey += 1
    m = 0
    for row in arr:
        for col_el in row:
            if col_el > m:
                m = col_el
                
    print(m)