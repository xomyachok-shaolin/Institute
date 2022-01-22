// 2018 ReVoL Primer Template
// bmap.cpp
#include "bmap.h"
// ���� � ����� BMP
#define PATH "ch01.bmp"
//#define PATH "ch04.bmp"
//#define PATH "ch08.bmp"
//#define PATH "ch24.bmp"

// ������������ BMP
void bitmap() {
    FILE * bin = fopen(PATH, "rb");
    if (!bin) return;
	BITMAPFILEHEADER bmfh;
	// ��������� ������ ��������� �� ������� ������� ���� BMP
	int res = fread((void*)&bmfh, sizeof(bmfh), 1, bin);
	if (!res) return;
	// ������ BITMAPINFO
	int cbmi = bmfh.bfOffBits - sizeof(BITMAPFILEHEADER);
	// ���������
	BITMAPINFO* pbmi = (BITMAPINFO*)LocalAlloc(LPTR, cbmi);
	res = fread((void*)pbmi, cbmi, 1, bin);
	if (!res) return;

	BMPX = pbmi->bmiHeader.biWidth; // ������ ��������
	BMPY = pbmi->bmiHeader.biHeight; // ������ ��������

	/* ����������� ��-�� ������� */
	RGBQUAD* ppal = &pbmi->bmiColors[0];
	pbmi->bmiColors[1].rgbBlue = 127;
	// ������ ����������� ������
	BYTE* dibs = (BYTE*)LocalAlloc(LPTR, pbmi->bmiHeader.biSizeImage);
	// ������ ���������� �����
	res = fread((void*)dibs, pbmi->bmiHeader.biSizeImage, 1, bin);
	// ��������
	HBMP = CreateDIBitmap(DCBMP, &pbmi->bmiHeader, CBM_INIT,
		dibs, pbmi, DIB_RGB_COLORS);
	SelectObject(CDC, HBMP);
	// ����� ��������
	BitBlt(DCBMP, 0, 0, BMPX, BMPY, CDC, 0, 0, SRCCOPY);
	// ��������������e ��������
	StretchBlt(DCBMP, 0, 50, BMPX * ScaleBlt, BMPY * ScaleBlt, CDC, 0, 0, BMPX, BMPY, SRCCOPY);
	// DeleteDC(CDC);
	DeleteObject(DCBMP);
	ReleaseDC(hWndBMP, DCBMP);
	fclose(bin);
}

// ������������ ���������
void metafile() {
	//HDC hdc = CreateEnhMetaFile(DCEMF, "flag.emf", NULL, NULL);

	//RECT rc1 = { 0, 0, 500, 100 };
	//HBRUSH hb = CreateSolidBrush(RGB(255, 255, 255)); // ������� �����
	//FillRect(hdc, &rc1, hb); // ����������� �������
	//DeleteObject(hb);
	//RECT rc2 = { 0, 100, 500, 200 };
	//hb = CreateSolidBrush(RGB(0, 0, 255));
	//FillRect(hdc, &rc2, hb); // ������ �������������, ������� � ����� ����
	//DeleteObject(hb);
	//RECT rc3 = { 0, 200, 500, 300 };
	//hb = CreateSolidBrush(RGB(255, 0, 0));
	//FillRect(hdc, &rc3, hb); // ������ �������������, ������� � ������� ����
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
