#include <iostream>

// Version 1.0

struct PersonalInfo{
	std::string nama_lengkap;
	std::string tanggal_lahir;
	std::string tempat_lahir;
	std::string email;
	std::string no_telepon;
	std::string jenis_kelamin;
	std::string alamat;
};

struct AccountInfo{
	std::string no_rekening;
	std::string no_kartu_atm;
	std::string jenis_akun;
	std::string nama_ibu;
	std::string profesi;
};

struct Nasabah{
	PersonalInfo infopersonal;
	AccountInfo infoakun;
	Nasabah* next;
};

Nasabah* top = NULL;

Nasabah* push(Nasabah* top,PersonalInfo infopersonal, AccountInfo infoakun){
	Nasabah* newnode = new Nasabah;
	newnode -> infopersonal.nama_lengkap = infopersonal.nama_lengkap;
	newnode -> infopersonal.tanggal_lahir = infopersonal.tanggal_lahir;
	newnode -> infopersonal.tempat_lahir = infopersonal.tempat_lahir;
	newnode -> infopersonal.email = infopersonal.email;
	newnode -> infopersonal.no_telepon = infopersonal.no_telepon;
	newnode -> infopersonal.jenis_kelamin = infopersonal.jenis_kelamin;
	newnode -> infopersonal.alamat = infopersonal.alamat;
	newnode -> infoakun.no_rekening = infoakun.no_rekening;
	newnode -> infoakun.no_kartu_atm = infoakun.no_kartu_atm;
	newnode -> infoakun.jenis_akun = infoakun.jenis_akun;
	newnode -> infoakun.nama_ibu = infoakun.nama_ibu;
	newnode -> infoakun.profesi = infoakun.profesi;
	newnode -> next = top;
	return newnode;
}

Nasabah* input_nasabah(Nasabah* top){
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
void display(Nasabah* top){
	Nasabah* temp = top;
	while(temp != NULL){
		std::cout << temp -> infopersonal.nama_lengkap << "\n";
		std::cout << temp -> infopersonal.alamat << "\n";

		std::cout << temp -> infoakun.no_rekening << "\n";
		std::cout << temp -> infoakun.profesi << "\n";

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
