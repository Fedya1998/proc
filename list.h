//
// Created by fedya on 06.05.17.
//


#include <cstdlib>

#ifndef NEW_PROC_LIST_H
#define NEW_PROC_LIST_H

#endif //NEW_PROC_LIST_H

template <typename T> class List_Elem{
public:
    T * data;
    List_Elem<T> * next;
    List_Elem<T>():next(NULL){}
    ~List_Elem<T>(){
        if (!this)
            return;
        if (next == NULL) {
            delete this;
            delete data;
            return;
        }
        next->~List_Elem<T>();
    }
};

template <typename T> class List{
public:
    List_Elem<T> * first = NULL;
    List_Elem<T> * last = NULL;
    size_t count = 0;
    List<T>(){};
    ~List(){
        if (!first)
            return;
        first->~List_Elem();
    };
    int (*Compare)(List_Elem<T> * elem, char * string);
    void add_end(List_Elem<T> * elem){
        count++;
        last->next=elem;
    }
    List_Elem<T> * find(char * value){
        for(List_Elem<T> * elem = first; elem!=last; elem=elem->next){
            if (Compare(elem, value) == 0)
                return elem;
        }
        return NULL;
    }
};



