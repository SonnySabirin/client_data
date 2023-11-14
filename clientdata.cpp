#include <iostream>
#include <fstream>
#include <sstream>
// Version 1.9

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

Node* load_file(std::string nama_file){
	PersonalInfo infopersonal;
	AccountInfo infoakun;
	std::string line;
	std::ifstream datanasabah (nama_file.c_str());
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

// in progress
void output_file(Node* top){}

// test display node
void display(Node* top){
	Node* temp = top;
	while(temp != NULL){
		std::cout << temp -> data.infopersonal.nama_lengkap << "\n";
		std::cout << temp -> data.infopersonal.alamat << "\n";

		std::cout << temp -> data.infoakun.jenis_akun << "\n";
		std::cout << temp -> data.infoakun.profesi << "\n";

		temp = temp -> next;
	}
}

// Linear Search
void search(std::string nama){
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

Node* merge(Node* left,Node* right){
	if(left == NULL){
		return right;
	}
	if(right == NULL){
		return left;
	}

	Node* result = NULL;

	if (left->data.infoakun.id_jenis_akun <= right->data.infoakun.id_jenis_akun){
		result = left;
		result->next = merge(left->next,right);
	}
	else{
		result = right;
		result->next = merge(left,right->next);
	}

	return result;
}

Node* split(Node* head){
	Node* slow = head;
	Node* fast = head->next;

	while(fast != NULL && fast -> next != NULL){
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

Node* mergesort(Node* head){
	if (head == NULL || head -> next == NULL){
		return head;
	}

	Node* half = split(head);
	Node* left = head;
	Node* right = half -> next;
	half -> next = NULL;

	left = mergesort(left);
	right = mergesort(right);
	return merge(left,right);
}


void header(){
	std::cout << "=========================" << "\n";
	std::cout << "===    BANK LABIRIN   ===" << "\n";
	std::cout << "=========================" << "\n";
}

void menu_load(bool opsi_extra){
	char opsi;
	std::string nama;
	header();
	std::cout << "1. Display data nasabah" << "\n";
	std::cout << "2. Search nama nasabah" << "\n";
	std::cout << "3. Sort berdasarkan jenis tabungan" << "\n";
	if(opsi_extra){
		std::cout << "4. Output ke file" << "\n";
	}
	std::cout << "0. Exit" << "\n";
	std::cout << "Pilih Opsi: ";
	std::cin >> opsi;
	system(clear_cmd.c_str());
	switch(opsi){
		case '1': 
			display(top);
			menu_load(opsi_extra);
			break;
		case '2':
			std::cout << "Nama nasabah yang ingin disearch: ";
			std::cin >> nama;
			search(nama);
			menu_load(opsi_extra);
			break;
		case '3':
			top = mergesort(top);
			display(top);
			opsi_extra = true;
			menu_load(opsi_extra);
			break;
		case '4':
			// in progress
			output_file(top);
			break;
		case '0':
			std::cout << "Exit" << "\n";
			break;
		default:
			std::cout << "Opsi tidak valid!" << "\n";
			menu_load(opsi_extra);
			break;
	}
}
void menu_utama(){
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
			std::cout << "Input nama file (dengan path lengkap): ";
			std::cin >> nama_file;
			top = load_file(nama_file);
			std::cout << "Load success" << "\n";
			menu_load(opsi_extra);
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
			menu_load(opsi_extra);
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
