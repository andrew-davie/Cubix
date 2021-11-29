    
#include "drawBitmap.h"
#include "main.h"
#include "bitpatterns.h"
#include "defines_from_dasm_for_c.h"

// duplicate from defines_cdfj.h
// Raw queue pointers
extern void* DDR;
#define RAM ((unsigned char*)DDR)


#define BMP_WIDTH 0
#define BMP_HEIGHT 1
#define BMP_CENTER_X 2
#define BMP_CENTER_Y 3
#define BMP_HEADER_BYTES 4

// const unsigned char rocketShip[] = {

//     1,                  // width in BYTES (=8 pix/byte) (MAX =4)
//     105,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
//     3,105,               // center point (PIXELS) from 0,0 top left MULT OF 3

//     ________ //________   // 000    // colour 0
//     ________ //________   // 001    // colour 1
//     ________ //________   // 002    // colour 2 etc...
//     ___X____ //___X____   // 003 
//     ________ //________   // 004 
//     ________ //________   // 005 
//     ________ //________   // 006 
//     ___X____ //___X____   // 007 
//     ________ //___X____   // 008 
//     ___X____ //___X____   // 009 
//     ___X____ //___X____   // 010 
//     ________ //___X____   // 011 
//     __XXX___ //__XXX___   // 012 
//     __XXX___ //__XXX___   // 013 
//     ___XX___ //__XXX___   // 014 
//     __XXX___ //__XXX___   // 015 
//     __XXX___ //__XXX___   // 016 
//     ___XX___ //__XXX___   // 017 
//     ___X____ //__XXX___   // 018
//     __X_X___ //__XXX___   // 019 
//     ___XX___ //__XXX___   // 020 
//     ___X____ //__XXX___   // 021  // 00
//     __XXX___ //__XXX___   // 022  // 01
//     ___X____ //__XXX___   // 023  // 02
//     __XXX___ //__XXX___   // 024  // 03
//     _XXXXX__ //_XXXXX__   // 025  // 04
//     __XXX___ //__XXX___   // 026  // 05
//     _XXXXX__ //_XXXXX__   // 027  // 06
//     _XXXXX__ //_XXXXX__   // 028  // 07
//     __XXXX__ //_XXXXX__   // 029  // 08
//     _XXXXX__ //_XXXXX__   // 030  // 09
//     _XXX_X__ //_XXXXX__   // 031  // 10
//     __XX_X__ //_XXXXX__   // 032  // 11
//     _XXXXX__ //_XXXXX__   // 033  // 12
//     _XX_____ //_XXXXX__   // 034  // 13
//     __X_____ //_XXXXX__   // 035  // 14
//     _XXXXX__ //_XXXXX__   // 036  // 15
//     _XX_____ //_XXXXX__   // 037  // 16
//     __X_____ //_XXXXX__   // 038  // 17
//     XXXXXXX_ //XXXXXXX_   // 039  // 18
//     XXX___X_ //XXXXXXX_   // 040  // 19
//     _XX___X_ //XXXXXXX_   // 041  // 20
//     XXXXXXX_ //XXXXXXX_   // 042  // 00
//     XXXX_XX_ //XXXXXXX_   // 043  // 01
//     _XXX_XX_ //XXXXXXX_   // 044  // 02
//     XXXXXXX_ //XXXXXXX_   // 045  // 03
//     XXXXXXX_ //XXXXXXX_   // 046  // 04
//     _XXXXXX_ //XXXXXXX_   // 047  // 05
//     XXXXXXX_ //XXXXXXX_   // 048  // 06
//     XXXXXXX_ //XXXXXXX_   // 049  // 07
//     _XXXXXX_ //XXXXXXX_   // 050  // 08
//     XXXXXXX_ //XXXXXXX_   // 051  // 09
//     XXXXXXX_ //XXXXXXX_   // 052  // 10
//     _XXXXXX_ //XXXXXXX_   // 053  // 11
//     XXXXXXX_ //XXXXXXX_   // 054  // 12
//     XXXXXXX_ //XXXXXXX_   // 055  // 13
//     _XXXXXX_ //XXXXXXX_   // 056  // 14
//     XXXXXXX_ //XXXXXXX_   // 057  // 15
//     XXXXXXX_ //XXXXXXX_   // 058  // 16
//     _XXXXXX_ //XXXXXXX_   // 059  // 17
//     XXXXXXX_ //XXXXXXX_   // 060  // 18
//     XXXXXXX_ //XXXXXXX_   // 061  // 19
//     _XXXXXX_ //XXXXXXX_   // 062  // 20
//     XXXXXXX_ //XXXXXXX_   // 063  // 00
//     XXXXXXX_ //XXXXXXX_   // 064  // 01
//     _XXXXXX_ //XXXXXXX_   // 065  // 02
//     XXXXXXX_ //XXXXXXX_   // 066  // 12
//     XXXXXXX_ //XXXXXXX_   // 067  // 13
//     _XXXXXX_ //XXXXXXX_   // 068  // 14
//     XXXXXXX_ //XXXXXXX_   // 069  // 15
//     XXXXXXX_ //XXXXXXX_   // 070  // 16
//     _XXXXXX_ //XXXXXXX_   // 071  // 17
//     XXXXXXX_ //XXXXXXX_   // 072  // 18
//     XXXXXXX_ //XXXXXXX_   // 073  // 10
//     _XXXXXX_ //XXXXXXX_   // 074  // 11
//     _XXXXXX_ //_XXXXX__   // 075  // 12
//     _XXXXX__ //_XXXXX__   // 076  // 13
//     ________ //_XXXXX__   // 077  // 14
//     _XXXXX__ //_XXXXX__   // 078  // 15
//     __XXXX__ //_XXXXX__   // 079  // 16
//     __XXXX__ //_XXXXX__   // 080  // 17
//     __XXX___ //__XXX___   // 081  // 18
//     _____X__ //_XXXXX__   // 082  // 19
//     __XXXX__ //_XXXXX__   // 083  // 20
//     __XXX___ //__XXX___   // 084 
//     __XXX___ //__XXX___   // 085 
//     __XXX___ //__XXX___   // 086 
//     __XXX___ //__XXX___   // 087 
//     _XX_XX__ //_XXXXX__   // 088 
//     _XXXXX__ //_XXXXX__   // 089 
//     __XXX___ //__XXX___   // 090 
//     XXXXXXX_ //XXXXXXX_   // 091 
//     XXXXXXX_ //XXXXXXX_   // 092 
//     __XXX___ //__XXX___   // 093 
//     __XXX___ //XXXXXXX_   // 094 
//     X_XXXXX_ //XXXXXXX_   // 095 
//     __XXX___ //_XXXX___   // 096 
//     ________ //XXXXXXX_   // 097 
//     X_XXX_X_ //X_XXX_X_   // 098 
//     ___X____ //X_XXX_X_   // 099 
//     ________ //X__X__X_   // 100 
//     X__X__X_ //X_XXX_X_   // 101 
//     ________ //X_XXX_X_   // 102 
//     ________ //X_____X_   // 103 
//     X_____X_ //X_____X_   // 104 
// };

