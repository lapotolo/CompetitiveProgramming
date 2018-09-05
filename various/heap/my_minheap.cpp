#include <iostream>
#include <vector>

using namespace std;

template <class T>
class MinHeap {
    vector<T> heap;

    void bubble_up();
    void bubble_down();
    void swap(int child_index, int parent_index);
    int left_child(int parent_index);
    int right_child(int parent_index);
    int get_parent(int child_index);
public:
    MinHeap();
    MinHeap(vector<T> const& v);
    void insert(T value);
    void pop();
    int get_size();
    T front();
    void print_heap();


};

template <class T>
MinHeap<T> :: MinHeap(){}

template <class T>
MinHeap<T> :: MinHeap(vector<T> const& v){
    heap.reserve(v.size());
    for(auto element : v) insert(element);
    print_heap();
}

template <class T>
int MinHeap<T> :: get_size(){
    return heap.size();
}

template <class T>
void MinHeap<T>::swap(int child_index, int parent_index) {
    T temp;
    temp = heap[child_index];
    heap[child_index] = heap[parent_index];
    heap[parent_index] = temp;
}

template <class T>
int MinHeap<T> :: get_parent(int child_index) {
    if (child_index % 2 == 0) return (child_index /2 ) -1;
    else return child_index/2;

}

template <class T>
int MinHeap<T> :: left_child(int parent_index){
    return 2*parent_index +1;
}

template <class T>
int MinHeap<T> :: right_child(int parent_index){
    return 2 * parent_index + 2;
}

template <class T>
void MinHeap<T> :: insert(T value) {

    heap.push_back(value);
    bubble_up();

}

template <class T>
void MinHeap <T>:: bubble_up() {
    int child_index = heap.size() - 1;
    int parent_index = get_parent(child_index);
    while (heap[child_index] < heap[parent_index] && child_index >=0 && parent_index >= 0) {
        swap(child_index, parent_index);
        child_index = parent_index;
        parent_index = get_parent(child_index);
    }
}

template <class T>
T MinHeap<T> :: front(){ return heap[0];}


template <class T>
void MinHeap<T> :: pop() {
    int child_index = heap.size() - 1, parent_index = 0;
    swap(child_index, 0);
    heap.pop_back();
    bubble_down();
}


template <class T>
void MinHeap<T> :: bubble_down() {
    int parent_index = 0;
    bool no_operation = false;

    while (!no_operation) {
        int left = left_child(parent_index);
        int right = right_child(parent_index);
        int length = heap.size();
        int largest = parent_index;

        if (left < length && heap[left] < heap[largest])
            largest = left;

        if (right < length && heap[right] < heap[largest])
            largest = right;

        if (largest != parent_index) {
            swap(largest, parent_index);
            parent_index = largest;
        }
        else no_operation = true;
    }
}

template <class T>
void MinHeap<T> :: print_heap(){for(auto element : heap) cout << (element) << " ";cout << endl;}

int main(){
    vector<int> a({4, 5,123,2,3,99,4567,4,6,7});
    MinHeap<int> test_heap(a);
    int len = sizeof(a) /sizeof(int);

    test_heap.insert(9);
    test_heap.print_heap();
    
    cout << "front is = "<< test_heap.front() << endl;
    test_heap.pop();
    test_heap.print_heap();
    
    cout << "front is = "<< test_heap.front() << endl;
    test_heap.pop();
    test_heap.print_heap();
    cout << "front is = "<< test_heap.front() << endl;

    // for (int i = 0; i < len; i++) {
    //     MinHeap.insert(a[i]);
    //   }

    // while(MinHeap.get_size() > 0)
    //     cout<<"MinHeap Max\t"<< MinHeap.pop()<<endl;
    // return 0;

}
