#ifndef __CAVEDATA_H
#define __CAVEDATA_H

extern const unsigned char cave1[];

struct caveInfo {
    const unsigned char *cavePtr;
    const unsigned char caveColour[1][3+24];
};

extern const struct caveInfo caveList[];

#endif
