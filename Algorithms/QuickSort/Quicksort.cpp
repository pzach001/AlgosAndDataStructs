//
//  Quicksort.cpp
//  
//
//  Created by phillip zachariah on 1/12/18.
//
//

#include <vector>
#include  <iostream>
using namespace std;
void printarray(int* x, int size)
{
    for(int i =0; i < size; i++){
        cout << x[i] << " ";
    }
    cout << endl;
}

using namespace std;
int Partition(int *x, int start, int end)
{
    
    int pivot     =  x[end];
    int curr      =  start;

    for(int i = start; i < end; i++)
    {
        if(x[i] <= pivot)
        {
            if(x[curr] != x[end])
            {
                swap(x[i],x[curr]);
                curr++;
            }
        }
    }
    swap(x[curr],x[end]);
    //cout << x[curr] << endl;
    //cout << x[end] << endl;
    //printarray(x,8);
   // cout << endl << endl;
    return curr;
}
void QuickSort(int* x, int start, int end)
{
    printarray(x,8);
   // cout << "start:"<< start << endl;
   // cout << "end:"<< end << endl;
    if(start < end)
    {
        int mid = Partition(x,start,end);
       // cout << "mid:" << mid << endl << endl;
        QuickSort(x, start,  mid-1);
        QuickSort(x, mid+1, end);
    }
    //cout << "sorted" << endl;
}

int main(){
    
    int x[] = {1,40,5,1,1,3,20,30};
    QuickSort(x,0,7);
    //cout << "test" << endl;
    printarray(x,8);
    
}
