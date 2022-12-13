#ifndef _EM_Piano_H_
#define _EM_Piano_H_
#include <Arduino.h>
#define KEY_MAX 8
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
extern ST_KEY_MAP em_ir_keymap[];

class Piano {
  private:
    uint8_t SCLPin, SDOPin;
  public:
    void initPiano(uint8_t SclPin, uint8_t SdoPin);
    uint16_t GetKeyCode(void);
    String GetKeyMap(void);
    uint16_t GetKey(void);
};
#endif  /* _KEYMAY_H_ */
