#include <iostream>
#include <vector>
#include <string>

enum class genre {
    Art, Tech, None
};

class book {
public:
    book(const std::string& auth, const std::string& nam, genre gen) : author(auth), m_name(nam), genre(gen) {
    }
    genre get_genre()const {
        return genre;
    }
private:
    const std::string m_name, author;
    const genre genre;
};

class library {
public:

    void AddBook(const std::string& auth, const std::string& name, const genre& gen) {
        if (!auth.empty() && !name.empty()) {
            book_col.emplace_back(new book(auth, name, gen));
        }
    }
    ~library() {
        for (auto book : book_col) {
            delete book;
        }
    }
    void Count() {
        int art = 0,
            tech = 0;
        for (auto book : book_col) {
            switch (book->get_genre())
            {
            case genre::Art:
                ++art;
                break;
            case genre::Tech:
                ++tech;
                break;
            }
        }
        std::cout << "withSw" << std::endl;
        std::cout << "Художественных книг: " << art << std::endl;
        std::cout << "Технических книг: " << tech << std::endl;
    }
    void withoutSwCount() {
        int art = 0,
            tech = 0;
        for (auto book : book_col) {

            if (book->get_genre() == genre::Art) {
                ++art;
            }
            else if ((book->get_genre() == genre::Tech)) {
                ++tech;
            }
        }
        std::cout << "witoutSw" << std::endl;
        std::cout << "Художественных книг: " << art << std::endl;
        std::cout << "Технических книг: " << tech << std::endl;
    }
private:
    std::vector<book*> book_col;
};


int main()
{
    setlocale(LC_ALL, "Ru");
    library lib;
    lib.AddBook("Пушкин", "Капитанская дочка", genre::Art);
    lib.AddBook("Сапковский", "Ведьмак", genre::Art);
    lib.AddBook("EU", "EU EU", genre::Tech);
    lib.AddBook("", "", genre::Art);
    lib.Count();
    lib.withoutSwCount();
    return 0;
}