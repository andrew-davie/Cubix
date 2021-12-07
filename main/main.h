#ifndef __MAIN_H
#define __MAIN_H

    #include <stdbool.h>


#define ENABLE_SOUND 1
#define ENABLE_SHAKE 0

#define DEBUG_SLOWDOWN 1
#define GAMESPEED 11


#define PIECE_DEPTH 21


#define PIXELS_PER_CHAR 4
#define HALFWAYX 20
#define HALFWAYY (28+6)
#define TRILINES (PIECE_DEPTH/3)

#define SCANLINES (_ARENA_SCANLINES - SCORE_SCANLINES) 

#define PF0 0
#define PF1 1
#define PF2 2

enum Direction {
    LEFT = -1,
    RIGHT = 1,
};

extern unsigned char bufferedSWCHA;

extern int rockfordX;
extern int rockfordY;
extern int playerX, playerY;

extern int scrollX;
extern int scrollY;



enum DisplayMode {
    NORMAL,
    OVERVIEW,
};

extern enum DisplayMode displayMode;


extern unsigned char ColourConvert(unsigned char color);

#if ENABLE_SHAKE
extern int shakeX;
extern int shakeY;
#endif


#endif
