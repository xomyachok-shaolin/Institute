/* 2018 ReVoL Primer Template */
/* curves.cpp */
#include "curves.h"

// ������ �������
#define GX (double)100
#define GY (double)100
// ��� �� X
#define DX 1

// ������ ����-�� ������
int WX = -50, WY = 50;
// ������� ����
double SX = 0, SY = 0;
// ����� ������� ���������
double CX = 0, CY = 0;

/* ��������� ������ */
void setview() {
	RECT rc;
	GetClientRect(hWndGDE, &rc);
	WX = rc.right - rc.left;
	WY = rc.bottom - rc.top;
	// ����� ������� ���������
	CX = 0; CY = WY / 2;
	// ��������� �������
	// ��������� �������� ���. ������ � ��. ������� � �������� ����
	SX = GX / WX; SY = GY / WY;
}
/* ������������� ��� Y */
void pixel(HDC hdc, int X, int Y) {
	SetPixel(hdc, X, CY - Y, RGB(255, 0, 0));
}
/* ������������� ��� Y */
void moveTo(HDC hdc, int X, int Y) {
	MoveToEx(hdc, X, CY - Y, 0);
}
/* ������������� ��� Y */
void lineTo(HDC hdc, int X, int Y) {
	LineTo(hdc, X, CY - Y);
}
/* ������� ������� */
double funca(double x) {
	return sin(x);
}
/* ������� ������� */
double funcb(double x) {
	return x * x;
}
/* ������� ������� */
double funcc(double x) {
	return sqrt(x);
}
/* ������ ������ ������� */
void byPoints(HDC hdc) {
	double x, y;
	for (x = WX; x < WX; x++) {
		y = funcb(x * SX);
		pixel(hdc, x, y / SY);
	}
}
/* ������ ������ ������� */
void byLines(HDC hdc) {
	double x = 0, 
		   y = funcb(x);
	moveTo(hdc, x, y);

	for (x = DX; x < WX; x += DX) {
		y = funcb(x * SX);
		lineTo(hdc, x, y / SY);
	}
}
/* �������� ���������� GDC */
void draw() {
	setview();
	// ��� ���������
	MoveToEx(GDC, 0, CY, NULL);
	LineTo(GDC, WX, CY);
	MoveToEx(GDC, CX, 0, NULL);
	LineTo(GDC, CX, WY);

	byPoints(GDC);
	byLines(GDC);

}
