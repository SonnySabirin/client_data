#include <iostream>

// Version 1.1

typedef struct{
	std::string nama_lengkap,tanggal_lahir,tempat_lahir,email,no_telepon,jenis_kelamin,alamat;
}PersonalInfo;

typedef struct{
	std::string no_rekening,no_kartu_atm,jenis_akun,nama_ibu,profesi;
}AccountInfo;

typedef struct{
	PersonalInfo infopersonal;
	AccountInfo infoakun;
}Nasabah;

typedef struct Node{
    Nasabah data;
    Node* next; 
}Node;

Node* top = NULL;

Node* push(Node* top,PersonalInfo infopersonal, AccountInfo infoakun){
	Node* newnode = new Node;
	newnode -> data.infopersonal.nama_lengkap = infopersonal.nama_lengkap;
	newnode -> data.infopersonal.tanggal_lahir = infopersonal.tanggal_lahir;
	newnode -> data.infopersonal.tempat_lahir = infopersonal.tempat_lahir;
	newnode -> data.infopersonal.email = infopersonal.email;
	newnode -> data.infopersonal.no_telepon = infopersonal.no_telepon;
	newnode -> data.infopersonal.jenis_kelamin = infopersonal.jenis_kelamin;
	newnode -> data.infopersonal.alamat = infopersonal.alamat;
	newnode -> data.infoakun.no_rekening = infoakun.no_rekening;
	newnode -> data.infoakun.no_kartu_atm = infoakun.no_kartu_atm;
	newnode -> data.infoakun.jenis_akun = infoakun.jenis_akun;
	newnode -> data.infoakun.nama_ibu = infoakun.nama_ibu;
	newnode -> data.infoakun.profesi = infoakun.profesi;
	newnode -> next = top;
	return newnode;
}

Node* input_nasabah(Node* top){
	PersonalInfo infopersonal;
	AccountInfo infoakun;
	std::cin.ignore();
	std::cout << "Input nama_lengkap: ";
	std::getline(std::cin, infopersonal.nama_lengkap);
	std::cout << "Tanggal lahir: ";
	std::getline(std::cin, infopersonal.tanggal_lahir);
	std::cout << "Tempat lahir: ";
	std::getline(std::cin, infopersonal.tempat_lahir);
	std::cout << "Email: ";
	std::getline(std::cin, infopersonal.email);
	std::cout << "No telepon: ";
	std::getline(std::cin, infopersonal.no_telepon);
	std::cout << "Jenis kelamin: ";
	std::getline(std::cin, infopersonal.jenis_kelamin);
	std::cout << "Alamat: ";
	std::getline(std::cin, infopersonal.alamat);
	std::cout << "Nomor Rekening: ";
	std::getline(std::cin, infoakun.no_rekening);
	std::cout << "Nomor Kartu ATM: ";
	std::getline(std::cin, infoakun.no_kartu_atm);
	std::cout << "Jenis Akun: ";
	std::getline(std::cin, infoakun.jenis_akun);
	std::cout << "Nama Ibu Kandung: ";
	std::getline(std::cin, infoakun.nama_ibu);
	std::cout << "Profesi: ";
	std::getline(std::cin, infoakun.profesi);
	top = push(top,infopersonal,infoakun);
	return top;
}

// test display node
void display(Node* top){
	Node* temp = top;
	while(temp != NULL){
		std::cout << temp -> data.infopersonal.nama_lengkap << "\n";
		std::cout << temp -> data.infopersonal.alamat << "\n";

		std::cout << temp -> data.infoakun.no_rekening << "\n";
		std::cout << temp -> data.infoakun.profesi << "\n";

		temp = temp -> next;
	}
}
void header(){
	std::cout << "=========================" << "\n";
	std::cout << "===    BANK LABIRIN   ===" << "\n";
	std::cout << "=========================" << "\n";
}

void menu_utama(){
	char opsi,opsi_lanjut;
	header();
	std::cout << "1. Load Data Nasabah" << "\n";
	std::cout << "2. Input data nasabah baru" << "\n";
	std::cout << "3. Keluar" << "\n";
	std::cout << "Pilih opsi: ";
	std::cin >> opsi;

	if(opsi == '2'){
		top = input_nasabah(top);
		std::cout << "Lanjut? ";
		std::cin >> opsi_lanjut;
		while(opsi_lanjut == 'Y'){
			top = input_nasabah(top);
			std::cout << "Lanjut? ";
			std::cin >> opsi_lanjut;
		}
		display(top);
	}
}

int main(){
	menu_utama();
	return 0;
}
