#pragma once
namespace Pow {
	float Pow(float x, int n) {
		if (n == 0)
			return 1;
		if (n == 1)
			return x;
		if (n < 0) {
			x = 1.0 / x;
			n = -n;
		}

		float tmp = Pow(x, n / 2);
		if (n % 2 == 0) {
			return tmp * tmp;
		}
		return tmp * tmp * x;
	}
}