const unsigned char eroShip2[] = {



    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    60,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,60,               // center point (PIXELS) from 0,0 top left



    ________ //________   // 000    // colour 0
    ________ //________   // 001    // colour 1
    ________ //________   // 002    // colour 2 etc...
    ___XX___ //________   // 000    // colour 0
    ___XX___ //________   // 001    // colour 1
    ________ //________   // 002    // colour 2 etc...
    __XXXX__ //________   // 000    // colour 0
    __XXXX__ //________   // 001    // colour 1
    ________ //________   // 002    // colour 2 etc...
    _XXXXXX_ //________   // 000    // colour 0
    _XXXXXX_ //________   // 001    // colour 1
    ________ //________   // 002    // colour 2 etc...
    XXXXXXXX //________   // 000    // colour 0
    XXXXXXXX //________   // 001    // colour 1
    ________ //________   // 002    // colour 2 etc...
    XXXXXXXX //________   // 000    // colour 0
    XXXXXXX_ //________   // 001    // colour 1
    X_______ //________   // 002    // colour 2 etc...
    _XXXXXXX //________   // 000    // colour 0
    XXXXXX__ //________   // 001    // colour 1
    XX______ //________   // 002    // colour 2 etc...
    __XXXXXX //________   // 000    // colour 0
    XXXXX___ //________   // 001    // colour 1
    XXX_____ //________   // 002    // colour 2 etc...
    ___XXXXX //___X____   // 003 
    XXXX____ //________   // 004 
    XXXX____ //________   // 005 
    ____XXXX //___X____   // 003 
    XXXX____ //________   // 004 
    XXXX____ //________   // 005 
    ____XXXX //___X____   // 003 
    XXXX____ //________   // 004 
    XXXX____ //________   // 005 
    ____XXXX //___X____   // 003 
    XXXX____ //________   // 004 
    XXXX____ //________   // 005 
    ____XXXX //___X____   // 003 
    XXXX____ //________   // 004 
    XXXX____ //________   // 005 
    ____XXXX //___X____   // 003 
    XXXX____ //________   // 004 
    XXXX____ //________   // 005 
    ____XXXX //___X____   // 009 
    XXXX____ //___X____   // 010 
    XXXX____ //___X____   // 011 
    ____XXXX //__XXX___   // 015 
    XXXX____ //__XXX___   // 016 
    XXXX____ //__XXX___   // 017 
    ____XXX_ //__XXX___   // 018
    _XXX____ //__XXX___   // 019 
    _XXX____ //__XXX___   // 020 
    ____XX__ //__XXX___   // 018
    __XX____ //__XXX___   // 019 
    __XX____ //__XXX___   // 020 
    ____X___ //__XXX___   // 018
    ___X____ //__XXX___   // 019 
    ___X____ //__XXX___   // 020 
    ________
    ________
    ________


};


