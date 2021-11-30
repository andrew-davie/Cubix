#ifndef __DRAWBITMAP_H
#define __DRAWBITMAP_H

#include <stdbool.h>

extern const unsigned char cubeBoundary[];
extern const unsigned char cube1Boundary[];
extern const unsigned char topFace[];
extern const unsigned char innerFacets[];

extern const unsigned char rightFacets000[];
extern const unsigned char rightFacets001[];
extern const unsigned char rightFacets010[];
extern const unsigned char rightFacets011[];
extern const unsigned char rightFacets100[];
extern const unsigned char rightFacets101[];
extern const unsigned char rightFacets110[];
extern const unsigned char rightFacets111[];

extern const unsigned char right2Facets000[];
extern const unsigned char right2Facets001[];
extern const unsigned char right2Facets010[];
extern const unsigned char right2Facets011[];
extern const unsigned char right2Facets100[];
extern const unsigned char right2Facets101[];
extern const unsigned char right2Facets110[];
extern const unsigned char right2Facets111[];

extern const unsigned char right3Facets000[];
extern const unsigned char right3Facets001[];
extern const unsigned char right3Facets010[];
extern const unsigned char right3Facets011[];
extern const unsigned char right3Facets100[];
extern const unsigned char right3Facets101[];
extern const unsigned char right3Facets110[];
extern const unsigned char right3Facets111[];

extern const unsigned char leftFacets000[];
extern const unsigned char leftFacets001[];
extern const unsigned char leftFacets010[];
extern const unsigned char leftFacets011[];
extern const unsigned char leftFacets100[];
extern const unsigned char leftFacets101[];
extern const unsigned char leftFacets110[];
extern const unsigned char leftFacets111[];

extern const unsigned char left2Facets000[];
extern const unsigned char left2Facets001[];
extern const unsigned char left2Facets010[];
extern const unsigned char left2Facets011[];
extern const unsigned char left2Facets100[];
extern const unsigned char left2Facets101[];
extern const unsigned char left2Facets110[];
extern const unsigned char left2Facets111[];

extern const unsigned char left3Facets000[];
extern const unsigned char left3Facets001[];
extern const unsigned char left3Facets010[];
extern const unsigned char left3Facets011[];
extern const unsigned char left3Facets100[];
extern const unsigned char left3Facets101[];
extern const unsigned char left3Facets110[];
extern const unsigned char left3Facets111[];

extern const unsigned char topFacets000[];
extern const unsigned char topFacets001[];
extern const unsigned char topFacets010[];
extern const unsigned char topFacets011[];
extern const unsigned char topFacets100[];
extern const unsigned char topFacets101[];
extern const unsigned char topFacets110[];
extern const unsigned char topFacets111[];

extern const unsigned char top2Facets000[];
extern const unsigned char top2Facets001[];
extern const unsigned char top2Facets010[];
extern const unsigned char top2Facets011[];
extern const unsigned char top2Facets100[];
extern const unsigned char top2Facets101[];
extern const unsigned char top2Facets110[];
extern const unsigned char top2Facets111[];


extern const unsigned char top3Facets000[];
extern const unsigned char top3Facets001[];
extern const unsigned char top3Facets010[];
extern const unsigned char top3Facets011[];
extern const unsigned char top3Facets100[];
extern const unsigned char top3Facets101[];
extern const unsigned char top3Facets110[];
extern const unsigned char top3Facets111[];

extern const unsigned char topFacet45_000[];
extern const unsigned char topFacet45_001[];
extern const unsigned char topFacet45_010[];
extern const unsigned char topFacet45_011[];
extern const unsigned char topFacet45_100[];
extern const unsigned char topFacet45_101[];
extern const unsigned char topFacet45_110[];
extern const unsigned char topFacet45_111[];


extern const unsigned char frontFacet45_000[];
extern const unsigned char frontFacet45_001[];
extern const unsigned char frontFacet45_010[];
extern const unsigned char frontFacet45_011[];
extern const unsigned char frontFacet45_100[];
extern const unsigned char frontFacet45_101[];
extern const unsigned char frontFacet45_110[];
extern const unsigned char frontFacet45_111[];


extern void drawBitmap(const unsigned char *bmp, int x, int y, bool relativeToScreen);


#endif
