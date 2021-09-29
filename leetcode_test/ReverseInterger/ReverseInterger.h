#pragma once
int ReverseInterger(long long test) {
	long long tmp = 0;
	while (test != 0) {
		tmp = tmp * 10 + test % 10;
		test = test / 10;
	}
	if (tmp > pow(2,31) - 1 || tmp < -pow(2,31)){
//	if (tmp > 0x7fffffff || tmp < 0x80000000) {
		return 0;
	}
	return tmp;
}