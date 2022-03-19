#include <Adafruit_NeoPixel.h>

#define PIN        10
#define NUMPIXELS 256

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

/*
long nigao[4][256] = {{0x002AFF,0x002AFF,0x002AFF,0x000000,0x010000,0x000000,0x010000,0x010000,0x010000,0x010000,0x000000,0x000000,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x000000,0x010000,0x0D0D0D,0x0C0C0C,0x0C0C0C,0x0C0C0C,0x0C0C0C,0x0C0C0C,0x0C0C0C,0x000000,0x000000,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x000000,0x010000,0x0B0B0B,0x080808,0x0B0B0B,0x080808,0x000000,0x080808,0x0B0B0B,0x080808,0x0B0B0B,0x000000,0x000000,0x002AFF,0x002AFF,0x002AFF,0x000100,0x0D0D0D,0x080808,0x000000,0x080808,0x000000,0xCD804A,0x000000,0x080808,0x000000,0x080808,0x0C0C0C,0x000000,0x002AFF,0x002AFF,0x002AFF,0x010000,0x0B0B0B,0x000000,0xCD804A,0x000000,0xCD804A,0xCD804A,0xCD804A,0x000000,0xCD804A,0x000000,0x0B0B0B,0x000000,0x002AFF,0x002AFF,0x002AFF,0x010000,0x080808,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0x080808,0x000000,0x002AFF,0x002AFF,0x002AFF,0x000102,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0x000000,0x002AFF,0x002AFF,0x000000,0x010000,0x000000,0x000102,0x000102,0x000102,0x000102,0xCD804A,0x000102,0x000102,0x000102,0x000102,0x040000,0x000000,0x000000,0x002AFF,0x000102,0xCD804A,0x000102,0xFFFFFF,0x000102,0xFFFFFF,0x000102,0x000102,0x000102,0xFFFFFF,0x000102,0xFFFFFF,0x000102,0xCD804A,0x000000,0x002AFF,0x000102,0xCD804A,0x000102,0x000102,0x000102,0x000102,0x000102,0xCD804A,0x000102,0x000102,0x000102,0x000102,0x000102,0xCD804A,0x000000,0x002AFF,0x000102,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0x000000,0x002AFF,0x000000,0x000002,0x000002,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0x000200,0x010000,0x000000,0x002AFF,0x002AFF,0x002AFF,0x000000,0xCD804A,0xCD804A,0xCD804A,0xD42222,0xD42222,0xD42222,0xCD804A,0xCD804A,0xCD804A,0x040001,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x000000,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0x040001,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x000000,0x010002,0x000000,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0x000000,0x000000,0x000000,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x002AFF}
,{0x002AFF,0x002AFF,0x002AFF,0x000000,0x010000,0x000000,0x010000,0x010000,0x010000,0x010000,0x000000,0x000000,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x000000,0x010000,0x0D0D0D,0x0C0C0C,0x0C0C0C,0x0C0C0C,0x0C0C0C,0x0C0C0C,0x0C0C0C,0x000000,0x000000,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x000000,0x010000,0x0B0B0B,0x080808,0x0B0B0B,0x080808,0x000000,0x080808,0x0B0B0B,0x080808,0x0B0B0B,0x000000,0x000000,0x002AFF,0x002AFF,0x002AFF,0x000100,0x0D0D0D,0x080808,0x000000,0x080808,0x000000,0xCD804A,0x000000,0x080808,0x000000,0x080808,0x0C0C0C,0x000000,0x002AFF,0x002AFF,0x002AFF,0x010000,0x0B0B0B,0x000000,0xCD804A,0x000000,0xCD804A,0xCD804A,0xCD804A,0x000000,0xCD804A,0x000000,0x0B0B0B,0x000000,0x002AFF,0x002AFF,0x002AFF,0x010000,0x080808,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0x080808,0x000000,0x002AFF,0x002AFF,0x002AFF,0x000102,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0x000000,0x002AFF,0x002AFF,0x000000,0x010000,0x000000,0x000102,0x000102,0x000102,0x000102,0xCD804A,0x000102,0x000102,0x000102,0x000102,0x040000,0x000000,0x000000,0x002AFF,0x000102,0xCD804A,0x000102,0x000102,0xFFFFFF,0xFFFFFF,0x000102,0x000102,0x000102,0x000102,0xFFFFFF,0xFFFFFF,0x000102,0xCD804A,0x000000,0x002AFF,0x000102,0xCD804A,0x000102,0x000102,0x000102,0x000102,0x000102,0xCD804A,0x000102,0x000102,0x000102,0x000102,0x000102,0xCD804A,0x000000,0x002AFF,0x000102,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0x000000,0x002AFF,0x000000,0x000002,0x000002,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0x000200,0x010000,0x000000,0x002AFF,0x002AFF,0x002AFF,0x000000,0xCD804A,0xCD804A,0xCD804A,0xD42222,0xD42222,0xD42222,0xCD804A,0xCD804A,0xCD804A,0x040001,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x000000,0xCD804A,0xCD804A,0xCD804A,0xD42222,0xD42222,0xD42222,0xCD804A,0xCD804A,0xCD804A,0x040001,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x000000,0x010002,0x000000,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0x000000,0x000000,0x000000,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x002AFF}
,{0x002AFF,0x002AFF,0x002AFF,0x000000,0x010000,0x000000,0x010000,0x010000,0x010000,0x010000,0x000000,0x000000,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x000000,0x010000,0x0D0D0D,0x0C0C0C,0x0C0C0C,0x0C0C0C,0x0C0C0C,0x0C0C0C,0x0C0C0C,0x000000,0x000000,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x000000,0x010000,0x0B0B0B,0x080808,0x0B0B0B,0x080808,0x000000,0x080808,0x0B0B0B,0x080808,0x0B0B0B,0x000000,0x000000,0x002AFF,0x002AFF,0x002AFF,0x000100,0x0D0D0D,0x080808,0x000000,0x080808,0x000000,0xCD804A,0x000000,0x080808,0x000000,0x080808,0x0C0C0C,0x000000,0x002AFF,0x002AFF,0x002AFF,0x010000,0x0B0B0B,0x000000,0xCD804A,0x000000,0xCD804A,0xCD804A,0xCD804A,0x000000,0xCD804A,0x000000,0x0B0B0B,0x000000,0x002AFF,0x002AFF,0x002AFF,0x010000,0x080808,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0x080808,0x000000,0x002AFF,0x002AFF,0x002AFF,0x000102,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0x000000,0x002AFF,0x002AFF,0x000000,0x010000,0x000000,0x000102,0x000102,0x000102,0x000102,0xCD804A,0x000102,0x000102,0x000102,0x000102,0x040000,0x000000,0x000000,0x002AFF,0x000102,0xCD804A,0x000102,0xFFFFFF,0x000102,0xFFFFFF,0x000102,0x000102,0x000102,0xFFFFFF,0x000102,0xFFFFFF,0x000102,0xCD804A,0x000000,0x002AFF,0x000102,0xCD804A,0x000102,0x000102,0x000102,0x000102,0x000102,0xCD804A,0x000102,0x000102,0x000102,0x000102,0x000102,0xCD804A,0x000000,0x002AFF,0x000102,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0x000000,0x002AFF,0x000000,0x000002,0x000002,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0x000200,0x010000,0x000000,0x002AFF,0x002AFF,0x002AFF,0x000000,0xCD804A,0xCD804A,0xCD804A,0xD42222,0xD42222,0xD42222,0xCD804A,0xCD804A,0xCD804A,0x040001,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x000000,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0x040001,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x000000,0x010002,0x000000,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0x000000,0x000000,0x000000,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x002AFF}
,{0x002AFF,0x002AFF,0x002AFF,0x000000,0x010000,0x000000,0x010000,0x010000,0x010000,0x010000,0x000000,0x000000,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x000000,0x010000,0x0D0D0D,0x0C0C0C,0x0C0C0C,0x0C0C0C,0x0C0C0C,0x0C0C0C,0x0C0C0C,0x000000,0x000000,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x000000,0x010000,0x0B0B0B,0x080808,0x0B0B0B,0x080808,0x000000,0x080808,0x0B0B0B,0x080808,0x0B0B0B,0x000000,0x000000,0x002AFF,0x002AFF,0x002AFF,0x000100,0x0D0D0D,0x080808,0x000000,0x080808,0x000000,0xCD804A,0x000000,0x080808,0x000000,0x080808,0x0C0C0C,0x000000,0x002AFF,0x002AFF,0x002AFF,0x010000,0x0B0B0B,0x000000,0xCD804A,0x000000,0xCD804A,0xCD804A,0xCD804A,0x000000,0xCD804A,0x000000,0x0B0B0B,0x000000,0x002AFF,0x002AFF,0x002AFF,0x010000,0x080808,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0x080808,0x000000,0x002AFF,0x002AFF,0x002AFF,0x000102,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0x000000,0x002AFF,0x002AFF,0x000000,0x010000,0x000000,0x000102,0x000102,0x000102,0x000102,0xCD804A,0x000102,0x000102,0x000102,0x000102,0x040000,0x000000,0x000000,0x002AFF,0x000102,0xCD804A,0x000102,0xFFFFFF,0xFFFFFF,0x000102,0x000102,0x000102,0x000102,0xFFFFFF,0xFFFFFF,0x000102,0x000102,0xCD804A,0x000000,0x002AFF,0x000102,0xCD804A,0x000102,0x000102,0x000102,0x000102,0x000102,0xCD804A,0x000102,0x000102,0x000102,0x000102,0x000102,0xCD804A,0x000000,0x002AFF,0x000102,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0x000000,0x002AFF,0x000000,0x000002,0x000002,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0x000200,0x010000,0x000000,0x002AFF,0x002AFF,0x002AFF,0x000000,0xCD804A,0xCD804A,0xCD804A,0xD42222,0xD42222,0xD42222,0xCD804A,0xCD804A,0xCD804A,0x040001,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x000000,0xCD804A,0xCD804A,0xCD804A,0xD42222,0xD42222,0xD42222,0xCD804A,0xCD804A,0xCD804A,0x040001,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x000000,0x010002,0x000000,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0xCD804A,0x000000,0x000000,0x000000,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x002AFF,0x002AFF,0x002AFF,0x002AFF,0x002AFF}
};
*/

