#include <iostream>
#include <string>
#include <unordered_map>
#include "Page.hpp"
#include <stdexcept>
#include <iterator>
#include "Direction.hpp"
using namespace std;
namespace ariel {
    void Page::write_in_Page(int row, int column, Direction dir, string const &str) {
        int len=str.length();
            if (dir == Direction::Horizontal) {
                unsigned int t=0;
                for (int i = column; i < len+column; i++) {
                    if (page[row][i] > '~' || page[row][i] <' ' || page[row][i] == '_') {
                            page[row][i] = str[t];
                            t++;
                    } else {
                        throw std::out_of_range{"You have already write/deleted"};
                    }
                }
            }else if(dir == Direction::Vertical){
                unsigned int t=0;
                for (int i = row; i <len+row ; i++) {
                    if(page[i][column]> '~' || page[i][column] <' ' || page[i][column] == '_'){
                            page[i][column] = str[t];
                            t++;
                    } else {
                        throw std::out_of_range{"You have already write/deleted"};
                    }
                    }
                }
            }


    string Page::read_in_Page(int row, int column, Direction dir, int len) {
            string str;
            if (dir == Direction::Horizontal) {
                for (int i = column; i < len+column; i++) {
                    if((page[row][i]<= '~' )&&(page[row][i] >=' ')){
                        str+=page[row][i];
                    } else{
                       page[row][i]='_';
                        str+=page[row][i];
                    }

                }
            }
            if (dir == Direction::Vertical) {
                for (int i = row; i < len+row; i++) {
                    if((page[i][column]<= '~') && (page[i][column] >=' ')){
                        str+=page[i][column];
                    }else{
                       page[i][column]='_';
                        str+=page[i][column];
                    }

                }
            }
        return str;
    }


    void Page::erase_page(int row, int column, Direction dir, int len) {
            if (dir == Direction::Horizontal) {
                for (int i = column; i < len+column; i++) {
                        page[row][i] = '~';
                }
            }
            if (dir == Direction::Vertical) {
                for (int i = row; i < len+row; i++) {
                        page[i][column] = '~';
                }
            }
        }

    void Page::showPage(){
        int number_row=0;
        for (auto iter =page.begin(); iter!=page.end(); iter++) {
            if(number_row<iter->first){
                number_row=iter->first;
            }

        }

        for (int i = 0; i<number_row ; i++) {
            for(int j=0; j<max_size1; j++){
                if(page[i][j] > '~' || page[i][j] <' '){
                    page[i][j]='_';
                    cout<<'_';
            }else{
                    cout<<page[i][j];
                }
        }

    }
    }

    }
