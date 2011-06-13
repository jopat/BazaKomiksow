#include "ConfigManager.h"
#include <iostream>
#include <fstream>
using namespace std;

/** @file ConfigManager.cpp
 * @brief A brief description of readconfig.cpp.
 *
 * A more extensive description of readconfig.cpp.
 */

//=============================================================
ConfigManager::ConfigManager(const string& configFileName)
{
    this -> configFileName = configFileName;
}

//=============================================================
string ConfigManager::Trim(const string& s)
{
    string tmp = s;

    static const char whitespace[] = " \n\t\v\r\f";
    tmp.erase( 0, tmp.find_first_not_of(whitespace) );
    tmp.erase( tmp.find_last_not_of(whitespace) + 1U );

    return s;
}

//=============================================================
int ConfigManager::ReadConfigFile()
{
    // Plan:
    // 1 - otwarcie pliku konfiguracyjnego
    // 2 - zaczytywanie zawartoœci pliku linia po linii
    //  2.1 - wyszukiwanie linii w których znajduje siê znak '='
    //  2.2 - popranie klucza i sprawdzenie czy nie jest duplikatem
    //  2.3 - zaczytanie wartoœci dla danego klucza
    // 3 - linie zawieraj¹ce odpowiednie wpisy zapisywane s¹ do mapy konfiguracji

    //1
    fstream config(configFileName.c_str());
    if (!config)
    {
        lastError = "B³¹d odczytu pliku konfiguracyjnego.";
        return FILE_ER;
    }

    //2
    string tmp;
    while (getline(config, tmp))
    {
        //2.1
        string key, value;
        size_t found = tmp.find("=");
        if (found != string::npos)
        {
            //2.2
            key = Trim(tmp.substr(0, found));
            if (configDictionary.find(key) == configDictionary.end())
            {
                //2.3
                value = tmp.substr(found + 1, string::npos);
                configDictionary[key] = Trim(value);
            }
        }
    }

    config.close();
    return FILE_OK;
}

//=============================================================
int ConfigManager::SaveConfigFile(const string &key)
{
    // Plan:
    //

    fstream config(configFileName.c_str());
    if (!config)
    {
        lastError = "B³¹d odczytu pliku konfiguracyjnego.";
        return FILE_ER;
    }

    string tmp;
    unsigned pos = 0;
    while (getline(config, tmp))
    {
        size_t found = tmp.find("=");
        if (found != string::npos)
        {
            iterator it = configDictionary.find(key);
            if (it != configDictionary.end())
            {
                tmp = it -> first + "=" + it -> second;
                config.seekp(pos-1, ios::beg);
                config.write(tmp.c_str(), tmp.length());
            }
        }
        pos += tmp.length();
    }

    config.close();
    return FILE_OK;
}

//=============================================================
int ConfigManager::SaveConfigFile()
{
    fstream config(configFileName.c_str(), ios::out | ios::trunc);
    if (!config)
    {
        lastError = "B³¹d odczytu pliku konfiguracyjnego.";
        return FILE_ER;
    }

    iterator it = configDictionary.begin();

    for (; it != configDictionary.end(); it++)
    {
        config << it -> first << " = " << it -> second << endl;
    }

    return FILE_OK;
}

//=============================================================
void ConfigManager::SetDefaultConfig(const map<string, string> &defaultConfig)
{
    configDictionary = defaultConfig;
}
