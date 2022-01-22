// 2007 ReVoL Primer Template
// 3-multi.h

// матрица-столбец дифференциалов
point K[MAX_POINT];
// матрица-столбец свободных элементов
point B[MAX_POINT];
// длины сегментов
double T[MAX_POINT];

// рисует многосегментный параметрический сплайн
// px, py - массивы координат точек
// m      - количество точек (схватов)
// ln     - количество сегментов пр€мых
void draw_segments(HDC hdc, int * px, int * py, int m, int ln) {
	// дифференциалы в концевых точках
	double k0x = 0, k0y = 0, k1x = 0, k1y = 0;
	int n = m - 1;
	for (int i = 0; i < n; i++) 
		T[i + 1] = sqrt((px[i + 1] - px[i]) * (px[i + 1] - px[i]) + 
						(py[i + 1] - py[i]) * (py[i + 1] - py[i]));

	int dx = px[0] - px[GRIP_L],
		dy = py[0] - py[GRIP_L];
	double d1 = sqrt(dx * dx + dy * dy);
	k0x = dx / d1; k0y = dy / d1;
	K[0].x = k0x; K[0].y = k0y;

	dx = px[GRIP_R] - px[n];
	dy = py[GRIP_R] - py[n];
	double d2 = sqrt(dx * dx + dy * dy);
	k1x = dx / d2; k1y = dy / d2;
	K[n].x = k1x; K[n].y = k1y;

	// длина сегмента равна длине хорды, соедин€ющ концевые точки сегмента
	for (int i = 1; i < n; i++) {
		B[i].x = 3 * ((px[i + 1] - px[i]) * T[i] / T[i + 1] + 
			(px[i] - px[i - 1]) * T[i + 1] / T[i]);
		B[i].y = 3 * ((py[i + 1] - py[i]) * T[i] / T[i + 1] +
			(py[i] - py[i - 1]) * T[i + 1] / T[i]);
	}

	solve_tgs(K, B, T, n);

	for (int i = 0; i < n; i++) {
		draw_segment(hdc, px[i], py[i], px[i + 1], py[i + 1], K[i].x, K[i].y, K[i + 1].x, K[i + 1].y, T[i + 1], ln);
	}
}
