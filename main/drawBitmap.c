    
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
    X_______
    X_______

};



// FRAME 0 RIGHT
#define RIGHTFACET(a,b,c) \
    1, \
    45, \
    3,9, \
a & _______X \
b & _______X \
c & _______X \
a & ______XX \
b & ______XX \
c & ______XX \
a & _____XXX \
b & _____XXX \
c & _____XXX \
a & ____XXXX \
b & ____XXXX \
c & ____XXXX \
a & ____XXXX \
b & ____XXXX \
c & ____XXXX \
a & ____XXXX \
b & ____XXXX \
c & ____XXXX \
a & ____XXXX \
b & ____XXXX \
c & ____XXXX \
a & ____XXXX \
b & ____XXXX \
c & ____XXXX \
a & ____XXXX \
b & ____XXXX \
c & ____XXXX \
a & ____XXXX \
b & ____XXXX \
c & ____XXXX \
a & ____XXXX \
b & ____XXXX \
c & ____XXXX \
a & ____XXXX \
b & ____XXXX \
c & ____XXXX \
a & ____XXX_ \
b & ____XXX_ \
c & ____XXX_ \
a & ____XX__ \
b & ____XX__ \
c & ____XX__ \
a & ____X___ \
b & ____X___ \
c & ____X___ \


const unsigned char rightFacets000[] = {
    RIGHTFACET(0,0,0)
};

const unsigned char rightFacets001[] = {
    RIGHTFACET(0xFF,0,0)
};

const unsigned char rightFacets010[] = {
    RIGHTFACET(0,0xFF,0)
};

const unsigned char rightFacets011[] = {
    RIGHTFACET(0xFF,0xFF,0)
};

const unsigned char rightFacets100[] = {
    RIGHTFACET(0,0,0xFF)
};

const unsigned char rightFacets101[] = {
    RIGHTFACET(0xFF,0,0xFF)
};

const unsigned char rightFacets110[] = {
    RIGHTFACET(0,0xFF,0xFF)
};

const unsigned char rightFacets111[] = {
    RIGHTFACET(0xFF,0xFF,0xFF)
};


// FRAME 1, RIGHT FACE
// GOOD
#define RIGHT2FACET(a,b,c) \
    1, \
    42, \
    4,6, \
a & _______X \
b & _______X \
c & _______X \
a & _____XXX \
b & _____XXX \
c & _____XXX \
a & ___XXXXX \
b & ___XXXXX \
c & ___XXXXX \
a & ___XXXXX \
b & ___XXXXX \
c & ___XXXXX \
a & ___XXXXX \
b & ___XXXXX \
c & ___XXXXX \
a & ___XXXXX \
b & ___XXXXX \
c & ___XXXXX \
a & ___XXXXX \
b & ___XXXXX \
c & ___XXXXX \
a & ___XXXXX \
b & ___XXXXX \
c & ___XXXXX \
a & ___XXXXX \
b & ___XXXXX \
c & ___XXXXX \
a & ___XXXXX \
b & ___XXXXX \
c & ___XXXXX \
a & ___XXXXX \
b & ___XXXXX \
c & ___XXXXX \
a & ___XXXXX \
b & ___XXXXX \
c & ___XXXXX \
a & ___XXXX_ \
b & ___XXXX_ \
c & ___XXXX_ \
a & ___XX___ \
b & ___XX___ \
c & ___XX___ \


const unsigned char right2Facets000[] = {
    RIGHT2FACET(0,0,0)
};

const unsigned char right2Facets001[] = {
    RIGHT2FACET(0xFF,0,0)
};

const unsigned char right2Facets010[] = {
    RIGHT2FACET(0,0xFF,0)
};

const unsigned char right2Facets011[] = {
    RIGHT2FACET(0xFF,0xFF,0)
};

const unsigned char right2Facets100[] = {
    RIGHT2FACET(0,0,0xFF)
};


const unsigned char right2Facets101[] = {
    RIGHT2FACET(0xFF,0,0xFF)
};

