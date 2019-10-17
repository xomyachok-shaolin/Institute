// 2018 ReVoL Primer Template
// fonts.cpp
#include "fonts.h" 

// ������������ �������
void fonts(void) {
	// ��������� ���������� ������ �� ���������������� (�����������) ������, ������, ������� ��� ������.
	HFONT hf = (HFONT)GetStockObject(ANSI_VAR_FONT); // ��������� ���������� ���������������� �����
	HFONT exhf = (HFONT)SelectObject(CDC, hf); // �������� ������ � �������� �������� ����������
	SetTextColor(CDC, RGB(255, 0, 0)); // ���������� ����
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 0, 0, "��� ������ ������ ������ ������", 31);
	SetTextColor(CDC, RGB(0, 255, 255)); // ���������� ����
	SetBkColor(CDC, RGB(128, 0, 255)); // ������ ���� ����
	TextOut(CDC, 0, 20, "��� ������ ������ ������ ������", 31);
	SetTextColor(CDC, RGB(0, 0, 255)); // ���������� ����
	SetBkColor(CDC, RGB(255, 0, 255)); // ������ ���� ����
	SetBkMode(CDC, OPAQUE); // ������������� ������������
	TextOut(CDC, 0, 40, "��� ������ ������ ������ ������", 31);
	SelectObject(CDC, exhf);
	DeleteObject(hf); // ������� ����� hf
	// �������������� ����� � ���� ������
	InvalidateRect(hWndOut, 0, 1);

	// ��������� ���������� ������ �� ���������������� (�����������) ������, ������, ������� ��� ������.
	hf = (HFONT)GetStockObject(DEFAULT_GUI_FONT); // ��������� ���������� ���������������� �����
	SetTextColor(CDC, RGB(255, 0, 0)); // ���������� ����
	SetBkColor(CDC, RGB(255, 255, 255)); // ������ ���� ����
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 0, 80, "��� ������ ������ ������ ������", 31);
	SetTextColor(CDC, RGB(0, 255, 255)); // ���������� ����
	SetBkColor(CDC, RGB(128, 0, 255)); // ������ ���� ����
	TextOut(CDC, 0, 100, "��� ������ ������ ������ ������", 31);
	SetTextColor(CDC, RGB(0, 0, 255)); // ���������� ����
	SetBkColor(CDC, RGB(255, 0, 255)); // ������ ���� ����
	SetBkMode(CDC, OPAQUE); // ������������� ������������
	TextOut(CDC, 0, 120, "��� ������ ������ ������ ������", 31);
	SelectObject(CDC, exhf);
	DeleteObject(hf); // ������� ����� hf
	// �������������� ����� � ���� ������
	InvalidateRect(hWndOut, 0, 1);

	// ��������� ���������� ������ �� ���������������� (�����������) ������, ������, ������� ��� ������.
	hf = (HFONT)GetStockObject(WHITE_BRUSH); // ��������� ���������� ���������������� �����
	SetTextColor(CDC, RGB(255, 0, 0)); // ���������� ����
	SetBkColor(CDC, RGB(255, 255, 255)); // ������ ���� ����
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 0, 160, "��� ������ ������ ������ ������", 31);
	SetTextColor(CDC, RGB(0, 255, 255)); // ���������� ����
	SetBkColor(CDC, RGB(128, 0, 255)); // ������ ���� ����
	TextOut(CDC, 0, 180, "��� ������ ������ ������ ������", 31);
	SetTextColor(CDC, RGB(0, 0, 255)); // ���������� ����
	SetBkColor(CDC, RGB(255, 0, 255)); // ������ ���� ����
	SetBkMode(CDC, OPAQUE); // ������������� ������������
	TextOut(CDC, 0, 200, "��� ������ ������ ������ ������", 31);
	SelectObject(CDC, exhf);
	DeleteObject(hf); // ������� ����� hf
					  // �������������� ����� � ���� ������
	InvalidateRect(hWndOut, 0, 1);

	// ��������� ���������� ������ �� ���������������� (�����������) ������, ������, ������� ��� ������.
	hf = (HFONT)GetStockObject(ANSI_FIXED_FONT); // ��������� ���������� ���������������� �����
	SetTextColor(CDC, RGB(255, 0, 0)); // ���������� ����
	SetBkColor(CDC, RGB(255, 255, 255)); // ������ ���� ����
	SetTextAlign(CDC, TA_LEFT);
	TextOut(CDC, 350, 0, "��� ������ ������ ������ ������", 31);
	SetTextColor(CDC, RGB(0, 255, 255)); // ���������� ����
	SetBkColor(CDC, RGB(128, 0, 255)); // ������ ���� ����
	TextOut(CDC, 350, 20, "��� ������ ������ ������ ������", 31);
	SetTextColor(CDC, RGB(0, 0, 255)); // ���������� ����
	SetBkColor(CDC, RGB(255, 0, 255)); // ������ ���� ����
	SetBkMode(CDC, OPAQUE); // ������������� ������������
	TextOut(CDC, 350, 40, "��� ������ ������ ������ ������", 31);
	SelectObject(CDC, exhf);
	DeleteObject(hf); // ������� ����� hf
					  // �������������� ����� � ���� ������
	InvalidateRect(hWndOut, 0, 1);
}
