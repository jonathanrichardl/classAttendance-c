#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define NAMA_SIZE 30
#define NPM_SIZE 20
#define ALAMAT_SIZE 100
#define TELP_SIZE 20


struct Student{
    char nama[NAMA_SIZE];
    char  npm[NPM_SIZE];
    char alamat[ALAMAT_SIZE];
    char  telp[TELP_SIZE];
    int noAbsen;
    struct Student *nextStudent,*prevStudent;
}*class;

struct Absen{
    char nama[NAMA_SIZE];
    char npm[NPM_SIZE];
    int noAbsen;
    int tahun;
    int bulan;
    int tanggal;
    int jam;
    int menit;
    struct Absen *nextStudent,*prevStudent;
}*absen;


void datamenu();
void mainmenu();
void insertStudent(char nama[],char npm[], char alamat[],char telp[],int noAbsen);
void deleteStudent();
void printKelas();
void absensi();
void insertAbsen();
void deleteAbsen();
void printAbsen();
void sortNama();
void sortNPM();
void searchStudent();
void deleteAllStudent();
void swap(struct Student *a,struct Student *b);

void castToFile();
void saveToFile();
void readFromFile();
void help();
char *strcasestr(const char *haystack, const char *needle);

int absenCount=0;
int count;


int main () {
   	system("color 09");
    readFromFile();
    mainmenu();

    return 0;
}

void mainmenu(){
    int i;
    char dump[10];
    for (;;) {
    	printf("      ------------------------------------------------------\n");
    	printf("  ==============================================================\n");
        printf("||                          Proyek akhir                        ||\n");
        printf("||                       Kelompok Rotan (23)                    ||\n");
        printf("||                 Sistem Absensi Kelas SMA Rotan               ||\n");
        printf("||                            SIAK-SR                           ||\n");
        printf("  ==============================================================\n");
        printf("      ------------------------------------------------------\n");
        printf("\n                            Main Menu \n\n");
        printf(" [1] - Data murid\n");
        printf(" [2] - Lakukan Absen\n");
        printf(" [3] - Help\n");
        printf(" [4] - Exit\n");
        printf("\nMasukkan pilihan fungsi\n:");

        scanf("%d", &i);
        gets(dump);

        
        if (i == 1) {
        	system("CLS");
            datamenu();
        }
        else if (i == 2) {
        	system("CLS");
            absensi();
        }
        else if(i==3){
            system("CLS");
            help();
            system("PAUSE");
            system("CLS");
        }
        else if (i == 4){
            printf(" ------------------------------------------------------------\n");
            printf("|                                                            |\n");
            printf("|             Terimakasih sudah menggunakan program          |\n");
            printf("|              by :Ervin Halimsurya (1806195173)             |\n");
            printf("|                  Jonathan Richard (1806147930)             |\n");
            printf("|                                                            |\n");
            printf(" ------------------------------------------------------------\n");
            exit(0);
            break;
        }
        else{
            printf("[Error]Masukkan input sesuai pilihan.\n");
            system("PAUSE");
            system("CLS");
        }
    }
}

