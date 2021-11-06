#include <stdio.h>

int main () {
	int n, hr, min, sec;
	printf("Enter seconds: ");
	scanf("%d", &n);
	
	//statement to call split_time
	split_time(n, &hr, &min, &sec);
	
	printf("Converted format: %d hour %d mins %d secs \n", hr, min, sec);
	//statements calculating hr, min, and sec
	return 0;
}

void split_time (long total_sec, int *hr, int *min, int *sec) {
	//statement to calculate hr, min, and sec
	total_sec = total_sec % (60 * 60);
	*hr = (int)(total_sec / (60 * 60));
	*min = (int)(total_sec / 60);
	*sec = (total_sec % 60);
}