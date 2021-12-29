#include "shapes.h"
#include "bitpatterns.h"

const unsigned char marker[] = {
    1,1,
    0,11,

    X_______

    X_______
};


const unsigned char layer0LeftCornerTopFrame3[] = {

    1,8,
    0,12,

    ________
    ________
    ________
    ________
    ________
    ________
    ________
    ________

    __XXXXXX
    __XXXXXX
    _XXXXXXX
    XXXXXXXX
    _XXXXXXX
    ___XXXXX
    _____XXX
    _______X

};

const unsigned char vertBlack[] = {

    1,8,
    0,12,

    ________
    ________
    ________
    ________
    ________
    ________
    ________
    ________

    X_______
    X_______
    X_______
    X_______
    X_______
    X_______
    X_______
    X_______

};

const unsigned char layer0RightCornerTopFrame3[] = {

    1,6,
    0,3,

    ________
    ________
    ________
    ________
    ________
    ________

    _______X
    XXXXXXXX
    _XXXXXXX
    __XXXXXX
    ____XXXX
    ______XX

};


const unsigned char leftCornerTop[] = {
    1,9,
    0,12,

    ________
    ________
    ________
    ________
    ________
    ________
    ________
    ________
    ________

    ___XXXXX
    __XXXXXX
    _XXXXXXX
    XXXXXXXX
    _XXXXXXX
    __XXXXXX
    ___XXXXX
    ____XXXX
    _____XXX

};


const unsigned char axis1FixupRightCornerTop[] = {

    1,17,
    0,12,

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
    ________
    ________
    ________
    ________
    ________
    ________

    _______X
    ______XX
    _____XXX
    ____XXXX
    ___XXXXX
    __XXXXXX
    _XXXXXXX
    XXXXXXXX
    XXXXXXXX
    XXXXXXXX
    XXXXXXX_
    XXXXXX__
    XXXXX___
    XXXX____
    XXX_____
    XX______
    X_______

};

const unsigned char axis1FixupFrame1[] = {

    1,17,
    0,12,

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
    ________
    ________
    ________
    ________
    ________
    ________

    X_______
    XX______
    XXX_____
    XXXX____
    XXXXX___
    XXXXX___
    XXXXXXX_
    XXXXXXXX
    XXXXXXXX
    XXXXXXXX
    XXXXXXXX
    _XXXXXXX
    __XXXXXX
    ___XXXXX
    ____XXXX
    _____XXX
    ______XX

};

const unsigned char leftCornerTopFrame3[] = {
    2,9,
    0,12,

    ________ ________
    ________ ________
    ________ ________
    ________ ________
    ________ ________
    ________ ________
    ________ ________
    ________ ________
    ________ ________

    ___XXXXX ________
    _XXXXXXX ________
    _XXXXXXX ________
    XXXXXXXX ________
    _XXXXXXX ________
    ___XXXXX ________
    _____XXX XXXXX___
    _______X XXXXX___
    ________ _X_XX___

};

const unsigned char rightCornerTopFrame3[] = {
    1,9,
    0,12,

    ________
    ________
    ________
    ________
    ________
    ________
    ________
    ________
    ________

    ___XXXX_
    __XXXXX_
    _XXXXXX_
    XXXXXXX_
    XXXXXX__
    XXXXXX__
    __XXX___
    _XXXX___
    __XXX___

};



const unsigned char frontCornerTop[] = {
    1,5,
    0,15,

    ________
    ________
    ________
    ________
    ________

    XXXXXXXX
    XXXXXXXX
    _XXXXXX_
    __XXXX__
    ___XX___

};


const unsigned char frontCornerTopFrame1[] = {

    1,8,
    2,24,

    ________
    ________
    ________
    ________
    ________
    ________
    ________
    ________

    XXXXXXXX
    _XXXXXXX
    _XXXXXXX
    _XXXXXXX
    __XXXXXX
    __XXXXXX
    ___XXXX_
    ___XXX__

};




const unsigned char axis1blackface[] = {

    1,8,
    4,24,

    ________
    ________
    ________
    ________
    ________
    ________
    ________
    ________

    XXXXX___
    XXXXX___
    XXXXXX__
    XXXXXX__
    XXXXXXX_
    XXXXXXX_
    XXXXXXXX
    XXXXXXXX

};


const unsigned char rightCornerTopFrame1[] = {

    1,8,
    2,27,

    ________
    ________
    ________
    ________
    ________
    ________
    ________
    ________

    XXXXXXX_
    XXXXXXX_
    XXXXXXXX
    XXXXXXXX
    XXXXXXX_
    XXXXX___
    XXX_____
    X_______

};


