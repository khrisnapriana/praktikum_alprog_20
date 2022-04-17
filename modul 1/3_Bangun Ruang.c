#include <stdio.h>
#include <math.h>

double v, lp;

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

void cetak_tabung(int n1, int n2) {
	v = 3.14*n1*n1*n2;
	lp = 2*3.14*n1*(n1+n2);
	printf("\nTabung");
	printf("\nV = 3,14 x %d x %d x %d \nV = %.2f", n1,n1,n2,v);
	printf("\nLp = 2 x 3,14 x %d x (%d + %d) \nLp = %.2f", n1,n1,n2,lp);
}

void cetak_bola(int n1) {
	v = (4*3.14*n1*n1*n1)/3;
	lp = 4*3.14*n1*n1;
	printf("\nBola");
	printf("\nV = (4 x 3,14 x %d x %d x %d) / 3 \nV = %.2f", n1,n1,n1,v);
	printf("\nLp = 4 x 3,14 x %d x %d \nLp = %.2f", n1,n1,lp);
}

void cetak_limas_segiempat(int n1, int n2, int n3) {
	v = (n1*n1)*n2/3;
	lp = (n1*n1)+(4/2*n1*n3);
	printf("\nLimas Segiempat");
	printf("\nV = (%d x %d) x %d / 3 \nV = %.2f", n1,n1,n3,v);
	printf("\nLp = (%d x %d) + (4 / 2 x %d x %d) \nLp = %.2f", n1,n1,n1,n3,lp);
}

void cetak_prisma_segitiga(int n1, int n2, int n3) {
	v = (n1*n2/2)*n3;
	lp = n1*n2/2;
	printf("\nPrisma Segitiga");
	printf("\nV = (%d x %d / 2) x %d \nV = %.2f", n1,n2,n3,v);
	printf("\nLp = %d x %d / 2 \nLp = %.2f", n1,n2,lp);
}

void cetak_kerucut(int n1, int n2) {
	v = 3.14*n1*n1*n2/3;
	lp = (3.14*n1*n1) + (3.14*n1*(sqrt((n1*n1) + (n2*n2))));
	printf("\nKerucut");
	printf("\nV = 3,14 x %d x %d x %d / 3 \nV = %.2f", n1,n1,n2,v);
	printf("\nLp = (3.14 x %d^2) + (3.14 x %d x (\xfb(%d^2 + %d^2))); \nLp = %.2f", n1,n1,n1,n2,lp);
}