/*
long nigao[4][256] = {{0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x886230,0x548135,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x886230,0x886230,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x3F3F3F,0xFFFF00,0x000000,0x886230,0x886230,0x548135,0x548135,0x548135,0x548135,0x886230,0x548135,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0xFFFF00,0xFFFF00,0x886230,0x886230,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0xFFFF00,0xFFFF00,0x886230,0x886230,0x886230,0x886230,0x886230,0x886230,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0xFFFF00,0xFFFF00,0x886230,0x886230,0x886230,0x886230,0x886230,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0xFFFF00,0x886230,0x886230,0x886230,0x886230,0x886230,0x886230,0x886230,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x886230,0x548135,0x886230,0x548135,0x548135,0x886230,0x548135,0x548135,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x886230,0x548135,0x886230,0x548135,0x548135,0x548135,0x886230,0x548135,0x548135,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x886230,0x548135,0x886230,0x548135,0x548135,0x548135,0x886230,0x548135,0x548135,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135}
,{0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x886230,0x548135,0x886230,0x548135,0x548135,0x548135,0x548135,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x886230,0x886230,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x3F3F3F,0xFFFF00,0x000000,0x886230,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0xFFFF00,0xFFFF00,0x886230,0x886230,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0xFFFF00,0xFFFF00,0x886230,0x886230,0x886230,0x886230,0x886230,0x886230,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0xFFFF00,0xFFFF00,0x886230,0x886230,0x886230,0x886230,0x886230,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x886230,0xFFFF00,0x886230,0x886230,0x886230,0x886230,0x886230,0x886230,0x886230,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x886230,0x548135,0x548135,0x886230,0x548135,0x548135,0x886230,0x548135,0x548135,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x886230,0x548135,0x548135,0x548135,0x886230,0x548135,0x548135,0x886230,0x548135,0x548135,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x886230,0x548135,0x548135,0x548135,0x886230,0x548135,0x548135,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135}
,{0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x886230,0x548135,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x886230,0x886230,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x3F3F3F,0xFFFF00,0x000000,0x886230,0x886230,0x548135,0x548135,0x548135,0x548135,0x886230,0x548135,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0xFFFF00,0xFFFF00,0x886230,0x886230,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0xFFFF00,0xFFFF00,0x886230,0x886230,0x886230,0x886230,0x886230,0x886230,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0xFFFF00,0xFFFF00,0x886230,0x886230,0x886230,0x886230,0x886230,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0xFFFF00,0x886230,0x886230,0x886230,0x886230,0x886230,0x886230,0x886230,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x886230,0x548135,0x886230,0x548135,0x548135,0x886230,0x548135,0x548135,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x886230,0x548135,0x886230,0x548135,0x548135,0x548135,0x886230,0x548135,0x548135,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x886230,0x548135,0x886230,0x548135,0x548135,0x548135,0x886230,0x548135,0x548135,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135}
,{0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x886230,0x548135,0x886230,0x548135,0x548135,0x548135,0x548135,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x886230,0x886230,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x3F3F3F,0xFFFF00,0x000000,0x886230,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0xFFFF00,0xFFFF00,0x886230,0x886230,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0xFFFF00,0xFFFF00,0x886230,0x886230,0x886230,0x886230,0x886230,0x886230,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0xFFFF00,0xFFFF00,0x886230,0x886230,0x886230,0x886230,0x886230,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x886230,0xFFFF00,0x886230,0x886230,0x886230,0x886230,0x886230,0x886230,0x886230,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x886230,0x548135,0x548135,0x886230,0x548135,0x548135,0x886230,0x548135,0x548135,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x886230,0x548135,0x548135,0x548135,0x886230,0x548135,0x548135,0x886230,0x548135,0x548135,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x886230,0x548135,0x548135,0x548135,0x886230,0x548135,0x548135,0x886230,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135,0x548135}
};
 */

