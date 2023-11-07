#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct film {
    int durasi;
    int rating;
    int usia;
    int nom;
    char judul[100];
    char studio[100];
    char sinopsis[10000];
    char genre[100];
    int rilis, date, moon, year;
    struct film *right;
    struct film *left;
};

void penyimpananFilm(struct film *action, struct film *comedy, struct film *scifi, struct film *romance, struct film *horror, struct film *animation){
    struct film *baruP;
    int i;
    char dataFilm[1000][1000];

    strcpy(dataFilm[1], "Transformer Rise Of The Beast");
    strcpy(dataFilm[2], "Marmut Merah Jambu");
    strcpy(dataFilm[3], "Avatar The Way Of Water");
    strcpy(dataFilm[4], "Aladdin");
    strcpy(dataFilm[5], "Pengabdi Setan Dua");
    strcpy(dataFilm[6], "Spiderman Across The Spiderverse");

    strcpy(dataFilm[7], "Paramount Pictures");
    strcpy(dataFilm[8], "Starvision Plus");
    strcpy(dataFilm[9], "20th Century Studio");
    strcpy(dataFilm[10], "Walt Disney Studios");
    strcpy(dataFilm[11], "Rapi Film");
    strcpy(dataFilm[12], "Sony Pictures");

    strcpy(dataFilm[13], "Kembali ke aksi dan tontonan yang telah memikat penonton, \nTransformers: Rise of the Beasts akan membawa penonton \ndalam petualangan keliling dunia tahun 90-an dengan Autobots \ndan memperkenalkan generasi baru Transformer Maximals ke pertempuran \nyang ada di bumi antara Autobots dan Decepticons.");
    strcpy(dataFilm[14], "Dika menceritakan kisah cinta pertamanya saat SMA dengan cewek \nbernama Ina Mangunkusumo. Cerita ketika dia dan temannya \nBertus membentuk sebuah grup detektif, dan juga \npersahabatannya dengan Cindy.");
    strcpy(dataFilm[15], "Lebih dari satu dekade setelah peristiwa film pertama, \nAvatar: The Way of Water mulai menceritakan kisah keluarga Sully \n(Jake, Neytiri, dan anak-anak mereka), masalah yang mengikuti mereka, \nsejauh mana mereka pergi. untuk menjaga keamanan satu sama lain, \npertempuran yang mereka lakukan untuk tetap hidup, \ndan tragedi yang mereka alami.");
    strcpy(dataFilm[16], "Aladdin, seorang anak jalanan yang jatuh cinta pada seorang putri. \nDengan perbedaan kasta dan harta, Aladdin pun berusaha mencari jalan \nagar bisa mejadi seorang pangeran, tak disangka ia menemukan lampu \ndengan jin di dalamnya. Aladdin pun menggunakan lampu untuk \nmengubah dirinya menjadi seorang pangeran untuk memenangkan hati \nPutri Jasmine, tapi Wazir jahat juga mengejar \nlampu tersebut untuk menguasai kerajaan.");
    strcpy(dataFilm[17], "Beberapa tahun setelah berhasil menyelamatkan diri dari \nkejadian mengerikan yang membuat mereka kehilangan ibu \ndan si bungsu Ian, Rini dan adik-adiknya, Toni dan Bondi, \nserta Bapak tinggal di rumah susun \nkarena percaya tinggal di rumah susun aman \njika terjadi sesuatu karena ada banyak orang.");
    strcpy(dataFilm[18], "Miles Morales hadir kembali dalam babak baru saga Spider-Verse. \nUsai berjumpa lagi dengan Gwen Stacy, Spider-Man si tetangga \nyang ramah asal Brooklyn ini terlontar melintasi Multiverse \nyang membawanya pada Spider Society, kelompok pahlawan manusia laba-laba \nyang bertugas melindungi kelangsungan Multiverse.");

    int dataF[37] = {0, 127, 91, 192, 128, 119, 117,
                    94, 93, 88, 86, 92, 97,
                    13, 13, 13, 5, 13, 5,
                    7, 8, 14, 4, 24, 31,
                    6, 5, 12, 8, 5, 5,
                    2023, 2014, 2022, 2019, 2022, 2023};

    for(i = 1; i<=6; i++){
        baruP = (struct film*) malloc(sizeof(struct film));
        strcpy(baruP->judul, dataFilm[i]);
        strcpy(baruP->studio, dataFilm[i+6]);
        strcpy(baruP->sinopsis, dataFilm[i+12]);
        baruP->durasi = dataF[i];
        baruP->rating = dataF[i+6];
        baruP->usia = dataF[i+12];
        baruP->date = dataF[i+18];
        baruP->moon = dataF[i+24];
        baruP->year = dataF[i+30];
        baruP->rilis = dataF[i+18] + (dataF[i+24] * 100) + (dataF[i+30] * 1000);
        baruP->right = NULL;

        if(i == 1){
            action->right = baruP;
            baruP->left = scifi;
        }
        else if(i == 2){
            comedy->right = baruP;
            baruP->left = romance;
        }
        else if(i == 3){
            scifi->right = baruP;
            baruP->left = action;
        }
        else if(i == 4){
            romance->right = baruP;
            baruP->left = comedy;
        }
        else if(i == 5){
            horror->right = baruP;
            baruP->left = action;
        }
        else if(i == 6){
            animation->right = baruP;
            baruP->left = action;
        }
    }
}

