//
// Created by Mosa Yaqoobi on 2026-04-10.
//

#ifndef LEARN_CPP_GRAPH_H
#define LEARN_CPP_GRAPH_H
#include <vector>


class Graph {
    std::vector<std::vector<int>> adj_list {};  // the adjacency list representing the structure of the graph
    int vertices {};
public:
    explicit Graph(const std::vector<std::vector<int>>& adj_list) : adj_list(adj_list), vertices(adj_list.size()) {}
    Graph() {};
    //Core operations
    void addEdge(const int u, const int v);
    void removeEdge(const int u, const int v);
    std::vector<int> getNeighbors(const int u) noexcept;
    bool hasEdge(const int u, const int v) noexcept;
    //Graph info
    [[nodiscard]] int getVertexCount() const noexcept;
    [[nodiscard]] int getEdgeCount() const noexcept;
    [[nodiscard]] int getDegree(const int u) const noexcept;
    void print() const noexcept;
    //Traversals
    void BFS(const int = 0) const noexcept;
    void DFS(const int = 0) const noexcept;
    //Common algorithms
    bool isConnected() const noexcept;
    bool hasCycle() const noexcept;
    void shortestPath(const int u, const int v) const noexcept;





};

#endif //LEARN_CPP_GRAPH_H
