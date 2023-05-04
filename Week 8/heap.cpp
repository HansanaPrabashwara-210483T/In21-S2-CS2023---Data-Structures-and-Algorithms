/**
 * @file heap.cpp
 * @author D.G. Hansana Prabashwara (In21 - 210483T) 
 * @brief Heap Sorting Algorithm
 * @version 0.1
 * @date 2023-05-04
 * 
 * 
 */

#include <iostream>
#include <sstream>

using namespace std;


// function to find the index of the left child of the given node
int LeftChildIndex(int nodeIndex){
    return 2*nodeIndex+1; 
}

// function to find the index of the right child of the given node
int RightChildIndex(int nodeIndex){
    return 2*nodeIndex+2;
}

// function to swap two elements in a list
void swap (int arr[], int index1, int index2){
    auto temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}




// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   
   // Find the indexes of corresponding children 
   int leftIndex = LeftChildIndex(root);
   int rightIndex = RightChildIndex(root);
   
   // Unless childerns are larger than the parent node, largernode is the parent node
   int IndexOfLargest = root;

   // Check whether the left child is larger than the parent
   if(leftIndex < n && arr[leftIndex]>arr[IndexOfLargest]){
      IndexOfLargest = leftIndex;
   }
   // Check wheather the right child is larger than the maximum of thr left child and the right child
   if(rightIndex < n && arr[rightIndex]>arr[IndexOfLargest]){
      IndexOfLargest = rightIndex;
   }

   // In case parent is not the largest node, swap it with the largest child and heapify the subtree which swapped child node is the root
   if(IndexOfLargest != root){
      swap(arr, IndexOfLargest, root);
      heapify(arr,n, IndexOfLargest);
         
   } 
   
}
  

// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   // make nodes heapify from the leaf nodes
   for(int i = n/2-1; i>=0; i--){
        heapify(arr, n, i);
   }    
  
   // extracting elements from heap one by one
   int length = n;
   // decrese the length of the heap one by one while heapifing
   for(int i = length-1 ; i>0; i--){
      swap(arr, i, 0);
      heapify(arr, i, 0);  
   }
}



/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}


  
// main program
int main()
{
   // int heap_arr[] = {7,6,4,9,3,0};
   // int n = sizeof(heap_arr)/sizeof(heap_arr[0]);

   // cout<<"Input array"<<endl;
   // displayArray(heap_arr,n);
  
   // heapSort(heap_arr, n);
  
   // cout << "Sorted array"<<endl;
   // displayArray(heap_arr, n);



   /* Taking inputs from the user by one line*/
   string input_str;
   cout << "Enter the elements of the array separated by spaces: ";
   getline(cin, input_str);

   istringstream iss(input_str);
   int n = 0; // variable to store array size
   int num;  
   while (iss >> num) {
       n++;
   }
   
   int heap_arr[n]; // Initialize the array with the specific size
   iss.clear();
   iss.str(input_str);
   for (int i = 0; i < n; i++) {
       iss >> heap_arr[i];      // Add value to the array
   }
   
   // print the input array
   cout<<"Input array: "<<endl;
   displayArray(heap_arr,n);
  
   // Sort the array using heapsort
   heapSort(heap_arr, n);
  
   // Print the array
   cout << "Sorted array: "<<endl;
   displayArray(heap_arr, n);
   
   return 0;
}