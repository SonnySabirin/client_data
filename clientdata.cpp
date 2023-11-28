#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <bits/stdc++.h> 
// Version 2.9.1

std::string clear_cmd;
typedef struct{
	std::string nama_lengkap,tanggal_lahir,tempat_lahir,email,no_handphone,jenis_kelamin,alamat;
}PersonalInfo;

typedef struct{
	std::string no_rekening,no_kartu_atm,jenis_akun,id_jenis_akun,nama_ibu,profesi;
}AccountInfo;

typedef struct{
	PersonalInfo infopersonal;
	AccountInfo infoakun;
}Nasabah;

typedef struct Node{
	Nasabah data;
	Node* next;
}Node;

Node* push(Node* top, PersonalInfo infopersonal, AccountInfo infoakun){
	Node* newnode = new Node;
	newnode -> data.infopersonal.nama_lengkap = infopersonal.nama_lengkap;
	newnode -> data.infopersonal.tempat_lahir = infopersonal.tempat_lahir;
	newnode -> data.infopersonal.tanggal_lahir = infopersonal.tanggal_lahir;
	newnode -> data.infopersonal.jenis_kelamin = infopersonal.jenis_kelamin;
	newnode -> data.infoakun.profesi = infoakun.profesi;
	newnode -> data.infopersonal.alamat = infopersonal.alamat;
	newnode -> data.infopersonal.email = infopersonal.email;
	newnode -> data.infopersonal.no_handphone = infopersonal.no_handphone;
	newnode -> data.infoakun.no_rekening = infoakun.no_rekening;
	newnode -> data.infoakun.no_kartu_atm = infoakun.no_kartu_atm;
	newnode -> data.infoakun.jenis_akun = infoakun.jenis_akun;
	if (infoakun.jenis_akun == "Tabungan"){
		infoakun.id_jenis_akun = 1;
	}
	else if (infoakun.jenis_akun == "Giro"){
		infoakun.id_jenis_akun = 2;
	}
	else if (infoakun.jenis_akun == "Investasi"){
		infoakun.id_jenis_akun = 3;
	}
	newnode->data.infoakun.id_jenis_akun = infoakun.id_jenis_akun;
	newnode->data.infoakun.nama_ibu = infoakun.nama_ibu;
	newnode->next = top;
	return newnode;
}

Node* pop(Node* top){
	Node* temp = top;
	std::string nama;
	std::string search_string;
	char choice;
	std::cout << "Nama yang ingin didelete: ";
	std::cin >> nama;
	transform(nama.begin(), nama.end(), nama.begin(), ::tolower);
	while (temp != NULL){
		search_string = temp->data.infopersonal.nama_lengkap;
		transform(search_string.begin(), search_string.end(), search_string.begin(), ::tolower);
		if (search_string.find(nama) != std::string::npos){
			std::cout << "Nama yang ingin didelete adalah " << temp -> data.infopersonal.nama_lengkap << " (Y/N)? ";
			std::cin >> choice;
			if (choice == 'Y' || choice == 'y'){
				top = temp -> next;
				std::cout << temp -> data.infopersonal.nama_lengkap << " dihapus." << "\n";
				delete temp;
			}
			else if (choice == 'N' || choice == 'n'){
				std::cout << temp -> data.infopersonal.nama_lengkap << " tidak dihapus." << "\n";
			}
		}
		temp = temp->next;
	}
	return top;
}

