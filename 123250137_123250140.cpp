#include <iostream>
#include <fstream>
using namespace std;

struct Mahasiswa {
    string namaMahasiswa;
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
        getline(cin, m.namaMahasiswa);

        cout<<"Nim           : ";
        getline(cin, m.nim);

        cout<<"Prodi         : ";
        getline(cin, m.prodi);

        cout<<"IPK      : ";
        cin>>m.ipk;
        cin.ignore();

        file<<m.namaMahasiswa<<"|";
        file<<m.nim<<"|";
        file<<m.prodi<<"|";
        file<<m.ipk<<endl;
    }
    file.close();
    cout<<"Data Berhasil Disimpan"<<endl;
}

int hitungData() {
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
    ifstream file("dataMahasiswa.txt");

    if (!file)
    {
        n = 0;
        return;
    }
    n = 0;

    while(getline(file, m[n].namaMahasiswa, '|'))
    {
        getline(file, m[n].nim, '|');
        getline(file, m[n].prodi, '|');

        file >> m[n].ipk;
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

    while (getline(file, m.namaMahasiswa, '|'))
    {
        getline(file, m.nim, '|');
        getline(file, m.prodi, '|');
        file >> m.ipk;
        file.ignore();

        cout<<"Data ke-"<< no++ << endl;
        cout<<"Nama Mahasiswa   : "<<m.namaMahasiswa<<endl;
        cout<<"Nim              : "<<m.nim<<endl;
        cout<<"Prodi            : "<<m.prodi<<endl;
        cout<<"IPK              : "<<m.ipk<<endl;
        cout<<endl;
    }
    file.close();
}

int partitionNim(Mahasiswa m[], int low, int high) {
    string pivot = m[high].nim;

    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (m[j].nim < pivot)
        {
            i++;

            Mahasiswa temp = m[i];
            m[i] = m[j];
            m[j] = temp;
        }
    }

    Mahasiswa temp = m[i + 1];
    m[i + 1] = m[high];
    m[high] = temp;

    return i + 1;
}

void quickSort(Mahasiswa m[], int low, int high) {
    if (low < high)
    {
        int pi = partitionNim(m, low, high);

        quickSort(m, low, pi - 1);
        quickSort(m, pi + 1, high);
    }
}

void sortingNim() {
    Mahasiswa m[100];
    int n;

    muatData(m, n);

    if(n == 0)
    {
        cout << "Data kosong!" << endl;
        return;
    }

    quickSort(m, 0, n - 1);

    cout << "\n=== DATA SETELAH SORTING NIM ===\n";

    for(int i = 0; i < n; i++)
    {
        cout << "Data ke-" << i + 1 << endl;
        cout << "Nama Mahasiswa : " << m[i].namaMahasiswa << endl;
        cout << "NIM            : " << m[i].nim << endl;
        cout << "Prodi          : " << m[i].prodi << endl;
        cout << "IPK            : " << m[i].ipk << endl;
        cout << endl;
    }
}

int main() {
    int pilih;
    do{

        cout<<"============================================"<<endl;
        cout<<"               DATA MAHASISWA               "<<endl;
        cout<<"============================================"<<endl;
        cout<<"1. Tambah Data Mahasiswa"<<endl;
        cout<<"2. Tampilkan Data Mahasiswa"<<endl;
        cout<<"3. Sorting Berdasarkan Nim"<<endl;
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
            sortingNim();
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
