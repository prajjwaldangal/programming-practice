def  numberOfPaths(b):
    for a in b:
        n_p = {}
        n = len(a)
        m = len(a[0])
        j = 0
        for i in range(n):
            if a[i][j] == 0:
                n_p[(i, j)] = 0
            n_p[(i, j)] = 1
            
        i = 0
        for j in range(m):
            if a[i][j] == 0:
                n_p[(i, j)] = 0
            n_p[(i, j)] = 1
        for i in range(1, n):
            for j in range(1, m):
                if a[i][j] == 0:
                    n_p[(i, j)] = 0
                    break
                n_p[(i, j)] = n_p[(i-1, j)] + n_p[(i, j-1)]
        print(n_p[(n-1, m-1)])

