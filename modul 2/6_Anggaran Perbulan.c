#include <stdio.h>
#include <stdlib.h>

void judulprogram(){
	printf("\n============================================\n");
	printf("||	     PROGRAM MENGHITUNG		  ||\n");
	printf("||	ANGSURAN YANG HARUS DIBAYAR	  ||\n"); 
	printf("||              KELOMPOK 20               ||\n");
	printf("============================================\n\n");
}

void hitungangsuran(int pinjampokok, int besaranbunga, int waktupinjam){
	int bungaperbulan;
	int angsuranperbulan;
	int angsuranpokok;
	int totalbunga;
	int totalangsuran;
	int bulan;
	
	angsuranpokok = pinjampokok/waktupinjam;
	printf("\nBulan\t Bunga\t Angsuran Pokok\t Angsuran Perbulan");
			
	for(bulan=1; bulan<=waktupinjam; bulan++){
		bungaperbulan = (pinjampokok-((bulan-1)*angsuranpokok))*besaranbunga/100/12;
		angsuranperbulan = bungaperbulan + angsuranpokok;
		totalbunga = totalbunga + bungaperbulan;
		totalangsuran = totalangsuran + angsuranperbulan;
			
		printf("\n %d\t Rp%d\t     Rp%d\t     Rp%d\t", bulan, bungaperbulan, angsuranpokok, angsuranperbulan);
	}
	printf("\n=======================================================");
	printf("\nTotal Bunga\t\t\t     Rp%d",totalbunga);
	printf("\ntotal Angsuran\t\t\t     Rp%d",totalangsuran);
	printf("\n=======================================================");
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

int main(){
	char menu_salah = 'y' || 'Y';
	int menu;
	int pokokpinjaman;
	int besarbunga;
	int lamapinjam;
	
	do{
		//memaggil fungsi judulprogram
		judulprogram();
		printf("\n==========================\n");
		printf("||       Pilih menu:    ||\n");
		printf("||1. Hitung Angsuran    ||\n");
		printf("||2. Keluar             ||\n");
		printf("==========================\n\n");
		printf("Masukkan pilihan menu: ");	
		menu = validasi();
		//clear layar setelah user menginputkan menu
		system("cls");
		judulprogram();
		
		if(menu==1){
			printf("Masukkan pokok pinjaman: ");
			pokokpinjaman = validasi();
			printf("\nMasukkan besar bunga(%%): ");
			besarbunga = validasi();
			printf("\nMasukkan lama pinjaman(bulan): ");
			lamapinjam = validasi();
			system("cls");
			judulprogram();
			//memanggil fungsi hitungangsuran
			hitungangsuran(pokokpinjaman, besarbunga, lamapinjam);
		}
		else if(menu == 2){
			//fungsi untuk keluar dari program
			system("cls");
			exit(0);
		}
		else{
			printf("Input yang anda masukkan tidak ada dalam menu! Silahkan coba lagi\n");
		}
		printf("\n*Tekan selain keyword Y/y untuk keluar*");
		printf("\nKembali ke menu? (Y/y): ");
		scanf(" %c", &menu_salah);
		system("cls");
	}
	while(menu_salah == 'y' || menu_salah == 'Y');
	
	return 0;
}