const unsigned char right2Facets110[] = {
    RIGHT2FACET(0,0xFF,0xFF)
};

const unsigned char right2Facets111[] = {
    RIGHT2FACET(0xFF,0xFF,0xFF)
};


// FRAME 3, LEFT FACE
#define RIGHT3FACET(a,b,c) \
    1,      /* width in BYTES (=8 pix/byte) (MAX =4) */\
    42,     /* height in SCANLINES (pref multiples of 3 -- TRIPIXs) */\
    3,3,    /* center point (PIXELS) from 0,0 top left */\
\
a & X_______ \
b & X_______ \
c & X_______ \
a & XXX_____ \
b & XXX_____ \
c & XXX_____ \
a & XXXXX___ \
b & XXXXX___ \
c & XXXXX___ \
a & XXXXX___ \
b & XXXXX___ \
c & XXXXX___ \
a & XXXXX___ \
b & XXXXX___ \
c & XXXXX___ \
a & XXXXX___ \
b & XXXXX___ \
c & XXXXX___ \
a & XXXXX___ \
b & XXXXX___ \
c & XXXXX___ \
a & XXXXX___ \
b & XXXXX___ \
c & XXXXX___ \
a & XXXXX___ \
b & XXXXX___ \
c & XXXXX___ \
a & XXXXX___ \
b & XXXXX___ \
c & XXXXX___ \
a & XXXXX___ \
b & XXXXX___ \
c & XXXXX___ \
a & XXXXX___ \
b & XXXXX___ \
c & XXXXX___ \
a & _XXXX___ \
b & _XXXX___ \
c & _XXXX___ \
a & ___XX___ \
b & ___XX___ \
c & ___XX___ \


const unsigned char right3Facets000[] = {
    RIGHT3FACET(0,0,0)
};

const unsigned char right3Facets001[] = {
    RIGHT3FACET(0xFF,0,0)
};

const unsigned char right3Facets010[] = {
    RIGHT3FACET(0,0xFF,0)
};

const unsigned char right3Facets011[] = {
    RIGHT3FACET(0xFF,0xFF,0)
};

const unsigned char right3Facets100[] = {
    RIGHT3FACET(0,0,0xFF)
};

const unsigned char right3Facets101[] = {
    RIGHT3FACET(0xFF,0,0xFF)
};

const unsigned char right3Facets110[] = {
    RIGHT3FACET(0,0xFF,0xFF)
};

const unsigned char right3Facets111[] = {
    RIGHT3FACET(0xFF,0xFF,0xFF)
};




#define LEFTFACET(a,b,c) \
    1, \
    45, \
    3,9, \
\
a & X_______ \
b & X_______ \
c & X_______ \
a & XX______ \
b & XX______ \
c & XX______ \
a & XXX_____ \
b & XXX_____ \
c & XXX_____ \
a & XXXX____ \
b & XXXX____ \
c & XXXX____ \
a & XXXX____ \
b & XXXX____ \
c & XXXX____ \
a & XXXX____ \
b & XXXX____ \
c & XXXX____ \
a & XXXX____ \
b & XXXX____ \
c & XXXX____ \
a & XXXX____ \
b & XXXX____ \
c & XXXX____ \
a & XXXX____ \
b & XXXX____ \
c & XXXX____ \
a & XXXX____ \
b & XXXX____ \
c & XXXX____ \
a & XXXX____ \
b & XXXX____ \
c & XXXX____ \
a & XXXX____ \
b & XXXX____ \
c & XXXX____ \
a & _XXX____ \
b & _XXX____ \
c & _XXX____ \
a & __XX____ \
b & __XX____ \
c & __XX____ \
a & ___X____ \
b & ___X____ \
c & ___X____ \


const unsigned char leftFacets000[] = {
    LEFTFACET(0,0,0)
};

const unsigned char leftFacets001[] = {
    LEFTFACET(0xFF,0,0)
};

const unsigned char leftFacets010[] = {
    LEFTFACET(0,0xFF,0)
};

const unsigned char leftFacets011[] = {
    LEFTFACET(0xFF,0xFF,0)
};

