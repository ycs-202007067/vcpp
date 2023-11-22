#include "yuhanCG.h"
#include <Windows.h>


void DrawBonobono1(HWND hwnd, HDC hdc, int blink) {
    HBRUSH hBrush = CreateSolidBrush(RGB(127, 200, 255));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 197, 130, 597, 530); // 보노보노 얼굴

    hBrush = CreateSolidBrush(RGB(255, 150, 255));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 380, 360, 420, 440);// 혀

    hBrush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 330, 340, 400, 395);// 왼쪽 흰색

    hBrush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 400, 340, 470, 395);// 오른쪽 흰색

    hBrush = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 375, 320, 425, 370);// 코

    hBrush = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 535, 290, 545, 310);// 오른쪽 검은자

    hBrush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 536, 296, 543, 303);//오른쪽 흰자

    hBrush = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 250, 290, 260, 310);//왼쪽 검은자

    hBrush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 252, 296, 259, 303);//왼쪽 흰자

    MoveToEx(hdc, 350, 360, NULL);
    LineTo(hdc, 300, 340);//왼쪽 위 수염

    MoveToEx(hdc, 350, 370, NULL);
    LineTo(hdc, 300, 390);//왼쪽 아래 수염

    MoveToEx(hdc, 450, 360, NULL);
    LineTo(hdc, 500, 340);//오른쪽 위 수염

    MoveToEx(hdc, 450, 370, NULL);
    LineTo(hdc, 500, 390);//오른쪽 아래 수염

}

void DrawBonobono2(HWND hwnd, HDC hdc, int blink) {
    HBRUSH hBrush = CreateSolidBrush(RGB(127, 200, 255));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 197, 130, 597, 530); // 보노보노 얼굴

    hBrush = CreateSolidBrush(RGB(255, 150, 255));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 380, 360, 420, 440);// 혀

    hBrush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 330, 340, 400, 395);// 왼쪽 흰색

    hBrush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 400, 340, 470, 395);// 오른쪽 흰색

    hBrush = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 375, 320, 425, 370);// 코

    MoveToEx(hdc, 275, 270, NULL);
    LineTo(hdc, 295, 285); //왼쪽 윗 눈

    MoveToEx(hdc, 275, 300, NULL);
    LineTo(hdc, 295, 284); //왼쪽 아랫 눈

    MoveToEx(hdc, 495, 285, NULL);
    LineTo(hdc, 520, 270); //오른쪽 윗 눈

    MoveToEx(hdc, 495, 285, NULL);
    LineTo(hdc, 520, 300); //오른쪽 아랫 눈

    MoveToEx(hdc, 350, 360, NULL);
    LineTo(hdc, 300, 340);//왼쪽 위 수염

    MoveToEx(hdc, 350, 370, NULL);
    LineTo(hdc, 300, 390);//왼쪽 아래 수염

    MoveToEx(hdc, 450, 360, NULL);
    LineTo(hdc, 500, 340);//오른쪽 위 수염

    MoveToEx(hdc, 450, 370, NULL);
    LineTo(hdc, 500, 390);//오른쪽 아래 수염
}


void DrawRyan(HWND hWnd, HDC hdc, int x, int y, int width, int height) {
    // 라이언을 그리는 코드 작성
    // 필요에 따라 이 함수를 구현

    HBRUSH hBrush = CreateSolidBrush(RGB(255, 200, 15));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, x + width * 0.18, y + height * 0.11, x + width * 0.31, y + height * 0.24); // 왼쪽 귀

    hBrush = CreateSolidBrush(RGB(255, 200, 15));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, x + width * 0.50, y + height * 0.11, x + width * 0.63, y + height * 0.24); // 오른쪽 귀

    hBrush = CreateSolidBrush(RGB(255, 200, 15));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, x + width * 0.197, y + height * 0.13, x + width * 0.597, y + height * 0.53); // 라이언 얼굴

    hBrush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, x + width * 0.33, y + height * 0.34, x + width * 0.40, y + height * 0.395); // 왼쪽 흰색

    hBrush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, x + width * 0.40, y + height * 0.34, x + width * 0.47, y + height * 0.395); // 오른쪽 흰색

    hBrush = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, x + width * 0.50, y + height * 0.28, x + width * 0.525, y + height * 0.30); // 오른쪽 눈

    MoveToEx(hdc, x + width * 0.25, y + height * 0.25, NULL);
    LineTo(hdc, x + width * 0.30, y + height * 0.25); // 오른쪽 눈썹

    hBrush = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, x + width * 0.27, y + height * 0.28, x + width * 0.295, y + height * 0.30); // 왼쪽 눈

    MoveToEx(hdc, x + width * 0.49, y + height * 0.25, NULL);
    LineTo(hdc, x + width * 0.54, y + height * 0.25); // 왼쪽 눈썹

    // 메모리 누수 방지를 위해 브러시를 삭제합니다.
    DeleteObject(hBrush);
}

void DrawBox(HWND hWnd, HDC hdc, int startX, int startY, int width, int height) {
    // 검정색 펜으로 설정
    HPEN hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));  // 검정색 펜, 선 굵기 1
    HGDIOBJ hOldPen = SelectObject(hdc, hPen);

    // 흰색으로 채워진 사각형 그리기
    HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255));  // 흰색 브러시
    HGDIOBJ hOldBrush = SelectObject(hdc, hBrush);

    Rectangle(hdc, startX, startY, startX + width, startY + height);

    // 사용한 펜과 브러시 해제
    SelectObject(hdc, hOldPen);
    DeleteObject(hPen);
    SelectObject(hdc, hOldBrush);
    DeleteObject(hBrush);
}

void DrawCircle(HWND hWnd, HDC hdc, int startX, int startY, int width, int height) {
    // 원을 그릴 때 사용할 펜과 브러시 설정
    HPEN hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));  // 검정색 펜, 선 굵기 1
    HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255));  // 흰색 브러시

    // 펜과 브러시를 선택
    HGDIOBJ hOldPen = SelectObject(hdc, hPen);
    HGDIOBJ hOldBrush = SelectObject(hdc, hBrush);

    // 원을 그림
    Ellipse(hdc, startX, startY, startX + width, startY + height);

    // 사용한 펜과 브러시 해제
    SelectObject(hdc, hOldPen);
    SelectObject(hdc, hOldBrush);
    DeleteObject(hPen);
    DeleteObject(hBrush);
}