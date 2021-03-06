
#define AXES 2
#define ROTATE 4


struct facet {
    signed char shape;
    int x;
    int y;
    char face;
    char square;
};


#define MARKER 0

               // THIS GROUPING DEFINES DISPLAY OF A LAYER (e.g, one row or column of a cube)

            // multiple facets, each...
            // face, colour, x, y, side, face# (to get colour), topOnly

    // FACE     INTERPRETATION
    // 0        TOP
    // 1        LEFT
    // 2        RIGHT
    // 3        BOTTOM
    // 4        BACK LEFT
    // 5        BACK RIGHT




            // topOnly:
            // true             a part of the 3x3 "top" of the layer
            // false            always drawn



// FACET NUMBERING on a face

// 6 7 8
// 3 4 5
// 0 1 2

// face orientation...


//      6
//    3   7
//  0   4   8
// \  1   5  / 
// 6 \  2  / 8
//   7 \ / 7 
// 3   8|6   5
//   4  |  4
// 0   5|3   2
//   1  |  1
//     210  


// may be old...
// each of the 3 visible faces indexes to an array telling us which face is actually there
// orientation of faces is hardwired -- we move/swap contents when rotating

//             B/2
//            +--+--+--+
//            |15|16|17|
//            +--+--+--+
//            |12|13|14|
//            +--+--+--+
//            | 9|10|11|
//            +--+--+--+
//  A/0        C/3        E/5        F/6
// +--+--+--+ +--+--+--+ +--+--+--+ +--+--+--+
// | 6| 7| 8| |24|25|26| |42|43|44| |51|52|53|
// +--+--+--+ +--+--+--+ +--+--+--+ +--+--+--+
// | 3| 4| 5| |21|22|23| |39|40|41| |48|49|50|
// +--+--+--+ +--+--+--+ +--+--+--+ +--+--+--+
// | 0| 1| 2| |18|19|20| |36|37|38| |45|46|47|
// +--+--+--+ +--+--+--+ +--+--+--+ +--+--+--+
//             D/4
//            +--+--+--+
//            |33|34|35|
//            +--+--+--+
//            |30|31|32|
//            +--+--+--+
//            |27|28|29|
//            +--+--+--+


#define VERT_0 ((39 * 3 + 2) << 16)
#define VERT_1 ((35 * 3 + 1) << 16)
#define VERT_2 ((31 * 3 + 0) << 16)

#define END \
    {   -1,0,0,0,0,        },



