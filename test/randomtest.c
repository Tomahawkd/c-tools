//
// Created by Ghost on 2019/9/19.
//

#include <stdio.h>
#include "random/sys_random.h"
#include "time.h"

int main(int argc, char *argv[]) {
    uint8_t r[64];
    uint32_t i;

    randseed(time(NULL));
    getrandombits(r, 64);

    for (i = 0; i < 64u; ++i) {
        printf("0x%02X, ", r[i]);
        if (!((i + 1) & 31u)) printf("\n");
    }
}