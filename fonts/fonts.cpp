// 2018 ReVoL Primer Template
// fonts.cpp
#include "fonts.h" 

// ������������ �������
void fonts(void) {
	/* ������������� ����������� ������� */

	// ��������� ���������� ������ �� ���������������� (�����������) ������, ������, ������� ��� ������.
	HFONT hf = (HFONT)GetStockObject(OEM_FIXED_FONT);
	// �������� ����� � ��������
	HFONT exhf = (HFONT)SelectObject(CDC, hf);
	// �������� ���� � ������ ������
	SetTextColor(CDC, RGB(255, 0, 0));
	SetBkColor(CDC, RGB(0, 0, 255));
	// ������ ������������
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 0, 0, "����� OEM_FIXED_FONT", 17);	
	// �������� ������ �����
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(ANSI_FIXED_FONT);
	SetTextColor(CDC, RGB(255, 255, 0));
	SetBkColor(CDC, RGB(0, 0, 255));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 0, 20, "����� ANSI_FIXED_FONT", 21);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(ANSI_VAR_FONT);
	SetTextColor(CDC, RGB(255, 0, 255));
	SetBkColor(CDC, RGB(0, 255, 0));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 0, 40, "����� ANSI_VAR_FONT", 19);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(SYSTEM_FONT);
	SetTextColor(CDC, RGB(0, 255, 255));
	SetBkColor(CDC, RGB(0, 0, 0));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 0, 60, "����� SYSTEM_FONT", 19);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(DEVICE_DEFAULT_FONT);
	SetTextColor(CDC, RGB(0, 255, 0));
	SetBkColor(CDC, RGB(255, 0, 255));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 300, 0, "����� DEVICE_DEFAULT_FONT", 25);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
	SetTextColor(CDC, RGB(0, 0, 255));
	SetBkColor(CDC, RGB(255, 255, 0));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 300, 20, "����� DEFAULT_GUI_FONT", 22);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(SYSTEM_FIXED_FONT);
	SetTextColor(CDC, RGB(255, 0, 0));
	SetBkColor(CDC, RGB(0, 255, 255));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 300, 40, "����� SYSTEM_FIXED_FONT", 23);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	// ������ ����� � ���� ������
	InvalidateRect(hWndOut, 0, 1);

	/* ����� ������ ��� ������ ������������ ������� */
	HDC hdc; CHOOSEFONTA cf; static LOGFONT lf;
	static DWORD rgbCurrent;
	ZeroMemory(&cf, sizeof(CHOOSEFONT));
	cf.lStructSize = sizeof(CHOOSEFONT);
	cf.hwndOwner = hWndOut;
	cf.lpLogFont = &lf;
	cf.rgbColors = rgbCurrent;
	cf.Flags = CF_SCREENFONTS | CF_EFFECTS;
	if (ChooseFont(&cf) == TRUE) {
		hdc = GetDC(hWndOut);
		hf = CreateFontIndirect(cf.lpLogFont);
		SelectObject(hdc, hf);
		rgbCurrent = cf.rgbColors;
		SetTextColor(hdc, rgbCurrent);
		TextOut(hdc, 0, 80, "AbCdEf 012345 ������", 20);
		ReleaseDC(hWndOut, hdc);
	}

	/* �������� ������ */
	// �������������
	hf = CreateFont(16, 0, 0, 0, 0, 0, 0, 0, RUSSIAN_CHARSET, 0, 0, 0, 0, "Tahoma");
	exhf = (HFONT)SelectObject(hdc, hf);
	TextOut(hdc, 0, 120, "Horisontal", 10);
	SelectObject(hdc, exhf);
	DeleteObject(hf);
	// �����������
	// SetGraphicsMode(CDC, GM_ADVANCED);
	hf = CreateFont(16, 0, 900, 0, 0, 0, 0, 0, RUSSIAN_CHARSET, 0, 0, 0, 0, "Times New Roman");
	exhf = (HFONT)SelectObject(hdc, hf);
	TextOut(hdc, 0, 185, "Vertical", 8);
	SelectObject(hdc, exhf);
	DeleteObject(hf);
	// � ��������� ���� �� 45����
	hf = CreateFont(16, 0, -450, 0, 0, 0, 0, 0, RUSSIAN_CHARSET, 0, 0, 0, 0, "MS Sans Serif");
	exhf = (HFONT)SelectObject(hdc, hf);
	SetGraphicsMode(hdc, GM_ADVANCED);
	TextOut(hdc, 0, 195, "With a rotation angle of 45 degrees", 35);
	SelectObject(hdc, exhf);
	DeleteObject(hf);
	// � ����������� ������� �������� � ����
	hf = CreateFont(16, 0, 0, 900, 0, 0, 0, 0, RUSSIAN_CHARSET, 0, 0, 0, 0, "Arial");
	exhf = (HFONT)SelectObject(hdc, hf);
	SetGraphicsMode(hdc, GM_ADVANCED);
	TextOut(hdc, 210, 150, "With a rotation horizontal & vertical", 37);
	SelectObject(hdc, exhf);
	DeleteObject(hf);

	hf = CreateFont(16, 0, 0, -900, 0, 0, 0, 0, RUSSIAN_CHARSET, 0, 0, 0, 0, "Arial");
	exhf = (HFONT)SelectObject(hdc, hf);
	SetGraphicsMode(hdc, GM_ADVANCED);
	TextOut(hdc, 240, 170, "With a rotation horizontal & vertical", 37);
	SelectObject(hdc, exhf);
	DeleteObject(hf);

	hf = CreateFont(16, 0, -900, -900, 0, 0, 0, 0, RUSSIAN_CHARSET, 0, 0, 0, 0, "Arial");
	exhf = (HFONT)SelectObject(hdc, hf);
	SetGraphicsMode(hdc, GM_ADVANCED);
	TextOut(hdc, 170, 150, "With a rotation horizontal & vertical", 37);
	SelectObject(hdc, exhf);
	DeleteObject(hf);

	hf = CreateFont(16, 0, -900, 900, 0, 0, 0, 0, RUSSIAN_CHARSET, 0, 0, 0, 0, "Arial");
	exhf = (HFONT)SelectObject(hdc, hf);
	SetGraphicsMode(hdc, GM_ADVANCED);
	TextOut(hdc, 190, 150, "With a rotation horizontal & vertical", 37);
	SelectObject(hdc, exhf);
	DeleteObject(hf);
	// � �������� � ������ ���������
	hf = CreateFont(16, 10, 0, 0, 0, 0, 0, 0, RUSSIAN_CHARSET, 0, 0, 0, 0, "Tahoma");
	exhf = (HFONT)SelectObject(hdc, hf);
	TextOut(hdc, 0, 400, "Witdh big width", 20);
	SelectObject(hdc, exhf);
	DeleteObject(hf);

	TEXTMETRIC txm;
	hf = CreateFont(16, 5, 0, 0, 0, 0, 0, 0, RUSSIAN_CHARSET, 0, 0, 0, 0, "Tahoma");
	exhf = (HFONT)SelectObject(hdc, hf);
	TextOut(hdc, 0, 420, "Width small width", 20);

	GetTextMetrics(hdc, &txm);

	SelectObject(hdc, exhf);
	DeleteObject(hf);
}
