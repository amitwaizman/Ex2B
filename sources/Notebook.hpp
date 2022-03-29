#ifndef NOTEBOOK_A_NOTEBOOKE_H
#define NOTEBOOK_A_NOTEBOOKE_H
#include <iostream>
#include <string.h>
#include "Direction.hpp"
#include "Page.hpp"

using namespace std;
namespace ariel{
    class Notebook{
    public:
        int max_size=100;
        unordered_map<int, Page> NoteBooke;
        void  write( int NumberPage,  int row,int column,Direction dir, string const& str);
        string read( int NumberPage, int row,int column,Direction dir,int len);
        void  erase( int NumberPage,int row,int column,Direction dir,int len);
        void  show( int  NumberPage);
    };
}


#endif //NOTEBOOK_A_NOTEBOOKE_H
