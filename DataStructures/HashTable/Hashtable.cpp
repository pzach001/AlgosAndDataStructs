//
//  Hashtable.cpp
//  
//
//  Created by phillip zachariah on 1/12/18.
//
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct node{
    node* next;
    node* prev;
    int key;
    string value;
};
class HashTable{
    vector<node *> Hashtable;
    int sizeofTable;
    public:
            void  initTable(int x);
            int  hashFunc(string x);
            node*  LastNodeofList(int x);
            bool search(string x);
            void insert(string x);
            void deletion(string x);
    
};
void HashTable::initTable(int x){
    vector<node *> initTable(x);
    Hashtable = initTable;
    sizeofTable = x;
}
int HashTable::hashFunc(string x){
// Hashtable was taken from this weblink: https://stackoverflow.com/questions/8317508/hash-function-for-a-string
    int seed = 131;
    unsigned long hash = 0;
    for(int i = 0; i < x.length(); i++)
    {
        hash = (hash * seed) + x[i];
    }
    return hash % sizeofTable;
}

node* HashTable::LastNodeofList(int x){
    
    node* currnode = Hashtable.at(x);
    if( currnode == NULL)
    {
        cout << "First one of the list " << endl;
        return currnode;
    }
    else{
        while(currnode->next !=NULL)
        {
            cout << " moving to next node" << endl;
            currnode = currnode->next;
        }
        return currnode;
    }
}
bool HashTable::search(string x){
    bool flag = false;
    int key        =  hashFunc(x);
    node*currnode  =  Hashtable.at(key);
    if( currnode == NULL)
    {
        cout << "LIST WAS ALREADY EMPTY: NOT FOUND " << endl;
    }
    else{
            cout << " Check" << endl;
            if(currnode ->value == x)
            {
                cout << x << " Was found inside the Hash table! " << endl;
                //flag = true;
                return true;
            }
            while(currnode->next != NULL)
            {
                if(currnode->value == x)
                {
                    cout << x << " Was found inside the Hash table! " << endl;
                   // flag = true;
                    return true;
                }
                currnode = currnode->next;
            }
        //  cout << " Check" << endl;
        
    }
    return flag;
}

void HashTable::insert(string x)
{
    int key =  hashFunc(x);
    node* newnode   = new node;
    newnode->key    = key;
    newnode->value = x;
    newnode->next   = NULL;
    node* prevnode   = LastNodeofList(key);
    
    if(prevnode == NULL)
    {
        //NO NODE PRESENTED SO JUST INSERT THE NEWNODE.
        cout << "first node being inserted to  the list at location " << key << endl;
        Hashtable.at(key) = newnode;
       // cout << "test" << endl;
        newnode->prev = NULL;
        // cout << "test" << endl;
    }
    else{
        cout << "collision has occured appending new node to the end of the list at location " << key << endl;
        // There are node presents at the list on location key because prevnode actually is a node.
        prevnode->next = newnode;
        newnode->prev = prevnode;
        
    }
}
void  HashTable::deletion(string x){
     bool flag = search(x);
     bool check = false;
     if(flag == false)
     {
         cout << " cannot delete because its not there" << endl;
     }
    else{

            int key =  hashFunc(x);
            node*currnode  =  Hashtable.at(key);
            if(currnode->value == x)
            {
               
                cout << x << " was found! now deleting from the table" << endl;
                node* holdnode = currnode;
                Hashtable.at(key) = NULL;
                currnode->next = NULL;
                currnode->prev = NULL;

            }
            while(currnode->next != NULL)
            {
                if(currnode->value == x)
                {
                    cout << x << " was found! now deleting from the table" << endl;
                    node* holdnode = currnode;
                    node*prevnode  = holdnode->prev;
                    node*nextnode  = holdnode->next;
                    prevnode->next = holdnode->next;
                    nextnode->prev = holdnode->prev;
                    currnode->next = NULL;
                    currnode->prev = NULL;
                    break;
                    //free(currnode) ??????? test later
                }
                currnode = currnode->next;
           }
        }
        

    

    
}

int main(){
    HashTable x;
    string m = "phillip";
    x.initTable(10);

    x.insert(m);
    x.search(m);
    x.deletion(m);
    x.search(m);

    
    
    
    
    
    
}