const unsigned char leftUpTop[] = {
    1,7,
    0,21,

    ________
    ________
    ________
    ________
    ________
    ________
    ________

    XXXXXXX_
    XXXXXXX_
    XXXXXXX_
    XXXXXXX_
    XXXXXXX_
    XXXXXXX_
    XXXXXXX_

};



const unsigned char rightCornerTop[] = {
    1,10,
    0,12,

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

    XXXXX___
    XXXXXX__
    XXXXXXX_
    XXXXXXXX
    XXXXXXX_
    XXXXXX__
    XXXXX___
    XXXX____
    XXX_____
    XX______
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
    18,
    2,12,

    ________
    ________
    ________
    ______X_
    _____XX_
    ____XXX_
    ___XXXX_
    ___XXXX_
    ___XXXX_
    ___XXXX_
    ___XXXX_
    ___XXXX_
    ___XXXX_
    ___XXXX_
    ___XXX__
    ___XX___
    ___X____
    ________

    _______X
    _______X
    ______XX
    _____XXX
    ____XXXX
    ___XXXXX
    ___XXXXX
    ___XXXXX
    ___XXXXX
    ___XXXXX
    ___XXXXX
    ___XXXXX
    ___XXXXX
    ___XXXX_
    ___XXXX_
    ___XXX__
    ___XX___
    ___X____

};


const unsigned char rightFacets000RHS[] = {

    1,
    16,
    2,6,

    ________
    ______X_
    _____XX_
    ____XXX_
    ___XXXX_
    ___XXXX_
    ___XXXX_
    ___XXXX_
    ___XXXX_
    ___XXXX_
    ___XXXX_
    ___XXXX_
    ___XXX__
    ___XX___
    ___X____
    ________

    ______X_
    _____XX_
    ____XXX_
    ___XXXX_
    ___XXXX_
    ___XXXX_
    ___XXXX_
    ___XXXX_
    ___XXXX_
    ___XXXX_
    ___XXXX_
    ___XXXX_
    ___XXXX_
    ___XXX__
    ___XX___
    ___X____
};



// FRAME 1, RIGHT FACE

const unsigned char right2Facets000[] = {

    1,
    15,
    3,6,

    ______X_
    ____XXX_
    __XXXXX_
    __XXXXX_
    __XXXXX_
    __XXXXX_
    __XXXXX_
    __XXXXX_
    __XXXXX_
    __XXXXX_
    __XXXXX_
    __XXXXX_
    __XXXX__
    __XX____
    ________

    ______XX
    ____XXXX
    __XXXXXX
    __XXXXXX
    __XXXXXX
    __XXXXXX
    __XXXXXX
    __XXXXXX
    __XXXXXX
    __XXXXXX
    __XXXXXX
    __XXXXXX
    __XXXXX_
    __XXXX__
    __XX____
};

const unsigned char right2Facets000RHS[] = {

    1,
    15,
    3,6,

    ______X_
    ____XXX_
    __XXXXX_
    __XXXXX_
    __XXXXX_
    __XXXXX_
    __XXXXX_
    __XXXXX_
    __XXXXX_
    __XXXXX_
    __XXXXX_
    __XXXXX_
    __XXXX__
    __XX____
    ________

    ______X_
    ____XXX_
    __XXXXX_
    __XXXXX_
    __XXXXX_
    __XXXXX_
    __XXXXX_
    __XXXXX_
    __XXXXX_
    __XXXXX_
    __XXXXX_
    __XXXXX_
    __XXXXX_
    __XXXX__
    __XX____
};

// FRAME 3, LEFT FACE

const unsigned char layer0Left01Frame3[] = {

    1,
    15,
    4,6,

    _X______
    _XXX____
    _XXXXX__
    _XXXXX__
    _XXXXX__
    _XXXXX__
    _XXXXX__
    _XXXXX__
    _XXXXX__
    _XXXXX__
    _XXXXX__
    _XXXXX__
    __XXXX__
    ____XX__
    ________

    _X______
    _XXX____
    _XXXXXX_
    _XXXXXX_
    _XXXXXX_
    _XXXXXX_
    _XXXXXX_
    _XXXXXX_
    _XXXXXX_
    _XXXXXX_
    _XXXXXX_
    _XXXXXX_
    _XXXXXX_
    __XXXXX_
    ____XX__
};

const unsigned char layer0Left2Frame3[] = {

    1,
    15,
    4,3,

    _X______
    _XXX____
    _XXXXX__
    _XXXXX__
    _XXXXX__
    _XXXXX__
    _XXXXX__
    _XXXXX__
    _XXXXX__
    _XXXXX__
    _XXXXX__
    _XXXXX__
    __XXXX__
    ____XX__
    ________

    _X______
    _XXX____
    _XXXXX__
    _XXXXX__
    _XXXXX__
    _XXXXX__
    _XXXXX__
    _XXXXX__
    _XXXXX__
    _XXXXX__
    _XXXXX__
    _XXXXX__
    _XXXXX__
    __XXXX__
    ____XX__
};

