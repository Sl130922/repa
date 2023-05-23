#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>

struct Reference {
    std::string author;
    std::string title;
    std::string year;
    std::string page;
};
bool inRussian(char ch) {

    if (ch >= 0 && ch <= 127) {
        return false;
    }
    return true;
}

void printReferences(const std::vector<Reference>& references, bool withNumbers) {
    for (int i = 0; i < references.size(); i++) {
        if (withNumbers) {
            std::cout << i + 1 << ". ";
        }
        std::cout << references[i].author << " " << references[i].year << ". " << references[i].title << " " << references[i].page << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    std::vector <Reference> references;
    std::ifstream file("bd2.txt");
    if (!file.is_open()) {
        std::cout << "Error" << std::endl;
        return -1;
    }

    std::string line;
    while (getline(file, line)) {
        std::string author, title, year, page;
        std::istringstream pg(line);
        getline(pg, author, ',');
        getline(pg, year, ',');
        getline(pg, title, ',');
        pg >> page;
        Reference ref = { author, title, year, page };
        references.push_back(ref);
    }
    file.close();


    sort(references.begin(), references.end(), [](const Reference& a, const Reference& b) {

        if (inRussian(a.author[0]) && !inRussian(b.author[0])) {
            return true;
        }
        else if (!inRussian(a.author[0]) && inRussian(b.author[0])) {
            return false;
        }
        else {
            return a.author < b.author;
        }
    });

    std::cout << "Список литературы (с номерами):" << std::endl;
    printReferences(references, true);

    std::cout << std::endl << "Список литературы (без номеров):" << std::endl;
    printReferences(references, false);

    return 0;
}