const unsigned char leftFacets100[] = {
    LEFTFACET(0,0,0xFF)
};


const unsigned char leftFacets101[] = {
    LEFTFACET(0xFF,0,0xFF)
};

const unsigned char leftFacets110[] = {
    LEFTFACET(0,0xFF,0xFF)
};

const unsigned char leftFacets111[] = {
    LEFTFACET(0xFF,0xFF,0xFF)
};

// FRAME 1, LEFT FACE

#define LEFT2FACET(a,b,c) \
    1, \
    45, \
    4,9, \
a & _X______ \
b & _X______ \
c & _X______ \
a & _X______ \
b & _X______ \
c & _X______ \
a & _XX_____ \
b & _XX_____ \
c & _XX_____ \
a & _XX_____ \
b & _XX_____ \
c & _XX_____ \
a & _XXX____ \
b & _XXX____ \
c & _XXX____ \
a & _XXX____ \
b & _XXX____ \
c & _XXX____ \
a & _XXX____ \
b & _XXX____ \
c & _XXX____ \
a & _XXX____ \
b & _XXX____ \
c & _XXX____ \
a & _XXX____ \
b & _XXX____ \
c & _XXX____ \
a & _XXX____ \
b & _XXX____ \
c & _XXX____ \
a & _XXX____ \
b & _XXX____ \
c & _XXX____ \
a & __XX____ \
b & __XX____ \
c & __XX____ \
a & __XX____ \
b & __XX____ \
c & __XX____ \
a & ___X____ \
b & ___X____ \
c & ___X____ \
a & ___X____ \
b & ___X____ \
c & ___X____ \


const unsigned char left2Facets000[] = {
    LEFT2FACET(0,0,0)
};

const unsigned char left2Facets001[] = {
    LEFT2FACET(0xFF,0,0)
};

const unsigned char left2Facets010[] = {
    LEFT2FACET(0,0xFF,0)
};

const unsigned char left2Facets011[] = {
    LEFT2FACET(0xFF,0xFF,0)
};

const unsigned char left2Facets100[] = {
    LEFT2FACET(0,0,0xFF)
};


const unsigned char left2Facets101[] = {
    LEFT2FACET(0xFF,0,0xFF)
};

const unsigned char left2Facets110[] = {
    LEFT2FACET(0,0xFF,0xFF)
};

const unsigned char left2Facets111[] = {
    LEFT2FACET(0xFF,0xFF,0xFF)
};



// FRAME 3 RIGHT FACE
#define LEFT3FACET(a,b,c) \
\
    1,      \
    48,     \
    3,9,    \
\
a & ______X_ \
b & ______X_ \
c & ______X_ \
a & ______X_ \
b & ______X_ \
c & ______X_ \
a & _____XX_ \
b & _____XX_ \
c & _____XX_ \
a & _____XX_ \
b & _____XX_ \
c & _____XX_ \
a & ____XXX_ \
b & ____XXX_ \
c & ____XXX_ \
a & ____XXX_ \
b & ____XXX_ \
c & ____XXX_ \
a & ____XXX_ \
b & ____XXX_ \
c & ____XXX_ \
a & ____XXX_ \
b & ____XXX_ \
c & ____XXX_ \
a & ____XXX_ \
b & ____XXX_ \
c & ____XXX_ \
a & ____XXX_ \
b & ____XXX_ \
c & ____XXX_ \
a & ____XXX_ \
b & ____XXX_ \
c & ____XXX_ \
a & ____XXX_ \
b & ____XXX_ \
c & ____XXX_ \
a & ____XX__ \
b & ____XX__ \
c & ____XX__ \
a & ____XX__ \
b & ____XX__ \
c & ____XX__ \
a & ____X___ \
b & ____X___ \
c & ____X___ \
a & ____X___ \
b & ____X___ \
c & ____X___ \


const unsigned char left3Facets000[] = {
    LEFT3FACET(0,0,0)
};