const unsigned char eroShip[] = {



    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    60,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,60,               // center point (PIXELS) from 0,0 top left



    ________ //________   // 000    // colour 0
    ________ //________   // 001    // colour 1
    ________ //________   // 002    // colour 2 etc...
    ___XX___ //________   // 000    // colour 0
    ___XX___ //________   // 001    // colour 1
    ___XX___ //________   // 002    // colour 2 etc...
    __XXXX__ //________   // 000    // colour 0
    __XXXX__ //________   // 001    // colour 1
    __XXXX__ //________   // 002    // colour 2 etc...
    _XXXXXX_ //________   // 000    // colour 0
    _XXXXXX_ //________   // 001    // colour 1
    _XXXXXX_ //________   // 002    // colour 2 etc...
    XXXXXXXX //________   // 000    // colour 0
    XXXXXXXX //________   // 001    // colour 1
    XXXXXXXX //________   // 002    // colour 2 etc...
    XXXXXXXX //________   // 000    // colour 0
    XXXXXXX_ //________   // 001    // colour 1
    XXXXXXXX //________   // 002    // colour 2 etc...
    _XXXXXXX //________   // 000    // colour 0
    XXXXXX__ //________   // 001    // colour 1
    XXXXXXXX //________   // 002    // colour 2 etc...
    __XXXXXX //________   // 000    // colour 0
    XXXXX___ //________   // 001    // colour 1
    XXXXXXXX //________   // 002    // colour 2 etc...
    ___XXXXX //___X____   // 003 
    XXXX____ //________   // 004 
    XXXXXXXX //________   // 005 
    ____XXXX //___X____   // 003 
    XXXX____ //________   // 004 
    XXXXXXXX //________   // 005 
    ____XXXX //___X____   // 003 
    XXXX____ //________   // 004 
    XXXXXXXX //________   // 005 
    ____XXXX //___X____   // 003 
    XXXX____ //________   // 004 
    XXXXXXXX //________   // 005 
    ____XXXX //___X____   // 003 
    XXXX____ //________   // 004 
    XXXXXXXX //________   // 005 
    ____XXXX //___X____   // 003 
    XXXX____ //________   // 004 
    XXXXXXXX //________   // 005 
    ____XXXX //___X____   // 009 
    XXXX____ //___X____   // 010 
    XXXXXXXX //___X____   // 011 
    ____XXXX //__XXX___   // 012 
    XXXX____ //__XXX___   // 013 
    XXXXXXXX //__XXX___   // 017 
    ____XXX_ //__XXX___   // 018
    _XXX____ //__XXX___   // 019 
    _XXXXXX_ //__XXX___   // 020 
    ____XX__ //__XXX___   // 018
    __XX____ //__XXX___   // 019 
    __XXXX__ //__XXX___   // 020 
    ____X___ //__XXX___   // 018
    ___X____ //__XXX___   // 019 
    ___XX___ //__XXX___   // 020 
    ________
    ________
    ________


};

const unsigned char topFace[] = {



    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    60,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,60,               // center point (PIXELS) from 0,0 top left



    ________ //________   // 000    // colour 0
    ________ //________   // 001    // colour 1
    ________ //________   // 002    // colour 2 etc...
    ___XX___ //________   // 000    // colour 0
    ___XX___ //________   // 001    // colour 1
    ___XX___ //________   // 002    // colour 2 etc...
    __XXXX__ //________   // 000    // colour 0
    __XXXX__ //________   // 001    // colour 1
    __XXXX__ //________   // 002    // colour 2 etc...
    _XXXXXX_ //________   // 000    // colour 0
    _XXXXXX_ //________   // 001    // colour 1
    _XXXXXX_ //________   // 002    // colour 2 etc...
    XXXXXXXX //________   // 000    // colour 0
    XXXXXXXX //________   // 001    // colour 1
    XXXXXXXX //________   // 002    // colour 2 etc...
    _XXXXXXX //________   // 000    // colour 0
    _XXXXXXX //________   // 001    // colour 1
    _XXXXXXX //________   // 002    // colour 2 etc...
    __XXXXX_ //________   // 000    // colour 0
    __XXXXX_ //________   // 001    // colour 1
    __XXXXX_ //________   // 002    // colour 2 etc...
    ___XXX__ //________   // 000    // colour 0
    ___XXX__ //________   // 001    // colour 1
    ___XXX__ //________   // 002    // colour 2 etc...
    ____X___ //___X____   // 003 
    ____X___ //________   // 004 
    ____X___ //________   // 005 
    ________ //___X____   // 003 
    ________ //________   // 004 
    ________ //________   // 005 
    ________ //___X____   // 003 
    ________ //________   // 004 
    ________ //________   // 005 
    ________ //___X____   // 003 
    ________ //________   // 004 
    ________ //________   // 005 
    ________ //___X____   // 003 
    ________ //________   // 004 
    ________ //________   // 005 
    ________ //___X____   // 003 
    ________ //________   // 004 
    ________ //________   // 005 
    ________ //___X____   // 009 
    ________ //___X____   // 010 
    ________ //___X____   // 011 
    ________ //__XXX___   // 012 
    ________ //__XXX___   // 013 
    ________ //__XXX___   // 014 
    ________ //__XXX___   // 015 
    ________ //__XXX___   // 016 
    ________ //__XXX___   // 017 
    ________ //__XXX___   // 018
    ________ //__XXX___   // 019 
    ________ //__XXX___   // 020 
    ________ //__XXX___   // 018
    ________ //__XXX___   // 019 
    ________ //__XXX___   // 020 
    ________ //__XXX___   // 018
    ________ //__XXX___   // 019 
    ________ //__XXX___   // 020 



};

