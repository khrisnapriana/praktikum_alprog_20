#include <stdio.h>

void koreksi(int *var, char *prompt){
	while(1){
		printf(prompt);
		if(valid(var))
			break;
		printf("\n\t\tHanya menerima input berupa angka!!\n");
	}
}

int valid(int *var){
	char buff[1024];
	char cek;
	fflush(stdin);
	if(fgets(buff, sizeof(buff), stdin) != NULL){
		if(sscanf(buff, "%d %f", var, &cek) == 1) {
			return 1;
		}
	}
	return 0;
}

int cek_validasi();
int cek_validasi(){
	int bilangan;
    char huruf;
    scanf("%d%c", &bilangan,&huruf);
    if(huruf != '\n' || bilangan<0){
        printf("\n\tHanya menerima input berupa angka!");
        printf("\n\tMasukkan Angka yang benar \t: ");
        fflush(stdin);
        cek_validasi();
    }
	else{
        return bilangan;
    }
}

struct pegawai{
	
	int jam_kerja;
	int gaji_perjam;
	int gaji_lembur;
	int gaji_harian;

};
//fungsi header tampilan atas
void header(){
	printf("\n\t\t\t\xda==========================================\xbf\n");
	printf("\t\t\t||	     PROGRAM MENGHITUNG		  ||\n");
	printf("\t\t\t||	    GAJI HARIAN & LEMBUR	  ||\n"); 
	printf("\t\t\t||              KELOMPOK 20               ||\n");
	printf("\t\t\t\xc0==========================================\xd9\n\n");
}


int main() {
	
	int pilih;
	char ulang;	
	struct pegawai pegawai01;
	
	do{
		
		system("cls");
		header();
		printf("\t\tMenghitung Gaji Harian");
		printf("\n\n\t\t[1]. Hitung Gaji");
		printf("\n\n\t\t[2]. Keluar");
		koreksi(&pilih, "\n\n\t\tMasukkan Pilihan Anda : ");
		
//		
		if(pilih==1){
			system("cls");
			header();
			printf("\n\n\t\tMasukkan Jumlah Jam Kerja : ");
			pegawai01.jam_kerja = cek_validasi();
			
			if(pegawai01.jam_kerja>8){
				pegawai01.gaji_perjam = 8 * 10625;
				pegawai01.gaji_lembur = (pegawai01.jam_kerja - 8) * 10625 * 8;
				pegawai01.gaji_harian = pegawai01.gaji_perjam + pegawai01.gaji_lembur;
				printf("\n\t\t\xda================================================\xbf\n");
				printf("\t\t|| Gaji perjam anda adalah    |\tRp.%d	||", pegawai01.gaji_perjam);
				printf("\n\t\t||----------------------------------------------||");
				printf("\n\t\t|| Gaji lembur anda adalah    |\tRp.%d	||", pegawai01.gaji_lembur);
				printf("\n\t\t||----------------------------------------------||");
				printf("\n\t\t|| TOTAL                                        ||");
				printf("\n\t\t|| Gaji harian anda adalah    |\tRp.%d	||", pegawai01.gaji_harian);
				printf("\n\t\t\xc0================================================\xd9\n");
				printf("\n\n\t\tApakah anda ingin mencoba lagi? (Y/N) ");
				scanf("%s", &ulang);
			} else if(pegawai01.jam_kerja<=8){
				pegawai01.gaji_perjam = pegawai01.jam_kerja * 10625;
				printf("\n\t\t\xda================================================\xbf\n");
				printf("\t\t|| Gaji perjam anda adalah	|\t%d	||", pegawai01.gaji_perjam);
				printf("\n\t\t||----------------------------------------------||");
				printf("\n\t\t|| Gaji lembur anda adalah	|\t-	||");
				printf("\n\t\t||----------------------------------------------||");
				printf("\n\t\t|| Gaji harian anda adalah	|\t%d	||", pegawai01.gaji_perjam);
				printf("\n\t\t\xc0================================================\xd9\n");
				printf("\n\n\t\tApakah anda ingin mencoba lagi? (Y/N) ");
				scanf("%s", &ulang);
			}	
		}
		else if(pilih==2){
			printf(" ");
		}else{
			printf("\n\t\tPilihan tidak tersedia!\n");
			printf("\n\t\tIngin memilih lagi? (Y/N) ");
			scanf("%s", &ulang);
		}	
	}while (ulang=='Y'||ulang=='y');
	
	do{
		return printf("\n\n\t\tTerima Kasih Sudah Menggunakan Program Kami!");
	}while (ulang=='N'||ulang=='n');
}