const unsigned char left3Facets001[] = {
    LEFT3FACET(0xFF,0,0)
};

const unsigned char left3Facets010[] = {
    LEFT3FACET(0,0xFF,0)
};

const unsigned char left3Facets011[] = {
    LEFT3FACET(0xFF,0xFF,0)
};

const unsigned char left3Facets100[] = {
    LEFT3FACET(0,0,0xFF)
};


const unsigned char left3Facets101[] = {
    LEFT3FACET(0xFF,0,0xFF)
};

const unsigned char left3Facets110[] = {
    LEFT3FACET(0,0xFF,0xFF)
};

const unsigned char left3Facets111[] = {
    LEFT3FACET(0xFF,0xFF,0xFF)
};

#define TOPFACET45(a,b,c) \
a & XXXXXX__ \
b & XXXXXX__ \
c & XXXXXX__ \
a & XXXXXX__ \
b & XXXXXX__ \
c & XXXXXX__ \
a & XXXXXX__ \
b & XXXXXX__ \
c & XXXXXX__ \
a & XXXXXX__ \
b & XXXXXX__ \
c & XXXXXX__ \
a & XXXXXX__ \
b & XXXXXX__ \
c & XXXXXX__ \
a & XXXXXX__ \
b & XXXXXX__ \
c & XXXXXX__ \


const unsigned char topFacet45_000[] = {
    1, 18, 2,18,
    TOPFACET45(0,0,0)
};

const unsigned char topFacet45_001[] = {
    1, 18, 2,18,
    TOPFACET45(0xFF,0,0)
};

const unsigned char topFacet45_010[] = {
    1, 18, 2,18,
    TOPFACET45(0,0xFF,0)
};

const unsigned char topFacet45_011[] = {
    1, 18, 2,18,
    TOPFACET45(0xFF,0xFF,0)
};

const unsigned char topFacet45_100[] = {
    1, 18, 2,18,
    TOPFACET45(0,0,0xFF)
};


const unsigned char topFacet45_101[] = {
    1, 18, 2,18,
    TOPFACET45(0xFF,0,0xFF)
};

const unsigned char topFacet45_110[] = {
    1, 18, 2,18,
    TOPFACET45(0,0xFF,0xFF)
};

const unsigned char topFacet45_111[] = {
    1, 18, 2,18,
    TOPFACET45(0xFF,0xFF,0xFF)
};




#define FRONTFACET45(a,b,c) \
a & XXXXXX__ \
b & XXXXXX__ \
c & XXXXXX__ \
a & XXXXXX__ \
b & XXXXXX__ \
c & XXXXXX__ \
a & XXXXXX__ \
b & XXXXXX__ \
c & XXXXXX__ \
a & XXXXXX__ \
b & XXXXXX__ \
c & XXXXXX__ \
a & XXXXXX__ \
b & XXXXXX__ \
c & XXXXXX__ \
a & XXXXXX__ \
b & XXXXXX__ \
c & XXXXXX__ \
a & XXXXXX__ \
b & XXXXXX__ \
c & XXXXXX__ \
a & XXXXXX__ \
b & XXXXXX__ \
c & XXXXXX__ \
a & XXXXXX__ \
b & XXXXXX__ \
c & XXXXXX__ \
a & XXXXXX__ \
b & XXXXXX__ \
c & XXXXXX__ \
a & XXXXXX__ \
b & XXXXXX__ \
c & XXXXXX__ \
a & XXXXXX__ \
b & XXXXXX__ \
c & XXXXXX__ \


const unsigned char frontFacet45_000[] = {
    1, 36, 2,0,
    FRONTFACET45(0,0,0)
};

const unsigned char frontFacet45_001[] = {
    1, 36, 2,0,
    FRONTFACET45(0xFF,0,0)
};

const unsigned char frontFacet45_010[] = {
    1, 36, 2,0,
    FRONTFACET45(0,0xFF,0)
};

const unsigned char frontFacet45_011[] = {
    1, 36, 2,0,
    FRONTFACET45(0xFF,0xFF,0)
};