const unsigned char innerFacets[] = {



    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    60,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,60,               // center point (PIXELS) from 0,0 top left



    ________ //________   // 000    // colour 0
    ________ //________   // 001    // colour 1
    ________ //________   // 002    // colour 2 etc...
    ________ //________   // 000    // colour 0
    ________ //________   // 001    // colour 1
    ________ //________   // 002    // colour 2 etc...
    ________ //________   // 000    // colour 0
    ________ //________   // 001    // colour 1
    ________ //________   // 002    // colour 2 etc...
    ________ //________   // 000    // colour 0
    ________ //________   // 001    // colour 1
    ________ //________   // 002    // colour 2 etc...
    ________ //________   // 000    // colour 0
    ________ //________   // 001    // colour 1
    ________ //________   // 002    // colour 2 etc...
    _______X //________   // 000    // colour 0
    ________ //________   // 001    // colour 1
    ________ //________   // 002    // colour 2 etc...
    ______XX //________   // 000    // colour 0
    ________ //________   // 001    // colour 1
    ________ //________   // 002    // colour 2 etc...
    _____XXX //________   // 000    // colour 0
    ________ //________   // 001    // colour 1
    ________ //________   // 002    // colour 2 etc...
    ____XXX_ //___X____   // 003 
    ________ //________   // 004 
    ________ //________   // 005 
    ____XX__ //___X____   // 003 
    ________ //________   // 004 
    ________ //________   // 005 
    ____X___ //___X____   // 003 
    ________ //________   // 004 
    ________ //________   // 005 
    ____X___ //___X____   // 003 
    ________ //________   // 004 
    ________ //________   // 005 
    ____X___ //___X____   // 003 
    ________ //________   // 004 
    ________ //________   // 005 
    ____X___ //___X____   // 003 
    ________ //________   // 004 
    ________ //________   // 005 
    ____X___ //___X____   // 009 
    ________ //___X____   // 010 
    ________ //___X____   // 011 
    ____X___ //__XXX___   // 015 
    ________ //__XXX___   // 016 
    ________ //__XXX___   // 017 
    ____X___ //__XXX___   // 018
    ________ //__XXX___   // 019 
    ________ //__XXX___   // 020 
    ____X___ //__XXX___   // 018
    ________ //__XXX___   // 019 
    ________ //__XXX___   // 020 
    ____X___ //__XXX___   // 018
    ________ //__XXX___   // 019 
    ________ //__XXX___   // 020 
    ________ //__XXX___   // 020 
    ________ //__XXX___   // 020 
    ________ //__XXX___   // 020 



};



#define RIGHTFACET(a,b,c) \
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

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    42,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,45,               // center point (PIXELS) from 0,0 top left


    RIGHTFACET(0,0,0)
};

const unsigned char rightFacets001[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    42,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,45,               // center point (PIXELS) from 0,0 top left


    RIGHTFACET(0xFF,0,0)
};

const unsigned char rightFacets010[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    42,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,45,               // center point (PIXELS) from 0,0 top left


    RIGHTFACET(0,0xFF,0)
};

const unsigned char rightFacets011[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    42,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,45,               // center point (PIXELS) from 0,0 top left


    RIGHTFACET(0xFF,0xFF,0)
};

const unsigned char rightFacets100[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    42,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,45,               // center point (PIXELS) from 0,0 top left


    RIGHTFACET(0,0,0xFF)
};


const unsigned char rightFacets101[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    42,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,45,               // center point (PIXELS) from 0,0 top left


    RIGHTFACET(0xFF,0,0xFF)
};

const unsigned char rightFacets110[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    42,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,45,               // center point (PIXELS) from 0,0 top left


    RIGHTFACET(0,0xFF,0xFF)
};

const unsigned char rightFacets111[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    42,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,45,               // center point (PIXELS) from 0,0 top left


    RIGHTFACET(0xFF,0xFF,0xFF)
};


