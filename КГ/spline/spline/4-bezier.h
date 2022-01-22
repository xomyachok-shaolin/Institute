// 2007 ReVoL Primer Template
// 4-bezier.h

// ������ ������ �����
// px, py - ������� ��������� �����
// m      - ���������� ����� (�������), ������� ������ �� 1 ������
// ln     - ���������� ��������� ������
void draw_bezier(HDC hdc, const int * px, const int * py, int m, int ln) {
	// ��������� ����������
	double dt = 1.0 / ln;
	double t = 0;
	// ������������� ��������� �����
	MoveToEx(hdc, px[0], py[0], 0);
	for (int k(0); k < ln; k++) {
		t += dt;
		double x = 0, y = 0;
		for (int i(0); i < m; i++) {
			double w = jnit(m - 1, i, t);
			x += px[i] * w;
			y += py[i] * w;
		}
		LineTo(hdc, x, y);
	}
	POINT points[MAX_POINT];
	for (int i(0); i < m; i++) {
		points[i].x = px[i];
		points[i].y = py[i];
	}
	PolyBezier(hdc, (PPOINT)points, m);
}

// ��������� �������� ������� ������ �����
double jnit(int n, int i, double t) {
    return cni(n,i) * pow(t,i) * pow(1 - t, n - i);
}

// ��������� �������������� �����������
double cni(int n, int i) {
    return fact[n]/fact[i]/fact[n-i];
}

// ��������� n
int fact[] = { 1, 1, 2, 6, 24, 120, 720, 5040 };