const unsigned char frontFacet45_100[] = {
    1, 36, 2,0,
    FRONTFACET45(0,0,0xFF)
};


const unsigned char frontFacet45_101[] = {
    1, 36, 2,0,
    FRONTFACET45(0xFF,0,0xFF)
};

const unsigned char frontFacet45_110[] = {
    1, 36, 2,0,
    FRONTFACET45(0,0xFF,0xFF)
};

const unsigned char frontFacet45_111[] = {
    1, 36, 2,3,
    FRONTFACET45(0xFF,0xFF,0xFF)
};






#define TOPFACET(a,b,c) \
a & ___XX___ \
b & ___XX___ \
c & ___XX___ \
a & __XXXX__ \
b & __XXXX__ \
c & __XXXX__ \
a & _XXXXXX_ \
b & _XXXXXX_ \
c & _XXXXXX_ \
a & XXXXXXXX \
b & XXXXXXXX \
c & XXXXXXXX \
a & _XXXXXX_ \
b & _XXXXXX_ \
c & _XXXXXX_ \
a & __XXXX__ \
b & __XXXX__ \
c & __XXXX__ \
a & ___XX___ \
b & ___XX___ \
c & ___XX___ \


const unsigned char topFacets000[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    21,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    3,21,               // center point (PIXELS) from 0,0 top left


    TOPFACET(0,0,0)
};

const unsigned char topFacets001[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    21,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    3,21,               // center point (PIXELS) from 0,0 top left


    TOPFACET(0xFF,0,0)
};

const unsigned char topFacets010[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    21,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    3,21,               // center point (PIXELS) from 0,0 top left


    TOPFACET(0,0xFF,0)
};

const unsigned char topFacets011[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    21,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    3,21,               // center point (PIXELS) from 0,0 top left


    TOPFACET(0xFF,0xFF,0)
};

const unsigned char topFacets100[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    21,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    3,21,               // center point (PIXELS) from 0,0 top left


    TOPFACET(0,0,0xFF)
};


const unsigned char topFacets101[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    21,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    3,21,               // center point (PIXELS) from 0,0 top left


    TOPFACET(0xFF,0,0xFF)
};

const unsigned char topFacets110[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    21,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    3,21,               // center point (PIXELS) from 0,0 top left


    TOPFACET(0,0xFF,0xFF)
};

const unsigned char topFacets111[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    21,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    3,21,               // center point (PIXELS) from 0,0 top left


    TOPFACET(0xFF,0xFF,0xFF)
};


// FRAME 1, TOP FACE
#define TOP2FACET(a,b,c) \
\
    1, \
    21, \
    3,18, \
\
a & ___XXX__ \
b & ___XXX__ \
c & ___XXX__ \
a & _XXXXX__ \
b & _XXXXX__ \
c & _XXXXX__ \
a & XXXXXXX_ \
b & XXXXXXX_ \
c & XXXXXXX_ \
a & _XXXXXX_ \
b & _XXXXXX_ \
c & _XXXXXX_ \
a & _XXXXXXX \
b & _XXXXXXX \
c & _XXXXXXX \
a & __XXXXX_ \
b & __XXXXX_ \
c & __XXXXX_ \
a & __XXX___ \
b & __XXX___ \
c & __XXX___ \


const unsigned char top2Facets000[] = {

    TOP2FACET(0,0,0)
};

const unsigned char top2Facets001[] = {
    TOP2FACET(0xFF,0,0)
};

const unsigned char top2Facets010[] = {
    TOP2FACET(0,0xFF,0)
};

const unsigned char top2Facets011[] = {
    TOP2FACET(0xFF,0xFF,0)
};

const unsigned char top2Facets100[] = {
    TOP2FACET(0,0,0xFF)
};


const unsigned char top2Facets101[] = {
    TOP2FACET(0xFF,0,0xFF)
};

const unsigned char top2Facets110[] = {
    TOP2FACET(0,0xFF,0xFF)
};

const unsigned char top2Facets111[] = {
    TOP2FACET(0xFF,0xFF,0xFF)
};






