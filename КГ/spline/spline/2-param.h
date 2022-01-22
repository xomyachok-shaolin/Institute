// 2007 ReVoL Primer Template
// 2-param.h

// рисует параметрический сплайн (сегмент)
// px, py - массивы координат точек
// ln     - количество сегментов прямых
void draw_param(HDC hdc, const int * px, const int * py, int ln) {
	// дифференциалы в концевых точках
	double k0x = 0, k0y = 0, k1x = 0, k1y = 0;
	// длина кривой
	double t = 0;

	int dx = px[GRIP_L] - px[0],
		dy = py[GRIP_L] - py[0];
	double d1 = sqrt(dx * dx + dy * dy);
	
	k0x = dx / d1; k0y = dy / d1;
	
	dx = px[1] - px[GRIP_R];
	dy = py[1] - py[GRIP_R];
	double d2 = sqrt(dx * dx + dy * dy);
	
	k1x = dx / d2; k1y = dy / d2;

	t = (d1 + d2) * 5;
	// t = px[1] - px[0];

	// выводим сегмент
	draw_segment(hdc, px[0], py[0], px[1], py[1], k0x, k0y, k1x, k1y, t, ln);
}

// рисует сегмент кубического сплайна
// x0, y0   - координаты начальной точки
// x1, y1   - координаты конечной точки
// k0x, k0y - дифференциал в начальной точке
// k1x, k1y - дифференциал в конечной точке
// t        - максимальное значение параметра
// ln       - количество прямых линий
void draw_segment(HDC hdc, int x0, int y0, int x1, int y1, double k0x, double k0y, double k1x, double k1y, double t2, int ln) {
	double a3x = 3 * (x1 - x0) / (t2 * t2) - (k0x + k0x + k1x) / t2;
	double a3y = 3 * (y1 - y0) / (t2 * t2) - (k0y + k0y + k1y) / t2;
	double a4x = 2 * (x0 - x1) / (t2 * t2 * t2) + (k0x + k1x) / (t2 * t2);
	double a4y = 2 * (y0 - y1) / (t2 * t2 * t2) + (k0y + k1y) / (t2 * t2);
	// вычисляем шаг приращения
	double dt = (double)t2 / ln;
	double t = 0;
	// устанавливаем начальную точку
	MoveToEx(hdc, x0, y0, 0);
	for (int i(0); i < ln; i++) {
		t += dt;
		int x = x0 + (k0x + (a3x + a4x * t) * t) * t;
		int y = y0 + (k0y + (a3y + a4y * t) * t) * t;
		LineTo(hdc, x, y);
	}
}