void datamenu(){
    int chc;
    char nama[NAMA_SIZE],alamat[ALAMAT_SIZE],dump[10];
    char npm[NPM_SIZE],telp[TELP_SIZE];
    for (;;) {
        printf(" ------------------------------------------------------------\n");
        printf("|                        Menu Data Kelas                     |\n");
        printf(" ------------------------------------------------------------\n");
        printf("[ Jangan lupa untuk menyimpan data setiap kali melakukan perubahan ^_^ ]\n");
        printf("\n");
        printf(" [1] - Tambahkan murid\n");
        printf(" [2] - Hapus murid\n");
        printf(" [3] - Tampilkan data murid dalam kelas\n");
        printf("\n");
        printf(" [4] - Urutkan Nomor Absen murid berdasarkan nama\n");
        printf(" [5] - Urutkan Nomor Absen murid berdasarkan NPM\n");
        printf(" [6] - Lakukan pencarian murid\n");
        printf("\n");
        printf(" [7] - Simpan Data\n");
        printf(" [8] - Hapus semua data murid\n");
        printf(" [9] - Kembali ke menu awal\n");
        printf("\nMasukkan pilihan fungsi\n:");

        scanf("%d", &chc);
        gets(dump);

        
        if (chc == 1) {
        	while (1){ //input nama dengan format yang benar
        		printf("Masukkan Nama \t\t:");
            	gets(nama);
        		if(strcmp(nama,"A")<0){
					printf("[Error] Masukkan input huruf\n");
				}
				else{
					break;
				}
			}
            while(1){ //input npm dengan format yang benar
                printf("Masukkan NPM \t\t:");
                gets(npm);
                
                if(strcmp(npm,"a")>=0){
                    printf("[Error] Masukkan input berupa angka\n");
                }
                else if(strcmp(npm,"0")<0){
                	printf("[Error] Masukkan input berupa angka positif\n");
				}
                else{
                    break; 
                }
	        }
	        while (1){ //input alamat dengan format yang benar
        		printf("Masukkan Alamat \t:");
            	gets(alamat);
        		if(strcmp(alamat,"A")<0){
					printf("[Error] Masukkan input huruf\n");
				}
				else{
					break;
				}
			}
            while(1){ //input nomor telepon dengan format yang benar
                printf("Masukkan No.Telp \t:");
                gets(telp);
                
                if(strcmp(telp,"a")>=0){
                    printf("[Masukkan input berupa angka]\n");
                }
                else if(strcmp(telp,"0")<0){
                	printf("[Error] Masukkan input berupa angka positif\n");
				}
                else{
                    break;
                }
	        }
            count++;
            int noAbsen=count;
            insertStudent(nama,npm,alamat,telp,noAbsen);
            system("CLS");
        }
        else if (chc == 2) {
        	deleteStudent();
            system("PAUSE");
            system("CLS");
        }
        else if(chc==3){
            system("CLS");
            printKelas();
            system("PAUSE");
            system("CLS");
        }
        else if(chc==4){
            sortNama();
            system("PAUSE");
            system("CLS");
        }
        else if(chc==5){
            sortNPM();
            system("PAUSE");
            system("CLS");
        }
        else if (chc==6){
            searchStudent();
            system("PAUSE");
            system("CLS");
        }
        else if(chc==7){
            saveToFile();
            system("PAUSE");
            system("CLS");
        }
        else if(chc==8){
            deleteAllStudent();
            system("PAUSE");
            system("CLS");
        }
        else if (chc == 9){
        	system("CLS");
        	mainmenu();
        	break;
        }
        else{
            printf("[Error] Masukkan input sesuai pilihan.\n");
            system("PAUSE");
            system("CLS");
        }
    }
}

//fungsi untuk menambah data
void insertStudent(char nama[],char npm[], char alamat[],char telp[],int noAbsen) {
   
    struct Student *t, *temp;

    //t untuk menyimpan data input
    
    t = (struct Student*)malloc(sizeof(struct Student));
    strcpy(t->nama,nama);
    strcpy(t->npm,npm);
    strcpy(t->alamat,alamat);
    strcpy(t->telp,telp);
    t->noAbsen=noAbsen;
    //jika belum ada data dan ini adalah data pertama
    if (class == NULL) {
        class = t;
        class->nextStudent=NULL;
        class->prevStudent=NULL;
        return;
    }

    temp = class;
    //iterasi sampai akhir node
    while (temp->nextStudent != NULL){
        temp = temp->nextStudent;
    }
    //jadikan t tadi sebagai node baru dan pastikan prev node baru terhubung dengan node sebelumnya
    temp->nextStudent=t;
    temp->nextStudent->prevStudent=temp;
    temp->nextStudent->nextStudent=NULL;

}

