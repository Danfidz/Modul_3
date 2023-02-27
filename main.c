/** EL2208 Praktikum Pemecahan Masalah dengan C 2022/2023
 *   Modul               :
 *   Hari dan Tanggal    :
 *   Nama (NIM)          :
 *   Nama File           : main.c
 *   Deskripsi           :
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 255

// Kerjakan soal dengan konsep pointer
// Fungsi yang disediakan hanya referensi untuk menjawab soal.
// Silahkan ubah parameter fungsi atau menambah/mengurangi fungsi sesuai keperluan

void tambah_senjata(int *HP, int *atk, int *cRate, int *cDam, int *ER, int *EM,char senjata)
{ // Lengkapi parameter
    if (senjata == 1)
    {
        *atk += 400;
        *cRate = *cRate + (28);
    }
    else if (senjata == 2)
    {
        *atk += 600;
        *cDam = *cDam + (66);
    }
    else if (senjata == 3)
    {
        *atk += 550;
        *cDam = *cDam + (88);
    }
    else if (senjata == 4)
    {
        *atk += 600;
        *ER = *ER + (*ER * 56 / 100);
    }
    else if (senjata == 5)
    {
        *atk += 540;
        *EM = *EM + 265;
    }
    // Lengkapi fungsi
}

void tambah_artifak(int *HP, int *atk, int *cRate, int *cDam, int *ER, int *EM, char senjata)
{ // Lengkapi parameter
    if (senjata == 1)
    {
        *HP = *HP + (*HP * 20 / 100);
        *atk = *atk + (*atk * 20 / 100);
    }
    else if (senjata == 2)
    {
        *ER = *ER + (*ER * 20 / 100);
        *EM = *EM + 80;
    }
    else if (senjata == 3)
    {
        *cRate = *cRate + 12;
        *cDam = *cDam + 24;
    }
    else if (senjata == 4)
    {
        *atk *= 115/100;
        *EM = *EM + 80;
    }
    else if (senjata == 5)
    {
        *atk = *atk + (*atk * 20 / 100);
        *cRate = *cRate + (*cRate * 10 / 100);
    }
    // Lengkapi fungsi
}

int main()
{
    char nama_file[MAX_LEN];
    char nama[MAX_LEN];
    char list_senj[MAX_LEN];
    char temp[MAX_LEN];
    char list_buff[255];

    int c1, c2, c3, c4, c5;
    
    int HP ;
    int atk ;
    int cRate ;
    int cDam;
    int ER;
    int EM ;


    char string[1024];

    // list_buff nama file
    printf("Gensin Impek - Berpetualang di Dunia Fantasi\n");
    printf("Masukkan nama file yang berisi status karakter: ");
    scanf("%s", nama_file);

    // Validasi File
    FILE *fp;
    fp = fopen(nama_file, "r");
    if (fp == NULL)
    {
        printf("File tidak dapat dibuka. Program Berakhir.");
    }
    else
    {
        // list_buff nomor senjata dan set artifak
        printf("Masukkan nomor senjata, set artifak 1, dan set artifak 2: ");
   scanf("%d %d %d", &c1, &c2, &c3);
//    printf("%d %d %d", c1,c2,c3);

        // fgets(string, 2, fp);
        // printf("%s", string);
        int line = 1;
        while (fgets(string, 1024, fp) != NULL)
        {
            // printf("%s", string); // print each line
            if (line == 1) {
                int pjg = strlen(string);
                strncpy(nama, string, pjg-1); 
            }
            else if (line == 2) {strcpy(list_senj, string); }
            line++;
        }
        fclose(fp); // close file
        // printf("%s", nama); // print each line
        // printf("%s", list_senj); // print each line


        const char s[2] = ",";
        char *token;
        token = strtok(list_senj, s);

        int kata =1;
        while( token != NULL ) {
            // printf( " %s\n", token );
            strcpy(temp, token);
            if (kata == 1){HP = atoi(temp);}
            else if (kata == 2){atk = atoi(temp);}
            else if (kata == 3){cRate = atoi(temp);}
            else if (kata == 4){cDam = atoi(temp);}
            else if (kata == 5){ER = atoi(temp);}
            else if (kata == 6){EM = atoi(temp);};
            token = strtok(NULL, s);
            kata++;
        }

        int senjata1 = c1;
        int artefak1 = c2;
        int artefak2 = c3;
        // printf("%s\n", list_buff);
        // printf("%c %c %c\n",senjata1, artefak1, artefak2);
        // printf("%d, %d, %d, %d, %d, %d\n", HP, atk, cRate, cDam, ER, EM);

        tambah_senjata(&HP, &atk, &cRate, &cDam, &ER, &EM, senjata1);
        tambah_artifak(&HP, &atk, &cRate, &cDam, &ER, &EM, artefak1);
        tambah_artifak(&HP, &atk, &cRate, &cDam, &ER, &EM, artefak2);
        printf("Status akhir karakter %s setelah menggunakan senjata dan artifak adalah:\n", nama);
        printf("HP: %d\n", HP);
        printf("ATK: %d\n", atk);
        printf("Crit Rate: %d%%\n", cRate );
        printf("Crit Damage: %d%%\n", cDam );
        printf("ER: %d%%\n", ER);
        printf("EM: %d\n", EM);
        // printf("%d, %d, %d, %d, %d, %d", HP, atk, cRate, cDam, ER, EM);

        // // Print Akhir
        // printf("Status akhir karakter %s setelah menggunakan senjata dan artifak adalah:\n",...);
        // printf("HP: \n",...);
        // printf("ATK: \n",...);
        // printf("Crit Rate: \n",...);
        // printf("Crit Damage: \n",...);
        // printf("ER: \n",...);
        // printf("EM: \n",...);
    }
    return 0;
}
