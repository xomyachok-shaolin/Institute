// 2018 ReVoL Primer Template
// fonts.cpp
#include "fonts.h" 

// тестирование шрифтов
void fonts(void) {
	/* Использование стандартных шрифтов */

	// извлекает дескриптор одного из предопределенных (стандартных) перьев, кистей, шрифтов или палитр.
	HFONT hf = (HFONT)GetStockObject(OEM_FIXED_FONT);
	// выбираем шрифт в контекст
	HFONT exhf = (HFONT)SelectObject(CDC, hf);
	// выбираем цвет и режимы вывода
	SetTextColor(CDC, RGB(255, 0, 0));
	SetBkColor(CDC, RGB(0, 0, 255));
	// задает прозрачность
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 0, 0, "Шрифт OEM_FIXED_FONT", 17);	
	// выбираем предыд шрифт
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(ANSI_FIXED_FONT);
	SetTextColor(CDC, RGB(255, 255, 0));
	SetBkColor(CDC, RGB(0, 0, 255));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 0, 20, "Шрифт ANSI_FIXED_FONT", 21);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(ANSI_VAR_FONT);
	SetTextColor(CDC, RGB(255, 0, 255));
	SetBkColor(CDC, RGB(0, 255, 0));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 0, 40, "Шрифт ANSI_VAR_FONT", 19);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(SYSTEM_FONT);
	SetTextColor(CDC, RGB(0, 255, 255));
	SetBkColor(CDC, RGB(0, 0, 0));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 0, 60, "Шрифт SYSTEM_FONT", 19);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(DEVICE_DEFAULT_FONT);
	SetTextColor(CDC, RGB(0, 255, 0));
	SetBkColor(CDC, RGB(255, 0, 255));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 300, 0, "Шрифт DEVICE_DEFAULT_FONT", 25);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
	SetTextColor(CDC, RGB(0, 0, 255));
	SetBkColor(CDC, RGB(255, 255, 0));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 300, 20, "Шрифт DEFAULT_GUI_FONT", 22);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(SYSTEM_FIXED_FONT);
	SetTextColor(CDC, RGB(255, 0, 0));
	SetBkColor(CDC, RGB(0, 255, 255));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 300, 40, "Шрифт SYSTEM_FIXED_FONT", 23);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	// принуд вывод в окно вывода
	InvalidateRect(hWndOut, 0, 1);

	/* Выбор шрифта при помощи стандартного диалога */
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
		HFONT hf = CreateFontIndirect(cf.lpLogFont);
		SelectObject(hdc, hf);
		rgbCurrent = cf.rgbColors;
		SetTextColor(hdc, rgbCurrent);
		TextOut(hdc, 0, 80, "AbCdEf 012345 АБВГДЕ", 20);
		ReleaseDC(hWndOut, hdc);
	}
}
