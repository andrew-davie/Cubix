
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


extern const struct facet shapeDef[AXES][ROTATE][3][25];

