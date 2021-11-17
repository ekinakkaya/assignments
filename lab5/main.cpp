#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>


using namespace std;



bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}



class Student {
    public:
        vector<string> name;
        string lastname;
        int number;
};


class ZoomChatLog {
    public:
        vector<string> chat_lines;
        vector<Student> students;

        ZoomChatLog(string logfile_name) {
            string tempstr;
            Student s;

            ifstream chatfile(logfile_name);

            while (getline(chatfile, tempstr)) {
                chat_lines.push_back(tempstr);
            }

            chatfile.close();


            for (int i = 0; i < chat_lines.size(); i++) {
                Student s = extractStudentInfo(chat_lines[i]);
                students.push_back(s);
            }


            /* sort by student number */
            Student st;
            for (int i = 0; i < students.size(); i++) {
                for (int j = 0; j < students.size(); j++) {
                    if (students[i].number < students[j].number) {
                        st = students[i];
                        students[i] = students[j];
                        students[j] = st;
                    }
                }
            }



            /* remove duplicates */
            for (int i = 0; i < students.size(); i++) {
                if (students[i].number == students[i + 1].number) {
                    students.erase(students.begin() + i);
                    i--;
                }
            }
            


            /* write to file */

            ofstream outputfile("YoklamaListesi.txt");
            for (int i = 0; i < students.size(); i++) {
                outputfile << i << ". " << students[i].number;
                for (int j = 0; j < students[i].name.size(); j++)
                    outputfile << " " << students[i].name[j];
                outputfile << "\n";
            }


        }

        vector<string> parseLine(string raw_line);
        Student extractStudentInfo(string raw_line);
};


vector<string> ZoomChatLog::parseLine(string raw_line) {
    stringstream strstream(raw_line);
    string token;

    vector<string> chat_line_tokens;


    while ( getline(strstream, token, ' ') ) {
        chat_line_tokens.push_back(token);
    }

    if (0) { // debug
        for (int i = 0; i < chat_line_tokens.size(); i++)
            cout << "'" << chat_line_tokens[i] << "' ";
        cout << "\n";
    }

    return chat_line_tokens;
}



Student ZoomChatLog::extractStudentInfo(string raw_line) {
    Student s;
    bool parsed_number = false, parsed_name = false;
    vector<string> tokens = parseLine(raw_line);

    /* discard until the token after ":" */
    while (tokens[0] != ":") {
        tokens.erase(tokens.begin());
    }
    tokens.erase(tokens.begin());

    if (0) { // debug
        for (int i = 0; i < tokens.size(); i++)
            cout << "'" << tokens[i] << "' ";
        cout << "\n";
    }


    /* pick the student number and erase it from tokens */
    for (int i = 0; i < tokens.size(); i++)
        if (isNumber(tokens[i])) {
            s.number = atoi(tokens[i].c_str());
            tokens.erase(tokens.begin() + i);
        }

    /* add remaining tokens to the vector name */
    s.name = tokens;

    return s;
}





int main() {
    vector<string> chat_lines;

    ZoomChatLog log("Lab5.txt");

    return 0;
}
