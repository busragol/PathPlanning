// Program to print BFS traversal from a given 
// source vertex. BFS(int s) traverses vertices  
// reachable from s. 
#include<iostream> //The iostream library is an object-oriented library that provides input and output functionality using streams.
#include <list> //list library is used for list operations.
#include <chrono> 
using namespace std::chrono;
using namespace std;

// This class represents a directed graph using 
// adjacency list representation 
class Graph
{
    int V;    // No. of vertices 

    // Pointer to an array containing adjacency 
    // lists 
    list<int>* adj;
public:
    Graph(int V);  // Constructor 

    // function to add an edge to graph 
    void addEdge(int v, int w);

    // prints BFS traversal from a given source s 
    void BFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list. 
}

void Graph::BFS(int s)
{
    // Mark all the vertices as not visited 
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Create a queue for BFS 
    list<int> queue;

    // Mark the current node as visited and enqueue it 
    visited[s] = true;
    queue.push_back(s);

    // 'i' will be used to get all adjacent 
    // vertices of a vertex 
    list<int>::iterator i;

    while (!queue.empty())
    {
        // Dequeue a vertex from queue and print it 
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued 
        // vertex s. If a adjacent has not been visited,  
        // then mark it visited and enqueue it 
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

// Driver program to test methods of graph class 
int main()
{


    auto start = high_resolution_clock::now();

    // Create a graph given in the above diagram 
    Graph g(9);
    g.addEdge(0, 1);
    g.addEdge(0, 7);
    g.addEdge(1, 2);
    g.addEdge(1, 7);
    g.addEdge(2, 3);
    g.addEdge(2, 8);
    g.addEdge(2, 5);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(6, 8);
    g.addEdge(7, 8);

    cout << "Following is Breadth First Traversal "
        << "(starting from vertex 0) \n";
    g.BFS(0);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    // To get the value of duration use the count() 
    // member function on the duration object 
    cout << endl << duration.count() << "ms" << endl;
    return 0;
}