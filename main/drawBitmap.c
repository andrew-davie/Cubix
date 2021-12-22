    
#include "drawBitmap.h"
#include "main.h"
#include "bitpatterns.h"
#include "defines_from_dasm_for_c.h"
#include <string.h>

// duplicate from defines_cdfj.h
// Raw queue pointers
extern void* DDR;
#define RAM ((unsigned char*)DDR)


#define BMP_WIDTH 0
#define BMP_HEIGHT 1
#define BMP_CENTER_X 2
#define BMP_CENTER_Y 3
#define BMP_HEADER_BYTES 4




const unsigned char marker[] = {
    1,3,0,1+10,

    X_______

};



//   █████  ██████    █████    ███  ███   █████   ████
//   ██     ██   ██  ██   ██  ██ ████ ██  ██     ██  ██
//   ██     ██   ██  ██   ██  ██  ██  ██  ██     ██   
//   ████   █████    ███████  ██  ██  ██  ████    ████ 
//   ██     ██  ██   ██   ██  ██  ██  ██  ██         ██
//   ██     ██   ██  ██   ██  ██  ██  ██  ██     ██  ██
//   ██     ██   ██  ██   ██  ██  ██  ██  █████   ████



// FRAME 0 RIGHT

const unsigned char rightFacets000[] = {

    1,
    45,
    3,9,

    _______X
    ______XX
    _____XXX
    ____XXXX
    ____XXXX
    ____XXXX
    ____XXXX
    ____XXXX
    ____XXXX
    ____XXXX
    ____XXXX
    ____XXXX
    ____XXX_
    ____XX__
    ____X___
};


// FRAME 1, RIGHT FACE

const unsigned char right2Facets000[] = {

    1,
    42,
    4,6,

    _______X
    _____XXX
    ___XXXXX
    ___XXXXX
    ___XXXXX
    ___XXXXX
    ___XXXXX
    ___XXXXX
    ___XXXXX
    ___XXXXX
    ___XXXXX
    ___XXXXX
    ___XXXX_
    ___XX___
};


// FRAME 3, LEFT FACE

const unsigned char right3Facets000[] = {

    1,
    42,
    3,3,

    X_______
    XXX_____
    XXXXX___
    XXXXX___
    XXXXX___
    XXXXX___
    XXXXX___
    XXXXX___
    XXXXX___
    XXXXX___
    XXXXX___
    XXXXX___
    _XXXX___
    ___XX___
};


const unsigned char leftFacets000[] = {

    1,
    45,
    3,9,

    X_______
    XX______
    XXX_____
    XXXX____
    XXXX____
    XXXX____
    XXXX____
    XXXX____
    XXXX____
    XXXX____
    XXXX____
    XXXX____
    _XXX____
    __XX____
    ___X____
};


// FRAME 1, LEFT FACE

const unsigned char left2Facets000[] = {

    1,
    45,
    4,9,

    _X______
    _X______
    _XX_____
    _XX_____
    _XXX____
    _XXX____
    _XXX____
    _XXX____
    _XXX____
    _XXX____
    _XXX____
    __XX____
    __XX____
    ___X____
    ___X____
};



// FRAME 3 RIGHT FACE



const unsigned char left3Facets000[] = {

    1,
    48,
    3,9,

    ______X_
    ______X_
    _____XX_
    _____XX_
    ____XXX_
    ____XXX_
    ____XXX_
    ____XXX_
    ____XXX_
    ____XXX_
    ____XXX_
    ____XXX_
    ____XX__
    ____XX__
    ____X___
    ____X___
};


const unsigned char topFacet45_000[] = {

    1, 18, 2,18,

    XXXXXX__
    XXXXXX__
    XXXXXX__
    XXXXXX__
    XXXXXX__
    XXXXXX__
};


const unsigned char frontFacet45_000[] = {

    1, 36, 2,0,

    XXXXXX__
    XXXXXX__
    XXXXXX__
    XXXXXX__
    XXXXXX__
    XXXXXX__
    XXXXXX__
    XXXXXX__
    XXXXXX__
    XXXXXX__
    XXXXXX__
    XXXXXX__
};


const unsigned char topFacets000[] = {

    1,
    21,
    3,21,

    ___XX___
    __XXXX__
    _XXXXXX_
    XXXXXXXX
    _XXXXXX_
    __XXXX__
    ___XX___
};


const unsigned char top2Facets000[] = {

    1,
    21,
    3,18,

    ___XXX__
    _XXXXX__
    XXXXXXX_
    _XXXXXX_
    _XXXXXXX
    __XXXXX_
    __XXX___
};


// TOP FRAME 3


const unsigned char top3Facets000[] = {

    1,
    21,
    3,18,

    __XXX___
    __XXXXX_
    _XXXXXXX
    _XXXXXX_
    XXXXXXX_
    _XXXXX__
    ___XXX__
};


const unsigned char axis1Frame1Side000[] = {

    1,
    24,
    3,15,

    ________
    _X______
    __X_____
    ___X____
    ___XX___
    ____XX__
    _____X__
    ______X_
};