int main() {
	int temp, status,
		menu, n1, n2, n3;
		
	puts("===> KELOMPOK 20 ALPROG <=== \n");
	puts("=> Program Menghitung Volume dan Luas Permukaan Bangun Ruang <=");
	puts("=> 1. Tabung");
	puts("=> 2. Bola");
	puts("=> 3. Limas Segiempat");
	puts("=> 4. Prisma Segitiga");
	puts("=> 5. Kerucut");
	
	printf("\nPilih Menu Bangun Ruang: ");
	status = scanf("%d", &menu);
	while(status != 1) {
		while((temp=getchar()) != EOF && temp != '\n');
		printf("Invalid input \n");
		printf("Pilih Menu Bangun Ruang: ");
		status = scanf("%d", &menu);
	}
	
	switch(menu) {
		case 1:
			// scan nilai jari-jari (r)
			printf("Masukkan nilai jari-jari (r): ");
			status = scanf("%d", &n1);
			while(status != 1) {
				while((temp=getchar()) != EOF && temp != '\n');
				printf("Invalid Input \n");
				printf("Masukkan nilai jari-jari (r): ");
				status = scanf("%d", &n1);
			}
			// scan nilai tinggi (t)
			printf("Masukkan nilai tinggi (t): ");
			status = scanf("%d", &n2);
			while(status != 1) {
				while((temp=getchar()) != EOF && temp != '\n');
				printf("Invalid Input \n");
				printf("Masukkan nilai tinggi (t): ");
				status = scanf("%d", &n2);
			}
			// cetak
			cetak_tabung(n1, n2);
			// validasi
			validasi();
			break;
			
		case 2:
			// scan nilai jari-jari (r)
			printf("Masukkan nilai jari-jari (r): ");
			status = scanf("%d", &n1);
			while(status != 1) {
				while((temp=getchar()) != EOF && temp != '\n');
				printf("Invalid Input \n");
				printf("Masukkan nilai jari-jari (r): ");
				status = scanf("%d", &n1);
			}
			// cetak bola
			cetak_bola(n1);
			// validasi
			validasi();
			break;
			
		case 3:
			// scan nilai sisi (s)
			printf("Masukkan nilai sisi (s): ");
			status = scanf("%d", &n1);
			while(status != 1) {
				while((temp=getchar()) != EOF && temp != '\n');
				printf("Invalid Input \n");
				printf("Masukkan nilai sisi (s): ");
				status = scanf("%d", &n1);
			}
			// scan nilai tinggi (t)
			printf("Masukkan nilai tinggi (t): ");
			status = scanf("%d", &n2);
			while(status != 1) {
				while((temp=getchar()) != EOF && temp != '\n');
				printf("Invalid Input \n");
				printf("Masukkan nilai tinggi (t): ");
				status = scanf("%d", &n2);
			}
			// scan nilai tinggi selimut (T)
			printf("Masukkan nilai tinggi selimut (T): ");
			status = scanf("%d", &n3);
			while(status != 1) {
				while((temp=getchar()) != EOF && temp != '\n');
				printf("Invalid Input \n");
				printf("Masukkan nilai tinggi selimut (T): ");
				status = scanf("%d", &n3);
			}
			// cetak
			cetak_limas_segiempat(n1, n2, n3);
			// validasi
			validasi();
			break;
		
		case 4:
			// scan nilai alas (p)
			printf("Masukkan nilai alas (p): ");
			status = scanf("%d", &n1);
			while(status != 1) {
				while((temp=getchar()) != EOF && temp != '\n');
				printf("Invalid Input \n");
				printf("Masukkan nilai alas (p): ");
				status = scanf("%d", &n1);
			}
			// scan nilai tinggi (t)
			printf("Masukkan nilai tinggi (t): ");
			status = scanf("%d", &n2);
			while(status != 1) {
				while((temp=getchar()) != EOF && temp != '\n');
				printf("Invalid Input \n");
				printf("Masukkan nilai tinggi (t): ");
				status = scanf("%d", &n2);
			}
			// scan nilai tinggi prisma (T)
			printf("Masukkan nilai tinggi prisma (T): ");
			status = scanf("%d", &n3);
			while(status != 1) {
				while((temp=getchar()) != EOF && temp != '\n');
				printf("Invalid Input \n");
				printf("Masukkan nilai tinggi prisma (T): ");
				status = scanf("%d", &n3);
			}
			// cetak
			cetak_prisma_segitiga(n1, n2, n3);
			// validasi
			validasi();
			break;
		
		case 5:
			// scan nilai jari-jari (r)
			printf("Masukkan nilai jari-jari (r): ");
			status = scanf("%d", &n1);
			while(status != 1) {
				while((temp=getchar()) != EOF && temp != '\n');
				printf("Invalid Input \n");
				printf("Masukkan nilai jari-jari (r): ");
				status = scanf("%d", &n1);
			}
			// scan nilai tinggi (t)
			printf("Masukkan nilai tinggi (t): ");
			status = scanf("%d", &n2);
			while(status != 1) {
				while((temp=getchar()) != EOF && temp != '\n');
				printf("Invalid Input \n");
				printf("Masukkan nilai tinggi (t): ");
				status = scanf("%d", &n2);
			}
			// cetak
			cetak_kerucut(n1, n2);
			// validasi
			validasi();
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
