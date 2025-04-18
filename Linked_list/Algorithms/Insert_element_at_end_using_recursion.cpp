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


node* createLinkList(vector<int>v , int ind){
    if(ind == v.size()){
        //index out of range means the previous node
        //was the last node of the list.
        //so the pointer of the last node will have a NULL value

        return NULL;
    }

    //create e node
    node *tmp = new node(v[ind]);

    //in the current node's pointer, save the address of the next node
    tmp->next = createLinkList(v, ind+1);

    return tmp;
}

int main(){

    vector<int>v = {1, 2 , 3 , 4 , 5};


    node *curr = createLinkList(v, 0);

    while(curr != NULL){
        cout<<curr->data<<"\n";

        curr = curr->next;
    }
}
