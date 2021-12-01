#include <iostream>
#include <queue>

using std::queue;
using std::cin; using std::cout;


void print_queue(queue<int> q) {
    cout << "Kuyruk yazdırılıyor... FRONT ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "BACK\n";
}

template<typename T>
void cut(queue<T> &q, int n, const T &item) {
    queue<int> q1 = q, q2;

    for (int i = 0; i < n - 1; i++) {
        q2.push(q1.front());
        q1.pop();
    }
    q2.push(item);
    while (!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }

    q = q2;
}




int main() {
    queue<int> q;
    int kaceleman, yenidegerindex, yenidegerdeger = 0, tempint;

    cout << "Kuyruğa kaç eleman eklemek istiyorsunuz: ";
    cin >> kaceleman;

    cout << kaceleman << " tamsayı değer giriniz...\n";
    for (int i = 0; i < kaceleman; i++) {
        cin >> tempint;
        q.push(tempint);
    }

    cout << "Kuyruğun ilk hali: \n";
    print_queue(q);


    cout << "Kuyruğun neresine yeni değeri eklemek istersiniz: ";
    cin >> yenidegerindex;
    while (yenidegerindex < 1 || yenidegerindex > q.size() + 1) {
        if (yenidegerindex < 1) {
            cout << "Çok küçük değer girdiniz. Daha büyük değer giriniz: ";
            cin >> yenidegerindex;
        } else if (yenidegerindex > q.size() + 1) {
            cout << "Çok büyük değer girdiniz. Daha küçük değer giriniz: ";
            cin >> yenidegerindex;
        }
    }

    cout << "Eklemek istediğiniz değeri giriniz: ";
    cin >> yenidegerdeger;

    cut(q, yenidegerindex, yenidegerdeger);

    print_queue(q);
    
}


