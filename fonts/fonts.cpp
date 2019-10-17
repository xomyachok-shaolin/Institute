// 2018 ReVoL Primer Template
// fonts.cpp
#include "fonts.h" 

// тестирование шрифтов
void fonts(void) {
	// извлекает дескриптор одного из предопределенных (стандартных) перьев, кистей, шрифтов или палитр.
	HFONT hf = (HFONT)GetStockObject(ANSI_VAR_FONT); // Системный нормальный пропорциональный шрифт
	HFONT exhf = (HFONT)SelectObject(CDC, hf); // выбирает объект в заданный контекст устройства
	SetTextColor(CDC, RGB(255, 0, 0)); // установить цвет
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 0, 0, "Это пример вывода строки текста", 31);
	SetTextColor(CDC, RGB(0, 255, 255)); // установить цвет
	SetBkColor(CDC, RGB(128, 0, 255)); // задает цвет фона
	TextOut(CDC, 0, 20, "Это пример вывода строки текста", 31);
	SetTextColor(CDC, RGB(0, 0, 255)); // установить цвет
	SetBkColor(CDC, RGB(255, 0, 255)); // задает цвет фона
	SetBkMode(CDC, OPAQUE); // устанавливает прозрачность
	TextOut(CDC, 0, 40, "Это пример вывода строки текста", 31);
	SelectObject(CDC, exhf);
	DeleteObject(hf); // удалить шрифт hf
	// принудительный вывод в окно вывода
	InvalidateRect(hWndOut, 0, 1);

	// извлекает дескриптор одного из предопределенных (стандартных) перьев, кистей, шрифтов или палитр.
	hf = (HFONT)GetStockObject(DEFAULT_GUI_FONT); // Системный нормальный пропорциональный шрифт
	SetTextColor(CDC, RGB(255, 0, 0)); // установить цвет
	SetBkColor(CDC, RGB(255, 255, 255)); // задает цвет фона
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 0, 80, "Это пример вывода строки текста", 31);
	SetTextColor(CDC, RGB(0, 255, 255)); // установить цвет
	SetBkColor(CDC, RGB(128, 0, 255)); // задает цвет фона
	TextOut(CDC, 0, 100, "Это пример вывода строки текста", 31);
	SetTextColor(CDC, RGB(0, 0, 255)); // установить цвет
	SetBkColor(CDC, RGB(255, 0, 255)); // задает цвет фона
	SetBkMode(CDC, OPAQUE); // устанавливает прозрачность
	TextOut(CDC, 0, 120, "Это пример вывода строки текста", 31);
	SelectObject(CDC, exhf);
	DeleteObject(hf); // удалить шрифт hf
	// принудительный вывод в окно вывода
	InvalidateRect(hWndOut, 0, 1);

	// извлекает дескриптор одного из предопределенных (стандартных) перьев, кистей, шрифтов или палитр.
	hf = (HFONT)GetStockObject(WHITE_BRUSH); // Системный нормальный пропорциональный шрифт
	SetTextColor(CDC, RGB(255, 0, 0)); // установить цвет
	SetBkColor(CDC, RGB(255, 255, 255)); // задает цвет фона
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 0, 160, "Это пример вывода строки текста", 31);
	SetTextColor(CDC, RGB(0, 255, 255)); // установить цвет
	SetBkColor(CDC, RGB(128, 0, 255)); // задает цвет фона
	TextOut(CDC, 0, 180, "Это пример вывода строки текста", 31);
	SetTextColor(CDC, RGB(0, 0, 255)); // установить цвет
	SetBkColor(CDC, RGB(255, 0, 255)); // задает цвет фона
	SetBkMode(CDC, OPAQUE); // устанавливает прозрачность
	TextOut(CDC, 0, 200, "Это пример вывода строки текста", 31);
	SelectObject(CDC, exhf);
	DeleteObject(hf); // удалить шрифт hf
					  // принудительный вывод в окно вывода
	InvalidateRect(hWndOut, 0, 1);

	// извлекает дескриптор одного из предопределенных (стандартных) перьев, кистей, шрифтов или палитр.
	hf = (HFONT)GetStockObject(ANSI_FIXED_FONT); // Системный нормальный пропорциональный шрифт
	SetTextColor(CDC, RGB(255, 0, 0)); // установить цвет
	SetBkColor(CDC, RGB(255, 255, 255)); // задает цвет фона
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 350, 0, "Это пример вывода строки текста", 31);
	SetTextColor(CDC, RGB(0, 255, 255)); // установить цвет
	SetBkColor(CDC, RGB(128, 0, 255)); // задает цвет фона
	TextOut(CDC, 350, 20, "Это пример вывода строки текста", 31);
	SetTextColor(CDC, RGB(0, 0, 255)); // установить цвет
	SetBkColor(CDC, RGB(255, 0, 255)); // задает цвет фона
	SetBkMode(CDC, OPAQUE); // устанавливает прозрачность
	TextOut(CDC, 350, 40, "Это пример вывода строки текста", 31);
	SelectObject(CDC, exhf);
	DeleteObject(hf); // удалить шрифт hf
					  // принудительный вывод в окно вывода
	InvalidateRect(hWndOut, 0, 1);
}