long nigao[4][256] = {{0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x5F4522,0x43672A,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x5F4522,0x5F4522,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x3F3F3F,0xAEAE20,0x000000,0x5F4522,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x5F4522,0x43672A,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0xAEAE20,0xAEAE20,0x5F4522,0x5F4522,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0xAEAE20,0xAEAE20,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0xAEAE20,0xAEAE20,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0xAEAE20,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x5F4522,0x43672A,0x5F4522,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x5F4522,0x43672A,0x5F4522,0x43672A,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x5F4522,0x43672A,0x5F4522,0x43672A,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A}
,{0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x5F4522,0x43672A,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x5F4522,0x5F4522,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x3F3F3F,0xAEAE20,0x000000,0x5F4522,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0xAEAE20,0xAEAE20,0x5F4522,0x5F4522,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0xAEAE20,0xAEAE20,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0xAEAE20,0xAEAE20,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x5F4522,0xAEAE20,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A}
,{0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x5F4522,0x43672A,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x5F4522,0x5F4522,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x3F3F3F,0xAEAE20,0x000000,0x5F4522,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x5F4522,0x43672A,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0xAEAE20,0xAEAE20,0x5F4522,0x5F4522,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0xAEAE20,0xAEAE20,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0xAEAE20,0xAEAE20,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0xAEAE20,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x5F4522,0x43672A,0x5F4522,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x5F4522,0x43672A,0x5F4522,0x43672A,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x5F4522,0x43672A,0x5F4522,0x43672A,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A}
,{0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x5F4522,0x43672A,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x5F4522,0x5F4522,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x3F3F3F,0xAEAE20,0x000000,0x5F4522,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0xAEAE20,0xAEAE20,0x5F4522,0x5F4522,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0xAEAE20,0xAEAE20,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0xAEAE20,0xAEAE20,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x5F4522,0xAEAE20,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x5F4522,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A,0x43672A}
};

#define AKARUSA (4)

int leds[] = {16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16};
int pic=0;

void setup() {
  pixels.begin();
}

void loop() {
  pixels.clear();

  long c;
  int left = 0;
  int right = 0;
  int dir = -1;
  int pos=0;
  
  for(int rows=0; rows< sizeof(leds)/sizeof(int) ; rows++) {
    left = right;
    right += leds[rows];
    dir *= -1;
    if(dir==1){
      for(int i=left;i<right;i++){
        c=nigao[pic][i];
        pixels.setPixelColor(NUMPIXELS -1 -pos++, pixels.Color((0xFF&c>>16)/AKARUSA,(0xFF&c>>8)/AKARUSA,(0xFF&c>>0)/AKARUSA));
      }
    }else{
      for(int i=right-1;i>=left;i--){
        c=nigao[pic][i];
        pixels.setPixelColor(NUMPIXELS -1 -pos++, pixels.Color((0xFF&c>>16)/AKARUSA,(0xFF&c>>8)/AKARUSA,(0xFF&c>>0)/AKARUSA));
      }
    }
  }
  
  pic=(pic+1)%4;
  pixels.show();
  delay(DELAYVAL);
}
