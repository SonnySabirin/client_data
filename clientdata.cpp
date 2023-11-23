#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
// Version 2.2

std::string clear_cmd;
typedef struct{
	std::string nama_lengkap,tanggal_lahir,tempat_lahir,email,no_telepon,jenis_kelamin,alamat;
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
	if(infoakun.jenis_akun == "Tabungan"){
		infoakun.id_jenis_akun = 1;
	}
	else if(infoakun.jenis_akun == "Giro"){
		infoakun.id_jenis_akun = 2;
	}
	else if(infoakun.jenis_akun == "Investasi"){
		infoakun.id_jenis_akun = 3;
	}
	newnode -> data.infoakun.id_jenis_akun = infoakun.id_jenis_akun;
	newnode -> data.infoakun.nama_ibu = infoakun.nama_ibu;
	newnode -> data.infoakun.profesi = infoakun.profesi;
	newnode -> next = top;
	return newnode;
}

Node* input_nasabah(Node* top){
	PersonalInfo infopersonal;
	AccountInfo infoakun;
	std::cin.ignore();
	std::cout << "Input nama lengkap: ";
	std::getline(std::cin, infopersonal.nama_lengkap);
	std::cout << "Tanggal lahir (dd-mm-yyyy): ";
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
	std::cout << "Jenis Akun (Tabungan,Giro,Investasi): ";
	std::getline(std::cin, infoakun.jenis_akun);
	std::cout << "Nama Ibu Kandung: ";
	std::getline(std::cin, infoakun.nama_ibu);
	std::cout << "Profesi: ";
	std::getline(std::cin, infoakun.profesi);
	top = push(top,infopersonal,infoakun);
	return top;
}

Node* load_file(Node* top,std::string nama_file){
	PersonalInfo infopersonal;
	AccountInfo infoakun;
	std::string line;
	bool header_file = true;
	std::ifstream datanasabah (nama_file.c_str());
	if(datanasabah.is_open()){
		std::cout << "Load Success!" << "\n";
	}
	while(getline(datanasabah,line)){
		if(header_file){
			header_file = false;
			continue;
		}
		std::stringstream data(line);
		getline(data, infopersonal.nama_lengkap, ',');
		getline(data, infopersonal.tanggal_lahir, ',');
		getline(data, infopersonal.tempat_lahir, ',');
		getline(data, infopersonal.email, ',');
		getline(data, infopersonal.no_telepon, ',');
		getline(data, infopersonal.jenis_kelamin, ',');
		getline(data, infopersonal.alamat, ',');
		getline(data, infoakun.no_rekening, ',');
		getline(data, infoakun.no_kartu_atm, ',');
		getline(data, infoakun.jenis_akun, ',');
		getline(data, infoakun.nama_ibu, ',');
		getline(data, infoakun.profesi, ',');
		top = push(top,infopersonal,infoakun);
	}
	datanasabah.close();
	return top;
}

void output_file(Node* top,std::string nama_output){
	std::ofstream output_to (nama_output.c_str());
	Node* temp = top;
	output_to << "Nama Lengkap,Tanggal Lahir,Tempat Lahir,Email,No Telepon,Jenis Kelamin,Alamat,No Rekening,No Kartu ATM,Jenis Akun,Nama Ibu,Profesi" << "\n";
	while(temp != NULL){
		output_to << temp -> data.infopersonal.nama_lengkap << "," << temp -> data.infopersonal.tanggal_lahir << "," << temp -> data.infopersonal.tempat_lahir << "," << temp -> data.infopersonal.email << "," << temp -> data.infopersonal.no_telepon << "," << temp -> data.infopersonal.jenis_kelamin << "," << temp -> data.infopersonal.alamat << "," << temp -> data.infoakun.no_rekening << "," << temp -> data.infoakun.no_kartu_atm << "," << temp -> data.infoakun.jenis_akun << "," << temp -> data.infoakun.nama_ibu << "," << temp -> data.infoakun.profesi << "\n";

		temp = temp -> next;
	}
	output_to.close();
}

