// Fatih Akgündüz 150117032

#include <stdio.h>

void superDigit(int a,int b);
int count=0;
int main(){
	
	int n,k;
	
	printf("Please enter a number (n=) :");
	scanf("%d",&n);
	
	printf("\nPlease enter repetition factor (k=):");
	scanf("%d",&k);
	
	superDigit(n,k);
}

void superDigit(int a,int b){
	
	int kalan=0;
	
	while(a>0){
		
	kalan+=(a%10);
	a/=10;	
	}
	
	if(b!=0||count==0)
	kalan*=b;
	count++;
	
	if(kalan<10)
	printf("super_digit = %d",kalan);
	
	if(kalan>=10) {
	
	superDigit(kalan,0);
	}
}
