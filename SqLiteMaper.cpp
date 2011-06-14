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
    db -> close();
    if (db)
        delete db;
}

//=============================================================
int SqLiteMaper::CreateDatabase(const string &fileName)
{
    ifstream file;
    file.open(fileName.c_str());
    string createQuery;

    if(file.good())
    {
        string tmp;
        while(!file.eof())
        {
            getline(file, tmp);
            createQuery += tmp;
        }

        if(db -> isOpen())
        {
            lastError = "Baza danych ju¿ istnieje.";
        }
        else
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
                query.exec(QString::fromStdString(createQuery));
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
    QSqlDatabase dbTmp = QSqlDatabase::addDatabase("QSQLITE");
    dbTmp.setDatabaseName(QString::fromStdString(dbName));

    db = new QSqlDatabase(dbTmp);

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
    struct stat stFileInfo;
    int intStat;

    // Attempt to get the file attributes
    intStat = stat(dbName.c_str(), &stFileInfo);
    if(intStat == 0)
    {
    // We were able to get the file attributes
    // so the file obviously exists.
        return true;
    }
    else
    {
    // We were not able to get the file attributes.
    // This may mean that we don't have permission to
    // access the folder which contains this file. If you
    // need to do that level of checking, lookup the
    // return values of stat which will give you
    // more details on why stat failed.
        return false;
    }
}

//=============================================================
void SqLiteMaper::ReadSqlFromFile(const string &fileName)
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
        unsigned pos = 0;
        while (getline(file, lineTmp))
        {
            size_t found = lineTmp.find(";");
            if (found != string::npos)
            {
                char[1024] tmp;
                file.seekg(pos, ios::beg);
                int p = pos + found;
                file.read(tmp, p);
                sqlTmp += tmp;



                pos = found + 1;
                sqlTmp.clear();
            }
            else
            {
                sqlTmp += lineTmp;
            }
        }
    }
    else
    {

    }
}


