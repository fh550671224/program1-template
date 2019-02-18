#include "List.h"
#include <iostream>


List::List(){
    head=NULL;
    tail=NULL;
    index=0;
}

List::~List(){
    Node * node = this->head;
    while(node != NULL){
        delete node->data;
    }
    node->=this->head;
    Node * node_next;
    while(node != NULL){
        node_next = node->next;
        delete node;
        node=node->next;
    }
}

void List::insert(int index, Planet * p){
  
}