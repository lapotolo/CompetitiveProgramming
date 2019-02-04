#include <iostream>
#include <vector>

struct Tree {
	int position, height;
	Tree(int p, int h) : position(p), height(h) {} 
};

struct Forest {
	std::vector<Tree> trees;

	Forest(int n) : trees() { 
			trees.reserve(n);
	}

	void add_tree(Tree t) { trees.push_back(t); }

	bool can_be_cut_left(int t) {
		if( (trees[t].position - trees[t].height) <= trees[t-1].position) return false;
		return true;
  }

	bool can_be_cut_right(int t) {
		if( (trees[t].position + trees[t].height) >= trees[t+1].position) return false;
		trees[t].position += trees[t].height; // update position of cut tree
		return true;        
	}  
};


int main(){
	int p, h, num_trees, result;

	std::cin >> num_trees;

	if ( num_trees <= 2 ) { std::cout << num_trees << std::endl; return 0; }
	else {
		result = 2; // first tree can always be cut left, last tree can be cut right
		Forest test(num_trees);
		for( int i = 0; i < num_trees; ++i ) {
			std::cin >> p;
			std::cin >> h;
			test.add_tree( Tree(p, h) );
		}
		for ( int i = 1; i < num_trees-1; ++i ) {
			if( test.can_be_cut_left(i) ) ++result;
			else if( test.can_be_cut_right(i) ) ++result;
		}
		std::cout << result << std::endl;
		return 0;
  }
}

