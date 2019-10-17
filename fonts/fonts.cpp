// 2018 ReVoL Primer Template
// fonts.cpp
#include "fonts.h" 

// тестирование шрифтов
void fonts(void) {
	/* Использование стандартных шрифтов */
	// извлекает дескриптор одного из предопределенных (стандартных) перьев, кистей, шрифтов или палитр.
	HFONT hf = (HFONT)GetStockObject(WHITE_BRUSH);
	// выбираем шрифт в контекст
	HFONT exhf = (HFONT)SelectObject(CDC, hf);
	// выбираем цвет и режимы вывода
	SetTextColor(CDC, RGB(255, 0, 0));
	SetBkColor(CDC, RGB(0, 0, 255));
	// задает прозрачность
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 0, 0, "Шрифт WHITE_BRUSH", 17);	
	// выбираем предыд шрифт
	SelectObject(CDC, exhf);
	DeleteObject(hf);
	
	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(LTGRAY_BRUSH);
	SetTextColor(CDC, RGB(255, 255, 0));
	SetBkColor(CDC, RGB(0, 0, 255));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 0, 20, "Шрифт LTGRAY_BRUSH", 18);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(GRAY_BRUSH);
	SetTextColor(CDC, RGB(0, 255, 255));
	SetBkColor(CDC, RGB(255, 0, 0));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 0, 40, "Шрифт GRAY_BRUSH", 16);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(DKGRAY_BRUSH);
	SetTextColor(CDC, RGB(255, 0, 255));
	SetBkColor(CDC, RGB(0, 255, 0));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 0, 60, "Шрифт DKGRAY_BRUSH", 18);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(BLACK_BRUSH);
	SetTextColor(CDC, RGB(128, 128, 0));
	SetBkColor(CDC, RGB(0, 0, 128));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 0, 80, "Шрифт BLACK_BRUSH", 17);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(HOLLOW_BRUSH);
	SetTextColor(CDC, RGB(0, 128, 128));
	SetBkColor(CDC, RGB(128, 0, 0));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 0, 100, "Шрифт HOLLOW_BRUSH", 18);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(NULL_BRUSH);
	SetTextColor(CDC, RGB(128, 0, 128));
	SetBkColor(CDC, RGB(0, 128, 0));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 0, 120, "Шрифт NULL_BRUSH", 16);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(WHITE_PEN);
	SetTextColor(CDC, RGB(0, 255, 0));
	SetBkColor(CDC, RGB(255, 0, 255));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 0, 140, "Шрифт WHITE_PEN", 15);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(BLACK_PEN);
	SetTextColor(CDC, RGB(255, 0, 0));
	SetBkColor(CDC, RGB(0, 255, 255));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 0, 160, "Шрифт BLACK_PEN", 15);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(OEM_FIXED_FONT);
	SetTextColor(CDC, RGB(0, 0, 255));
	SetBkColor(CDC, RGB(255, 255, 0));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 0, 180, "Шрифт OEM_FIXED_FONT", 21);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(ANSI_FIXED_FONT);
	SetTextColor(CDC, RGB(0, 255, 0));
	SetBkColor(CDC, RGB(0, 0, 255));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 300, 0, "Шрифт ANSI_FIXED_FONT", 21);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(ANSI_VAR_FONT);
	SetTextColor(CDC, RGB(0, 0, 255));
	SetBkColor(CDC, RGB(0, 255, 0));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 300, 20, "Шрифт ANSI_VAR_FONT", 19);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(SYSTEM_FONT);
	SetTextColor(CDC, RGB(128, 0, 0));
	SetBkColor(CDC, RGB(0, 255, 0));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 300, 40, "Шрифт SYSTEM_FONT", 19);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(DEVICE_DEFAULT_FONT);
	SetTextColor(CDC, RGB(0, 128, 0));
	SetBkColor(CDC, RGB(255, 0, 0));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 300, 60, "Шрифт DEVICE_DEFAULT_FONT", 25);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
	SetTextColor(CDC, RGB(0, 0, 128));
	SetBkColor(CDC, RGB(128, 0, 0));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 300, 80, "Шрифт DEFAULT_GUI_FONT", 22);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(DEFAULT_PALETTE);
	SetTextColor(CDC, RGB(64, 0, 0));
	SetBkColor(CDC, RGB(0, 128, 0));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 300, 100, "Шрифт DEFAULT_PALETTE", 21);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(SYSTEM_FIXED_FONT);
	SetTextColor(CDC, RGB(0, 64, 0));
	SetBkColor(CDC, RGB(0, 0, 128));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 300, 120, "Шрифт SYSTEM_FIXED_FONT", 23);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(DC_BRUSH);
	SetTextColor(CDC, RGB(32, 0, 0));
	SetBkColor(CDC, RGB(0, 64, 0));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 300, 140, "Шрифт DC_BRUSH", 14);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	exhf = (HFONT)SelectObject(CDC, hf);
	hf = (HFONT)GetStockObject(DC_PEN);
	SetTextColor(CDC, RGB(255, 255, 255));
	SetBkColor(CDC, RGB(0, 0, 64));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 300, 160, "Шрифт DC_PEN", 12);
	SelectObject(CDC, exhf);
	DeleteObject(hf);

	// принуд вывод в окно вывода
	InvalidateRect(hWndOut, 0, 1);
}
