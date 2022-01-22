// 2007 ReVoL Primer Template
// 5-bspline

// узловой вектор
int V[MAX_POINT + MAX_POINT + 1];

// вычисляет базисную функцию B-сплайна
double nikt(int i, int k, double t, int ln) {
	if (k == 1) {
		if (V[i] * ln <= int(t * ln) && int(t * ln) <= V[i + 1] * ln)
			return 1;
		else
			return 0;
	}
	if (k > 1) {
		double nk_a = nikt(i, k - 1, t, ln),
			   num_a = (t - V[i]) * nk_a,
			   den_a = V[i + k - 1] - V[i];
		double nk_b = nikt(i + 1, k - 1, t, ln),
			num_b = (V[i + k] - t) * nk_b,
			den_b = V[i + k] - V[i + 1];
		if (fabs(den_a) < 0.001 || fabs(nk_a) < 0.001) {
			num_a = 0; den_a = 1;
		}
		if (fabs(den_b) < 0.001 || fabs(nk_b) < 0.001) {
			num_b = 0; den_b = 1;
		}
		return (num_a / den_a  + num_b / den_b);
	}
}

// рисует B-сплайн
// px, py - точки многоугольника
// m      - количество точек (схватов)
// ln     - количество сегментов прямых
// k      - порядок кривой
void draw_bspline(HDC hdc, const int * px, const int * py, int m, int ln, int k) {
	int n = m - 1, tmax = n - k + 2;
	double dt = (double)tmax / ln, t = 0;
	double x = 0, y = 0, w, oldx = 0, oldy = 0;
	double dist, newdist;
	bool flag = 0;
	MoveToEx(hdc, px[0], py[0], 0);
	for (int j = 0; j < ln; j++) {
		t += dt;
		oldx = x;
		oldy = y;
		x = 0; y = 0;
		for (int i = 0; i < m; i++) {
			w = nikt(i, k, t, ln);
			x += px[i] * w;
			y += py[i] * w;
		}
		newdist = sqrt((x - oldx) * (x - oldx) + (y - oldy) * (y - oldy));
		if ((flag != 0) && (newdist / dist > 4)) {
			x = oldx;
			y = oldy;
			flag = 0;
		}
		if ((x != oldx) || (y != oldy)) {
			flag = 1;
			dist = newdist;
		}
		LineTo(hdc, x, y);
	}
}

// строит узловой вектор для B-сплайна
// px, py - точки многоугольника
// m      - количество точек (схватов)
// k      - порядок кривой
// x      - узловой вектор
void build_knot(const int * px, const int * py, int m, int k, int * x) {
	int t = 1;
	for (int i(0); i < m + k; i++)
		if (i < k)
			x[i] = 0;
		else
			if (i < m)
				x[i] = t++;
			else 
				x[i] = t;
}