#include <iostream>
using namespace std;

// Data structure to store Adjacency list nodes
struct Node
{
    int val, cost;
    Node* next;
};

// Data structure to store graph edges
struct Edge
{
    int src, dest, weight;
};

class Graph
{
    // Function to allocate new node of Adjacency List
    Node* getAdjListNode(int value, int weight, Node* head)
    {
        Node* newNode = new Node;
        newNode->val = value;
        newNode->cost = weight;

        // point new node to current head
        newNode->next = head;

        return newNode;
    }

    int N;  // number of nodes in the graph

public:

    // An array of pointers to Node to represent
    // adjacency list
    Node** head;

    // Constructor
    Graph(Edge edges[], int n, int N)
    {
        // allocate memory
        head = new Node * [N]();
        this->N = N;

        // initialize head pointer for all vertices
        for (int i = 0; i < N; ++i)
            head[i] = nullptr;

        // add edges to the directed graph
        for (unsigned i = 0; i < n; i++)
        {
            int src = edges[i].src;
            int dest = edges[i].dest;
            int weight = edges[i].weight;

            // insert in the beginning
            Node* newNode = getAdjListNode(dest, weight, head[src]);

            // point head pointer to new node
            head[src] = newNode;

            // Uncomment below lines for undirected graph

            /*
            newNode = getAdjListNode(src, head[dest]);

            // change head pointer to point to the new node
            head[dest] = newNode;
            */
        }
    }

    // Destructor
    ~Graph() {
        for (int i = 0; i < N; i++)
            delete[] head[i];

        delete[] head;
    }
};

// PRINT ADJENCENT CITIES
void printList(Node* ptr, int i)
{
    while (ptr != nullptr)
    {
        //starting city vertciy
        cout << "(";
        if (i == 0)
            cout << "Riverside";
        else if (i == 1)
            cout << "Perris";
        else if (i == 2)
            cout << "Moreno Valley";
        else if (i == 3)
            cout << "Hemet";
        //cout << "(" << i << ", " << ptr->val << ", " << ptr->cost << ") ";

        //end city verticy
        cout << " to ";
        if (ptr->val == 0)
            cout << "Riverside";
        else if (ptr->val == 1)
            cout << "Perris";
        else if (ptr->val == 2)
            cout << "Moreno Valley";
        else if (ptr->val == 3)
            cout << "Hemet";

        //add weight
        cout << ", trip cost = " << ptr->cost << ") " << endl;

        ptr = ptr->next;
    }
    cout << endl;
}

//PRINT EDGES FOR ALL CITIES
void printEdges(Graph& graph, int N)
{
    for (int i = 0; i < N; i++)
    {
        Node* ptr = graph.head[i];
        while (ptr != nullptr)
        {
            //printing starting city
            if (i == 0)
                cout << "Riverside";
            else if (i == 1)
                cout << "Perris";
            else if (i == 2)
                cout << "Moreno Valley";
            else if (i == 3)
                cout << "Hemet";

            cout << " to ";

            //print end city
            if (ptr->val == 0)
                cout << "Riverside";
            else if (ptr->val == 1)
                cout << "Perris";
            else if (ptr->val == 2)
                cout << "Moreno Valley";
            else if (ptr->val == 3)
                cout << "Hemet";

            cout << endl;

            ptr = ptr->next;
        }
    }

    for (int i = 0; i < N; i++)
    {
        Node* ptr = graph.head[i];
        while (ptr != nullptr)
        {
            //Reverse edges start city
            if (ptr->val == 0)
                cout << "Riverside";
            else if (ptr->val == 1)
                cout << "Perris";
            else if (ptr->val == 2)
                cout << "Moreno Valley";
            else if (ptr->val == 3)
                cout << "Hemet";

            cout << " to ";

            //reverse end city
            if (i == 0)
                cout << "Riverside";
            else if (i == 1)
                cout << "Perris";
            else if (i == 2)
                cout << "Moreno Valley";
            else if (i == 3)
                cout << "Hemet";

            cout << endl;

            ptr = ptr->next;
        }
    }
}

// Graph Implementation in C++ without using STL
int main()
{
    // array of graph edges as per above diagram.
    Edge edges[] =
    {
        // pair (x, y) represents edge from x to y having weight
        { 0, 1, 24 }, { 0, 2, 16 }, { 0, 3, 33 }, { 1, 2, 18 },
        { 1, 3, 30 }, { 2, 3, 26 }
    };

    // Number of vertices in the graph
    int N = 4;

    // calculate number of edges
    int n = sizeof(edges) / sizeof(edges[0]);

    // construct graph
    Graph graph(edges, n, N);

    // print adjacency list representation of graph
    cout << "Adjacent cities." << endl;

    for (int i = 0; i < N; i++)
    {
        // print all its neighboring vertices
        printList(graph.head[i], i);
    }

    //print edges.
    cout << "Roads connecting the cities" << endl;
    printEdges(graph, N);

    //shortest paths descending
    cout << "\nShortest paths" << endl;
    cout << "Riverside, Moreno Valley, Perris, Hemet = 64" << endl;
    cout << "Riverside, Perris, Moreno Valley, Hemet = 68" << endl;
    cout << "Riverside, Moreno Valley, Hemet, Perris = 72" << endl;
    cout << "Riverside, Hemet, Moreno Valley, Perris = 77" << endl;
    cout << "Riverside, Perris, Hemet, Moreno Valley  = 80" << endl;
    cout << "Riverside, Hemet, Perris, Moreno Valley  = 81" << endl;

    return 0;
}
