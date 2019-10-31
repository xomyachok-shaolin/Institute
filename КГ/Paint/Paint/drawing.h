/* 2018 ReVoL Primer Template */
/* drawing.h */
#pragma once
/* установить значение 2 для геометрического пера */
#define MAX_PEN_TYPE 1
/* текущий инструмент */
TOOLS painting_tool = TOOL_MOUSE;
/* текущий цвет */
COLORREF fore_color = RGB(0, 0, 0);
/* текущий фон */
COLORREF back_color = RGB(255, 255, 255);
/* перо для плана */
HPEN PenFore = 0;
/* перо для фона */
HPEN PenBack = 0;
/* тип пера */
int pen_type = PS_COSMETIC;
/* тип линии тонкого косметического пера */
int line_style = PS_SOLID;
/* размер пера */
int pen_size = 1;
/* кисть геометрического пера */
LOGBRUSH PenBrush;
/* тип концевой точки */
int pen_endcap = PS_ENDCAP_FLAT;
/* тип соединения */
int pen_jointy = PS_JOIN_ROUND;
/* тип кисти пера */
int g_style = BS_SOLID;
/* тип штриховки пера */
int g_hatch = HS_CROSS;
/* признак полилинии */
int poly_left = 0, poly_right = 0;

/* вычисляет направление движения мыши */
void ShiftMouse(short X1, short Y1, short & X2, short & Y2) {
}

/* режим фона */
void SetBackStyle(COLORREF color) {
    if (backstyle_mode == 1) {
        /* режим фона прозрачный */
    } else {
        /* режим фона непрозрачный */
    }
}

/* событие WM_LBUTTONDOWN */
int LeftButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam) {
    return 0;
}

/* событие WM_RBUTTONDOWN */
int RightButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam) {
    return 0;
}

/* событие WM_LBUTTONUP */
int LeftButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam) {
    return 0;
}

/* событие WM_RBUTTONUP */
int RightButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam) {
    return 0;
}

/* создает новое перо плана или фона */
void CreateNewPen(HPEN & Pen, COLORREF color) {
    // создаем перо
    if (pen_type == PS_COSMETIC) {
        // косметическое перо
    } else {
        // геометрическое перо
    }
}

/* рисует линию */
void DrawMouse(short & X1, short & Y1, short X2, short Y2) {
}

/* рисует прямую */
void DrawLine(short X1, short Y1, short X2, short Y2) {
}

/* рисует прямоугольник */
void DrawRect(short X1, short Y1, short X2, short Y2) {
}

/* рисует овал */
void DrawOval(short X1, short Y1, short X2, short Y2) {
}

/* рисует прямую по алгоритму Брезенхейма */
void DrawBrez(short X1, short Y1, short X2, short Y2) {
}

/* рисует прямую по алгоритму Ву */
void DrawBWoo(short X1, short Y1, short X2, short Y2) {
}
