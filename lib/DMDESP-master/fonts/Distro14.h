

/*
 * Fareed Read
 * http://www.facebook.com/fareed.reads
 *
 * Distro14
 *
 * created with FontCreator
 * written by F. Maximilian Thiele
 *
 * http://www.apetech.de/fontCreator
 * me@apetech.de
 *
 * File Name           : Distro14.h
 * Date                : 28.06.2018
 * Font size in bytes  : 7410
 * Font width          : 10
 * Font height         : 14
 * Font first char     : 32
 * Font last char      : 128
 * Font used chars     : 96
 *
 * The font data are defined as
 *
 * struct _FONT_ {
 *     uint16_t   font_Size_in_Bytes_over_all_included_Size_it_self;
 *     uint8_t    font_Width_in_Pixel_for_fixed_drawing;
 *     uint8_t    font_Height_in_Pixel_for_all_characters;
 *     unit8_t    font_First_Char;
 *     uint8_t    font_Char_Count;
 *
 *     uint8_t    font_Char_Widths[font_Last_Char - font_First_Char +1];
 *                  // for each character the separate width in pixels,
 *                  // characters < 128 have an implicit virtual right empty row
 *
 *     uint8_t    font_data[];
 *                  // bit field of all characters
 */

#include <inttypes.h>
#include <avr/pgmspace.h>

#ifndef DISTRO14_H
#define DISTRO14_H

#define DISTRO14_WIDTH 10
#define DISTRO14_HEIGHT 14

