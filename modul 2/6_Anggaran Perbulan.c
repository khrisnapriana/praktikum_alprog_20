#include <stdio.h>
#include <stdlib.h>

void judulprogram(){
	printf("\n============================================\n");
	printf("||	     PROGRAM MENGHITUNG		  ||\n");
	printf("||	ANGSURAN YANG HARUS DIBAYAR	  ||\n"); 
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

int main(){
	char menu_salah = 'y';
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
		scanf("%d", &menu);
		//clear layar setelah user menginputkan menu
		system("cls");
		judulprogram();
		
		if(menu==1){
			printf("Masukkan pokok pinjaman: ");
			scanf("%d", &pokokpinjaman);
			printf("\nMasukkan besar bunga (%%): ");
			scanf("%d", &besarbunga);
			printf("\nMasukkan lama pinjaman (bulan): ");
			scanf("%d", &lamapinjam);
			system("cls");
			judulprogram();
			//memanggil fungsi hitungangsuran
			hitungangsuran(pokokpinjaman, besarbunga, lamapinjam);
		}
		else if(menu == 2){
			//fungsi untuk keluar dari program
			exit(0);
		}
		else{
			printf("Input yang anda masukkan tidak ada dalam menu! Silahkan coba lagi");
		}
		printf("\n\nKembali ke menu? (y/t): ");
		scanf(" %c", &menu_salah);
		system("cls");
	}
	while(menu_salah == 'y');
	
	return 0;
}

