#ifndef __DRAWBITMAP_H
#define __DRAWBITMAP_H

#include <stdbool.h>

extern const unsigned char rocketShip[];
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

extern const unsigned char leftFacets000[];
extern const unsigned char leftFacets001[];
extern const unsigned char leftFacets010[];
extern const unsigned char leftFacets011[];
extern const unsigned char leftFacets100[];
extern const unsigned char leftFacets101[];
extern const unsigned char leftFacets110[];
extern const unsigned char leftFacets111[];

extern const unsigned char topFacets000[];
extern const unsigned char topFacets001[];
extern const unsigned char topFacets010[];
extern const unsigned char topFacets011[];
extern const unsigned char topFacets100[];
extern const unsigned char topFacets101[];
extern const unsigned char topFacets110[];
extern const unsigned char topFacets111[];



extern const unsigned char eroShip[];
extern const unsigned char eroShip2[];
extern const unsigned char rocketShipLeg[];
extern const unsigned char rocketShipFlame[];
extern const unsigned char flagUSA[];
extern const unsigned char shipFuelTank[];

extern void drawBitmap(const unsigned char *bmp, int x, int y, bool relativeToScreen);


#endif
