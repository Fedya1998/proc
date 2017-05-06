//
// Created by fedya on 05.05.17.
//

#ifndef NEW_PROC_PROC_FUNCTIONS_H
#define NEW_PROC_PROC_FUNCTIONS_H

#endif //NEW_PROC_PROC_FUNCTIONS_H
#include <cstdio>

#include "proc.h"
template <typename T>
void Processor<T>::dump() {
    printf("Proc:\n");
#define reg(name)\
    std::cout<<'\t'<<#name<<" = "<<name<<'\n';
#include "registers_to_define.h"
#undef reg
    stack.dump();
}

