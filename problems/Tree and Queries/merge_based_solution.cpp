/*
Maintain a set of values for each node in the tree. Let set(u) be the set of all values in the subtree rooted at u. We want size(set(u)) for all u.

Let a node u have k children, v1, v2...vk. Every time you want to merge set(u) with set(vi), pop out the elements from the smaller set and insert them into the larger one. You can think of it like implementing union find, based on size.

Consider any arbitrary node value. Every time you remove it from a certain set and insert it into some other, the size of the merged set is atleast twice the size of the original.

Say you merge sets x and y. Assume size(x) ≤ size(y). Therefore, by the algorithm, you will push all the elements of x into y. Let xy be the merged set. size(xy) = size(x) + size(y). But size(y) ≥ size(x).

So size(xy) ≥ 2 * size(x).

Thus, each value will not move more than log n times. Since each move is done in O(logn), the total complexity for n values amounts to O(nlog2 n)

*/

#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second

using namespace std;

const int MAX = 3e5 + 50;

const ll MOD1 = (ll)(1e9 + 7);
const ll MOD2 = (ll)(1e9 + 297);

vector < int > adjList[MAX];

ll C[MAX]  , D[MAX];
int P[MAX] , N;

ll  PRIME = 137;
ll  H1[MAX] , H2[MAX] , A[MAX];

set < pair < ll , ll > > S[MAX];

int root( int x ){ // Path Compression
	if( P[x] == x ) return x;
	return P[x] = root( P[x] );
}

void merge( int a , int b ){ // Union by Size
	
	a = root(a) , b = root(b);
	
	if( a == b ) return;
	
	if( S[a].size() < S[b].size() ) swap( a , b );
	
	for( pair < ll , ll > cur : S[b] )
		S[a].insert( cur );

	S[b].clear();
	P[b] = a;
}

void dfs1( int node , int par ){ // Compute Prefix Hashes
	
	H1[node] = ( H1[par] * PRIME + A[node] ) % MOD1 ; // First Hash
	H2[node] = ( H2[par] * PRIME + A[node] ) % MOD2 ; // Second Hash

	for( int next : adjList[node] ){
		if( next == par ) continue;
		dfs1( next , node );
	}

}

void dfs2( int node , int par ){
	
	S[node].insert( { H1[node] , H2[node] } );

	for( int next : adjList[node] ){
		if( next == par ) continue;
		dfs2( next , node );
		merge( node , next );
	}

	D[node] = S[ root(node) ].size();
}

int main(){
	
	//rf;
	cin.tie(0) , ios::sync_with_stdio(false);
	cin >> N;

	for(int i = 1 ; i <= N ; i++){
		cin >> C[i];
		P[i] = i;
	}

	for(int i = 1 ; i <= N ; i++){
		char x;
		cin >> x;
		A[i] = ( x - 'a' + 1 );
	}

	for(int i = 1 ; i < N ; i++){
		int u , v;
		cin >> u >> v;
		adjList[u].emplace_back(v);
		adjList[v].emplace_back(u);
	}

	dfs1(1 , 0);
	dfs2(1 , 0);

	ll mx = 0 , mxcnt = 0;
	for(int i = 1 ; i <= N ; i++){
		if( D[i] + C[i] > mx )
			mx = D[i] + C[i] , mxcnt = 1;
		else if( D[i] + C[i] == mx )
			mxcnt++;
	}

	cout << mx << endl;
	cout << mxcnt << endl;

}