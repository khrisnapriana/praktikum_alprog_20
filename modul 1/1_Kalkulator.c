#include <stdio.h>
#include <stdlib.h>

void validasi() {
	int temp, status,
		retry;
		
	puts("\nIngin mencoba lagi? ");
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

int main() {
	int temp, status,
		menu, a, b, retry;
	
	puts("===> KELOMPOK 20 ALPROG <=== \n");
	puts("=== Program Kalkulator Sederhana ===");
	puts("1. Penjumlahan (+)");
	puts("2. Pengurangan (-)");
	puts("3. Perkalian   (*)");
	puts("4. Pembagian   (/)");
	puts("5. Modulus     (%)");
	
	printf("\nPilih Menu Operasi: ");
	status = scanf("%d", &menu);
	while(status != 1) {
		while((temp=getchar()) != EOF && temp != '\n');
		printf("Invalid input \n");
		printf("Pilih Menu Operasi: ");
		status = scanf("%d", &menu);
	}
	
	//printf("Anda memilih menu %d \n", input);
	switch(menu) {
		case 1:
			// ambil nilai a
			printf("Masukkan nilai a: ");
			status = scanf("%d", &a);
			while(status != 1) {
				while((temp=getchar()) != EOF && temp != '\n');
				printf("Invalid input \n");
				printf("Masukkan nilai a: ");
				status = scanf("%d", &a);
			}
			// ambil nilai b
			printf("Masukkan nilai b: ");
			status = scanf("%d", &b);
			while(status != 1) {
				while((temp=getchar()) != EOF && temp != '\n');
				printf("Invalid input \n");
				printf("Masukkan nilai b: ");
				status = scanf("%d", &b);
			}
			// cetak hasil
			printf("\nNilai a + b adalah %d \n", a+b);
			
			// konfirmasi untuk mencoba lagi
			validasi();
			break;
			
		case 2:
			// ambil nilai a
			printf("Masukkan nilai a: ");
			status = scanf("%d", &a);
			while(status != 1) {
				while((temp=getchar()) != EOF && temp != '\n');
				printf("Invalid input \n");
				printf("Masukkan nilai a: ");
				status = scanf("%d", &a);
			}
			// ambil nilai b
			printf("Masukkan nilai b: ");
			status = scanf("%d", &b);
			while(status != 1) {
				while((temp=getchar()) != EOF && temp != '\n');
				printf("Invalid input \n");
				printf("Masukkan nilai b: ");
				status = scanf("%d", &b);
			}
			// cetak hasil
			printf("\nNilai a - b adalah %d \n", a-b);
			
			// konfirmasi untuk mencoba lagi
			validasi();
			break;
		
		case 3:
			// ambil nilai a
			printf("Masukkan nilai a: ");
			status = scanf("%d", &a);
			while(status != 1) {
				while((temp=getchar()) != EOF && temp != '\n');
				printf("Invalid input \n");
				printf("Masukkan nilai a: ");
				status = scanf("%d", &a);
			}
			// ambil nilai b
			printf("Masukkan nilai b: ");
			status = scanf("%d", &b);
			while(status != 1) {
				while((temp=getchar()) != EOF && temp != '\n');
				printf("Invalid input \n");
				printf("Masukkan nilai b: ");
				status = scanf("%d", &b);
			}
			// cetak hasil
			printf("\nNilai a * b adalah %d \n", a*b);
			
			// konfirmasi untuk mencoba lagi
			validasi();
			break;
			
		case 4:
			// ambil nilai a
			printf("Masukkan nilai a: ");
			status = scanf("%d", &a);
			while(status != 1) {
				while((temp=getchar()) != EOF && temp != '\n');
				printf("Invalid input \n");
				printf("Masukkan nilai a: ");
				status = scanf("%d", &a);
			}
			// ambil nilai b
			printf("Masukkan nilai b: ");
			status = scanf("%d", &b);
			while(status != 1) {
				while((temp=getchar()) != EOF && temp != '\n');
				printf("Invalid input \n");
				printf("Masukkan nilai b: ");
				status = scanf("%d", &b);
			}
			// cetak hasil
			printf("\nNilai a / b adalah %d \n", a/b);
			
			// konfirmasi untuk mencoba lagi
			validasi();
			break;
			
		case 5:
			// ambil nilai a
			printf("Masukkan nilai a: ");
			status = scanf("%d", &a);
			while(status != 1) {
				while((temp=getchar()) != EOF && temp != '\n');
				printf("Invalid input \n");
				printf("Masukkan nilai a: ");
				status = scanf("%d", &a);
			}
			// ambil nilai b
			printf("Masukkan nilai b: ");
			status = scanf("%d", &b);
			while(status != 1) {
				while((temp=getchar()) != EOF && temp != '\n');
				printf("Invalid input \n");
				printf("Masukkan nilai b: ");
				status = scanf("%d", &b);
			}
			// cetak hasil
			printf("\nNilai a %% b adalah %d \n", a%b);
			
			// konfirmasi untuk mencoba lagi
			validasi();
			break;
			
		default:
			system("cls");
			puts("\nInvalid input");
			puts("Silahkan pilih menu 1 - 5 !! \n");
			main();
			break;
	}
	
	return 0;
}