//fungsi untuk menghapus data
void deleteStudent(){
    struct Student *t, *u;
    char dump[10];
    char n[NAMA_SIZE];
    char studName[NAMA_SIZE];
    int found=0,chc;
    char NPM[NPM_SIZE];
    
    //jika linked list kosong
    if (class == NULL) {
        printf("Tidak ada murid dalam data kelas\n\n");
        return;
    }
    //Jika linked list ada isi minta input berdasarkan pilihan nama atau npm
    for(;;){
        printf("\nBerdasarkan :\n[1]-Nama \n[2]-NPM \n");
        printf("(Note) Masukkan angka pilihan\n:");
        scanf("%d",&chc);
        gets(dump);

        //jika mau delete berdasarkan nama
        if (chc==1){
            printf("\nMasukkan nama murid yang ingin dihapus\n");
            printf("(Note)Masukkan nama lengkap murid sesuai dengan yang ada di database atau murid tidak akan terhapus\n: ");
            gets(studName);
    
            t=class;
            //mencari apakah nama yang di cari ada di list
            while(t!=NULL){
                //jika ada found dijadikan 1
                if(strcmp(t->nama,studName)==0){ 
                    found=1; 
                    break; 
                }
                t=t->nextStudent;
            }
        }
        //jika mau delete berdasarkan npm
        else if(chc==2){

            printf("\nMasukkan NPM murid yang ingin dihapus\n:");
            gets(NPM);
    
            t=class;
            //mencari apakah nama yang di cari ada di list
            while(t!=NULL){
                //jika ada found dijadikan 1
                if(strcmp(t->npm,NPM)==0){ 
                    found=1; 
                    break; 
                }
                t=t->nextStudent;
            }
        }
        //jika pilihan tidak sesuai menu
        else{
            printf("\nMasukkan sesuai pilihan yang ada\n");
            system("PAUSE");
            system("CLS");
            datamenu();
        }

        //jika nama atau npm yang ingin dicari ditemukan
        if(found==1){
            count--;
            //jika hanya terdapat data tersebut
            if (class->nextStudent == NULL) {
                strcpy(n,class->nama);
                free(class);
                class = NULL;
                printf("%s telah dihapus dari data kelas\n", n);
                break;
            }
            //jika data merupakan pertama lakukan pop head
            else if(t==class){
                strcpy(n,t->nama);
                class=t->nextStudent;
                free(t);
                printf("%s telah dihapus dari data kelas\n", n);
                break;
            }
            //jika data ada di akhir lakukan pop tail
            else if(t->nextStudent==NULL){
                strcpy(n,t->nama);
                t->prevStudent->nextStudent=NULL;
                free(t);
                printf("%s telah dihapus dari data kelas\n", n);
                break;
            }
            //jika data di tengah lakukan penyambungan data
            else{
                strcpy(n,t->nama);
                t->prevStudent->nextStudent=t->nextStudent;
                t->nextStudent->prevStudent=t->prevStudent;
                free(t);
                printf("%s telah dihapus dari data kelas.\n", n);
                break;
            }   
        }
        //jika data yang dicari tidak ditemukan
        else{
            printf("Murid tidak ditemukan dalam data kelas\n");
            break;
        }
    }

    
}

void deleteAllStudent(){
    struct Student  *next;
    while(class != NULL){
        next = class->nextStudent;
        free(class);
        class = next;
    }
    printf("Semua data (%d data) telah dihapus !\n",count);
    count=0;
}

//print data dengan menelusurinya
void printKelas() {
    struct Student *t;
    int j=1;
    t = class;

    if (t == NULL) {
        printf("\nTidak ada murid di dalam data kelas\n");
        return;
    }
    printf("\n ---------------------------------------\n");
    printf("|           Ada %d murid di kelas       |\n", count);
    printf(" ---------------------------------------\n");
    printf("List : \n");
        printf("No. Absen|              Nama              |       NPM       |       No. Telp       |        Alamat\n");
        printf("---------|--------------------------------|-----------------|----------------------|----------------------\n");
    while (t->nextStudent != NULL) {
        printf("   %-3d   | %-30s | %-15s | %-20s | %-100s\n",t->noAbsen, t->nama,t->npm,t->telp,t->alamat);
        t = t->nextStudent; 
        j++;
    }

    printf("   %-3d   | %-30s | %-15s | %-20s | %-100s\n",t->noAbsen, t->nama,t->npm,t->telp,t->alamat); // Print last Class
}

