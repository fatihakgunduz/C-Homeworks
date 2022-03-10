#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Math.h>
#define SIZE 10


	typedef struct MetroStation{
		
		char name[20];
		double x;
		double y;
		
	}MetroStation;
	
	typedef struct MetroLine{
		
		char color[20];
		MetroStation MetroStations[SIZE];
		
		
	}MetroLine;
	
	typedef struct MetroSystem{
		
		char name[20];
		MetroLine MetroLines[SIZE];
		
	}MetroSystem;



int equals(MetroStation s1, MetroStation s2);

void addStation(MetroLine *mL, MetroStation mS);

int hasStation(MetroLine mL, MetroStation mS);

MetroStation getFirstStop(MetroLine mL);

MetroStation getPriorStop(MetroLine mL, MetroStation mS);

MetroStation getNextStop(MetroLine mL, MetroStation mS);

void addLine(MetroSystem *mSys, MetroLine mS);

void printLine(MetroLine mL);

void printPath(MetroStation mS[]);

double getDistanceTravelled(MetroStation mS[]);

MetroStation findNearestStation(MetroSystem mSys, double x, double y);

MetroStation getNeighboringStations(MetroSystem mSys, MetroStation mS, MetroStation neighboringStations[]);

void findPath(MetroStation start, MetroStation finish, MetroStation path[]);

void recursiveFindPath(MetroStation start, MetroStation finish, MetroStation partialPath[],MetroStation bestPath[]);


//Declare a MetroSystem with the name of istanbul and an empty content.
MetroSystem istanbul = {"istanbul", '\0'};

int main()
{
	
	int i;
	double myX=1, myY=2; 
	double goalX=62, goalY=45; 
	
	// define 3 metro lines, 9 metro stations, and an empty myPath
	MetroLine red={'\0'}, blue={'\0'}, green={'\0'};
	MetroStation s1, s2, s3, s4, s5, s6, s7, s8, s9;
	MetroStation myPath[SIZE]={'\0'};
	
	strcpy(red.color, "red"); 
	strcpy(blue.color, "blue");
	strcpy(green.color, "green");

	
	strcpy(s1.name, "Haydarpasa"); 		s1.x=0; 	s1.y=0;
	strcpy(s2.name, "Sogutlucesme"); 	s2.x=10; 	s2.y=5;
	strcpy(s3.name, "Goztepe"); 		s3.x=20; 	s3.y=10;
	strcpy(s4.name, "Kozyatagi"); 		s4.x=30; 	s4.y=35;
	strcpy(s5.name, "Bostanci"); 		s5.x=45; 	s5.y=20;
	strcpy(s6.name, "Kartal"); 			s6.x=55; 	s6.y=20;
	strcpy(s7.name, "Samandira"); 		s7.x=60; 	s7.y=40;
	strcpy(s8.name, "Icmeler"); 		s8.x=70; 	s8.y=15;
	
	//Add several metro stations to the given metro lines.
	addStation(&red, s1); addStation(&red, s2); addStation(&red, s3); addStation(&red, s4); addStation(&red, s5); addStation(&red, s8);
	
	addStation(&blue, s2); addStation(&blue, s3); addStation(&blue, s4); addStation(&blue, s6); addStation(&blue, s7);
	
	addStation(&green, s2); addStation(&green, s3); addStation(&green, s5); addStation(&green, s6); addStation(&green, s8);
	
	// Add red, blue, green metro lines to the Istanbul metro system.
	addLine(&istanbul, red);
	addLine(&istanbul, blue);
	addLine(&istanbul, green);
	
	// print the content of the red, blue, green metro lines
	printLine(red);
	printLine(blue);
	printLine(green);
		
		
	// find the nearest stations to the current and target locations
	MetroStation nearMe = findNearestStation(istanbul, myX, myY);
	MetroStation nearGoal = findNearestStation(istanbul, goalX, goalY);

	printf("\n");
	
	printf("The best path from %s to %s is:\n", nearMe.name, nearGoal.name);
	
	// if the nearest current and target stations are the same, then print a message and exit.
	if(equals(nearMe, nearGoal)){
		printf("It is better to walk!\n");
		return 0;
	}
	
	// Calculate and print the myPath with the minimum distance travelled from start to target stations.
	findPath(nearMe, nearGoal, myPath);
	
	if(strlen(myPath[0].name) == 0)
		printf("There is no path on the metro!\n");
	else{
		printPath(myPath);
	}
	
	return 0;

}