const unsigned char leftFacets000[] = {

    1,
    18,
    5,12,

    ________
    ________
    ________
    __X_____
    __XX____
    __XXX___
    __XXXX__
    __XXXX__
    __XXXX__
    __XXXX__
    __XXXX__
    __XXXX__
    __XXXX__
    __XXXX__
    ___XXX__
    ____XX__
    _____X__
    ________

    _X______
    _X______
    _XX_____
    _XXX____
    _XXXX___
    _XXXXX__
    _XXXXXX_
    _XXXXXX_
    _XXXXXX_
    _XXXXXX_
    _XXXXXX_
    _XXXXXX_
    _XXXXXX_
    __XXXXX_
    __XXXXX_
    ___XXX__
    ____XX__
    _____X__
};
const 
unsigned char leftFacets000LHS[] = {

    1,
    16,
    5,6,

    ________
    __X_____
    __XX____
    __XXX___
    __XXXX__
    __XXXX__
    __XXXX__
    __XXXX__
    __XXXX__
    __XXXX__
    __XXXX__
    __XXXX__
    ___XXX__
    ____XX__
    _____X__
    ________

    __X_____
    __XX____
    __XXX___
    __XXXX__
    __XXXXX_
    __XXXXX_
    __XXXXX_
    __XXXXX_
    __XXXXX_
    __XXXXX_
    __XXXXX_
    __XXXXX_
    __XXXXX_
    ___XXXX_
    ____XXX_
    _____XX_
};

// FRAME 1, LEFT FACE

const unsigned char left2Facets000[] = {

    1,
    16,
    4,15,

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
    __XX____
    ___X____
    ___X____

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
    __XX____
    ___X____
    ___X____

};



// FRAME 3 RIGHT FACE



const unsigned char layer0Right01Frame3[] = {
    // misnamed!  is right side

    1,
    17,
    2,9,

    ________
    _____X__
    _____X__
    ____XX__
    ____XX__
    ___XXX__
    ___XXX__
    ___XXX__
    ___XXX__
    ___XXX__
    ___XXX__
    ___XXX__
    ___XX___
    ___XX___
    ___X____
    ___X____
    ___X____

    _____X__
    _____X__
    ____XX__
    ____XX__
    ____XX__
    ___XXX__
    ___XXX__
    ___XXX__
    ___XXX__
    ___XXX__
    ___XXX__
    ___XXX__
    ___XX___
    ___XX___
    ___X____
    ___X____
    ___X____
};

const unsigned char layer0Right2Frame3[] = {
    // misnamed!  is right side

    1,
    18,
    3,0,

    ______X_
    ______X_
    ______X_
    _____XX_
    _____XX_
    _____XX_
    ____XXX_
    ____XXX_
    ____XXX_
    ____XXX_
    ____XXX_
    ____XX__
    ____XX__
    ____XX__
    ____X___
    ____X___
    ____X___
    ________

    ______X_
    ______X_
    ______X_
    _____XX_
    _____XX_
    _____XX_
    ____XXX_
    ____XXX_
    ____XXX_
    ____XXX_
    ____XXX_
    ____XXX_
    ____XX__
    ____XX__
    ____XX__
    ____X___
    ____X___
    ____X___
};


const unsigned char topFacet45_000[] = {

    1, 7,
    2,18,

    XXXXXX__
    XXXXXX__
    XXXXXX__
    XXXXXX__
    XXXXXX__
    XXXXXX__
    ________

    XXXXXXX_
    XXXXXXX_
    XXXXXXX_
    XXXXXXX_
    XXXXXXX_
    XXXXXXX_
    XXXXXXX_
};


const unsigned char layer2Right2TopFrame2[] = {

    1, 7,
    2,18,

    XXXXXX__
    XXXXXX__
    XXXXXX__
    XXXXXX__
    XXXXXX__
    XXXXXX__
    ________

    XXXXXX__
    XXXXXX__
    XXXXXX__
    XXXXXX__
    XXXXXX__
    XXXXXX__
    XXXXXX__
};


const unsigned char frontFacet45_000[] = {

    1, 14,
    3,3,

    ________
    _XXXXXX_
    _XXXXXX_
    _XXXXXX_
    _XXXXXX_
    _XXXXXX_
    _XXXXXX_
    _XXXXXX_
    _XXXXXX_
    _XXXXXX_
    _XXXXXX_
    _XXXXXX_
    _XXXXXX_
    ________

    _XXXXXXX
    _XXXXXXX
    _XXXXXXX
    _XXXXXXX
    _XXXXXXX
    _XXXXXXX
    _XXXXXXX
    _XXXXXXX
    _XXXXXXX
    _XXXXXXX
    _XXXXXXX
    _XXXXXXX
    _XXXXXXX
    _XXXXXXX
};