#define RIGHT2FACET(a,b,c) \
a & ________ \
b & ________ \
c & ________ \
a & ______XX \
b & ______XX \
c & ______XX \
a & ____XXXX \
b & ____XXXX \
c & ____XXXX \
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
a & ________ \
b & ________ \
c & ________ \


const unsigned char right2Facets000[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    42,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,45,               // center point (PIXELS) from 0,0 top left


    RIGHT2FACET(0,0,0)
};

const unsigned char right2Facets001[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    42,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,45,               // center point (PIXELS) from 0,0 top left


    RIGHT2FACET(0xFF,0,0)
};

const unsigned char right2Facets010[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    42,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,45,               // center point (PIXELS) from 0,0 top left


    RIGHT2FACET(0,0xFF,0)
};

const unsigned char right2Facets011[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    42,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,45,               // center point (PIXELS) from 0,0 top left


    RIGHT2FACET(0xFF,0xFF,0)
};

const unsigned char right2Facets100[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    42,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,45,               // center point (PIXELS) from 0,0 top left


    RIGHT2FACET(0,0,0xFF)
};


const unsigned char right2Facets101[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    42,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,45,               // center point (PIXELS) from 0,0 top left


    RIGHT2FACET(0xFF,0,0xFF)
};

const unsigned char right2Facets110[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    42,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,45,               // center point (PIXELS) from 0,0 top left


    RIGHT2FACET(0,0xFF,0xFF)
};

const unsigned char right2Facets111[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    42,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,45,               // center point (PIXELS) from 0,0 top left


    RIGHT2FACET(0xFF,0xFF,0xFF)
};

#define LEFTFACET(a,b,c) \
a & ________ \
b & X_______ \
c & X_______ \
a & X_______ \
b & XX______ \
c & XX______ \
a & XX______ \
b & XXX_____ \
c & XXX_____ \
a & XXX_____ \
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

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    42,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,45,               // center point (PIXELS) from 0,0 top left


    LEFTFACET(0,0,0)
};

const unsigned char leftFacets001[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    42,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,45,               // center point (PIXELS) from 0,0 top left


    LEFTFACET(0xFF,0,0)
};

const unsigned char leftFacets010[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    42,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,45,               // center point (PIXELS) from 0,0 top left


    LEFTFACET(0,0xFF,0)
};

const unsigned char leftFacets011[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    42,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,45,               // center point (PIXELS) from 0,0 top left


    LEFTFACET(0xFF,0xFF,0)
};

const unsigned char leftFacets100[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    42,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,45,               // center point (PIXELS) from 0,0 top left


    LEFTFACET(0,0,0xFF)
};


const unsigned char leftFacets101[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    42,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,45,               // center point (PIXELS) from 0,0 top left


    LEFTFACET(0xFF,0,0xFF)
};

const unsigned char leftFacets110[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    42,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,45,               // center point (PIXELS) from 0,0 top left


    LEFTFACET(0,0xFF,0xFF)
};

const unsigned char leftFacets111[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    42,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,45,               // center point (PIXELS) from 0,0 top left


    LEFTFACET(0xFF,0xFF,0xFF)
};

#define LEFT2FACET(a,b,c) \
a & ________ \
b & ________ \
c & ________ \
a & ________ \
b & ________ \
c & ________ \
a & _X______ \
b & _X______ \
c & _X______ \
a & _X______ \
b & _X______ \
c & _X______ \
a & _X______ \
b & _XX_____ \
c & _XX_____ \
a & _XX_____ \
b & _XX_____ \
c & _XX_____ \
a & _XX_____ \
b & _XX_____ \
c & _XX_____ \
a & _XX_____ \
b & _XX_____ \
c & _XX_____ \
a & _XX_____ \
b & _XX_____ \
c & _XX_____ \
a & _XX_____ \
b & _XX_____ \
c & _XX_____ \
a & _XX_____ \
b & _XX_____ \
c & _XX_____ \
a & __X_____ \
b & __X_____ \
c & __X_____ \
a & __X_____ \
b & __X_____ \
c & __X_____ \
a & __X_____ \
b & __X_____ \
c & __X_____ \
a & __X_____ \
b & __X_____ \
c & __X_____ \


const unsigned char left2Facets000[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    45,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,48,               // center point (PIXELS) from 0,0 top left


    LEFT2FACET(0,0,0)
};

const unsigned char left2Facets001[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    45,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,48,               // center point (PIXELS) from 0,0 top left


    LEFT2FACET(0xFF,0,0)
};

const unsigned char left2Facets010[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    45,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,48,               // center point (PIXELS) from 0,0 top left


    LEFT2FACET(0,0xFF,0)
};

const unsigned char left2Facets011[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    45,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,48,               // center point (PIXELS) from 0,0 top left


    LEFT2FACET(0xFF,0xFF,0)
};

const unsigned char left2Facets100[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    45,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,48,               // center point (PIXELS) from 0,0 top left


    LEFT2FACET(0,0,0xFF)
};