Node* input_nasabah(Node* top){
	PersonalInfo infopersonal;
	AccountInfo infoakun;
	std::cin.ignore();
	std::cout << "Input nama lengkap (contoh: Anton)  : ";
	std::getline(std::cin, infopersonal.nama_lengkap);
	std::cout << "Tempat lahir (contoh: Jakarta)      : ";
	std::getline(std::cin, infopersonal.tempat_lahir);
	std::cout << "Tanggal lahir (dd-mm-yyyy)          : ";
	std::getline(std::cin, infopersonal.tanggal_lahir);

	while (true){
		std::cout << "Jenis kelamin (Pria/Perempuan)      : ";
		std::getline(std::cin, infopersonal.jenis_kelamin);

		if (infopersonal.jenis_kelamin == "Pria" || infopersonal.jenis_kelamin == "pria"){
			infopersonal.jenis_kelamin = "Pria";
			break;
		}
		else if (infopersonal.jenis_kelamin == "Perempuan" || infopersonal.jenis_kelamin == "perempuan"){
			infopersonal.jenis_kelamin = "Perempuan";
			break;
		}
		else{
			std::cout << "Jenis kelamin tidak valid, silahkan input ulang." << "\n";
		}
	}

	std::cout << "Profesi (contoh: Wiraswasta)        : ";
	std::getline(std::cin, infoakun.profesi);
	std::cout << "Alamat (contoh: Jl. Mawar No.8)     : ";
	std::getline(std::cin, infopersonal.alamat);
	std::cout << "Email (contoh: anton@gmail.com)     : ";
	std::getline(std::cin, infopersonal.email);
	std::cout << "Nomor handphone (contoh: 08xxxxxxx) : ";
	std::getline(std::cin, infopersonal.no_handphone);

	while (infopersonal.no_handphone.length() < 10){
		std::cout << "Nomor handphone tidak valid, silahkan input ulang." << "\n";
		std::cout << "Nomor handphone (contoh: 08xxxxxxx) : ";
		std::getline(std::cin, infopersonal.no_handphone);
	}
	infopersonal.no_handphone = infopersonal.no_handphone.substr(0,4) + "-" + infopersonal.no_handphone.substr(4,4) + "-" 
		+ infopersonal.no_handphone.substr(8,4);

	std::cout << "Nomor Rekening (contoh: 1234567890) : ";
	std::getline(std::cin, infoakun.no_rekening);

	while (infoakun.no_rekening.length() != 10){
		std::cout << "Nomor rekening tidak valid, silahkan input ulang." << "\n";
		std::cout << "Nomor Rekening (contoh: 1234567890) : ";
		std::getline(std::cin, infoakun.no_rekening);
	}

	std::cout << "Nomor Kartu ATM                     : ";
	std::getline(std::cin, infoakun.no_kartu_atm);

	while (infoakun.no_kartu_atm.length() != 16){
		std::cout << "Nomor kartu ATM tidak valid, silahkan input ulang." << "\n";
		std::cout << "Nomor Kartu ATM                     : ";
		std::getline(std::cin, infoakun.no_kartu_atm);
	}
	infoakun.no_kartu_atm = infoakun.no_kartu_atm.substr(0,4) + "-" + infoakun.no_kartu_atm.substr(4,4) + "-" 
		+ infoakun.no_kartu_atm.substr(8,4) + "-" + infoakun.no_kartu_atm.substr(12,4);

	while (true){
		std::cout << "Jenis Akun (Tabungan/Giro/Investasi): ";
		std::getline(std::cin, infoakun.jenis_akun);

		if (infoakun.jenis_akun == "Tabungan" || infoakun.jenis_akun == "tabungan"){
			infoakun.jenis_akun = "Tabungan";
			break;
		}
		else if (infoakun.jenis_akun == "Giro" || infoakun.jenis_akun == "giro"){
			infoakun.jenis_akun = "Giro";
			break;
		}
		else if (infoakun.jenis_akun == "Investasi" || infoakun.jenis_akun == "investasi"){
			infoakun.jenis_akun = "Investasi";
			break;
		}
		else{
			std::cout << "Jenis Akun tidak valid, silahkan input ulang." << "\n";
		}
	}

	std::cout << "Nama Ibu Kandung                    : ";
	std::getline(std::cin, infoakun.nama_ibu);

	top = push(top,infopersonal,infoakun);
	return top;
}

Node* load_file(Node* top, std::string nama_file){
	PersonalInfo infopersonal;
	AccountInfo infoakun;
	std::string line;
	bool header_file = true;
	std::ifstream datanasabah (nama_file.c_str());
	if (datanasabah.is_open()){
		std::cout << "Load success!" << "\n";
	}
	while (getline(datanasabah, line)){
		if (header_file){
			header_file = false;
			continue;
		}
		std::stringstream data(line);
		getline(data, infopersonal.nama_lengkap, ',');
		getline(data, infopersonal.tempat_lahir, ',');
		getline(data, infopersonal.tanggal_lahir, ',');
		getline(data, infopersonal.jenis_kelamin, ',');
		getline(data, infoakun.profesi, ',');
		getline(data, infopersonal.alamat, ',');
		getline(data, infopersonal.email, ',');
		getline(data, infopersonal.no_handphone, ',');
		getline(data, infoakun.no_rekening, ',');
		getline(data, infoakun.no_kartu_atm, ',');
		getline(data, infoakun.jenis_akun, ',');
		getline(data, infoakun.nama_ibu, ',');
		top = push(top, infopersonal, infoakun);
	}
	datanasabah.close();
	return top;
}

