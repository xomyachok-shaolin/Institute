// 2018 ReVoL Primer Template
// fonts.cpp
#include "fonts.h"

// ������������ �������
void fonts(void) {
	// �������� �����
	HFONT hf = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
	// �������� ����� � ��������
	HFONT exhf = (HFONT)SelectObject(CDC, hf);
	// �������� ���� � ������ ������
	SetTextColor(CDC, RGB(255, 0, 0));
	SetBkColor(CDC, RGB(0, 0, 255));
	SetBkMode(CDC, OPAQUE);
	SetTextAlign(CDC, TA_UPDATECP);
	
	TextOut(CDC, 10, 10, "����� ANSI_VAR_FONT", 20);
	// �������� ������ �����
	SelectObject(CDC, exhf);
	DeleteObject(hf);
	
	InvalidateRect(hWndOut, 0, 1);
}
