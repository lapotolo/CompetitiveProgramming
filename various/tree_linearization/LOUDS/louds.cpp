#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

struct LOUDS{

    LOUDS(vector<int> degree_sequence)
    {
        // bit required by loud repr
        size_t N = 2*degree_sequence.size() -1;
        bitset<N> tree;
        m_tree = tree; 
        build(degree_sequence);
    }

    private:
        bitset m_tree; 

        void build(vector<int> degrees){

        }   
};