void display(Node* top) {
    Node* temp = top;
    std::cout << std::setw(20) << std::left << "Nama Lengkap"
              << std::setw(12) << std::left << "Tgl Lahir"
              << std::setw(20) << std::left << "Tempat Lahir"
              << std::setw(25) << std::left << "Email"
              << std::setw(15) << std::left << "No Telepon"
              << std::setw(15) << std::left << "Jenis Kelamin"
              << std::setw(25) << std::left << "Alamat"
              << std::setw(20) << std::left << "No Rekening"
              << std::setw(20) << std::left << "No Kartu ATM"
              << std::setw(15) << std::left << "Jenis Akun"
              << std::setw(20) << std::left << "Nama Ibu"
              << std::setw(20) << std::left << "Profesi" << "\n";

    while(temp != NULL) {
        std::cout << std::setw(20) << std::left << temp->data.infopersonal.nama_lengkap
                  << std::setw(12) << std::left << temp->data.infopersonal.tanggal_lahir
                  << std::setw(20) << std::left << temp->data.infopersonal.tempat_lahir
                  << std::setw(25) << std::left << temp->data.infopersonal.email
                  << std::setw(15) << std::left << temp->data.infopersonal.no_telepon
                  << std::setw(15) << std::left << temp->data.infopersonal.jenis_kelamin
                  << std::setw(25) << std::left << temp->data.infopersonal.alamat
                  << std::setw(20) << std::left << temp->data.infoakun.no_rekening
                  << std::setw(20) << std::left << temp->data.infoakun.no_kartu_atm
                  << std::setw(15) << std::left << temp->data.infoakun.jenis_akun
                  << std::setw(20) << std::left << temp->data.infoakun.nama_ibu
                  << std::setw(20) << std::left << temp->data.infoakun.profesi << "\n";
        temp = temp->next;
    }
}

// Linear Search
void search(Node* top,std::string nama){
	Node* temp = top;
	Node* found = NULL;
	while(temp != NULL){
		if(temp -> data.infopersonal.nama_lengkap.find(nama) != std::string::npos){
			Node* node_found = new Node;
			node_found -> data = temp -> data;
			node_found -> next = found;
			found = node_found;
		}
		temp = temp -> next;
	}
	if(found == NULL){
		std::cout << "Nasabah tidak ditemukan" << "\n";
	}
	display(found);
}

Node* bubblesort(Node* top) {
    if(top == NULL || top->next == NULL){
        return top;
    }
    Node* temp;
    bool swapped = true;
    while(swapped){
        swapped = false;
        Node* current = top;
        Node* prev = NULL;
        while(current && current->next){
            if(current->data.infoakun.id_jenis_akun > current->next->data.infoakun.id_jenis_akun){
                if(prev){
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
	std::cout << "=========================" << "\n";
	std::cout << "===    BANK LABIRIN   ===" << "\n";
	std::cout << "=========================" << "\n";
}

void menu_utama();
void menu_load(Node* top, bool opsi_extra){
	char opsi;
	std::string nama,nama_output;
	header();
	std::cout << "1. Display data nasabah" << "\n";
	std::cout << "2. Search nama nasabah" << "\n";
	std::cout << "3. Sort berdasarkan jenis tabungan" << "\n";
	if(opsi_extra){
		std::cout << "4. Output ke file" << "\n";
	}
	std::cout << "0. Kembali ke menu utama" << "\n";
	std::cout << "Pilih Opsi: ";
	std::cin >> opsi;
	system(clear_cmd.c_str());
	switch(opsi){
		case '1': 
			display(top);
			menu_load(top,opsi_extra);
			break;
		case '2':
			std::cout << "Nama nasabah yang ingin disearch: ";
			std::cin >> nama;
			search(top,nama);
			menu_load(top,opsi_extra);
			break;
		case '3':
			top = bubblesort(top);
			display(top);
			opsi_extra = true;
			menu_load(top,opsi_extra);
			break;
		case '4':
			std::cout << "Nama file output (.csv): ";
			std::cin >> nama_output;
			if(nama_output.find(".csv") == std::string::npos){
				std::cout << "Format file tidak sesuai, harus csv.";
				menu_load(top,opsi_extra);
				break;
			}
			output_file(top,nama_output);
			std::cout << "Output success!" << "\n";
			opsi_extra = false;
			menu_load(top,opsi_extra);
			break;
		case '0':
			menu_utama();
			break;
		default:
			std::cout << "Opsi tidak valid!" << "\n";
			menu_load(top,opsi_extra);
			break;
	}
}
void menu_utama(){
	Node* top = NULL;
	char opsi,opsi_lanjut;
	bool opsi_extra;
	std::string nama_file;
	header();
	std::cout << "1. Load Data Nasabah" << "\n";
	std::cout << "2. Input data nasabah baru" << "\n";
	std::cout << "3. Exit" << "\n";
	std::cout << "Pilih opsi: ";
	std::cin >> opsi;
	system(clear_cmd.c_str());
	switch(opsi){
		case '1':
			std::cout << "Input nama file (dengan path lengkap, .csv): ";
			std::cin >> nama_file;
			if(nama_file.find(".csv") == std::string::npos){
				std::cout << "Format file tidak sesuai, harus csv." << "\n";
				menu_utama();
				break;
			}
			top = load_file(top,nama_file);
			menu_load(top,opsi_extra);
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
			system(clear_cmd.c_str());
			opsi_extra = true;
			menu_load(top,opsi_extra);
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