void absensi(){
    char dump[10];
    int chc;
    char Name[NAMA_SIZE];
    for (;;) {
        printf(" ------------------------------------------------------------\n");
        printf("|                           Menu Absensi                     |\n");
        printf(" ------------------------------------------------------------\n");
        printf("\n");
        printf(" [1] - Masukkkan murid yang sudah hadir\n");
        printf(" [2] - Hapus murid dari daftar absensi\n");
        printf(" [3] - Tampilkan isi daftar absensi\n");
        printf("\n");
        printf(" [4] - Cetak daftar absensi ke file terpisah\n");
        printf(" [5] - Kembali ke menu awal\n");
        printf("\nMasukkan pilihan fungsi \n: ");

        scanf("%d", &chc);
        gets(dump);

        
        if (chc == 1) {
        	while (1){
        		printf("\nMasukkan Nama\n");
        		printf("[Note] Masukkan input 0 untuk berhenti menambahkan\n: ");
    			gets(Name);
    			if(strcmp(Name,"0")==0){
    				printf("Selesai menambahkan\n");
    				break;
				}
				else if(strcmp(Name,"A")<0){
					printf("[Error] Masukkan input huruf\n");
				}
				else{
					insertAbsen(Name);
				}
    			
			}
            system("PAUSE");
            system("CLS");
        }
        else if (chc == 2) {
        	deleteAbsen();
            system("PAUSE");
            system("CLS");
        }
        else if(chc==3){
            system("CLS");
            printAbsen();
            system("PAUSE");
            system("CLS");
        }
        else if(chc==4){
            castToFile();
            system("PAUSE");
            system("CLS");
        }
        else if (chc == 5){
            system("CLS");
        	mainmenu();
        	break;
        }
        else{
            printf("[Error] Tolong masukkan sesuai pilihan\n");
            system("PAUSE");
            system("CLS");
        }
    }
}

void insertAbsen(char targetName[]){
    int found,jam,menit;
    struct Student *tmpClass; 
    
    if (class == NULL) {
        printf("Tidak ada murid dalam daftar kelas\n");
        return;
    }



    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    tmpClass=class;
    
    //mencari apakah nama yang di cari ada di list
    while(tmpClass!=NULL){
        //jika ada found dijadikan 1
        if(strcasestr(tmpClass->nama,targetName)!=NULL){ 
            found=1; 
            break; 
        }
        tmpClass=tmpClass->nextStudent;
    }
    //jika nama yang ingin dicari ditemukan
    if(found==1){
        struct Absen *tmpAbsen,*varStorage;
        varStorage = (struct Absen*)malloc(sizeof(struct Absen));
        strcpy(varStorage->nama,tmpClass->nama);
        strcpy(varStorage->npm,tmpClass->npm);
        varStorage->noAbsen=tmpClass->noAbsen;
        varStorage->tahun=tm.tm_year;
        varStorage->bulan=tm.tm_mon;
        varStorage->tanggal=tm.tm_mday;
        varStorage->jam=tm.tm_hour;
        varStorage->menit=tm.tm_min;

        absenCount++;
        //jika belum ada data di absen
        if (absen == NULL) {
            absen=varStorage;
            absen->nextStudent=NULL;
            absen->prevStudent=NULL;
            printf("%s telah dimasukkan ke absen\n", absen->nama);
            return;
        }
        else{
            tmpAbsen=absen;
            while (tmpAbsen->nextStudent != NULL){
                tmpAbsen = tmpAbsen->nextStudent;
            }
            //jadikan t tadi sebagai node baru dan pastikan prev node baru terhubung dengan node sebelumnya
            tmpAbsen->nextStudent=varStorage;
            tmpAbsen->nextStudent->prevStudent=tmpAbsen;
            tmpAbsen->nextStudent->nextStudent=NULL;
            printf("%s telah dimasukkan ke absen\n", tmpAbsen->nextStudent->nama);
        }
    }
    //jika data yang dicari tidak ditemukan
    else{
        printf("Murid tidak ditemukan dalam data kelas\n");
    }
}

