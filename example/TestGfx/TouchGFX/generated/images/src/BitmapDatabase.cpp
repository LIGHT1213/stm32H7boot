// 4.16.0 0x5afee504
// Generated by imageconverter. Please, do not edit!

#include <BitmapDatabase.hpp>
#include <touchgfx/Bitmap.hpp>

extern const unsigned char image_blue_buttons_round_edge_small[]; // BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_ID = 0, Size: 170x60 pixels
extern const unsigned char image_blue_buttons_round_edge_small_pressed[]; // BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID = 1, Size: 170x60 pixels
extern const unsigned char image_blue_progressindicators_bg_medium_circle_indicator_bg_full[]; // BITMAP_BLUE_PROGRESSINDICATORS_BG_MEDIUM_CIRCLE_INDICATOR_BG_FULL_ID = 2, Size: 104x104 pixels
extern const unsigned char image_blue_progressindicators_fill_medium_circle_indicator_fill_line_full[]; // BITMAP_BLUE_PROGRESSINDICATORS_FILL_MEDIUM_CIRCLE_INDICATOR_FILL_LINE_FULL_ID = 3, Size: 104x104 pixels
extern const unsigned char image_blue_slider_horizontal_small_indicators_slider_horizontal_small_round_knob[]; // BITMAP_BLUE_SLIDER_HORIZONTAL_SMALL_INDICATORS_SLIDER_HORIZONTAL_SMALL_ROUND_KNOB_ID = 4, Size: 54x34 pixels
extern const unsigned char image_blue_slider_horizontal_small_slider_horizontal_small_round_back[]; // BITMAP_BLUE_SLIDER_HORIZONTAL_SMALL_SLIDER_HORIZONTAL_SMALL_ROUND_BACK_ID = 5, Size: 172x20 pixels
extern const unsigned char image_blue_slider_horizontal_small_slider_horizontal_small_round_fill[]; // BITMAP_BLUE_SLIDER_HORIZONTAL_SMALL_SLIDER_HORIZONTAL_SMALL_ROUND_FILL_ID = 6, Size: 172x20 pixels

const touchgfx::Bitmap::BitmapData bitmap_database[] =
{
    { image_blue_buttons_round_edge_small, 0, 170, 60, 11, 4, 148, (uint8_t)(touchgfx::Bitmap::ARGB8888) >> 3, 50, (uint8_t)(touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_blue_buttons_round_edge_small_pressed, 0, 170, 60, 11, 4, 148, (uint8_t)(touchgfx::Bitmap::ARGB8888) >> 3, 50, (uint8_t)(touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_blue_progressindicators_bg_medium_circle_indicator_bg_full, 0, 104, 104, 16, 15, 72, (uint8_t)(touchgfx::Bitmap::ARGB8888) >> 3, 74, (uint8_t)(touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_blue_progressindicators_fill_medium_circle_indicator_fill_line_full, 0, 104, 104, 87, 31, 10, (uint8_t)(touchgfx::Bitmap::ARGB8888) >> 3, 42, (uint8_t)(touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_blue_slider_horizontal_small_indicators_slider_horizontal_small_round_knob, 0, 54, 34, 8, 4, 38, (uint8_t)(touchgfx::Bitmap::ARGB8888) >> 3, 24, (uint8_t)(touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_blue_slider_horizontal_small_slider_horizontal_small_round_back, 0, 172, 20, 10, 0, 152, (uint8_t)(touchgfx::Bitmap::ARGB8888) >> 3, 20, (uint8_t)(touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_blue_slider_horizontal_small_slider_horizontal_small_round_fill, 0, 172, 20, 10, 0, 152, (uint8_t)(touchgfx::Bitmap::ARGB8888) >> 3, 20, (uint8_t)(touchgfx::Bitmap::ARGB8888) & 0x7 }
};

namespace BitmapDatabase
{
const touchgfx::Bitmap::BitmapData* getInstance()
{
    return bitmap_database;
}

uint16_t getInstanceSize()
{
    return (uint16_t)(sizeof(bitmap_database) / sizeof(touchgfx::Bitmap::BitmapData));
}
}