void output_file(Node* top, std::string nama_output){
	std::ofstream output_to(nama_output.c_str());
	Node* temp = top;

	output_to << "Nama Lengkap,Tempat Lahir,Tanggal Lahir,Jenis Kelamin,Profesi,Alamat,Email,No Handphone,No Rekening,No Kartu ATM,Jenis Akun,Nama Ibu" << "\n";

	while (temp != NULL){
		output_to << temp->data.infopersonal.nama_lengkap << ","
			<< temp->data.infopersonal.tempat_lahir << ","
			<< temp->data.infopersonal.tanggal_lahir << ","
			<< temp->data.infopersonal.jenis_kelamin << ","
			<< temp->data.infoakun.profesi << ","
			<< temp->data.infopersonal.alamat << ","
			<< temp->data.infopersonal.email << ","
			<< temp->data.infopersonal.no_handphone << ","
			<< temp->data.infoakun.no_rekening << ","
			<< temp->data.infoakun.no_kartu_atm << ","
			<< temp->data.infoakun.jenis_akun << ","
			<< temp->data.infoakun.nama_ibu << "\n";

		if(temp -> next == NULL){
			break;
		}
		temp = temp->next;
	}

	output_to.close();
}

void display(Node* top){
	std::string namasingkat;
	std::string namalengkap;
	int no = 1;
	Node* temp = top;
	std::cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << "\n"
		<< "| " << std::setw(4) << std::left << "No. " << "| "
		<< std::setw(20) << std::left << "Nama Lengkap" << "| "
		<< std::setw(15) << std::left << "Tempat Lahir" << "| "
		<< std::setw(15) << std::left << "Tanggal Lahir" << "| "
		<< std::setw(15) << std::left << "Jenis Kelamin" << "| "
		<< std::setw(20) << std::left << "Profesi" << "| "
		<< std::setw(25) << std::left << "Alamat" << "| "
		<< std::setw(25) << std::left << "Email" << "| "
		<< std::setw(15) << std::left << "No. Handphone" << "| "
		<< std::setw(15) << std::left << "No. Rekening" << "| "
		<< std::setw(20) << std::left << "No. Kartu ATM" << "| "
		<< std::setw(15) << std::left << "Jenis Akun" << "| "
		<< std::setw(20) << std::left << "Nama Ibu" << "| " << "\n"
		<< "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << "\n";

	while (temp != NULL){
		namalengkap = temp->data.infopersonal.nama_lengkap;
		for (int i = 0; i < namalengkap.length(); i++){
			if (namalengkap[i] == ' '){
				namasingkat = namalengkap.substr(0, i);
				break;
			}
		}
		for (int i = namalengkap.length(); i > 0; i--){
			if (namalengkap[i] == ' '){
				namasingkat = namasingkat + " " + namalengkap.substr(i+1, namalengkap.length());
				break;
			}
		}
		if (namasingkat == ""){
			namasingkat = namalengkap;
		}
		std::cout << "| " <<  std::setw(2) << std::right << no++ <<  std::setw(2) << std::left << "." << "| "
			<< std::setw(20) << std::left << namasingkat << "| "
			<< std::setw(15) << std::left << temp->data.infopersonal.tempat_lahir << "| "
			<< std::setw(15) << std::left << temp->data.infopersonal.tanggal_lahir << "| "
			<< std::setw(15) << std::left << temp->data.infopersonal.jenis_kelamin << "| "
			<< std::setw(20) << std::left << temp->data.infoakun.profesi << "| "
			<< std::setw(25) << std::left << temp->data.infopersonal.alamat << "| "
			<< std::setw(25) << std::left << temp->data.infopersonal.email << "| "
			<< std::setw(15) << std::left << temp->data.infopersonal.no_handphone << "| "
			<< std::setw(15) << std::left << temp->data.infoakun.no_rekening << "| "
			<< std::setw(20) << std::left << temp->data.infoakun.no_kartu_atm << "| "
			<< std::setw(15) << std::left << temp->data.infoakun.jenis_akun << "| "
			<< std::setw(20) << std::left << temp->data.infoakun.nama_ibu << "| " << "\n";
		temp = temp->next;
		namasingkat = "";
	}
	std::cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << "\n";
}

// Linear Search
Node* search(Node* top,std::string nama){
	Node* temp = top;
	Node* found = NULL;
	std::string search_string;
	transform(nama.begin(), nama.end(), nama.begin(), ::tolower);
	while (temp != NULL){
		search_string = temp -> data.infopersonal.nama_lengkap;
		transform(search_string.begin(), search_string.end(), search_string.begin(), ::tolower);
		if (search_string.find(nama) != std::string::npos){
			Node* node_found = new Node;
			node_found -> data = temp -> data;
			node_found -> next = found;
			found = node_found;
		}
		temp = temp -> next;
	}
	if (found == NULL){
		std::cout << "Nasabah tidak ditemukan" << "\n";
	}
	display(found);
	return found;
}

