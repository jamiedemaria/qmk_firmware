/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for my custom setup
  [0] = LAYOUT_universal(
    QK_GRAVE_ESCAPE   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                        KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_MINS   ,
    KC_TAB   , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                        KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , KC_ENT  ,
    KC_LSFT  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                                        KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , RSFT_T(KC_QUOT)  ,
              KC_LCTL,KC_LALT,KC_LCMD     ,KC_BTN1,LT(4,KC_BTN2),                  LT(2,KC_BSPC),LT(1,KC_SPC), XXXXXXX,     XXXXXXX  , KC_LBRC
  ),
  // numbers, desktop navigation, [], (), {}
  [1] = LAYOUT_universal(
    KC_GRV  ,KC_EQL, KC_7     , KC_8    , KC_9     , S(KC_8)  ,                                         S(KC_9)  , S(KC_0)  , C(KC_UP)  , KC_LBRC  , KC_RBRC  , _______  ,
    _______  ,KC_PLUS, KC_4     , KC_5    , KC_6     , KC_EQL  ,                                         S(KC_LBRC)  , C(KC_LEFT)  , C(KC_DOWN), C(KC_RIGHT)  , XXXXXXX  , XXXXXXX  ,
    _______  ,S(KC_MINS), KC_1     , KC_2    , KC_3     ,S(KC_LBRC),                                        S(KC_RBRC),XXXXXXX, XXXXXXX   ,XXXXXXX, S(KC_SLSH),XXXXXXX,
                  KC_0     , KC_DOT  , _______  ,         _______  , _______  ,                   _______   , _______  , _______       , _______  , _______
  ),
  // symbols, arrows, shift + cmd/alt for selecting text with arrows
  [2] = LAYOUT_universal(
    KC_GRAVE  ,  S(KC_SLSH)   , XXXXXXX    , S(KC_1)   , XXXXXXX    , S(KC_GRV)    ,                                  XXXXXXX    , S(KC_PIPE)    , KC_UP    , XXXXXXX    , S(KC_5)   , XXXXXXX   ,
    _______  ,  S(KC_2) , S(KC_8)  , S(KC_4)   , XXXXXXX   , XXXXXXX   ,                                         S(KC_3)  , KC_LEFT  , KC_DOWN    , KC_RGHT  , XXXXXXX  , XXXXXXX   ,
    _______  ,  _______ , XXXXXXX  , S(KC_6) , XXXXXXX  , XXXXXXX  ,                                         S(KC_7)  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , _______  ,
                  KC_LCTL  , KC_LALT , KC_LCMD  ,       S(KC_LALT)  , S(KC_LCMD)  ,                   _______  , _______  , _______       , _______  , _______
  ),

  // page up/down, end/home, tab navigation 
  [4] = LAYOUT_universal(
    _______   , XXXXXXX     , XXXXXXX    , XXXXXXX     , XXXXXXX     , XXXXXXX     ,                        KC_END     ,XXXXXXX     , KC_PGUP     , XXXXXXX     , XXXXXXX     , XXXXXXX  ,
    XXXXXXX   , XXXXXXX     , XXXXXXX     , XXXXXXX     , XXXXXXX     , XXXXXXX     ,                        KC_HOME    , RCS(KC_TAB)    , KC_PGDN    , C(KC_TAB)     , XXXXXXX  , _______  ,
    XXXXXXX  , XXXXXXX    , XXXXXXX     , XXXXXXX     , XXXXXXX     , XXXXXXX     ,                          XXXXXXX    , XXXXXXX     , XXXXXXX  , XXXXXXX   , XXXXXXX  , XXXXXXX  ,
              _______,_______,_______     ,_______,_______,                                             _______,_______, _______,     _______  , _______
  ),


};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 4
    keyball_set_scroll_mode(get_highest_layer(state) == 4);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    // keyball_oled_render_keyinfo();
    // keyball_oled_render_ballinfo();
    // keyball_oled_render_layerinfo();
}
#endif