void inputStorage(struct film *action){
    int i;
    FILE *file = fopen("data_film.txt", "w");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    struct film *current, *move;
    current = move = action;
    for(i = 1; i <= 6; i++){
        current = current->right;
        while (current != NULL) {
            fprintf(file, "<<<==<>==<>==<>==<>============<</<{<>}>/>>==========<>==<>==<>==<>==>>>\n");
            fprintf(file, "Genre: %s / %s\n", move->genre, current->left->genre);
            fprintf(file, "Judul: %s\n", current->judul);
            fprintf(file, "Studio: %s\n", current->studio);
            fprintf(file, "Durasi: %d\n", current->durasi);
            fprintf(file, "Rating: %d\n", current->rating);
            fprintf(file, "Usia: %d\n", current->usia);
            fprintf(file, "Tanggal Rilis: %d/%d/%d\n", current->date, current->moon, current->year);
            fprintf(file, "Sinopsis: %s\n", current->sinopsis);
            fprintf(file, "<<<==<>==<>==<>==<>============<</<{<>}>/>>==========<>==<>==<>==<>==>>>");
            fprintf(file, "\n");

            current = current->right;
        }
        move = move->left;
        current = move;
    }

    fclose(file);
}

void bacaDataFilm(struct film *action) {
    FILE *file = fopen("data_film.txt", "r");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    char buffer[1000];
    int i = 1;

    while (fgets(buffer, sizeof(buffer), file)) {
        if (strncmp(buffer, "Judul:", 6) == 0) {
            sscanf(buffer, "Judul: %[^\n]", action[i].judul);
        } else if (strncmp(buffer, "Studio:", 7) == 0) {
            sscanf(buffer, "Studio: %[^\n]", action[i].studio);
        } else if (strncmp(buffer, "Sinopsis:", 9) == 0) {
            sscanf(buffer, "Sinopsis: %[^\n]", action[i].sinopsis);
        } else if (strncmp(buffer, "Durasi:", 7) == 0) {
            sscanf(buffer, "Durasi: %d", &action[i].durasi);
        } else if (strncmp(buffer, "Rating:", 7) == 0) {
            sscanf(buffer, "Rating: %d", &action[i].rating);
        } else if (strncmp(buffer, "Usia:", 5) == 0) {
            sscanf(buffer, "Usia: %d", &action[i].usia);
        } else if (strncmp(buffer, "Tanggal Rilis:", 14) == 0) {
            sscanf(buffer, "Tanggal Rilis: %d/%d/%d", &action[i].date, &action[i].moon, &action[i].year);
        } else if (strncmp(buffer, "Genre:", 6) == 0) {
            sscanf(buffer, "Genre: %[^\n]", action[i].genre);
            i++;
        }
    }

    fclose(file);
}

