#include <Windows.h>
#include "yuhanCG.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

HWND hBox2, hBoxButton, hCircleButton, hBonobonoButton, hRyanButton, hCubeButton;
BOOL isMouseDragging = FALSE;
BOOL isMouseOverBox2 = FALSE;
BOOL isDrawingBox = FALSE;
BOOL defaultBonobono = FALSE;
BOOL spaceBonobono = FALSE;
BOOL isSpacePressed = FALSE;
BOOL isRyanMode = FALSE;
int startX, startY, endX, endY;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASSEX wc = { 0 };
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = L"BasicWindowClass";

    RegisterClassEx(&wc);

    HWND hwnd = CreateWindow(L"BasicWindowClass", L"202007067 문현민", WS_OVERLAPPEDWINDOW, 100, 100, 800, 600, NULL, NULL, hInstance, NULL);

    if (hwnd == NULL) {
        MessageBox(NULL, L"윈도우를 생성하는 데 실패했습니다.", L"에러", MB_ICONERROR);
        return 1;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    hBoxButton = CreateWindow(
        L"BUTTON", L"Box", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        20, 20, 138, 64, hwnd, (HMENU)1, hInstance, NULL);

    hCircleButton = CreateWindow(
        L"BUTTON", L"Circle", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        20 + 138 + 16, 20, 138, 64, hwnd, (HMENU)2, hInstance, NULL);

    hBonobonoButton = CreateWindow(
        L"BUTTON", L"Bonobono", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        20 + 2 * (138 + 16), 20, 138, 64, hwnd, (HMENU)3, hInstance, NULL);

    hRyanButton = CreateWindow(
        L"BUTTON", L"Ryan", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        20 + 3 * (138 + 16), 20, 138, 64, hwnd, (HMENU)4, hInstance, NULL);

    hCubeButton = CreateWindow(
        L"BUTTON", L"Cube", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        20 + 4 * (138 + 16), 20, 138, 64, hwnd, (HMENU)5, hInstance, NULL);

    hBox2 = CreateWindow(
        L"STATIC", L"Box2", WS_CHILD | WS_VISIBLE | SS_SUNKEN | SS_BLACKFRAME,
        20, 20 + 64 + 20, 800 - 2 * 20, 450, hwnd, (HMENU)1002, NULL, NULL);

    HBRUSH hBox2Brush = CreateSolidBrush(RGB(255, 255, 255));
    // hBox2의 배경색을 설정할 때 사용한 SendMessage 함수를 아래와 같이 변경
    SendMessage(hBox2, WM_CTLCOLORSTATIC, (WPARAM)GetDC(hBox2), (LPARAM)hBox2Brush);

    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

#include "yuhanCG.h"
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    HDC hdc;
    PAINTSTRUCT ps;

    switch (msg) {
    case WM_CREATE: {
        HBRUSH hBrush = CreateSolidBrush(RGB(255, 240, 220));
        SetClassLongPtr(hwnd, GCLP_HBRBACKGROUND, (LONG_PTR)hBrush);

        HWND box1 = CreateWindow(L"STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_BLACKFRAME, 8, 8, 800 - 2 * 8, 600 - 2 * 8, hwnd, (HMENU)1001, NULL, NULL);
        SetClassLongPtr(box1, GCLP_HBRBACKGROUND, (LONG_PTR)hBrush);
        break;
    }

    case WM_MOUSEMOVE: {
        // 마우스 이동 이벤트를 처리하여 드로잉영역 내부에 마우스가 있는지 확인
        POINT pt;
        GetCursorPos(&pt);
        ScreenToClient(hwnd, &pt);

        // 드로잉영역의 좌표와 크기를 가져옵니다.
        RECT box2Rect;
        GetWindowRect(hBox2, &box2Rect);
        MapWindowPoints(HWND_DESKTOP, hwnd, (LPPOINT)&box2Rect, 2);

        if (PtInRect(&box2Rect, pt)) {
            // 드로잉영역 내부에 마우스가 있을 때 커서를 십자 모양으로 변경
            if (!isMouseOverBox2) {
                isMouseOverBox2 = TRUE;
                SetCursor(LoadCursor(NULL, IDC_CROSS));
            }

            if (isMouseDragging) {
                endX = LOWORD(lParam);
                endY = HIWORD(lParam);
                // 화면을 갱신하여 드래그 중인 사각형을 그립니다.
                InvalidateRect(hwnd, NULL, TRUE);
            }
        }
        else {
            // 드로잉영역에서 마우스가 벗어났을 때 원래 커서로 변경
            if (isMouseOverBox2) {
                isMouseOverBox2 = FALSE;
                SetCursor(LoadCursor(NULL, IDC_ARROW));
            }
        }
        return 0;
    }

    case WM_LBUTTONDOWN: {
        if (isDrawingBox || isRyanMode) {
            startX = LOWORD(lParam);
            startY = HIWORD(lParam);
            endX = startX;
            endY = startY;
            isMouseDragging = TRUE;
            SetCapture(hwnd);
        }
        return 0;
    }

    case WM_LBUTTONUP: {
        if (isMouseDragging) {
            isMouseDragging = FALSE;
            ReleaseCapture();

            if (isRyanMode) {
                int width = abs(endX - startX);
                int height = abs(endY - startY);
                int x = min(startX, endX);
                int y = min(startY, endY);

                HDC hdc = GetDC(hwnd);
                DrawRyan(hwnd, hdc, x, y, width, height);
                ReleaseDC(hwnd, hdc);
            }
        }
        return 0;
    }



    case WM_KEYDOWN: {
        if (wParam == VK_SPACE) {
            isSpacePressed = TRUE;
            if (defaultBonobono) {
                if (isDrawingBox) {
                    defaultBonobono = FALSE;
                    spaceBonobono = FALSE;
                }
                else {
                    defaultBonobono = !isSpacePressed;
                    spaceBonobono = isSpacePressed;
                }
                InvalidateRect(hwnd, NULL, TRUE);
            }
        }
        return 0;
    }

    case WM_KEYUP: {
        if (wParam == VK_SPACE) {
            isSpacePressed = FALSE;
            if (spaceBonobono) {
                if (!isDrawingBox) {
                    defaultBonobono = !isSpacePressed;
                    spaceBonobono = isSpacePressed;
                    InvalidateRect(hwnd, NULL, TRUE);
                }
            }
        }
        return 0;
    }

    case WM_COMMAND: {
        switch (LOWORD(wParam)) {
        case 1: // "Box" 버튼의 ID
            isDrawingBox = TRUE; // "Box" 버튼을 눌렀을 때 도형을 그릴 수 있도록 상태 변경
            defaultBonobono = FALSE;
            spaceBonobono = FALSE;
            isRyanMode = FALSE;
            SetFocus(hwnd);
            InvalidateRect(hwnd, NULL, TRUE); // 화면 갱신
            break;
        case 2: // "Circle" 버튼의 ID
            isDrawingBox = FALSE;
            defaultBonobono = FALSE; // Bonobono 이미지를 그리지 않도록 설정
            spaceBonobono = FALSE;
            isRyanMode = FALSE;
            SetFocus(hwnd);
            InvalidateRect(hwnd, NULL, TRUE); // 화면 갱신
            // 다른 버튼 처리
            break;
        case 3: // "Bonobono" 버튼의 ID
            isDrawingBox = FALSE; // 다른 버튼을 눌렀을 때 도형을 그릴 수 없도록 상태 변경
            if (isSpacePressed) {
                defaultBonobono = FALSE;
                spaceBonobono = TRUE;
            }
            else {
                defaultBonobono = TRUE;
                spaceBonobono = FALSE;
            }
            isRyanMode = FALSE;
            SetFocus(hwnd);
            InvalidateRect(hwnd, NULL, TRUE); // 화면 갱신
            break;
        case 4: // "Ryan" 버튼의 ID
            isDrawingBox = FALSE;
            defaultBonobono = FALSE; // Bonobono 이미지를 그리지 않도록 설정
            spaceBonobono = FALSE;
            isRyanMode = TRUE;
            SetFocus(hwnd);
            InvalidateRect(hwnd, NULL, TRUE); // 화면 갱신
            // 다른 버튼 처리
            break;
        case 5: // "Cube" 버튼의 ID
            isDrawingBox = FALSE;
            defaultBonobono = FALSE; // Bonobono 이미지를 그리지 않도록 설정
            spaceBonobono = FALSE;
            isRyanMode = FALSE;
            SetFocus(hwnd);
            InvalidateRect(hwnd, NULL, TRUE); // 화면 갱신
            // 다른 버튼 처리
            break;
        }
        return 0;
    }

    case WM_PAINT: {
        PAINTSTRUCT ps;
        hdc = BeginPaint(hwnd, &ps);
        if (defaultBonobono) {
            DrawBonobono1(hwnd, hdc, 1);
        }
        else if (spaceBonobono) {
            DrawBonobono2(hwnd, hdc, 1);
        }
        EndPaint(hwnd, &ps);
        return 0;
    }

    case WM_DESTROY: {
        PostQuitMessage(0);
        break;
    }

    default: {
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
           return 0;
    }
}