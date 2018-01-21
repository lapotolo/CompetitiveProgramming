// author: Lapo Toloni
// problem: http://www.spoj.com/problems/MST/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Edge {
    int source;
    int dest;
    int weight;

    // to use std::sort
    bool operator < (const Edge& e) const {return (weight < e.weight);}
    bool operator > (const Edge& e) const {return (weight > e.weight);}
};

struct Element {
    int parent;
    int rank;
};

struct DisjointSet{

    DisjointSet(int n) : num_elements(n){
        elements.reserve(n);
        //initialize set
        for (int i = 0; i < n; ++i)
            elements.emplace_back(Element {-1, -1});
    }

    void make_set(int x){
        if (elements[x].rank == -1) {
            elements[x].parent = x;
            elements[x].rank = 0;
        }
        // cout << "elements = [";
        // for(auto el : elements) cout << el.parent << " ";
        // cout << "]\n";
    }

    void unite(int x, int y){
        int x_set = find_set(x);
        int y_set = find_set(y);
        if(x_set != y_set){
            link(x_set, y_set);
            num_elements -= 1;
        }
    }

    int find_set(int x){
        if( x != elements[x].parent)
            elements[x].parent = find_set(elements[x].parent);
        return elements[x].parent;
    }

    int get_num_elements() {return num_elements;}

private:

    vector<Element> elements;
    int num_elements;

    void link(int x, int y){
        if(elements[x].rank > elements[y].rank)
            elements[y].parent = x;
        else { // y >= x
            elements[x].parent = y;
            if(elements[x].rank == elements[y].rank)
                elements[y].rank += 1;
        }
    }
};

int64_t kruskal(DisjointSet & union_find, vector<Edge> & edges){
    int64_t mst_weight = 0;
    sort(edges.begin(), edges.end());
    for(int i = 0; (i < edges.size()) and union_find.get_num_elements() > 1 ; ++i) {  // and union_find.get_num_elements() == 1
        if(union_find.find_set(edges[i].source) != union_find.find_set(edges[i].dest)){
            mst_weight += edges[i].weight;
            union_find.unite(edges[i].source, edges[i].dest);
        }
    }
    return mst_weight;

}

int main() {

    int N, M;
    int src, dst, w;

    cin >> N >> M;

    vector<Edge> edges;
    edges.reserve(M);
    DisjointSet union_find(N);

    for (int i = 0; i < M; ++i) {
        cin >> src >> dst >> w;
        src -= 1; // 0 based representation in my DisjointSet
        dst -= 1;
        edges.emplace_back(Edge {src, dst, w});
        union_find.make_set(src);
        union_find.make_set(dst);
    }

    auto result = kruskal(union_find, edges);
    
    cout << result << endl;
    return 0;
}
