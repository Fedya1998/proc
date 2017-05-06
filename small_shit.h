//
// Created by fedya on 06.05.17.
//

#include <cstdlib>
#include "list.h"

#ifndef NEW_PROC_SMALL_SHIT_H
#define NEW_PROC_SMALL_SHIT_H

#endif //NEW_PROC_SMALL_SHIT_H

const int BAD_LABEL = 0;

enum errors{
    ERR_BAD_INDEX
};



class Label{
public:
    char * name;
    size_t number;
    Label():name(NULL), number(BAD_LABEL){};
    ~Label(){
        free(name);
    }

};

template <typename T> class Buf{
public:
    size_t m_current;
    T operator [](int i){
        if (i < 0 || i > m_count)
            return ERR_BAD_INDEX;
        return m_data[i];
    }
    Buf(size_t size):m_count(size){};
    ~Buf(){
        free(m_data);
    }
    size_t get_count(){
        return m_count;
    }
    void set_buf(T * data){
        m_data = data;
    }
    T * get_buf(){
        return m_data;
    }
    void append(T value){
        if (m_current >= m_count){
            printf("Buffer overfilled\n");
            return;
        }
        this[m_current++] = value;
    }

private:
    T * m_data;
    size_t m_count;
};

class Program_Info {
public:
    size_t size;
    size_t strings;
    size_t arguments;
    size_t labels;
    size_t functions;
    Program_Info(Buf <char> & buf);
    ~Program_Info(){};
    void dump();
};

typedef struct labels {
    char *label_name = NULL;
    int value = BAD_LABEL;
};

char * The_End_Of_The_Word(char * source);

Program_Info::Program_Info(Buf <char> & buf): size(buf.get_count()),
                                     arguments(0),
                                     strings(1), 
                                     labels(0), 
                                     functions(0) {
    char *k = buf.get_buf();
    while (1) {
        k = strchr(k, ' ');
        /*printf("k = %i\n", k);
        printf("k-buf = %i\n", k-buf);  */
        if (!k) break;
        if (k > buf.get_buf() + size)
            break;
        arguments++;
        k++;
    }

    k = buf.get_buf();
    while (1) {
        k = strchr(k, '\n');
        /*printf("k = %i\n", k);
        printf("k-buf = %i\n", k-buf); */
        if (!k) break;
        if (k > buf.get_buf() + size)
            break;
        strings++;
        k++;
    }

    k = buf.get_buf();
    int labels_and_functions = 0;
    while (1) {
        k++;
        k = strchr(k, ':');
        if (!k) break;
        if (k > buf.get_buf() + size)
            break;
        Gde;
        labels_and_functions++;
    }
    k = buf.get_buf();
    while (1){
        k++;
        k = strchr(k, '.');
        if (!k)
            break;
        if (k > (buf.get_buf() + size))
            break;
        char * end_word = The_End_Of_The_Word(k+1);
        if (*end_word == ':')
            labels++;
    }
    functions = labels_and_functions - labels;
}

void Program_Info::dump() {
    printf("size = %lu\n", size);
    printf("strings = %lu\n", size);
    printf("arguments = %lu\n", arguments);
    printf("labels = %lu\n", labels);
    printf("functions = %lu\n", functions);
}