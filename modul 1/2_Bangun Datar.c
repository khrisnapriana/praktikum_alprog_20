#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void validasi() {
	int temp, status,
		retry;
		
	puts("\n\nIngin mencoba lagi? ");
	puts("1. Ya");
	puts("2. Tidak");
	
	printf("\nPilih Menu Operasi: ");
	status = scanf("%d", &retry);
	while(status != 1) {
		while((temp=getchar()) != EOF && temp != '\n');
		printf("Invalid input \n");
		printf("Pilih Menu Operasi: ");
		status = scanf("%d", &retry);
	}
	switch(retry) {
		case 1:
			system("cls");
			main();
			break;
		
		case 2:
			puts("Terima Kasih.");
			break;
			
		default:
			system("cls");
			puts("\nInvalid Input, silahkan pilih 1 / 2");
			validasi();
			break;
	}
}

int Submenu() {
	int temp, status,
		menu;
		
	puts("\n-> Pilihan Sub-Menu <-");
	puts("-> 1. Luas ");
	puts("-> 2. Keliling ");
	
	printf("\nPilih SubMenu Operasi: ");
	status = scanf("%d", &menu);
	while(status != 1) {
		while((temp=getchar()) != EOF && temp != '\n');
		printf("Invalid Input \n");
		printf("Pilih SubMenu Operasi: ");
		status = scanf("%d", &menu);
	}
	
	switch(menu) {
		case 1:
			return 1;
			break;
			
		case 2:
			return 2;
			break;
		
		default:
			system("cls");
			puts("Invalid Input");
			puts("Silahkan pilih submenu 1 / 2 \n");
			Submenu();
			break;
	}
}