void deleteAbsen(){
    struct Absen *t, *u;
    char n[NAMA_SIZE];
    char studName[NAMA_SIZE];
    int found=0;
    
    //jika linked list kosong
    if (class == NULL) {
        printf("Tidak ada murid dalam daftar kelas\n");
        return;
    }

    //jika linked list ada isi
    printf("Masukkan nama murid yang ingin dihapus\n");
    printf("[Tips] Masukkan nama lengkap murid agar tidak salah hapus\n:");
    gets(studName);
    t=absen;
    //mencari apakah nama yang di cari ada di list
    while(t!=NULL){
        //jika ada found dijadikan 1
        if(strcasestr(t->nama,studName)!=NULL){ 
            found=1; 
            break; 
        }
        t=t->nextStudent;
    }
    //jika nama yang ingin dicari ditemukan
    if(found==1){
        absenCount--;
        //jika hanya terdapat data tersebut
        if (absen->nextStudent == NULL) {
            strcpy(n,absen->nama);
            free(absen);
            absen = NULL;
            printf("%s deleted from absen successfully.\n", n);
            return;
        }
        //jika data merupakan pertama lakukan pop head
        else if(t==absen){
            strcpy(n,t->nama);
			absen=t->nextStudent;
            free(t);
            printf("%s deleted from absen successfully.\n", n);
    
        }
        //jika data ada di akhir lakukan pop tail
        else if(t->nextStudent==NULL){
            strcpy(n,t->nama);
            t->prevStudent->nextStudent=NULL;
            free(t);
            printf("%s deleted from absen successfully.\n", n);

        }
        //jika data di tengah lakukan penyambungan data
        else{
            strcpy(n,t->nama);
            t->prevStudent->nextStudent=t->nextStudent;
            t->nextStudent->prevStudent=t->prevStudent;
            free(t);
            printf("%s deleted from class successfully.\n", n);

        }
    }
    //jika data yang dicari tidak ditemukan
    else{
        printf("Murid tidak ditemukan dalam daftar absen\n");

    }
}

void printAbsen(){
    struct Absen *t;
        int j=1;
        t = absen;

        if (t == NULL) {
            printf("\nAbsen masih kosong\n");
            return;
        }
        printf("\n ---------------------------------------\n");
        printf("|           Ada %d murid di absen      |\n", absenCount);
        printf(" ---------------------------------------\n");
        printf("Absensi hari ini : \n");      
        printf("  No. |   No. Absen  |              Nama               |           NPM          |        Waktu Absen\n");
        printf("------|--------------|---------------------------------|------------------------|---------------------------\n");
        while (t->nextStudent != NULL) {
            printf("   %-3d|      %-5d   | \t%-30s |\t%-15s |\t%d:%d %d-%d-%d\n",j,t->noAbsen, t->nama,t->npm,t->jam,t->menit,t->tanggal,t->bulan,t->tahun);
            t = t->nextStudent;
            j++;
        }
        printf("   %-3d|      %-5d   | \t%-30s |\t%-15s |\t%d:%d %d-%d-%d\n",j,t->noAbsen, t->nama,t->npm,t->jam,t->menit,t->tanggal,t->bulan,t->tahun); // Print last absen
}
void sortNama(){
    struct Student *t;
    struct Student *temp=NULL;
    int swapped;

    //jika data kelas kosong
    if (class == NULL) {
        printf("\nTidak ada data yang bisa diurutkan! \nSihlakan isi data terlebih dahulu\n");
        return;
    }

    //mulai pengurutan dengan menggunakan bubble sort
    do{
        swapped=0;
        t=class;
        while(t->nextStudent!=temp){
            if (strcmp(t->nama,(t->nextStudent->nama))>0){
                swap(t,t->nextStudent);
                swapped=1;
            }
            t=t->nextStudent;
        }
        temp=t;
    }while (swapped); //jika swapped tidak menjadi bernilai 1 lagi artinya data sudah terurut, hentikan loop
    printf("\nPengurutan Berhasil !\n");

}

void sortNPM(){
    struct Student *t;
    struct Student *temp=NULL;
    int swapped;

    //jika data kelas kosong
    if (class == NULL) {
        printf("\nTidak ada data yang bisa diurutkan! \nSihlakan isi data terlebih dahulu\n");
        return;
    }

    do{
        swapped=0;
        t=class;
        while(t->nextStudent!=temp){
            if (strcmp(t->npm, t->nextStudent->npm)>0){
                swap(t,t->nextStudent);
                swapped=1;
            }
            t=t->nextStudent;
        }
        temp=t;
    }
    while (swapped);
    printf("\nPengurutan Berhasil !\n");
}

