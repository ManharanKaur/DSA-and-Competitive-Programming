#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class heap{
    vector<int> heap_array;
    bool isMinheap;

    // Index of Parent node of i
    int parent(int i){
        return (i - 1)/2;
    }

    // Index of Left child of i
    int LeftChild(int i){
        return 2 * i + 1;
    }

    // Index of Right child of i
    int RightChild(int i){
        return 2 * i + 2;
    }

    // Check property of heap
    bool compare(int a, int b){
        if(isMinheap) return a < b; // minheap
        else return a > b;  // maxheap
    }

    // Heapify up
    void heapifyUP(int i){
        while (i != 0 && compare(heap_array[i], heap_array[parent(i)]))
        {
            swap(heap_array[i], heap_array[parent(i)]);
            i = parent(i);
        }
    }

    // Heapify down
    void heapifyDOWN(int i){
        int left = LeftChild(i);
        int right = RightChild(i);
        int node = i;

        // to find relevant node
        if (left < heap_array.size() && compare(heap_array[left], heap_array[node]))
            node = left;
        
        if (right < heap_array.size() && compare(heap_array[right], heap_array[node]))
            node = right;
        
        // if relevant node is i, no need to swap, else swap node and i
        if(node != i){
            swap(heap_array[i], heap_array[node]);
            heapifyDOWN(node);
        }   
    }

public:
    heap(){
        cout << "Minheap(1) or Maxheap(0): ";
        int min;
        cin >> min;
        if(min)
            isMinheap = true;
        else isMinheap = false;
    }

    void insert(int ele){
        heap_array.push_back(ele);
        heapifyUP(heap_array.size() - 1); // heapify up the last node inserted 
    }

    int getTop(){
        if (heap_array.size() == 0)
        {
            cout << "Empty heap\n";
            return -1;
        }
        return heap_array[0];
    }

    void deleteTop(){
        if (heap_array.size() == 0) {
            cout << "Empty heap\n";
            return;
        }
        else if (heap_array.size() == 1){ //single element
            heap_array.pop_back();
            return;
        }

        heap_array[0] = heap_array.back(); // bring last element to top
        heap_array.pop_back(); //delete last element

        if (heap_array.size() > 1)
            heapifyDOWN(0);// heapify down the top now
    }

    void deleteElement(int i){
        if (heap_array.size() == 0) {
            cout << "Empty heap\n";
            return;
        }
        else if (heap_array.size() == 1){ //single element
            heap_array.pop_back();
            return;
        }

        // if heap is minheap, give i minimum value, else max int value
        heap_array[i] = isMinheap ? INT16_MIN : INT16_MAX;
        //bring minimum or maximum value to top
        heapifyUP(i);
        // delete this
        deleteTop();
    }

    void display(){
        if (heap_array.size() == 0) {
            cout << "Empty heap\n";
            return;
        }
        for (int i = 0; i < heap_array.size(); i++) {
            cout << heap_array[i] << " ";
        }
        cout << endl;
    }
};


int main(){
    heap example;
    example.insert(5);
    example.insert(6);
    example.insert(4);
    example.insert(7);
    example.insert(3);
    example.insert(8);

    example.display();

    example.deleteTop();
    example.display();

    cout << "Top element: " << example.getTop() << endl;

    example.deleteElement(3);
    example.display();

}