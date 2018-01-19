//
//  MergeSort.cpp
//  
//
//  Created by phillip zachariah on 1/16/18.
//
//

#include <iostream>

using namespace std;
void printarray(int* x, int size)
{
    for(int i =0; i < size; i++){
        cout << x[i] << " ";
    }
    cout << endl;
}
void Merge(int *A, int L , int M , int R ){
    //cout  << "here " << endl;
    //cout << "L: " << L << endl;
    //cout << "R: " << R << endl;
    //cout << "M: " << M << endl;
    int sizeL = M-L+1;
   // cout << "sizeL: " << sizeL << endl;
     int sizeR = R-M;
    cout << "sizeR: " << sizeR << endl;
    int* Larr = new int[sizeL];
    int* Rarr = new int[sizeR];
    //cout << " current regular array" << endl;
   // printarray(A,6);
    for(int i =0; i < sizeL;i++)
    {
        Larr[i] = A[L+i];
        
        
    }
  //  cout << "printing left array: " ;
   // printarray(Larr,sizeL);
    for(int i =0; i < sizeR;i++)
    {
        Rarr[i] = A[M+1+i];
       
        
    }
   // cout << "printing right array: " ;
   // printarray( Rarr,sizeR);
    int iterL = 0;
    int iterR = 0;
    int k = L;
    while( (iterL < sizeL) && (iterR < sizeR) )
    {
        if(Larr[iterL] <= Rarr[iterR])
        {
            A[k] =Larr[iterL];
           // printarray(A,7);
            iterL++;
        }
        else
        {
            A[k] = Rarr[iterR];
           //   printarray(A,7);
            iterR++;
        }
        k++;
    }
    
    while( iterL  < sizeL)
    {
        A[k] =  Larr[iterL];
        //   printarray(A,7);
        iterL++;
        k++;
    }
    
    while(iterR  < sizeR)
    {
        A[k] =  Rarr[iterR];
        
        //   printarray(A,7);
        iterR++;
        k++;
    }
    
}
void MergeSort(int* A, int L, int R)
{

   if(L < R)
   {
       //printarray(A,7);
      // cout << "L: " << L << endl;
       //cout << "R: " << R << endl;
       int mid =  L + (R -L) /2;
       //cout << "mid: " << mid << endl;
       MergeSort(A,L,mid);
       MergeSort(A,mid+1,R);
       Merge(A,L,mid,R);
   }
    
}
int main()
{
    int A[] = {10, 2, 4, 1, 4, 100,3,30,20,18,11,3,4,6,2,9};
    MergeSort(A,0,15);
    printarray(A,16);
    
}

