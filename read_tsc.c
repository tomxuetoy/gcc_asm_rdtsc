#include <stdio.h>

main()
{
	unsigned int low, high, old, new;
	while(1){
		asm volatile("rdtsc" : "=a"(low), "=d"(high));
		old = low;
		printf("low=%u\thigh=%u\n",low,high);

		sleep(1);
		
		asm volatile("rdtsc" : "=a"(low), "=d"(high));
		new = low;
		printf("The CPU freq is %fHz\n", (new-old)/1000000000.0);
	}
}
