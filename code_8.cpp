#include <iostream>
using namespace std;
  
void heapify(int arr[], int n, int root)

{
    
   int largest = root;  // initialize the largest element as root
   int left = 2*root + 1;  // left child node
   int right = 2*root + 2;  // right child node
 
 
   if (left < n && arr[left] > arr[largest])
      largest = left;
   if (right < n && arr[right] > arr[largest])
      largest = right;
   if (largest != root) {
      swap(arr[root], arr[largest]);
 
 
      heapify(arr, n, largest);
   }
}
void heapSort(int arr[], int n)
{
    
    
   for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  
   
   for (int i=n-1; i>=0; i--) {
      // move current root to end
      swap(arr[0], arr[i]);
  
      // call max heapify on the reduced heap
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
   int heap_arr[] = {4,17,3,12,9,6};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
   
   
   return 0;
}