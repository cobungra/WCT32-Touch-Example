/*
    Simple Touch menu, graphics and JPG display sample for WT32-SC01 
    https://github.com/cobungra
    
    References and credits: 
    Bodmer (TFT_eSPI) https://github.com/Bodmer
    lovyan03 (LovyanGFX) https://github.com/lovyan03
    TJpgDec http://elm-chan.org/fsw/tjpgd/00index.html
*/
#define LGFX_AUTODETECT     // Autodetect board
#define LGFX_USE_V1         // set to use new version of library
#include <LovyanGFX.hpp>    // main library
#include <TJpg_Decoder.h>
#include "LittleFS.h" 
#include "Free_Fonts.h"

static LGFX tft;            // declare display variable
static int32_t x, y; // Touch
String imagefile;
int pressed;
int k,i, mSelect, menuNum = 0; // Start with main
uint32_t keyStart;
int keyDelay = 1000; // 2 seconds betwen keypresses avoid bounce
bool tft_output(int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t* bitmap)
{
  if ( y >= tft.height() ) return 0;
  tft.pushImage(x, y, w, h, bitmap);
  return 1;
}
String controlLabel[10] = {"MAIN", "", "Image", "Text", "", "", "Lamp L", "Lamp R", "Utility", ""};
int Bx[30] = {0, 80, 160, 240, 320, 400, 0, 80, 160, 240, 320, 400,  0, 80, 160, 240, 320, 400,  0, 80, 160, 240, 320, 400,  0, 80, 160, 240, 320, 400};
int By[30] = {0,  0,  0,  0,  0,  0, 64, 64, 64, 64, 64, 64, 128, 128, 128, 128, 128, 128, 192, 192, 192, 192, 192, 192, 256, 256, 256, 256, 256, 256};
const int controlArray [] = {4,5,10,11,16,17,22,23,28,29};  //Menu buttons-1
  

void setup(void)
{
  Serial.begin(115200); 
  tft.init();
  // Setting display to landscape
  if (tft.width() < tft.height()) tft.setRotation(tft.getRotation() ^ 1);
  tft.setSwapBytes(true); // We need to swap the colour bytes (endianess)
  TJpgDec.setJpgScale(1);
  TJpgDec.setCallback(tft_output);
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  tft.setFont(FSS12);
  tft.setCursor(0, 0);
  tft.setTextColor(TFT_YELLOW);
  tft.print("ESP32 WT32 Touch panel");
  tft.setCursor(0, 35);
  if (!LittleFS.begin()) {
    Serial.println("LittleFS initialisation failed!");
    while (1) yield(); // Stay here waiting
  }
  drawControls(TFT_GREEN,TFT_WHITE);
}
//////////////////////////////////////////////////////// Loop
void loop()
{
    if (tft.getTouch(&x, &y) && millis() > keyStart + keyDelay) {
      getButton(x, y); // Evaluate press from menu file
      Serial.println(pressed);

        if (pressed == 11) {  //Button 11
          Serial.println(pressed);
          drawImage("/myimage.jpg");  // 320x320px
        }
        else if (pressed == 12) {  //Button 12
          Serial.println(pressed);
            tft.fillRect(0, 0, 320, 320, TFT_BLACK);
            tft.setFont(FSSB18);
            tft.setCursor(10,60);
            tft.println("FSS Bold 18");
          }      
        keyStart = millis();
  }
}

uint16_t getButton(int x, int y) {
//pressed=0;
for (k=0; k<30; k++) {
 if (x > Bx[k] && x < Bx[k]+80 && y > By[k] && y < By[k]+64 ) {  //Buttons
    Serial.print(Bx[k]);
    Serial.print("*");
    Serial.println(By[k]);
  pressed = k+1;
 }
}
  return pressed;
}

void drawImage(String image) {
  if (!LittleFS.begin()) {
    Serial.println("LittleFS initialisation failed!");
    while (1) yield(); 
  }
  int16_t x, y;
  tft.setSwapBytes(true); // swap the colour bytes (endianess)
  TJpgDec.setJpgScale(1);
  TJpgDec.setCallback(tft_output);
  uint16_t w = 0, h = 0;
  Serial.println(image);
  TJpgDec.getFsJpgSize(&w, &h, image.c_str(), LittleFS); // Note name preceded with "/"
  Serial.print("Width = "); Serial.print(w); Serial.print(", height = "); Serial.println(h);
  TJpgDec.drawFsJpg(0, 0, image, LittleFS);
}

void drawControls(uint16_t bgcolour, uint16_t textcolour) {   /// Rh Ten Menu buttons 
  tft.fillRect(0, 0, 320, 320, TFT_BLACK);
  tft.setTextColor(textcolour);
  tft.setFont(FSS9);
  for (int h : controlArray) {
    tft.drawRoundRect(Bx[h], By[h], 79, 63, 6, bgcolour);
    tft.setCursor(Bx[h]+8, By[h]+22);
    tft.print(controlLabel[i]);
    i++;
  }
}
