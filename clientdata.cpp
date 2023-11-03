#include <iostream>

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