void displayFilm(struct film *temp, struct film *tem, int sortR[100], int sortD[100], int total[1]){
    int i;
    int j = 1;

    for(i = 1 ; i<=6 ; i++){
        tem = temp;
        while(tem->right != NULL){
            tem = tem->right;
            printf("\t\t<<<==<>==<>==<>==<<[{={<>}=}]>>==<>==<>==<>==>>>\n");
            printf("\t\t<<<==<>==<>==<>==<>==<>==<>==<>==<>==<>==<>==>>>\n");
            printf("\t\tJudul Film : %s \n\t\tGenre : %s / %s \n\t\tStudio Distribusi : %s\n", tem->judul, temp->genre, tem->left->genre, tem->studio);
            printf("\t\tTanggal Rilis : %d - %d - %d \n\t\tRating Film : %d \n\t\tUntuk Usia : %d+\n", tem->date, tem->moon, tem->year, tem->rating, tem->usia);
            printf("\t\t<<<==<>==<>==<>==<>==<>==<>==<>==<>==<>==<>==>>>\n");
            printf("\t\t<<<==<>==<>==<>==<<[{={<>}=}]>>==<>==<>==<>==>>>\n\n");
            sortR[j] = tem->rating;
            sortD[j] = tem->rilis;
            j++;
        }
        temp = temp->left;
    }
    tem = temp;

    total[1] = j;
}

void sinopsis(struct film *temp, struct film *tem){
    char jwb[200];
    int count = 1;
    printf("\nIngin Membaca Sinopsis Film apa? \n(Judul mohon disesuaikan persis dengan yang ditampilkan di atas) \n:: ");
    getchar();
    gets(jwb);

    while(strcmp(jwb, tem->judul) != 0 && count < 8)
    {
        if(tem->right == NULL){
            temp = temp->left;
            tem = temp;
            count++;
        }
        tem = tem->right;
    }
    if(count == 8){
        printf("\nData dengan judul %s tidak ditemukan!", jwb);
    }
    else{
        printf("\nSinopsis dari film %s : \n%s", jwb, tem->sinopsis);
    }
}

void tambahFilm(struct film *temp, struct film *tem){
    struct film *baruP;
    int dataF;
    char jwb[100], dataFilm[1000][1000];

    printf("Genre utama film yang ingin kamu tambahkan : ");
    scanf("%s", &jwb);

    while(strcmp(jwb, temp->genre) != 0){
        temp =temp->left;
        printf("test");
    }
    tem = temp->right;
    while(tem->right != NULL){
        tem = tem->right;
    }

    printf("\nMasukan data film tersebut\n");
    baruP = (struct film*) malloc(sizeof(struct film));
    printf("Judul Film : ");
    getchar();
    gets(dataFilm[1]);
    strcpy(baruP->judul, dataFilm[1]);
    printf("Studio Film : ");
    getchar();
    gets(dataFilm[2]);
    strcpy(baruP->studio, dataFilm[2]);
    printf("Sinopsis Film : ");
    getchar();
    gets(dataFilm[3]);
    strcpy(baruP->sinopsis, dataFilm[3]);
    printf("Durasi Film : ");
    scanf("%d", &dataF);
    baruP->durasi = dataF;
    printf("Rating Film : ");
    scanf("%d", &dataF);
    baruP->rating = dataF;
    printf("Rating Usia Film : ");
    scanf("%d", &dataF);
    baruP->usia = dataF;
    printf("Tanggal Rilis Film (hanya tanggal saja tidak berisi bulan dan tahun) : ");
    scanf("%d", &dataF);
    baruP->date = dataF;
    printf("Bulan Rilis Film : ");
    scanf("%d", &dataF);
    baruP->moon = dataF;
    printf("Tahun Rilis Film : ");
    scanf("%d", &dataF);
    baruP->year = dataF;
    baruP->right = NULL;
    tem->right = baruP;

    printf("Masukan sub genre film : ");
    getchar();
    gets(dataFilm[4]);

    while(strcmp(dataFilm[4], temp->genre) != 0){
        temp = temp->left;
    }
    baruP->left = temp;
}

