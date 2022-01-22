// 2007 ReVoL Primer Template
// 1-nonparam.h

// рисует непараметрический сплайн
// px, py - массивы координат точек
// ln     - количество сегментов прямых
void draw_nonparam(HDC hdc, const int * px, const int * py, int ln) {
	int dx = px[GRIP_L] - px[0], 
		dy = py[GRIP_L] - py[0];

	double d = sqrt((double)dx * dx + dy * dy);
	double k0 = dy / d;

	// double k0 = (double)dy / dx;
		dx = px[1] - px[GRIP_R];
		dy = py[1] - py[GRIP_R];
	d = sqrt((double)dx * dx + dy * dy);
	double k1 = dy / d;
	// double k1 = (double)dy / dx;

	double t = px[1] - px[0];
	double a3 = 3 * (py[1] - py[0]) / (t * t) - (k0 + k0 + k1) / t;
	double a4 = 2 * (py[0] - py[1]) / (t * t * t) + (k0 + k1) / (t * t);
	// вычисляем шаг приращения
	double ax = (double)t / ln;
	// устанавливаем начальную точку
	double x = 0, y;
	MoveToEx(hdc, px[0], py[0], 0);
	for (int i(0); i < ln; i++) {
		x += ax;
		y = py[0] + (k0 + (a3 + a4 * x) * x) * x;
		LineTo(hdc, px[0] + x, y);
	}
}
