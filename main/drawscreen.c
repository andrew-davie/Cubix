#include <stdbool.h>
#include "main.h"
#include "defines_from_dasm_for_c.h"
#include "defines.h"
#include "main.h"
#include "bitpatterns.h"
#include "sound.h"

#include "drawscreen.h"


extern int scrollX;
extern int scrollY;
extern int scrollSpeed;
extern int scrollYSpeed;
extern int targetScrollSpeed;
extern int targetYScrollSpeed;

int accel = 1536, accelY = 160*256;
int decel = 200, decelY =200*16;


// duplicate from defines_cdfj.h
// Raw queue pointers
extern void* DDR;
#define RAM ((unsigned char*)DDR)

extern int getRandom32();


#define SCROLLSPEED_MAXIMUM_X (30 << 8)
#define SCROLL_MAXIMUM_X (30 << 16)
#define SCROLL_MAXIMUM_Y (160 << 8)
#define SCROLL_MINIMUM 0

#define SCROLLEDGER 6
#define SCROLLEDGERY 11


void Scroll() {

    int rocky = rockfordX * PIXELS_PER_CHAR + (PIXELS_PER_CHAR >> 1);
    int halfway = (scrollX >> 14) + HALFWAYX;

    if ((halfway - SCROLLEDGER)- rocky > 0)
        targetScrollSpeed = -SCROLLSPEED_MAXIMUM_X;
    else if (rocky - (halfway + SCROLLEDGER) > 0)
        targetScrollSpeed = SCROLLSPEED_MAXIMUM_X;

    rocky = rockfordY * TRILINES + (TRILINES >> 1);
    halfway = (scrollY >> 16) + HALFWAYY;

    if ((halfway - SCROLLEDGERY) - rocky > 0)
        targetYScrollSpeed = -SCROLL_MAXIMUM_Y;
    else if (rocky - (halfway + SCROLLEDGERY) > 0)
        targetYScrollSpeed = SCROLL_MAXIMUM_Y;


    if (scrollSpeed < targetScrollSpeed) {
        scrollSpeed += accel;
        if (scrollSpeed > targetScrollSpeed)
            scrollSpeed = targetScrollSpeed;
    }

    if (scrollSpeed > targetScrollSpeed) {
        scrollSpeed -= accel;
        if (scrollSpeed < targetScrollSpeed)
            scrollSpeed = targetScrollSpeed;
    }
    if (scrollYSpeed < targetYScrollSpeed) {
        scrollYSpeed += accelY;
        if (scrollYSpeed > targetYScrollSpeed)
            scrollYSpeed = targetYScrollSpeed;
    }

    if (scrollYSpeed > targetYScrollSpeed) {
        scrollYSpeed -= accelY;
        if (scrollYSpeed < targetYScrollSpeed)
            scrollYSpeed = targetYScrollSpeed;
    }


    scrollX += scrollSpeed;
    if (scrollX > SCROLL_MAXIMUM_X) {
        scrollX = SCROLL_MAXIMUM_X;
        targetScrollSpeed = 0;
        scrollSpeed = 0;
    }

    if (scrollX < SCROLL_MINIMUM) {
        scrollX = SCROLL_MINIMUM;
        scrollSpeed = 0;
        targetScrollSpeed = 0;
    }


    scrollY += scrollYSpeed;
    if (scrollY > (14*PIECE_DEPTH/3-2)<<16) {
        scrollY = ((14*PIECE_DEPTH/3-2)<<16);
        scrollYSpeed = 0;
        targetYScrollSpeed = 0;
    }

    if (scrollY < SCROLL_MINIMUM) {
        scrollY = SCROLL_MINIMUM;
        scrollYSpeed = 0;
        targetYScrollSpeed = 0;
    }


    if (targetScrollSpeed < 0) {
        targetScrollSpeed += decel;
        if (targetScrollSpeed > 0)
            targetScrollSpeed = 0;
    }

    if (targetScrollSpeed > 0) {
        targetScrollSpeed -= decel;
        if (targetScrollSpeed < 0)
            targetScrollSpeed = 0;
    }

    if (targetYScrollSpeed < 0) {
        targetYScrollSpeed += decelY;
        if (targetYScrollSpeed > 0)
            targetYScrollSpeed = 0;
    }

    if (targetYScrollSpeed > 0) {
        targetYScrollSpeed -= decelY;
        if (targetYScrollSpeed < 0)
            targetYScrollSpeed = 0;
    }

}


unsigned char screenMask[6];


//extern int uncoverCount;

unsigned int mindex = 0;








int looneyIndex = 0;
int looneyY = 0x400;

int radius = 0;
int rinc = 10;



unsigned char *p0;
unsigned char *p1;
unsigned char *p2;
unsigned char *p3;
unsigned char *p4;
unsigned char *p5;

unsigned char bit[40];

