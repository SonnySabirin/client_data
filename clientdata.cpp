#include <iostream>
#include <fstream>
#include <sstream>
// Version 1.2

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

Node* load_file(std::string nama_file){
	PersonalInfo infopersonal;
	AccountInfo infoakun;
	std::string line;
	std::ifstream datanasabah (nama_file);
	while(getline(datanasabah,line)){
		if(line.empty()){
			continue;
		}
		std::stringstream data(line);
		data >> infopersonal.nama_lengkap >> infopersonal.tanggal_lahir >> infopersonal.tempat_lahir >> infopersonal.email >> infopersonal.no_telepon >> infopersonal.jenis_kelamin >> infopersonal.alamat >> infoakun.no_rekening >> infoakun.no_kartu_atm >> infoakun.jenis_akun >> infoakun.nama_ibu >> infoakun.profesi;
		top = push(top,infopersonal,infoakun);
	}
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
	std::string nama_file;
	header();
	std::cout << "1. Load Data Nasabah" << "\n";
	std::cout << "2. Input data nasabah baru" << "\n";
	std::cout << "3. Keluar" << "\n";
	std::cout << "Pilih opsi: ";
	std::cin >> opsi;
	switch(opsi){
		case '1':
			std::cout << "Input nama file (dengan path lengkap): ";
			std::cin >> nama_file;
			top = load_file(nama_file);
			system("clear");
			std::cout << "Load success" << "\n";
			display(top);
			break;
		case '2':
			top = input_nasabah(top);
			std::cout << "Lanjut? ";
			std::cin >> opsi_lanjut;
			while(opsi_lanjut == 'Y'){
				top = input_nasabah(top);
				std::cout << "Lanjut? ";
				std::cin >> opsi_lanjut;
			}
			system("clear");
			display(top);
			break;
		case '3':
			std::cout << "Exit" << "\n";
			break;
	}

}
int main(){
	menu_utama();
	return 0;
}
