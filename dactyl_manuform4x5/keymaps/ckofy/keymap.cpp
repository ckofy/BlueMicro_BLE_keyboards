/*
Copyright 2018 <Pierre Constantineau>

3-Clause BSD License

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
#include "keymap.h"


#if KEYBOARD_SIDE == MASTER
std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
    {KEYMAP(
       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
                KC_2,    KC_3,    
                                  KC_4,    KC_5,
                                  KC_6,    KC_7,
                                  KC_8,    KC_9
    )};

void setupKeymap() {

   // no layers for master keymap
   // this is a keymap that's used for testing that each key is responding properly to key presses
   // flash this keymap to both left and right to test whether each half works properly.
   // once tested, you can flash the left and right to their respective halves.

}

void process_user_macros(uint16_t macroid)
{
	
}	

void process_user_layers(uint16_t layermask)
{
	
}	
#endif


#if KEYBOARD_SIDE == LEFT

/* Colemak DH
 * ,----------------------------------.
 * |   Q  |   W  |   F  |   P  |   B  | 
 * |------+------+------+------+------|
 * |   A  |   R  |   S  |   T  |   G  |
 * |------+------+------+------+------|
 * |   Z  |   X  |   C  |   D  |   V  |
 * `------+------+------+------+------'
 *        | Esc  |   =  |
 *        `---------------------------.
 *                      |Lower |Space |
 *                      `---------------------------. 
 *                                    | Bksp | Ctrl |
 *                                    --------------| 
 *                                    | Tab  |  Alt |
 *                                    --------------' 
 */

std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
    {KEYMAP(
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B, 
        KC_A,    KC_R,    KC_S,    KC_T,    KC_G,
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,
                 KC_ESC,  KC_EQL,  
                                   L_LOWER, KC_SPC,
                                                    KC_LCTL, L_MACRO,
                                                    KC_TAB,  KC_LALT
    )};

 
void setupKeymap() {

/* Lower
 * ,----------------------------------.
 * | LOCK |      |Ctrl-E| Caps |Ctrl-B| 
 * |------+------+------+------+------|
 * |  GUI | ALT  | SHFT | CTRL | Save |
 * |------+------+------+------+------|
 * | Undo | Cut  | Copy | Paste| Dup  |
 * `----------------------------------'
 *        |      |      |
 *        `---------------------------.
 *                      |      |      |
 *                      `---------------------------. 
 *                                    |      |      |
 *                                    --------------| 
 *                                    |      |      |
 *                                    --------------' 
 */
    uint32_t lower[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
  KC_LOCK,XXXXXXX,KC_SWP, KC_CAPS,KC_BRK,  \
  KC_LGUI,KC_LALT,KC_LSFT,KC_LCTL,KC_SVE,  \
  KC_UND, KC_CUT, KC_CPY, KC_PST, _______, \
          _______,_______,                 \
                          _______,_______, \
                                           _______,_______, \
                                           _______,_______  \
);

/* Raise
 * ,----------------------------------.
 * |  &   |  %   |  #   |  (   |   !  |
 * |------+------+------+------+------|
 * |  7   |  5   |  3   |  1   |  9   |
 * |------+------+------+------+------|
 * |  `   |  [   |  ]   |  _   |  =   |
 * `----------------------------------'
 *        |      |      |
 *        `---------------------------.
 *                      |      |      |
 *                      `---------------------------. 
 *                                    |      |      |
 *                                    --------------| 
 *                                    |      |      |
 *                                    --------------' 
 */
    uint32_t raise[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
  KC_AMPR, KC_PERC,KC_HASH,KC_LPRN,KC_EXLM, \
  KC_7,    KC_5,   KC_3,   KC_1,   KC_9,    \
  KC_GRAVE,KC_LBRC,KC_RBRC,KC_UNDS,KC_EQL,  \
          _______,_______,                 \
                           _______,_______, \
                                            _______,_______, \
                                            _______,_______  \
);
/* Adjust
 * ,----------------------------------.
 * |   F1 |  F2  |  F3  |  F4  |  F5  |
 * |------+------+------+------+-------
 * |      |      |      |      |      |
 * |------+------+------+------+------+
 * |      |      |      |      |      |
 * `----------------------------------'
 *        |      |      |
 *        `---------------------------.
 *                      |      |      |
 *                      `---------------------------. 
 *                                    |      |      |
 *                                    --------------| 
 *                                    |      |      |
 *                                    --------------' 
 */
    uint32_t adjust[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
   KC_F1,  KC_F2,  KC_F3,   KC_F4,   KC_F5,   \
   _______,_______,_______, _______, _______, \
   _______,_______,_______, _______, _______, \
           _______,_______,                   \
                            _______,_______,  \
                                             _______,_______, \
                                             _______,_______  \ 
);

    uint32_t macro[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
  PRINT_BATTERY,HOME_ADD,EMAIL_1,EMAIL_2,WORK_ADD, \		
  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,    \
  PRINT_INFO,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, \
             XXXXXXX,XXXXXXX,		          \
                             XXXXXXX,XXXXXXX, \
                                              XXXXXXX,XXXXXXX, \
                                              XXXXXXX,XXXXXXX  \
);

    /*
     * add the other layers on the regular presses.
     */
    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {		
            matrix[row][col].addActivation(_LOWER, Method::PRESS, lower[row][col]);
            matrix[row][col].addActivation(_RAISE, Method::PRESS, raise[row][col]);
            matrix[row][col].addActivation(_ADJUST, Method::PRESS, adjust[row][col]);
            matrix[row][col].addActivation(_MACRO,  Method::PRESS, macro[row][col]);
        }
    }

}

