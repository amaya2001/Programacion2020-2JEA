from heapq import heappop, heappush

INF = float('inf') # math.inf

def dijkstra(G, s):
    """G is a graph representation in adjacency list format with vertices
       in the set { 0, ..., |V|-1 } and source s is a vertex in G"""
    # dist[u] : "minimum distance detected from source to u
    d, p = [INF for i in range(len(G))], [-1 for i in range(len(G))]
    d[s] = 0
    heap = [(0, s1)]

    while len(heap) != 0:
        costo, u = heappop(heap)
        if costo == d[u]:
            for v, w in G[u]:
                if d[v] > d[u] + w:
                    d[v], p[v] = d[u] + w, u
                    heappush(heap, (d[v], v))
    return d, p
