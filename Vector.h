#ifndef VECTOR_H
#define VECTOR_H

#include "Star.h"

class Vector{
    private:
        //int index;
        //int current_planets;
        Planet ** planets;
        int capacity;

    public:
        Vector();
        ~Vector();
        void insert(int index, Planet * p);
        Planet* read(int index);
        bool remove(int index);
        unsigned size();
};




#endif