int equals( MetroStation s1,  MetroStation s2){
	int a = 0;
 
   	while (s1.name[a] == s2.name[a]) {
      	if (s1.name[a] == '\0' || s2.name[a] == '\0')
         	break;
      	a++;
   	}
   
   	if (s1.name[a] == '\0' && s2.name[a] == '\0')
      	return 1;
  	 else
      	return 0;
}


void addStation( MetroLine *mL, MetroStation mS){
	int a=0;
	while(mL->MetroStations[a].name[0]!=0){
		a++;
	}
	mL->MetroStations[a]=mS;
	
}


int hasStation(MetroLine mL, MetroStation mS){
	int a=0;
	while(mL.MetroStations[a].name[0]!=0){
		
		if(equals(mL.MetroStations[a],mS)){
			return 1;
		}
		
		else{
			return 0;		
		}
		
		a++;
	}

}


MetroStation getFirstStop(MetroLine mL){
	
	if(mL.MetroStations[0].name[0]!=0){
		return mL.MetroStations[0];
	}
	
	else{
		MetroStation empty;
		return empty;
	}
}


MetroStation getPriorStop(MetroLine mL, MetroStation mS){
	int a =0;
	while(equals(mL.MetroStations[a],mS)!=0){
		a++;
	} 
	
	if(a-1>0){
		return mL.MetroStations[a-1];
	}
	else{
		return mL.MetroStations[a];
	}
	
	
}


MetroStation getNextStop(MetroLine mL, MetroStation mS){
	int length=0;
	while(mL.MetroStations[length].name[0]!=0){
		length++;
	}
	int a =0;
	while(equals(mL.MetroStations[a],mS)!=0){
		a++;
	} 
	
	if(a+1<=length){
		return mL.MetroStations[a+1];
	}
	else{
		MetroStation emptyN;
		return emptyN;
	}
	
}


void addLine(MetroSystem *mSys, MetroLine mL){
	int a=0;
	while(mSys->MetroLines[a].color[0]!=0){
		a++;
	}
	mSys->MetroLines[a]=mL;
	
}


void printLine(MetroLine mL){
	int a=0;
		
		printf("Metroline %s:  ",mL.color);
		
		while(mL.MetroStations[a].name[0]!=0){
			printf("%s, ",mL.MetroStations[a].name);
			a++;
		}
		printf("\n");

}


void printPath(MetroStation mS[]){
	int length=sizeof(mS)/sizeof(5);
	int a =0;
	while(a<=length){
		printf("%s",mS);
	}
}


double getDistanceTravelled(MetroStation mS[]){
	int length=0;
	while(mS[length].name[0]!=0){
		length++;
	}
	int a = 0;
	double distance;
	if(length>2){	
		for(a=0;a<length-1;a++){
			double x1=mS[a].x , y1= mS[a].y;
			double x2=mS[a+1].x , y2= mS[a+1].y; 
			distance += sqrt(pow((x2-x1),2)+pow((y2-y1),2));
		}
		return distance;
	}
	else{
		return 0;
	}
}


MetroStation findNearestStation(MetroSystem mSys, double x, double y){
	int length=0;
	while(mSys.MetroLines[length].color[0]!=0){
		length++;
	}
	int b=0;
	int a=0;
	double distance1;
	
	do{
		
	a=0;
	int x=mSys.MetroLines[b].MetroStations[a].x;
	int y=mSys.MetroLines[b].MetroStations[a].y;
	
	double distance=sqrt(pow((x-x),2)+pow((y-y),2));
	do{
		
		++a;
		int x1=mSys.MetroLines[b].MetroStations[a].x;
		int y1=mSys.MetroLines[b].MetroStations[a].y;
		distance1=sqrt(pow((x-x1),2)+pow((y-y1),2));
		
	}while(distance1<=distance);
	b++;	
	
}while(b<length);
	
	return mSys.MetroLines[b].MetroStations[a];
}

MetroStation getNeighboringStations(MetroSystem mSys, MetroStation mS, MetroStation neighboringStations[]){
	int length= sizeof(mSys.MetroLines)/sizeof(int);
	int a=0;
	int b=0;
	neighboringStations[b++]=mS;
	for(a=0;a<length;a++){
		if(hasStation(mSys.MetroLines[length],mS)){
			neighboringStations[b++]=getPriorStop(mSys.MetroLines[length],mS);
			neighboringStations[b++]=getNextStop(mSys.MetroLines[length],mS);
			
		}
	}
}

void findPath(MetroStation start, MetroStation finish, MetroStation path[]){
	MetroStation partialPath[SIZE];
	recursiveFindPath(start,finish,path,partialPath);
}

void recursiveFindPath( MetroStation start, MetroStation finish, MetroStation partialPath[],MetroStation bestPath[]){
	
}








