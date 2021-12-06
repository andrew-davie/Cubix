#include "movePlayer.h"
#include "main.h"
#include "defines_from_dasm_for_c.h"
#include "defines.h"
#include "bitshapes.h"

#define RAM ((unsigned char*)DDR)


typedef struct {
    signed char x;
    signed char y;
    signed char face;
} OFFSET;

const OFFSET movementOffset[] = {

    // X   Y  DIR               RLDU

    {  0,  0,  0 },     // 0    0000
    {  0, -1,  0 },     // 1    0001
    {  0,  1,  0 },     // 2    0010
    {  0,  0,  0 },     // 3    0011
    { -1,  0, -1 },     // 4    0100
    { -1, -1, -1 },     // 5    0101
    { -1,  1, -1 },     // 6    0110
    {  0,  0,  0 },     // 7    0111
    {  1,  0,  1 },     // 8    1000
    {  1, -1,  1 },     // 9    1001
    {  1,  1,  1 },     // 10   1010
    {  0,  0,  0 },     // 11   1011
    {  0,  0,  0 },     // 12   1100
    {  0,  0,  0 },     // 13   1101
    {  0,  0,  0 },     // 14   1110
    {  0,  0,  0 },     // 15   1111
};

