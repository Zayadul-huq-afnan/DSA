//here we will insert the element
//one by one at the beginning of linked list


#include<bits/stdc++.h>

using namespace std;


class node{

public:
    //make the data and link to next node
    //public so that you can access it from outside

    int data;

    node *next; //this is a pointer.

    //this is the constructor
    node(int num){
        data = num;
        next = NULL;
    }

};


node* createLinkList(vector<int>v , int ind, node* address){
    if(ind == v.size()){
        //index out of range means the previous node
        //was the last node of the list.
        //so the pointer of the last node will have a NULL value
        return address;
    }

    //create e node
    node *tmp = new node(v[ind]);

    //in the current node's pointer, save the address of the next node
    tmp->next = address;

    return createLinkList(v, ind+1, tmp); //pass the address of the current node to the next node

    //return NULL;
}

int main(){

    vector<int>v = {1, 2 , 3 , 4 , 5};


    node *curr = createLinkList(v, 0, NULL);

    while(curr != NULL){
        cout<<curr->data<<"\n";

        curr = curr->next;
    }
}
