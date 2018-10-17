// TO FINISH!!!


#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>

using namespace std;

#define ALPHABET_SIZE 26
#define ASCII_OFFSET 97
// #define ALPHABETS = "abcdefghijklmnopqrstuvwxyz";

struct alpha_node{
    char id;
    int in_degree;
    vector<alpha_node*> neighbors;
};

bool create_new_lex_ordering(string const& a, string const& b, vector<alpha_node> graph){
    int shorter_size = min<int>(a.size(), b.size());
    int k = 0;
    while(a[k] == b[k] and k<shorter_size) ++k; // slide the window
    if(i < shorter_size){
        graph[(a[i]-ASCII_OFFSET)].neighbors.emplace_back(&graph[(b[i]-ASCII_OFFSET)]);
        graph[(b[i]-ASCII_OFFSET)]
    }
    else{
        if(shorter_size == b.size() and shorter < a.size()){
            return true;
        }
    }
}

int main() {

    int num_strings;
    cin >> num_strings;

    vector<alpha_node> graph;
    graph.reserve(ALPHABET_SIZE);

    for (char i = ASCII_OFFSET; i < ASCII_OFFSET+ALPHABET_SIZE; ++i){
        graph.emplace_back(alpha_node {i, 0, {}});
    }

    // for(auto el : graph) {
    //     if(el.parent == 1) cout << el.id << " ";
    //     else cout << " nope ";
    // }
    // cout << endl;

    string a, b;
    cin >> a;
    for (int i = 1; i < num_strings; ++i) {
        cin >> b;
        if (!create_new_lex_ordering(a, b, graph)){
            cout << "Impossible";
            return 0
        }
        swap(a, b);
    }


    
    // char a = 'a';
    // char y = 125;
    // int x = a - 96;
    // cout << y << endl;
    // cout << x << endl;
    return 0;
}