const unsigned char axis1Frame1Top000[] = {

    1,
    42,
    3,24,

    ____XX__
    ____XXX_
    ____XXXX
    ___XXXXX
    ___XXXXX
    ___XXXX_
    __XXXXX_
    __XXXXX_
    __XXXX__
    _XXXXX__
    _XXXXX__
    __XXX___
    ___XX___
    ____X___
};




const unsigned char axis1Frame2R000[] = {

    1,
    46,
    2,51,

    ____X___
    ____XX__
    ___XXXX_
    ___XXXX_
    ___XXXXX
    __XXXXXX
    __XXXXXX
    __XXXXX_
    _XXXXXX_
    _XXXXXX_
    _XXXXX__
    _XXXXX__
    __XXXX__
    ___XX___
    ___XX___
    ____X___
};


const unsigned char rollArrowRight[] = {

    2,48,0,0,

    ________ ________ 
    ________ ________ 
    _______X ________ 
    _______X ________ 
    ______XX X_______ 
    ______XX X_______ 
    ______XX X_______ 
    ______XX X_______ 
    ______XX X_______ 
    _______X XX______ 
    _______X XX______ 
    _______X XX______ 
    _______X XX______ 
    ________ XX______ 
    ________ XX______ 
    ________ XX______ 
    ________ XX______ 
    ________ XX______ 
    ________ XX______ 
    ________ XX______ 
    ________ XX______ 
    ________ XX______ 
    _____X__ XX______ 
    _____X__ XX______ 
    _____X_X XX______ 
    _____X_X XX______ 
    ____XX_X XX______ 
    ____XXXX XX______ 
    ____XXXX XX______ 
    ____XXXX X_______ 
    ___XXXXX X_______ 
    ___XXXXX X_______ 
    ___XXXXX X_______ 
    ___XXXXX ________ 
    __XXXXX_ ________ 
    __XXXXX_ ________ 
    __XXXXX_ ________ 
    __XXXXXX ________ 
    ___XXXXX ________ 
    ____XXXX ________ 
    _____XXX ________ 
    _______X ________ 
    ________ ________ 
    ________ ________ 
    ________ ________ 
    ________ ________ 
    ________ ________ 

};



const unsigned char cubeBoundary[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    21,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,21,               // center point (PIXELS) from 0,0 top left

    ________ 
    ________ 
    ___X____ 
    ________ 
    ________ 
    __X_____ 
    ________ 
    ________ 
    _X_X____ 
    ________ 
    ________ 
    X_X_____ 
    ________ 
    ________ 
    ___X____ 
    ________ 
    ________ 
    ____X___ 
    ________ 
    ________ 
    ________ 

};

const unsigned char cube1Boundary[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    21,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,21,               // center point (PIXELS) from 0,0 top left



    ________ 
    ________ 
    ________ 
    ________ 
    ________ 
    ________ 
    ________ 
    ________ 
    ________ 
    ________ 
    ________ 
    _X_X_X_X 
    ________ 
    ________ 
    X_X_X_X_ 
    ________ 
    ________ 
    ___X_X__ 
    ________ 
    ________ 
    ____X___ 

};




/*

ON-SCREEN INDEXING
27 cubes (invisible = 13,14,16,18,22,23,25,26)

visibleCube[27];

only 0-8 have a TOP
only 0,1,2,4,6,9,10,11,15,12,9 have a side
left: 0,4,6,9,12,15,18,21,24
right: 0,1,2,9,10,11,18,19,20

     8
   7   5
 6   4   2
   3   1
     0   
15      11
  12  10
     9
24      20
  21  19 
    18

DRAW ORDER:
24, 20, 21, 19, 18,
15, 11, 12, 10, 9
8, 7, 5, 6, 4, 2, 3, 1, 0


each 'plane' can rotate (but only one at a time)
only 0-8 have a TOP
front/face: 0 1 2 9 10 12 18 19 21

   6  7  8
   3  4  5
   0  1  2

DRAW ORDER:
0 1 2 3 4 5 6 7 8

//
  12  9  10
DRAW ORDER:
12 9 10
//
  21 18  19
DRAW ORDER:
21 18 19



faces of actual cube theCube[6]
* each face's planes [9]


BUT, since there is only one face which can rotate at any time
/// then handle that as a special-case

rotatingFace = 0-5
rotation = 0-3

so when drawing, we first determine if rotating face is horizontal
or vertical, and that determines our draw ordering







Rotations:

A 0->6, 1->3, 2->0, 3->7, 5->1, 6->8, 7->5, 8->2
  9->18, 12->21, 15->24
  18->27, 21->30, 24->33
  27->53, 30->50, 33-> 47
  47->15, 50->12, 53->9


ROTATION

0/1/2/3
    ^
    45°





*/








