#include <iostream>
#include <stack>

using std::stack;
using std::cin; using std::cout;


void print_stack(stack<int> &s) {
    stack<int> st = s;
    cout << "Yığın Yazdırılıyor... TOP";
    while (!st.empty()) {
        cout << " " << st.top();
        st.pop();
    }
    cout << " BOTTOM\n";
}



template <typename T>
T second(const stack<T> &s) {
    if (s.size() < 2)
        throw std::invalid_argument("underflowError");

    stack<int> st = s;

    st.pop();
    return st.top();
}



template <typename T>
void n2top(stack<T> &s, int n) {
    stack<int> st1 = s, st2;
    int nth_element;

    /* obtain nth element */
    for (int i = 0; i < n - 1; i++) {
        st2.push(st1.top());
        st1.pop();
    }

    nth_element = st1.top();
    st1.pop();

    while (!st2.empty()) {
        st1.push(st2.top());
        st2.pop();
    }
    st1.push(nth_element);
    s = st1;
}



int main() {
    int stacksiz, tempint = 0, kacincieleman = 0;
    stack<int> s;

    cout << "Yığıta kaç eleman eklemek istiyorsunuz: ";
    cin >> stacksiz;
    cout << stacksiz << " tamsayı değer giriniz...\n";

    for (int i = 0; i < stacksiz; i++) {
        cin >> tempint;
        s.push(tempint);
    }

    print_stack(s);

    cout << "Yığıtın üstten 2. elemanı: "<< second(s) << "\n\n";



    cout << "Yığıtın kaçıncı elemanını üste almak istersiniz: ";
    cin >> kacincieleman;
    while (kacincieleman > s.size() || kacincieleman <= 0) {
        cout << "Yığıtın bu elemanı yok. Farklı bir değer giriniz: ";
        cin >> kacincieleman;
    }

    n2top(s, kacincieleman);

    print_stack(s);

    
}


