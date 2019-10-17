// 2018 ReVoL Primer Template
// fonts.cpp
#include "fonts.h" 

// тестирование шрифтов
void fonts(void) {
	/* »спользование стандартных шрифтов */
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
	TextOut(CDC, 0, 0, "Ўрифт OEM_FIXED_FONT", 17);	
	// выбираем предыд шрифт
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(ANSI_FIXED_FONT);
	SetTextColor(CDC, RGB(255, 255, 0));
	SetBkColor(CDC, RGB(0, 0, 255));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 0, 20, "Ўрифт ANSI_FIXED_FONT", 21);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(ANSI_VAR_FONT);
	SetTextColor(CDC, RGB(255, 0, 255));
	SetBkColor(CDC, RGB(0, 255, 0));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 0, 40, "Ўрифт ANSI_VAR_FONT", 19);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(SYSTEM_FONT);
	SetTextColor(CDC, RGB(0, 255, 255));
	SetBkColor(CDC, RGB(0, 0, 0));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 0, 60, "Ўрифт SYSTEM_FONT", 19);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(DEVICE_DEFAULT_FONT);
	SetTextColor(CDC, RGB(0, 255, 0));
	SetBkColor(CDC, RGB(255, 0, 255));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 300, 0, "Ўрифт DEVICE_DEFAULT_FONT", 25);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
	SetTextColor(CDC, RGB(0, 0, 255));
	SetBkColor(CDC, RGB(255, 255, 0));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 300, 20, "Ўрифт DEFAULT_GUI_FONT", 22);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(SYSTEM_FIXED_FONT);
	SetTextColor(CDC, RGB(255, 0, 0));
	SetBkColor(CDC, RGB(0, 255, 255));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 300, 40, "Ўрифт SYSTEM_FIXED_FONT", 23);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	// принуд вывод в окно вывода
	InvalidateRect(hWndOut, 0, 1);
}
