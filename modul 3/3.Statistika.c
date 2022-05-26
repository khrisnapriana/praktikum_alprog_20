#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <conio.h>


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
			}		}
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
	}else if(huruf == 't'||huruf == 'T'){
		return huruf;
	}else if(huruf == 'n'|| huruf=='N'){
		return huruf;
	}else{
		printf("masukan anda tidak valid, silahkan masukan lagi:");
	}
	return exite();
}

float median(float *data, int jumlah_data){
	float hasil;
	if(jumlah_data % 2 ==0){
		hasil = (data[(jumlah_data/2)] + data[(jumlah_data/2)+1]) / 2;
	}else {
		hasil = data[(jumlah_data/2)+1];	
	}
	return hasil;
}

float mean(int *data, int jumlah_data){
	float sum = 0;
	float hasil;
	int i;
	for(i=0;i<=jumlah_data;i++){
		sum = sum + data[i];
		
	}
	hasil = sum/(float)jumlah_data;
	return (hasil);
}

float modus(int n, int *data){
	int a=0, b=0, k=1, i, j;
	int total[n];
	float mod[n];
	int temp;
	
//mengurutkan angka yang dimasukan
	for(i=0;i<n;i++){
		for(j=(n-1);j>=0;j--){
			if(data[j] < data[j-1]){
				temp=data[j];
				data[j]= data[j-1];
				data[j-1] = temp;
			}
		}
	}
	
//menghitung jumlah angka yang keluar
	for(i=0;i<n;i++){
		total[i]=0;
		for(j=0;j<i;j++){
			if(data[i] == data[j]){
				total[i]++;
				
			}
		}
	}
	
//menghitung jumlah data yang sering keluar
	for(i=0;i<n;i++){
		if(total[i] > k){
			k = total[i];
		}
	}

//jika terdapat modus lebih dari satu
	for(i=0;i<n;i++){
		if(b==0){
			mod[b]=0;
		}else {
			mod[b]=mod[b-1];
		}
		if(total[i]==k){
			if(data[i]!=mod[b]){
				mod[b] = data[i];
				b++;
				
			}
		}
	}
//jika semua angka sama banyaknya
	for(i=0;i<n;i++){
		if(total[i]==k){
		a++;
		}
	}
	if(a==n){ 
		b=0;
	}
	if (b==0){
		printf("\nTidak ada modus dari data tersebut!\n");
	}else{
		printf("\nHasil Dari Modus Adalah: "); 
		for(i=0;i<b;i++){
			printf(" %.0f", mod[i]);
			
			if(i<b-1){
				printf(",");
			}
		}
		printf("\n");
	}
}
	
void menu_modus(){
	int jumlah_data;
	int data[100];
	int i;
	char ulang;
	
	system("cls");
	printf("           PROGRAM MENGHITUNG MODUS             \n");
	printf("=========================================\n\n\n");
    fflush (stdin);
	printf("Masukkan jumlah data : ");
	jumlah_data = validasi_angka(1);	
	
	for(i=1; i<= jumlah_data; i++){
		printf("Masukkan Data Ke-%d : ", i);
		data[i] = validasi_angka(1);
    }
    
    printf("\n-----------------------------------\n");
 	printf("Nilai Modus\t:");
 	modus(jumlah_data, data);
 		printf("\n\nApakah Anda ingin mengulang untuk menghitung modus ?\nTekan Y untuk mengulang, N untuk kembali ke menu, dan T untuk menutup program.");

	while (1){
   	    printf("\nMasukkan pilihan: ");
   		ulang = exite();
   		
		if (ulang == 'Y' || ulang == 'y'){
			menu_modus();
			break;
		}
		else if (ulang == 'N' || ulang == 'n'){
			main();
			break;
		}
		else if (ulang == 'T' || ulang == 't'){
			keluar();
			break;
		}
		else{
			printf("Inputan salah! Tekan Y untuk mengulang, N untuk kembali ke menu, dan K untuk menutup program.\n\n");
		}
   }
}

void menu_median(){
	int masukan;
	float data[100];
	int i;
	float hasil_median;
	char ulang;
	
	system("cls");
	printf("           PROGRAM MENGHITUNG MEDIAN             \n");
	printf("=========================================\n\n\n");
    fflush (stdin);
	printf("Masukkan jumlah data : ");
	masukan = validasi_angka(1);	
	
	for(i=1; i<= masukan; i++){
		printf("Masukkan Data Ke-%d : ", i);
		data[i] = validasi_angka(1);
    }
    
    hasil_median = median(data, masukan);
    printf("\n-----------------------------------\n");
 	printf("Nilai Median\t: %.2f" ,hasil_median);
	printf("\n\nApakah Anda ingin mengulang untuk menghitung median ?\n Tekan Y untuk mengulang, N untuk kembali ke menu, dan T untuk menutup program.");

	while (1){
   	    printf("\nMasukkan pilihan: ");
   		ulang = exite();
   		
		if (ulang == 'Y' || ulang == 'y'){
			menu_median();
			break;
		}
		else if (ulang == 'N' || ulang == 'n'){
			main();
			break;
		}
		else if (ulang == 'T' || ulang == 't'){
			keluar();
			break;
		}
		else{
			printf("Inputan salah! Tekan Y untuk mengulang, N untuk kembali ke menu, dan K untuk menutup program.\n\n");
		}
   }	
}

void menu_mean(){
	int masukan;
	int data[100];
	int i;
	float hasil_mean;
	char ulang;
	
	system("cls");
	printf("           PROGRAM MENGHITUNG MEAN             \n");
	printf("=========================================\n\n\n");
    fflush (stdin);
	printf("Masukkan jumlah data : ");
	masukan = validasi_angka(1);	
	
	for(i=1; i<= masukan; i++){
		printf("Masukkan Data Ke-%d : ", i);
		data[i] = validasi_angka(1);
    }
    
    hasil_mean = mean(data,masukan);
    printf("\n-----------------------------------\n");
 	printf("Nilai Mean\t: %.2f" ,hasil_mean);
	printf("\n\nApakah Anda ingin mengulang untuk menghitung mean ?\n Tekan Y untuk mengulang, N untuk kembali ke menu, dan T untuk menutup program.");

	while (1){
   	    printf("\nMasukkan pilihan: ");
   		ulang = exite();
   		
		if (ulang == 'Y' || ulang == 'y'){
			menu_mean();
			break;
		}
		else if (ulang == 'N' || ulang == 'n'){
			main();
			break;
		}
		else if (ulang == 'T' || ulang == 't'){
			keluar();
			break;
		}
		else{
			printf("Inputan salah! Tekan Y untuk mengulang, N untuk kembali ke menu, dan K untuk menutup program.\n\n");
		}
   }	
}

void kelompok(){
	char lanjut ='\n';
	char enter;

	printf("======================================================\n");
	printf("\t\t ||Kelompok 20|| \t\t\n");
	printf("======================================================\n");
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
	kelompok();
	system("cls");
	printf("====================================\n");
	printf("\tPROGRAM STATISTIKA\t\t\n");
	printf("====================================\n");
	printf("\tMENU\t\t\n");
	printf("====================================\n");
	printf("\t1.MEAN\t\t\n");
	printf("\t2.MEDIAN\t\t\n");
	printf("\t3.MODUS\t\t\n");
	printf("\t4.Exit\t\t\n");
	printf("====================================\n");
	
	while(1){
		printf("masukan pilihan: ");
		pilih = validasi_angka(1);
		if (pilih == 1){
			menu_mean();
			break;
		}else if (pilih == 2){
			menu_median();
			break;
		}else if (pilih == 3){
			menu_modus();
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