void swap(struct Student *a,struct Student *b){
    char tempNama[NAMA_SIZE],tempAlamat[ALAMAT_SIZE];
    char tempNPM[NPM_SIZE];
    char tempTelp[TELP_SIZE];


    //swap nama
    strcpy(tempNama,a->nama);
    strcpy(a->nama,b->nama);
    strcpy(b->nama,tempNama);


    //swap npm
    strcpy(tempNPM,a->npm);
    strcpy(a->npm,b->npm);
    strcpy(b->npm,tempNPM);

    strcpy(tempAlamat,a->alamat);
    strcpy(a->alamat,b->alamat);
    strcpy(b->alamat,tempAlamat);

    strcpy(tempTelp,a->telp);
    strcpy(a->telp,b->telp);
    strcpy(b->telp,tempTelp);

}

void searchStudent(){
    struct Student *t;
    char dump[10];
    char studName[NAMA_SIZE];
    int found=0,chc;
    char NPM[NPM_SIZE];
    int searchCount=1;
    //jika linked list kosong
    if (class == NULL) {
        printf("Tidak ada murid dalam daftar kelas\n");
        return;
    }
    //Jika linked list ada isi minta input berdasarkan pilihan nama atau npm
    for(;;){
        
        printf("Berdasarkan :\n[1]-Nama \n[2]-NPM \n");
        printf("(Note) Masukkan angka pilihan\n:");
        scanf("%d",&chc);
        gets(dump);

        //jika mau mencari berdasarkan nama
        if (chc==1){
            printf("\nMasukkan nama murid yang ingin dicari\n");
            printf("[Tips]Nama yang dimasukkan tidak perlu nama lengkap\n: ");
            gets(studName);
    
            t=class;
            //mencari apakah nama yang di cari ada di list
            while(t!=NULL){
                //jika ada found dijadikan 1
                if(strcasestr(t->nama,studName)!=NULL){ 
                    found=1; 
                    break; 
                }
                searchCount++;
                t=t->nextStudent;
            }
        }
        //jika mau mencari berdasarkan npm
        else if(chc==2){

            printf("\nMasukkan NPM murid yang ingin dicari\n:");
            gets(NPM);
    
            t=class;
            //mencari apakah nama yang di cari ada di list
            while(t!=NULL){
                //jika ada found dijadikan 1
                if(strcmp(t->npm,NPM)==0){ 
                    found=1; 
                    break; 
                }
                searchCount++;
                t=t->nextStudent;
            }
        }
        //jika pilihan tidak sesuai menu
        else{
            printf("\nMasukkan sesuai pilihan yang ada\n");
            system("PAUSE");
            system("CLS");
            datamenu();
        }


        //jika nama atau npm yang ingin dicari ditemukan
        if(found==1){
        	printf("\n");
        	printf("   No. Absen   |          Nama             |        NPM        |              Alamat              |    No. Telp\n");
            printf(" \t%-3d    |      %-20s |   %-15s |   %-30s |   %-15s \n",t->noAbsen, t->nama,t->npm,t->alamat,t->telp);
            break;
        }   
        //jika data yang dicari tidak ditemukan
        else {
            printf("Murid tidak ditemukan dalam data kelas\n");
            break;
        }
    }
        
}

