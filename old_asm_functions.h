//
// Created by fedya on 05.05.17.
//

#ifndef NEW_PROC_ASM_FUNCTIONS_H
#define NEW_PROC_ASM_FUNCTIONS_H

#endif //NEW_PROC_ASM_FUNCTIONS_H


void Translate(char *source, double *prog, int *i, int *i2, labels *array, super_struct *sss) {
    assert(prog);
    d(15, printf("%s che prishlo to translate\n", source));

    char *sravn = source;

    char *cho = NULL;
    char *cho2 = NULL;
    cho = strchr(source,'\0');


    if (strcmp(source, ":") == 0) {
        char s[10] = "SET_LABEL";
        sravn = s;
    }

    int index = *i;
    int label_index = *i2;


#define DEF_CMD(name, num, arg, code) if (strcmp(sravn, #name) == 0){\
        d(4, printf("EEEEE PODOSHLO %s\n", #name));\
        if (#name != "SET_LABEL") prog[index++] = CMD_##name;\
        if (arg) {\
            if (num == CMD_OUT) {\
                if (*(cho + 1) != '0' && Number_Of_Ass == 2){\
                    char * end = strchr(cho + 1, '\0');\
                    char * output = (char *) calloc(end - cho, sizeof(char));\
                    strcpy(output, cho + 1);\
                    array_of_output[Number_Of_Strings] = output;\
                    /*printf("My output %s %i\n\n", output, output);*/\
                    prog[index++] = Number_Of_Strings++;\
                } else prog[index++] = 0;\
            } else if (num > 90 && num <= 101) {\
                char * cho2 = strchr(cho + 1, '\0');\
                char label_now[cho2 - cho + 1] = "";\
                /*printf("%i pointer space ", cho - source);*/\
                sscanf(cho + 1, "%s", label_now);\
                /*printf("LABEL NOW %s\n", label_now);*/\
                prog[index++] = Def_Label(label_now, array, sss);\
                /*printf("%i DEF_LABEL\n", prog[index - 1]);*/\
            } else if (#name != "SET_LABEL"){\
                if (#name == "PUSHR" || #name == "POPR") {\
                    /*printf("%c char popr push\n", *(cho+1));*/\
                    /*prog[index++] = (int)(*(cho+1)) - (int)'a' + 1;*/\
                    /*printf("Poidet v pushr %s\n", cho + 1);*/\
                    prog[index++] = atoi(cho + 1);\
                    /*printf("%i che napisali\n", (int)prog[index - 1]);*/\
                } else {\
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

    *i = index;
    *i2 = label_index;
}

void Execute(double *source, processor *This, super_struct *sss) {
    double value = 0;
#define DEF_CMD(name, num, arg, code) case CMD_##name: {p(7,("VIPOLNYAEM %s\n", #name));\
    if (arg) value = source[j++]; code break;}
    int j = 0, k = 1;
    while(k) {
        switch ((int) source[j++]) {
#include "supercmd.h"
            default: {
                printf("EXECUTE ERROR EPTA CHE DELAT' KAPITAN PSH PSH\n");
                printf("Command number %i tut napisano %s\n", j, source[j]);
                //assert(!"EXECUTE ERROR");
            }
        }
#undef DEF_CMD
    }
    Gde;
}

int Def_Label(char *str, labels *array, super_struct *sss) {
    p(11, ("CHE prishlo to def label pointer %i\n", str));
    p(11, ("CHE PRISHLO TO DEF_LABEL %s\n", str));
    for (int i = 0; i < sss->labels; i++) {
        //Gde;
        if (array[i].label_name) {
            p(12, ("array %s\n", array[i].label_name));
            p(12, ("my %s\n", str));
            if (strcmp(str, array[i].label_name) == 0) {
                p(10, ("KINDA PODOSHLO %s\n", array[i].label_name));
                p(10, ("NOMER %i\n", array[i].value));
                return array[i].value;
            }
        }
        //Gde;
    }
    p(11, ("BAD_LABEL"));
    return BAD_LABEL;
}

void Super_Struct_Ctor(char *buf, super_struct *sss) {
    sss->numbers = 0;
    sss->strings = 1;
    sss->labels = 0;
    char *k = buf;
    while (1) {
        k = strchr(k, ' ');
        /*printf("k = %i\n", k);
        printf("k-buf = %i\n", k-buf);  */
        if (!k) break;
        if (k > buf + sss->size) break;
        sss->numbers++;
        k++;
    }

    k = buf;
    while (1) {
        k = strchr(k, '\n');
        /*printf("k = %i\n", k);
        printf("k-buf = %i\n", k-buf); */
        if (!k) break;
        if (k > buf + sss->size) break;
        sss->strings++;
        k++;
    }

    k = buf;
    while (1) {
        k++;
        k = strchr(k, ':');
        //printf("k = %i\n", k);
        //printf("k-buf = %i\n", k-buf);
        if (!k) break;
        if (k > (buf + sss->size)) {printf("VIHOD"); break;}
        Gde;
        sss->labels++;
    }
}

double *Assembler(char *source, super_struct *sss, labels *array) {
    //printf("source %i\n", source);
    p(10,("Che prishlo to assembler\n%s\n\n", source));
    char *pointer_now_read = source;
    Gde;
    double * pointer_write = NULL;


    try {
        pointer_write = (double *) calloc(sss->strings + sss->numbers - 2 * sss->labels, sizeof(double));
        p(9,("error %i\n", (errno)));
        p(9,("try %i\n", pointer_write[sss->strings + sss->numbers - 2 * sss->labels - 1]));
    }
    catch(int i) {
        printf("Blya\n");
        pointer_write = NULL;
    }
    //pointer_write = (double *) calloc(sss->strings + sss->numbers - 2 * sss->labels - sss->functions, sizeof(double));
    p(10,("POINTER %i\n", pointer_write));
    Gde;
    int index = 0;
    int label_index = 0;
    int *index_to_write = &index;
    int *label_index_ptr = &label_index;
    char *p1 = NULL;
    char *p2 = NULL;
    bool bool1 = false, bool2 = false;

    for (int i = 0; i < sss->strings; i++) {// \r\n
        bool1 = false;
        bool2 = false;
        /*puts("\n-----------------\n");
        printf("%i pointer now read\n", pointer_now_read);*/
        p2 = strchr(pointer_now_read, '\n');
        p1 = strchr(pointer_now_read, ' ');
        //printf("%i p2\n", p2);
        if (p1 && (p1 < p2)) {
            *p1 = '\0';
            bool1 = true;
        }
        if (p2) {
            //*(p2 - 1) = '\0';
            *(p2) = '\0';
            bool2 = true;
        }


        if (p2 == NULL) {
            p2 = strchr(pointer_now_read + 1, '\0');
        }
/*
        printf("%i source\n", source);
        printf("%i p1\n", p1);

        printf("%i p2\n", p2);


        printf("%i index write now\n", index);

        puts("reading");
        puts(pointer_now_read);
*/
        Translate(pointer_now_read, pointer_write, index_to_write, label_index_ptr, array, sss, cpu1);

        if (bool1) *p1 = ' ';
        if (bool2) *(p2) = '\n';
        pointer_now_read = p2 + 1;
    }
    Gde;
    p(9,("pointer_write %i\n", pointer_write));
    return pointer_write;
}