// TOP FRAME 3
#define TOP3FACET(a,b,c) \
\
    1, \
    21, \
    3,18,\
\
a & __XXX___ \
b & __XXX___ \
c & __XXX___ \
a & __XXXXX_ \
b & __XXXXX_ \
c & __XXXXX_ \
a & _XXXXXXX \
b & _XXXXXXX \
c & _XXXXXXX \
a & _XXXXXX_ \
b & _XXXXXX_ \
c & _XXXXXX_ \
a & XXXXXXX_ \
b & XXXXXXX_ \
c & XXXXXXX_ \
a & _XXXXX__ \
b & _XXXXX__ \
c & _XXXXX__ \
a & ___XXX__ \
b & ___XXX__ \
c & ___XXX__ \


const unsigned char top3Facets000[] = {
    TOP3FACET(0,0,0)
};

const unsigned char top3Facets001[] = {
    TOP3FACET(0xFF,0,0)
};

const unsigned char top3Facets010[] = {
    TOP3FACET(0,0xFF,0)
};

const unsigned char top3Facets011[] = {
    TOP3FACET(0xFF,0xFF,0)
};

const unsigned char top3Facets100[] = {
    TOP3FACET(0,0,0xFF)
};


const unsigned char top3Facets101[] = {
    TOP3FACET(0xFF,0,0xFF)
};

const unsigned char top3Facets110[] = {
    TOP3FACET(0,0xFF,0xFF)
};

const unsigned char top3Facets111[] = {
    TOP3FACET(0xFF,0xFF,0xFF)
};





#define AXIS1FRAME1SIDE(a,b,c) \
\
    1, \
    24, \
    3,15,\
\
a & ________ \
b & ________ \
c & ________ \
a & _X______ \
b & _X______ \
c & _X______ \
a & __X_____ \
b & __X_____ \
c & __X_____ \
a & ___X____ \
b & ___X____ \
c & ___X____ \
a & ___XX___ \
b & ___XX___ \
c & ___XX___ \
a & ____XX__ \
b & ____XX__ \
c & ____XX__ \
a & _____X__ \
b & _____X__ \
c & _____X__ \
a & ______X_ \
b & ______X_ \
c & ______X_ \


const unsigned char axis1Frame1Side000[] = {
    AXIS1FRAME1SIDE(0,0,0)
};

const unsigned char axis1Frame1Side001[] = {
    AXIS1FRAME1SIDE(0xFF,0,0)
};

const unsigned char axis1Frame1Side010[] = {
    AXIS1FRAME1SIDE(0,0xFF,0)
};

const unsigned char axis1Frame1Side011[] = {
    AXIS1FRAME1SIDE(0xFF,0xFF,0)
};

const unsigned char axis1Frame1Side100[] = {
    AXIS1FRAME1SIDE(0,0,0xFF)
};

const unsigned char axis1Frame1Side101[] = {
    AXIS1FRAME1SIDE(0xFF,0,0xFF)
};

const unsigned char axis1Frame1Side110[] = {
    AXIS1FRAME1SIDE(0,0xFF,0xFF)
};

const unsigned char axis1Frame1Side111[] = {
    AXIS1FRAME1SIDE(0xFF,0xFF,0xFF)
};



#define AXIS1FRAME1TOP(a,b,c) \
\
    1, \
    42, \
    3,24,\
\
a & ____XX__ \
b & ____XX__ \
c & ____XX__ \
a & ____XXX_ \
b & ____XXX_ \
c & ____XXX_ \
a & ____XXXX \
b & ____XXXX \
c & ____XXXX \
a & ___XXXXX \
b & ___XXXXX \
c & ___XXXXX \
a & ___XXXXX \
b & ___XXXXX \
c & ___XXXXX \
a & ___XXXX_ \
b & ___XXXX_ \
c & ___XXXX_ \
a & __XXXXX_ \
b & __XXXXX_ \
c & __XXXXX_ \
a & __XXXXX_ \
b & __XXXXX_ \
c & __XXXXX_ \
a & __XXXX__ \
b & __XXXX__ \
c & __XXXX__ \
a & _XXXXX__ \
b & _XXXXX__ \
c & _XXXXX__ \
a & _XXXXX__ \
b & _XXXXX__ \
c & _XXXXX__ \
a & __XXX___ \
b & __XXX___ \
c & __XXX___ \
a & ___XX___ \
b & ___XX___ \
c & ___XX___ \
a & ____X___ \
b & ____X___ \
c & ____X___ \


