#include "Graph.h"
#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    Graph g;

    // вершины
    Node* n0 = new Node("0");
    Node* n1 = new Node("1");
    Node* n2 = new Node("2");
    Node* n3 = new Node("3");
    Node* n4 = new Node("4");
    Node* n5 = new Node("5");

    g.addNode(n0);
    g.addNode(n1);
    g.addNode(n2);
    g.addNode(n3);
    g.addNode(n4);
    g.addNode(n5);

    // рёбра
    g.addEdge(n0, n1);
    g.addEdge(n0, n3);
    g.addEdge(n0, n5);
    g.addEdge(n1, n2);
    g.addEdge(n1, n3);
    g.addEdge(n2, n4);
    g.addEdge(n2, n5);
    g.addEdge(n3, n4);
    g.addEdge(n4, n5);

    cout << "Граф успешно создан"<<endl;

    BFS bfs(g);
    DFS dfs(g);

    cout << "Проверка пути от вершины 0 до вершины 5:"<<endl;

    cout << "   Поиск в ширину (BFS): "<< (bfs.connected(n0, n5) ? "Да" : "Нет") << endl;

    cout << "   Поиск в глубину (DFS): "<< (dfs.connected(n0, n5) ? "Да" : "Нет") << endl;
    return 0;
}