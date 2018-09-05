// C++ program to count inversions using Binary Indexed Tree
// USE CONVERT FUNCTION TO ACHIEVE O(n) solution
// OTHERWHISE IT'S O(maxval{A})

#include<bits/stdc++.h>
using namespace std;

// Converts an array to an array with values from 1 to n
// and relative order of smaller and greater elements remains
// same.  For example, {7, -90, 100, 1} is converted to
// {3, 1, 4 ,2 }
void convert(int arr[], int n)
{
    // Create a copy of arrp[] in temp and sort the temp array
    // in increasing order
    int temp[n];
    for (int i=0; i<n; i++)
        temp[i] = arr[i];
    sort(temp, temp+n);
 
    // Traverse all array elements
    for (int i=0; i<n; i++)
    {
        // lower_bound() Returns pointer to the first element
        // greater than or equal to arr[i]
        arr[i] = lower_bound(temp, temp+n, arr[i]) - temp + 1;
    }
}
 
// Returns sum of arr[0..index]. This function assumes
// that the array is preprocessed and partial sums of
// array elements are stored in BITree[].
int sum(int BITree[], int i) {
    int sum = 0; // Initialize result
 
    // Traverse ancestors of BITree[i]
    while (i > 0) {
        // Add current element of BITree to sum
        sum += BITree[i];
 
        // Move i to parent node in getSum View
        i -= i & (-i);
    }
    return sum;
}
 
// Updates a node in Binary Index Tree (BITree) at given i
// in BITree.  The given value 'val' is added to BITree[i] and
// all of its ancestors in tree.
void add(int BITree[], int n, int i, int val) {
    // Traverse all ancestors and add 'val'
    while (i <= n) {
       // Add 'val' to current node of BIT Tree
       BITree[i] += val;
 
       // Update i to that of parent in update View
       i += i & (-i);
    }
}
 
// Returns inversion count arr[0..n-1]
int get_inv_count(int arr[], int n) {
    int inv_count = 0; // Initialize result
 
    // Find maximum element in arr[]
    int max_element = 0;
    for (int i=0; i<n; i++)
        if (max_element < arr[i]) max_element = arr[i];
 
    // Create a BIT with size equal to max_element+1 
    // Dummy Root
    // (Extra one is used so that elements can be directly be
    // used as index)
    int BIT[max_element+1];
    for (int i = 1; i<= max_element; i++)
        BIT[i] = 0;

    // Traverse all elements from right.
    for (int i=n-1; i >= 0; i--)
    {
        // Get count of elements smaller than arr[i]
        inv_count += sum(BIT, arr[i]-1);
 
        // Add current element to BIT
        add(BIT, max_element, arr[i], 1);
    }

    cout << "BIT = [ ";
    for(int c = 1; c <= max_element; ++c) cout << BIT[c] << " "; 
    cout << "]\n";
    return inv_count;
}

// Driver program
int main()
{
    int A[] = {8, 4, 2, 1};
    int n = sizeof(A)/sizeof(int);
    int ptrA = *(A+2);
    cout << ptrA << endl;
    int inv_count = get_inv_count(A, n);
    cout << "Number of inversions are : " << inv_count << endl;
    return 0;
}