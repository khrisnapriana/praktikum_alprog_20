#include <stdio.h>
#include <stdlib.h>

void judulprogram(){
	printf("\n============================================\n");
	printf("||    PROGRAM DERET BILANGAN FIBONACCI    ||\n");
	printf("||       METODE REKURSIF & ITERATIF       ||\n"); 
	printf("============================================\n\n");
}

void judulrekursif(){
	printf("\n========================================\n");
	printf("||            Metode Rekursif         ||\n");
	printf("||Menampilkan Deret Bilangan Fibonacci||\n");
	printf("========================================\n\n");
}

int deretfibonacci(int deret) {
    if(deret == 0 || deret == 1){
    	//jika value deret = 0 atau 1, maka akan di-return value itu sendiri
    	return deret; 
	}
    else{
    	//jika selain itu, maka akan di-return dengan rumus dibawah ini
    	return deretfibonacci(deret-1) + deretfibonacci(deret-2);
    	//misal value deret = 4
    	//deret 0 = 0
    	//deret 1 = 1
    	//deret 2 = value (deret(2-1) + deret(2-2)) = value (deret(1) + deret(0)) = 1 + 0 = 1
    	//deret 3 = value (deret(3-1) + deret(3-2)) = value (deret(2) + deret(1)) = 1 + 1 = 2
	}    
}

int main(){
    int i, menu;
    int banyakderet;
    char menu_salah = 'y';
    int deret1, deret2, deret, deretn;
    
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
		scanf("%d", &menu);
		//clear layar setelah user menginputkan menu
		system("cls");
	    
	    if(menu == 1){
	    	//memanggil fungsi judulrekursif
		    judulrekursif();
		   	printf("Masukkan jumlah deret: ");
		   	scanf("%d", &banyakderet);
		    system("cls");
		    judulrekursif();
		    printf("Deret bilangan fibonacci: \n\n");
		    //perulangan untuk menampilkan deret fibonacci
		   	for(i = 0; i<banyakderet; i++){
		       	printf("Deret ke-%d: %d \n", i+1, deretfibonacci(i));
		   	}  
		}
		else if(menu == 2){
			//inisialisasi variabel untuk metode iteratif
    		deret1 = 0;
			deret2 = 1;
   			deret = 0;
			printf("\n========================================\n");
			printf("||            Metode Iteratif         ||\n");
			printf("||Menampilkan Deret Bilangan Fibonacci||\n");
			printf("========================================\n\n");
			printf("Masukkan jumlah deret: ");
	    	scanf("%d", &banyakderet);
	    	printf("\nDeret bilangan fibonacci: \n\n");
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
			while(deret<banyakderet);
		}
		else if(menu == 3){
			//fungsi untuk keluar dari program
			exit(0);
		}
		else{
			judulprogram();
			printf("Input yang anda masukkan tidak ada dalam menu! Silahkan coba lagi");
		}
		printf("\n\nKembali ke menu? (y/t): ");
		scanf(" %c", &menu_salah);
		system("cls");
	}
    while(menu_salah == 'y');
    
    return 0;
}
