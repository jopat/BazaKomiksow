/** @file ConfigManager.cpp
 *  @brief Plik z implementacj¹ klasy ConfigManager.
 *
 * ================================================
 *  @author  Jakub Opatowski
 *  @version 0.1
 *  @date    30 VI 2011
 * ================================================
 */

#include "ConfigManager.h"
#include "StringTools.h"

#include <iostream>
#include <fstream>
using namespace std;

//=============================================================
ConfigManager::ConfigManager(const string& configFileName)
{
    this -> configFileName = configFileName;
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
        return ACTION_ER;
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
            key = StringTools::Trim(tmp.substr(0, found));
            if (configDictionary.find(key) == configDictionary.end())
            {
                //2.3
                value = tmp.substr(found + 1, string::npos);
                configDictionary[key] = StringTools::Trim(value);
            }
        }
    }

    config.close();
    return ACTION_OK;
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
        return ACTION_ER;
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
    return ACTION_OK;
}

//=============================================================
int ConfigManager::SaveConfigFile()
{
    fstream config(configFileName.c_str(), ios::out | ios::trunc);
    if (!config)
    {
        lastError = "B³¹d odczytu pliku konfiguracyjnego.";
        return ACTION_ER;
    }

    iterator it = configDictionary.begin();

    for (; it != configDictionary.end(); it++)
    {
        config << it -> first << " = " << it -> second << endl;
    }

    return ACTION_OK;
}

//=============================================================
void ConfigManager::SetDefaultConfig(const map<string, string> &defaultConfig)
{
    configDictionary = defaultConfig;
}
