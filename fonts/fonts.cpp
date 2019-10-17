// 2018 ReVoL Primer Template
// fonts.cpp
#include "fonts.h" 

// ������������ �������
void fonts(void) {
	/* ������������� ����������� ������� */
	// ��������� ���������� ������ �� ���������������� (�����������) ������, ������, ������� ��� ������.
	HFONT hf = (HFONT)GetStockObject(WHITE_BRUSH);
	// �������� ����� � ��������
	HFONT exhf = (HFONT)SelectObject(CDC, hf);
	// �������� ���� � ������ ������
	SetTextColor(CDC, RGB(255, 0, 0));
	SetBkColor(CDC, RGB(0, 0, 255));
	// ������ ������������
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 0, 0, "����� WHITE_BRUSH", 17);	
	// �������� ������ �����
	SelectObject(CDC, exhf);
	DeleteObject(hf);
	
	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(LTGRAY_BRUSH);
	SetTextColor(CDC, RGB(255, 255, 0));
	SetBkColor(CDC, RGB(0, 0, 255));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 0, 20, "����� LTGRAY_BRUSH", 18);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(GRAY_BRUSH);
	SetTextColor(CDC, RGB(0, 255, 255));
	SetBkColor(CDC, RGB(255, 0, 0));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 0, 40, "����� GRAY_BRUSH", 16);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(DKGRAY_BRUSH);
	SetTextColor(CDC, RGB(255, 0, 255));
	SetBkColor(CDC, RGB(0, 255, 0));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 0, 60, "����� DKGRAY_BRUSH", 18);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(BLACK_BRUSH);
	SetTextColor(CDC, RGB(128, 128, 0));
	SetBkColor(CDC, RGB(0, 0, 128));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 0, 80, "����� BLACK_BRUSH", 17);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(HOLLOW_BRUSH);
	SetTextColor(CDC, RGB(0, 128, 128));
	SetBkColor(CDC, RGB(128, 0, 0));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 0, 100, "����� HOLLOW_BRUSH", 18);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(NULL_BRUSH);
	SetTextColor(CDC, RGB(128, 0, 128));
	SetBkColor(CDC, RGB(0, 128, 0));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 0, 120, "����� NULL_BRUSH", 16);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(WHITE_PEN);
	SetTextColor(CDC, RGB(0, 255, 0));
	SetBkColor(CDC, RGB(255, 0, 255));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 0, 140, "����� WHITE_PEN", 15);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(BLACK_PEN);
	SetTextColor(CDC, RGB(255, 0, 0));
	SetBkColor(CDC, RGB(0, 255, 255));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 0, 160, "����� BLACK_PEN", 15);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(OEM_FIXED_FONT);
	SetTextColor(CDC, RGB(0, 0, 255));
	SetBkColor(CDC, RGB(255, 255, 0));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 0, 180, "����� OEM_FIXED_FONT", 21);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(ANSI_FIXED_FONT);
	SetTextColor(CDC, RGB(0, 255, 0));
	SetBkColor(CDC, RGB(0, 0, 255));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 300, 0, "����� ANSI_FIXED_FONT", 21);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(ANSI_VAR_FONT);
	SetTextColor(CDC, RGB(0, 0, 255));
	SetBkColor(CDC, RGB(0, 255, 0));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 300, 20, "����� ANSI_VAR_FONT", 19);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(SYSTEM_FONT);
	SetTextColor(CDC, RGB(128, 0, 0));
	SetBkColor(CDC, RGB(0, 255, 0));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 300, 40, "����� SYSTEM_FONT", 19);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(DEVICE_DEFAULT_FONT);
	SetTextColor(CDC, RGB(0, 128, 0));
	SetBkColor(CDC, RGB(255, 0, 0));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 300, 60, "����� DEVICE_DEFAULT_FONT", 25);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
	SetTextColor(CDC, RGB(0, 0, 128));
	SetBkColor(CDC, RGB(128, 0, 0));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 300, 80, "����� DEFAULT_GUI_FONT", 22);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(DEFAULT_PALETTE);
	SetTextColor(CDC, RGB(64, 0, 0));
	SetBkColor(CDC, RGB(0, 128, 0));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 300, 100, "����� DEFAULT_PALETTE", 21);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(SYSTEM_FIXED_FONT);
	SetTextColor(CDC, RGB(0, 64, 0));
	SetBkColor(CDC, RGB(0, 0, 128));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 300, 120, "����� SYSTEM_FIXED_FONT", 23);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(DC_BRUSH);
	SetTextColor(CDC, RGB(32, 0, 0));
	SetBkColor(CDC, RGB(0, 64, 0));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 300, 140, "����� DC_BRUSH", 14);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(DC_PEN);
	SetTextColor(CDC, RGB(255, 255, 255));
	SetBkColor(CDC, RGB(0, 0, 64));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 300, 160, "����� DC_PEN", 12);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	// ������ ����� � ���� ������
	InvalidateRect(hWndOut, 0, 1);
}
