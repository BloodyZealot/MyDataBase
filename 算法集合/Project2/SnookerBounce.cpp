#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
	double L, W, x, y, R, a, v, s;
	double speedx, speedy;
	int bouncex, bouncey;
	while (cin >> L >> W >> x >> y >> R >> a >> v >> s)
	{
		if (L == 0)
			return 0;
		a = a /180*3.14;
		W -= 2* R; L -= 2 * R;
		x -= R; y -= R;
		speedx = cos(a)*v;
		speedy = sin(a)*v;
		x += speedx*s;
		y += speedy*s;
		bouncex = x / L;
		bouncey = y / W;
		if (x < 0)
		{
			x -= bouncex*L;
			if (bouncex % 2 == 0)
				x = -x;
			else
				x = L + x;
		}
		else
		{
			x -= bouncex*L;
			if (bouncex % 2 != 0)
				x = L - x;
		}
		if (y < 0)
		{
			y -= bouncey*W;
			if (bouncey % 2 == 0)
				y = -y;
			else
				y = W + y;
		}
		else
		{
			y -= bouncey*W;
			if (bouncey % 2 != 0)
				y = W - y;
		}
		cout << setiosflags(ios::fixed) << setprecision(2) << x+R << ' ' << y+R << endl;
	}
}