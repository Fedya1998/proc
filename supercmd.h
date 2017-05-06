//
// Created by fedya on 05.05.17.
//

#ifndef NEW_PROC_SUPERCMD_H
#define NEW_PROC_SUPERCMD_H

#endif //NEW_PROC_SUPERCMD_H

DEF_CMD(push, 65, 1)
DEF_CMD(pushr, 66, 1)
DEF_CMD(pop, 67, 1)
DEF_CMD(add, 70, 2)
DEF_CMD(sub, 71, 2)
DEF_CMD(mul, 72, 2)
DEF_CMD(div, 73, 1)
DEF_CMD(cmp, 75, 2)
DEF_CMD(func, 89, 0)
DEF_CMD(set_label, 90, 1)
DEF_CMD(jmp, 91, 1)
DEF_CMD(jbe, 92, 1)
DEF_CMD(jae, 93, 1)
DEF_CMD(jb, 94, 1)
DEF_CMD(ja, 95, 1)
DEF_CMD(je, 96, 1)
DEF_CMD(jne, 97, 1)
DEF_CMD(call, 101, 1)
DEF_CMD(ret, 102, 0)