void drawBitmap(const unsigned char *bmp, char colour, int x, int y) {

    unsigned char pix[40];
    unsigned char pf[3][6];

    memset(pix, 0, 40);

    static unsigned char colourMask[8][3] = {

        { 0,     0,      0, },      // 0
        { 0,     0,   0xFF, },      // 1
        { 0,    0xFF,    0, },      // 2
        { 0,    0xFF, 0xFF, },      // 3
        { 0xFF,    0,    0, },      // 4
        { 0xFF,    0, 0xFF, },      // 5
        { 0xFF, 0xFF,    0, },      // 6
        { 0xFF, 0xFF, 0xFF, },      // 7
    };


    //trivial off-screen checks

    int pixL = (x - scrollX - (bmp[BMP_CENTER_X] << 14)) & 0xFFFFC000;
    int pixR = pixL + (bmp[BMP_WIDTH] << (14 + 3));
    if (pixR < 0 || pixL >= (40 << 14))
        return;

    int pixT = (y - ((scrollY & 0xFFFF0000) * 3)) - (bmp[BMP_CENTER_Y] << 16);
    int pixB = pixT + (bmp[BMP_HEIGHT] << 16);
    if (pixB < 0 || pixT >= (_ARENA_SCANLINES << 16))
        return;


    for (int line = 0; line * 3 < bmp[BMP_HEIGHT]; line++) {
        int scanline = line * 3 - bmp[BMP_CENTER_Y] + ((y - ((scrollY & 0xFFFF0000) * 3)) >> 16);
        if (scanline >= 0 && scanline < _ARENA_SCANLINES-2) {

            for (int ssl = 0; ssl < 3; ssl++) {

                int adjustedIndex = line * bmp[BMP_WIDTH] + BMP_HEADER_BYTES;
                unsigned int bits = 0;
                for (int i = 0; i < bmp[BMP_WIDTH]; i++)
                    bits = (bits << 8) | (bmp[adjustedIndex++] & colourMask[colour][ssl]);
                
                int bitRange = (bmp[BMP_WIDTH] << 3) - 1;
                int absBit = ((x - scrollX) >> 14) - bmp[BMP_CENTER_X];
                for (int bit = 0; bit <= bitRange; bit++) {
                    if (absBit >= 0 && absBit < 40)
                        pix[absBit] = (bits >> (bitRange - bit)) & 1;
                    absBit++;
                }

                // convert to PF format

                pf[ssl][0] = (pix[ 0] << 4)          // mirrored
                           | (pix[ 1] << 5)
                           | (pix[ 2] << 6)
                           | (pix[ 3] << 7);
                    
                pf[ssl][1] = (pix[ 4] << 7)          // normal
                           | (pix[ 5] << 6)
                           | (pix[ 6] << 5)
                           | (pix[ 7] << 4)
                           | (pix[ 8] << 3)
                           | (pix[ 9] << 2)
                           | (pix[10] << 1)
                           | (pix[11] /*<< 0*/);

                pf[ssl][2] = (pix[12] /*<< 0*/)          // mirrored
                           | (pix[13] << 1)
                           | (pix[14] << 2)
                           | (pix[15] << 3)
                           | (pix[16] << 4)
                           | (pix[17] << 5)
                           | (pix[18] << 6)
                           | (pix[19] << 7);

                pf[ssl][3] = (pix[20] << 4)          // mirrored
                           | (pix[21] << 5)
                           | (pix[22] << 6)
                           | (pix[23] << 7);
                    
                pf[ssl][4] = (pix[24] << 7)          // normal
                           | (pix[25] << 6)
                           | (pix[26] << 5)
                           | (pix[27] << 4)
                           | (pix[28] << 3)
                           | (pix[29] << 2)
                           | (pix[30] << 1)
                           | (pix[31] /*<< 0*/);

                pf[ssl][5] = (pix[32] /*<< 0*/)          // mirrored
                           | (pix[33] << 1)
                           | (pix[34] << 2)
                           | (pix[35] << 3)
                           | (pix[36] << 4)
                           | (pix[37] << 5)
                           | (pix[38] << 6)
                           | (pix[39] << 7);
            }

            unsigned char masker[6];
            masker[0] = ~(pf[0][0] | pf[1][0] | pf[2][0]);
            masker[1] = ~(pf[0][1] | pf[1][1] | pf[2][1]);
            masker[2] = ~(pf[0][2] | pf[1][2] | pf[2][2]);
            masker[3] = ~(pf[0][3] | pf[1][3] | pf[2][3]);
            masker[4] = ~(pf[0][4] | pf[1][4] | pf[2][4]);
            masker[5] = ~(pf[0][5] | pf[1][5] | pf[2][5]);

            extern const int bufPtr[][2];
            extern int pfBuffer;

            unsigned char *screen = RAM + bufPtr[0][pfBuffer] + scanline;

#define DST(a, offset) \
    *(screen + _ARENA_SCANLINES * a + offset)

#define SUB(a,b) \
    DST(a, b) = ((DST(a, b)) & masker[a]) | *ppf++;

#define SCR(offset) \
    ppf = pf[offset]; \
    SUB(0, offset) \
    SUB(1, offset) \
    SUB(2, offset) \
    SUB(3, offset) \
    SUB(4, offset) \
    SUB(5, offset)

            unsigned char *ppf;
            SCR(0)
            SCR(1)
            SCR(2)
        }
    }


}



// EOF
