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
	      KC_1,  KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
        KC_7,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
        KC_8,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
        KC_9,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
        KC_0,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
												                           KC_6,  KC_1,  KC_2,    
															                                   KC_3,
                                                                 KC_4
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

std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
    {KEYMAP(
	    KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5, 
      KC_DEL,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, 
      KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
      KC_LSFT, XXXXXXX, KC_X,    KC_C,    KC_V,    KC_B,
		  XXXXXXX, KC_QUOT,ALT_SHFT, KC_LEFT, KC_RGHT, KC_SPC, 
													                         KC_BSPC,KC_LALT,KC_LGUI,
																	                                 KC_HOME,
																	                                 KC_END  
    )};

 
void setupKeymap() {

    uint32_t qwerty_taph[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( 
	    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, CTL_Z_TAP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		L1GRV_TAP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
													                         XXXXXXX, XXXXXXX, XXXXXXX,
																                                     XXXXXXX,
																	                                   XXXXXXX
);

    uint32_t qwerty_hold[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( 
	    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, CTL_Z_HOLD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		L1GRV_HOLD,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
													                         XXXXXXX, XXXXXXX, XXXXXXX,
																                                     XXXXXXX,
																	                                   XXXXXXX		
);

    uint32_t lower[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
	    PRINT_BATTERY, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , 
        _______, KC_EXLM, KC_AT  , KC_LBRC, KC_RBRC, KC_PIPE,  
        _______, KC_HASH, KC_DLR , KC_LPRN, KC_RPRN, KC_GRV ,
        _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, 
		    _______, _______, _______, _______, _______, _______, 
													                           _______, _______, _______,
																                                       _______,
																	                                     _______	
);

    uint32_t raise[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
	      HOME_ADD, _______, _______, _______, _______, _______, 
        WORK_ADD, _______, _______, KC_MS_UP, _______, _______,  
        EMAIL_1, _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, _______,
        EMAIL_2, _______, _______, _______, _______, _______, 
		    _______, _______, _______, KC_MS_BTN1, KC_MS_BTN2, _______, 
													                           _______, _______, _______,
																                                       _______,
																	                                     _______	
);
 
    /*
     * add the other layers on the regular presses.
     */
    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {		
            matrix[row][col].addActivation(_QWERTY, Method::MT_TAP, qwerty_taph[row][col]);
            matrix[row][col].addActivation(_QWERTY, Method::MT_HOLD, qwerty_hold[row][col]);	
            matrix[row][col].addActivation(_LOWER, Method::PRESS, lower[row][col]);
            matrix[row][col].addActivation(_RAISE, Method::PRESS, raise[row][col]);
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
//    KeyScanner::process_for_tri_layers(_LOWER, _RAISE, _ADJUST);
}

#endif  // left



#if KEYBOARD_SIDE == RIGHT


std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
    {KEYMAP(
		                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_BSPC, 
                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_MINS, 
                          KC_H,    KC_J,    KC_K,    KC_L,    XXXXXXX,  XXXXXXX,
                          KC_N,    KC_M,    KC_COMM, KC_DOT,  XXXXXXX,  KC_RSFT,
                          KC_ENT , KC_UP  , KC_DOWN, KC_LBRC, KC_RBRC,  L_LOWER,
        KC_RALT, XXXXXXX, KC_TAB ,
        KC_PGUP,  
        KC_PGDN
    )};

 

void setupKeymap() {

    uint32_t qwerty_taph[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( 
		                      XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
                          XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
                          XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, L2COL_TAP, LG_QUOT_TAP,
                          XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, CTL_SLS_TAP,XXXXXXX,
                          XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX,CTL_ESC_TAP,XXXXXXX ,
        XXXXXXX,  
        XXXXXXX
);

    uint32_t qwerty_hold[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( 		
		                  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
                          XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
                          XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, L2COL_HOLD, LG_QUOT_HOLD,
                          XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, CTL_SLS_HOLD,XXXXXXX,
                          XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX,CTL_ESC_HOLD,XXXXXXX ,
        XXXXXXX,  
        XXXXXXX
);

    uint32_t lower[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
                          KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,
                          KC_UP  ,KC_P7  ,KC_P8  ,KC_P9  ,KC_PAST,KC_F12 ,
                          KC_DOWN,KC_P4  ,KC_P5  ,KC_P6  ,KC_PPLS,_______,
                          KC_AMPR,KC_P1  ,KC_P2  ,KC_P3  ,KC_PSLS,_______,
                          _______,_______,KC_PDOT,KC_P0  ,KC_PEQL,_______,
          _______,_______,_______,
          _______,                                   
          _______                                       
);

    uint32_t raise[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
                          _______,_______,_______,_______,_______,PRINT_BATTERY,
                          _______,_______,_______,_______,_______,_______,
                          _______,_______,_______,_______,_______,KC_MEDIA_PLAY_PAUSE,
                          _______,_______,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,_______,_______,
                          KC_WWW_BACK,KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,_______,_______,
          _______,_______,_______,
          _______,                                   
          _______  
);


    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {
            matrix[row][col].addActivation(_QWERTY, Method::MT_TAP, qwerty_taph[row][col]);
            matrix[row][col].addActivation(_QWERTY, Method::MT_HOLD, qwerty_hold[row][col]);				
            matrix[row][col].addActivation(_LOWER, Method::PRESS, lower[row][col]);
            matrix[row][col].addActivation(_RAISE, Method::PRESS, raise[row][col]);
        }
    }

}

void process_user_macros(uint16_t macroid)
{

}


void process_user_layers(uint16_t layermask)
{
 //    KeyScanner::process_for_tri_layers(_LOWER, _RAISE, _ADJUST);
}

#endif
