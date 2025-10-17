# 🏦 Client Data Management System (C++)

**Client Data** adalah aplikasi berbasis **C++** untuk mengelola data nasabah di sebuah bank.  
Program ini memungkinkan pengguna untuk **memuat, menampilkan, mencari, menyortir, menghapus**, dan **menyimpan ulang data nasabah** dalam format **CSV**.  
Proyek ini dirancang menggunakan struktur **linked list dinamis**, yang membuat proses manipulasi data (tambah, hapus, cari, urutkan) menjadi efisien tanpa ketergantungan pada ukuran tetap array.

---

## ⚙️ Fitur Utama

### 1. Load Data Nasabah  
- Membaca file **CSV** yang berisi data nasabah.  
- Data dimuat ke dalam struktur linked list.  
- Setelah data dimuat, pengguna dapat melakukan berbagai operasi (display, search, sort, delete, export).

### 2. Input Data Nasabah  
- Menambahkan data nasabah baru melalui input manual.  
- Validasi otomatis untuk beberapa field seperti:
  - Nomor rekening (harus 10 digit)
  - Nomor kartu ATM (harus 16 digit)
  - Jenis kelamin (Pria/Perempuan)
  - Jenis akun (Tabungan/Giro/Investasi)
  - Nomor handphone (minimal 10 digit)

### 3. Menu Load Data  
Setelah data berhasil dimuat atau ditambahkan, tersedia submenu:
| No | Fitur | Deskripsi |
|----|--------|-----------|
| 1 | **Display Data Nasabah** | Menampilkan seluruh data dalam format tabel rapi. |
| 2 | **Search Data Nasabah** | Mencari nasabah berdasarkan nama (case-insensitive). |
| 3 | **Sort Berdasarkan Jenis Akun** | Mengurutkan nasabah menurut kategori akun (Tabungan → Giro → Investasi). |
| 4 | **Delete Data Nasabah** | Menghapus nasabah tertentu dengan konfirmasi. |
| 5 | **Output ke File (.CSV)** | Mengekspor hasil data yang telah dimodifikasi ke file CSV baru. |

### 4. Navigasi Menu  
Program memiliki menu interaktif berbasis teks:
```
==========================
=====  BANK LABIRIN  =====
==========================
1. Load data nasabah
2. Input data nasabah baru
3. Exit
```

---

## 🧱 Struktur Data

Program menggunakan **linked list** dengan node bertipe `Nasabah`, yang terdiri atas:
- **PersonalInfo**
  - Nama lengkap
  - Tempat & tanggal lahir
  - Jenis kelamin
  - Alamat
  - Email
  - No. handphone  
- **AccountInfo**
  - No. rekening
  - No. kartu ATM
  - Jenis akun & ID akun
  - Nama ibu kandung
  - Profesi  

Linked list memudahkan penghapusan dan penambahan data tanpa alokasi ulang array.

---

## 🧩 Teknologi dan Bahasa
- Bahasa: **C++ (Standard 11+)**
- Compiler: GCC / MinGW / Visual C++
- File I/O: `fstream` (input/output CSV)
- Data structure: **Linked List**

---

## 🖥️ Cara Menjalankan
1. **Kompilasi program**
   ```bash
   g++ clientdata.cpp -o clientdata
   ```
2. **Jalankan program**
   ```bash
   ./clientdata
   ```
   atau di Windows:
   ```bash
   clientdata.exe
   ```
3. **Ikuti menu interaktif** untuk mengelola data nasabah.

---

## 📂 Format File CSV
File CSV yang digunakan/dihasilkan memiliki header berikut:
```
Nama Lengkap,Tempat Lahir,Tanggal Lahir,Jenis Kelamin,Profesi,Alamat,Email,No Handphone,No Rekening,No Kartu ATM,Jenis Akun,Nama Ibu
```

Contoh isi file:
```
Anton Wijaya,Jakarta,01-01-1990,Pria,Karyawan,Jl. Melati No.10,anton@gmail.com,081234567890,1234567890,1234567890123456,Tabungan,Sri Rahayu
```

---

## 🧹 Catatan Teknis
- Program mendeteksi sistem operasi:
  - `clear` untuk Linux
  - `cls` untuk Windows  
- Versi saat ini: **v3.0**
- Semua operasi disajikan melalui **CLI (Command Line Interface)** tanpa GUI.

---

## ✨ Tetang Project
Project: `client_data`  
Versi: 3.0  
Tujuan: Latihan manajemen data nasabah berbasis struktur data dinamis dan file handling di C++.