void hapusFilm(struct film *tem, struct film *temp){
    struct film *tem2;
    char jwb[100];
    int i;
    int count = 1;
    tem = temp;
    tem2 = temp;

    printf("Judul film yang ingin kamu hapus\n");
    printf("(sesuiakan dengan judul yang tertera di atas) : ");
    getchar();
    gets(jwb);

    tem = tem->right;
    while(strcmp(jwb, tem->judul) != 0 && count < 8){
        tem2 = tem;
        tem = tem2->right;
        if(tem == NULL){
            temp = temp->left;
            tem2 = tem = temp;
            count++;
        }
    }
    if(count == 8){
        printf("\nData dengan judul %s tidak ditemukan!", jwb);
    }
    else {
        printf(" . ");
        sleep (1);
        printf(" . ");
        sleep (1);
        printf(" . ");
        sleep (1);
        tem2->right = tem->right;
        free(tem);
        tem = tem2 = temp;
        printf("\nData film dengan judul %s telah terhapus", jwb);
    }
}

void sortingRating(int sortR[100], int ttl, struct film *temp, struct film *tem){
    int t = 0;
    int i, j;
    int pilihan;

    printf("<<<==<>==<>==<>==<>================<</<{<>}>/>>==============<>==<>==<>==<>==>>>\n");
    printf("Pilih urutan : \n1. Terbesar \n2. Terkecil \nPilihanmu : ");
    scanf("%d", &pilihan);
    printf("<<<==<>==<>==<>==<>================<</<{<>}>/>>==============<>==<>==<>==<>==>>>\n\n");

    if(pilihan == 1){
        for(i=1; i<ttl; i++){
            for(j=1; j<ttl; j++){
                if(sortR[j] < sortR[j+1]){
                    t = sortR[j];
                    sortR[j] = sortR[j+1];
                    sortR[j+1] = t;
                }
            }
        }
    }

    else if(pilihan == 2){
        for(i=1; i<ttl-1; i++){
            for(j=1; j<ttl-1; j++){
                if(sortR[j] > sortR[j+1]){
                    t = sortR[j];
                    sortR[j] = sortR[j+1];
                    sortR[j+1] = t;
                }
            }
        }
    }

    else{
        printf("Pilihan kamu salah!");
    }


    for(i = 1; i<ttl; i++){
        while(tem->rating != sortR[i]){
            if(tem->right == NULL){
                temp = temp->left;
                tem = temp;
            }
            tem = tem->right;
        }
        printf("\t\t<<<==<>==<>==<>==<<[{={ %d }=}]>>==<>==<>==<>==>>>\n", i);
        printf("\t\t<<<==<>==<>==<>==<>==<>===<>==<>==<>==<>==<>==>>>\n");
        printf("\t\tJudul Film : %s \n\t\tGenre : %s / %s \n\t\tStudio Distribusi : %s\n", tem->judul, temp->genre, tem->left->genre, tem->studio);
        printf("\t\tTanggal Rilis : %d - %d - %d \n\t\tRating Film : %d \n\t\tUntuk Usia : %d+\n", tem->date, tem->moon, tem->year, tem->rating, tem->usia);
        printf("\t\t<<<==<>==<>==<>==<>==<>===<>==<>==<>==<>==<>==>>>\n");
        printf("\t\t<<<==<>==<>==<>==<<[{={ %d }=}]>>==<>==<>==<>==>>>\n\n", i);
    }
}

