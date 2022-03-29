#include "Notebook.hpp"
#include "Direction.hpp"
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
namespace ariel {
    void Notebook::write(int NumberPage, int row, int column, Direction dir, string const &str) {
        int len = str.length();
        int exp = column + len;
        for (unsigned int i = 0; i < len; ++i) {
            if ((str[i] < ' ') || (str[i] >= '~')) {
                throw std::out_of_range{"Unwanted character"};
            }
        }
        if (row < 0 || column < 0 || NumberPage < 0) {
            throw std::out_of_range{"Negative value"};
        }
        if ((exp > max_size) && (dir == Direction::Horizontal)) {
            throw std::out_of_range{"You have exceeded 100 characters"};
        }
        if (column > max_size - 1) {
            throw std::out_of_range{"You have exceeded 100 characters"};
        }
        NoteBooke[NumberPage].write_in_Page(row, column, dir, str);
    }

    string Notebook::read(int NumberPage, int row, int column, Direction dir, int len) {
        int exp = len + column;
        if (row < 0 || column < 0 || len < 0 || NumberPage < 0) {
            throw std::out_of_range{"Negative value"};
        }
        if (column > max_size - 1) {
            throw std::out_of_range{"You have exceeded 100 characters"};
        }

        if ((exp > max_size) && dir == Direction::Horizontal) {
            throw std::out_of_range{"You have exceeded 100 characters"};
        }
        return NoteBooke[NumberPage].read_in_Page(row, column, dir, len);


    }

    void Notebook::erase(int NumberPage, int row, int column, Direction dir, int len) {
        int exp = len + column;
        if ((exp > max_size) && (dir == Direction::Horizontal)) {
            throw std::out_of_range{"You have exceeded 100 characters"};
        }
        if (column > max_size - 1) {
            throw std::out_of_range{"You have exceeded 100 characters"};
        }

        if (row < 0 || column < 0 || len < 0 || NumberPage < 0) {
            throw std::out_of_range{"Negative value"};
        }
        NoteBooke[NumberPage].erase_page(row, column, dir, len);

    }

    void Notebook::show(int NumberPage) {
        if (NumberPage < 0) {
            throw std::out_of_range{"Negative value"};
        }
        NoteBooke[NumberPage].showPage();

    }
}