const static uint8_t Distro14[] PROGMEM = {
    0x1C, 0xF2, // size
    0x0A, // width
    0x0E, // height
    0x20, // first char
    0x60, // char count
    
    // char widths
    0x00, 0x01, 0x03, 0x07, 0x06, 0x0B, 0x08, 0x01, 0x02, 0x02, 
    0x04, 0x06, 0x01, 0x06, 0x01, 0x04, 0x06, 0x04, 0x06, 0x06, 
    0x07, 0x06, 0x05, 0x06, 0x06, 0x06, 0x01, 0x01, 0x06, 0x06, 
    0x06, 0x05, 0x0B, 0x09, 0x07, 0x08, 0x08, 0x06, 0x06, 0x09, 
    0x08, 0x01, 0x05, 0x07, 0x05, 0x0A, 0x08, 0x0A, 0x05, 0x0A, 
    0x06, 0x06, 0x07, 0x07, 0x08, 0x0D, 0x08, 0x07, 0x07, 0x02, 
    0x04, 0x02, 0x06, 0x06, 0x02, 0x06, 0x06, 0x05, 0x07, 0x07, 
    0x04, 0x07, 0x06, 0x01, 0x03, 0x05, 0x01, 0x0A, 0x06, 0x06, 
    0x06, 0x07, 0x04, 0x04, 0x04, 0x06, 0x06, 0x0A, 0x05, 0x06, 
    0x05, 0x02, 0x01, 0x02, 0x04, 0x00, 
    
    // font data
    0xFE, 0x10, // 33
    0x06, 0x00, 0x06, 0x00, 0x00, 0x00, // 34
    0x90, 0xFC, 0x98, 0x10, 0x90, 0xFC, 0x98, 0x0C, 0x04, 0x00, 0x04, 0x0C, 0x04, 0x00, // 35
    0x1C, 0x26, 0x27, 0x46, 0x46, 0x80, 0x10, 0x10, 0x30, 0x38, 0x18, 0x0C, // 36
    0x1C, 0x22, 0x22, 0x22, 0xDC, 0x30, 0x88, 0x46, 0x40, 0x40, 0x80, 0x00, 0x00, 0x10, 0x0C, 0x00, 0x00, 0x0C, 0x10, 0x10, 0x10, 0x0C, // 37
    0x80, 0x7C, 0x62, 0x62, 0xF2, 0x8C, 0x80, 0x80, 0x0C, 0x10, 0x10, 0x10, 0x10, 0x1C, 0x0C, 0x0C, // 38
    0x06, 0x00, // 39
    0xF8, 0x06, 0x0C, 0x30, // 40
    0x06, 0xF8, 0x30, 0x0C, // 41
    0x08, 0x1C, 0x18, 0x08, 0x00, 0x00, 0x00, 0x00, // 42
    0x40, 0x40, 0xE8, 0xF0, 0x40, 0x40, 0x00, 0x00, 0x08, 0x04, 0x00, 0x00, // 43
    0x00, 0x38, // 44
    0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 45
    0x00, 0x10, // 46
    0x00, 0xC0, 0x38, 0x06, 0x1C, 0x00, 0x00, 0x00, // 47
    0xF8, 0x06, 0x02, 0x02, 0x06, 0xF8, 0x04, 0x18, 0x10, 0x10, 0x08, 0x04, // 48
    0x08, 0x04, 0x06, 0xFE, 0x00, 0x00, 0x00, 0x1C, // 49
    0x00, 0x04, 0x82, 0x42, 0x22, 0x1C, 0x18, 0x1C, 0x10, 0x10, 0x10, 0x00, // 50
    0x06, 0x02, 0x02, 0x22, 0x7C, 0x80, 0x00, 0x18, 0x10, 0x10, 0x10, 0x0C, // 51
    0x80, 0xE0, 0x30, 0x1C, 0x1E, 0xFE, 0x80, 0x04, 0x04, 0x04, 0x04, 0x0C, 0x1C, 0x04, // 52
    0x00, 0x3E, 0x22, 0x22, 0x22, 0xC2, 0x08, 0x18, 0x10, 0x10, 0x10, 0x0C, // 53
    0xE0, 0x38, 0x3E, 0x20, 0xC0, 0x0C, 0x10, 0x10, 0x10, 0x0C, // 54
    0x02, 0x02, 0x82, 0xE2, 0x3E, 0x0E, 0x00, 0x18, 0x0C, 0x00, 0x00, 0x00, // 55
    0xFC, 0x22, 0x22, 0x22, 0x7C, 0x80, 0x0C, 0x10, 0x10, 0x10, 0x10, 0x0C, // 56
    0x3C, 0x46, 0x42, 0xC2, 0xC6, 0x3C, 0x00, 0x00, 0x10, 0x0C, 0x00, 0x00, // 57
    0x20, 0x10, // 58
    0x20, 0x70, // 59
    0xC0, 0xC0, 0xC0, 0x20, 0x20, 0x10, 0x00, 0x00, 0x00, 0x04, 0x08, 0x08, // 60
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, // 61
    0x10, 0x20, 0x20, 0xC0, 0xC0, 0xC0, 0x08, 0x04, 0x04, 0x00, 0x00, 0x00, // 62
    0x04, 0x06, 0xC2, 0x62, 0x1E, 0x00, 0x10, 0x10, 0x00, 0x00, // 63
    0xF8, 0x04, 0x02, 0xF1, 0x09, 0x09, 0x09, 0xFA, 0x02, 0x04, 0x78, 0x04, 0x08, 0x10, 0x20, 0x24, 0x24, 0x24, 0x04, 0x04, 0x00, 0x00, // 64
    0x00, 0xC0, 0xF0, 0x1C, 0x0E, 0x1C, 0xF0, 0x80, 0x00, 0x18, 0x0C, 0x04, 0x04, 0x04, 0x04, 0x04, 0x0C, 0x18, // 65
    0xFE, 0x22, 0x22, 0x22, 0x22, 0x7C, 0x80, 0x1C, 0x10, 0x10, 0x10, 0x10, 0x18, 0x0C, // 66
    0xF8, 0x0C, 0x06, 0x02, 0x02, 0x02, 0x06, 0x00, 0x04, 0x0C, 0x18, 0x10, 0x10, 0x10, 0x18, 0x08, // 67
    0xFE, 0x02, 0x02, 0x02, 0x02, 0x06, 0x04, 0xF8, 0x1C, 0x10, 0x10, 0x10, 0x10, 0x08, 0x0C, 0x00, // 68
    0xFE, 0x22, 0x22, 0x22, 0x22, 0x02, 0x1C, 0x10, 0x10, 0x10, 0x10, 0x10, // 69
    0xFE, 0x42, 0x42, 0x42, 0x42, 0x02, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, // 70
    0xF8, 0x0C, 0x06, 0x02, 0x02, 0x02, 0x26, 0x64, 0xE0, 0x00, 0x0C, 0x08, 0x10, 0x10, 0x10, 0x10, 0x18, 0x0C, // 71
    0xFE, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0xFE, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, // 72
    0xFE, 0x1C, // 73
    0x00, 0x00, 0x00, 0x00, 0xFE, 0x08, 0x10, 0x10, 0x18, 0x0C, // 74
    0xFE, 0x60, 0x60, 0xF0, 0x8C, 0x06, 0x02, 0x1C, 0x00, 0x00, 0x00, 0x04, 0x0C, 0x18, // 75
    0xFE, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x10, 0x10, 0x10, 0x10, // 76
    0xFE, 0x0E, 0x1C, 0xE0, 0x80, 0x80, 0xE0, 0x1C, 0x0E, 0xFE, 0x1C, 0x00, 0x00, 0x00, 0x1C, 0x1C, 0x00, 0x00, 0x00, 0x1C, // 77
    0xFE, 0x0E, 0x1C, 0x30, 0xE0, 0x80, 0x00, 0xFE, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x1C, 0x1C, // 78
    0xF0, 0x0C, 0x04, 0x02, 0x02, 0x02, 0x02, 0x04, 0x0C, 0xF0, 0x00, 0x0C, 0x08, 0x10, 0x10, 0x10, 0x10, 0x08, 0x0C, 0x00, // 79
    0xFE, 0x42, 0x42, 0x42, 0x3C, 0x1C, 0x00, 0x00, 0x00, 0x00, // 80
    0xF0, 0x0C, 0x04, 0x02, 0x02, 0x02, 0x82, 0x04, 0x0C, 0xF0, 0x00, 0x0C, 0x08, 0x10, 0x10, 0x10, 0x1C, 0x1C, 0x3C, 0x04, // 81
    0xFE, 0x42, 0x42, 0xC2, 0x62, 0x1C, 0x1C, 0x00, 0x00, 0x00, 0x0C, 0x18, // 82
    0x1C, 0x3C, 0x62, 0x62, 0xC2, 0x82, 0x18, 0x10, 0x10, 0x10, 0x0C, 0x0C, // 83
    0x02, 0x02, 0x02, 0xFE, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, // 84
    0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x04, 0x08, 0x10, 0x10, 0x10, 0x08, 0x04, // 85
    0x06, 0x3C, 0xE0, 0x80, 0x00, 0xC0, 0x38, 0x0E, 0x00, 0x00, 0x04, 0x1C, 0x1C, 0x04, 0x00, 0x00, // 86
    0x0E, 0xF8, 0x80, 0x80, 0xE0, 0x1C, 0x0E, 0x3C, 0xE0, 0x80, 0x80, 0x78, 0x0E, 0x00, 0x00, 0x1C, 0x1C, 0x04, 0x00, 0x00, 0x00, 0x04, 0x1C, 0x1C, 0x00, 0x00, // 87
    0x00, 0x06, 0x8C, 0xF0, 0x70, 0xF8, 0x8C, 0x02, 0x10, 0x18, 0x04, 0x00, 0x00, 0x00, 0x0C, 0x18, // 88
    0x06, 0x0C, 0x38, 0xF0, 0x30, 0x0C, 0x06, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, // 89
    0x00, 0x02, 0x82, 0x62, 0x12, 0x0E, 0x06, 0x18, 0x1C, 0x10, 0x10, 0x10, 0x10, 0x10, // 90
    0xFE, 0x02, 0x7C, 0x40, // 91
    0x06, 0x18, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x1C, // 92
    0x02, 0xFE, 0x40, 0x7C, // 93
    0x10, 0x0C, 0x06, 0x06, 0x08, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 94
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, // 95
    0x06, 0x0C, 0x00, 0x00, // 96
    0x00, 0x20, 0x90, 0x90, 0x90, 0xE0, 0x0C, 0x14, 0x10, 0x00, 0x10, 0x1C, // 97
    0xFE, 0x30, 0x10, 0x10, 0x30, 0xE0, 0x1C, 0x18, 0x10, 0x10, 0x18, 0x0C, // 98
    0xE0, 0x30, 0x10, 0x10, 0x10, 0x0C, 0x18, 0x10, 0x10, 0x10, // 99
    0xC0, 0x30, 0x10, 0x10, 0x10, 0x30, 0xFE, 0x0C, 0x18, 0x10, 0x10, 0x10, 0x18, 0x1C, // 100
    0xC0, 0xE0, 0x90, 0x90, 0x90, 0x90, 0xE0, 0x04, 0x0C, 0x10, 0x10, 0x10, 0x10, 0x00, // 101
    0x30, 0xFE, 0x31, 0x11, 0x00, 0x1C, 0x00, 0x00, // 102
    0xC0, 0x30, 0x10, 0x10, 0x10, 0x30, 0xF0, 0x04, 0x88, 0x90, 0x90, 0x90, 0xD8, 0x7C, // 103
    0xFE, 0x30, 0x10, 0x10, 0x30, 0xE0, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x1C, // 104
    0xF2, 0x1C, // 105
    0x00, 0x00, 0xF2, 0x80, 0xC0, 0x7C, // 106
    0xFC, 0x80, 0x80, 0x40, 0x20, 0x1C, 0x04, 0x04, 0x0C, 0x10, // 107
    0xFE, 0x1C, // 108
    0xE0, 0x60, 0x20, 0x20, 0xE0, 0x60, 0x20, 0x20, 0x60, 0xC0, 0x1C, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x1C, // 109
    0xF0, 0x30, 0x10, 0x10, 0x30, 0xE0, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x1C, // 110
    0xC0, 0x30, 0x10, 0x10, 0x30, 0xE0, 0x04, 0x18, 0x10, 0x10, 0x18, 0x04, // 111
    0xF0, 0x30, 0x10, 0x10, 0x30, 0xE0, 0xFC, 0x18, 0x10, 0x10, 0x18, 0x0C, // 112
    0xC0, 0x30, 0x10, 0x10, 0x10, 0x30, 0xF0, 0x04, 0x18, 0x10, 0x10, 0x10, 0x18, 0xFC, // 113
    0xF0, 0x30, 0x10, 0x10, 0x1C, 0x00, 0x00, 0x00, // 114
    0x60, 0xF0, 0x90, 0x20, 0x10, 0x10, 0x10, 0x1C, // 115
    0x10, 0xFC, 0x18, 0x10, 0x00, 0x0C, 0x18, 0x10, // 116
    0xF0, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x0C, 0x18, 0x10, 0x10, 0x18, 0x1C, // 117
    0x30, 0xE0, 0x00, 0x00, 0xC0, 0x30, 0x00, 0x04, 0x1C, 0x1C, 0x04, 0x00, // 118
    0x70, 0xC0, 0x00, 0x80, 0x70, 0x70, 0xC0, 0x00, 0x80, 0x70, 0x00, 0x0C, 0x1C, 0x0C, 0x00, 0x00, 0x0C, 0x1C, 0x0C, 0x00, // 119
    0x10, 0xE0, 0xE0, 0x30, 0x00, 0x18, 0x0C, 0x04, 0x18, 0x10, // 120
    0x30, 0xE0, 0x80, 0x00, 0xC0, 0x70, 0x80, 0x80, 0x7C, 0x3C, 0x04, 0x00, // 121
    0x20, 0x10, 0x90, 0x70, 0x20, 0x18, 0x1C, 0x10, 0x10, 0x00, // 122
    0xFC, 0x02, 0x3C, 0x40, // 123
    0xFE, 0x1C, // 124
    0x02, 0xFC, 0x40, 0x3C, // 125
    0x0C, 0x04, 0x0C, 0x04, 0x00, 0x00, 0x00, 0x00, // 126
    
};

#endif
