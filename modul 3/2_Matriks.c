#include <stdio.h>
#include <stdlib.h>

int matriks1[50][50];
int matriks2[50][50];
int matriks3[50][50];
int baris,kolom;
int pilihan;


float validasi_angka(){
	char masukan[100];
	while(1){
		int i = 0;
		int isi = 0;
		int salah = 0;
		float hasil;
		
		scanf("%[^\n]", &masukan);
		fflush(stdin);
		
		while(masukan[i] != '\0'){
			if(masukan[i] == '.'){
				salah = 1;
				masukan[i] = '\0';
			}else if(masukan[i] == ' '){
				salah = 1;
				masukan[i] = '\0';
			}else if(masukan[i] >= '0' && masukan[i] <= '9'){
				isi = masukan[i] - 48;
				i++;
			}else {
				salah = 1;
				masukan[i] = '\0';
			}	
		}
		hasil = isi;
		if(salah == 1){
			printf("angka yang anda masukan tidak valid, silahkan masukan angka yang benar:");
		}else{
			return hasil;
		}
	}
}

char exite(){
	char huruf;
	scanf("%c", &huruf);
	if(huruf == 'y'|| huruf == 'Y'){
		return huruf;
	}else if(huruf == 'n'|| huruf=='N'){
		return huruf;
	}else{
		printf("masukan anda tidak valid, silahkan masukan lagi:");
	}
	return exite();
}

void pertambahan(){
	
	int i,j;
	for(i=0;i<baris;i++){
		for(j=0;j<kolom;j++){
			matriks3[i][j] = matriks1[i][j] + matriks2[i][j];
		}
	}
}

void perkalian(){
	int i,j,k;
	int sum = 0;
	for(i=0;i<baris;i++){
		for(j=0;j<kolom;j++){
			for(k=0;k<baris;k++){
				sum += matriks1[i][k] * matriks2[k][j];
			}
			matriks3[i][j] = sum;
			sum = 0;
		}
	}
}

