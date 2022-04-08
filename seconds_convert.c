#include <stdio.h>
/*
convert a given integer (in seconds) to hours, minutes and seconds.
*/
int main() {
	int sec=9000, h, m, s;
    h = (sec/3600);
	m = (sec -(3600*h))/60;
	s = (sec -(3600*h)-(m*60));
	printf("H:M:S - %d:%d:%d\n",h,m,s);
	return 0;
}
