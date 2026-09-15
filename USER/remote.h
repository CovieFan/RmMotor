#ifndef __REMOTE_H
#define __REMOTE_H

#include "main.h"

typedef struct
{
int16_t ch0;
int16_t ch1;
int16_t ch2;
int16_t ch3;
int16_t sw1;
int16_t sw2;
} Remote_t;

extern volatile Remote_t remote;
void Remote_Init(void);
#endif


