// 2007 ReVoL Primer Template
// 4-bezier.h

// рисует кривую Безье
// px, py - массивы координат точек
// m      - количество точек (схватов), порядок кривой на 1 меньше
// ln     - количество сегментов прямых
void draw_bezier(HDC hdc, const int * px, const int * py, int m, int ln) {
	// вычисляем приращения
	double dt = 1.0 / ln;
	double t = 0;
	// устанавливаем начальную точку
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

// вычисляет базисную функцию кривой Безье
double jnit(int n, int i, double t) {
    return cni(n,i) * pow(t,i) * pow(1 - t, n - i);
}

// вычисляет полиномиальный коэффициент
double cni(int n, int i) {
    return fact[n]/fact[i]/fact[n-i];
}

// факториал n
int fact[] = { 1, 1, 2, 6, 24, 120, 720, 5040 };
