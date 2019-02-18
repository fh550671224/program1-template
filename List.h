#ifndef LIST_H
#define LIST_H

class List{

    private:
    int index;
    Node * head, tail;

    public:
    List();
    ~List();
    void insert(int index, Planet * p);
    Planet* read(int index);
    bool remove(int index);
    unsigned size();
}

class Node{
    private:
        Planet * data;
        Node * next, prev;
}

#endif