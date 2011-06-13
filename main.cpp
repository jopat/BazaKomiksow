#include <QtGui/QApplication>
#include <QTextCodec>
#include "mainwindow.h"

/** @file main.cpp
 * @brief A brief description of filename.ext.
 *
 * A more extensive description of filename.ext.
 */

/** \brief A brief description of myProcedure().
 *
 * A more extensive description of myProcedure().
 * \param argc A brief description of argc.
 * \param *argv[] A brief description of *argv[].
 * \return A brief description of what myProcedure() returns.
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName ("Windows-1250"));
    MainWindow w;
    w.show();

    return a.exec();
}

/** @mainpage package templates
*
* @authors Documentation Task Force
*
* @section intro Introduction
*
* This project includes some algorihms to handle databses (especialy sqlite ver. 3).
*
*
* Also note the existence of the following directories:
* - cmt
* -# Contains the requirements file
* - doc
* -# Contains the release.notes file
*
* @todo [optionally include text about more work to be done]
* @todo Sprawdzenie istnienia bazy. W przypadku braku stworzyæ now¹.
* @todo Przegl¹danie bazy danych, perzygotowaæ odpowiednie formatki do tabel.
* @todo Dodawanie rekordów do azy danych, perzygotowaæ odpowiednie formatki do tabel.
*
*/
