#include "StringTools.h"

//=============================================================
string StringTools::Trim(const string& str)
{
    string tmp = str;

    static const char whitespace[] = " \n\t\v\r\f";
    tmp.erase( 0, tmp.find_first_not_of(whitespace) );
    tmp.erase( tmp.find_last_not_of(whitespace) + 1U );

    return tmp;
}