void sortingRelease(int sortD[100], int ttl, struct film *temp, struct film *tem){
    int t = 0;
    int i, j;
    int pilihan;

    printf("<<<==<>==<>==<>==<>================<</<{<>}>/>>==============<>==<>==<>==<>==>>>\n");
    printf("Pilih urutan : \n1. Terbaru \n2. Terlama \nPilihanmu : ");
    scanf("%d", &pilihan);
    printf("<<<==<>==<>==<>==<>================<</<{<>}>/>>==============<>==<>==<>==<>==>>>\n\n");

    if(pilihan == 1){
        for(i=1; i<ttl; i++){
            for(j=1; j<ttl; j++){
                if(sortD[j] < sortD[j+1]){
                    t = sortD[j];
                    sortD[j] = sortD[j+1];
                    sortD[j+1] = t;
                }
            }
        }
    }

    else if(pilihan == 2){
        for(i=1; i<ttl-1; i++){
            for(j=1; j<ttl-1; j++){
                if(sortD[j] > sortD[j+1]){
                    t = sortD[j];
                    sortD[j] = sortD[j+1];
                    sortD[j+1] = t;
                }
            }
        }
    }

    else{
        printf("Pilihan kamu salah!");
    }


    for(i = 1; i<ttl; i++){
        while(tem->rilis != sortD[i]){
            if(tem->right == NULL){
                temp = temp->left;
                tem = temp;
            }
            tem = tem->right;
        }
        printf("\t\t<<<==<>==<>==<>==<<[{={ %d }=}]>>==<>==<>==<>==>>>\n", i);
        printf("\t\t<<<==<>==<>==<>==<>==<>===<>==<>==<>==<>==<>==>>>\n");
        printf("\t\tJudul Film : %s \n\t\tGenre : %s / %s \n\t\tStudio Distribusi : %s\n", tem->judul, temp->genre, tem->left->genre, tem->studio);
        printf("\t\tTanggal Rilis : %d - %d - %d \n\t\tRating Film : %d \n\t\tUntuk Usia : %d+\n", tem->date, tem->moon, tem->year, tem->rating, tem->usia);
        printf("\t\t<<<==<>==<>==<>==<>==<>===<>==<>==<>==<>==<>==>>>\n");
        printf("\t\t<<<==<>==<>==<>==<<[{={ %d }=}]>>==<>==<>==<>==>>>\n\n", i);
    }
}

void searching(struct film *action, struct film *comedy, struct film *scifi, struct film *romance, struct film *horror, struct film *animation){
    char genre[20];
    printf("Masukkan genre film yang ingin dicari: ");
    scanf(" %[^\n]", genre);
    if (strcmp(genre, "action") == 0) {
        printGenre(action);
    } else if (strcmp(genre, "comedy") == 0) {
        printGenre(comedy);
    } else if (strcmp(genre, "scifi") == 0) {
        printGenre(scifi);
    } else if (strcmp(genre, "romance") == 0) {
        printGenre(romance);
    } else if (strcmp(genre, "horror") == 0) {
        printGenre(horror);
    } else if (strcmp(genre, "animation") == 0) {
        printGenre(animation);
    } else {
        printf("Genre tidak valid.\n");
    }

}
void printGenre(struct film *genre) {
    struct film *current = genre->right;

    if (current == NULL) {
        printf("Tidak ada film dalam genre ini.\n");
        return;
    }

    printf("\nDaftar film dalam genre %s:\n\n", genre->genre);
    while (current != NULL) {
        printf("<<<==<>==<>==<>============<<[{={<()>}=}]>>============<>==<>==<>==>>>\n");
        printf("<<<==<>==<>==<>==<>==<>==<>==<>===<>===<>==<>==<>==<>==<>==<>==<>==>>>\n");
        printf("Judul: %s\n", current->judul);
        printf("Studio: %s\n", current->studio);
        printf("Durasi: %d\n", current->durasi);
        printf("Rating: %d\n", current->rating);
        printf("Usia: %d\n\n", current->usia);
        printf("Tanggal Rilis: %d/%d/%d\n", current->date, current->moon, current->year);
        printf("Sinopsis: %s\n", current->sinopsis);
        printf("<<<==<>==<>==<>==<>==<>==<>==<>===<>===<>==<>==<>==<>==<>==<>==<>==>>>\n");
        printf("<<<==<>==<>==<>============<<[{={<()>}=}]>>============<>==<>==<>==>>>\n");
        current = current->right;
    }
}