const struct facet shapeDef[AXES][ROTATE][3][25] = {

    {   // AXIS 0 (horizontal planes)
        // AXIS 0, FRAME 0

        // ROTATION 0  ISO

        {

#define AX0 0
#define AY1 0

            // LAYER 0
            {
                // left facets

                {   17,    4, 0x140000+VERT_0,   1, 0,       },       // L0
                {   1,    9, 0x190000+VERT_0,   1, 1,       },       // L1
                {   1,   14, 0x1E0000+VERT_0,   1, 2,       },       // L2 (@CENTER)

                // right facets

                {   2,   14, 0x1E0000+VERT_0,   2, 0,       },
                {   2,   19, 0x190000+VERT_0,   2, 1,       },
                {  16,   24, 0x140000+VERT_0,   2, 2,       },

                // { 14, 24, 0x140000 + VERT_0, 2, 2, },

                END
            },
            
            // LAYER 1
            {
                // left facets

                {   17,    4, 0x140000+VERT_1,   1, 3,       },       // L0
                {   1,    9, 0x190000+VERT_1,   1, 4,       },       // L1
                {   1,   14, 0x1E0000+VERT_1,   1, 5,       },       // L2 (@CENTER)

                // right facets

                {   2,   14, 0x1E0000+VERT_1,   2, 3,       },
                {   2,   19, 0x190000+VERT_1,   2, 4,       },
                {  16,   24, 0x140000+VERT_1,   2, 5,       },
                END
            },

            // LAYER 2
            {
                // top facets

                {   0,    4, 0x140000+VERT_2,   0, 0,        }, //?ordering here needs fixing
                {   0,    9, 0x190000+VERT_2,   0, 1,        },
                {   0,   14, 0x1E0000+VERT_2,   0, 2,        },
    //
                {   0,    9, 0x0F0000+VERT_2,   0, 3,        },
                {   0,   14, 0x140000+VERT_2,   0, 4,        },
                {   0,   19, 0x190000+VERT_2,   0, 5,        },
    //
                {   0,   14, 0x0A0000+VERT_2,   0, 6,        },
                {   0,   19, 0x0F0000+VERT_2,   0, 7,        },
                {   0,   24, 0x140000+VERT_2,   0, 8,        },

                // left facets

                {   17,    4, 0x140000+VERT_2,   1, 6,       },       // L0
                {   1,    9, 0x190000+VERT_2,   1, 7,       },       // L1
                {   1,   14, 0x1E0000+VERT_2,   1, 8,       },       // L2 (@CENTER)

                // right facets

                {   2,   14, 0x1E0000+VERT_2,   2, 6,       },
                {   2,   19, 0x190000+VERT_2,   2, 7,       },
                {  16,   24, 0x140000+VERT_2,   2, 8,       },
                END
            },
        },
    

        // AXIS 0, FRAME 1
        {

#define AX1 2
#define AY1 -0x10000

            // LAYER 0
            {
                // { 18, -1 + AX1, 0x200000+AY1 + VERT_0, 1,0, },     // left corner
                // { 19, 19 + AX1, 0x200000+AY1 + VERT_0, 1,0, },     // right corner
                // { 20, 9 + AX1, 0x200000+AY1 + VERT_0, 1,0, },     // front top

                { 22, 7 + AX1, 0x200000+AY1 + VERT_0, 1,0, },
                { 23, 20 + AX1, 0x1D0000+AY1 + VERT_0, 1,0, },
                { 23, 18 + AX1, 0x1E0000+AY1 + VERT_0, 1,0, },


                // left facets

                {   6,    3+AX1, 0x130000+AY1 + VERT_0,   1, 0,       },       // L0
                {   6,    6+AX1, 0x1A0000+AY1 + VERT_0,   1, 1,       },       // L1
                {   6,   9+AX1, 0x210000+AY1 + VERT_0,   1, 2,       },       // L2 (@CENTER)


                // right facets

                {   5,   10+AX1, 0x200000+AY1 + VERT_0,   2, 0,       },
                {   5,   16+AX1, 0x1D0000+AY1 + VERT_0,   2, 1,       },
                {  24,   22+AX1, 0x1A0000+AY1 + VERT_0,   2, 2,       },
                END
            },
            
            // LAYER 1
            {

                // { 18, -1 + AX1, 0x130000+AY1 + VERT_0, 1,0, },     // left corner
                // { 19, 19 + AX1, 0x130000+AY1 + VERT_0, 1,0, },     // right corner
                // { 20, 9 + AX1, 0x200000+AY1 + VERT_0, 1,0, },     // front top


                { 22, 7 + AX1, 0x130000+AY1 + VERT_0, 1,0, },
                { 23, 20 + AX1, 0x100000+AY1 + VERT_0, 1,0, },
                { 23, 18 + AX1, 0x110000+AY1 + VERT_0, 1,0, },

                // // { 22, 7 + AX1, 0x130000+AY1 + VERT_0, 1,0, },
                // { 23, 20 + AX1, 0x100000+AY1 + VERT_0, 1,0, },

                { 18, -1 + AX1, 0x210000+AY1 + VERT_1, 1,0, },     // left corner
                { 19, 19 + AX1, 0x140000+AY1 + VERT_0, 1,0, },     // right corner
                { 20, 9 + AX1, 0x200000+AY1 + VERT_0, 1,0, },     // right corner

                // left facets

                {   6,    3+AX1, 0x130000+AY1 + VERT_1,   1, 3,       },       // L0
                {   6,    6+AX1, 0x1A0000+AY1 + VERT_1,   1, 4,       },       // L1
                {   6,   9+AX1, 0x210000+AY1 + VERT_1,   1, 5,       },       // L2 (@CENTER)

                // right facets

                {   5,   10+AX1, 0x200000+AY1 + VERT_1,   2, 3,       },
                {   5,   16+AX1, 0x1D0000+AY1 + VERT_1,   2, 4,       },
                {  24,   22+AX1, 0x1A0000+AY1 + VERT_1,   2, 5,       },
                END
            },

            // LAYER 2
            {


                { 18, -1 + AX1, 0x140000+AY1 + VERT_1, 1,0, },     // left corner
                // { 19, 19 + AX1, 0x130000+AY1 + VERT_0, 1,0, },     // right corner
                 { 20, 9 + AX1, 0x130000+AY1 + VERT_0, 1,0, },

                // top facets

                {   7,    3+AX1, 0x110000+AY1 + VERT_2,   0, 0,        },
                {   7,    6+AX1, 0x180000+AY1 + VERT_2,   0, 1,        },
                {   7,   9+AX1, 0x1F0000+AY1 + VERT_2,   0, 2,        },
                {   7,   9+AX1, 0x0E0000+AY1 + VERT_2,   0, 3,        },
                {   7,   12+AX1, 0x150000+AY1 + VERT_2,   0, 4,        },
                {   7,   15+AX1, 0x1C0000+AY1 + VERT_2,   0, 5,        },
                {   7,   15+AX1, 0x0B0000+AY1 + VERT_2,   0, 6,        },     // TODO: ordering
                {   7,   18+AX1, 0x120000+AY1 + VERT_2,   0, 7,        },
                {   7,   21+AX1, 0x190000+AY1 + VERT_2,   0, 8,        },

                // left facets

                {   6,    3+AX1, 0x140000+AY1 + VERT_2,   1, 6,       },       // L0
                {   6,    6+AX1, 0x1B0000+AY1 + VERT_2,   1, 7,       },       // L1
                {   6,   9+AX1, 0x220000+AY1 + VERT_2,   1, 8,       },       // L2 (@CENTER)

                // right facets

                {   5,   10+AX1, 0x210000+AY1 + VERT_2,   2, 6,       },
                {   5,   16+AX1, 0x1E0000+AY1 + VERT_2,   2, 7,       },
                {  24,   22+AX1, 0x1B0000+AY1 + VERT_2,   2, 8,       },
                END
            },
        },

        // AXIS 0, FRAME 2

        {   // THIS GROUPING DEFINES DISPLAY OF A LAYER (e.g, one row or column of a cube)

#define AX2 -1
#define AY2 -0x10000

            // LAYER 0
            {

                // right facets (now face-on)

                {   4,    8+AX2, 0x1D0000+AY2 + VERT_0,   2, 0,       },       // L0
                {   4,   15+AX2, 0x1D0000+AY2 + VERT_0,   2, 1,       },       // L1
                {  25,   23+AX2, 0x1D0000+AY2 + VERT_0,   2, 2,       },       // L2 (@CENTER)

                { 21, 3 + AX1, 0x1D0000+AY1 + VERT_0, 1,0, },     // left up top
                { 21, 10 + AX1, 0x1D00000+AY1 + VERT_0, 1,0, },     // left up top
                { 21, 16 + AX1, 0x1D0000+AY1 + VERT_0, 1,0, },     // left up top
                END
            },
            
            // LAYER 1
            {

                { 21, 3 + AX1, 0x100000+AY1 + VERT_0, 1,0, },     // left up top
                { 21, 10 + AX1, 0x100000+AY1 + VERT_0, 1,0, },     // left up top
                { 21, 16 + AX1, 0x100000+AY1 + VERT_0, 1,0, },     // left up top

                { 18, -1 + AX1, 0x140000+AY1 + VERT_0, 1,0, },     // left corner
                { 19, 19 + AX1, 0x140000+AY1 + VERT_0, 1,0, },     // right corner
                { 20, 9 + AX1, 0x200000+AY1 + VERT_0, 1,0, },     // right corner

                // right facets (now face-on)

                {   4,    8+AX2, 0x1D0000+AY2 + VERT_1,   2, 3,       },       // L0
                {   4,   15+AX2, 0x1D0000+AY2 + VERT_1,   2, 4,       },       // L1
                {  25,   23+AX2, 0x1D0000+AY2 + VERT_1,   2, 5,       },       // L2 (@CENTER)
                END
            },

            // LAYER 2
            {
                { 18, -1 + AX1, 0x140000+AY1 + VERT_1, 1,0, },     // left corner
                { 19, 19 + AX1, 0x070000+AY1 + VERT_0, 1,0, },     // right corner
                { 20, 9 + AX1, 0x130000+AY1 + VERT_0, 1,0, },     // right corner

                // top facets

                {   3,   8+AX2, 0x0F0000+AY2 + VERT_2,   0, 0,        }, // TODO fix ordering
                {   3,  15+AX2, 0x0F0000+AY2 + VERT_2,   0, 3,        },
                {   32,  22+AX2, 0x0F0000+AY2 + VERT_2,   0, 6,        },
                {   3,   8+AX2, 0x160000+AY2 + VERT_2,   0, 1,        },
                {   3,  15+AX2, 0x160000+AY2 + VERT_2,   0, 4,        },
                {   32,  22+AX2, 0x160000+AY2 + VERT_2,   0, 7,        },
                {   3,   8+AX2, 0x1D0000+AY2 + VERT_2,   0, 2,        },
                {   3,  15+AX2, 0x1D0000+AY2 + VERT_2,   0, 5,        },
                {   32,  22+AX2, 0x1D0000+AY2 + VERT_2,   0, 8,        },

                // right facets (now face-on)

                {   4,    8+AX2, 0x1E0000+AY2 + VERT_2,   2, 6,       },       // L0
                {   4,   15+AX2, 0x1E0000+AY2 + VERT_2,   2, 7,       },       // L1
                {  25,   23+AX2, 0x1E0000+AY2 + VERT_2,   2, 8,       },       // L2 (@CENTER)
                END
            },

        },
 
        // AXIS 0, FRAME 3
        {
#define AX3 -1
#define AY3 -0x30000

            // LAYER 0
            {
                // right facets
                {   10,   19+AX3, 0x200000+AY3 + VERT_0,   4, 0,       },
                {   10,   22+AX3, 0x190000+AY3 + VERT_0,   4, 1,       },
                {   10,   25+AX3, 0x120000+AY3 + VERT_0,   4, 2,       },

                // left facets

                {   11,    6+AX3, 0x1B0000+AY3 + VERT_0,   2, 0,       },
                {   11,   12+AX3, 0x1E0000+AY3 + VERT_0,   2, 1,       },
                {   27,   18+AX3, 0x210000+AY3 + VERT_0,   2, 2,       },


                {   30, 0 + AX1, 0x190000+AY3 + VERT_0, 1,0, },     // top, left corner
                {   29, 13 + AX1, 0x1D0000+AY3 + VERT_0, 1,0, },     // top, left corner
                END
            },
            
            // LAYER 1
            {
                { 18, -1 + AX1, 0x140000+AY1 + VERT_0, 1,0, },
                { 19, 19 + AX1, 0x140000+AY1 + VERT_0, 1,0, },
                { 20, 9 + AX1, 0x200000+AY1 + VERT_0, 1,0, },



                // right facets

                {   10,   19+AX3, 0x200000+AY3 + VERT_1,   4, 3,       },
                {   10,   22+AX3, 0x190000+AY3 + VERT_1,   4, 4,       },
                {   10,   25+AX3, 0x120000+AY3 + VERT_1,   4, 5,       },

                // left facets

                {   11,    6+AX3, 0x1B0000+AY3 + VERT_1,   2, 3,       },
                {   11,   12+AX3, 0x1E0000+AY3 + VERT_1,   2, 4,       },
                {   27,   18+AX3, 0x210000+AY3 + VERT_1,   2, 5,       },


                { 28, 0 + AX1, 0x0B0000+AY1 + VERT_0, 1,0, },     // left corner
                { 29, 13 + AX1, 0x0E0000+AY1 + VERT_0, 1,0, },     // right corner
                END
            },

            // LAYER 2
            {

                { 19, 19 + AX1, 0x140000+AY1 + VERT_1, 1,0, },     // right corner
                { 20, 9 + AX1, 0x200000+AY1 + VERT_1, 1,0, },

                // { 18, -1 + AX1, 0x130000+AY1 + VERT_1, 1,0, },     // left corner
                // { 18, 19 + AX1, 0x130000+AY1 + VERT_1, 1,0, },     // left corner
                // { 20, 9 + AX1, 0x200000+AY1 + VERT_0, 1,0, },     // right corner


                // top facets

                {   9,   12+AX3, 0x0D0000+AY3 + VERT_2,   0, 0,        },
                {   9,    9+AX3, 0x140000+AY3 + VERT_2,   0, 1,        },
                {   9,    6+AX3, 0x1B0000+AY3 + VERT_2,   0, 2,        },
                {   9,   18+AX3, 0x100000+AY3 + VERT_2,   0, 3,        },
                {   9,   15+AX3, 0x170000+AY3 + VERT_2,   0, 4,        },
                {   9,   12+AX3, 0x1E0000+AY3 + VERT_2,   0, 5,        },
                {   9,   24+AX3, 0x130000+AY3 + VERT_2,   0, 6,        },
                {   9,   21+AX3, 0x1A0000+AY3 + VERT_2,   0, 7,        },
                {   9,   18+AX3, 0x210000+AY3 + VERT_2,   0, 8,        },

                // right facets

                {   10,   19+AX3, 0x220000+AY3 + VERT_2,   4, 6,       },
                {   10,   22+AX3, 0x1B0000+AY3 + VERT_2,   4, 7,       },
                {   10,   25+AX3, 0x140000+AY3 + VERT_2,   4, 8,       },

                // left facets

                {   11,    6+AX3, 0x1C0000+AY3 + VERT_2,   2, 6,       },
                {   11,   12+AX3, 0x1F0000+AY3 + VERT_2,   2, 7,       },
                {   27,   18+AX3, 0x220000+AY3 + VERT_2,   2, 8,       },
                END
            },
        },

    },


    /////////////////////////////////////////////////////////////////////////////////////////////
    //
    // AXIS 1
    //
    /////////////////////////////////////////////////////////////////////////////////////////////



    //    A
    //   B C
    //  D E F
    //   G H
    //    I



    {   // AXIS 1 (left vertical planes)
        // AXIS 1, FRAME 0
        {
#define AXIS1AX0 0
#define AXIS1AY0 0

            // SLICE 0 (back left vertical)
            {

                {   0,    4, 0x140000 + VERT_2,   0, 0, },
                {   0,    9, 0x0F0000 + VERT_2,   0, 3, },
                {   0,   14, 0x0A0000 + VERT_2,   0, 6, },

                {   17,    4, 0x140000 + VERT_0,   1, 0, },
                {   17,    4, 0x140000 + VERT_1,   1, 3, },
                {   17,    4, 0x140000 + VERT_2,   1, 6, },
                END
            },
            
            // SLICE 1
            {

                {   0,    9, 0x190000 + VERT_2,   0, 1, },
                {   0,   14, 0x140000 + VERT_2,   0, 4, },
                {   0,   19, 0x0F0000 + VERT_2,   0, 7, },

                {   1,    9, 0x190000 + VERT_0,   1, 1, },
                {   1,    9, 0x190000 + VERT_1,   1, 4, },
                {   1,    9, 0x190000 + VERT_2,   1, 7, },
                END
            },

            // SLICE 2
            {

                {   0,   14, 0x1E0000 + VERT_2,   0, 2, },
                {   0,   19, 0x190000 + VERT_2,   0, 5, },
                {   0,   24, 0x140000 + VERT_2,   0, 8, },


                {   1,   14, 0x1E0000 + VERT_0,   1, 2, },
                {   1,   14, 0x1E0000 + VERT_1,   1, 5, },
                {   1,   14, 0x1E0000 + VERT_2,   1, 8, },


                {   2,   14, 0x1E0000 + VERT_0,   2, 0, },
                {   2,   19, 0x190000 + VERT_0,   2, 1, },
                {  16,   24, 0x140000 + VERT_0,   2, 2, },

                {   2,   14, 0x1E0000 + VERT_1,   2, 3, },
                {   2,   19, 0x190000 + VERT_1,   2, 4, },
                {  16,   24, 0x140000 + VERT_1,   2, 5, },

                {   2,   14, 0x1E0000 + VERT_2,   2, 6, },
                {   2,   19, 0x190000 + VERT_2,   2, 7, },
                {  16,   24, 0x140000 + VERT_2,   2, 8, },

                END
            },
        },
    
        {

#define ADF3 -0x80000
#define ADFX3 -4

#define VERT_0B (134 << 16)
#define VERT_1B (125 << 16)
#define VERT_2B (116 << 16)

        // AXIS 1, FRAME 1
#define AXIS1AX2 -1
#define AXIS1AY2 -0x20000

#define ADFX3B -0x80000
#define ADF3B -0x40000


#define PART_SIDEFACE(xOffset, yOffset) \
    {   15,   18+AXIS1AX2+4 + xOffset, 0x200000+AXIS1AY2 + VERT_0B + (yOffset << 16),   2, 0,       }, \
    {   15,   21+AXIS1AX2+4 + xOffset, 0x1C0000+AXIS1AY2 + VERT_1B + (yOffset << 16),   2, 1,       }, \
    {   15,   24+AXIS1AX2+4 + xOffset, 0x060000+AXIS1AY2 + VERT_0B + (yOffset << 16),   2, 2,       }, \
    {   15,   14+AXIS1AX2+4 + xOffset, 0x230000+AXIS1AY2 + VERT_1B + (yOffset << 16),   2, 3,       }, \
    {   15,   17+AXIS1AX2+4 + xOffset, 0x160000+AXIS1AY2 + VERT_1B + (yOffset << 16),   2, 4,       }, \
    {   15,   20+AXIS1AX2+4 + xOffset, 0x090000+AXIS1AY2 + VERT_1B + (yOffset << 16),   2, 5,       }, \
    {   15,   10+AXIS1AX2+4 + xOffset, 0x260000+AXIS1AY2 + VERT_2B + (yOffset << 16),   2, 6,       }, \
    {   15,   13+AXIS1AX2+4 + xOffset, 0x190000+AXIS1AY2 + VERT_2B + (yOffset << 16),   2, 7,       }, \
    {   15,   16+AXIS1AX2+4 + xOffset, 0x0C0000+AXIS1AY2 + VERT_2B + (yOffset << 16),   2, 8,       }, \

#define PART_TOP_FRAME_1(xOffset, yOffset, col) \
    {   14,   13+AXIS1AX2+4 + xOffset, 0x00000+AXIS1AY2 + VERT_2B + ((yOffset+2) << 16),   0, 6 + col,       }, \
    {   14,   10+AXIS1AX2+4 + xOffset, 0x030000+AXIS1AY2 + VERT_1B + ((yOffset+2) << 16),   0, 3 + col,       }, \
    {   14,   7+AXIS1AX2+4+ xOffset, 0x060000+AXIS1AY2 + VERT_0B + ((yOffset+2) << 16),   0, 0 + col,       }, \

#define PART_BLANK_SIDEFACE(xOffset, yOffset) \
    {   33,   13+AXIS1AX2+4 + xOffset, -0x20000+AXIS1AY2 + VERT_2B + (yOffset << 16),  0, 0, }, \
    {   33,   7+AXIS1AX2+4 + xOffset,  0x30000+AXIS1AY2 + VERT_2B + (yOffset << 16),   0, 0, }, \
    {   33,   7+AXIS1AX2+4 + xOffset,  0x0C0000+AXIS1AY2 + VERT_2B + (yOffset << 16),   0, 0, }, \
    {   33,   7+AXIS1AX2+4 + xOffset,  0x150000+AXIS1AY2 + VERT_2B + (yOffset << 16),   0, 0, }, \
    {   33,   7+AXIS1AX2+4 + xOffset,  0x1F0000+AXIS1AY2 + VERT_2B + (yOffset << 16),  0, 0, },

#define PART_LOWER_SIDE_FRAME_1(xOffset, yOffset, col) \
    {   13,   8+AXIS1AX2+4 + xOffset, 0x0E0000+AXIS1AY2 + VERT_0B + ((yOffset+2) << 16),   1, 6 + col, }, \
    {   13,   12+AXIS1AX2+4 + xOffset, 0x1D0000+AXIS1AY2 + VERT_1B+ ((yOffset+2) << 16),   1, 3 + col, }, \
    {   13,   15+AXIS1AX2+4 + xOffset, 0x2A0000+AXIS1AY2 + VERT_2B+ ((yOffset+2) << 16),   1, 0 + col, },\

#define PART_BLACKFACE_RIGHT_FRAME1(x, y) \
//    {   13,   6+AXIS1AX2+ADFX3B, 0x0D0000+AXIS1AY2 + VERT_0B + ADF3B,   1, 7, }, \
//    {   13,   10+AXIS1AX2+ADFX3B, 0x1C0000+AXIS1AY2 + VERT_1B + ADF3B,   1, 4, }, \

#define PART_BLACK_FRAME2(x,y) \
    {   36,   10+9+AXIS1AX2 + -3+4 + x,  0x0C0000+AXIS1AY2 + VERT_2B + (-11 << 16) + (y << 16),   0, 0, }, \
    {   36,   10+4+AXIS1AX2 + -3+4 + x,  0x110000+AXIS1AY2 + VERT_2B + (-11 << 16) + (y << 16),   0, 0, }, \
    {   36,   10+1+AXIS1AX2 + -3+4 + x,  0x200000+AXIS1AY2 + VERT_2B + (-11 << 16) + (y << 16),   0, 0, }, \
    {   36,   10+0+AXIS1AX2 + -3+4 + x,  0x240000+AXIS1AY2 + VERT_2B + (-11 << 16) + (y << 16),   0, 0, }, \



            // SLICE 0


            {
                PART_BLACK_FRAME2(-10, -10)
                // {   36,   9+AXIS1AX2 + -3+4,  0x0C0000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },
                // {   36,   4+AXIS1AX2 + -3+4,  0x110000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },
                // {   36,   1+AXIS1AX2 + -3+4,  0x200000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },
                // {   36,   0+AXIS1AX2 + -3+4,  0x240000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },

                PART_TOP_FRAME_1(-10, -10, 0)
                PART_LOWER_SIDE_FRAME_1(-10, -10, 0)
                END
            },
            
            // SLICE 1
            {

                // {   36,   9+AXIS1AX2 + -3+4,  0x0C0000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },
                // {   36,   4+AXIS1AX2 + -3+4,  0x110000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },
                // {   36,   1+AXIS1AX2 + -3+4,  0x200000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },
                // {   36,   0+AXIS1AX2 + -3+4,  0x240000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },

                PART_BLANK_SIDEFACE(-5, -5)
                PART_BLACK_FRAME2(-5, -5)
                PART_TOP_FRAME_1(-5, -5, 1)
                PART_LOWER_SIDE_FRAME_1(-5, -5, 1)
                END



                // // PART_BLANK_SIDEFACE(-5, -5)
                // // PART_TOP_FRAME_1(-5, -5, 1)
                // // PART_LOWER_SIDE_FRAME_1(-5, -5, 1)
                // // PART_BLACKFACE_RIGHT_FRAME1(0, 0)
                // // END


                // {   36,   9+AXIS1AX2 + -3+4,  0x0C0000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },
                // {   36,   4+AXIS1AX2 + -3+4,  0x110000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },
                // {   36,   1+AXIS1AX2 + -3+4,  0x200000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },
                // {   36,   0+AXIS1AX2 + -3+4,  0x240000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },

                // PART_TOP_FRAME_1(-10, -10, 0)
                // PART_LOWER_SIDE_FRAME_1(-10, -10, 0)
                // END
            },

            // AXIS 1, FRAME 1, SLICE 2
            {
                PART_BLANK_SIDEFACE(0, 0)
                PART_SIDEFACE(0,0)
                PART_TOP_FRAME_1(0, 0, 2)
                PART_LOWER_SIDE_FRAME_1(0, 0, 2)
                END
            },
        },

        // AXIS 1, FRAME 2
        {
#define AXIS1AX2 -1
#define AXIS1AY2 -0x20000

            // SLICE 0
            {

                // {   36,   9+AXIS1AX2 + -3+4,  0x0C0000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },
                // {   36,   4+AXIS1AX2 + -3+4,  0x110000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },
                // {   36,   1+AXIS1AX2 + -3+4,  0x200000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },
                // {   36,   0+AXIS1AX2 + -3+4,  0x240000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },

                // PART_TOP_FRAME_1(-10, -10, 0)
                // PART_LOWER_SIDE_FRAME_1(-10, -10, 0)
                // END

                PART_BLACK_FRAME2(-10, -10)
                PART_TOP_FRAME_1(-10, -10, 0)
                PART_LOWER_SIDE_FRAME_1(-10, -10, 0)
                END
            },
            
            // SLICE 1
            {


                // {   36,   9+AXIS1AX2 + -3+4,  0x0C0000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },
                // {   36,   4+AXIS1AX2 + -3+4,  0x110000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },
                // {   36,   1+AXIS1AX2 + -3+4,  0x200000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },
                // {   36,   0+AXIS1AX2 + -3+4,  0x240000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },

                PART_BLANK_SIDEFACE(-5, -5)
                PART_BLACK_FRAME2(-5, -5)
                PART_TOP_FRAME_1(-5, -5, 1)
                PART_LOWER_SIDE_FRAME_1(-5, -5, 1)
                END


                // {   36,   9+AXIS1AX2 + -3+4,  0x0C0000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },
                // {   36,   4+AXIS1AX2 + -3+4,  0x110000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },
                // {   36,   1+AXIS1AX2 + -3+4,  0x200000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },
                // {   36,   0+AXIS1AX2 + -3+4,  0x240000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },

                // PART_TOP_FRAME_1(-10, -10, 0)
                // PART_LOWER_SIDE_FRAME_1(-10, -10, 0)
                // END

                // PART_BLANK_SIDEFACE(-5, -5)
                // PART_TOP_FRAME_1(-5, -5, 1)
                // PART_LOWER_SIDE_FRAME_1(-5, -5, 1)

                // // lower side

                // {   13,   6+AXIS1AX2+ADFX3B, 0x0D0000+AXIS1AY2 + VERT_0B + ADF3B,   1, 7,       },
                // {   13,   10+AXIS1AX2+ADFX3B, 0x1C0000+AXIS1AY2 + VERT_1B + ADF3B,   1, 4,       },
                // // {   13,   15+AXIS1AX2+ADFX3B, 0x2E0000+AXIS1AY2 + VERT_2B + ADF3B,   1, 2,       },  CULLED BY PRIORITY
                // END
            },

            // SLICE 2
            {
#define VERT_0B (134 << 16)
#define VERT_1B (125 << 16)
#define VERT_2B (116 << 16)



    //    A
    //   B C
    //  D E F
    //   G H
    //    I


                PART_BLANK_SIDEFACE(0, 0)
                PART_SIDEFACE(0,0)
                PART_TOP_FRAME_1(0, 0, 2)
                PART_LOWER_SIDE_FRAME_1(0, 0, 2)
                END
            },

        },
 
          // AXIS 1, FRAME 3
        {
#define AXIS1AX2 -1
#define AXIS1AY2 -0x20000

            // SLICE 0
            {

    // {   33,   8+AXIS1AX2+4 + -10,  0x0C0000+AXIS1AY2 + VERT_2B + (-10 << 16),   0, 0, },
    // {   33,   8+AXIS1AX2+4 + -10,  0x140000+AXIS1AY2 + VERT_2B + (-10 << 16),   0, 0, },
    // {   33,   8+AXIS1AX2+4 + -7,  0x0D0000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },
    // {   22,   8+AXIS1AX2+4 + -7,  0x0330000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },

    // {   35,   8+AXIS1AX2+4 + -3+4,  0x140000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },


    //             PART_TOP_FRAME_1(-10, -10, 0)
    //             PART_LOWER_SIDE_FRAME_1(-10, -10, 0)
    //             END

                // {   36,   9+AXIS1AX2 + -3+4,  0x0C0000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },
                // {   36,   4+AXIS1AX2 + -3+4,  0x110000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },
                // {   36,   1+AXIS1AX2 + -3+4,  0x200000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },
                // {   36,   0+AXIS1AX2 + -3+4,  0x240000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },

                PART_BLACK_FRAME2(-10, -10)
                PART_TOP_FRAME_1(-10, -10, 0)
                PART_LOWER_SIDE_FRAME_1(-10, -10, 0)
                END

                // {   36,   9+AXIS1AX2 + -3+4,  0x0C0000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },
                // {   36,   4+AXIS1AX2 + -3+4,  0x110000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },
                // {   36,   1+AXIS1AX2 + -3+4,  0x200000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },
                // {   36,   0+AXIS1AX2 + -3+4,  0x240000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },

                // PART_TOP_FRAME_1(-10, -10, 0)
                // PART_LOWER_SIDE_FRAME_1(-10, -10, 0)
                // END
            },
            
            // SLICE 1
            {

                // PART_BLANK_SIDEFACE(-5, -5)
                // PART_TOP_FRAME_1(-5, -5, 1)
                // PART_LOWER_SIDE_FRAME_1(-5, -5, 1)

                // // lower side

                // {   13,   6+AXIS1AX2+ADFX3B, 0x0D0000+AXIS1AY2 + VERT_0B + ADF3B,   1, 7,       },
                // {   13,   10+AXIS1AX2+ADFX3B, 0x1C0000+AXIS1AY2 + VERT_1B + ADF3B,   1, 4,       },
                // // {   13,   15+AXIS1AX2+ADFX3B, 0x2E0000+AXIS1AY2 + VERT_2B + ADF3B,   1, 2,       },  CULLED BY PRIORITY

                // END

                // {   36,   9+AXIS1AX2 + -3+4,  0x0C0000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },
                // {   36,   4+AXIS1AX2 + -3+4,  0x110000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },
                // {   36,   1+AXIS1AX2 + -3+4,  0x200000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },
                // {   36,   0+AXIS1AX2 + -3+4,  0x240000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },

                PART_BLANK_SIDEFACE(-5, -5)
                PART_BLACK_FRAME2(-5, -5)
                PART_TOP_FRAME_1(-5, -5, 1)
                PART_LOWER_SIDE_FRAME_1(-5, -5, 1)
                END

                // {   36,   9+AXIS1AX2 + -3+4,  0x0C0000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },
                // {   36,   4+AXIS1AX2 + -3+4,  0x110000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },
                // {   36,   1+AXIS1AX2 + -3+4,  0x200000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },
                // {   36,   0+AXIS1AX2 + -3+4,  0x240000+AXIS1AY2 + VERT_2B + (-23 << 16),   0, 0, },

                // PART_TOP_FRAME_1(-10, -10, 0)
                // PART_LOWER_SIDE_FRAME_1(-10, -10, 0)
                // END
            },

            // SLICE 2
            {


    //    A
    //   B C
    //  D E F
    //   G H
    //    I

                PART_BLANK_SIDEFACE(0, 0)
                PART_SIDEFACE(0,0)
                PART_TOP_FRAME_1(0, 0, 2)
                PART_LOWER_SIDE_FRAME_1(0, 0, 2)
                END
            },
        },
    },

};