void transpose(int matriks[50][50], int baris, int kolom){
	int i,j;
	int matrikstranspose[50][50];
	for(i=0;i<kolom;i++){
		for(j=0;j<baris;j++){
			matrikstranspose[j][i] = matriks[i][j];
		}
	}
	for(i=0;i<baris;i++){
		for(j=0;j<kolom;j++){
			printf("\t%d\t", matrikstranspose[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void hasil_matriks(int matriks[50][50], int baris, int kolom){
	int i,j;
	for(i=0;i<baris;i++){
		for(j=0;j<kolom;j++){
			printf("\t%d\t", matriks[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void menu_pertambahan(){
	char pilihan;
	int i,j;
	
	system("cls");
	printf("=======================================================\n");
	printf("		||PERTAMBAHAN||				\n");
	printf("=======================================================\n\n");
	printf("		||Inputan Bilangan||			\n");
	printf("=======================================================\n\n");
	printf("		||Matriks 1||				\n\n");
	printf("masukan jumlah baris:");
	baris = validasi_angka(1);
	
	printf("masukan jumlah kolom:");
	kolom = validasi_angka(1);
	
	for(i = 0; i < baris; i++){
		for(j = 0; j < kolom; j++){
			printf("Bilangan baris [%d] kolom [%d] :", i+1, j+1);
			matriks1[i][j] = validasi_angka(1);
			
		}
	}
	printf("=======================================================\n");
	printf("		||Matriks 2||				\n\n");
	
	printf("jumlah baris matriks 2: %d\n", baris);
	printf("jumlah kolom matriks 2: %d\n", kolom);
	
	for(i = 0; i < baris; i++){
		for(j = 0; j < kolom; j++){
			printf("Bilangan baris [%d] kolom [%d] :", i+1, j+1);
			matriks2[i][j] = validasi_angka(1);
			
		}
	}
	printf("=======================================================\n\n");
	pertambahan();
	printf("\tMatriks 1: \n");
	hasil_matriks(matriks1,baris,kolom);
	printf("\tMatriks 2: \n");
	hasil_matriks(matriks2,baris,kolom);
	printf("\tMatriks 3: \n");
	hasil_matriks(matriks3,baris,kolom);
	
	
	printf("\nTekan Y untuk kembali ke Menu, Tekan N untuk Menutup Program");
	while(1){
		printf("\tMasukan Pilihan: \n");
		pilihan = exite();
		
		if(pilihan == 'Y'|| pilihan == 'y'){
			main();
			break;
		}else if(pilihan =='N'|| pilihan == 'n'){
			keluar();
			break;
		}else{
			printf("Pilihan anda salah, Silahkan masukan pilihan kembali: \n");
		}
	}
}

void menu_perkalian(){
	char pilihan;
	int i,j;
	
	system("cls");
	printf("=======================================================\n");
	printf("		||PERKALIAN||				\n");
	printf("=======================================================\n\n");
	printf("		||Inputan Bilangan||			\n");
	printf("=======================================================\n\n");
	printf("		||Matriks 1||				\n\n");
	
	printf("masukan jumlah baris:");
	baris = validasi_angka(1);
	
	printf("masukan jumlah kolom:");
	kolom = validasi_angka(1);
	
	for(i = 0; i < baris; i++){
		for(j = 0; j < kolom; j++){
			printf("Bilangan baris [%d] kolom [%d] :", i+1, j+1);
			matriks1[i][j] = validasi_angka(1);
			
		}
	}
	printf("\n=======================================================\n");
	printf("		||Matriks 2||				\n");
	printf("jumlahh baris matriks 2: %d\n", baris);
	printf("jumlah kolom matriks 2: %d\n", kolom);
	
	for(i = 0; i < baris; i++){
		for(j = 0; j < kolom; j++){
			printf("Bilangan baris [%d] kolom [%d] :", i+1, j+1);
			matriks2[i][j] = validasi_angka(1);
			
		}
	}
	printf("=======================================================\n");
	perkalian();
	printf("\tMatriks 1: \n");
	hasil_matriks(matriks1,baris,kolom);
	printf("\tMatriks 2: \n");
	hasil_matriks(matriks2,baris,kolom);
	printf("\tMatriks 3: \n");
	hasil_matriks(matriks3,baris,kolom);
	
	
	printf("\nTekan Y untuk kembali ke Menu, Tekan N untuk Menutup Program");
	while(1){
		printf("\tMasukan Pilihan: \n");
		pilihan = exite();
		
		if(pilihan == 'Y'|| pilihan == 'y'){
			main();
			break;
		}else if(pilihan =='N'|| pilihan == 'n'){
			keluar();
			break;
		}else{
			printf("Pilihan anda salah, Silahkan masukan pilihan kembali: \n");
		}
	}
}

void menu_transpose(){
	char pilihan;
	int i,j;
	
	system("cls");
	printf("=======================================================\n");
	printf("		||TRANSPOSE||				\n");
	printf("=======================================================\n\n");
	printf("		||Inputan Bilangan||			\n");
	printf("=======================================================\n\n");
	printf("		||Matriks 1||				\n\n");
	printf("masukan jumlah baris:");
	baris = validasi_angka(1);
	
	printf("masukan jumlah kolom:");
	kolom = validasi_angka(1);
	
	for(i = 0; i < baris; i++){
		for(j = 0; j < kolom; j++){
			printf("Bilangan baris [%d] kolom [%d] :", i+1, j+1);
			matriks1[i][j] = validasi_angka(1);
			
		}
	}
	printf("\n=======================================================\n");
	printf("\tMatriks 1: \n");
	hasil_matriks(matriks1,baris,kolom);
	printf("\tTranspose Matriks: \n");
	transpose(matriks1,baris,kolom);
	
	printf("\nTekan Y untuk kembali ke Menu, Tekan N untuk Menutup Program");
	while(1){
		printf("\tMasukan Pilihan: \n");
		pilihan = exite();
		
		if(pilihan == 'Y'|| pilihan == 'y'){
			main();
			break;
		}else if(pilihan =='N'|| pilihan == 'n'){
			keluar();
			break;
		}else{
			printf("Pilihan anda salah, Silahkan masukan pilihan kembali: \n");
		}
	}
}
void kelompok(){
	char lanjut = '\n';
	char enter;

	printf("======================================================\n");
	printf("\t\t ||Kelompok 20|| \t\t\n");
	printf("1.(2105551016)\n");
	printf("2.(2105551065)\n");
	printf("3.(2105551086)\n");
	printf("4.(2105551096)\n");
	printf("5.(2105551098)\n");
	printf("6.(2105551151)\n");
	printf("======================================================\n");
	
	printf("Tekan enter untuk melanjutkan:");
	scanf("%c", &enter);
	
}
void keluar(){
	system("cls");
	printf("======================================================\n");
	printf("\tTerima kasih Sudah menggunakan program <3\n\n");
	printf("======================================================\n");
	keluar(0);
}

int main(){
	int pilih;
	char lanjut = '\n';
	char enter;
	kelompok();
	system("cls");
	printf("====================================\n");
	printf("\tPROGRAM MATRIKS\t\t\n");
	printf("====================================\n");
	printf("\tMENU\t\t\n");
	printf("====================================\n");
	printf("\t1.Penjumlahan\t\t\n");
	printf("\t2.Perkalian\t\t\n");
	printf("\t3.Transpose\t\t\n");
	printf("\t4.Exit\t\t\n");
	printf("====================================\n");
	
	while(1){
		printf("masukan pilihan: ");
		pilih = validasi_angka(1);
		if (pilih == 1){
			menu_pertambahan();
			break;
		}else if (pilih == 2){
			menu_perkalian();
			break;
		}else if (pilih == 3){
			menu_transpose();
			break;
		}else if (pilih == 4){
			keluar();
			break;
		}else{
			printf("Masukan pilihan anda tidak valid, silahkann masukan kembaliiiii: \n");
		}	
	}
	return 0;
}
