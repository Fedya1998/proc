#include <iostream>
#include <cstring>
#include <ctype.h>

const int MAX_STK = 100;

#define DEBUG

#include <my_debug.h>
#include <assert.h>


#include "proc_functions.h"
#include "asm_functions.h"
#include "my_functions.h"
#include "super_table.h"

enum registers{
#define reg(name) name,
#include "registers_to_define.h"
#undef reg
    reg_empty
};

template <typename T> int Compare(List_Elem <T> * elem, char * string){
    if (strcmp(string, elem->data->name) == 0)
        return 0;
    return 1;
}

int Compare_Int(int value1, int value2){
    return value2 - value1;
}


int main() {
    
    FILE * test_ = fopen("test.txt", "r");

    Buf <char> buf = File_To_Buf_s(test_);

    Program_Info info = Program_Info(buf);
    info.dump();
    List <Label> label_list = List<Label>();
    label_list.Compare = Compare;
    Super_Table<int, const char *> super_table = Super_Table<int, const char *>(16);

#define reg(name)\
    super_table.data1[name] = name;\
    super_table.data2[name] = #name;

#include "registers_to_define.h"
#undef reg

    super_table.dump();
    super_table.compare1 = Compare_Int;
    super_table.compare2 = strcmp;


    std::cout<<super_table.find("rcx");

    return 0;
}