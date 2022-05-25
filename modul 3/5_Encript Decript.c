#include <stdio.h>
#include <stdlib.h>
//deklarasi fungsi
int enkripsi();
int dekripsi();
void header();
void reinpt();
void rangeVldIntMenu();
void rangeVldIntKey();
void rangeVldIntReinp();

int main(){
	int input;
    fflush(stdin);
	header();
	printf("\n\t\t\tPilih operasi yang diinginkan:     \n");
	printf("\t\t\t[1] Enkripsi                         \n");
	printf("\t\t\t[2] Dekripsi                         \n");
	printf("\t\t\t[0] Keluar                         \n");
	rangeVldIntMenu(&input, "\n\t\t\tMasukkan pilihan anda : ");

	header();
	switch(input){
		//memilih fungsi berdasarkan inputan
        case 1:
            enkripsi();
        	break;
        case 2:
            dekripsi();
            break;
        case 0:
            exit(0);
    }
    reinpt();
	return(0);
}


int enkripsi(){
	char s[100];
	int i, key;
	printf("\n\t\t\tMasukan pesan yang akan di-enkripsi : ");
	gets(s);
	rangeVldIntKey(&key, "\n\t\t\tMasukan jumlah pergeseran : ");
	//blok kode enkripsi alphabet kapital
	for(i = 0; s[i] != '\0'; ++i){
		if(s[i] >= 'A' && s[i] <= 'Z') {
        	s[i] = s[i] + 32;
      	}
    //blok kode enkripsi alphabet kecil
		if(s[i] >= 'a' && s[i] <= 'z'){
			s[i] = s[i] + key;
			if(s[i] > 'z'){
				s[i] = s[i] - 26;
			}
			s[i] = s[i] -32;
		}
	}

	printf("\n\t\t\tHasil Enkripsi : %s", s);
	return 0;
}

int dekripsi(){
	char s[100];
	int i, key;
	printf("\n\t\t\tMasukan Pesan yang akan di-dekripsi: ");
	gets(s);
	rangeVldIntKey(&key, "\n\t\t\tMasukan jumlah pergeseran : ");
	//blok kode dekripsi alphabet kecil
	for(i = 0; s[i] != '\0'; ++i){
		if(s[i] >= 'a' && s[i] <= 'z') {
        	s[i] = s[i] - 32;
      	}
    //blok kode dekripsi alphabet kapital  
		if(s[i] >= 'A' && s[i] <= 'Z'){
			s[i] = s[i] - key;
			if(s[i] < 'A'){
				s[i] = s[i] + 26;
			}
			s[i] = s[i] +32;
		}
	}

	printf("\n\t\t\tHasil Dekripsi : %s", s);
	return 0;
}

void header(){
    system("cls");
    printf("\n\t\t\t\xda===================================\xbf\n");
	printf("\t\t\t||		PROGRAM            ||\n");
	printf("\t\t\t||	  ENKRIPSI & DESKRIPSI	   ||\n"); 
	printf("\t\t\t||            KELOMPOK 20          ||\n");
	printf("\t\t\t\xc0===================================\xd9\n\n");
}

void reinpt(){
    int pilih;
    int n;
    printf("\n\n\t\t\t================================================\n");
    printf("\n\t\t\tApakah anda ingin mengulang program?");
    printf("\n\t\t\t[1] Untuk Kembali ke Menu Utama\n");
    printf("\t\t\t[2] Untuk Keluar Dari Program\n");
    rangeVldIntReinp(&pilih, "\n\t\t\tMasukan Pilihan \t= ");
    if(pilih == 1){
    system("cls");
        main();
    }else if(pilih == 2){
    	system("cls");
        exit(0);
    }
}

int validInt(int *var){
	char buff[1024];
	char cek;
	fflush(stdin);
	if(fgets(buff, sizeof(buff), stdin) != NULL){
		if(sscanf(buff, "%d %c", var, &cek) == 1) {
			return 1;
		}
	}
	return 0;
}

void reVldInt(int *var, char *prompt){
	while(1){
		printf(prompt);
		if(validInt(var))
			break;
		printf("\t\t\tInput salah! Masukkan Angka.\n");
	}
}

void rangeVldIntMenu(int *var, char *prompt){
	while(1){
		reVldInt(var, prompt);
		if(*var >=0 && *var <=2)
			break;
		printf("\t\t\tInput salah! Pilih 0, 1 atau 2.\n");
	}
}

void rangeVldIntKey(int *var, char *prompt){
	while(1){
		reVldInt(var, prompt);
		if(*var >0)
			break;
		printf("\t\t\tInput salah! Masukkan angka lebih dari 0\n");
	}
}

void rangeVldIntReinp(int *var, char *prompt){
	while(1){
		reVldInt(var, prompt);
		if(*var == 1 || *var == 2)
			break;
		printf("\t\t\tInput salah! Pilih 1 atau 2.\n");
	}
}
