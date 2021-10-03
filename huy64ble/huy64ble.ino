#include "var.h"
void setup() {
  Keyboard.begin();
  if (Usb.Init() == -1)
  delay(100);
  HidKeyboard.SetReportParser(0, &Prs);
}

void loop() {
  Usb.Task(); 
}