int main() {
	int temp, status,
		menu, submenu,
		n1, n2, n3;
	double luas, kell;
	
	puts("===> KELOMPOK 20 ALPROG <=== \n");
	puts("-> Program Menghitung Luas dan Keliling Bangun Datar <-");
	puts("-> 1. Segitiga Sembarang ");
	puts("-> 2. Belah Ketupat ");
	puts("-> 3. Jajar Genjang ");
	puts("-> 4. Trapesium ");
	puts("-> 5. Lingkaran ");
	
	printf("\nPilih Bangun Datar: ");
	status = scanf("%d", &menu);
	while(status != 1) {
		while((temp=getchar()) != EOF && temp != '\n');
		printf("Invalid Input \n");
		printf("Pilih Bangun Datar: ");
		status = scanf("%d", &menu);
	}
	
	switch(menu) {
		case 1:
			// Segitiga Sembarang
			// ambil nilai submenu
			submenu = Submenu();
			// 1. Luas
			if(submenu == 1) {
				// scan nilai 1
				printf("Masukkan nilai a: ");
				status = scanf("%d", &n1);
				while(status != 1) {
					while((temp=getchar()) != EOF && temp != '\n');
					printf("Invalid Input \n");
					printf("Masukkan nilai a: ");
					status = scanf("%d", &n1);
				}
				// scan nilai 2
				printf("Masukkan nilai b: ");
				status = scanf("%d", &n2);
				while(status != 1) {
					while((temp=getchar()) != EOF && temp != '\n');
					printf("Invalid Input \n");
					printf("Masukkan nilai b: ");
					status = scanf("%d", &n2);
				}
				// scan nilai 3
				printf("Masukkan nilai c: ");
				status = scanf("%d", &n3);
				while(status != 1) {
					while((temp=getchar()) != EOF && temp != '\n');
					printf("Invalid Input \n");
					printf("Masukkan nilai c: ");
					status = scanf("%d", &n3);
				}
				// kalkulasi Luas
				luas = (n1 + n2 + n3) / 2;
				// cetak Luas
				printf("\nLuas Segitiga Sembarang");
				printf("\nLuas = (%d + %d + %d) / 2 \nLuas = %.1f", n1,n2,n3,luas);
				
				// validasi ulang
				validasi();
				
			// 2. Keliling
			} else if(submenu == 2) {
				// scan nilai 1
				printf("Masukkan nilai a: ");
				status = scanf("%d", &n1);
				while(status != 1) {
					while((temp=getchar()) != EOF && temp != '\n');
					printf("Invalid Input \n");
					printf("Masukkan nilai a: ");
					status = scanf("%d", &n1);
				}
				// scan nilai 2
				printf("Masukkan nilai b: ");
				status = scanf("%d", &n2);
				while(status != 1) {
					while((temp=getchar()) != EOF && temp != '\n');
					printf("Invalid Input \n");
					printf("Masukkan nilai b: ");
					status = scanf("%d", &n2);
				}
				// scan nilai 3
				printf("Masukkan nilai c: ");
				status = scanf("%d", &n3);
				while(status != 1) {
					while((temp=getchar()) != EOF && temp != '\n');
					printf("Invalid Input \n");
					printf("Masukkan nilai c: ");
					status = scanf("%d", &n3);
				}
				// kalkulasi Luas
				kell = n1 + n2 + n3;
				// cetak Luas
				printf("\nKeliling Segitiga Sembarang");
				printf("\nKell = %d + %d + %d \nKell = %.1f", n1,n2,n3,kell);
				
				// validasi ulang
				validasi();
			} 
			break;
			
		case 2:
			// Belah Ketupat
			// Ambil pilihan submenu
			submenu = Submenu();
			// 1. Luas
			if(submenu == 1) {
				// scan nilai 1
				printf("Masukkan nilai d1: ");
				status = scanf("%d", &n1);
				while(status != 1) {
					while((temp=getchar()) != EOF && temp != '\n');
					printf("Invalid Input \n");
					printf("Masukkan nilai d1: ");
					status = scanf("%d", &n1);
				}
				// scan nilai 2
				printf("Masukkan nilai d2: ");
				status = scanf("%d", &n2);
				while(status != 1) {
					while((temp=getchar()) != EOF && temp != '\n');
					printf("Invalid Input \n");
					printf("Masukkan nilai d2: ");
					status = scanf("%d", &n2);
				}
				// kalkulasi Luas
				luas = (n1 * n2) / 2;
				// cetak Luas
				printf("\nLuas Belah Ketupat");
				printf("\nLuas = (%d x %d) / 2 \nLuas = %.1f", n1,n2,luas);
				
				// validasi ulang
				validasi();
				
			// 2. Keliling
			} else if(submenu == 2) {
				// scan nilai 1
				printf("Masukkan nilai s: ");
				status = scanf("%d", &n3);
				while(status != 1) {
					while((temp=getchar()) != EOF && temp != '\n');
					printf("Invalid Input \n");
					printf("Masukkan nilai s: ");
					status = scanf("%d", &n3);
				}
				// kalkulasi Kell dgn rumus
				kell = 4 * n3;
				// cetak Luas
				printf("\nKeliling Belah Ketupat");
				printf("\nKell = 4 x %d \nKell = %.1f", n3,kell);
				
				// validasi ulang
				validasi();
			}
			break;
			
		case 3:
			// Jajar Genjang
			// Ambil pilihan submenu
			submenu = Submenu();
			// 1. Luas Jajar Genjang
			if(submenu == 1) {
				// scan nilai alas (a)
				printf("Masukkan nilai alas (a): ");
				status = scanf("%d", &n1);
				while(status != 1) {
					while((temp=getchar()) != EOF && temp != '\n');
					printf("Invalid Input \n");
					printf("Masukkan nilai alas (a): ");
					status = scanf("%d", &n1);
				}
				// scan nilai tinggi (t)
				printf("Masukkan nilai tinggi (t): ");
				status = scanf("%d", &n3);
				while(status != 1) {
					while((temp=getchar()) != EOF && temp != '\n');
					printf("Invalid Input \n");
					printf("Masukkan nilai tinggi (t): ");
					status = scanf("%d", &n3);
				}
				// kalkulasi
				luas = n1 * n3;
				// cetak hasil
				printf("\nLuas Jajar Genjang");
				printf("\nLuas = %d x %d \nLuas = %.0f", n1,n3,luas);
				// validasi kembali
				validasi();
				
			// 2. Keliling Jajar Genjang
			} else if(submenu == 2) {
				// scan nilai alas (a)
				printf("Masukkan nilai alas (a): ");
				status = scanf("%d", &n1);
				while(status != 1) {
					while((temp=getchar()) != EOF && temp != '\n');
					printf("Invalid Input \n");
					printf("Masukkan nilai alas (a): ");
					status = scanf("%d", &n1);
				}
				// scan nilai sisi miring (b)
				printf("Masukkan nilai sisi miring (b): ");
				status = scanf("%d", &n2);
				while(status != 1) {
					while((temp=getchar()) != EOF && temp != '\n');
					printf("Invalid Input \n");
					printf("Masukkan nilai sisi miring (b): ");
					status = scanf("%d", &n2);
				}
				// rumus kell jajar genjang
				kell = 2 * (n1 + n2);
				// cetak kell
				printf("\nKeliling Jajar Genjang");
				printf("\nKell = 2 x (%d + %d) \nKell = %.0f", n1,n2,kell);
				// validasi ulang
				validasi();
			}
			break;
			
		case 4:
			// Trapesium sama kaki
			// Ambil pilihan submenu
			submenu = Submenu();
			// 1. Luas
			if(submenu == 1) {
				// scan nilai sisi atas (a)
				printf("Masukkan nilai sisi atas (a): ");
				status = scanf("%d", &n1);
				while(status != 1) {
					while((temp=getchar()) != EOF && temp != '\n');
					printf("Invalid Input \n");
					printf("Masukkan nilai sisi atas (a): ");
					status = scanf("%d", &n1);
				}
				// scan nilai sisi bawah (b)
				printf("Masukkan nilai sisi bawah (b): ");
				status = scanf("%d", &n2);
				while(status != 1) {
					while((temp=getchar()) != EOF && temp != '\n');
					printf("Invalid Input \n");
					printf("Masukkan nilai sisi bawah (b): ");
					status = scanf("%d", &n2);
				}
				// scan nilai tinggi (t)
				printf("Masukkan nilai tinggi (t): ");
				status = scanf("%d", &n3);
				while(status != 1) {
					while((temp=getchar()) != EOF && temp != '\n');
					printf("Invalid Input \n");
					printf("Masukkan nilai tinggi (t): ");
					status = scanf("%d", &n3);
				}
				// kalkulasi
				luas = (n1 + n2) / 2 * n3;
				// cetak
				printf("\nLuas Trapesium");
				printf("\nLuas = (%d + %d) / 2 x %d \nLuas = %.0f", n1,n2,n3,luas);
				// validasi
				validasi();
				
			// 2. Keliling
			} else if(submenu == 2) {
				// scan nilai sisi atas (a)
				printf("Masukkan nilai sisi atas (a): ");
				status = scanf("%d", &n1);
				while(status != 1) {
					while((temp=getchar()) != EOF && temp != '\n');
					printf("Invalid Input \n");
					printf("Masukkan nilai sisi atas (a): ");
					status = scanf("%d", &n1);
				}
				// scan nilai sisi bawah (b)
				printf("Masukkan nilai sisi bawah (b): ");
				status = scanf("%d", &n2);
				while(status != 1) {
					while((temp=getchar()) != EOF && temp != '\n');
					printf("Invalid Input \n");
					printf("Masukkan nilai sisi bawah (b): ");
					status = scanf("%d", &n2);
				}
				// scan nilai tinggi (t)
				printf("Masukkan nilai tinggi (t): ");
				status = scanf("%d", &n3);
				while(status != 1) {
					while((temp=getchar()) != EOF && temp != '\n');
					printf("Invalid Input \n");
					printf("Masukkan nilai tinggi (t): ");
					status = scanf("%d", &n3);
				}
				// kalkulasi kell trapesium
				kell = n1 + n2 + (2 * (sqrt(((n2-n1)/2) * ((n2-n1)/2) + n3*n3)));
				// cetak hasil
				printf("\nKeliling Trapesium");
				printf("\nKell = %d + %d + (2 x (\xfb((%d-%d)/2)^2 + %d^2))) \nKell = %.0f", n1,n2,n2,n1,n3,kell);
				// validasi
				validasi();
			}
			break;
		
		case 5:
			// Lingkaran
			// Ambil pilihan submenu
			submenu = Submenu();
			// 1. Luas
			if(submenu == 1) {
				// scan nilai jari-jari (r)
				printf("Masukkan nilai jari-jari (r): ");
				status = scanf("%d", &n1);
				while(status != 1) {
					while((temp=getchar()) != EOF && temp != '\n');
					printf("Invalid Input \n");
					printf("Masukkan nilai jari-jari (r): ");
					status = scanf("%d", &n1);
				}
				// rumus luas lingkaran
				luas = 3.14 * n1 * n1;
				// cetak luas lingkaran
				printf("\nLuas Lingkaran");
				printf("\nLuas = 3,14 x %d x %d \nLuas = %.1f", n1,n1,luas);
				// validasi
				validasi();
			
			// 2. Keliling
			} else if(submenu == 2) {
				// scan nilai jari-jari (r)
				printf("Masukkan nilai jari-jari (r): ");
				status = scanf("%d", &n1);
				while(status != 1) {
					while((temp=getchar()) != EOF && temp != '\n');
					printf("Invalid Input \n");
					printf("Masukkan nilai jari-jari (r): ");
					status = scanf("%d", &n1);
				}
				// rumus luas lingkaran
				kell = 2 * 3.14 * n1;
				// cetak luas lingkaran
				printf("\nKeliling Lingkaran");
				printf("\nKell = 2 x 3,14 x %d \nKell = %.1f", n1,kell);
				// validasi
				validasi();
			}
			break;
		
		default:
			system("cls");
			puts("Invalid Input");
			puts("Silahkan pilih menu 1 - 5 \n");
			main();
			break;
	}
	
	return 0;
}
