/** \file SqLiteMaper.cpp
 * \brief A brief description of filename.ext.
 *
 * A more extensive description of filename.ext.
 */

#include <QSqlError>
#include <QSqlQuery>
#include <fstream>
#include "SqLiteMaper.h"
#include <sys/stat.h>
#include "Log.h"

using namespace std;

// KONSTRUKTOR
//=============================================================
SqLiteMaper::SqLiteMaper(const string& dbName)
{
    this -> dbName = dbName;
}

// DESTRUKTOR
//=============================================================
SqLiteMaper::~SqLiteMaper()
{
    if (db)
    {
        if (db -> isOpen())
            db -> close();
        delete db;
    }
}

//=============================================================
int SqLiteMaper::CreateDatabase(const string &fileName)
{
    // zaczytanie pliku ze skryptem buduj¹cym bazê
    ifstream file;
    file.open(fileName.c_str());
    string createQuery;

    if(file.good())
    {
        if (ReadSqlFromFile(fileName))
        {
            fstream dbFileContainer;
            dbFileContainer.open(dbName.c_str(), ios::out | ios::trunc);
            dbFileContainer.close();

            //tworzenie bazy danych w pliku
            QSqlDatabase dbFile = QSqlDatabase::addDatabase("QSQLITE");
            dbFile.setDatabaseName("comics.db");
            if (dbFile.open())
            {
                QSqlQuery query(dbFile);

                for (vector<string>::iterator it = sqlList.begin(); it != sqlList.end(); it++)
                {
                    query.exec(QString::fromStdString(*it));
                }

                //query.exec(QString::fromStdString(it[0]));

                QSqlError error = query.lastError();
                lastError = error.text().toStdString();
                dbFile.close();
            }
        }
    }
    else
    {
        lastError = "Brak pliku sql bazy danych !";
    }
    return 1;
}

//=============================================================
int SqLiteMaper::ConnectionStatus()
{
    if (db -> isOpen())
        return 1;
    else
        return 0;
}

//=============================================================
int SqLiteMaper::Connect()
{
    if (!db)
    {
        QSqlDatabase dbTmp = QSqlDatabase::addDatabase("QSQLITE");
        dbTmp.setDatabaseName(QString::fromStdString(dbName));

        db = new QSqlDatabase(dbTmp);
    }

    if (!db -> open())
    {
        QSqlError error = db -> lastError();
        lastError = "B³¹d po³¹czenia.\n";
        lastError += error.text().toStdString();

        return CONNECTION_ERRROR;
    }

    return CONNECTION_OK;
}

//=============================================================
int SqLiteMaper::Disconnect()
{
    if (db -> isOpen())
        db -> close();
    return CONNECTION_CLOSED;
}

//=============================================================
bool SqLiteMaper::CheckDatabase()
{
    ifstream ifile(dbName.c_str());
    return ifile;
}

//=============================================================
int SqLiteMaper::ReadSqlFromFile(const string &fileName)
{
    // dzielimy plik na pojedyncze zapytania sql
    // zapytania s¹ oddzielone znakiem ';'

    //1. otwieramy plik
    fstream file;
    file.open(fileName.c_str());

    //2. je¿eli plik jest ok, kontynuuj
    if(file.good())
    {
        string lineTmp, sqlTmp;
        //2.1. zaczytaj plik linia po linii
        while (getline(file, lineTmp))
        {
            //2.2. poszukaj wyst¹pienia w linni znaku koñca zapytania
            size_t semicolonPosition = lineTmp.find(";");
            //2.3. je¿eli znajjdziesz taki znak
            if (semicolonPosition != string::npos)
            {
                char tmp[lineTmp.length()];
                lineTmp.copy(tmp, semicolonPosition + 1);
                sqlTmp += tmp;
                sqlList.push_back(sqlTmp);
                sqlTmp.clear();
            }
            //2.4. je¿eli nie znajdziesz takiego znaku
            else
            {
                sqlTmp += lineTmp;
            }
        }
        return 1;
    }
    //3. plik nie zosta³ odczytany poprawnie
    else
    {
        return 0;
    }
}


