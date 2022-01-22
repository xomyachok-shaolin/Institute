// 2018 ReVoL Primer Template
// bmap.cpp
#include "bmap.h"
// путь к файлу BMP
#define PATH "ch01.bmp"
//#define PATH "ch04.bmp"
//#define PATH "ch08.bmp"
//#define PATH "ch24.bmp"

// исследование BMP
void bitmap() {
    FILE * bin = fopen(PATH, "rb");
    if (!bin) return;
	BITMAPFILEHEADER bmfh;
	// Считываем первую структуру из которой состоит файл BMP
	int res = fread((void*)&bmfh, sizeof(bmfh), 1, bin);
	if (!res) return;
	// Размер BITMAPINFO
	int cbmi = bmfh.bfOffBits - sizeof(BITMAPFILEHEADER);
	// Структура
	BITMAPINFO* pbmi = (BITMAPINFO*)LocalAlloc(LPTR, cbmi);
	res = fread((void*)pbmi, cbmi, 1, bin);
	if (!res) return;

	BMPX = pbmi->bmiHeader.biWidth; // ширина картинки
	BMPY = pbmi->bmiHeader.biHeight; // высота картинки

	/* Анализируем эл-ты палитры */
	RGBQUAD* ppal = &pbmi->bmiColors[0];
	pbmi->bmiColors[1].rgbBlue = 127;
	// массив пиксельного набора
	BYTE* dibs = (BYTE*)LocalAlloc(LPTR, pbmi->bmiHeader.biSizeImage);
	// читаем пиксельный набор
	res = fread((void*)dibs, pbmi->bmiHeader.biSizeImage, 1, bin);
	// картинка
	HBMP = CreateDIBitmap(DCBMP, &pbmi->bmiHeader, CBM_INIT,
		dibs, pbmi, DIB_RGB_COLORS);
	SelectObject(CDC, HBMP);
	// вывод картинки
	BitBlt(DCBMP, 0, 0, BMPX, BMPY, CDC, 0, 0, SRCCOPY);
	// масштабированиe картинки
	StretchBlt(DCBMP, 0, 50, BMPX * ScaleBlt, BMPY * ScaleBlt, CDC, 0, 0, BMPX, BMPY, SRCCOPY);
	// DeleteDC(CDC);
	DeleteObject(DCBMP);
	ReleaseDC(hWndBMP, DCBMP);
	fclose(bin);
}

// исследование метафайла
void metafile() {
	//HDC hdc = CreateEnhMetaFile(DCEMF, "flag.emf", NULL, NULL);

	//RECT rc1 = { 0, 0, 500, 100 };
	//HBRUSH hb = CreateSolidBrush(RGB(255, 255, 255)); // создает кисть
	//FillRect(hdc, &rc1, hb); // закрашивает область
	//DeleteObject(hb);
	//RECT rc2 = { 0, 100, 500, 200 };
	//hb = CreateSolidBrush(RGB(0, 0, 255));
	//FillRect(hdc, &rc2, hb); // рисует прямоугольник, залитый в синий цвет
	//DeleteObject(hb);
	//RECT rc3 = { 0, 200, 500, 300 };
	//hb = CreateSolidBrush(RGB(255, 0, 0));
	//FillRect(hdc, &rc3, hb); // рисует прямоугольник, залитый в красный цвет
	//DeleteObject(hb);

	//HENHMETAFILE hemf = CloseEnhMetaFile(hdc);
	//RECT rc = { 0, 0, 500, 300 };
	//PlayEnhMetaFile(DCEMF, hemf, &rc);
	//CloseEnhMetaFile(hdc);

	int W = 10000, H = 10000;
	RECT rc_quad = { 0, 0, W, H };

	HDC hdc2 = CreateEnhMetaFile(DCEMF, "quad.emf", &rc_quad, NULL);
	SetMapMode(hdc2, MM_HIMETRIC);
	
	HPEN hp = CreatePen(PS_SOLID | PS_INSIDEFRAME, 300,  0);
	SelectObject(hdc2, hp);
	Rectangle(hdc2, 0, 0, W, -H);
	DeleteObject(hp);
	
	hp = CreatePen(PS_SOLID | PS_INSIDEFRAME, 100, 0); 
	SelectObject(hdc2, hp);

	MoveToEx(hdc2, W / 2, 0, NULL); 
	LineTo(hdc2, W / 2, -H); 
	MoveToEx(hdc2, 0, -H / 2, NULL); 
	LineTo(hdc2, W, -H / 2); 
	DeleteObject(hp);

	HENHMETAFILE hemf = CloseEnhMetaFile(hdc2);
	SetMapMode(DCEMF, MM_HIMETRIC);
	RECT rc_quad1 = { 0, 0, W - 200, 200 - H };
	PlayEnhMetaFile(DCEMF, hemf, &rc_quad1);

	CloseEnhMetaFile(hdc2);
}
