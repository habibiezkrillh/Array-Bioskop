#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	const int totalSeats = 100;
	vector<string> seats(totalSeats, "Kosong");
	string name;
	int numTickets, seatNumber;
	
	while (true) {
		cout<<"Masukkan nama pembeli (atau ketik 'selesai' untuk mengakhiri): ";
		getline(cin, name);
		
		if (name == "selesai") {
			break;
		}
		
		cout<<"Berapa tiket yang ingin dibeli, "<<name<<"? ";
		cin>>numTickets;
		cin.ignore();
		
		for (int i = 0; i < numTickets; ++i) {
			cout<<"Masukkan nomor kursi yang diinginkan (1-"<<totalSeats<<"): ";
			cin>>seatNumber;
			cin.ignore();
			
			if (seatNumber < 1 || seatNumber > totalSeats) {
				cout<<"Nomor kursi tidak valid. Silahkan masukkan nomor kursi antara 1 dan "<<totalSeats<<".\n";
				--i;
				continue;
			}
			
			if (seats[seatNumber - 1] != "Kosong") {
				cout<<"Kursi sudah terisi. Silahkan pilih kursi lain.\n";
				--i;
				continue;
			}
			
			seats[seatNumber - 1] = name;
		}
	}
	
	cout<<"\nDaftar pembeli dan nomor kursi:\n";
	for (int i = 0; i < totalSeats; ++i) {
		if (seats[i] != "Kosong") {
			cout<<"Kursi nomor "<<i + 1<<" Dibeli oleh "<<seats[i] << endl;
		}
	}
	
	return 0;
}