int main () {
    int i = 0, pilihan;
    int total[1], ttl;
    int sortR[100], sortD[100];
    char jwb[1000];
    struct film *action, *comedy, *scifi, *romance, *horror, *animation, *temp, *tem, *baru;
    action = comedy = scifi = romance = horror = animation = NULL;
    temp = tem = NULL;

    char dataGenre[100][100];
    strcpy(dataGenre[1], "action");
    strcpy(dataGenre[2], "comedy");
    strcpy(dataGenre[3], "scifi");
    strcpy(dataGenre[4], "romance");
    strcpy(dataGenre[5], "horror");
    strcpy(dataGenre[6], "animation");

    for(i = 1; i<=6; i++){
        baru = (struct film*) malloc(sizeof(struct film));
        strcpy(baru->genre, dataGenre[i]);
        baru->nom = i;
        baru->left = tem;
        if(temp == NULL){
        temp = baru;
        }
        tem = baru;
        if(i == 1){
            action = baru;
        }
        else if(i == 2){
            comedy = baru;
        }
        else if(i == 3){
            scifi = baru;
        }
        else if(i == 4){
            romance = baru;
        }
        else if(i == 5){
            horror = baru;
        }
        else if(i == 6){
            animation = baru;
        }
        temp->left = tem;
    }

    penyimpananFilm(action, comedy, scifi, romance, horror, animation);

    menu:
    memset(sortR, 0, sizeof(sortR));
    memset(total, 0, sizeof(total));

    system ("cls");
    printf("<<<==<>==<>==<>==<>================<</<{<>}>/>>==============<>==<>==<>==<>==>>>\n");
    printf("<<<==<>==<>                 <>==== PUSTAKA FILM ====<>               <>==<>==>>>\n");
    printf("<<<==<>==<>==<>==<>================<</<{<>}>/>>==============<>==<>==<>==<>==>>>\n\n");

    displayFilm(temp, tem, sortR, sortD, total);
    inputStorage(action);
    ttl = total[1];

    printf("<<<==<>==<>==<>==<>================<</<{<>}>/>>==============<>==<>==<>==<>==>>>");
    printf("\nDaftar Menu: \n1. Baca Sinopsis \n2. Tambah Film \n3. Hapus Film \n4. Rating Film \n5. Tanggal Rilis \n6. Cari Film Berdasarkan");
    printf("\nPilihanmu : ");
    scanf("%d", &pilihan);
    printf("<<<==<>==<>==<>==<>================<</<{<>}>/>>==============<>==<>==<>==<>==>>>\n");

    switch(pilihan){
    case 1:
        sinopsis:
        sinopsis(temp, tem);
        pilihan:
        printf("\n\nApakah ingin kembali ke menu utama (iya / tidak) \nJawaban mu : ");
        scanf("%s", &jwb);
        if(strcmp(jwb, "iya") == 0){
            goto menu;
        }
        else if(strcmp(jwb, "tidak") == 0){
            goto sinopsis;
        }
        else {
            printf("\nJawaban mu tidak sesuai!\n");
            goto pilihan;
        }
        break;

    case 2:
        tambahFilm(temp, tem);
        goto menu;
        pilihan2:
        printf("\n\nApakah ingin kembali ke menu utama (iya / tidak) \nJawaban mu : ");
        scanf("%s", &jwb);
        if(strcmp(jwb, "iya") == 0){
            goto menu;
        }
        else if(strcmp(jwb, "tidak") == 0){
            goto sinopsis;
        }
        else {
            printf("\nJawaban mu tidak sesuai!\n");
            goto pilihan2;
        }
        break;

    case 3:
        hapusFilm(temp, tem);
        pilihan3:
        printf("\n\nApakah ingin kembali ke menu utama (iya / tidak) \nJawaban mu : ");
        scanf("%s", &jwb);
        if(strcmp(jwb, "iya") == 0){
            goto menu;
        }
        else if(strcmp(jwb, "tidak") == 0){
            goto sinopsis;
        }
        else {
            printf("\nJawaban mu tidak sesuai!\n");
            goto pilihan3;
        }
        break;

    case 4:
        system ("cls");
        printf("<<<==<>==<>==<>==<>================<</<{<>}>/>>==============<>==<>==<>==<>==>>>\n");
        printf("<<<==<>==<>             <>==== RATING PUSTAKA FILM ====<>            <>==<>==>>>\n");
        printf("<<<==<>==<>==<>==<>================<</<{<>}>/>>==============<>==<>==<>==<>==>>>\n\n");
        sortingRating(sortR, ttl, temp, tem);
        pilihan4:
        printf("\n\nApakah ingin kembali ke menu utama (iya / tidak) \nJawaban mu : ");
        scanf("%s", &jwb);
        if(strcmp(jwb, "iya") == 0){
            goto menu;
        }
        else if(strcmp(jwb, "tidak") == 0){
            goto sinopsis;
        }
        else {
            printf("\nJawaban mu tidak sesuai!\n");
            goto pilihan4;
        }
        break;

    case 5:
        system ("cls");
        printf("<<<==<>==<>==<>==<>================<</<{<>}>/>>==============<>==<>==<>==<>==>>>\n");
        printf("<<<==<>==<>         <>==== TANGGAL RILIS  PUSTAKA FILM ====<>        <>==<>==>>>\n");
        printf("<<<==<>==<>==<>==<>================<</<{<>}>/>>==============<>==<>==<>==<>==>>>\n\n");
        sortingRelease(sortD, ttl, temp, tem);
        pilihan5:
        printf("\n\nApakah ingin kembali ke menu utama (iya / tidak) \nJawaban mu : ");
        scanf("%s", &jwb);
        if(strcmp(jwb, "iya") == 0){
            goto menu;
        }
        else if(strcmp(jwb, "tidak") == 0){
            goto sinopsis;
        }
        else {
            printf("\nJawaban mu tidak sesuai!\n");
            goto pilihan5;
        }
        break;

    case 6:
        system ("cls");
        printf("<<<==<>==<>==<>==<>================<</<{<>}>/>>==============<>==<>==<>==<>==>>>\n");
        printf("<<<==<>==<>          <>==== DAFTAR GENRE PUSTAKA FILM ====<>         <>==<>==>>>\n");
        printf("<<<==<>==<>==<>==<>================<</<{<>}>/>>==============<>==<>==<>==<>==>>>\n\n");
        searching(action, comedy, scifi, romance, horror, animation);
        pilihan6:
        printf("\n\nApakah ingin kembali ke menu utama (iya / tidak) \nJawaban mu : ");
        scanf("%s", &jwb);
        if(strcmp(jwb, "iya") == 0){
            goto menu;
        }
        else if(strcmp(jwb, "tidak") == 0){
            goto sinopsis;
        }
        else {
            printf("\nJawaban mu tidak sesuai!\n");
            goto pilihan6;
        }
        break;

    default:
        printf("Pilihan kamu tidak valid!\n");
        sleep(1);
        goto menu;
    }
return 0;
}
