
#include "fire20.h"
led_config_t g_led_config = { {
  // Key Matrix to LED Index
  {   NO_LED, NO_LED, NO_LED, NO_LED , NO_LED},
  {4 , 3 , 2 , 1 , 0 },
  {5 , 6 , 7 , 8 , 9 },
  {14, 13, 13, 11, 10},
  {15, 16, 17, 18, 19}
}, {
  // LED Index to Physical Position
   {224, 0}, {168, 0}, {112, 0}, {56, 0}, {0, 0},
   {0, 22} , {56, 22}, {112, 22}, {168, 22}, {224, 22},
   {224, 43}, {168, 43}, {112, 43}, {56, 43}, {0, 43},
   {0, 64} , {56, 64}, {112, 64}, {168, 64}, {224, 64}
}, {
  // LED Index to Flag
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2    
} };


