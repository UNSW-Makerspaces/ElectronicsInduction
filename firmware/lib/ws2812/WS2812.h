// lib/WS2812.h

/*
 *  Author:     Michael Lloyd (micl.dev)
 *  Version:    1.0.0
 *  Date:       2/10/22
 *
 *      __   ___.--'_`. 
 *     ( _`.'. -   'o` ) 
 *     _\.'_'      _.-'  
 *     ( `. )    //`    
 *     \_`-'`---'\__,   
 *      \`        \`--    
 *
 */

#ifndef _PGP_WS2812_H 
#define _PGP_WS2812_H

#include "pico/types.h"
#include "hardware/pio.h"

// ================================================================================================
// WS2812 Entity, for abstraction over each RGB(?W) LED
// ================================================================================================


// ========================================================
// WS2812 value selections 
// =====================
// Bitfield colour enum 
typedef uint8_t    colourValue; 
typedef uint32_t   colourData;

class WS2812 {

        public:
        enum WS2812DataByte {
        NONE    =   0     , 
        RED     =   1     ,
        GREEN   =   2     ,
        BLUE    =   3     ,
        WHITE   =   4

        };
        enum WS2812DataFormat {

        FORMAT_RGB  =   0   ,
        FORMAT_GRB  =   1   ,
        FORMAT_WRGB =   2
        };
          // ========================================================
          // Object instantiation methods  

          // =====================
          // Constructors  

          WS2812(uint pin, uint length, PIO pio, uint sm);

          WS2812(uint pin, uint length, PIO pio, uint sm, 
                          WS2812DataFormat format);

          WS2812(uint pin, uint length, PIO pio, uint sm, 
                          WS2812DataByte b1, 
                          WS2812DataByte b2, 
                          WS2812DataByte b3);

          WS2812(uint pin, uint length, PIO pio, uint sm, 
                          WS2812DataByte b1, 
                          WS2812DataByte b2, 
                          WS2812DataByte b3, 
                          WS2812DataByte b4);

          // =====================
          // Destructor 
          ~WS2812();

          // ========================================================
          // Hexadecimal masking of colours in RGB 
          static colourData RGB(
                          colourValue red, 
                          colourValue green, 
                          colourValue blue) {

                  return(
                          (colourData)(blue)    << 16  
                          | (colourData)(green) << 8 
                          | (colourData)(red)
                        );

          };

          // ========================================================
          // Hexadecimal masking of colours in RGBW
          static colourData RGBW(
                          colourValue red, 
                          colourValue green, 
                          colourValue blue, 
                          colourValue white) {

                  return(
                          (colourData)(white)   << 24 
                          | (colourData)(blue)  << 16 
                          | (colourData)(green) << 8 
                          | (colourData)(red) 
                        );

          }

          // ========================================================
          // LED Control methods 

          // ========================================================
          // FIXME
          void setPixelColor(uint index, colourData color);

          // ========================================================
          // FIXME
          void setPixelColor(
                          uint index, 
                          colourValue red, 
                          colourValue green, 
                          colourValue blue);

          // ========================================================
          // FIXME
          void setPixelColor(
                          uint index, 
                          colourValue red, 
                          colourValue green, 
                          colourValue blue,
                          colourValue white);

          // ========================================================
          // FIXME
          void fill(
                          colourData color);

          // ========================================================
          // FIXME
          void fill(
                          colourData color, 
                          uint first);

          // ========================================================
          // FIXME
          void fill(colourData color, uint first, uint count);

          // ========================================================
          // FIXME
          void show();

        private:

          uint pin;
          uint length;
          PIO pio;
          uint sm;

          WS2812DataByte bytes[4];

          colourData *data;

          void initialise(uint pin, uint length, PIO pio, uint sm, 
            WS2812DataByte b1, 
            WS2812DataByte b2, 
            WS2812DataByte b3, 
            WS2812DataByte b4);

          colourData convertData(colourData rgbw);

};

// * - *
#endif
