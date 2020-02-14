#include<stdio.h>
#include<time.h>
#include<random>

int main(void)
{
	int n = 5;  //liczba rozdawanych kart
	int i, x, y, win=0, lose=0, s=0;
	time_t t;

	//pula kart i kolorow
	char kl[4] = {'p', 'k', 't', 'i'};
	char fg[13] = {'2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A'}; //32 33 34 35 36 37 38 39 30 4A 51 4B 41 
	char r1[5]={}, r2[5]={}, k1[5]={}, k2[5]={};
	//pamiec wylosowanych kart
	int kf[4][13] = {0}, l=0;	

	srand( time(&t));
	
	//losowanie pierwszej reki
	for(i=0; i<n; i++){
		x = rand()%12;
		y = rand()%3;
		if(kf[y][x] == 0){
			k1[i]=fg[x];
			k2[i]=kl[y];
			printf("  X ");
			kf[y][x] = 1;
		}
		else --i;
	}

	printf("\n\n\n");
	
	//losowanie drugiej reki
	for(i=0; i<n; i++){
		x = rand()%12;
		y = rand()%3;
		if(kf[y][x] == 0){
			r1[i]=fg[x];
			r2[i]=kl[y];
			printf(" %c%c ", fg[x], kl[y]);
			kf[y][x] = 1;			
		}
		else --i;
	}
	printf("\n");
	
	//wyci¹ganie kart z pamieci
	while(true){
		if((r1[0]!=0 && r2[0]!=0) || (r1[1]!=0 && r2[1]!=0) || (r1[2]!=0 && r2[2]!=0) || (r1[3]!=0 && r2[3]!=0) || (r1[4]!=0 && r2[4]!=0)){
		scanf_s("%d", &l);
		for(int i=0; i<5; i++)
			printf("  X ");

		switch(l){
		case 1: printf("\n\t %c%c", k1[3], k2[3]);
				printf("\n\t %c%c", r1[0], r2[0]);
				k1[3] = 0;
				k2[3] = 0;
				r1[0] = 0;
				r2[0] = 0;
				break;
		case 2: printf("\n\t %c%c", k1[1], k2[1]);
				printf("\n\t %c%c", r1[1], r2[1]);
				k1[1] = 0;
				k2[1] = 0;
				r1[1] = 0;
				r2[1] = 0;
				break;
		case 3: printf("\n\t %c%c", k1[4], k2[4]);
				printf("\n\t %c%c", r1[2], r2[2]);
				k1[4] = 0;
				k2[4] = 0;
				r1[2] = 0;
				r2[2] = 0;
				break;
		case 4: printf("\n\t %c%c", k1[2], k2[2]);
				printf("\n\t %c%c", r1[3], r2[3]);
				k1[2] = 0;
				k2[2] = 0;
				r1[3] = 0;
				r2[3] = 0;
				break;
		case 5: printf("\n\t %c%c", k1[0], k2[0]);
				printf("\n\t %c%c", r1[4], r2[4]);
				k1[0] = 0;
				k2[0] = 0;
				r1[4] = 0;
				r2[4] = 0;
				break;
		//case 9: system("cls"); break;
		default: printf("Zly wybor\n");
		}
		printf("\n");
		for(int i=0; i<5; i++)
			printf(" %c%c ", r1[i], r2[i]);
		for(int i=0; i<5; i++){
		if(k1[i]=='0') k1[i]='0'+10;
		if(r1[i]=='0') r1[i]='0'+10;
		if(k1[i]=='J') k1[i]=41;
		if(k1[i]=='J') k1[i]=41;
		if(k1[i]=='Q') k1[i]=42;
		if(r1[i]=='Q') r1[i]=42;
		if(k1[i]=='K') k1[i]=43;
		if(r1[i]=='K') r1[i]=43;
		if(k1[i]=='A') k1[i]=44;
		if(r1[i]=='A') r1[i]=44;
		}
			
			if(k1[s]>r1[s]){ ++lose; printf("lose");}
			else if(k1[s]==r1[s]) printf("remis");
			else{ ++win; printf("win");}

		s++;
		for(int i=0; i<5; i++){
		if(k1[i]=='0'+10) k1[i]='0';
		if(r1[i]=='0'+10) r1[i]='0';
		if(k1[i]==41) k1[i]='J';
		if(k1[i]==41) k1[i]='J';
		if(k1[i]==42) k1[i]='Q';
		if(r1[i]==42) r1[i]='Q';
		if(k1[i]==43) k1[i]='K';
		if(r1[i]==43) r1[i]='K';
		if(k1[i]==44) k1[i]='A';
		if(r1[i]==44) r1[i]='A';
		}
		}else break;
	}
	printf("\nWin: %d - %d Lose", win, lose);
	printf("\n\n");
	return 0;
}