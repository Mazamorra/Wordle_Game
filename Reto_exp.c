#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int RandomAhora();
void ImprimirTeclado(int Abecedario[][2]);
void ImprimirLetra(int ascii[]);
void ImprimirLetra_2(int ascii[], int fin);
void Vacio(int lineas_vacias);
int PalabraReal(char word[]);

int main(){
	
	FILE *text;
	text = fopen("palabras5.txt", "r");
	
	int wanted_line = 3200; 
	int actual_line = 0;
	int lives = 6;
	int temp_lives = lives;
	
	int letras = 5;
	int n = letras;
	
	char palabras_lista[3200][6] = {0};
	
	char attempt[128];

	char word[128]; 
	
	char* buff;
	
	int ready = 1;
	
	int abc=0;
	int opq=0;

	int Abecedario[26][2];
	int palabra_aceptada = 1;
	
	int flag[5] = {0, 0, 0, 0, 0};
	
	int temp[5] = {0, 0, 0, 0, 0};
	
	char tried[6][128];
	
	int tried_data[6][5] =  {{5, 5, 5, 5, 5},
							{5, 5, 5, 5, 5},
							{5, 5, 5, 5, 5},
							{5, 5, 5, 5, 5},
							{5, 5, 5, 5, 5},
							{5, 5, 5, 5, 5}};					
							
	int palabra_azar = 0;
	
	for(abc=0; abc<=25; abc++){
		Abecedario[abc][0] = abc+65;
		Abecedario[abc][1] = 0;
	}
	
	while(ready){
		
		while(actual_line != wanted_line){
			
			if (!fgets(word, sizeof word, text)) break;
   			//printf("Line contains");
    		buff = word;
    		while (1) {
    			if (*buff == '\n' || *buff == '\0') break;
    			sscanf(word, "%s", buff);
				//printf(" %s", word);
				break;
    		}
    		
    		if((word[0] == '\0' || word[1] == '\0' || word[2] == '\0' || word[3] == '\0' || word[4] == '\0') || word[5] != '\0'){
				//wanted_line = RandomAhora() % 366; 
				//actual_line = 0;
				ready = 1;
			
			}else{
				
				if(PalabraReal(word)){
					ready = 0;

					palabras_lista[actual_line][0] = word[0] - 32;
					palabras_lista[actual_line][1] = word[1] - 32;
					palabras_lista[actual_line][2] = word[2] - 32;
					palabras_lista[actual_line][3] = word[3] - 32;
					palabras_lista[actual_line][4] = word[4] - 32;
				
					actual_line++;
				}	
				
			}
    		
		}

	}
	
	palabra_azar = RandomAhora() % wanted_line;	
	
	word[0] = palabras_lista[palabra_azar][0];
	
	fclose(text);

	palabra_azar = RandomAhora() % wanted_line;	
	
	word[0] = palabras_lista[palabra_azar][0];
	word[1] = palabras_lista[palabra_azar][1];
	word[2] = palabras_lista[palabra_azar][2];
	word[3] = palabras_lista[palabra_azar][3];
	word[4] = palabras_lista[palabra_azar][4];
	
	//printf("%s\n", word);
	//printf("%d\n", wanted_line);

	while(lives > 0){

		//printf("%d", n);
		n = letras;	
		
		while(palabra_aceptada){
			
			scanf("%s", attempt);
	
			if((attempt[0] == '\0' || attempt[1] == '\0' || attempt[2] == '\0' || attempt[3] == '\0' || attempt[4] == '\0') || attempt[5] != '\0'){
				palabra_aceptada = 1;
				printf("Write a valid word\n");
			}else{
				palabra_aceptada = 0;
			}
					
		}
		
		palabra_aceptada = 1;
		
		tried[lives-1][0] = attempt[0];
		tried[lives-1][1] = attempt[1];	
		tried[lives-1][2] = attempt[2];	
		tried[lives-1][3] = attempt[3];	
		tried[lives-1][4] = attempt[4];	
		
		if(attempt[0] == word[0]){
			Abecedario[attempt[0]-65][1] = 1;
			flag[0] = 1;
			tried_data[lives-1][0]= 1;
		}else if(attempt[0] == word[1] || attempt[0] == word[2] || attempt[0] == word[3] || attempt[0] == word[4]){
			Abecedario[attempt[0]-65][1] = 2;
			flag[0] = 2;
			tried_data[lives-1][0]= 2;
		}else{
			Abecedario[attempt[0]-65][1] = 3;
			flag[0] = 3;
			tried_data[lives-1][0]= 3;
		}

		
		if(attempt[1] == word[1]){
			Abecedario[attempt[1]-65][1] = 1;	
			flag[1] = 1;
			tried_data[lives-1][1]= 1;
		}else if(attempt[1] == word[0] || attempt[1] == word[2] || attempt[1] == word[3] || attempt[1] == word[4]){
			Abecedario[attempt[1]-65][1] = 2;
			flag[1] = 2;
			tried_data[lives-1][1]= 2;
		}else{
			Abecedario[attempt[1]-65][1] = 3;
			flag[1] = 3;
			tried_data[lives-1][1]= 3;
		}
		
		if(attempt[2] == word[2]){
			Abecedario[attempt[2]-65][1] = 1;	
			flag[2] = 1;
			tried_data[lives-1][2]= 1;
		}else if(attempt[2] == word[1] || attempt[2] == word[0] || attempt[2] == word[3] || attempt[2] == word[4]){
			Abecedario[attempt[2]-65][1] = 2;
			flag[2] = 2;
			tried_data[lives-1][2]= 2;
		}else{
			Abecedario[attempt[2]-65][1] = 3;
			flag[2] = 3;
			tried_data[lives-1][2]= 3;
		}
		
		if(attempt[3] == word[3]){
			Abecedario[attempt[3]-65][1] = 1;	
			flag[3] = 1;
			tried_data[lives-1][3]= 1;
		}else if(attempt[3] == word[1] || attempt[3] == word[2] || attempt[3] == word[0] || attempt[3] == word[4]){
			Abecedario[attempt[3]-65][1] = 2;
			flag[3] = 2;
			tried_data[lives-1][3]= 2;
		}else{
			Abecedario[attempt[3]-65][1] = 3;
			flag[3] = 3;
			tried_data[lives-1][3]= 3;
		}
		
		if(attempt[4] == word[4]){
			Abecedario[attempt[4]-65][1] = 1;	
			flag[4] = 1;
			tried_data[lives-1][4]= 1;
		}else if(attempt[4] == word[1] || attempt[4] == word[2] || attempt[4] == word[3] || attempt[4] == word[0]){
			Abecedario[attempt[4]-65][1] = 2;
			flag[4] = 2;
			tried_data[lives-1][4]= 2;
		}else{
			Abecedario[attempt[4]-65][1] = 3;
			flag[4] = 3;
			tried_data[lives-1][4]= 3;
		}
		
		temp_lives = 7-lives;
		lives--;
		
		while(n>=0){
			if(tried_data[n][0] == 1 && tried_data[n][1] == 1 && tried_data[n][2] == 1 && tried_data[n][3] == 1 && tried_data[n][4] == 1){
				lives = 0;
			}
			n--;
		}
		n= 5;
	
	//	do{
			
		system("cls");
			
	//	while(temp_lives!= 0){
		
		if(lives == 5){
			
			while(n>=0){
				printf("+");
				if(n!=0){
					printf("---");
				}else{
					printf("\n");
				}
				n--;		
			}	
			n = 5;	
		}
		
		if (tried_data[4][0] != 5){
			while(n>=0){
				printf("+");
				if(n!=0){
					printf("---");
				}else{
					printf("\n");
				}
				n--;		
			}	
			n = 5;
		
			temp[0] = Abecedario[tried[5][0]-65][1];
			if(tried_data[5][0]==1){
				Abecedario[tried[5][0]-65][1] = 1;
			}else if(tried_data[5][0] == 2){
				Abecedario[tried[5][0]-65][1] = 2;
			}else if(tried_data[5][0] == 3){
				Abecedario[tried[5][0]-65][1] = 3;
			}
			
			ImprimirLetra_2(Abecedario[tried[5][0] - 65], 0);
			
			temp[1] = Abecedario[tried[5][1]-65][1];
			if(tried_data[5][1]==1){
				Abecedario[tried[5][1]-65][1] = 1;
			}else if(tried_data[5][1] == 2){
				Abecedario[tried[5][1]-65][1] = 2;
			}else if(tried_data[5][1] == 3){
				Abecedario[tried[5][1]-65][1] = 3;
			}
			
			ImprimirLetra_2(Abecedario[tried[5][1] - 65], 0);
			
			temp[2] = Abecedario[tried[5][2]-65][1];
			if(tried_data[5][2]==1){
				Abecedario[tried[5][2]-65][1] = 1;
			}else if(tried_data[5][2] == 2){
				Abecedario[tried[5][2]-65][1] = 2;
			}else if(tried_data[5][2] == 3){
				Abecedario[tried[5][2]-65][1] = 3;
			}
			
			ImprimirLetra_2(Abecedario[tried[5][2] - 65], 0);
			
			temp[3] = Abecedario[tried[5][3]-65][1];
			if(tried_data[5][3]==1){
				Abecedario[tried[5][3]-65][1] = 1;
			}else if(tried_data[5][3] == 2){
				Abecedario[tried[5][3]-65][1] = 2;
			}else if(tried_data[5][3] == 3){
				Abecedario[tried[5][3]-65][1] = 3;
			}
			
			ImprimirLetra_2(Abecedario[tried[5][3] - 65], 0);
			
			temp[4] = Abecedario[tried[5][4]-65][1];
			if(tried_data[5][4]==1){
				Abecedario[tried[5][4]-65][1] = 1;
			}else if(tried_data[5][4] == 2){
				Abecedario[tried[5][4]-65][1] = 2;
			}else if(tried_data[5][4] == 3){
				Abecedario[tried[5][4]-65][1] = 3;
			}
			
			ImprimirLetra_2(Abecedario[tried[5][4] - 65], 1);
			
			
			while(n>=0){
					printf("+");
					if(n!=0){
						printf("---");
					}else{
						printf("\n");
					}
				n--;		
				}
				
				n = 5;
		} 
		if (tried_data[3][0] != 5){
		/*	ImprimirLetra_2(Abecedario[tried[4][0] - 65], 0);
			ImprimirLetra_2(Abecedario[tried[4][1] - 65], 0);
			ImprimirLetra_2(Abecedario[tried[4][2] - 65], 0);
			ImprimirLetra_2(Abecedario[tried[4][3] - 65], 0);
			ImprimirLetra_2(Abecedario[tried[4][4] - 65], 1);*/
			
				temp[0] = Abecedario[tried[4][0]-65][1];
			if(tried_data[4][0]==1){
				Abecedario[tried[4][0]-65][1] = 1;
			}else if(tried_data[4][0] == 2){
				Abecedario[tried[4][0]-65][1] = 2;
			}else if(tried_data[4][0] == 3){
				Abecedario[tried[4][0]-65][1] = 3;
			}
			
			ImprimirLetra_2(Abecedario[tried[4][0] - 65], 0);
			
			temp[1] = Abecedario[tried[4][1]-65][1];
			if(tried_data[4][1]==1){
				Abecedario[tried[4][1]-65][1] = 1;
			}else if(tried_data[4][1] == 2){
				Abecedario[tried[4][1]-65][1] = 2;
			}else if(tried_data[4][1] == 3){
				Abecedario[tried[4][1]-65][1] = 3;
			}
			
			ImprimirLetra_2(Abecedario[tried[4][1] - 65], 0);
			
			temp[2] = Abecedario[tried[4][2]-65][1];
			if(tried_data[4][2]==1){
				Abecedario[tried[4][2]-65][1] = 1;
			}else if(tried_data[4][2] == 2){
				Abecedario[tried[4][2]-65][1] = 2;
			}else if(tried_data[4][2] == 3){
				Abecedario[tried[4][2]-65][1] = 3;
			}
			
			ImprimirLetra_2(Abecedario[tried[4][2] - 65], 0);
			
			temp[3] = Abecedario[tried[4][3]-65][1];
			if(tried_data[4][3]==1){
				Abecedario[tried[4][3]-65][1] = 1;
			}else if(tried_data[4][3] == 2){
				Abecedario[tried[4][3]-65][1] = 2;
			}else if(tried_data[4][3] == 3){
				Abecedario[tried[4][3]-65][1] = 3;
			}
			
			ImprimirLetra_2(Abecedario[tried[4][3] - 65], 0);
			
			temp[4] = Abecedario[tried[4][4]-65][1];
			if(tried_data[4][4]==1){
				Abecedario[tried[4][4]-65][1] = 1;
			}else if(tried_data[4][4] == 2){
				Abecedario[tried[4][4]-65][1] = 2;
			}else if(tried_data[4][4] == 3){
				Abecedario[tried[4][4]-65][1] = 3;
			}
			
			ImprimirLetra_2(Abecedario[tried[4][4] - 65], 1);
			
			while(n>=0){
					printf("+");
					if(n!=0){
						printf("---");
					}else{
						printf("\n");
					}
				n--;		
				}
				
				n = 5;
			
		}
		if (tried_data[2][0] != 5){
		/*	ImprimirLetra_2(Abecedario[tried[3][0] - 65], 0);
			ImprimirLetra_2(Abecedario[tried[3][1] - 65], 0);
			ImprimirLetra_2(Abecedario[tried[3][2] - 65], 0);
			ImprimirLetra_2(Abecedario[tried[3][3] - 65], 0);
			ImprimirLetra_2(Abecedario[tried[3][4] - 65], 1);*/
			
			temp[0] = Abecedario[tried[3][0]-65][1];
			if(tried_data[3][0]==1){
				Abecedario[tried[3][0]-65][1] = 1;
			}else if(tried_data[3][0] == 2){
				Abecedario[tried[3][0]-65][1] = 2;
			}else if(tried_data[3][0] == 3){
				Abecedario[tried[3][0]-65][1] = 3;
			}
			
			ImprimirLetra_2(Abecedario[tried[3][0] - 65], 0);
			
			temp[1] = Abecedario[tried[3][1]-65][1];
			if(tried_data[3][1]==1){
				Abecedario[tried[3][1]-65][1] = 1;
			}else if(tried_data[3][1] == 2){
				Abecedario[tried[3][1]-65][1] = 2;
			}else if(tried_data[3][1] == 3){
				Abecedario[tried[3][1]-65][1] = 3;
			}
			
			ImprimirLetra_2(Abecedario[tried[3][1] - 65], 0);
			
			temp[2] = Abecedario[tried[3][2]-65][1];
			if(tried_data[3][2]==1){
				Abecedario[tried[3][2]-65][1] = 1;
			}else if(tried_data[3][2] == 2){
				Abecedario[tried[3][2]-65][1] = 2;
			}else if(tried_data[3][2] == 3){
				Abecedario[tried[3][2]-65][1] = 3;
			}
			
			ImprimirLetra_2(Abecedario[tried[3][2] - 65], 0);
			
			temp[3] = Abecedario[tried[3][3]-65][1];
			if(tried_data[3][3]==1){
				Abecedario[tried[3][3]-65][1] = 1;
			}else if(tried_data[3][3] == 2){
				Abecedario[tried[3][3]-65][1] = 2;
			}else if(tried_data[3][3] == 3){
				Abecedario[tried[3][3]-65][1] = 3;
			}
			
			ImprimirLetra_2(Abecedario[tried[3][3] - 65], 0);
			
			temp[4] = Abecedario[tried[3][4]-65][1];
			if(tried_data[3][4]==1){
				Abecedario[tried[3][4]-65][1] = 1;
			}else if(tried_data[3][4] == 2){
				Abecedario[tried[3][4]-65][1] = 2;
			}else if(tried_data[3][4] == 3){
				Abecedario[tried[3][4]-65][1] = 3;
			}
			
			ImprimirLetra_2(Abecedario[tried[3][4] - 65], 1);
			
			while(n>=0){
				printf("+");
				if(n!=0){
					printf("---");
				}else{
					printf("\n");
				}
				n--;		
			}
				
			n = 5;
			
		}
		if (tried_data[1][0] != 5){
		/*	ImprimirLetra_2(Abecedario[tried[2][0] - 65], 0);
			ImprimirLetra_2(Abecedario[tried[2][1] - 65], 0);
			ImprimirLetra_2(Abecedario[tried[2][2] - 65], 0);
			ImprimirLetra_2(Abecedario[tried[2][3] - 65], 0);
			ImprimirLetra_2(Abecedario[tried[2][4] - 65], 1);*/
			
				temp[0] = Abecedario[tried[2][0]-65][1];
			if(tried_data[2][0]==1){
				Abecedario[tried[2][0]-65][1] = 1;
			}else if(tried_data[2][0] == 2){
				Abecedario[tried[2][0]-65][1] = 2;
			}else if(tried_data[2][0] == 3){
				Abecedario[tried[2][0]-65][1] = 3;
			}
			
			ImprimirLetra_2(Abecedario[tried[2][0] - 65], 0);
			
			temp[1] = Abecedario[tried[2][1]-65][1];
			if(tried_data[2][1]==1){
				Abecedario[tried[2][1]-65][1] = 1;
			}else if(tried_data[2][1] == 2){
				Abecedario[tried[2][1]-65][1] = 2;
			}else if(tried_data[2][1] == 3){
				Abecedario[tried[2][1]-65][1] = 3;
			}
			
			ImprimirLetra_2(Abecedario[tried[2][1] - 65], 0);
			
			temp[2] = Abecedario[tried[2][2]-65][1];
			if(tried_data[2][2]==1){
				Abecedario[tried[2][2]-65][1] = 1;
			}else if(tried_data[2][2] == 2){
				Abecedario[tried[2][2]-65][1] = 2;
			}else if(tried_data[2][2] == 3){
				Abecedario[tried[2][2]-65][1] = 3;
			}
			
			ImprimirLetra_2(Abecedario[tried[2][2] - 65], 0);
			
			temp[3] = Abecedario[tried[2][3]-65][1];
			if(tried_data[2][3]==1){
				Abecedario[tried[2][3]-65][1] = 1;
			}else if(tried_data[2][3] == 2){
				Abecedario[tried[2][3]-65][1] = 2;
			}else if(tried_data[2][3] == 3){
				Abecedario[tried[2][3]-65][1] = 3;
			}
			
			ImprimirLetra_2(Abecedario[tried[2][3] - 65], 0);
			
			temp[4] = Abecedario[tried[2][4]-65][1];
			if(tried_data[2][4]==1){
				Abecedario[tried[2][4]-65][1] = 1;
			}else if(tried_data[2][4] == 2){
				Abecedario[tried[2][4]-65][1] = 2;
			}else if(tried_data[2][4] == 3){
				Abecedario[tried[2][4]-65][1] = 3;
			}
			
			ImprimirLetra_2(Abecedario[tried[2][4] - 65], 1);
			
			while(n>=0){
				printf("+");
				if(n!=0){
					printf("---");
				}else{
					printf("\n");
				}
				n--;		
			}
			n = 5;
		
		}
		if (tried_data[0][0] != 5){
		
		/*	ImprimirLetra_2(Abecedario[tried[1][0] - 65], 0);
			ImprimirLetra_2(Abecedario[tried[1][1] - 65], 0);
			ImprimirLetra_2(Abecedario[tried[1][2] - 65], 0);
			ImprimirLetra_2(Abecedario[tried[1][3] - 65], 0);
			ImprimirLetra_2(Abecedario[tried[1][4] - 65], 1);*/
			
			temp[0] = Abecedario[tried[1][0]-65][1];
			if(tried_data[1][0]==1){
				Abecedario[tried[1][0]-65][1] = 1;
			}else if(tried_data[1][0] == 2){
				Abecedario[tried[1][0]-65][1] = 2;
			}else if(tried_data[1][0] == 3){
				Abecedario[tried[1][0]-65][1] = 3;
			}
			
			ImprimirLetra_2(Abecedario[tried[1][0] - 65], 0);
			
			temp[1] = Abecedario[tried[1][1]-65][1];
			if(tried_data[1][1]==1){
				Abecedario[tried[1][1]-65][1] = 1;
			}else if(tried_data[1][1] == 2){
				Abecedario[tried[1][1]-65][1] = 2;
			}else if(tried_data[1][1] == 3){
				Abecedario[tried[1][1]-65][1] = 3;
			}
			
			ImprimirLetra_2(Abecedario[tried[1][1] - 65], 0);
			
			temp[2] = Abecedario[tried[1][2]-65][1];
			if(tried_data[1][2]==1){
				Abecedario[tried[1][2]-65][1] = 1;
			}else if(tried_data[1][2] == 2){
				Abecedario[tried[1][2]-65][1] = 2;
			}else if(tried_data[1][2] == 3){
				Abecedario[tried[1][2]-65][1] = 3;
			}
			
			ImprimirLetra_2(Abecedario[tried[1][2] - 65], 0);
			
			temp[3] = Abecedario[tried[1][3]-65][1];
			if(tried_data[1][3]==1){
				Abecedario[tried[1][3]-65][1] = 1;
			}else if(tried_data[1][3] == 2){
				Abecedario[tried[1][3]-65][1] = 2;
			}else if(tried_data[1][3] == 3){
				Abecedario[tried[1][3]-65][1] = 3;
			}
			
			ImprimirLetra_2(Abecedario[tried[1][3] - 65], 0);
			
			temp[4] = Abecedario[tried[1][4]-65][1];
			if(tried_data[1][4]==1){
				Abecedario[tried[1][4]-65][1] = 1;
			}else if(tried_data[1][4] == 2){
				Abecedario[tried[1][4]-65][1] = 2;
			}else if(tried_data[1][4] == 3){
				Abecedario[tried[1][4]-65][1] = 3;
			}
			
			ImprimirLetra_2(Abecedario[tried[1][4] - 65], 1);
			
			while(n>=0){
				printf("+");
				if(n!=0){
					printf("---");
				}else{
					printf("\n");
				}
				n--;		
			}	
			n = 5;	
		}

		temp[0] = Abecedario[tried[6-temp_lives][0]-65][1];
		if(tried_data[6-temp_lives][0]==1){
			Abecedario[tried[6-temp_lives][0]-65][1] = 1;
		}else if(tried_data[6-temp_lives][0] == 2){
			Abecedario[tried[6-temp_lives][0]-65][1] = 2;
		}else if(tried_data[6-temp_lives][0] == 3){
			Abecedario[tried[6-temp_lives][0]-65][1] = 3;
		}
		
		//ImprimirLetra_2(Abecedario[attempt[0] - 65], 0);
		ImprimirLetra_2(Abecedario[tried[6-temp_lives][0] - 65], 0);

		temp[1] = Abecedario[tried[6-temp_lives][1]-65][1];
		if(tried_data[6-temp_lives][1]==1){
			Abecedario[tried[6-temp_lives][1]-65][1] = 1;
		}else if(tried_data[6-temp_lives][1] == 2){
			Abecedario[tried[6-temp_lives][1]-65][1] = 2;
		}else if(tried_data[6-temp_lives][1] == 3){
			Abecedario[tried[6-temp_lives][1]-65][1] = 3;
		}
		
		//ImprimirLetra_2(Abecedario[attempt[1] - 65], 0);
		ImprimirLetra_2(Abecedario[tried[6-temp_lives][1] - 65], 0);
		
		temp[2] = Abecedario[tried[6-temp_lives][2]-65][1];
		if(tried_data[6-temp_lives][2]==1){
			Abecedario[tried[6-temp_lives][2]-65][1] = 1;
		}else if(tried_data[6-temp_lives][2] == 2){
			Abecedario[tried[6-temp_lives][2]-65][1] = 2;
		}else if(tried_data[6-temp_lives][2] == 3){
			Abecedario[tried[6-temp_lives][2]-65][1] = 3;
		}
		
		//ImprimirLetra_2(Abecedario[attempt[2] - 65], 0);
		ImprimirLetra_2(Abecedario[tried[6-temp_lives][2] - 65], 0);
		
		temp[3] = Abecedario[tried[6-temp_lives][3]-65][1];
		if(tried_data[6-temp_lives][3]==1){
			Abecedario[tried[6-temp_lives][3]-65][1] = 1;
		}else if(tried_data[6-temp_lives][3] == 2){
			Abecedario[tried[6-temp_lives][3]-65][1] = 2;
		}else if(tried_data[6-temp_lives][3] == 3){
			Abecedario[tried[6-temp_lives][3]-65][1] = 3;
		}
		
		//ImprimirLetra_2(Abecedario[attempt[3] - 65], 0);
		ImprimirLetra_2(Abecedario[tried[6-temp_lives][3] - 65], 0);
		
		//temp[4] = Abecedario[attempt[4]-65][1];
		temp[4] = Abecedario[tried[6-temp_lives][4]-65][1];
		if(tried_data[6-temp_lives][4]==1){
			Abecedario[tried[6-temp_lives][4] -65][1] = 1;
		}else if(tried_data[6-temp_lives][4] == 2){
			Abecedario[tried[6-temp_lives][4] -65][1] = 2;
		}else if(tried_data[6-temp_lives][4] == 3){
			Abecedario[tried[6-temp_lives][4]-65][1] = 3;
			//Abecedario[attempt[4]-65][1] = 3;
		}
		
		//ImprimirLetra_2(Abecedario[attempt[4] - 65], 1);
		ImprimirLetra_2(Abecedario[tried[6-temp_lives][4] - 65], 1);

		/*
		Abecedario[tried[6-temp_lives][0]-65][1] = temp[0];
		Abecedario[tried[6-temp_lives][1]-65][1] = temp[1];
		Abecedario[tried[6-temp_lives][2]-65][1] = temp[2];
		Abecedario[tried[6-temp_lives][3]-65][1] = temp[3];
		Abecedario[tried[6-temp_lives][4]-65][1] = temp[4];*/
		//Abecedario[attempt[4]-65][1] = temp[4];
		
		if(tried_data[4][0] == 5){
			Vacio(5);
		}else if (tried_data[3][0] == 5){
			Vacio(4);
		}else if (tried_data[2][0] == 5){
			Vacio(3);		
		}else if (tried_data[1][0] == 5){
			Vacio(2);
		}else if (tried_data[0][0] == 5){
			Vacio(1);
		}

		for(abc=0; abc<=6; abc++){
			for(opq=0; opq<=5; opq++){
				if(tried_data[abc][opq]==0)
					Abecedario[tried[abc][opq]-65][1] = 0;	
			}
		}
		for(abc=0; abc<=6; abc++){
			for(opq=0; opq<=5; opq++){
				if(tried_data[abc][opq]==3)
					Abecedario[tried[abc][opq]-65][1] = 3;	
			}
		}
		for(abc=0; abc<=6; abc++){
			for(opq=0; opq<=5; opq++){
				if(tried_data[abc][opq]==2)
					Abecedario[tried[abc][opq]-65][1] = 2;	
			}
		}
		for(abc=0; abc<=6; abc++){
			for(opq=0; opq<=5; opq++){
				if(tried_data[abc][opq]==1)
					Abecedario[tried[abc][opq]-65][1] = 1;	
			}
		}
			
		temp_lives--;
				
		while(n>=0){
			printf("+");
			if(n!=0){
				printf("---");
			}else{
				printf("\n");
			}
			n--;		
		}
				
		n = 5;

		ImprimirTeclado(Abecedario);

//		}while(0);
		//printf("%d\n", lives);
		//printf("%s\n", word);
		//printf("%s\n", attempt);
		/*printf("%c\n", word[1]);
		printf("%c\n", word[2]);
		printf("%c\n", word[3]);
		printf("%c\n", word[4]);*/
	}
	
	if(lives==0){
		printf("\nThe word was: %s\n", word);
		/*printf("%s\n", tried[5]);
		printf("%s\n", tried[4]);
		printf("%s\n", tried[3]);
		printf("%s\n", tried[2]);
		printf("%s\n", tried[1]);
		printf("%s\n", tried[0]);*/
	}
	
	return 0;
	
}

