//here we will insert the element
//at a specified position


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

    int arr[] = {1, 2 , 3 , 4 , 5};

    //take a head
    node *head = NULL;
    node *tail;

    for(int i = 0 ; i < 5 ; i++){

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

    //insert the value at 4th postion
    int position = 5;

    int new_value = 30;

    node *new_node = new node(new_value);

    if(position == 1){
        new_node->next = head;
        head = new_node;
    }
    else{

        //if i want to insert it at position 4
        //so i need to reach node 3 first.

        node *tmp = head;

        while(position != 2){
            tmp = tmp->next;
            position--;
        }

        new_node->next = tmp->next;
        tmp->next = new_node;
    }


    node *curr = head;

    while(curr != NULL){
        cout<<curr->data<<"\n";

        curr = curr->next;
    }
}
