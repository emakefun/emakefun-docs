/***********************************************************************
 *       __                                                          _
 *      / /        _____  __    __  _          _   (_)   ________   | |
 *     / /____   / _____) \ \  / / | |   __   | |  | |  (  ______)  | |_____
 *    / / ___/  | |_____   \ \/ /  | |  /  \  | |  | |  | |______   |  ___  |
 *   / /\ \     | |_____|   \  /   | | / /\ \ | |  | |  (_______ )  | |   | |
 *  / /  \ \__  | |_____    / /    | |/ /  \ \| |  | |   ______| |  | |   | |
 * /_/    \___\  \______)  /_/      \__/    \__/   |_|  (________)  |_|   |_|
 *
 *
 * KeyWay Tech firmware
 *
 * Copyright (C) 2015-2020
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, in version 3.
 * learn more you can see <http://www.gnu.org/licenses/>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.
 *
 *
 * [Title]    Arduino Serial port printf voltage which read from continuous potentiometer
 * [diagram]
 *           Arduino PIN A5   ===================   SCLPin
 *           Arduino PIN A4  ===================   SDOPin
 */
#ifndef _EM_Piano_H_
#define _EM_Piano_H_

#include <Arduino.h>
#define KEY_MAX 8
#define EM_PIANO_KEYCODE_1 0xfefe
#define EM_PIANO_KEYCODE_2 0xfdfd
#define EM_PIANO_KEYCODE_3 0xfbfb
#define EM_PIANO_KEYCODE_4 0xf7f7 
#define EM_PIANO_KEYCODE_5 0xefef
#define EM_PIANO_KEYCODE_6 0xdfdf
#define EM_PIANO_KEYCODE_7 0xbfbf
#define EM_PIANO_KEYCODE_8 0x7f7f
#define EM_Piano_Released  0xFFFF

typedef struct
{
  String keyname;
  uint16_t keycode;
} ST_KEY_MAP;

typedef enum {
  EM_KEYCODE_1 = 0,
  EM_KEYCODE_2,
  EM_KEYCODE_3,
  EM_KEYCODE_4,
  EM_KEYCODE_5,
  EM_KEYCODE_6,
  EM_KEYCODE_7,
  EM_KEYCODE_8,
} E_EM_KEYCODE;
extern ST_KEY_MAP em_piano_keymap[];




class Piano {
  private:
    uint8_t SCLPin, SDOPin;
    unsigned int PianoKey;
  public:
    void initPiano(uint8_t SclPin, uint8_t SdoPin);
    uint16_t GetKeyCode(void);
    String GetKeyMap(void);
    uint16_t GetKey(void);
    boolean PressBsButton(unsigned int button);
};
#endif  /* _KEYMAY_H_ */
