#include <Keyboard.h>
#include <Button.h>
#include <ButtonEventCallback.h>
#include <PushButton.h>
#include <Bounce2.h>

const int button_hold_threshold = 500;

const int Button_2_pin = 6;    // upper LH button
const int Button_3_pin = 7;    // upper LH button
const int Button_4_pin = 9;    // upper LH button
const int Button_5_pin = 8;    // upper LH button

const char Button_2_press_key = KEY_LEFT_ARROW;           // Pfeil - Links
const char Button_2_hold_key = KEY_F1;                    // QuickMenü (F1)

const char Button_3_press_key = KEY_RIGHT_ARROW;           // Pfeil - Rechts
const char Button_3_hold_key = KEY_ESC;                   // ESC

const char Button_4_press_key = KEY_UP_ARROW;           // Pfeil - Rechts
const char Button_4_hold_key = KEY_RETURN;              // Return (Bestätigen)

const char Button_5_press_key = KEY_DOWN_ARROW;           // Pfeil - Runter
// const char Button_5_hold_key = KEY_ESC;                   // ESC

PushButton Button_2 = PushButton(Button_2_pin, ENABLE_INTERNAL_PULLUP);
PushButton Button_3 = PushButton(Button_3_pin, ENABLE_INTERNAL_PULLUP);
PushButton Button_4 = PushButton(Button_4_pin, ENABLE_INTERNAL_PULLUP);
PushButton Button_5 = PushButton(Button_5_pin, ENABLE_INTERNAL_PULLUP);

void setup() {

  Button_2.onRelease(0, button_hold_threshold - 1, onButtonReleased);
  Button_2.onHold(button_hold_threshold, onButtonHeld);

  Button_3.onRelease(0, button_hold_threshold - 1, onButtonReleased);
  Button_3.onHold(button_hold_threshold, onButtonHeld);

  Button_4.onRelease(0, button_hold_threshold - 1, onButtonReleased);
  Button_4.onHold(button_hold_threshold, onButtonHeld);

  Button_5.onRelease(0, button_hold_threshold - 1, onButtonReleased);
  Button_5.onHold(button_hold_threshold, onButtonHeld);

  Keyboard.begin();

}


void loop() {
  Button_2.update();
  Button_3.update();
  Button_4.update();
  Button_5.update();
}


void onButtonReleased(Button& btn) {
  if (btn.is(Button_2)) Keyboard.press(Button_2_press_key);
  if (btn.is(Button_3)) Keyboard.press(Button_3_press_key);
  if (btn.is(Button_4)) Keyboard.press(Button_4_press_key);
  if (btn.is(Button_5)) Keyboard.press(Button_5_press_key);
  Keyboard.releaseAll();
}

void onButtonHeld(Button& btn) {
  if (btn.is(Button_2)) Keyboard.press(Button_2_hold_key);
  if (btn.is(Button_3)) Keyboard.press(Button_3_hold_key);
  if (btn.is(Button_4)) Keyboard.press(Button_4_hold_key);
  if (btn.is(Button_5)) {
    Keyboard.press(KEY_LEFT_ALT);
    delay(100);
    Keyboard.press(KEY_TAB);
    Keyboard.release(KEY_TAB);
    delay(100);
    Keyboard.press(KEY_TAB);
    delay(100);
    Keyboard.release(KEY_TAB);
    delay(500);
  }
  Keyboard.releaseAll();
}
