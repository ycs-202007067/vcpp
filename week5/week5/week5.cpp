#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif

#include <windows.h>
// 윈도우의 이벤트를 처리하는 콜백(Callback) 함수.

HINSTANCE hInst; // 응용 프로그램의 인스턴스 핸들을 저장
HWND hWnd; // 윈도우 창의 핸들
RECT drawingRect = { 0, 0, 0, 0 }; // 그려질 사각형의 위치 및 크기
RECT movingRect = { 0, 0, 0, 0 };  // 이동 가능한 사각형의 위치 및 크기
bool isDrawing = false; // 현재 그리기 모드인지 여부
bool isMoving = false; // 현재 이동 모드인지 여부
POINT startPoint; // 마우스 드래그를 시작한 지점의 좌표를 저장
POINT offset; // 이동 중인 사각형의 현재 위치와 이전 위치 간의 차이를 저장
// 전역 변수

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
// 윈도우 프로시저 함수
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) // 윈도우 이벤트를 처리
{
    switch (message)
    {
    case WM_PAINT: 
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        // 이전에 그려진 사각형을 지우기
        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

        // 그려진 사각형 그리기
        if (!isDrawing)
        {
            HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 255));
            FillRect(hdc, &drawingRect, hBrush);
            DeleteObject(hBrush);
        }

        EndPaint(hWnd, &ps);
        break;
    }
    case WM_LBUTTONDOWN: 
    {
        // 마우스 왼쪽 버튼 누를 때
        startPoint.x = LOWORD(lParam);
        startPoint.y = HIWORD(lParam);
        isDrawing = true;
        isMoving = false;
        break;
    }
    case WM_LBUTTONUP:
    {
        // 마우스 왼쪽 버튼 놓을 때
        if (isDrawing)
        {
            isDrawing = false;
            RECT rect;
            rect.left = startPoint.x;
            rect.top = startPoint.y;
            rect.right = LOWORD(lParam);
            rect.bottom = HIWORD(lParam);
            drawingRect = rect;
            InvalidateRect(hWnd, NULL, TRUE);
        }
        break;
    }
    case WM_RBUTTONDOWN:
    {
        // 마우스 오른쪽 버튼 누를 때
        startPoint.x = LOWORD(lParam);
        startPoint.y = HIWORD(lParam);
        if (PtInRect(&drawingRect, startPoint))
        {
            isMoving = true;
            offset.x = startPoint.x - drawingRect.left;
            offset.y = startPoint.y - drawingRect.top;
        }
        break;
    }
    case WM_RBUTTONUP:
    {
        // 마우스 오른쪽 버튼 놓을 때
        isMoving = false;
        break;
    }
    case WM_MOUSEMOVE:
    {
        // 마우스 이동 시
        if (isMoving)
        {
            int newX = LOWORD(lParam) - offset.x;
            int newY = HIWORD(lParam) - offset.y;
            RECT newRect;
            newRect.left = newX;
            newRect.top = newY;
            newRect.right = newX + (drawingRect.right - drawingRect.left);
            newRect.bottom = newY + (drawingRect.bottom - drawingRect.top);
            drawingRect = newRect;
            InvalidateRect(hWnd, NULL, TRUE);
        }
        break;
    }
    case WM_DESTROY:
    {
        PostQuitMessage(0);
        break;
    }
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return S_OK;
}
#ifdef UNICODE
int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
#else
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR pCmdLine, _In_ int nCmdShow)
#endif
{
    /* 윈도우 클래스 선언.*/
    WNDCLASS wc;
    ZeroMemory(&wc, sizeof(wc));   // 모두 0으로 초기화.

    // 윈도우 클래스 값 설정
    wc.hInstance = hInstance;
    wc.lpszClassName = TEXT("Computer Software");
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_CROSS);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WindowProc;

    // 윈도우 클래스 등록.
    if (RegisterClass(&wc) == 0)
    {
        MessageBox(NULL, L"RegisterClass failed!", L"Error", MB_ICONERROR);
        exit(-1);   //예외
    }

    // Window viewport 영역 조정
    RECT rect = { 150, 100, 800, 600 };
    AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, 0);
    int width = rect.right - rect.left;
    int height = rect.bottom - rect.top;

    // 윈도우 생성
    HWND hwnd = CreateWindow(
        wc.lpszClassName,
        TEXT("202007067 문현민"),
        WS_OVERLAPPEDWINDOW,
        0, 0,
        width, height,
        NULL, NULL,
        hInstance,
        NULL
    );

    // 오류 검사.
    if (hwnd == NULL)
    {
        MessageBox(NULL, L"CreateWindow failed!", L"Error", MB_ICONERROR);
        exit(-1);
    }

    // 창 보이기.
    ShowWindow(hwnd, SW_SHOW); // 창 띄우고
    UpdateWindow(hwnd); // 업데이트해야 보임. 한 쌍으로 쓴다고 보면 됨.



    // 메시지 처리 루프.
    MSG msg;
    ZeroMemory(&msg, sizeof(msg));

    while (msg.message != WM_QUIT)
    {
        // 메시지 처리.
        if (GetMessage(&msg, hwnd, 0, 0))
            //if (PeekMessage(&msg, hwnd, 0, 0, PM_REMOVE)) // PM_REMOVE의 자리는 이 메세지를 쓰고 어떡할거냐.의 의미인데 지운다는 것임.
        {

            // 메시지 해석해줘.
            TranslateMessage(&msg);
            // 메시지를 처리해야할 곳에 전달해줘.
            DispatchMessage(&msg);

        }
        /*else
        {

        }*/
    }

    //종료 메시지 보내기
    return (int)msg.wParam;
}