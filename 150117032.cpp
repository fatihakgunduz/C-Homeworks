#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SAT(int arr[], int n,int array[],int clauses){

	int sat[clauses][1]={0}; 
	
	int j=0;
    
	for (int i = 0; i < n*clauses; i++)  {

		if(i!=0&&i%n==0)
			j++;

		if(arr[i%n]==1&&array[i]>0)
			sat[j][0]=1;
		
		if(arr[i%n]==0&&array[i]<0)
			sat[j][0]=1;

    } 
    
    int solution=1;
    
    for(int i=0;i<clauses;i++){

    	solution*=sat[i][0];
	}
	
	if(solution==1){
		printf("SAT\n");
		for(int i=1;i<=n;i++){
			
			if(arr[i-1]==1)
				printf("%d ",i);
			
			else
				printf("-%d ",i);
			
		}
		exit(0);
	}

} 

void generateAll(int n, int arr[], int i,int array[],int clauses){
 
    if (i == n) { 
    
        SAT(arr, n,array,clauses); 
        return; 
    } 
  
    // First assign "0" at ith position 
    // and try for all other permutations 
    // for remaining positions 
    arr[i] = 0; 
    generateAll(n, arr, i + 1,array,clauses); 
  
    // And then assign "1" at ith position 
    // and try for all other permutations 
    // for remaining positions 
    arr[i] = 1; 
    generateAll(n, arr, i + 1,array,clauses); 
} 

int main(){

	FILE *cnf=fopen("input.cnf","r");

	if ((cnf = fopen("input.cnf", "r")) == NULL) {

	        printf("Error! opening file");
	        exit(1);
	
	}
	
	char *ch=(char *)malloc(sizeof(char));
	char *c=(char *)malloc(sizeof(char));
	
	do {
	
		fscanf(cnf,"%s",ch);
	
	}while(strcmp(ch,"cnf"));
	
	fscanf(cnf,"%s",ch);
	fscanf(cnf,"%s",c);
	
	int variables=atoi(ch),clauses=atoi(c);
	
	int array[variables*clauses];
	
	if(clauses==0){
		printf("There is no clauses!!!");
		exit(0);
	}
	
	int a=0;

	while (!feof(cnf)){
		
		fscanf(cnf,"%s",ch);
			
		int number=atoi(ch);
		
		if(number!=0){
	
			while((a%3+1)!=abs(number)){
			
				array[a]=0;
				a++;
			}
		
			array[a]=number;
		
			a++;
		}
		
		else if (number==0&&a%3!=0){
			
			while(a%3!=2){
				array[a]=0;
				a++;
			}
		}
		
	}
	
	fclose(cnf);
	
	int arr[variables];

	generateAll(variables,arr,0,array,clauses);
	
	printf("UNSAT");
	
	printf("\n\n");
	
	printf("end of code");
	
}


