#ifndef __DRAWBITMAP_H
#define __DRAWBITMAP_H 

#include <stdbool.h>

extern const unsigned char highlighter[];
extern const unsigned char marker[];
extern const unsigned char rollArrowRight[];

extern const unsigned char cubeBoundary[];
extern const unsigned char cube1Boundary[];
extern const unsigned char topFace[];
extern const unsigned char innerFacets[];

extern const unsigned char rightFacets000[];
extern const unsigned char right2Facets000[];
extern const unsigned char right3Facets000[];
extern const unsigned char leftFacets000[];
extern const unsigned char left2Facets000[];
extern const unsigned char left3Facets000[];
extern const unsigned char topFacets000[];
extern const unsigned char top2Facets000[];
extern const unsigned char top3Facets000[];
extern const unsigned char topFacet45_000[];
extern const unsigned char frontFacet45_000[];
extern const unsigned char axis1Frame1Side000[];
extern const unsigned char axis1Frame1Top000[];
extern const unsigned char axis1Frame2R000[];
extern void drawBitmap(const unsigned char *bmp, char colour, int x, int y);


#endif
