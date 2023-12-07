//
// Created by NAT20 on 07/12/2023.
//

#ifndef CORE_H
#define CORE_H

#include <stdio.h>

namespace Framework
{
#define GE_LOG(x, ...) printf(x "\n", ##__VA_ARGS__) // This is a macro, the 2 ## are for when there are no arguments, it will still compile.
}




#endif //CORE_H
