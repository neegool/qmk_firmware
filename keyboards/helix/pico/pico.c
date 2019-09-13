#include "helix.h"

#ifdef SSD1306OLED
#include "ssd1306.h"

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
	return process_record_gfx(keycode,record) && process_record_user(keycode, record);
}

void led_set_kb(uint8_t usb_led) {
    // put your keyboard LED indicator (ex: Caps Lock LED) toggling code here
    //led_set_user(usb_led);
}
#endif

void matrix_init_kb(void) {

	matrix_init_user();
};

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
    {   0,   1,   2,   3,   4,   5, NO_LED }, 
    {  12,  13,  14,  15,  16,  17, NO_LED }, 
    {  24,  25,  26,  27,  28,  29, NO_LED }, 
    {  36,  37,  38,  39,  40,  41,      42},
    { NO_LED,  6,   7,   8,   9,  10,  11 },
    { NO_LED, 18,  19,  20,  21,  22,  23 },
    { NO_LED, 30,  31,  32,  33,  34,  35 },
    {    43,  44,  45,  46,  47,  48,  49 } 
}, {
    {   0,   0 }, {  17,   0 }, {  34,   0 }, {  52,   0 }, {  69,   0 }, { 86,   0 },                           { 138,   0 }, { 155,   0 }, { 172,   0 }, { 190,   0 }, { 207,   0 }, { 224,   0 },
    {   0,  21 }, {  17,  21 }, {  34,  21 }, {  52,  21 }, {  69,  21 }, { 86,  21 },                           { 138,  21 }, { 155,  21 }, { 172,  21 }, { 190,  21 }, { 207,  21 }, { 224,  21 },
    {   0,  43 }, {  17,  43 }, {  34,  43 }, {  52,  43 }, {  69,  43 }, { 86,  43 },                           { 138,  43 }, { 155,  43 }, { 172,  43 }, { 190,  43 }, { 207,  43 }, { 224,  43 },
    {   0,  64 }, {  17,  64 }, {  34,  64 }, {  52,  64 }, {  69,  64 }, { 86,  64 }, { 103, 64 }, { 121, 64 }, { 138,  64 }, { 155,  64 }, { 172,  64 }, { 190,  64 }, { 207,  64 }, { 224,  64 }
}, {
    1, 4, 4, 4, 4, 4,       4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4,       4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4,       4, 4, 4, 4, 4, 1,
    1, 1, 1, 1, 1, 1, 4, 4, 1, 1, 1, 1, 1, 1
} };
#endif