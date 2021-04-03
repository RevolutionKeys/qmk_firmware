#pragma once

#include "quantum.h"


#define LAYOUT_25(\
     k00,      k02,      k04, \
     k10, k11, k12, k13, k14, \
     k20, k21, k22, k23, k24, \
     k30, k31, k32, k33, k34, \
     k40, k41, k42, k43, k44 \
     ) { \
    { k00, KC_NO, k02, KC_NO, k04, }, \
    { k10, k11, k12, k13, k14, }, \
    { k20, k21, k22, k23, k24, }, \
    { k30, k31, k32, k33, k34, }, \
    { k40, k41, k42, k43, k44 }  \
}