int RandomAhora(){
	
	unsigned seed = time(0);
	srand(seed);
	return rand();
		
}

void ImprimirTeclado(int Abecedario[][2]){
	
	printf("\n");
	ImprimirLetra(Abecedario['Q' - 65]);
	ImprimirLetra(Abecedario['W' - 65]);
	ImprimirLetra(Abecedario['E' - 65]);
	ImprimirLetra(Abecedario['R' - 65]);
	ImprimirLetra(Abecedario['T' - 65]);
	ImprimirLetra(Abecedario['Y' - 65]);
	ImprimirLetra(Abecedario['U' - 65]);
	ImprimirLetra(Abecedario['I' - 65]);
	ImprimirLetra(Abecedario['O' - 65]);
	ImprimirLetra(Abecedario['P' - 65]);
	ImprimirLetra(Abecedario['A' - 65]);
	ImprimirLetra(Abecedario['S' - 65]);
	ImprimirLetra(Abecedario['D' - 65]);
	ImprimirLetra(Abecedario['F' - 65]);
	ImprimirLetra(Abecedario['G' - 65]);
	ImprimirLetra(Abecedario['H' - 65]);
	ImprimirLetra(Abecedario['J' - 65]);
	ImprimirLetra(Abecedario['K' - 65]);
	ImprimirLetra(Abecedario['L' - 65]);
	printf("[ Ñ ]\n");
	printf("        ");
	ImprimirLetra(Abecedario['Z' - 65]);
	ImprimirLetra(Abecedario['X' - 65]);
	ImprimirLetra(Abecedario['C' - 65]);
	ImprimirLetra(Abecedario['V' - 65]);
	ImprimirLetra(Abecedario['B' - 65]);
	ImprimirLetra(Abecedario['N' - 65]);
	ImprimirLetra(Abecedario['M' - 65]);
	printf("\n");
}

