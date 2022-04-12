# WT32 Touch Menu and Graphics
A demo example of cooperating touch recognition, JPG decoding and graphics handling for a [WT32-SC01](https://www.seeedstudio.com/ESP32-Development-board-WT32-SC01-p-4735.html) board .

In this prototype, the screen is considered as having 30 touch buttons that can be drawn and labelled in arrays.
These can be defined into menus.
Touch functions are interpreted in the loop.
TJpg_Decoder is used to load a JPG image from LittleFS.  In the example, a 320x320px image needs to be loaded into the sketch data folder.


![IMG_4515](https://github.com/cobungra/WCT32-Touch-Example/blob/main/WT32Menu.jpg)


References and credits: 
    Bodmer (TFT_eSPI) https://github.com/Bodmer
    lovyan03 (LovyanGFX) https://github.com/lovyan03
    TJpgDec http://elm-chan.org/fsw/tjpgd/00index.html
