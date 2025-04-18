//here we will create a doubly linked list

#include<bits/stdc++.h>

using namespace std;


class node{

public:
    //make the data and link to next node
    //public so that you can access it from outside

    int data;

    node *next; //this is a pointer.
    node *prev ;

    //this is the constructor
    node(int num){
        data = num;
        next = NULL;
        prev = NULL;
    }

};




int main(){

    vector<int>arr = {1, 2, 3, 4, 5};

    //take a head
    node *head = NULL;
    node *tail = NULL;

    for(int i = 0 ; i < arr.size() ; i++){

        //head NULL means there is currently no linked list
        if(head == NULL){
            //creating the first node of the linked list
            head = new node(arr[i]);

            //tail always locate at the last node of the list
            tail = head;
        }

        else{

            //create e new node and save it address in the tmp pointer
            node *tmp = new node(arr[i]);

            //save the address of the new node in the current node
            tail->next = tmp;

            //save the address of the previous node in the new node

            tmp->prev = tail;

            //now move the tail to the new node

            tail = tmp;

        }
    }


    node *curr = head;
    while(curr != NULL){
        cout<<curr->data<<" ";

        curr = curr->next;
    }

    cout<<"\n";

    curr = tail;

    while(curr != NULL){
        cout<<curr->data<<" ";
        curr = curr->prev;
    }

    cout<<"\n";
}