const unsigned char axis1Frame1Top000[] = {
    AXIS1FRAME1TOP(0,0,0)
};

const unsigned char axis1Frame1Top001[] = {
    AXIS1FRAME1TOP(0xFF,0,0)
};

const unsigned char axis1Frame1Top010[] = {
    AXIS1FRAME1TOP(0,0xFF,0)
};

const unsigned char axis1Frame1Top011[] = {
    AXIS1FRAME1TOP(0xFF,0xFF,0)
};

const unsigned char axis1Frame1Top100[] = {
    AXIS1FRAME1TOP(0,0,0xFF)
};

const unsigned char axis1Frame1Top101[] = {
    AXIS1FRAME1TOP(0xFF,0,0xFF)
};

const unsigned char axis1Frame1Top110[] = {
    AXIS1FRAME1TOP(0,0xFF,0xFF)
};

const unsigned char axis1Frame1Top111[] = {
    AXIS1FRAME1TOP(0xFF,0xFF,0xFF)
};



// a & ____X___ a & ________ \
// b & ____X___ b & ________ \
// c & ____X___ c & ________ \
// a & ____X___ a & ________ \
// b & ____X___ b & ________ \
// c & ____X___ c & ________ \
// a & ___XXX__ a & ________ \
// b & ___XXX__ b & ________ \
// c & ___XXX__ c & ________ \
// a & ___XXX__ a & ________ \
// b & ___XXX__ b & ________ \
// c & ___XXX__ c & ________ \
// a & ___XXXX_ a & ________ \
// b & ___XXXX_ b & ________ \
// c & ___XXXX_ c & ________ \
// a & __XXXXX_ a & ________ \
// b & __XXXXX_ b & ________ \
// c & __XXXXX_ c & ________ \
// a & __XXXXXX a & ________ \
// b & __XXXXXX b & ________ \
// c & __XXXXXX c & ________ \
// a & __XXXXXX a & ________ \
// b & __XXXXXX b & ________ \
// c & __XXXXXX c & ________ \
// a & _XXXXXX_ a & ________ \
// b & _XXXXXX_ b & ________ \
// c & _XXXXXX_ c & ________ \
// a & _XXXXXX_ a & ________ \
// b & _XXXXXX_ b & ________ \
// c & _XXXXXX_ c & ________ \
// a & __XXXXX_ a & ________ \
// b & __XXXXX_ b & ________ \
// c & __XXXXX_ c & ________ \
// a & __XXXX__ a & ________ \
// b & __XXXX__ b & ________ \
// c & __XXXX__ c & ________ \
// a & ___XXX__ a & ________ \
// b & ___XXX__ b & ________ \
// c & ___XXX__ c & ________ \
// a & ___XXX__ a & ________ \
// b & ___XXX__ b & ________ \
// c & ___XXX__ c & ________ \
// a & ____X___ a & ________ \
// b & ____X___ b & ________ \
// c & ____X___ c & ________ \
// a & ____X___ a & ________ \
// b & ____X___ b & ________ \
// c & ____X___ c & ________ \



#define AXIS1FRAME2R(a,b,c) \
\
    1, \
    46, \
    2,51,\
