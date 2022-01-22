// 2018 ReVoL Primer Template
// spline.cpp
#include "spline.h"
#include "1-nonpa.h"
#include "2-param.h"
#include "3-multis.h"
#include "4-bezier.h"
#include "5-bspline.h"
int GetIntValueFromEdit(HWND hwnd) {
    GetWindowText(hwnd, buff, MAX_EDIT_BUFF);
    if (strlen(buff) == 0) return 0;
    return atol(buff);
}
void draw_knot() {
    int i;
    char* p = buff;
    build_knot(GX, GY, p_number, s_power, V);
    for (i = 0; i < p_number + s_power; i++) p += sprintf(p, "%d", V[i]);
    SetWindowText(hWndMB, buff);
}
void set_current_mode() {
    int i, j;
    for (i = 0; i < MAX_GRIP; i++) ShowWindow(WGRIP[i], SW_HIDE);
    switch (current_spline) {
    case SPLINE_NS: case SPLINE_PS: case SPLINE_MS:
        ShowWindow(WGRIP[GRIP_L], SW_SHOW);
        ShowWindow(WGRIP[GRIP_R], SW_SHOW);
    }
    j = p_number;
    switch (current_spline) {
    case SPLINE_NS: case SPLINE_PS:
        j = 2;
    }
    for (i = 0; i < j; i++) ShowWindow(WGRIP[i], SW_SHOW);
    switch (current_spline) {
    case SPLINE_NS: case SPLINE_PS:
        for (i = 2; i < MAX_POINT; i++) EnableWindow(WPN[i], 0);
        for (i = 1; i < MAX_POINT; i++) EnableWindow(WSP[i], 0);
        SetWindowText(hWndMB, "");
        break;
    case SPLINE_MS: case SPLINE_BZ:
        EnableWindow(WPN[1], 0);
        for (i = 2; i < MAX_POINT; i++) EnableWindow(WPN[i], 1);
        for (i = 1; i < MAX_POINT; i++) EnableWindow(WSP[i], 0);
        SetWindowText(hWndMB, "");
        break;
    case SPLINE_BS:
        SetPower(s_power);
        for (i = 2; i < MAX_POINT; i++) EnableWindow(WPN[i], 1);
        for (i = 1; i < p_number; i++) EnableWindow(WSP[i], 1);
        for (i = p_number; i < MAX_POINT; i++) EnableWindow(WSP[i], 0);
    }
}
// рисует изображение на заданное устройство
// выводит узловой вектор для B-сплайна
void draw_view(HDC hdc) {
    if (loaded == 0) return;
    PatBlt(hdc, 0, 0, W1W - 2, W1H - 2, PATCOPY);
    switch (current_spline) {
    case SPLINE_NS:
        DrawVectors(hdc, GX, GY, 1);
        draw_nonparam(hdc, GX, GY, s_lines);
        break;
    case SPLINE_PS:
        DrawVectors(hdc, GX, GY, 1);
        draw_param(hdc, GX, GY, s_lines);
        break;
    case SPLINE_MS:
        DrawVectors(hdc, GX, GY, p_number - 1);
        draw_segments(hdc, GX, GY, p_number, s_lines);
        break;
    case SPLINE_BZ:
        DrawVerect(hdc, GX, GY, p_number);
        draw_bezier(hdc, GX, GY, p_number, s_lines);
        break;
    case SPLINE_BS:
        DrawVerect(hdc, GX, GY, p_number);
        draw_knot();
        draw_bspline(hdc, GX, GY, p_number, s_lines, s_power);
    }
}
void SettingsPath() {
    char path[MAX_STRING];
    GetWindowModuleFileName(W0, path, MAX_STRING);
    LPTSTR p = strrchr(path, 46);
    p[0] = 0;
    strcat(path, ".ini");
    int i, j;
    for (i = 0, j = 0; i < (int)strlen(path); i++) {
        if (path[i] == 92) szIniPath[j++] = path[i];
        szIniPath[j++] = path[i];
    }
    szIniPath[j] = 0;
}
void GetSettings() {
    Settings s;
    s.PutPath(szIniPath);
    SetSpline((int)s.GetSettingLong("spline", SPLINE_NS));
    SplineParamsGet((int)current_spline);
}
void PutSettings() {
    Settings s;
    s.PutPath(szIniPath);
    s.PutSettingLong((int)current_spline, "spline");
    SplineParamsPut((int)current_spline);
}
LRESULT CALLBACK GripProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    PAINTSTRUCT ps;
    HDC hdc;
    RECT rc, rm;
    POINT MP;
    static long down = 0;
    int X, Y;
    int index = GetWindowLong(hWnd, GWL_ID);
    switch (message) {
    case WM_LBUTTONDOWN:
        SetFocus(W0);
        GetWindowRect(hWnd, &rc);
        GetWindowRect(W1, &rm);
        GetCursorPos(&MP);
        MSX = MP.x - (rc.left - rm.left) + 1;
        MSY = MP.y - (rc.top - rm.top) + 1;
        down = (long)hWnd;
        BringWindowToTop(hWnd);
        InvalidateRect(hWnd, 0, 1);
        SetCapture(hWnd);
        return 0;
    case WM_MOUSEMOVE:
        if (down != (long)hWnd) {
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
        GetCursorPos(&MP);
        X = MP.x - MSX;
        Y = MP.y - MSY;
        MoveWindow(hWnd, X, Y, GRIPW, GRIPW, TRUE);
        GX[index] = X + GRIPH;
        GY[index] = Y + GRIPH;
        draw_view(CDC);
        InvalidateRect(W1, 0, 0);
        return 0;
    case WM_LBUTTONUP:
        ReleaseCapture();
        down = 0;
        return 0;
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        GetClientRect(hWnd, &rc);
        MoveToEx(hdc, rc.left, rc.top, 0);
        LineTo(hdc, rc.right - 1, rc.top);
        LineTo(hdc, rc.right - 1, rc.bottom - 1);
        LineTo(hdc, rc.left, rc.bottom - 1);
        LineTo(hdc, rc.left, rc.top);
        if (index < MAX_POINT) {
            sprintf(buff, "%d", index);
        } else {
            sprintf(buff, "·");
        }
        DrawText(hdc, buff, 1, &rc, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        EndPaint(hWnd, &ps);
        return 0;
    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}
LRESULT CALLBACK GDProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    PAINTSTRUCT ps;
    HDC hdc;
    int L, T, W, H;
    switch (message) {
    case WM_LBUTTONDOWN:
        SetFocus(W0);
        return 0;
    case WM_PAINT:
        draw_view(CDC);
        hdc = BeginPaint(hWnd, &ps);
        L = ps.rcPaint.left;
        T = ps.rcPaint.top;
        W = ps.rcPaint.right - L;
        H = ps.rcPaint.bottom - T;
        BitBlt(hdc, L, T, W, H, CDC, L, T, SRCCOPY);
        EndPaint(hWnd, &ps);
        return 0;
    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}
LRESULT CALLBACK CSProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    int wmIdent, wmEvent;
    switch (message) {
    case WM_COMMAND:
        wmIdent = LOWORD(wParam);
        wmEvent = HIWORD(wParam);
        switch (wmEvent) {
        case BN_CLICKED:
            switch (wmIdent) {
            case SPLINE_NS:
            case SPLINE_PS:
            case SPLINE_MS:
            case SPLINE_BZ:
            case SPLINE_BS:
                SplineParamsPut(current_spline);
                current_spline = spline_type(wmIdent);
                SplineParamsGet(current_spline);
                set_current_mode();
                InvalidateRect(W1, 0, 0);
                SetFocus(W0);
                return 0;
            }
            return 0;
        }
        break;
    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}
LRESULT CALLBACK PNProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    int wmIdent, wmEvent;
    switch (message) {
    case WM_COMMAND:
        wmIdent = LOWORD(wParam);
        wmEvent = HIWORD(wParam);
        switch (wmEvent) {
        case BN_CLICKED:
            p_number = wmIdent;
            set_current_mode();
            InvalidateRect(W1, 0, 0);
            SetFocus(W0);
            return 0;
        }
        break;
    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}
LRESULT CALLBACK SPProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    int wmIdent, wmEvent;
    switch (message) {
    case WM_COMMAND:
        wmIdent = LOWORD(wParam);
        wmEvent = HIWORD(wParam);
        switch (wmEvent) {
        case BN_CLICKED:
            s_power = wmIdent;
            set_current_mode();
            InvalidateRect(W1, 0, 0);
            SetFocus(W0);
            return 0;
        }
        break;
    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    int wmIdent, wmEvent;
    switch (message) {
    case WM_COMMAND:
        wmIdent = LOWORD(wParam);
        wmEvent = HIWORD(wParam);
        switch (wmIdent) {
        case ID_EDITL:
            switch (wmEvent) {
            case EN_CHANGE:
                s_lines = GetIntValueFromEdit(hWndL);
                set_current_mode();
                InvalidateRect(W1, 0, 0);
                return 0;
            }
            break;
        }
        break;
    case WM_DESTROY:
        DeleteObject(tahoma);
        DeleteObject(smallf);
        DeleteObject(hPenTang);
        DeleteObject(hPenMain);
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}
ATOM RegisterClasses(HINSTANCE hInstance) {
    WNDCLASSEX wcex;
    wcex.cbSize = sizeof(WNDCLASSEX); 
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = (WNDPROC)WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, (LPCTSTR)IDI_SPLINE);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW);
    wcex.lpszMenuName = 0;
    wcex.lpszClassName = "SPLINEAPP";
    wcex.hIconSm = LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);
    if (!RegisterClassEx(&wcex)) return 0;
    wcex.style          = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
    wcex.lpfnWndProc    = (WNDPROC)GripProc;
    wcex.hCursor        = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)CreateSolidBrush(RGB(255, 255, 160));
    wcex.lpszClassName  = "SPLINEGRIP";
    return RegisterClassEx(&wcex);
}
BOOL CreateTools(HWND W0, HINSTANCE hInst) {
    int i, ccy, ccx, ccw, W1T, L, T;
    HDC hdc;
    RECT rc;
    GetClientRect(W0, &rc);
    hPenTang = CreatePen(0, 0, RGB(192, 96, 48));
    hPenMain = CreatePen(0, 0, RGB(0, 0, 0));
    tahoma = CCreateFont(W0, "Tahoma", 8);
    smallf = CCreateFont(W0, "Small Fonts", 7);
    W1T = 16 + BTH + OPH;
    W1 = CCreatePaintBox(hInst, W0, ULEFT, W1T, W1W, W1H, GDProc);
    ccw = (BTW + BTW + BTW + BTW + BTW);
    WCS[0] = CCreateStatic(hInst, W0, ULEFT, 4, ccw, BTH, CSProc);
    ccx = 0; ccw = BTW; for (i = 1; i <= 5; i++) { WCS[i] = CCreateRadioPT(hInst, WCS[0], ccx, 0, BTW, BTH, i, tahoma, splinesn[i]); ccx += BTW; }
    ccy = 44; CCreateLabel(hInst, W0, ULEFT, ccy, 30, STEPL, tahoma, "Линий");
    hWndL = CCreateNumber3D(hInst, W0, 50, ccy - 2, 49, 18, ID_EDITL, tahoma);
    CCreateLabel(hInst, W0, 125, ccy, 30, STEPL, tahoma, "Точек");
    ccw = 7 * OPH; ccy = 10 + BTH;
    WPN[0] = CCreateStatic(hInst, W0, 166, ccy, ccw, OPH, PNProc);
    ccx = 0; for (i = 1; i <= 7; i++) { WPN[i] = CCreateRadioPT(hInst, WPN[0], ccx, 0, OPW, OPH, (i + 1), tahoma, snumbers[i]); ccx += OPH; }
    ccy = 44; CCreateLabel(hInst, W0, 377, ccy, 50, STEPL, tahoma, "Порядок");
    ccy = 10 + BTH; WSP[0] = CCreateStatic(hInst, W0, 433, ccy, ccw, OPH, SPProc);
    ccx = 0; for (i = 1; i <= 7; i++) { WSP[i] = CCreateRadioPT(hInst, WSP[0], ccx, 0, OPW, OPH, (i + 1), tahoma, snumbers[i]); ccx += OPH; }
    hWndMB = CCreateLabel(hInst, W0, ULEFT, W1T + W1H + 3, 120, STEPL, tahoma, "12345");
    for (i = 0; i < MAX_GRIP; i++) {
        L = GRIPW * (i + 1);
        T = GRIPW * (i + 1);
        WGRIP[i] = CreateWindow("SPLINEGRIP", 0, WS_CHILD, L, T, GRIPW, GRIPW, W1, (HMENU)i, hInst, 0);
        GX[i] = L + GRIPH;
        GY[i] = T + GRIPH;
        hdc = GetDC(WGRIP[i]);
        SelectObject(hdc, (HGDIOBJ)smallf);
        SetBkMode(hdc, TRANSPARENT);
        ReleaseDC(WGRIP[i], hdc);
    }
    return TRUE;
}
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow) {
    hInst = hInstance;
    int cx = (GetSystemMetrics(SM_CXSCREEN) - W0W) / 2;
    int cy = (GetSystemMetrics(SM_CYSCREEN) - W0H) / 2;
    W0 = CreateWindow("SPLINEAPP", "2018 ReVoL Primer Template", 0x80c80000, cx, cy, W0W, W0H, 0, 0, hInst, 0);
    if (!W0) return FALSE;
    ShowWindow(W0, nCmdShow);
    UpdateWindow(W0);
    HDC hdc = GetDC(W1);
    CDC = CreateCompatibleDC(hdc);
    CBMP = CreateCompatibleBitmap(hdc, W1W - 2, W1H - 2);
    SelectObject(CDC, CBMP);
    SelectObject(CDC, GetStockObject(WHITE_BRUSH));
    PatBlt(CDC, 0, 0, W1W - 2, W1H - 2, PATCOPY);
    ReleaseDC(W1, hdc);
    InvalidateRect(W1, 0, 1);
    return CreateTools(W0, hInst);
}
void SetSpline(int index) {
    if (index < 1) index = 1;
    if (index > 5) index = 5;
    current_spline = (spline_type)index;
    CheckRadioButton(WCS[0], 1, 8, index);
}
void SetNumber(int index) {
    if (index < 2) index = 2;
    if (index > MAX_POINT) index = MAX_POINT;
    switch (current_spline) {
    case SPLINE_NS:
    case SPLINE_PS:
        index = 2;
        break;
    }
    p_number = index;
    CheckRadioButton(WPN[0], 1, 8, index);
}
void SetPower(int index) {
    if (index < 2) index = 2;
    if (index > MAX_POINT) index = MAX_POINT;
    if (current_spline == SPLINE_PS || current_spline == SPLINE_NS) {
        index = 3;
    } else if (current_spline == SPLINE_MS) {
        index = 3;
    } else if (current_spline == SPLINE_BZ) {
        index = p_number - 1;
    } else if (current_spline == SPLINE_BS) {
        if (index > p_number) {
            index = p_number;
        }
    }
    s_power = index;
    CheckRadioButton(WSP[0], 1, 8, index);
}
void GripGet(Settings s, const char * name, int index, int x, int y) {
    sprintf(buff, "%sX%d", name, index);
    GX[index] = s.GetSettingLong(buff, x);
    sprintf(buff, "%sY%d", name, index);
    GY[index] = s.GetSettingLong(buff, y);
    if (GX[index] < GRIPH) {
        GX[index] = GRIPH;
    } else if (GX[index] > W1W - GRIPH) {
        GX[index] = W1W - GRIPH;
    }
    if (GY[index] < GRIPH) {
        GY[index] = GRIPH;
    } else if (GY[index] > W1H - GRIPH) {
        GY[index] = W1H - GRIPH;
    }
    MoveWindow(WGRIP[index], GX[index] - GRIPH, GY[index] - GRIPH, GRIPW, GRIPW, 0);
}
void GripsGet(Settings s, const char * name) {
    int i, gx = 30, gy = 20;
    GripGet(s, name, GRIP_L, gx, gy);
    gx += 30; gy += 20;
    for (i = 0; i <  MAX_GRIP; i++) {
        if (i == GRIP_L) continue;
        GripGet(s, name, i, gx, gy);
        gx += 30; gy += 20;
    }
}
void GripsPut(Settings s, const char * name) {
    for (int i = 0; i <  MAX_GRIP; i++) {
        sprintf(buff, "%sX%d", name, i);
        s.PutSettingLong(GX[i], buff);
        sprintf(buff, "%sY%d", name, i);
        s.PutSettingLong(GY[i], buff);
    }
}
void SplineParamsGet(int t) {
    int p;
    Settings s;
    s.PutPath(szIniPath);
    switch ((spline_type)t) {
    case SPLINE_NS:
    case SPLINE_PS:
        GripsGet(s, "GRIP1");
        s_lines = s.GetSettingLong("lines1", 16);
        SetNumber(2);
        SetPower(3);
        break;
    case SPLINE_MS:
        GripsGet(s, "GRIP3");
        s_lines = s.GetSettingLong("lines3", 24);
        SetNumber((int)s.GetSettingLong("points3", 4));
        SetPower(3);
        break;
    case SPLINE_BZ:
        GripsGet(s, "GRIP4");
        s_lines = s.GetSettingLong("lines5", 24);
        SetNumber((int)s.GetSettingLong("points4", 4));
        SetPower(p_number - 1);
        break;
    case SPLINE_BS:
        GripsGet(s, "GRIP4");
        s_lines = s.GetSettingLong("lines5", 48);
        SetNumber((int)s.GetSettingLong("points5", 6));
        p = (int)s.GetSettingLong("power5", 5);
        if (p > p_number) p = p_number;
        SetPower(p);
        break;
    }
    sprintf(buff, "%d", s_lines);
    SetWindowText(hWndL, buff);
}
void SplineParamsPut(int t) {
    Settings s;
    s.PutPath(szIniPath);
    switch ((spline_type)t) {
    case SPLINE_NS:
    case SPLINE_PS:
        s.PutSettingLong(s_lines, "lines1");
        GripsPut(s, "GRIP1");
        break;
    case SPLINE_MS:
        s.PutSettingLong(s_lines, "lines3");
        s.PutSettingLong(p_number, "points3");
        GripsPut(s, "GRIP3");
        break;
    case SPLINE_BZ:
        s.PutSettingLong(s_lines, "lines5");
        s.PutSettingLong(p_number, "points4");
        GripsPut(s, "GRIP4");
        break;
    case SPLINE_BS:
        s.PutSettingLong(s_lines, "lines5");
        s.PutSettingLong(p_number, "points5");
        s.PutSettingLong(s_power, "power5");
        GripsPut(s, "GRIP4");
        break;
    }
}
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    MSG msg;
    RegisterClasses(hInstance);
    if (!InitInstance(hInstance, nCmdShow)) return FALSE;
    SettingsPath();
    GetSettings();
    set_current_mode();
    loaded = 1;
    while (GetMessage(&msg, NULL, 0, 0)) {
        if (msg.message == WM_KEYDOWN) {
            if (msg.wParam == 27) {
                SendMessage(W0, WM_DESTROY, 0, 0);
            }
        }
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    PutSettings();
    DeleteObject(CBMP);
    DeleteDC(CDC);
    return (int)msg.wParam;
}
