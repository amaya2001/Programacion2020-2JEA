from sys import stdin

MAX = 10000
adj = [[] for i in range(MAX)]
visitado = [0 for i in range(MAX)]
p = [-1 for i in range(MAX)]
d, f = [-1 for _ in range(MAX)], [-1 for _ in range(MAX)]
n, t = int(), 0

# 0 = no visitado, 1 = visitado pero no completado, 2 = completado
def dfsAux(v):
    d[v] = t
    t += 1
    visitado[v] = 1
    print(v)

    for u in adj[v]:
        if visitado[u] == 0:
            p[u] = v
            dfsAux(u)
    f[v] = t
    t += 1
    #visitado[v] = 2

def dfs():
    for i in range(n):
        visitado[i] = 0
        p[i] = -1

    for i in range(n):
        if visitado[i] == 0:
            dfsAux(i)

def main():
    global n
    n, m = list(map(int, stdin.readline().split()))

    for i in range(n):
        vals = list(map(int, stdin.readline().split()))
        u = vals[0]
        for j in range(u):
            adj[i].append(vals[j + 1])

    print("Grafo")
    for i in range(n):
        print("Nodo %d:" % i)
        for j in range(len(adj[i])):
            print("%d" % adj[i][j], end = ' ')
        print("")

    print("Recorrido en profundidad grafo:")
    dfs()
    print("Predecesores:")
    for i in range(n):
        print("El predecesor de %d es %d" % (i, pred[i]))

main()

    
    
