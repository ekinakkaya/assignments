#include <iostream>
using namespace std;


class time24
{
    public:
        // constructor
        time24(int h = 0, int m = 0) {
            hour = h;
            minute = m;
        }

        void addTime(int m);
        time24 duration(const time24 &t);

        void readTime();
        void writeTime() const;

        int getHour() const {
            return hour;
        }

        int getMinute() const {
            return minute;
        }


    private:
        int hour, minute;
        void normalizeTime();
};

void time24::addTime(int m) {
    if (m >= 0) {
        minute += m;
        normalizeTime();
    }
    else {
        cout << "error at addTime: input 'm' must be zero\n";
    }
}

time24 time24::duration(const time24 &t) {
    time24 tR(abs(hour - t.hour), abs(minute - t.minute));
    return tR;
}

void time24::readTime() {
    cout << "Enter time in format HH:MM\n";
    fscanf(stdin, "%d:%d", &hour, &minute);
}

void time24::writeTime() const {
    cout << hour << ":" << minute << "\n";
}

void time24::normalizeTime() {
    int extraHours = 0;
    if (minute >= 60) {
        extraHours = minute / 60;
        minute %= 60;
        hour += extraHours;
    }
    
    if (hour >= 24) {
        hour %= 24;
    }
}





int main() {
    time24 tA(11, 30), tB, tC;

    tB.readTime();
    tB.addTime(50);

    tC = tA.duration(tB);
    tC.writeTime();

    cout << (tC.getHour() * 60 + tC.getMinute());
    
    return 0;
}

