// 2018 ReVoL Primer Template
// fonts.cpp
#include "fonts.h"

// עוסעטנמגאםטו רנטפעמג
void fonts(void) {
	// גûבטנאול רנטפע
	HFONT hf = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
	// גûבטנאול רנטפע ג ךמםעוךסע
	HFONT exhf = (HFONT)SelectObject(CDC, hf);
	// גûבטנאול צגוע ט נוזטלû גûגמהא
	SetTextColor(CDC, RGB(255, 0, 0));
	SetBkColor(CDC, RGB(0, 0, 255));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_UPDATECP);
	
	TextOut(CDC, 10, 10, "״נטפע ANSI_VAR_FONT", 20);
	// גûבטנאול ןנוהûה רנטפע
	SelectObject(CDC, exhf);
	DeleteObject(hf);
	
	InvalidateRect(hWndOut, 0, 1);
}