\
a & ____X___ \
b & ____X___ \
c & ____X___ \
a & ____XX__ \
b & ____XX__ \
c & ____XX__ \
a & ___XXXX_ \
b & ___XXXX_ \
c & ___XXXX_ \
a & ___XXXX_ \
b & ___XXXX_ \
c & ___XXXX_ \
a & ___XXXXX \
b & ___XXXXX \
c & ___XXXXX \
a & __XXXXXX \
b & __XXXXXX \
c & __XXXXXX \
a & __XXXXXX \
b & __XXXXXX \
c & __XXXXXX \
a & __XXXXX_ \
b & __XXXXX_ \
c & __XXXXX_ \
a & _XXXXXX_ \
b & _XXXXXX_ \
c & _XXXXXX_ \
a & _XXXXXX_ \
b & _XXXXXX_ \
c & _XXXXXX_ \
a & _XXXXX__ \
b & _XXXXX__ \
c & _XXXXX__ \
a & _XXXXX__ \
b & _XXXXX__ \
c & _XXXXX__ \
a & __XXXX__ \
b & __XXXX__ \
c & __XXXX__ \
a & ___XX___ \
b & ___XX___ \
c & ___XX___ \
a & ___XX___ \
b & ___XX___ \
c & ___XX___ \
a & ____X___ \
b & ____X___ \
c & ____X___ \


const unsigned char axis1Frame2R000[] = {
    AXIS1FRAME2R(0,0,0)
};

const unsigned char axis1Frame2R001[] = {
    AXIS1FRAME2R(0xFF,0,0)
};

const unsigned char axis1Frame2R010[] = {
    AXIS1FRAME2R(0,0xFF,0)
};

const unsigned char axis1Frame2R011[] = {
    AXIS1FRAME2R(0xFF,0xFF,0)
};

const unsigned char axis1Frame2R100[] = {
    AXIS1FRAME2R(0,0,0xFF)
};

const unsigned char axis1Frame2R101[] = {
    AXIS1FRAME2R(0xFF,0,0xFF)
};

const unsigned char axis1Frame2R110[] = {
    AXIS1FRAME2R(0,0xFF,0xFF)
};

const unsigned char axis1Frame2R111[] = {
    AXIS1FRAME2R(0xFF,0xFF,0xFF)
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


// const unsigned char wenhop[] = {

//     1,                  // width in BYTES (=8 pix/byte) (MAX =4)
//     9,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
//     0,0,               // center point (PIXELS) from 0,0 top left

//     X_XXX___ //_XXXX___ 
//     X_______ //XXXXXXX_ 
//     X_XXX_X_ //X_XXX_X_ 
//     X_______ //X_____X_ 
//     X___X___ //X_____X_ 
//     X_X_X_X_ //X_____X_ 
//     X_X_X___ //X_____X_ 
//     X_X_X___ //X_____X_ 
//     XXXXX_X_ //X_____X_ 
// };




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








void drawBitmap(const unsigned char *bmp, int x, int y) {

    unsigned char pix[40];
    unsigned char pf[3][6];

    memset(pix, 0, 40);


    //trivial off-screen checks

    int pixL = (x - scrollX - (bmp[BMP_CENTER_X] << 14)) & 0xFFFFC000;
    int pixR = pixL + (bmp[BMP_WIDTH] << (14 + 3));
    if (pixR < 0 || pixL >= (40 << 14))
        return;

    int pixT = (y - ((scrollY & 0xFFFF0000) * 3)) - (bmp[BMP_CENTER_Y] << 16);
    int pixB = pixT + (bmp[BMP_HEIGHT] << 16);
    if (pixB < 0 || pixT >= (_ARENA_SCANLINES << 16))
        return;


    for (int line = 0; line < bmp[BMP_HEIGHT]; line += 3) {
        int scanline = line - bmp[BMP_CENTER_Y] + ((y - ((scrollY & 0xFFFF0000) * 3)) >> 16);
        if (scanline >= 0 && scanline < _ARENA_SCANLINES-2) {

            for (int ssl = 0; ssl < 3; ssl++) {

                int adjustedIndex = (line + ssl) * bmp[BMP_WIDTH] + BMP_HEADER_BYTES;
                unsigned int bits = 0;
                for (int i = 0; i < bmp[BMP_WIDTH]; i++)
                    bits = (bits << 8) | bmp[adjustedIndex++];
                
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
