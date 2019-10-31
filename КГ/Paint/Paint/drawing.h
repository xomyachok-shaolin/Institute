/* 2018 ReVoL Primer Template */
/* drawing.h */
#pragma once
/* ���������� �������� 2 ��� ��������������� ���� */
#define MAX_PEN_TYPE 1
/* ������� ���������� */
TOOLS painting_tool = TOOL_MOUSE;
/* ������� ���� */
COLORREF fore_color = RGB(0, 0, 0);
/* ������� ��� */
COLORREF back_color = RGB(255, 255, 255);
/* ���� ��� ����� */
HPEN PenFore = 0;
/* ���� ��� ���� */
HPEN PenBack = 0;
/* ��� ���� */
int pen_type = PS_COSMETIC;
/* ��� ����� ������� �������������� ���� */
int line_style = PS_SOLID;
/* ������ ���� */
int pen_size = 1;
/* ����� ��������������� ���� */
LOGBRUSH PenBrush;
/* ��� �������� ����� */
int pen_endcap = PS_ENDCAP_FLAT;
/* ��� ���������� */
int pen_jointy = PS_JOIN_ROUND;
/* ��� ����� ���� */
int g_style = BS_SOLID;
/* ��� ��������� ���� */
int g_hatch = HS_CROSS;
/* ������� ��������� */
int poly_left = 0, poly_right = 0;

/* ��������� ����������� �������� ���� */
void ShiftMouse(short X1, short Y1, short & X2, short & Y2) {
}

/* ����� ���� */
void SetBackStyle(COLORREF color) {
    if (backstyle_mode == 1) {
        /* ����� ���� ���������� */
    } else {
        /* ����� ���� ������������ */
    }
}

/* ������� WM_LBUTTONDOWN */
int LeftButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam) {
    return 0;
}

/* ������� WM_RBUTTONDOWN */
int RightButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam) {
    return 0;
}

/* ������� WM_LBUTTONUP */
int LeftButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam) {
    return 0;
}

/* ������� WM_RBUTTONUP */
int RightButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam) {
    return 0;
}

/* ������� ����� ���� ����� ��� ���� */
void CreateNewPen(HPEN & Pen, COLORREF color) {
    // ������� ����
    if (pen_type == PS_COSMETIC) {
        // ������������� ����
    } else {
        // �������������� ����
    }
}

/* ������ ����� */
void DrawMouse(short & X1, short & Y1, short X2, short Y2) {
}

/* ������ ������ */
void DrawLine(short X1, short Y1, short X2, short Y2) {
}

/* ������ ������������� */
void DrawRect(short X1, short Y1, short X2, short Y2) {
}

/* ������ ���� */
void DrawOval(short X1, short Y1, short X2, short Y2) {
}

/* ������ ������ �� ��������� ����������� */
void DrawBrez(short X1, short Y1, short X2, short Y2) {
}

/* ������ ������ �� ��������� �� */
void DrawBWoo(short X1, short Y1, short X2, short Y2) {
}
