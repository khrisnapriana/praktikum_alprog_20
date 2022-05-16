#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void judulprogram(){
	printf("\n============================================\n");
	printf("||	  PROGRAM KASUS MENARA HANOI      ||\n");
	printf("||	BANYAK LANGKAH & PENYELESAIAN     ||\n");
	printf("||	  METODE REKURSIF & ITERATIF      ||\n"); 
	printf("||               KELOMPOK 20              ||\n");
	printf("============================================\n\n");
}

void judulrekursif(){
	printf("\n==============================================================\n");
	printf("||                      Metode Rekursif                     ||\n");
	printf("||Menghitung Banyak Langkah Minimum dan Langkah Penyelesaian||\n");
	printf("||                        Kelompok 20                       ||\n");
	printf("==============================================================\n\n");
}

void juduliteratif(){
	printf("\n==============================================================\n");
	printf("||                      Metode Iteratif                     ||\n");
	printf("||Menghitung Banyak Langkah Minimum dan Langkah Penyelesaian||\n");
	printf("||                        Kelompok 20                       ||\n");
	printf("==============================================================\n\n");
}

void hanoi_rekursif(int n, char awal, char bantuan, char akhir){
	if(n==1){
		//jika n atau banyak cakram = 1 maka cetak ke layar statement dibawah ini
		printf(" >Pindahkan cakram ke-1 dari menara %c ke menara %c\n", awal, akhir);
	}
	else{
		hanoi_rekursif(n-1, awal, akhir, bantuan);
		printf(" >Pindahkan cakram ke-%d dari menara %c ke menara %c\n", n, awal, akhir);
		hanoi_rekursif(n-1, bantuan, awal, akhir);
		//misal n=3 maka memanggil fungsi menarahanoi sampai n==1 bernilai TRUE
		//(3-1, A,C,B) = (2, A,C,B)
		//(3, A,C)						>> 3 Dari A-C
		//(3-1, B,A,C) = (2, B,A,C)
		
		//** (2, A,C,B)
		//(2-1, A,B,C) = (1, A,B,C)		>> 1 Dari A-C
		//(2, A,B) 						>> 2 Dari A-B
		//(2-1, C,A,B)) = (1, C,A,B)	>> 1 Dari C-B
		
		//** (2, B,A,C)
		//(2-1, B,C,A) = (1, B,C,A)		>> 1 Dari B-A
		//(2, B,C)						>> 2 Dari B-C
		//(2-1, A,B,C) = (1, A,B,C)		>> 1 Dari A-C
	}
}

void hanoi_iteratif(int jumlahcakram){
	int i;
	
	//operator << untuk menggeser bilangan biner ke kiri
	//misal banyakcakram = 4
	//bilangan biner 1 = 0001 = 2^0 = 1
	//digeser ke kiri 4 langkah = 1000 = 2^4 = 16
	for(i=1; i<(1 << jumlahcakram); i++){
		//operator & (AND) dan | (OR) untuk menghitung proses bilangan biner
		printf(" >Pindahkan cakram paling atas dari menara %d ke menara %d\n", ((i&(i-1))%jumlahcakram )+ 1,(((i|(i-1))+1)%jumlahcakram) + 1);
	}
}

void langkahpenyelesaian(int jumlahcakram){
	int minimum_langkah;
	
	//rumus hitung langkah minimum penyelesaian
	//pow(2,banyakcakram)-1 = (2^banyakcakram)-1
	minimum_langkah = pow(2,jumlahcakram)-1;
	printf("\n\n===================================================================================\n");
	printf("Jumlah langkah minimum penyelesaian menara Hanoi dengan %d buah cakram: %d langkah\n", jumlahcakram, minimum_langkah);
	printf("===================================================================================\n");
}

int validasi(){
	int angka;
	char karakter;
	
	if(scanf("%d%c",&angka,&karakter)!= 2 || karakter != '\n'){
		//Untuk menghilangkan nilai buffer pada system
		//Sehingga saat melakukan input kembali, nilai sebelumnya tidak mempengaruhi input selanjutnya
		fflush(stdin);	
		printf("\nHanya menerima input berupa angka saja!\n");
		printf("Masukkan input yang benar: ");
		return validasi();
	}
	else{
		return angka;
	}
}

int main() {
	int banyakcakram, menu;
	char menu_salah = 'y' || 'Y';
	
	do{
		//memanggil fungsi judulprogram
		judulprogram();
		printf("\n==========================\n");
		printf("||       Pilih menu:    ||\n");
		printf("||1. Metode Rekursif	||\n");
		printf("||2. Metode Iteratif    ||\n");
		printf("||3. Keluar             ||\n");
		printf("==========================\n\n");
		printf("Masukkan pilihan menu: ");	
		menu = validasi();
		//clear layar setelah user menginputkan menu
		system("cls");
	
		if(menu == 1){
			//memanggil fungsi judulrekursif
			judulrekursif();
			printf("Masukan jumlah cakram: ");
			banyakcakram = validasi();
			printf("\nLangkah-langkah penyelesaian menara Hanoi %d buah cakram:\n\n", banyakcakram);
			//memanggil fungsi hanoi_rekursif
			hanoi_rekursif(banyakcakram,'A','B','C');
			langkahpenyelesaian(banyakcakram);
		}
		else if(menu == 2){
			//memanggil fungsi juduliteratif
			juduliteratif();
			printf("Masukan jumlah cakram: ");
			banyakcakram = validasi();
			printf("\nLangkah-langkah penyelesaian menara Hanoi %d buah cakram:\n\n", banyakcakram);
			//memanggil fungsi hanoi_iteratif
			hanoi_iteratif(banyakcakram);
			langkahpenyelesaian(banyakcakram);
		}
		else if(menu == 3){
			//fungsi untuk keluar dari program
			exit(0);
		}
		else{
			judulprogram();
			printf("Input yang anda masukkan tidak ada dalam menu! Silahkan coba lagi\n\n");
		}
		printf("*Tekan selain keyword Y/y untuk keluar*");
		printf("\nKembali ke menu? (Y/y): ");
		scanf(" %c", &menu_salah);
		system("cls");
	}
	while(menu_salah == 'y' || menu_salah == 'Y');
	
	return 0;
}

