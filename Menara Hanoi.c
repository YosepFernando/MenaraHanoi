#include <stdio.h>

int main(){
	char pilihan;
	system("cls"); 
	printf("+-------------------------------------------------+\n");
	printf("|               PROGRAM TOWER HANOI               |\n");
	printf("+-------------------------------------------------+\n\n\n");

	printf("    +----------------------------------------+\n");
	printf("    |                  MENU                  |\n");
	printf("    +----------------------------------------+\n");
	printf("    |           1. Tower Hanoi Rekursif      |\n");
	printf("    |           2. Tower Hanoi Iteratif      |\n");
	printf("    |           3. Tutup Program             |\n");
	printf("    +----------------------------------------+\n\n\n");

	do{
		fflush(stdin);
		printf("Masukkan pilihan: ");
		scanf("%c", &pilihan);
		if(pilihan == '1'){ 
			towerHanoiRekursif(); 
			break; 
		}
		else if(pilihan == '2'){ 
			towerHanoiIteratif();
			break; 
		}
		else if(pilihan == '3'){ 
			exit(0); 
			break; 
		}
		else{
			printf("Inputan salah! Mohon hanya memasukkan angka dari 1 hingga 3.\n\n"); 
		}
	}while(1);

	return 0; 
}

void towerHanoiRekursif(){
	char pilihan;
	int jumlahCakram=0, counter=1, i;

	system("cls"); 
	printf("+-------------------------------------------------+\n");
	printf("|               PROGRAM TOWER HANOI               |\n");
	printf("+-------------------------------------------------+\n\n\n");
	do{
		fflush(stdin);
		printf("Masukkan jumlah cakram: ");
		scanf("%d", &jumlahCakram);
		if(jumlahCakram <= 0){
			printf("Inputan salah! Mohon hanya memasukkan angka lebih dari 0.\n\n");
		}
		else{
			break;
		}
	}while(1);

	hanoiRekursif(jumlahCakram,1,3,2); // memanggil prosedur hanoiRekursif untuk memindahkan sejumlah cakram ke tiang tujuan

	for(i=0; i<jumlahCakram; i++){ // melakukan perulangan untuk menghitung langkah minimum pemindahan cakram
		counter = 2 * counter; // meng-assign nilai counter dengan nilai 2 dikali dengan nilai counter sebelumnya
		if(i == jumlahCakram - 1){ // apabila nilai iterasi sama dengan jumlah cakram - 1 maka
			counter = counter - 1; // kurangi nilai counter dengan 1
		}
	}
	printf("Langkah minimum untuk memindahkan %d cakram yaitu: %d", jumlahCakram, counter); // menampilkan hasil

	printf("\n\nApakah Anda ingin menghitung langkah minimum tower hanoi ulang?\nTekan [Y] untuk mengulang\nTekan [N] untuk kembali ke menu\nTekan [K] untuk menutup program.");
	do{
		fflush(stdin);
		printf("\nMasukkan pilihan: ");
		scanf(" %c", &pilihan);
		if(pilihan == 'Y' || pilihan == 'y'){ 
			towerHanoiRekursif(); 
			break;
		}
		else if(pilihan == 'N' || pilihan == 'n'){ 
			main(); 
			break; 
		}
		else if(pilihan == 'K' || pilihan == 'k'){ 
			exit(0); 
			break; 
		}
		else{ 
			printf("Inputan salah! \nTekan [Y] untuk mengulang\nTekan [N] untuk kembali ke menu\nTekan [K] untuk menutup program.\n\n"); 
		}
	}while(1);
}

void hanoiRekursif(int cakram, int asal, int tujuan, int temp){
	if (cakram > 0) { // apabila masih ada cakram yang belum dipindahkan maka
        hanoiRekursif(cakram-1, asal, temp, tujuan); // memanggil prosedur diri sendiri untuk memindahkan cakram dari tiang awal ke tiang sementara
        printf ("Memindahkan Cakram dari Tiang %d ke Tiang %d\n", asal, tujuan); 
        hanoiRekursif(cakram-1, temp, tujuan, asal); // memanggil prosedur diri sendiri untuk memindahkan cakram dari tiang sementara ke tiang tujuan
    }
}

void towerHanoiIteratif(){
	char pilihan;
	int jumlahCakram=0, i, counter=0;
	/* variabel jumlahCakram => untuk menampung jumlah cakram dari tower hanoi
	   variabel i => untuk menampung nilai iterasi pada perulangan for
	   variabel counter => untuk menampung nilai langkah minimal yang diperlukan dan diinisialisasi dengan nilai 1 */

	char tower[] = {'1','2','3'}; // mendeklarasikan array dengan nama tower untuk menampung nilai dari tower yang ada

	system("cls");

	do{
		fflush(stdin);
		printf("Masukkan jumlah cakram: ");
		scanf("%d", &jumlahCakram);
		if(jumlahCakram <= 0){ 
			printf("Inputan salah! Mohon hanya memasukkan angka lebih dari 0\n\n"); 
		}
		else{ 
			break; 
		}
	}while(1);

	if(jumlahCakram % 2 == 0){ // apabila sisa hasil bagi antara jumlah cakram dengan 2 sama dengan 0 maka
		tower[1] = '3'; // merubah nilai tower ke 2 dengan nilai 3
		tower[2] = '2'; // merubah nilai tower ke 3 dengan nilai 2
	}

	for(i=1; i < (1<<jumlahCakram); i++){ // melakukan perulangan sebanyak (2 pangkat jumlah cakram) - 1
		counter++; // menambahkan nilai counter dengan 1
		printf("Memindahkan Cakram dari Tiang %c ke Tiang %c\n", tower[((i & (i - 1)) % 3)], tower[(((i | (i - 1)) + 1) % 3)]); // menampilkan perpindahan cakram
	}

	printf("Langkah minimum untuk memindahkan %d cakram yaitu: %d", jumlahCakram, counter); // tampilkan hasil

	printf("\n\nApakah Anda ingin menghitung langkah minimum tower hanoi ulang?\nTekan [Y] untuk mengulang\nTekan [N] untuk kembali ke menu\nTekan [K] untuk menutup program.");
	do{
		printf("\nMasukkan pilihan: ");
		scanf(" %c", &pilihan);
		if(pilihan == 'Y' || pilihan == 'y'){ 
			towerHanoiIteratif(); 
			break; 
		}
		else if(pilihan == 'N' || pilihan == 'n'){ 
			main(); 
			break; 
		}
		else if(pilihan == 'K' || pilihan == 'k'){ 
			exit(0); 
			break; 
		}
		else{ 
			printf("Inputan salah! \nTekan [Y] untuk mengulang\nTekan [N] untuk kembali ke menu\nTekan [K] untuk menutup program.\n\n"); // menampilkan error apabila inputan salah
		}
	}while(1);
}