const unsigned char frontFacet45_000RHS[] = {

    1, 14,
    3,3,

    ________
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
    ________

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
    XXXXXX__
    XXXXXX__
};


const unsigned char topFacets000[] = {

    1, 10,
    3, 18,

    ___XX___
    __XXXX__
    _XXXXXX_
    XXXXXXXX
    _XXXXXX_
    __XXXX__
    ___XX___
    ________
    ________
    ________
    
    ___XX___
    __XXXX__
    _XXXXXX_
    XXXXXXXX
    XXXXXXXX
    XXXXXXXX
    _XXXXXX_
    __XXXX__
    ___XX___
    ___XX___
};


const unsigned char top2Facets000[] = {

    2, 10,
    3,18,

    ___XXX__ ________
    _XXXXXX_ ________
    XXXXXXX_ ________
    _XXXXXXX ________
    _XXXXXXX ________
    __XXXXX_ ________
    __XXX___ ________
    ________ ________
    ________ ________
    ________ ________

    ___XXX__ ________
    _XXXXX__ ________
    XXXXXXX_ ________
    XXXXXXX_ ________
    XXXXXXXX ________
    _XXXXXXX ________
    _XXXXXXX ________
    __XXXX__ ________
    __XX____ ________
    __XX____ ________
};


// TOP FRAME 3


const unsigned char top3Facets000[] = {

    2, 10,
    3,18,

    __XXX___ ________
    __XXXXX_ ________
    _XXXXXXX ________
    _XXXXXX_ ________
    XXXXXXX_ ________
    _XXXXX__ ________
    ___XXX__ ________
    ________ ________
    ________ ________
    ________ ________

    __XXX___ ________
    __XXXXX_ ________
    _XXXXXXX ________
    _XXXXXXX ________
    XXXXXXXX ________
    XXXXXXX_ ________
    XXXXXXX_ ________
    __XXXX__ ________
    ____XX__ ________
    _____X__ ________
};


const unsigned char axis1Frame1Side000[] = {

    1,
    9,
    3,15,

    X_______
    _X______
    _XX_____
    __XX____
    ___XX___
    ___XXX__
    ____XXX_
    ______XX
    _______X

    X_______
    _X______
    _XX_____
    __XX____
    ___XX___
    ___XXX__
    ____XXX_
    ______XX
    _______X
};


const unsigned char axis1Frame1Top000[] = {

    1,
    16,
    3,24,

    ________
    ___XX___
    ___XXX__
    ___XXXX_
    __XXXXXX
    __XXXXXX
    __XXXXX_
    __XXXXX_
    _XXXXXX_
    _XXXXX__
    _XXXXX__
    __XXXX__
    ___XXX__
    ____X___
    ________
    ________

    ________
    ___XX___
    ___XXX__
    ___XXXX_
    __XXXXXX
    __XXXXXX
    __XXXXX_
    __XXXXX_
    _XXXXXX_
    _XXXXX__
    _XXXXX__
    __XXXX__
    ___XXX__
    ____X___
    ________
    ________

};



const unsigned char axis1Frame1Top0[] = {

    1,
    16,
    3,24,

    ____X___
    ___XX___
    ___XXX__
    ___XXXX_
    __XXXXXX
    __XXXXXX
    __XXXXX_
    __XXXXX_
    _XXXXXX_
    _XXXXX__
    _XXXXX__
    __XXXX__
    ___XXX__
    ___XX___
    ____X___
    ________

    ____X___
    ___XX___
    ___XXX__
    ___XXXX_
    __XXXXXX
    __XXXXXX
    __XXXXX_
    __XXXXX_
    _XXXXXX_
    _XXXXXX_
    _XXXXXX_
    __XXXXX_
    ___XXXX_
    ___XXXX_
    ____XXX_
    ______X_

};



const unsigned char axis1Frame2R000[] = {

    1,
    18,
    2,51,

    ________
    ____X___
    ___XX___
    ___XXX__
    ___XXXX_
    __XXXXX_
    __XXXXX_
    __XXXXX_
    __XXXXX_
    _XXXXX__
    _XXXXX__
    _XXXXX__
    __XXXX__
    ___XX___
    ___XX___
    ____X___
    ________
    ________

    ___X____
    ___XX___
    __XXX___
    __XXXX__
    __XXXXX_
    _XXXXXX_
    _XXXXXX_
    _XXXXXX_
    _XXXXX__
    XXXXXX__
    XXXXXX__
    XXXXXX__
    XXXXXX__
    _XXXX___
    __XXX___
    __XXX___
    ___XX___
    ____X___
};


const unsigned char rollArrowRight[] = {

// OLD FORMAT!!!

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
// OLD FORMAT!!!

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
// OLD FORMAT!!!

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

