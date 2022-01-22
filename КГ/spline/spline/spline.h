// 2018 ReVoL Primer Template
// spline.h
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "targetver.h"
#include <windows.h>
#include <stdio.h>
#include <math.h>
#include "resource.h"
#include "settings.h"
#include "ccreate.h"
#define W0W 632
#define W0H 532
#define W1W 600
#define W1H 400
#define ULEFT 8
#define GLEFT 122
#define BTW 120
#define BTH 29
#define OPW 25
#define OPH 25
#define STEPL 16
#define STEPE 18
#define MAX_STRING 260
#define MAX_EDIT_BUFF 80
#define MAX_POINT 8
#define MAX_GRIP 10
#define GRIP_L 8
#define GRIP_R 9
#define GRIPW 13
#define GRIPH 6
#define S_LINES "16"
#define I_LINES  16
#define ID_EDITL 1103
char * snumbers[] = {"1", "2", "3", "4", "5", "6", "7", "8"};
char * splinesn[] = {"", "Непараметрический", "Параметрический", "Многосегментный", "Безье", "B-сплайн"};
// текущее количество линейных сегментов кривой
int s_lines = I_LINES;
int loaded = 0;
HINSTANCE hInst;
struct point { double x, y; };
void draw_nonparam(HDC, const int *, const int *, int);
void draw_param(HDC, const int *, const int *, int);
void draw_segment(HDC, int, int, int, int, double, double, double, double, double, int);
void draw_segments(HDC, int *, int *, int, int);
void draw_bezier(HDC, const int *, const int *, int, int);
void draw_bspline(HDC hdc, const int *, const int *, int, int, int);
double jnit(int, int, double);
double cni(int, int);
int fact[];
double nikt(int, int, double, int);
void build_knot(const int *, const int *, int, int, int *);
void solve_tgs(point *, point *, double *, int);
void DrawVectors(HDC, const int *, const int *, int);
void DrawVerect(HDC, const int *, const int *, int);
char szIniPath[MAX_STRING];
HWND W0, W1;
HWND WCS[6], WPN[8], WSP[8];
HWND hWndN, hWndP, hWndL, hWndMB;
HWND WGRIP[MAX_GRIP];
HFONT tahoma, smallf;
HDC CDC;
HBITMAP CBMP;
HPEN hPenTang;
HPEN hPenMain;
int MSX, MSY;
int GX[MAX_GRIP], GY[MAX_GRIP];
int p_number = 2;
int s_power = 3;
char buff[MAX_EDIT_BUFF];
void SetSpline(int index);
void SetNumber(int index);
void SetPower(int index);
int GetIntValueFromEdit(HWND);
void draw_view(HDC hdc);
void GripsGet(Settings, const char *);
void GripsPut(Settings, const char *);
void SplineParamsGet(int);
void SplineParamsPut(int);
void SettingsPath();
void GetSettings();
void PutSettings();
void set_current_mode();
enum spline_type {
    SPLINE_NS = 1,   // непараметрический
    SPLINE_PS,       // параметрический
    SPLINE_MS,       // многосегментный
    SPLINE_BZ,       // Безье
    SPLINE_BS        // B-сплайн
};
// текущий тип сплайновой кривой
spline_type current_spline = SPLINE_NS;
// рисует направляющие векторы
void DrawVectors(HDC hdc, const int * px, const int * py, int n) {
    SelectObject(hdc, (HGDIOBJ)hPenTang);
    MoveToEx(hdc, px[GRIP_L], py[GRIP_L], 0);
    LineTo(hdc, px[0], py[0]);
    MoveToEx(hdc, px[GRIP_R], py[GRIP_R], 0);
    LineTo(hdc, px[n], py[n]);
    SelectObject(hdc, (HGDIOBJ)hPenMain);
}
// рисует задающий многоугольник
void DrawVerect(HDC hdc, const int * px, const int * py, int N) {
    SelectObject(hdc, (HGDIOBJ)hPenTang);
    MoveToEx(hdc, px[0], py[0], 0);
    for (int i = 1; i < N; i++) {
        LineTo(hdc, px[i], py[i]);
    }
    SelectObject(hdc, (HGDIOBJ)hPenMain);
}
// решает тригональную систему уравнений методом прогонки
// K - дифференциалы
// B - коэффициенты (правые части)
// T - длины (хорды) сегментов
// n - размерность
void solve_tgs(point * K, point * B, double * T, int n) {
    int i, j;
    double D;
    double AA[MAX_POINT];
    point BB[MAX_POINT];
    for (i = 0; i <= n; i++) {
        AA[i] = 0.0;
    }
    // (c) 1999 Designed By ReVoL //
    // прямая прогонка
    BB[1] = K[0];
    for (i = 1, j = 2; i < n; i++, j++) {
        D = -AA[i] * T[j] - T[j] - T[j] - T[i] - T[i];
        AA[j] = T[i] / D;
        BB[j].x = (T[j] * BB[i].x - B[i].x) / D;
        BB[j].y = (T[j] * BB[i].y - B[i].y) / D;
    }
    // обратная прогонка
    for (i = n - 1, j = n; i > 0; i--, j--) {
        K[i].x = AA[j] * K[j].x + BB[j].x;
        K[i].y = AA[j] * K[j].y + BB[j].y;
    }
}
