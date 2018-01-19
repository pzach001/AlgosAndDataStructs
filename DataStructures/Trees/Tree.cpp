//
//  Tree.cpp
//  
//
//  Created by phillip zachariah on 1/17/18.
//
//https://www.cs.cmu.edu/~adamchik/15-121/lectures/Trees/trees.htmlfa

#include "Tree.hpp"
#include<iostream>
using namespace std;

struct TreeNode{
    int Value;
    TreeNode * parent;
    TreeNode * LeftChild;
    TreeNode * RightChild;
};

class BST{
    TreeNode* Head;
    bool search(TreeNode * x , int val);
    void setvalue(int x);
};
TreeNode* shiftforRight(TreeNode* x)
{
    if(x->RightChild == NULL)
    {
        return x;
    }
    return shiftforRight(x->RightChild);
}
void printBST(TreeNode *x)
{
    //using depth first search
    if(x == NULL)
    {
        // END OF PATH
    }
    else{
        cout << x->Value <<" ";
        printBST(x->LeftChild);
        printBST(x->RightChild);
    }
}


TreeNode* search(TreeNode * x,int val )
{
    if(x == NULL)
    {
        cout << "value: " << val << " was not found inside BST" << endl;
        return NULL;
    }
    int curr = x->Value;
    cout << "curr: "<< curr <<  "  val:" << val << endl;
    if(curr== val)
    {
        cout << "value: " << val << " was found inside the BST" << endl;
        return x;
    }
    
    if(val < curr )
    {
        cout <<  "went left" << endl;
        return search(x->LeftChild,val);
    }
    if(val > curr)
    {
         cout << "went right" << endl;
        return search(x->RightChild,val);
    }
}
bool deletion(TreeNode *x, int val)
{
    TreeNode* d = search(x,val);
    //either child is NULL or it is a leaf NODE

    if(d->LeftChild == NULL && d->RightChild == NULL){
        //LEAF
        cout << "value(" << val << ") is a leaf node.....deleting as is." << endl;
        d->parent->LeftChild  = NULL;
        d->parent->RightChild = NULL;
    }
    if(d->LeftChild == NULL && d->RightChild != NULL){
          //RIGHT CHILD IS THERE
        cout << "value(" << val <<") has a right child..........connecting parent to right child " << endl;
        int childflag;
        if(d->parent->LeftChild == d){
            childflag = 0;
        }
        if(d->parent->RightChild == d){
            childflag = 1;
        }
        if(childflag == 0){
            d->parent->LeftChild = d->RightChild;
        }
        else if(childflag == 1){
            d->parent->RightChild = d->RightChild;
        }
        d->RightChild->parent = d->parent;
    }
    if(d->LeftChild != NULL && d->RightChild == NULL){
        //LEFT CHILD IS THERE
        cout << "value(" << val <<")has a left child............connecting parent to left child " << endl;
        d->parent->LeftChild  = NULL;
        d->parent->RightChild = NULL;
        int childflag;
        if(d->parent->LeftChild  ==  d){
            childflag = 0;
        }
        if(d->parent->RightChild ==  d){
            childflag = 1;
        }
        if(childflag == 0){
            d->parent->LeftChild = d->LeftChild;
        }
        else if(childflag == 1){
            d->parent->RightChild = d->LeftChild;
        }
        d->LeftChild->parent = d->parent;
    }
    if(d->LeftChild !=NULL && d->RightChild !=NULL){
        //BOTH CHILDREN EXIST
        //THIS NEEDS TO BE FIXED
        //YOU 
         cout << "value(" << val <<")has a two children............connecting parent to left child " << endl;
        TreeNode* LargestChild = shiftforRight(d->LeftChild);
        if(LargestChild == d->LeftChild)
        {
            d->Value = d->LeftChild->Value;
            d->LeftChild = NULL;
        }
        else{
            d->Value = LargestChild->Value;
            if(LargestChild->LeftChild == NULL && LargestChild->RightChild == NULL){
                LargestChild->parent->RightChild = NULL;
            }
            if(LargestChild->LeftChild != NULL && LargestChild->RightChild == NULL){
                LargestChild->parent->RightChild = d->LeftChild;
            }
        }
    }
    
    
}

// to insert you want to take
bool insert(TreeNode *x , int val)
{
    if(x == NULL)
    {
        return false;
    }
    int curr = x->Value;
    cout << "curr: "<< curr <<  "  val:" << val << endl;
    if(curr== val)
    {
        cout << "value: " << val << " was found inside the BST no need to insert into tree" << endl;
    }
    
    if(val < curr )
    {
        
        cout <<  "went left" << endl;
        if(x->LeftChild == NULL)
        {
            cout << "Value is not in the tree...... appending value(" << val << ") as leaf to the left side of last node." << endl;
            TreeNode * newNode = new TreeNode;
            newNode->Value = val;
            newNode->LeftChild  = NULL;
            newNode->RightChild = NULL;
            newNode->parent     = x;
            x->LeftChild = newNode;
            
            return true;
            
        }
        return insert(x->LeftChild, val);
    }
    if(val > curr)
    {
        cout << "went right" << endl;
        if(x->RightChild == NULL)
        {
            cout << "Value is not in the tree...... appending value(" << val << ") as leaf to the right side of last node." << endl;
            TreeNode * newNode = new TreeNode;
            newNode->Value = val;
            newNode->LeftChild = NULL;
            newNode->RightChild = NULL;
            newNode->parent     = x;
            x->RightChild = newNode;
            
            return true;
            
        }
        return insert(x->RightChild,val);
    }
}
int main(){
    
    //BST x;
    TreeNode a,b,c,d,e,f,g,h;
    a.Value=50;
    b.Value=25;
    c.Value=100;
    d.Value=5;
    e.Value=30;
    f.Value=75;
    g.Value=125;
    h.Value=65;
    /*
    a.LeftChild  = &b;
    a.RightChild = &c;
    b.LeftChild  = &d;
    b.RightChild = &e;
    c.LeftChild  = &f;
    c.RightChild = &g;
     */
    TreeNode* x;
    int usin;
    while(1){
        cout << "." << endl;
        cout << "." << endl;
        cout << "." << endl;
        cout << "." << endl;
        cout << "-----Welcome to BST Tree Maker----------------" << endl;
        cout << "Starting base node will value 50.............." << endl;
        cout << endl;
        cout << "CHOOSE AN OPTION:"                              << endl;
        cout << "1. insert a value."                             << endl;
        cout << "2. delete a value."                             << endl;
        cout << "3. search to see if a tree has a certain value."<< endl;
        cout << "4. print out your tree."                        << endl;
        cout << "-----------------------------------------------"<< endl;
        cin >> usin;
        cout <<"."<< endl;
        cout <<"."<< endl;
        cout <<"."<< endl;
        
        bool flag;
        switch(usin){
            case 1:
                        cout << " choose a value to insert: " << endl;
                        cin  >> usin;
                        flag = insert(&a,usin);
            break;
            
            case 2:
                        cout << " choose a value to delete: " << endl;
                        cin  >> usin;
                        flag = deletion(&a,usin);
              break;
            case 3:
                        cout << " choose a value to search: " << endl;
                        cin  >> usin;
                        x = search(&a,usin);
              break;
            case 4:
                        printBST(&a);
              break;
        }
    }

    
    
    
    
}
