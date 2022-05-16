#include <stdio.h>
#include <stdlib.h>

void judulprogram(){
	printf("\n============================================\n");
	printf("||    PROGRAM DERET BILANGAN FIBONACCI    ||\n");
	printf("||       METODE REKURSIF & ITERATIF       ||\n");
	printf("||              KELOMPOK 20               ||\n"); 
	printf("============================================\n\n");
}

void judulrekursif(){
	printf("\n========================================\n");
	printf("||          Metode Rekursif           ||\n");
	printf("||Menampilkan Deret Bilangan Fibonacci||\n");
	printf("||            Kelompok 20             ||\n"); 
	printf("========================================\n\n");
}

void juduliteratif(){
	printf("\n========================================\n");
	printf("||          Metode Iteratif           ||\n");
	printf("||Menampilkan Deret Bilangan Fibonacci||\n");
	printf("||            Kelompok 20             ||\n"); 
	printf("========================================\n\n");
}

int fibonacci_rekursif(int deret) {
    if(deret == 0 || deret == 1){
    	//jika value deret = 0 atau 1, maka akan di-return value itu sendiri
    	return deret; 
	}
    else{
    	//jika selain itu, maka akan di-return dengan rumus dibawah ini
    	return fibonacci_rekursif(deret-1) + fibonacci_rekursif(deret-2);
    	//misal value deret = 4
    	//deret 0 = 0
    	//deret 1 = 1
    	//deret 2 = value (deret(2-1) + deret(2-2)) = value (deret(1) + deret(0)) = 1 + 0 = 1
    	//deret 3 = value (deret(3-1) + deret(3-2)) = value (deret(2) + deret(1)) = 1 + 1 = 2
	}    
}

void fibonacci_iteratif(int jumlahderet){
	int deret1 = 0;
	int	deret2 = 1;
   	int deret = 0;
   	int deretn;
   	
	do{
	    //variabel deretn akan berubah-ubah setiap kali perulangan do-while berjalan
	    //1. deretn = 0 + 1 = 1
	    //2. deretn = 1 + 1 = 2
	    //3. deretn = 1 + 2 = 3
	    deretn = deret1 + deret2;
	    if(deret == 0){
	   		printf("Deret ke-1: %d \n", deret1);
	    }
	   	else if(deret == 1){
	    	printf("Deret ke-2: %d \n", deret2);
		}
		else{
			printf("Deret ke-%d: %d \n", deret+1, deretn);
			//inisialisasi variabel deret1 dengan value deret2
			deret1 = deret2;
			//inisialisasi variabel deret2 dengan value deretn
			deret2 = deretn;
		}
		deret++;
	}
	while(deret<jumlahderet);
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
    int i, menu;
    int banyakderet;
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
			printf("Masukkan jumlah deret: ");
			banyakderet = validasi();
			printf("Deret bilangan fibonacci: \n\n");
			//perulangan untuk menampilkan deret fibonacci
			for(i=0; i<banyakderet; i++){
			    printf("Deret ke-%d: %d \n", i+1, fibonacci_rekursif(i));
			}  
		}
		else if(menu == 2){
			//memanggil fungsi juduliteratif
			juduliteratif();
			printf("Masukkan jumlah deret: ");
			banyakderet = validasi();
			printf("\nDeret bilangan fibonacci: \n\n");
			//memanggil fungsi fibonacci_iteratif
			fibonacci_iteratif(banyakderet);
		}
		else if(menu == 3){
			//fungsi untuk keluar dari program
			exit(0);
		}
		else{
			judulprogram();
			printf("Input tidak ada dalam menu! Silahkan coba lagi");
		}
		printf("\n========================================\n\n");
		printf("*Tekan selain keyword Y/y untuk keluar*\n");
		printf("Kembali ke menu? (Y/y): ");
		scanf("%c", &menu_salah);
		system("cls");
	}  
    while(menu_salah == 'y' || menu_salah == 'Y');
    
    return 0;
}
