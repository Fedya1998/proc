//
// Created by fedya on 05.05.17.
//

#ifndef NEW_PROC_PROC_H
#define NEW_PROC_PROC_H

#endif //NEW_PROC_PROC_H


#include "stack.h"


template <typename T> class Processor {
public:
    Stack <T> stack = Stack <T>(MAX_STK);
#define reg(name) T name = 0;
#include "registers_to_define.h"
#undef reg

    Processor(){}
    ~Processor(){}
    void dump();
private:
    double * commands = NULL;
};

class Ram{
public:
    void * alloc(size_t size){
        pointer+=size;
        return pointer - size;
    }
private:
    void * data = calloc(1024, 10);
    void * pointer = data;
};