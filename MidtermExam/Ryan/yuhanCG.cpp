#include "yuhanCG.h"
#include <Windows.h>;


void DrawBonobono1(HWND hwnd, HDC hdc, int blink) {
        HBRUSH hBrush = CreateSolidBrush(RGB(127, 200, 255));
        SelectObject(hdc, hBrush);
        Ellipse(hdc, 197, 130, 597, 530); // º¸³ëº¸³ë ¾ó±¼

        hBrush = CreateSolidBrush(RGB(255, 150, 255));
        SelectObject(hdc, hBrush);
        Ellipse(hdc, 380, 360, 420, 440);// Çô

        hBrush = CreateSolidBrush(RGB(255, 255, 255));
        SelectObject(hdc, hBrush);
        Ellipse(hdc, 330, 340, 400, 395);// ¿ÞÂÊ Èò»ö

        hBrush = CreateSolidBrush(RGB(255, 255, 255));
        SelectObject(hdc, hBrush);
        Ellipse(hdc, 400, 340, 470, 395);// ¿À¸¥ÂÊ Èò»ö

        hBrush = CreateSolidBrush(RGB(0, 0, 0));
        SelectObject(hdc, hBrush);
        Ellipse(hdc, 375, 320, 425, 370);// ÄÚ

        hBrush = CreateSolidBrush(RGB(0, 0, 0));
        SelectObject(hdc, hBrush);
        Ellipse(hdc, 535, 290, 545, 310);// ¿À¸¥ÂÊ °ËÀºÀÚ

        hBrush = CreateSolidBrush(RGB(255, 255, 255));
        SelectObject(hdc, hBrush);
        Ellipse(hdc, 536, 296, 543, 303);//¿À¸¥ÂÊ ÈòÀÚ

        hBrush = CreateSolidBrush(RGB(0, 0, 0));
        SelectObject(hdc, hBrush);
        Ellipse(hdc, 250, 290, 260, 310);//¿ÞÂÊ °ËÀºÀÚ

        hBrush = CreateSolidBrush(RGB(255, 255, 255));
        SelectObject(hdc, hBrush);
        Ellipse(hdc, 252, 296, 259, 303);//¿ÞÂÊ ÈòÀÚ

        MoveToEx(hdc, 350, 360, NULL);
        LineTo(hdc, 300, 340);//¿ÞÂÊ À§ ¼ö¿°

        MoveToEx(hdc, 350, 370, NULL);
        LineTo(hdc, 300, 390);//¿ÞÂÊ ¾Æ·¡ ¼ö¿°

        MoveToEx(hdc, 450, 360, NULL);
        LineTo(hdc, 500, 340);//¿À¸¥ÂÊ À§ ¼ö¿°

        MoveToEx(hdc, 450, 370, NULL);
        LineTo(hdc, 500, 390);//¿À¸¥ÂÊ ¾Æ·¡ ¼ö¿°

    }

void DrawBonobono2(HWND hwnd, HDC hdc, int blink) {
        HBRUSH hBrush = CreateSolidBrush(RGB(127, 200, 255));
        SelectObject(hdc, hBrush);
        Ellipse(hdc, 197, 130, 597, 530); // º¸³ëº¸³ë ¾ó±¼

        hBrush = CreateSolidBrush(RGB(255, 150, 255));
        SelectObject(hdc, hBrush);
        Ellipse(hdc, 380, 360, 420, 440);// Çô

        hBrush = CreateSolidBrush(RGB(255, 255, 255));
        SelectObject(hdc, hBrush);
        Ellipse(hdc, 330, 340, 400, 395);// ¿ÞÂÊ Èò»ö

        hBrush = CreateSolidBrush(RGB(255, 255, 255));
        SelectObject(hdc, hBrush);
        Ellipse(hdc, 400, 340, 470, 395);// ¿À¸¥ÂÊ Èò»ö

        hBrush = CreateSolidBrush(RGB(0, 0, 0));
        SelectObject(hdc, hBrush);
        Ellipse(hdc, 375, 320, 425, 370);// ÄÚ

        MoveToEx(hdc, 275, 270, NULL);
        LineTo(hdc, 295, 285); //¿ÞÂÊ À­ ´«

        MoveToEx(hdc, 275, 300, NULL);
        LineTo(hdc, 295, 284); //¿ÞÂÊ ¾Æ·§ ´«

        MoveToEx(hdc, 495, 285, NULL);
        LineTo(hdc, 520, 270); //¿À¸¥ÂÊ À­ ´«

        MoveToEx(hdc, 495, 285, NULL);
        LineTo(hdc, 520, 300); //¿À¸¥ÂÊ ¾Æ·§ ´«

        MoveToEx(hdc, 350, 360, NULL);
        LineTo(hdc, 300, 340);//¿ÞÂÊ À§ ¼ö¿°

        MoveToEx(hdc, 350, 370, NULL);
        LineTo(hdc, 300, 390);//¿ÞÂÊ ¾Æ·¡ ¼ö¿°

        MoveToEx(hdc, 450, 360, NULL);
        LineTo(hdc, 500, 340);//¿À¸¥ÂÊ À§ ¼ö¿°

        MoveToEx(hdc, 450, 370, NULL);
        LineTo(hdc, 500, 390);//¿À¸¥ÂÊ ¾Æ·¡ ¼ö¿°
    }


void DrawRyan(HWND hWnd, HDC hdc, int x, int y, int width, int height) {
    // ¶óÀÌ¾ðÀ» ±×¸®´Â ÄÚµå ÀÛ¼º
    // ÇÊ¿ä¿¡ µû¶ó ÀÌ ÇÔ¼ö¸¦ ±¸Çö

    HBRUSH hBrush = CreateSolidBrush(RGB(255, 200, 15));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, x + width * 0.18, y + height * 0.11, x + width * 0.31, y + height * 0.24); // ¿ÞÂÊ ±Í

    hBrush = CreateSolidBrush(RGB(255, 200, 15));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, x + width * 0.50, y + height * 0.11, x + width * 0.63, y + height * 0.24); // ¿À¸¥ÂÊ ±Í

    hBrush = CreateSolidBrush(RGB(255, 200, 15));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, x + width * 0.197, y + height * 0.13, x + width * 0.597, y + height * 0.53); // ¶óÀÌ¾ð ¾ó±¼

    hBrush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, x + width * 0.33, y + height * 0.34, x + width * 0.40, y + height * 0.395); // ¿ÞÂÊ Èò»ö

    hBrush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, x + width * 0.40, y + height * 0.34, x + width * 0.47, y + height * 0.395); // ¿À¸¥ÂÊ Èò»ö

    hBrush = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, x + width * 0.50, y + height * 0.28, x + width * 0.525, y + height * 0.30); // ¿À¸¥ÂÊ ´«

    MoveToEx(hdc, x + width * 0.25, y + height * 0.25, NULL);
    LineTo(hdc, x + width * 0.30, y + height * 0.25); // ¿À¸¥ÂÊ ´«½ç

    hBrush = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, x + width * 0.27, y + height * 0.28, x + width * 0.295, y + height * 0.30); // ¿ÞÂÊ ´«

    MoveToEx(hdc, x + width * 0.49, y + height * 0.25, NULL);
    LineTo(hdc, x + width * 0.54, y + height * 0.25); // ¿ÞÂÊ ´«½ç

    // ¸Þ¸ð¸® ´©¼ö ¹æÁö¸¦ À§ÇØ ºê·¯½Ã¸¦ »èÁ¦ÇÕ´Ï´Ù.
    DeleteObject(hBrush);
}
