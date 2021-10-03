#include <hidboot.h>
#include <usbhub.h>
#include <BleCombo.h>
#include <SPI.h>règerrffnmn56u787671117

bool isCtrlPress=false;
bool isShiftPress=false;
bool isAltPress=false;
bool isGuiPress=false;

class KbdRptParser : public KeyboardReportParser {
    void PrintKey(uint8_t mod, uint8_t key);
  protected:
    void OnControlKeysChanged(uint8_t before, uint8_t after);
    void OnKeyDown  (uint8_t mod, uint8_t key);
    void OnKeyUp  (uint8_t mod, uint8_t key);
    void OnKeyPressed(uint8_t key);
};

void KbdRptParser::PrintKey(uint8_t m, uint8_t key) {
};

void KbdRptParser::OnControlKeysChanged(uint8_t before, uint8_t after) {
  MODIFIERKEYS beforeMod;
  *((uint8_t*)&beforeMod) = before;
  MODIFIERKEYS afterMod;
  *((uint8_t*)&afterMod) = after;
  if (beforeMod.bmLeftCtrl != afterMod.bmLeftCtrl) {
    if (!isCtrlPress) {
      Keyboard.press(KEY_LEFT_CTRL);
      isCtrlPress=true;
    } else {
      Keyboard.release(KEY_LEFT_CTRL);
      isCtrlPress=false;
    }
  }
  if (beforeMod.bmLeftShift != afterMod.bmLeftShift) {
    if (!isShiftPress) {
      Keyboard.press(KEY_LEFT_SHIFT);
      isShiftPress=true;
    } else {
      Keyboard.release(KEY_LEFT_SHIFT);
      isShiftPress=false;
    }
  }
  if (beforeMod.bmLeftAlt != afterMod.bmLeftAlt) {
    if (!isAltPress) {
      Keyboard.press(KEY_LEFT_ALT);
      isAltPress=true;
    } else {
      Keyboard.release(KEY_LEFT_ALT);
      isAltPress=false;
    }
  }
  if (beforeMod.bmLeftGUI != afterMod.bmLeftGUI) {
    if (!isGuiPress) {
      Keyboard.press(KEY_LEFT_GUI);
      isGuiPress=true;
    } else {
      Keyboard.release(KEY_LEFT_GUI);
      isGuiPress=false;
    }
  }
  
  if (beforeMod.bmRightCtrl != afterMod.bmRightCtrl) {
    if (!isCtrlPress) {
      Keyboard.press(KEY_RIGHT_CTRL);
      isCtrlPress=true;
    } else {
      Keyboard.release(KEY_RIGHT_CTRL);
      isCtrlPress=false;
    }
  }
  if (beforeMod.bmRightShift != afterMod.bmRightShift) {
    if (!isShiftPress) {
      Keyboard.press(KEY_RIGHT_SHIFT);
      isShiftPress=true;
    } else {
      Keyboard.release(KEY_RIGHT_SHIFT);
      isShiftPress=false;
    }
  }
  if (beforeMod.bmRightAlt != afterMod.bmRightAlt) {
    if (!isAltPress) {
      Keyboard.press(KEY_RIGHT_ALT);
      isAltPress=true;
    } else {
      Keyboard.release(KEY_RIGHT_ALT);
      isAltPress=false;
    }
  }
  if (beforeMod.bmRightGUI != afterMod.bmRightGUI) {
    if (!isGuiPress) {
      Keyboard.press(KEY_RIGHT_GUI);
      isGuiPress=true;
    } else {
      Keyboard.release(KEY_RIGHT_GUI);
      isGuiPress=false;
    }
  }
}
void KbdRptParser::OnKeyDown(uint8_t mod, uint8_t key) { 
  uint8_t c = OemToAscii(mod, key);
  if (c)
    OnKeyPressed(c);
  if (key==0x2A) Keyboard.press(KEY_BACKSPACE); 
  if (key==0x28) Keyboard.press(KEY_RETURN);
  if (key==0x50) Keyboard.press(KEY_LEFT_ARROW); 
  if (key==0x4F) Keyboard.press(KEY_RIGHT_ARROW);
  if (key==0x52) Keyboard.press(KEY_UP_ARROW); 
  if (key==0x51) Keyboard.press(KEY_DOWN_ARROW);
  if (key==0x4B) Keyboard.press(KEY_PAGE_UP); 
  if (key==0x4E) Keyboard.press(KEY_PAGE_DOWN);
  if (key==0x4A) Keyboard.press(KEY_HOME); 
  if (key==0x4D) Keyboard.press(KEY_END);
  if (key==0x49) Keyboard.press(KEY_INSERT); 
  if (key==0x4C) Keyboard.press(KEY_DELETE);
  if (key==0x29) Keyboard.press(KEY_ESC);
  if (key==0x3A) Keyboard.press(KEY_F1); 
  if (key==0x3B) Keyboard.press(KEY_F2); 
  if (key==0x3C) Keyboard.press(KEY_F3);
  if (key==0x3D) Keyboard.press(KEY_F4); 
  if (key==0x3E) Keyboard.press(KEY_F5);
  if (key==0x3F) Keyboard.press(KEY_F6); 
  if (key==0x40) Keyboard.press(KEY_F7);
  if (key==0x41) Keyboard.press(KEY_F8); 
  if (key==0x42) Keyboard.press(KEY_F9);
  if (key==0x43) Keyboard.press(KEY_F10); 
  if (key==0x44) Keyboard.press(KEY_F11);
  if (key==0x45) Keyboard.press(KEY_F12);
  if (key==0x46) {
    Keyboard.write(KEY_MEDIA_VOLUME_DOWN);
  }
  if (key==0x47) {
    Keyboard.write(KEY_MEDIA_MUTE);
  }
  if (key==0x48) {
    Keyboard.write(KEY_MEDIA_VOLUME_UP);
  }
  if (key==0x2B) Keyboard.press(KEY_TAB);
  if (key==0x39) Keyboard.press(KEY_CAPS_LOCK);
}

