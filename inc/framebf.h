// ----------------------------------- framebf.h -------------------------------------
#include "mbox.h"
#include "printf.h"

// ARGB in byte order (ABGR in memory order)
#define BLACK   0x00000000 
#define MAROON  0x00AA0000 
#define GREEN   0x0000AA00    
#define OLIVE   0x00AAAA00 
#define NAVY    0x000000AA 
#define PURPLE  0x00AA00AA 
#define TEAL    0x000055AA 
#define SILVER  0x00AAAAAA 
#define GRAY    0x00555555 
#define RED     0x00FF5555 
#define LIME    0x0055FF55 
#define YELLOW  0x00FFFF55 
#define BLUE    0x005555FF 
#define FUCHSIA 0x00FF55FF 
#define AQUA    0x0055FFFF 
#define WHITE   0x00FFFFFF 

//Use RGBA32 (32 bits for each pixel)
#define COLOR_DEPTH 32
// //Pixel Order: RGB in memory order (little endian --> BGR in byte order)
// #define PIXEL_ORDER 1

//Pixel Order: BGR in memory order (little endian --> RGB in byte order)
#define PIXEL_ORDER 0

void framebf_init();
void drawPixel(int x, int y, unsigned int attr);
void drawLine(int x1, int y1, int x2, int y2, unsigned int attr);
void drawRect(int x1, int y1, int x2, int y2, unsigned int attr, int fill);
void drawCircle(int x0, int y0, int radius, unsigned int attr, int fill);
void drawChar(unsigned char ch, int x, int y, unsigned int attr);
void drawString(int x, int y, char *s, unsigned int attr);
void showPicture(int offset);
void clearScreen();
