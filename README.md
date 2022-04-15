# WT32 Touch Menu and Graphics
A demo example of cooperating touch recognition, JPG decoding and graphics handling for a [WT32-SC01](https://www.seeedstudio.com/ESP32-Development-board-WT32-SC01-p-4735.html) board .

In this prototype, the screen is considered as having 30 touch buttons that can be drawn and labelled in arrays.
These can be defined into menus.
Touch functions are interpreted in the loop.
TJpg_Decoder is used to load a JPG image from LittleFS.  In the example, a 320x320px image needs to be loaded into the sketch data folder.

![WT32Menu](https://user-images.githubusercontent.com/25142892/163530544-c7e3ad25-4935-453f-b895-454499eee3f1.png)


References and credits:
- lovyan03 (LovyanGFX) https://github.com/lovyan03
- TJpgDec http://elm-chan.org/fsw/tjpgd/00index.html
- Bodmer (TFT_eSPI) https://github.com/Bodmer
- 3D printed case https://sketchfab.com/3d-models/wt32-sc01-case-cfec05638de540b0acccff2091508500
