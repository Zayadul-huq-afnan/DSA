//here we will delete the last node


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


int main(){

    vector<int>arr = {1, 2, 3, 4, 5};

    //take a head
    node *head = NULL;
    node *tail;

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

            //now move the tail to the newly added node which is
            //the current last node of the list

            tail = tail->next;

        }
    }

    node *tmp = head;

    if(tmp->next == NULL){
        delete tmp;
        head = NULL;
    }

    else{

        //treverse to the second last node
        while(tmp->next->next != NULL){
            tmp = tmp->next;
        }

        //take the address of the last node
        node *del = tmp->next;
        //make the "next" filed of the second last node NULL
        tmp->next = NULL;
        //delete the last node;
        delete del;
    }

    node *curr = head;

    while(curr != NULL){
        cout<<curr->data<<"\n";

        curr = curr->next;
    }
}
