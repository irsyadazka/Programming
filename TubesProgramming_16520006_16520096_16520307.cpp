#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
using namespace std;

int main()
{
    srand(time(0));
    char mode;
    int siap;
    float distance;
    int killed = 0;
    int robothp = 100;
    int xrobot = 0;
    int yrobot = 0;
    int kecoahp = 40;
    int xkecoa = xrobot;
    int ykecoa = yrobot;

    while ((xkecoa == xrobot) or (ykecoa == yrobot))
    {
        srand(time(0));
        xkecoa = (rand()%5 + 1);
        ykecoa = (rand()%5 + 1);
    }
    
    cout << "Selamat Datang di Medan Perang Membasmi Kecoa!" << endl;
    cout << "\nAmbillah tembakan ini! Tapi ingat, tembakan ini hanya bekerja jika kecoa berada pada jarak <= 5! \nTerlalu jauh dari itu, maka tembakan akan menjadi inakurat" << endl;
    cout << "\nKecoa-kecoa ini cerdik, sehingga mereka dapat menyerang balik jika kamu berada \nsatu petak di depan, belakang, kanan, atau kirinya" << endl << "Apakah kamu sudah siap? (Ketik '1' jika siap)" << endl;
    cin >> siap;

    if (siap == 1) {
    	cout << string(25, '\n');
	    while (robothp > 0)
	    {
	        if (kecoahp == 0) {
	            cout << "\nBerhasil membunuh kecoa! Ayo lakukan lagi!" << endl;
	            killed++;
	            kecoahp = 40;
	            xkecoa = xrobot;
			    ykecoa = yrobot;

			    while ((xkecoa == xrobot) or (ykecoa == yrobot))
			    {
			        srand(time(0));
			        xkecoa = (rand()%5 + 1);
			        ykecoa = (rand()%5 + 1);
			    }

	            cout << "Terpantau kecoa pada koordinat " << xkecoa << "," << ykecoa << endl;
	            cout << "Saat ini kamu berada di koordinat " << xrobot << "," << yrobot << endl;
	            cout << "Robot health: " << robothp << endl;
	            cout << "Kecoa health: " << kecoahp << endl;
	        }
	        else {
	            cout << "Terpantau kecoa pada koordinat " << xkecoa << "," << ykecoa << endl;
	            cout << "Saat ini kamu berada di koordinat " << xrobot << "," << yrobot << endl;
	            cout << "Robot health: " << robothp << endl;
	            cout << "Kecoa health: " << kecoahp << endl;
	    	}

			cout << "Pilih mode: \n W = maju \n S = mundur \n A = kiri \n D = kanan \n X = attack \n Q = quit" << endl;
	        cin >> mode;

	        if (mode == 'Q') break;
	        else {
		        switch (mode) {
		            case 'W' :
		                if (yrobot == 5 or ((xrobot == xkecoa) && (yrobot + 1 == ykecoa))) {
		                	cout << string(25, '\n');
		                    cout << "Tidak bisa menjalankan mode!" << endl;
		                    distance = sqrt((pow((ykecoa - yrobot), 2)) + (pow((xkecoa - xrobot), 2)));
		                } 
		                else {
		                	yrobot += 1;
		                    distance = sqrt((pow((ykecoa - yrobot), 2)) + (pow((xkecoa - xrobot), 2)));
		                    cout << string(25, '\n');
		                }
		                break;
		            case 'S' :
		                if (yrobot == 0 or ((xrobot == xkecoa) && (yrobot - 1 == ykecoa))) {
		                	cout << string(25, '\n');
		                    cout << "Tidak bisa menjalankan mode!" << endl;
		                    distance = sqrt((pow((ykecoa - yrobot), 2)) + (pow((xkecoa - xrobot), 2)));
		                }
		                else {
		                    yrobot -= 1;
		                    distance = sqrt((pow((ykecoa - yrobot), 2)) + (pow((xkecoa - xrobot), 2)));
		                    cout << string(25, '\n');
		                }
		                break;
		            case 'A' :
		                if (xrobot == 0 or ((xrobot - 1 == xkecoa) && (yrobot == ykecoa))) {
		                	cout << string(25, '\n');
		                    cout << "Tidak bisa menjalankan mode!" << endl;
		                    distance = sqrt((pow((ykecoa - yrobot), 2)) + (pow((xkecoa - xrobot), 2)));
		                }
		                else {
		                    xrobot -= 1;
		                    distance = sqrt((pow((ykecoa - yrobot), 2)) + (pow((xkecoa - xrobot), 2)));
		                    cout << string(25, '\n');
		                }
		                break;
		            case 'D' :
		                if (xrobot == 5 or ((xrobot + 1 == xkecoa) && (yrobot == ykecoa))) {
		                	cout << string(25, '\n');
		                    cout << "Tidak bisa menjalankan mode!" << endl;
		                    distance = sqrt((pow((ykecoa - yrobot), 2)) + (pow((xkecoa - xrobot), 2)));
		                }
		                else {
		                    xrobot += 1;
		                    distance = sqrt((pow((ykecoa - yrobot), 2)) + (pow((xkecoa - xrobot), 2)));
		                    cout << string(25, '\n');
		                }
		                break;
		            case 'X' :
		                distance = sqrt((pow((ykecoa - yrobot), 2)) + (pow((xkecoa - xrobot), 2)));
		                if (distance > 5) {
		                	cout << string(25, '\n');
		                    cout << "Tidak bisa menjalankan mode!" << endl;
		                    distance = sqrt((pow((ykecoa - yrobot), 2)) + (pow((xkecoa - xrobot), 2)));
		                } 
		                else {
		                    kecoahp -= 10;
		                    distance = sqrt((pow((ykecoa - yrobot), 2)) + (pow((xkecoa - xrobot), 2)));
		                    cout << string(25, '\n');
		                }
		    	}

			    if (((xkecoa == xrobot + 1) && (ykecoa == yrobot)) or ((xkecoa == xrobot - 1) && (ykecoa == yrobot)) or ((ykecoa == yrobot + 1) && (xkecoa == xrobot)) or ((ykecoa == yrobot - 1) && (ykecoa == yrobot))) {
			    	cout << "\n ALERT! DAMAGED BY KECOA (-5 HP) \n";
			    	robothp -= 5;
			    	cout << "Jarak ke kecoa: " << distance << endl;
				}
			    else {
			    	cout << "Jarak ke kecoa: " << distance << endl;
				}
	        }
	    }
	    cout << string(30, '\n');
	    cout << "GAME OVER! \n Total kecoa yang terbunuh: " << killed << "\n Good job!"; 
	}
	else cout << "\n Aku kira kamu sudah siap, ternyata masih mental jelly. Euhh goreng";
}