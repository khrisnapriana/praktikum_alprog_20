#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//deklarasi fungsi
void proses();
void header();
void reinpt();
void rangeVldIntMenu();
void rangeVldIntReinp();
//deklarasi variabel global
clock_t waktu;
double durasi[2];
int x, y, temp;

int main(){
    int input;
	//fflush membersihkan buffer
    fflush(stdin);
	header();
    printf("\n\t\t\tPilih operasi pengurutan yang diinginkan :   \n");
    printf("\t\t\t[1] Bubblesort 1000                         \n");
    printf("\t\t\t[2] Bubblesort 16000                        \n");
    printf("\t\t\t[3] Bubblesort 64000                        \n");
    printf("\t\t\t[0] Keluar                                  \n");
    rangeVldIntMenu(&input, "\n\t\t\tMasukkan pilihan anda : ");
    
    header();
    switch(input){
    	//pemberian nilai kepada proses
        case 1:
            proses(1000);
        	break;
        case 2:
            proses(16000);
            break;
        case 3:
            proses(64000);
            break;
        case 0:
            exit(0);
    }
    reinpt();
    return 0;
}
//bubble sort
void cara_biasa(int a1[], int n){
	for(x=0; x<n-1; x++){
		for(y=0; y<n-1-x; y++){
			if(a1[y] > a1[y+1]){
				temp = a1[y];
				a1[y] = a1[y+1];
				a1[y+1] = temp;
			}
		}
	}
}
//pointer
void cara_pointer(int *pa2[], int n){
	for(x=0; x<n-1; x++){
		for(y=0; y<n-1-x; y++){
			if(*(pa2+y) > *(pa2+y+1)){
				temp = *(pa2+y);
				*(pa2+y) = *(pa2+y+1);
				*(pa2+y+1) = temp;
			}
		}
	}
}
//fungsi memproses penghitungan
void proses(int n){
    int a1[n], a2[n];
    int pilih;
	//bilangan random
    for(x=0; x<n; x++){
		a1[x] = rand();
		a2[x] = a1[x];
	}
	
    printf("\n\t\t\t==================================================\n");
    printf("\n\t\t\tTampilkan %d bilangan acak\n", n);
    //menampilkan bilangan yang acak agar rapih
	for(x=0; x<n; x++){
        printf("\t\t\t");
        for(y=0; y<=10; y++){
            printf("%d ", a1[x]);
        }
        printf("\n");
	}

	printf("\n\t\t\t==================================================\n");
    printf("\n\t\t\tMulai mengurutkan data dengan cara biasa dan pointer\n");
    printf("\n\t\t\tTekan tombol apa saja. . .\n\n");
    getch();
	
	//baris kode proses penghitungan waktu menggunakan cara_biasa
	waktu = clock();
	cara_biasa(a1, n);	
    waktu = clock() - waktu;
    durasi[0] = (double)(waktu) / CLOCKS_PER_SEC;
	//baris kode proses penghitungan waktu menggunakan cara_pointer
    waktu = clock();
	cara_pointer(a2, n);
	waktu = clock() - waktu;
	durasi[1] = (double)(waktu) / CLOCKS_PER_SEC;
	
	printf("\n\t\t\t==================================================\n");
    printf("\n\t\t\tPengurutan data dengan cara biasa dan pointer Selesai\n");
	printf("\n\n");
	printf("\t\t\t+-----------------------------------+\n");
	printf("\t\t\t\tWaktu Yang Dibutuhkan        \n");
	printf("\t\t\t+-----------------------------------+\n");
	printf("\t\t\tCara biasa : %f detik               \n", durasi[0]);
	printf("\t\t\tPointer    : %f detik               \n", durasi[1]);
	printf("\t\t\t+-----------------------------------+\n");
	
	printf("\n\n\t\t\tTampilkan hasil pengurutan?");
	printf("\n\t\t\t[1] Untuk Menampilkan Hasil Pengurutan\n");
    printf("\t\t\t[2] Untuk Tidak Menampilkan Hasil\n");
    rangeVldIntReinp(&pilih, "\n\t\t\tMasukan Pilihan \t= ");
    
    if(pilih == 1){
	    printf("\n\n\t\t\t================================================\n");
	    printf("\t\t\tHasil Pengurutan\n\n");
		for(x=0; x<n; x++){
	        printf("\t\t\t");
	        for(y=0; y<=10; y++){
	            printf("%d ", a1[x]);
	        }
	        printf("\n");
		}
    }
}

void header(){
    system("cls");
	printf("\n\t\t\t\xda============================================\xbf\n");
	printf("\t\t\t||	PROGRAM PENGURUTAN BILANGAN ACAK    ||\n");
	printf("\t\t\t||	       DENGAN BUBBLE SORT	    ||\n"); 
	printf("\t\t\t||                KELOMPOK 20               ||\n");
	printf("\t\t\t\xc0============================================\xd9\n\n");
}

void reinpt(){
    int pilih;
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
		if(*var >=0 && *var <=3)
			break;
		printf("\t\t\tInput salah! Pilih 0 - 3.\n");
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
