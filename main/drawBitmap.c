    
#include "drawBitmap.h"
#include "main.h"
#include "bitpatterns.h"
#include "defines_from_dasm_for_c.h"
#include "shapes.h"

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
    unsigned char maskPix[40];

    unsigned char pf[3][6];
    unsigned char masker[6];


    memset(pix, 0, 40);
    memset(maskPix, 0, 40);

    static const unsigned char colourMask[8][3] = {

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
    int pixR = pixL + (bmp[BMP_WIDTH] << (14));
    if (pixR < 0 || pixL >= (40 << 14))
        return;

    int pixT = (y - ((scrollY & 0xFFFF0000) * 3)) - ((bmp[BMP_CENTER_Y]) << 16);
    int pixB = pixT + ((bmp[BMP_HEIGHT] * 3) << 16);
    if (pixB < 0 || pixT >= ((_ARENA_SCANLINES )<< 16))
        return;


    for (int line = 0; line < bmp[BMP_HEIGHT]; line ++) {
        int scanline = line * 3 - bmp[BMP_CENTER_Y] + ((y - ((scrollY & 0xFFFF0000) * 3)) >> 16);
        if (scanline >= 0 && scanline < _ARENA_SCANLINES) {

            for (int ssl = 0; ssl < 3; ssl++) {

                unsigned char *adjustedIndex = bmp + line * bmp[BMP_WIDTH] + BMP_HEADER_BYTES;
                unsigned char *maskAjdustedIndex = adjustedIndex + bmp[BMP_WIDTH] * bmp[BMP_HEIGHT];

                unsigned int bits = 0;
                unsigned int maskBits = 0xFFFFFFFF;

                for (int i = 0; i < bmp[BMP_WIDTH]; i++) {
                    bits = (bits << 8) | (*adjustedIndex++ & colourMask[colour][ssl]);
                    maskBits = (maskBits << 8) | *maskAjdustedIndex++;
                }

                int bitRange = (bmp[BMP_WIDTH] << 3) - 1;
                int absBit = ((x - scrollX) >> 14) - bmp[BMP_CENTER_X];
                for (int bit = bitRange; bit >= 0; bit--) {
                    // if (absBit >= 0 && absBit < 40) {
                        pix[absBit] = (bits >> bit) & 1;
                        maskPix[absBit++] = (maskBits >> bit) & 1;
                    // }
                    // absBit++;
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



                masker[0] =  ((maskPix[ 0] << 4)          // mirrored
                           | (maskPix[ 1] << 5)
                           | (maskPix[ 2] << 6)
                           | (maskPix[ 3] << 7)) ^ 0xFF;
                    
                masker[1] = ((maskPix[ 4] << 7)          // normal
                           | (maskPix[ 5] << 6)
                           | (maskPix[ 6] << 5)
                           | (maskPix[ 7] << 4)
                           | (maskPix[ 8] << 3)
                           | (maskPix[ 9] << 2)
                           | (maskPix[10] << 1)
                           | (maskPix[11] /*<< 0*/)) ^ 0xFF;

                masker[2] = ((maskPix[12] /*<< 0*/)          // mirrored
                           | (maskPix[13] << 1)
                           | (maskPix[14] << 2)
                           | (maskPix[15] << 3)
                           | (maskPix[16] << 4)
                           | (maskPix[17] << 5)
                           | (maskPix[18] << 6)
                           | (maskPix[19] << 7)) ^ 0xFF;

                masker[3] = ((maskPix[20] << 4)          // mirrored
                           | (maskPix[21] << 5)
                           | (maskPix[22] << 6)
                           | (maskPix[23] << 7)) ^ 0xFF;
                    
                masker[4] = ((maskPix[24] << 7)          // normal
                           | (maskPix[25] << 6)
                           | (maskPix[26] << 5)
                           | (maskPix[27] << 4)
                           | (maskPix[28] << 3)
                           | (maskPix[29] << 2)
                           | (maskPix[30] << 1)
                           | (maskPix[31] /*<< 0*/)) ^ 0xFF;

                masker[5] = ((maskPix[32] /*<< 0*/)          // mirrored
                           | (maskPix[33] << 1)
                           | (maskPix[34] << 2)
                           | (maskPix[35] << 3)
                           | (maskPix[36] << 4)
                           | (maskPix[37] << 5)
                           | (maskPix[38] << 6)
                           | (maskPix[39] << 7)) ^ 0xFF;



            }


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
