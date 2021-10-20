#include <iostream>
#include <string>

using namespace std;

class Ders {
    private:
        string DersinKodu;
        bool DersBasariDurumu;
        float Vize, Final, BasariOrtalamasi;

    public:
        void DersOzeti() {
            cout << "Dersin Adı: " << DersinKodu << "\n";
            cout << "Vize Notu: " << Vize << "\n";
            cout << "Final Notu: " << Final << "\n";
            cout << "Ortalaması: " << BasariOrtalamasi << "\n";
            cout << "Başarı Durumu: " << DersBasariDurumu << "\n\n";
        }

        void Bilgiler(string DersKodu, float vize, float final) {
            DersinKodu = DersKodu;
            Vize = vize;
            Final = final;
            BasariOrtalamasi = (Vize * 0.6) + (Final + 0.4);

            DersBasarisi(BasariOrtalamasi);
        }

        bool DersBasarisi(float DersOrtalamasi) {
            if (DersOrtalamasi >= 60)
                DersBasariDurumu = true;
            else
                DersBasariDurumu = false;
        }

};

    

class Ogrenci {
    public:
        int OkulNumarasi;
        string OgrencininAdi, OgrencininSoyadi;

        int dersAdedi;

        Ders KayitliOlduguDersler[64];

        Ogrenci(string Adi = " ", string Soyadi = " ", int OkulNo = 0) {
            OgrencininAdi = Adi;
            OgrencininSoyadi = Soyadi;
            OkulNumarasi = OkulNo;
        }


        void DersBilgileri(Ders DersListesi[], int DersAdedi) {
            for (int i = 0; i < DersAdedi; i++) {
                KayitliOlduguDersler[i] = DersListesi[i];
                DersListesi[i].DersOzeti();
            }
            dersAdedi = DersAdedi;
        }

        void KimlikBilgileri() {
            cout << "Adı     : " << OgrencininAdi << "\n";
            cout << "Soyadı  : " << OgrencininSoyadi << "\n";
            cout << "Okul No : " << OkulNumarasi << "\n";
        }
};


int main() {
    Ogrenci ogrenciler[128];
    int ogrenciSayisi;

    string temp_DersKodu;
    float temp_Vize, temp_Final;

    cout << "Ogrenci sayisini giriniz: ";
    cin >> ogrenciSayisi;

    cout << "\nOgrenci Bilgilerini Giriniz\n";
    for (int i = 0; i < ogrenciSayisi; i++) {
        cout << i << ". ogrencinin okul numarasi, adini ve soyadini giriniz: ";
        cin >> ogrenciler[i].OkulNumarasi >> ogrenciler[i].OgrencininAdi >> ogrenciler[i].OgrencininSoyadi;
    }

    for (int i = 0; i < ogrenciSayisi; i++) {
        cout << ogrenciler[i].OgrencininAdi << " " << ogrenciler[i].OgrencininSoyadi << " adlı ogrenciye ait ders bilgilerini giriniz." << "\n";
        cout << "Ders Adedi: ";
        cin >> ogrenciler[i].dersAdedi;

        for (int j = 0; j < ogrenciler[i].dersAdedi ; j++) {
            cout << j << ". ders için DersKodu, Vize, Final Giriniz: ";
            cin >> temp_DersKodu >> temp_Vize >> temp_Final;

            ogrenciler[i].KayitliOlduguDersler[j].Bilgiler(temp_DersKodu, temp_Vize, temp_Final);
        }
        cout << "\n";
    }

    
    for (int i = 0; i < ogrenciSayisi; i++) {
        ogrenciler[i].KimlikBilgileri();

        for (int j = 0; j < ogrenciler[i].dersAdedi ; j++) {
            ogrenciler[i].KayitliOlduguDersler[j].DersOzeti();
        }
    }
        


    return 0;
}