void process_user_macros(uint16_t macroid)
{

				  
 switch ((macroid))
 { 
     case HOME_ADD:
     addStringToQueue("123 Quiet Crescent");
     break;
     case WORK_ADD:
     addStringToQueue("123 Work Place");
      break;
     case EMAIL_1:
     addStringToQueue("Primary@Email");
      break;
     case EMAIL_2:
     addStringToQueue("Other@Email");
      break;   
 }
}

void process_user_layers(uint16_t layermask)
{
    KeyScanner::process_for_tri_layers(_LOWER, _RAISE, _ADJUST);
}

#endif  // left



#if KEYBOARD_SIDE == RIGHT

/* Colemak DH
 *                ,----------------------------------.
 *                |   J  |   L  |   U  |   Y  |   ;  |
 *                |------+------+------+------+------|
 *                |   M  |   N  |   E  |   I  |   O  |
 *                |------+------+------+------+------|
 *                |   K  |   H  |   ,  |   .  |   /  |
 *                `----------------------------------'
 *                              |   -  |   '  |
 *                ,---------------------------'
 *                | Shift| Raise|
 *  ,---------------------------' 
 *  | Ctrl | Enter|
 *  |-------------| 
 *  | GUI  | Bksp |
 *  `-------------' 
 */

std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
    {KEYMAP(
        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCOLON,
        KC_M,    KC_N,    KC_E,    KC_I,    KC_O,     
        KC_K,    KC_H,    KC_COMMA,KC_DOT,  KC_SLSH,  
                          KC_MINS ,KC_QUOTE, 
        KC_LSFT ,L_RAISE,				  
        KC_RCTL, KC_ENT,
        KC_LGUI, KC_BSPACE
    )};

 

void setupKeymap() {

/* Lower
 *                ,----------------------------------.
 *                | PgUp | Home |  Up  | End  | Del  |
 *                |------+------+------+------+------|
 *                | PgDn | Left | Down | Right| BkSp |
 *                |------+------+------+------+------|
 *                |  Ins |      |      |      |      |
 *                `----------------------------------'
 *                              |      |      |
 *                ,---------------------------'
 *                |      |      |
 *  ,---------------------------' 
 *  |      |      |
 *  |-------------| 
 *  |      |      |
 *  `-------------' 
 */
    uint32_t lower[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
  KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_DEL,  \
  KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, \
  KC_INS , XXXXXXX, KC_COMMA,KC_DOT,  KC_SLSH, \
                    _______, _______,          \
  _______, _______,                            \
  _______, _______,                            \
  _______, _______                             \ 
);

/* Raise
 *                ,----------------------------------.
 *                |   *  |   )  |  @   |   $  |   ^  |
 *                |------+------+------+------+------|
 *                |  8   |  0   |  2   |   4  |  6   |
 *                |------+------+------+------+------|
 *                | +    |  -   |      |      |  \   |
 *                `----------------------------------'
 *                              |      |      |
 *                ,---------------------------'
 *                |      |      |
 *  ,---------------------------' 
 *  |      |      |
 *  |-------------| 
 *  |      |      |
 *  `-------------' 
 */
    uint32_t raise[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
  KC_ASTR, KC_RPRN, KC_AT,   KC_DLR,  KC_CIRC, \
  KC_8,    KC_0,    KC_2,    KC_4,    KC_6,    \
  KC_PLUS, KC_MINUS,KC_COMMA,KC_DOT,  KC_BSLS, \
                    _______, _______,          \
  _______, _______,                            \
  _______, _______,                            \
  _______, _______                             \ 
);

/* Adjust
 *                ,-----------------------------------------.
 *                |  F6  |  F7  |  F8  |  F9  | F10  |      |
 *                |-----------------------------------------|
 *                |      |      |      | F11  | F12  |      |
 *                |------+------+------+------+-------------|
 *                |      |      |      |      |      |      |
 *                |------+------+------+------+------|------|
 *                |      |      |      |      |      |      |
 *                `-----------------------------------------'
 *                              |      |      |
 *                ,---------------------------'
 *                |      |      |
 *  ,---------------------------' 
 *  |      |      |
 *  |-------------| 
 *  |      |      |
 *  `-------------' 
 */
    uint32_t adjust[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, \
  _______, _______, _______, KC_F11,  KC_F12, \
  _______, _______, _______, _______, _______,\
                    _______, _______,         \
  _______, _______,                           \
  _______, _______,                           \
  _______, _______                            \ 
);

    uint32_t macro[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,PRINT_BATTERY,\		
  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,      \
  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,PRINT_INFO,   \
                  XXXXXXX,XXXXXXX,              \
  XXXXXXX,XXXXXXX,                              \
  XXXXXXX,XXXXXXX,                              \
  XXXXXXX,XXXXXXX                               \
);
    /*
     * add the other layers
     */
    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {
            matrix[row][col].addActivation(_LOWER, Method::PRESS, lower[row][col]);
            matrix[row][col].addActivation(_RAISE, Method::PRESS, raise[row][col]);
            matrix[row][col].addActivation(_ADJUST, Method::PRESS, adjust[row][col]);
            matrix[row][col].addActivation(_MACRO,  Method::PRESS, macro[row][col]);
        }
    }

}

void process_user_macros(uint16_t macroid)
{

}


void process_user_layers(uint16_t layermask)
{
    KeyScanner::process_for_tri_layers(_LOWER, _RAISE, _ADJUST);
}

#endif
