#include <iostream>
#include <string.h>
#include <unordered_map>
#include "Direction.hpp"
#include <string>
using namespace std;
namespace ariel {
    class  Page{
    public:
        int max_size1=100;
         unordered_map<int,char[100]> page;
        void write_in_Page(int  row, int  column,Direction dir, string const& str);
        string read_in_Page(int  row,int   column, Direction dir,int   len);
        void erase_in_Page(int  row,int   column, Direction dir,int   len);
        void erase_page(int  row,int   column, Direction dir,int   len);
        void showPage();
    };

};