Node* bubblesort(Node* top){
	if (top == NULL || top->next == NULL){
		return top;
	}
	Node* temp;
	bool swapped = true;
	while (swapped){
		swapped = false;
		Node* current = top;
		Node* prev = NULL;
		while (current && current->next){
			if (current->data.infoakun.id_jenis_akun > current->next->data.infoakun.id_jenis_akun){
				if (prev){
					prev->next = current->next;
				}
				else{
					top = current->next;
				}
				temp = current->next->next;
				current->next->next = current;
				current->next = temp;
				swapped = true;
			}
			prev = current;
			current = current->next;
		}
	}
	return top;
}

void header(){
	std::cout << "==========================" << "\n";
	std::cout << "=====  BANK LABIRIN  =====" << "\n";
	std::cout << "==========================" << "\n";
}

void menu_utama();

void menu_load(Node* top, Node* found,bool opsi_extra){
	//Node* found = NULL;
	Node* output = NULL;
	char opsi;
	std::string nama,nama_output;
	header();
	std::cout << "1. Display data nasabah" << "\n";
	std::cout << "2. Search nama nasabah" << "\n";
	std::cout << "3. Sort berdasarkan jenis akun" << "\n";
	std::cout << "4. Delete nama" << "\n";
	if(opsi_extra){
		std::cout << "5. Output ke file" << "\n";
	}
	std::cout << "0. Kembali ke menu utama" << "\n";
	std::cout << "Pilih opsi: ";
	std::cin >> opsi;
	system(clear_cmd.c_str());
	switch(opsi){
		case '1': 
			display(top);
			menu_load(top,NULL,opsi_extra);
			break;
		case '2':
			std::cout << "Nama nasabah yang ingin disearch: ";
			std::cin >> nama;
			found = search(top,nama);
			if(found != NULL){
				opsi_extra = true;
			}
			menu_load(top,found,opsi_extra);
			break;
		case '3':
			top = bubblesort(top);
			display(top);
			opsi_extra = true;
			menu_load(top,NULL,opsi_extra);
			break;
		case '4':
			top = pop(top);
			menu_load(top,NULL,opsi_extra);
			break;
		case '5':
			std::cout << "Nama file output (.csv): ";
			std::cin >> nama_output;
			if (nama_output.find(".csv") == std::string::npos){
				std::cout << "Format file tidak sesuai, harus csv.";
				menu_load(top,NULL,opsi_extra);
				break;
			}
			if(found != NULL){
				output = found;
			}
			else{
				output = top;
			}
			output_file(output,nama_output);
			std::cout << "Output success!" << "\n";
			opsi_extra = false;
			menu_load(top,NULL,opsi_extra);
			break;
		case '0':
			menu_utama();
			break;
		default:
			std::cout << "Opsi tidak valid!" << "\n";
			menu_load(top,NULL,opsi_extra);
			break;
	}
}

void menu_utama(){
	Node* top = NULL;
	char opsi,opsi_lanjut;
	bool opsi_extra;
	std::string nama_file;
	header();
	std::cout << "1. Load data nasabah" << "\n";
	std::cout << "2. Input data nasabah baru" << "\n";
	std::cout << "3. Exit" << "\n";
	std::cout << "Pilih opsi: ";
	std::cin >> opsi;
	system(clear_cmd.c_str());
	switch(opsi){
		case '1':
			std::cout << "Input nama file (dengan path lengkap, .csv): ";
			std::cin >> nama_file;
			if (nama_file.find(".csv") == std::string::npos){
				std::cout << "Format file tidak sesuai, harus csv." << "\n";
				menu_utama();
				break;
			}
			top = load_file(top,nama_file);
			menu_load(top,NULL,opsi_extra);
			break;
		case '2':
			top = input_nasabah(top);
			std::cout << "Lanjut (Y/N)? ";
			std::cin >> opsi_lanjut;
			while (opsi_lanjut == 'Y' || opsi_lanjut == 'y'){
				top = input_nasabah(top);
				std::cout << "Lanjut (Y/N)? ";
				std::cin >> opsi_lanjut;
			}
			system(clear_cmd.c_str());
			opsi_extra = true;
			menu_load(top,NULL,opsi_extra);
			break;
		case '3':
			std::cout << "Exit" << "\n";
			break;
		default:
			std::cout << "Opsi tidak valid!" << "\n";
			menu_utama();
			break;
	}
}

int main(){
	#if __linux__
		clear_cmd = "clear";
	#elif _WIN32
		clear_cmd = "cls";
	#endif
	menu_utama();
	return 0;
}