void castToFile(){
    char filename[30];
    struct Absen *t;
    struct Student *tempClass;
    int j=1;
    int found=0;
    
    if (t == NULL) {
        printf("\nAbsen masih kosong\n");
        return;
    }
    printf("Masukkan nama file untuk absen ini\n(Note) Gunakan.txt dan jangan ada spasi. Contoh : nama.txt\n:");
    scanf("%s",filename);
    FILE *f = fopen(filename, "w");
    if (f == NULL){
        printf("Error opening file!\n");
        exit(1);
    }
    //print ke file terpisah
    t = absen;
    fprintf(f," --------------------------------\n");
    fprintf(f,"| Murid yang Hadir pada %d/%d/%d |\n",t->tanggal,t->bulan,t->tahun);
    fprintf(f," --------------------------------\n");
    fprintf(f,"  No. |   No. Absen  |              Nama               |           NPM          |        Waktu Absen\n");
    fprintf(f,"------|--------------|---------------------------------|------------------------|---------------------------\n");
    while (t->nextStudent != NULL) {
        fprintf(f,"   %-3d|      %-5d   | \t%-30s |\t%-15s |\t%d:%d %d-%d-%d\n",j,t->noAbsen, t->nama,t->npm,t->jam,t->menit,t->tanggal,t->bulan,t->tahun);
        t = t->nextStudent;
        j++;
    }
    fprintf(f,"   %-3d|      %-5d   | \t%-30s |\t%-15s |\t%d:%d %d-%d-%d\n",j,t->noAbsen, t->nama,t->npm,t->jam,t->menit,t->tanggal,t->bulan,t->tahun); // Print last absen
    
	//Untuk mencetak murid yang tidak hadir
    tempClass=class;
    j=1;
    fprintf(f,"\n\n");
    fprintf(f," -------------------------------\n");
    fprintf(f,"| Murid yang absen (Tidak Hadir)|\n");
    fprintf(f," -------------------------------\n");
    fprintf(f,"  No. |   No. Absen  |              Nama               |           NPM          |\n");
    fprintf(f,"------|--------------|---------------------------------|------------------------|\n");
    while (tempClass!=NULL){ 
        t=absen;
        //program akan mengecek apakah data murid yang sekarang ada pada daftar absen 1 per 1
        while (t!=NULL){
            if (strcmp(t->nama,tempClass->nama)==0){ //jika data murid yang sekarang ada di daftar absen set found=1 artinya ditemukan
                found=1;
                break;
            }
            else{
                t=t->nextStudent;
            }
        }
        if(found==0){ //jika data ditemukan maka tidak lakukan apa-apa, tetapi jika tidak ditemukan, print data murid saat ini
            fprintf(f,"   %-3d|      %-5d   | \t%-30s |\t%-15s \n",j,tempClass->noAbsen, tempClass->nama,tempClass->npm);
            j++;
        }
        found=0; //reset status found
        tempClass=tempClass->nextStudent; //lanjut ke data murid berikutnya
    }

    fclose(f);
    printf("Pencetakan Berhasil !\n");
}

void saveToFile(){
    int i;
    int n;
	FILE *data;
    struct Student *tmp;
	data = fopen("database.bin","wb");
    tmp=class;
    if (data==NULL) {
        printf("failed to save.\n");
        return ;
    }
    while(tmp!=NULL){
        fwrite((tmp->nama), sizeof (tmp->nama), 1, data);
        fwrite((tmp->npm), sizeof (tmp->npm), 1, data); 
        fwrite((tmp->alamat), sizeof (tmp->alamat), 1, data); 
        fwrite((tmp->telp), sizeof (tmp->telp), 1, data); 
        fwrite(&(tmp->noAbsen),sizeof(tmp->noAbsen),1,data);
        tmp=tmp->nextStudent;
    }
    fclose(data);
    printf("Berhasil menyimpan %d data !\n",count);
}

void readFromFile(){
    int rlen;
    FILE *data = fopen("database.bin", "rb") ;
    if (data == NULL){
        printf("Error opening file\n");
        return;
    }
    else{
        while(1){
            struct Student *a;
            a = (struct Student*)malloc(sizeof(struct Student));
            // NOTE: do this for good measure
            a->nextStudent = NULL;

            rlen=fread(a->nama, sizeof a->nama, 1, data);
            if (rlen != 1)
                break;
            fread((a->npm), sizeof a->npm, 1, data);
            if (rlen != 1)
                break;
            fread(a->alamat, sizeof a->alamat, 1, data);
            if (rlen != 1)
                break;
            fread((a->telp), sizeof a->telp, 1, data);
            if (rlen != 1)
                break;
            fread(&(a->noAbsen), sizeof a->noAbsen, 1, data);
            if (rlen != 1)
                break;

            count++;
            insertStudent(a->nama,a->npm,a->alamat,a->telp,a->noAbsen);
        }
        fclose(data);
    }
    
}