void writeMask() {

    *p0++ &= (bit[0] << 4)
        | (bit[1] <<5 )
        | (bit[2] << 6)
        | (bit[3] << 7);

    *p1++  &= (bit[4] << 7)
        | (bit[5] << 6)
        | (bit[6] << 5)
        | (bit[7] << 4)
        | (bit[8] << 3)
        | (bit[9] << 2)
        | (bit[10] << 1)
        | (bit[11]);

    *p2++ &= (bit[12])
        | (bit[13] << 1)
        | (bit[14] << 2)
        | (bit[15] << 3)
        | (bit[16] << 4)
        | (bit[17] << 5)
        | (bit[18] << 6)
        | (bit[19] << 7);

    *p3++ &= (bit[20+0] << 4)
        | (bit[20+1] <<5 )
        | (bit[20+2] << 6)
        | (bit[20+3] << 7);

    *p4++  &= (bit[20+4] << 7)
        | (bit[20+5] << 6)
        | (bit[20+6] << 5)
        | (bit[20+7] << 4)
        | (bit[20+8] << 3)
        | (bit[20+9] << 2)
        | (bit[20+10] << 1)
        | (bit[20+11]);

    *p5++ &= (bit[20+12])
        | (bit[20+13] << 1)
        | (bit[20+14] << 2)
        | (bit[20+15] << 3)
        | (bit[20+16] << 4)
        | (bit[20+17] << 5)
        | (bit[20+18] << 6)
        | (bit[20+19] << 7);
}


int centerX = 19;
int centerY = 100;
int desiredRadius = 175;

extern const int bufPtr[][2];
extern int pfBuffer;

void circle(int leftX, int rightX, int r2) {
    

    p0 = &RAM[bufPtr[0][pfBuffer]];
    p1 = &RAM[bufPtr[1][pfBuffer]];
    p2 = &RAM[bufPtr[2][pfBuffer]];
    p3 = &RAM[bufPtr[3][pfBuffer]];
    p4 = &RAM[bufPtr[4][pfBuffer]];
    p5 = &RAM[bufPtr[5][pfBuffer]];

    for (int y = 0; y <= centerY; y++) {

        int distance = (centerX - leftX) * 7 * (centerX - leftX) * 7 + ((centerY - y)) * ((centerY - y));

        while (distance < r2 && leftX >= 0 && leftX <= centerX) {
            bit[leftX] = 1;
            leftX--;
            distance = (centerX - leftX) * 7 * (centerX - leftX) * 7 + ((centerY - y) ) * ((centerY - y) );
        }

        int distanceR = (centerX - rightX) * 7 * (centerX - rightX) * 7 + ((centerY - y) ) * ((centerY - y) );

        while (distanceR < r2 && rightX < 40 && rightX >= centerX) {
            bit[rightX] = 1;
            rightX++;
            distanceR = (centerX - rightX) * 7 * (centerX -rightX) * 7  + ((centerY - y) ) * ((centerY - y) );
        }

        writeMask();

    }

    for (int y = centerY+1; y <_ARENA_SCANLINES; y++) {

        int distance = (centerX - leftX) * 7 * (centerX - leftX) * 7 + ((centerY - y)) * ((centerY - y));

        while (distance > r2 && leftX >= -1 && leftX <= centerX) {
    
            if (leftX >= 0)
                bit[leftX] = 0;
    
            leftX++;
            distance = (centerX - leftX) * 7 * (centerX - leftX) * 7 + ((centerY - y) ) * ((centerY - y) );
        }

        int distanceR = (centerX - rightX) * 7 * (centerX - rightX) * 7 + ((centerY - y) ) * ((centerY - y) );

        while (distanceR > r2 && rightX <= 40 && rightX >= centerX) {

            if (rightX < 40)
                bit[rightX] = 0;
            rightX--;
            distanceR = (centerX - rightX) * 7 * (centerX -rightX) * 7  + ((centerY - y) ) * ((centerY - y) );
        }

        writeMask();

    }

}


void drawScreen(){

    unsigned char *p0 = RAM + bufPtr[0][pfBuffer];
    for (int sl = 0; sl < _ARENA_SCANLINES; sl++) {
        *(p0 + 0 * _ARENA_SCANLINES) = 0xFF; //getRandom32() & 0xFF;
        *(p0 + 1 * _ARENA_SCANLINES) = 0xFF; //getRandom32() & 0xFF;
        *(p0 + 2 * _ARENA_SCANLINES) = 0xFF; //getRandom32() & 0xFF;
        *(p0 + 3 * _ARENA_SCANLINES) = 0xFF; //getRandom32() & 0xFF;
        *(p0 + 4 * _ARENA_SCANLINES) = 0xFF; //getRandom32() & 0xFF;
        *(p0 + 5 * _ARENA_SCANLINES) = 0xFF; //getRandom32() & 0xFF;
        p0++;
    }

    return;
}


