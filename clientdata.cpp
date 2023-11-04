#include <iostream>

struct Nasabah{
	std::string nama_lengkap;
	std::string no_rekening;
	std::string no_kartu_atm;
	std::string jenis_akun;
	std::string tanggal_lahir;
	std::string tempat_lahir;
	std::string email;
	std::string no_telepon;
	std::string jenis_kelamin;
	std::string alamat;
	std::string nama_ibu;
	std::string profesi;
	Nasabah* next;
}

void header(){
	std::cout << "=========================" << "\n";
	std::cout << "===    BANK LABIRIN   ===" << "\n";
	std::cout << "=========================" << "\n";
}

void menu_utama(){
	header();
	std::cout << "1. Load Data Nasabah" << "\n";
	std::cout << "2. Input data nasabah baru" << "\n";
	std::cout << "3. Keluar" << "\n";
}

int main(){
	menu_utama();
	return 0;
}