void help(){
    int chc;
    char dump[10];
    for(;;){
    	printf(" ------------------------------------------------------------\n"); 
        printf("|                             Help                           |\n");
        printf(" ------------------------------------------------------------\n");
        printf("\n");
        printf(" Program ini merupakan program dengan 2 fungsi utama, yaitu pendataan murid dan juga absensi murid\n");
        printf(" Fungsi mana yang ingin anta ketahui lebih lanjut?\n");
        printf(" 1 - Pendataan Murid\n 2 - Absensi murid\n 3 - Kembali ke menu awal\n");
        printf("\nMasukkan pilihan fungsi \n: ");
        scanf("%d",&chc);
        gets(dump);
        if(chc==1){
            printf("Di dalam menu ini, terdapat 9 pilihan fungsi yang dapat digunakan\n");
            printf(" Pada menu ini, pengguna dapat :\n");
            printf(" 1. Menambahkan data murid baru kedalam kelas\n 2. Menghapus data murid berdasarkan Nama atau NPM-nya\n");
            printf(" 3. Menampilkan data murid yang ada saat ini\n 4. Mengurutkan nomor urut murid berdasarkan nama\n 5. Mengurutkan nomor urut murid berdasarkan NPM\n");
            printf(" 6. Melakukan pencarian murid tertentu berdasarkan Nama atau NPM-nya\n 7. Melakukan penyimpanan data pada file eksternal agar data dapat diakses kembali setelah program ditutup. Perubahan pada data hanya akan tersimpan setiap pengguna memilih fungsi ini\n");
            printf(" 8. Menghapus semua data murid yang ada di kelas\n 9. kembali ke menu awal\n");
            system("PAUSE");
            system("CLS");
        }
        else if(chc==2){
            printf("Pada menu absen, terdapat 5 fungsi utama yang dapat dipilih oleh pengguna\n");
            printf(" Pada menu ini, pengguna dapat :\n");
            printf(" 1. Menambahkan nama murid ke dalam daftar absen apabila murid telah hadir. Waktu akan direkam secara otomatis sesuai dengan waktu perangkat\n 2. Menghapus murid dari daftar absen berdasarkan nama-nya\n");
            printf(" 3. Menampilkan list isi absen saat ini\n 4. Mencetak absen saat ini ke file text eksternal. Berbeda dengan data murid, absen tidak disimpan secara permanen, tetapi pengguna dapat mencetak daftar absen ahri tersebut menjadi file tulisan\n");
            printf(" 5. kembali ke menu awal\n");
            system("PAUSE");
            system("CLS");
        }
        else if(chc==3){
        	system("CLS");
            mainmenu();
        }
        else{
            printf("Masukkan input sesuai dengan pilihan\n");
            system("PAUSE");
            system("CLS");
        }
    }

}

//Fungsi untuk melakukan compare string tanpa memperdulikan spasi dan huruf kapital
char *strcasestr(const char *haystack, const char *needle) {
    size_t i;

    //Kondisi spesial jika needle kosong
    if (!*needle){
        return (char*)haystack;
    }
    //Lakukan pencarian string needle pada string di haystack
    for (; *haystack; haystack++) {
        //perbandingan menggunakan toupper agar string yang dibandingkan semuanya kapital, sehingga mengabaikan string awal kapital atau tidak
        if (toupper((unsigned char)*haystack) == toupper((unsigned char)*needle)) {
            //perbandingan huruf-huruf berikutnya ketika huruf awal sudah sama
            //looping sampai huruf terakhir pada needle
            for (i = 1;; i++) {
                //jika tidak ada huruf berikutnya pada needle, berarti sudah ada kesamaan
                if (!needle[i]){
                    return (char*)haystack;
                }
                //Jika huruf berikutnya tidak sama maka hentikan loop
                if (toupper((unsigned char)haystack[i]) != toupper((unsigned char)needle[i])){
                    break;
                }
            }
        }
    }
    //jika tidak ada kesamaan sama sekali return null
    return NULL;
}
 
