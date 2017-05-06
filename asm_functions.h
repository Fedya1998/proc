//
// Created by fedya on 06.05.17.
//

#include "small_shit.h"

#ifndef NEW_PROC_ASM_FUNCTIONS_H
#define NEW_PROC_ASM_FUNCTIONS_H

#endif //NEW_PROC_ASM_FUNCTIONS_H

void Translate(char * source, Buf<double> & prog, List<Label> & labels_list, Program_Info & info){
    d(15, printf("%s che prishlo to translate\n", source));

    char *sravn = source;

    char * word_end = strchr(source,'\0');


    if (*source == '.') {
        char s[] = "SET_LABEL";
        sravn = s;
    }



#define DEF_CMD(name, num, arg) \
    if (strcmp(sravn, #name) == 0){\
        d(4, printf("EEEEE PODOSHLO %s\n", #name));\
        if (#name != "SET_LABEL") prog.append(CMD_##name);\
        if (arg) {\
            if (num >= CMD_jmp && num <= CMD_call) {\
                char * word_end2 = The_End_Of_The_Word(word_end+1);\
                char the_end = *word_end2;\
                *word_end2 = '\0';\
                prog.append(labels_list.find("fda")->data->number);\
                *word_end2 = the_end;\
            } else if (#name != "SET_LABEL"){\
                if (*(word_end + 1) =='r' ) {/*Pushr popr*/\
                    /*printf("%c char popr push\n", *(cho+1));*/\
                    /*prog[index++] = (int)(*(cho+1)) - (int)'a' + 1;*/\
                    /*printf("Poidet v pushr %s\n", cho + 1);*/\
                    prog.append(Reg_To_Number)\
                    /*printf("%i che napisali\n", (int)prog[index - 1]);*/\
                } else {    /**/\
                    /*printf("%i pointer space ", cho - source);*/\
                    sscanf(cho + 1, "%lf", &prog[index++]);\
                }\
            } else {/*printf("LABELS MF");*/  /*Labels are here. Let's work it out*/\
                /*printf("%i space pointer ", cho - source);*/\
                cho2 = strchr(cho + 1, '\0');\
                p(8, ("Cho %i source %i\n", cho, source));\
                array[label_index].label_name = (char *) calloc(cho2 - cho, 1);\
                array[label_index].label_name[cho2 - cho] = '\0';\
                sscanf(cho + 1, "%s", array[label_index].label_name);\
                p(6, ("LABEL %s\n", array[label_index].label_name));\
                array[label_index++].value = index;/*The label points at the next command*/\
            }\
        }\
    }\
    else

#include "supercmd.h"
        ;
#undef DEF_CMD
}

Buf<double> To_Asm(Buf buf, Program_Info & info, List & labels_list){
    char *pointer_now_read = buf.get_buf();

    Buf<double> prog = Buf<double>(info.strings + info.arguments - 2 * info.labels - info.functions);



    for (int i = 0; i < info.strings; i++) {
        char* word_end = The_End_Of_The_Word(pointer_now_read);
        char the_end_of_the_word = *word_end;
        *word_end = '\0';

        Translate(pointer_now_read, prog, labels_list, info);

        *word_end = the_end_of_the_word;

        pointer_now_read = strchr(word_end, '\n') + 1;
    }
    return prog;
}
