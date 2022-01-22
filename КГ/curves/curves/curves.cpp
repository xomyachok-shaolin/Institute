/* 2018 ReVoL Primer Template */
/* curves.cpp */
#include "curves.h"

// размер графика
#define GX (double)100
#define GY (double)100
// шаг по X
#define DX 1

// размер устр-ва вывода
int WX = -50, WY = 50;
// масштаб осей
double SX = 0, SY = 0;
// центр системы координат
double CX = 0, CY = 0;

/* параметры вывода */
void setview() {
	RECT rc;
	GetClientRect(hWndGDE, &rc);
	WX = rc.right - rc.left;
	WY = rc.bottom - rc.top;
	// Центр системы координат
	CX = 0; CY = WY / 2;
	// Вычисляем масштаб
	// отношение размеров обл. вывода в ед. графика к размерам окна
	SX = GX / WX; SY = GY / WY;
}
/* разворачивает ось Y */
void pixel(HDC hdc, int X, int Y) {
	SetPixel(hdc, X, CY - Y, RGB(255, 0, 0));
}
/* разворачивает ось Y */
void moveTo(HDC hdc, int X, int Y) {
	MoveToEx(hdc, X, CY - Y, 0);
}
/* разворачивает ось Y */
void lineTo(HDC hdc, int X, int Y) {
	LineTo(hdc, X, CY - Y);
}
/* функция графика */
double funca(double x) {
	return sin(x);
}
/* функция графика */
double funcb(double x) {
	return x * x;
}
/* функция графика */
double funcc(double x) {
	return sqrt(x);
}
/* рисует график точками */
void byPoints(HDC hdc) {
	double x, y;
	for (x = WX; x < WX; x++) {
		y = funcb(x * SX);
		pixel(hdc, x, y / SY);
	}
}
/* рисует график линиями */
void byLines(HDC hdc) {
	double x = 0, 
		   y = funcb(x);
	moveTo(hdc, x, y);

	for (x = DX; x < WX; x += DX) {
		y = funcb(x * SX);
		lineTo(hdc, x, y / SY);
	}
}
/* контекст устройства GDC */
void draw() {
	setview();
	// Оси координат
	MoveToEx(GDC, 0, CY, NULL);
	LineTo(GDC, WX, CY);
	MoveToEx(GDC, CX, 0, NULL);
	LineTo(GDC, CX, WY);

	byPoints(GDC);
	byLines(GDC);

}