void ImprimirLetra(int ascii[]){
	
	switch(ascii[1]){
		
		case 0:
			printf("[ %c ]", ascii[0]);
			break;
		case 1:
			printf("[=%c=]", ascii[0]);
			break;
		case 2:
			printf("[<%c>]", ascii[0]);
			break;
		case 3:
			printf("[>%c<]", ascii[0]);
			break;
	}
	
	if(ascii[0] == 80){
		printf("\n");
	}
		
}

void ImprimirLetra_2(int ascii[], int fin){
	
	switch(ascii[1]){
		
		case 0:
			printf("| %c ", ascii[0]);
			break;
		case 1:
			printf("|=%c=", ascii[0]);
			break;
		case 2:
			printf("|<%c>", ascii[0]);
			break;
		case 3:
			printf("|>%c<", ascii[0]);
			break;
		
	}
	
	if(fin){
		printf("|\n");
	}
		
}

void Vacio(int lineas_vacias){
	
	int n= 5;
	
	while(lineas_vacias){
		
		while(n>=0){
			printf("+");
			if(n!=0){
				printf("---");
			}else{
				printf("\n");
			}
			n--;		
		}
		n = 5;
		
		printf("|   ");
		printf("|   ");
		printf("|   ");
		printf("|   ");
		printf("|   ");
		printf("|\n");
	
		lineas_vacias--;
	}
	/*
	while(n>=0){
			printf("+");
			if(n!=0){
				printf("---");
			}else{
				printf("\n");
			}
			n--;		
		}
		n = 5;
	*/
}

int PalabraReal(char word[]){
	
	int nugget = 65;
	int lyrics = 0;
	int yes = 0;
	
	
	while(lyrics <= 4){
		while(nugget<=90){
			if(word[lyrics]-32 == nugget){		
				yes++;
			}
			nugget++;	
		}
		nugget = 0;	
	lyrics ++;
	}
	
	if(yes == 5){
		return 1;
	}else{
		return 0;
	}
	
}

