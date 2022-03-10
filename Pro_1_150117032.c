// Fatih Akgündüz 150117032

#include <stdio.h>

int count=0;
int ears=0;

void bunnyEars(int lines);

int main () {
	
	printf("Please enter the number of lines (n=):");
	
	int lines;
	
	scanf("%d",&lines);
	printf("\n");
	bunnyEars(lines);
	
}

void bunnyEars(int lines){
	
	if (count<=lines){
		if (count%2==0)
		ears+=3;
		
		if (count%2!=0)
		ears+=2;
		
		if (count==0)
		ears=0;
		
	
	printf("bunnyEars%d(%d) -> %d\n",lines,count,ears);
	
	count++;
	
	bunnyEars(lines);
	
	}
	if(count>lines){
	count=0;
	ears=0;
	}
}
