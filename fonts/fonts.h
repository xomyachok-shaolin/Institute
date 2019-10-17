// 2018 ReVoL Primer Template
// fonts.h
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN
#include "targetver.h"
#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "resource.h"

#include <commdlg.h>

#define MF_W 720
#define MF_H 520
int gde_w = 0, gde_h = 0;
HINSTANCE hInst;
HWND hWndMain;
HWND hWndOut;
HDC hDCMain;
HDC GDC;
HDC CDC;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    int wmIdent, wmEvent;
    switch (message) {
    case WM_COMMAND:
        wmIdent = LOWORD(wParam);
        wmEvent = HIWORD(wParam);
        switch (wmIdent) {
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
LRESULT CALLBACK OutProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    PAINTSTRUCT ps;
    HDC hdc;
    switch (message) {
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        BitBlt(hdc, 0, 0, gde_w, gde_h, CDC, 0, 0, SRCCOPY);
        EndPaint(hWnd, &ps);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
ATOM RegisterClasses(HINSTANCE hInstance) {
    WNDCLASSEX wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_FONTS));
    wcex.hCursor        = LoadCursor(0, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCE(IDC_FONTS);
    wcex.lpszClassName  = "FONTSAPP";
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
    if (!RegisterClassEx(&wcex)) return 0;
    wcex.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
    wcex.lpfnWndProc = (WNDPROC)OutProc;
    wcex.hIcon = 0;
    wcex.hCursor = LoadCursor(0, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(GetStockObject(WHITE_BRUSH));
    wcex.lpszMenuName = 0;
    wcex.lpszClassName = "FONTSOUT";
    wcex.hIconSm = 0;
    return RegisterClassEx(&wcex);
}
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow) {
    int SW = GetSystemMetrics(SM_CXSCREEN);
    int SH = GetSystemMetrics(SM_CYSCREEN);
    int cx = (SW - MF_W) / 2;
    int cy = (SH - MF_H) / 2;
    RECT rc;
    hInst = hInstance;
    hWndMain = CreateWindow("FONTSAPP", "Fonts Primer App", 0x80c80000, cx, cy, MF_W, MF_H, 0, 0, hInstance, 0);
    if (!hWndMain) return FALSE;
    hDCMain = GetDC(hWndMain);
    GetClientRect(hWndMain, &rc);
    gde_w = rc.right - 2;
    gde_h = rc.bottom - 2;
	hWndOut = CreateWindow("FONTSOUT", 0, 0x50810000, 1, 1, gde_w, gde_h, hWndMain, 0, hInst, 0);
    GDC = GetDC(hWndOut);
    CDC = CreateCompatibleDC(GDC);
    HBITMAP CBMP = CreateCompatibleBitmap(GDC, gde_w, gde_h);
    SelectObject(CDC, (HGDIOBJ)CBMP);
    SelectObject(CDC, (HGDIOBJ)GetStockObject(WHITE_BRUSH));
    PatBlt(CDC, 0, 0, gde_w, gde_h, PATCOPY);
    ShowWindow(hWndMain, nCmdShow);
    UpdateWindow(hWndMain);
    return TRUE;
}
void fonts(void);
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow) {
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
    RegisterClasses(hInstance);
    if (!InitInstance(hInstance, nCmdShow)) {
        return FALSE;
    }
    fonts();
    MSG msg;
    while (GetMessage(&msg, 0, 0, 0)) {
        if (msg.message == WM_KEYDOWN && msg.wParam == 27) {
            SendMessage(hWndMain, WM_DESTROY, 0, 0);
        }
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (int)msg.wParam;
}
