#ifndef STRINGTOOLS_H
#define STRINGTOOLS_H

/** @file StringTools.h
 *  @brief Plik zawiera implementacje narzedzi dla standardowych stringów.
 */

#include<string>
using namespace std;

/** @brief Klasa implementuje statyczne metody do manipulowania standardowymi stringami.
 */
class StringTools
{
public:
    static string Trim(const string& s);
};

#endif // STRINGTOOLS_H
