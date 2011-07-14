#ifndef READCONFIG_H
#define READCONFIG_H

#include <QWidget>
#include <string>
#include <map>
using namespace std;

/** @file ConfigManager.h
 *  @brief ConfigFileManager klasa obs�uguj�ca pliki konfiguracyjne.
 *
 * Klasa ConfigFileManager s�u�y do zarz�dzania plikami konfiguracyjnymi
 * tj. zapisaniem, odczytaniem, edycj� pojedy�czych warto�ci.
 */

/** @brief Config files reading class.
 *
 * A more extensive description of MyClass.
 */
class ConfigManager
{
public:

    /** @typedef iterator
    * Iterator dla mapy typu map<string, string>
    */
    typedef map<string, string>::iterator iterator;

    /** @brief Mapa do przechowywaniawarto�ci zaczytanych z pliku konfiguracyjnego.
    *
    * Mapa przechowuje warto�ci w�a�ciwo�ci zaczytanych z pliku konfiguracyjnego.
    * Kluczem jest nazwa w�a�ciwo�ci, warto�ci� jest warto�� danej w�a�ciwo�ci zaczytana z pliku.
    */
    map<string, string> configDictionary;

    /** @enum FileStatus
     * Enum ze statusami wykonania metod z klasy.
     */
    enum FileStatus
    {
        ACTION_OK = 0,    /*!< Metoda zaosta�a wykonana poprawnie. */
        ACTION_ER = 1     /*!< Metoda zosta�a wykonana z b��dem. */
    };

    /** @brief Konstruktor tworzy manager konfiguracji dla danego pliku.
     *
     * A more extensive description of myProcedure().
     * @param configFileName A brief description of aParameter.
     */
    ConfigManager(const string& configFileName);

    /** @brief A brief description of myProcedure().
     *
     * A more extensive description of myProcedure().
     * @return A brief description of what myProcedure() returns.
     */
    int ReadConfigFile();

    /** @brief A brief description of myProcedure().
     *
     * A more extensive description of myProcedure().
     * @param aParameter A brief description of aParameter.
     * @return A brief description of what myProcedure() returns.
     */
    int SaveConfigFile();

    /** @brief A brief description of myProcedure().
     *
     * A more extensive description of myProcedure().
     * @param aParameter A brief description of aParameter.
     * @return A brief description of what myProcedure() returns.
     */
    int SaveConfigFile(const string &key);

    /** @brief A brief description of myProcedure().
     *
     * A more extensive description of myProcedure().
     * @param aParameter A brief description of aParameter.
     * @return A brief description of what myProcedure() returns.
     */
    void SetDefaultConfig(const map<string, string> &defaultConfig);

private:
    string lastError;
    string configFileName;
};

#endif // READCONFIG_H
