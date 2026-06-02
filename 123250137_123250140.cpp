#include <iostream>
#include <fstream>
using namespace std;

struct Mahasiswa {
    string namaMahasiwa;
    string nim;
    string prodi;
    float ipk;
};

void tambahData() {
    ofstream file("dataMahasiswa.txt", ios::app);

    int banyakData;
    cout<<"Banyak data yang ingin ditambah: ";
    cin>>banyakData;
    cin.ignore();

    Mahasiswa m;
    for (int i = 0; i < banyakData; i++)
    {
        cout<<"Data ke-"<<i+1<<endl;
        cout<<"Nama Mahasiswa: ";
        getline(cin, m.namaMahasiwa);

        cout<<"Nim           : ";
        getline(cin, m.nim);

        cout<<"Prodi         : ";
        getline(cin, m.prodi);

        cout<<"IPK      : ";
        cin>>m.ipk;
        cin.ignore();

        file<<m.namaMahasiwa<<" | ";
        file<<m.nim<<" | ";
        file<<m.prodi<<" | ";
        file<<m.ipk<<endl;
    }
    file.close();
    cout<<"Data Berhasil Disimpan"<<endl;
}

int hitungData(){
    ifstream file("dataMahasiswa.txt");
    
    if (!file)
    {
        return 0;
    }

    string temp;
    int count = 0;
    
    while (getline(file,temp))
    {
        count++;
    }
    file.close();
    return count;
}

void muatData(Mahasiswa m[], int &n) {
    ifstream file("resepNusantara.txt");
    n = 0;

    while (getline(file, m[n].namaMahasiwa, '|')) 
    {
        getline(file, m[n].nim, '|');

        getline(file, m[n].prodi);

        file>>m[n].ipk;
        file.ignore();
        n++;
    }
    file.close();
}

void tampilkanData() {
    ifstream file("dataMahasiswa.txt");
    if (!file || file.peek() == EOF)
    {
        cout<<"File belum ada atau data masih kosong."<<endl;
        return;
    }
    Mahasiswa m;
    int no = 1;

    while (getline(file,m.namaMahasiwa, '|'))
    {
        getline(file, m.nim, '|');

        getline(file, m.prodi);

        file >> m.ipk;
        file.ignore();

        cout<<"Data ke-"<< no++ << endl;
        cout<<"Nama Mahasiswa   : "<<m.namaMahasiwa<<endl;
        cout<<"Nim              : "<<m.nim<<endl;
        cout<<"Prodi            : "<<m.prodi<<endl;
        cout<<"IPK              : "<<m.ipk<<endl;
        cout<<endl;
    }
    file.close();
}

int main() {
    do{
        int pilih;

        cout<<"============================================"<<endl;
        cout<<"               DATA MAHASISWA               "<<endl;
        cout<<"============================================"<<endl;
        cout<<"1. Tambah Data Mahasiswa"<<endl;
        cout<<"2. Tampilkan Data Mahasiswa"<<endl;
        cout<<"3. aaa"<<endl;
        cout<<"4. aaa"<<endl;
        cout<<"5. aaa"<<endl;
        cout<<"============================================"<<endl;
        cout<<"Pilih Menu (1-?): ";
        cin>>pilih;

        switch (pilih)
        {
        case 1:
            tambahData();
            break;
        case 2:
            tampilkanData();
            break;
        case 3:
            //aaa
            break;
        case 4:
            //aaa
            break;
        case 5:
            //aaa
            break;
        default:
            cout<<"Pilihan Tidak Valid"<<endl;
            break;
        }
    } while(pilih !=?);
    return 0;
}