const unsigned char left2Facets101[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    45,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,48,               // center point (PIXELS) from 0,0 top left


    LEFT2FACET(0xFF,0,0xFF)
};

const unsigned char left2Facets110[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    45,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,48,               // center point (PIXELS) from 0,0 top left


    LEFT2FACET(0,0xFF,0xFF)
};

const unsigned char left2Facets111[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    45,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,48,               // center point (PIXELS) from 0,0 top left


    LEFT2FACET(0xFF,0xFF,0xFF)
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
a & ________ \
b & ________ \
c & ________ \
a & ________ \
b & ________ \
c & ________ \
a & ________ \
b & ________ \
c & ________ \
a & ________ \
b & ________ \
c & ________ \
a & ________ \
b & ________ \
c & ________ \
a & ________ \
b & ________ \
c & ________ \
a & ________ \
b & ________ \
c & ________ \
a & ________ \
b & ________ \
c & ________ \
a & ________ \
b & ________ \
c & ________ \
a & ________ \
b & ________ \
c & ________ \
a & ________ \
b & ________ \
c & ________ \
a & ________ \
b & ________ \
c & ________ \
a & ________ \
b & ________ \
c & ________ \
a & ________ \
b & ________ \
c & ________ \


const unsigned char topFacet45_000[] = {
    1, 60, 8,60,
    TOPFACET45(0,0,0)
};

const unsigned char topFacet45_001[] = {
    1, 60, 8,60,
    TOPFACET45(0xFF,0,0)
};

const unsigned char topFacet45_010[] = {
    1, 60, 8,60,
    TOPFACET45(0,0xFF,0)
};

const unsigned char topFacet45_011[] = {
    1, 60, 8,60,
    TOPFACET45(0xFF,0xFF,0)
};

const unsigned char topFacet45_100[] = {
    1, 60, 8,60,
    TOPFACET45(0,0,0xFF)
};


const unsigned char topFacet45_101[] = {
    1, 60, 8,60,
    TOPFACET45(0xFF,0,0xFF)
};

const unsigned char topFacet45_110[] = {
    1, 60, 8,60,
    TOPFACET45(0,0xFF,0xFF)
};

const unsigned char topFacet45_111[] = {
    1, 60, 8,60,
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
a & ________ \
b & ________ \
c & ________ \
a & ________ \
b & ________ \
c & ________ \
a & ________ \
b & ________ \
c & ________ \
a & ________ \
b & ________ \
c & ________ \
a & ________ \
b & ________ \
c & ________ \
a & ________ \
b & ________ \
c & ________ \
a & ________ \
b & ________ \
c & ________ \
a & ________ \
b & ________ \
c & ________ \
a & ________ \
b & ________ \
c & ________ \


const unsigned char frontFacet45_000[] = {
    1, 60, 8,60,
    FRONTFACET45(0,0,0)
};

const unsigned char frontFacet45_001[] = {
    1, 60, 8,60,
    FRONTFACET45(0xFF,0,0)
};

const unsigned char frontFacet45_010[] = {
    1, 60, 8,60,
    FRONTFACET45(0,0xFF,0)
};

const unsigned char frontFacet45_011[] = {
    1, 60, 8,60,
    FRONTFACET45(0xFF,0xFF,0)
};

const unsigned char frontFacet45_100[] = {
    1, 60, 8,60,
    FRONTFACET45(0,0,0xFF)
};


const unsigned char frontFacet45_101[] = {
    1, 60, 8,60,
    FRONTFACET45(0xFF,0,0xFF)
};

const unsigned char frontFacet45_110[] = {
    1, 60, 8,60,
    FRONTFACET45(0,0xFF,0xFF)
};

const unsigned char frontFacet45_111[] = {
    1, 60, 8,60,
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
    8,57,               // center point (PIXELS) from 0,0 top left


    TOPFACET(0,0,0)
};

const unsigned char topFacets001[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    21,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,57,               // center point (PIXELS) from 0,0 top left


    TOPFACET(0xFF,0,0)
};

const unsigned char topFacets010[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    21,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,57,               // center point (PIXELS) from 0,0 top left


    TOPFACET(0,0xFF,0)
};

const unsigned char topFacets011[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    21,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,57,               // center point (PIXELS) from 0,0 top left


    TOPFACET(0xFF,0xFF,0)
};

const unsigned char topFacets100[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    21,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,57,               // center point (PIXELS) from 0,0 top left


    TOPFACET(0,0,0xFF)
};


const unsigned char topFacets101[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    21,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,57,               // center point (PIXELS) from 0,0 top left


    TOPFACET(0xFF,0,0xFF)
};

const unsigned char topFacets110[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    21,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,57,               // center point (PIXELS) from 0,0 top left


    TOPFACET(0,0xFF,0xFF)
};

const unsigned char topFacets111[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    21,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,57,               // center point (PIXELS) from 0,0 top left


    TOPFACET(0xFF,0xFF,0xFF)
};



#define TOP2FACET(a,b,c) \
a & _____X__ \
b & _____X__ \
c & _____X__ \
a & ___XXX__ \
b & ___XXX__ \
c & ___XXX__ \
a & _XXXXXX_ \
b & _XXXXXX_ \
c & _XXXXXX_ \
a & _XXXXXX_ \
b & _XXXXXX_ \
c & _XXXXXX_ \
a & __XXXXXX \
b & __XXXXXX \
c & __XXXXXX \
a & __XXXXXX \
b & __XXXXXX \
c & __XXXXXX \
a & ___XXXX_ \
b & ___XXXX_ \
c & ___XXXX_ \
a & ___XX___ \
b & ___XX___ \
c & ___XX___ \


const unsigned char top2Facets000[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    24,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,60,               // center point (PIXELS) from 0,0 top left


    TOP2FACET(0,0,0)
};

const unsigned char top2Facets001[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    24,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,60,               // center point (PIXELS) from 0,0 top left


    TOP2FACET(0xFF,0,0)
};

const unsigned char top2Facets010[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    24,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,60,               // center point (PIXELS) from 0,0 top left


    TOP2FACET(0,0xFF,0)
};

const unsigned char top2Facets011[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    24,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,60,               // center point (PIXELS) from 0,0 top left


    TOP2FACET(0xFF,0xFF,0)
};

const unsigned char top2Facets100[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    24,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,60,               // center point (PIXELS) from 0,0 top left


    TOP2FACET(0,0,0xFF)
};


const unsigned char top2Facets101[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    24,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,60,               // center point (PIXELS) from 0,0 top left


    TOP2FACET(0xFF,0,0xFF)
};

const unsigned char top2Facets110[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    24,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,60,               // center point (PIXELS) from 0,0 top left


    TOP2FACET(0,0xFF,0xFF)
};

const unsigned char top2Facets111[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    24,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    8,60,               // center point (PIXELS) from 0,0 top left


    TOP2FACET(0xFF,0xFF,0xFF)
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



const unsigned char shipFuelTank[] = {

    1, 24,
    2, 12,

_XXX____
_XXX____
________
_XXX____
_XXX____
________
___XX___
XXXXX___
________
___XX___
XXXXX___
________
____X___
XXXXX___
________
________
XXXXX___
________
________
_XXX____
________
________
_XXX____
________


// 1,9,
// -3,-10,

// ________
// ________
// ________
// ________
// XX______
// ________
// ________
// XX______
// ________


};


const unsigned char rocketShipFlame[] = {

    // 1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    // 21,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    // 3,0,               // center point (PIXELS) from 0,0 top left

    // ___X____ //__XXX___ 
    // ________ //__XXX___ 
    // __XXX___ //__XXX___ 
    // ___X____ //__XXX___ 
    // ________ //__XXX___ 
    // __XXX___ //__XXX___ 
    // ___X____ //__XXX___ 
    // ________ //__XXX___ 
    // __XXX___ //__XXX___ 
    // ___X____ //__XXX___ 
    // ________ //__XXX___ 
    // __XXX___ //__XXX___ 
    // ________ //___X____ 
    // ________ //___X____ 
    // ___X____ //___X____ 
    // ________ //___X____ 
    // ________ //___X____ 
    // ___X____ //___X____ 
    // ________ //___X____ 
    // ________ //___X____ 
    // ___X____ //___X____ 


    1,6,
    0,5,

    X_______
    X_______
    X_______
    X_______
    X_______
    X_______

};



const unsigned char flagUSA[] = {

    // 1,12,0,0,

    // _XX_____
    // X_______
    // X_______
    // _XX_____
    // X_______
    // ________
    // XXX_____
    // ________
    // ________
    // XXX_____
    // ________
    // ________


    1,3,0,0,

    _X______
    X_______
    X_______
    ________
    ________
    ________
    ________
    ________
    ________
    ________
    ________
    ________

};



/*

ON-SCREEN INDEXING
27 cubes (invisible = 13,14,16,18,22,23,25,26)

visibleCube[27];

only 0-8 have a TOP
only 0,1,2,3,6,9,10,11,15,12,9 have a side
left: 0,3,6,9,12,15,18,21,24
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





each of the 3 visible faces indexes to 'theCube'
orientation of faces is hardwired -- we move/swap contents when rotating

            B/2
           +--+--+--+
           |15|16|17|
           +--+--+--+
           |12|13|14|
           +--+--+--+
           | 9|10|11|
           +--+--+--+
 A/0        C/3        E/5        F/6
+--+--+--+ +--+--+--+ +--+--+--+ +--+--+--+
| 6| 7| 8| |24|25|26| |42|43|44| |51|52|53|
+--+--+--+ +--+--+--+ +--+--+--+ +--+--+--+
| 3| 4| 5| |21|22|23| |39|40|41| |48|49|50|
+--+--+--+ +--+--+--+ +--+--+--+ +--+--+--+
| 0| 1| 2| |18|19|20| |36|37|38| |45|46|47|
+--+--+--+ +--+--+--+ +--+--+--+ +--+--+--+
            D/4
           +--+--+--+
           |33|34|35|
           +--+--+--+
           |30|31|32|
           +--+--+--+
           |27|28|29|
           +--+--+--+

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








void drawBitmap(const unsigned char *bmp, int x, int y, bool relativeToScreen) {

    unsigned char pix[40];
    unsigned char pf[3][6];
    unsigned char masker[6];

    int screenStart = 0; //SCORE_SCANLINES; //relativeToScreen ? 0 : SCORE_SCANLINES;

    //for (int i = 0; i < 40; i++)
    //    pix[i] = 0;
    memset(pix, 0, 40);


    //trivial off-screen checks

    int pixL = (x - scrollX - (bmp[BMP_CENTER_X] << 14)) & 0xFFFFC000;
    int pixR = pixL + (bmp[BMP_WIDTH] << (14 + 3));
    if (pixR < 0 || pixL >= (40 << 14)) {
        return;

    }
    int pixT = (y - (scrollY * 3)) - (bmp[BMP_CENTER_Y] << 16);
    int pixB = pixT + (bmp[BMP_HEIGHT] << 16);
    if (pixB < 0 || pixT >= (_ARENA_SCANLINES << 16)) {
        return;
    }



    for (int line = 0; line < bmp[BMP_HEIGHT]; line += 3) {
        int scanline = line + screenStart - bmp[BMP_CENTER_Y] + ((y - (scrollY * 3)) >> 16);
        if (scanline >= screenStart && scanline < _ARENA_SCANLINES-2) {

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
                           | (pix[11] << 0);

                pf[ssl][2] = (pix[12] << 0)          // mirrored
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
                           | (pix[31] << 0);

                pf[ssl][5] = (pix[32] << 0)          // mirrored
                           | (pix[33] << 1)
                           | (pix[34] << 2)
                           | (pix[35] << 3)
                           | (pix[36] << 4)
                           | (pix[37] << 5)
                           | (pix[38] << 6)
                           | (pix[39] << 7);
            }

            masker[0] = ~(pf[0][0] | pf[1][0] | pf[2][0]);
            masker[1] = ~(pf[0][1] | pf[1][1] | pf[2][1]);
            masker[2] = ~(pf[0][2] | pf[1][2] | pf[2][2]);
            masker[3] = ~(pf[0][3] | pf[1][3] | pf[2][3]);
            masker[4] = ~(pf[0][4] | pf[1][4] | pf[2][4]);
            masker[5] = ~(pf[0][5] | pf[1][5] | pf[2][5]);

            extern const int bufPtr[][2];
            extern int pfBuffer;

            unsigned char *screen = RAM + bufPtr[0][pfBuffer] + scanline;

            unsigned char *ppf = pf[0];
            *screen = ((*screen) & masker[0]) | *ppf++;
            screen += _ARENA_SCANLINES;
            *screen = ((*screen) & masker[1]) | *ppf++;
            screen += _ARENA_SCANLINES;
            *screen = ((*screen) & masker[2]) | *ppf++;
            screen += _ARENA_SCANLINES;
            *screen = ((*screen) & masker[3]) | *ppf++;
            screen += _ARENA_SCANLINES;
            *screen = ((*screen) & masker[4]) | *ppf++;
            screen += _ARENA_SCANLINES;
            *screen = ((*screen) & masker[5]) | *ppf;
            screen -= 5 * _ARENA_SCANLINES - 1;

            ppf = pf[1];
            *screen = ((*screen) & masker[0]) | *ppf++;
            screen += _ARENA_SCANLINES;
            *screen = ((*screen) & masker[1]) | *ppf++;
            screen += _ARENA_SCANLINES;
            *screen = ((*screen) & masker[2]) | *ppf++;
            screen += _ARENA_SCANLINES;
            *screen = ((*screen) & masker[3]) | *ppf++;
            screen += _ARENA_SCANLINES;
            *screen = ((*screen) & masker[4]) | *ppf++;
            screen += _ARENA_SCANLINES;
            *screen = ((*screen) & masker[5]) | *ppf;
            screen -= 5 * _ARENA_SCANLINES - 1;

            ppf = pf[2];
            *screen = ((*screen) & masker[0]) | *ppf++;
            screen += _ARENA_SCANLINES;
            *screen = ((*screen) & masker[1]) | *ppf++;
            screen += _ARENA_SCANLINES;
            *screen = ((*screen) & masker[2]) | *ppf++;
            screen += _ARENA_SCANLINES;
            *screen = ((*screen) & masker[3]) | *ppf++;
            screen += _ARENA_SCANLINES;
            *screen = ((*screen) & masker[4]) | *ppf++;
            screen += _ARENA_SCANLINES;
            *screen = ((*screen) & masker[5]) | *ppf;

        }
    }


}



// EOF
