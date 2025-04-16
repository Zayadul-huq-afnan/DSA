//here we will delete a particular node using recursion


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


node* deleteNode(node *curr, int position){

    //means we reached the node we
    //want to delete
    if(position == 1){
        //take the address of the node
        //right after the node we want to delete
        node *tmp = curr->next;

        //delete the current node
        delete curr;

        //return the address of the next node of
        //the node we just deleted
        return tmp;
    }

    //now here just sent the address of the next node
    //of our current node.

    curr->next = deleteNode(curr->next, position-1);

    //just return the address of the current node

    return curr;
}

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


    node *curr = deleteNode(head, 5);

    while(curr != NULL){
        cout<<curr->data<<"\n";

        curr = curr->next;
    }
}