void KbdRptParser::OnKeyUp(uint8_t mod, uint8_t key) {              
  if (key==0x2A) Keyboard.release(KEY_BACKSPACE);
  if (key==0x28) Keyboard.release(KEY_RETURN); 
  if (key==0x50) Keyboard.release(KEY_LEFT_ARROW); 
  if (key==0x4F) Keyboard.release(KEY_RIGHT_ARROW);
  if (key==0x52) Keyboard.release(KEY_UP_ARROW); 
  if (key==0x51) Keyboard.release(KEY_DOWN_ARROW);
  if (key==0x4B) Keyboard.release(KEY_PAGE_UP); 
  if (key==0x4E) Keyboard.release(KEY_PAGE_DOWN);
  if (key==0x4A) Keyboard.release(KEY_HOME); 
  if (key==0x4D) Keyboard.release(KEY_END);
  if (key==0x49) Keyboard.release(KEY_INSERT); 
  if (key==0x4C) Keyboard.release(KEY_DELETE);  
  if (key==0x29) Keyboard.release(KEY_ESC);
  if (key==0x3A) Keyboard.release(KEY_F1); 
  if (key==0x3B) Keyboard.release(KEY_F2); 
  if (key==0x3C) Keyboard.release(KEY_F3);
  if (key==0x3D) Keyboard.release(KEY_F4); 
  if (key==0x3E) Keyboard.release(KEY_F5);
  if (key==0x3F) Keyboard.release(KEY_F6); 
  if (key==0x40) Keyboard.release(KEY_F7);
  if (key==0x41) Keyboard.release(KEY_F8); 
  if (key==0x42) Keyboard.release(KEY_F9);
  if (key==0x43) Keyboard.release(KEY_F10); 
  if (key==0x44) Keyboard.release(KEY_F11);
  if (key==0x45) Keyboard.release(KEY_F12);                
  if (key==0x2B) Keyboard.release(KEY_TAB);
  if (key==0x39) Keyboard.release(KEY_CAPS_LOCK);
} 

void KbdRptParser::OnKeyPressed(uint8_t key) {  
  Keyboard.print((char)key);
};

USB     Usb;
HIDBoot<USB_HID_PROTOCOL_KEYBOARD>    HidKeyboard(&Usb);
KbdRptParser Prs;
