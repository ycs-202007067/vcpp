#include "yuhanCG.h"
#include <Windows.h>


void DrawBonobono1(HWND hwnd, HDC hdc, int blink) {
    HBRUSH hBrush = CreateSolidBrush(RGB(127, 200, 255));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 197, 130, 597, 530); // ���뺸�� ��

    hBrush = CreateSolidBrush(RGB(255, 150, 255));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 380, 360, 420, 440);// ��

    hBrush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 330, 340, 400, 395);// ���� ���

    hBrush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 400, 340, 470, 395);// ������ ���

    hBrush = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 375, 320, 425, 370);// ��

    hBrush = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 535, 290, 545, 310);// ������ ������

    hBrush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 536, 296, 543, 303);//������ ����

    hBrush = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 250, 290, 260, 310);//���� ������

    hBrush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 252, 296, 259, 303);//���� ����

    MoveToEx(hdc, 350, 360, NULL);
    LineTo(hdc, 300, 340);//���� �� ����

    MoveToEx(hdc, 350, 370, NULL);
    LineTo(hdc, 300, 390);//���� �Ʒ� ����

    MoveToEx(hdc, 450, 360, NULL);
    LineTo(hdc, 500, 340);//������ �� ����

    MoveToEx(hdc, 450, 370, NULL);
    LineTo(hdc, 500, 390);//������ �Ʒ� ����

}

void DrawBonobono2(HWND hwnd, HDC hdc, int blink) {
    HBRUSH hBrush = CreateSolidBrush(RGB(127, 200, 255));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 197, 130, 597, 530); // ���뺸�� ��

    hBrush = CreateSolidBrush(RGB(255, 150, 255));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 380, 360, 420, 440);// ��

    hBrush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 330, 340, 400, 395);// ���� ���

    hBrush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 400, 340, 470, 395);// ������ ���

    hBrush = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 375, 320, 425, 370);// ��

    MoveToEx(hdc, 275, 270, NULL);
    LineTo(hdc, 295, 285); //���� �� ��

    MoveToEx(hdc, 275, 300, NULL);
    LineTo(hdc, 295, 284); //���� �Ʒ� ��

    MoveToEx(hdc, 495, 285, NULL);
    LineTo(hdc, 520, 270); //������ �� ��

    MoveToEx(hdc, 495, 285, NULL);
    LineTo(hdc, 520, 300); //������ �Ʒ� ��

    MoveToEx(hdc, 350, 360, NULL);
    LineTo(hdc, 300, 340);//���� �� ����

    MoveToEx(hdc, 350, 370, NULL);
    LineTo(hdc, 300, 390);//���� �Ʒ� ����

    MoveToEx(hdc, 450, 360, NULL);
    LineTo(hdc, 500, 340);//������ �� ����

    MoveToEx(hdc, 450, 370, NULL);
    LineTo(hdc, 500, 390);//������ �Ʒ� ����
}


void DrawRyan(HWND hWnd, HDC hdc, int x, int y, int width, int height) {
    // ���̾��� �׸��� �ڵ� �ۼ�
    // �ʿ信 ���� �� �Լ��� ����

    HBRUSH hBrush = CreateSolidBrush(RGB(255, 200, 15));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, x + width * 0.18, y + height * 0.11, x + width * 0.31, y + height * 0.24); // ���� ��

    hBrush = CreateSolidBrush(RGB(255, 200, 15));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, x + width * 0.50, y + height * 0.11, x + width * 0.63, y + height * 0.24); // ������ ��

    hBrush = CreateSolidBrush(RGB(255, 200, 15));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, x + width * 0.197, y + height * 0.13, x + width * 0.597, y + height * 0.53); // ���̾� ��

    hBrush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, x + width * 0.33, y + height * 0.34, x + width * 0.40, y + height * 0.395); // ���� ���

    hBrush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, x + width * 0.40, y + height * 0.34, x + width * 0.47, y + height * 0.395); // ������ ���

    hBrush = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, x + width * 0.50, y + height * 0.28, x + width * 0.525, y + height * 0.30); // ������ ��

    MoveToEx(hdc, x + width * 0.25, y + height * 0.25, NULL);
    LineTo(hdc, x + width * 0.30, y + height * 0.25); // ������ ����

    hBrush = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, x + width * 0.27, y + height * 0.28, x + width * 0.295, y + height * 0.30); // ���� ��

    MoveToEx(hdc, x + width * 0.49, y + height * 0.25, NULL);
    LineTo(hdc, x + width * 0.54, y + height * 0.25); // ���� ����

    // �޸� ���� ������ ���� �귯�ø� �����մϴ�.
    DeleteObject(hBrush);
}

void DrawBox(HWND hWnd, HDC hdc, int startX, int startY, int width, int height) {
    // ������ ������ ����
    HPEN hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));  // ������ ��, �� ���� 1
    HGDIOBJ hOldPen = SelectObject(hdc, hPen);

    // ������� ä���� �簢�� �׸���
    HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255));  // ��� �귯��
    HGDIOBJ hOldBrush = SelectObject(hdc, hBrush);

    Rectangle(hdc, startX, startY, startX + width, startY + height);

    // ����� ��� �귯�� ����
    SelectObject(hdc, hOldPen);
    DeleteObject(hPen);
    SelectObject(hdc, hOldBrush);
    DeleteObject(hBrush);
}

void DrawCircle(HWND hWnd, HDC hdc, int startX, int startY, int width, int height) {
    // ���� �׸� �� ����� ��� �귯�� ����
    HPEN hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));  // ������ ��, �� ���� 1
    HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255));  // ��� �귯��

    // ��� �귯�ø� ����
    HGDIOBJ hOldPen = SelectObject(hdc, hPen);
    HGDIOBJ hOldBrush = SelectObject(hdc, hBrush);

    // ���� �׸�
    Ellipse(hdc, startX, startY, startX + width, startY + height);

    // ����� ��� �귯�� ����
    SelectObject(hdc, hOldPen);
    SelectObject(hdc, hOldBrush);
    DeleteObject(hPen);
    DeleteObject(hBrush);
}