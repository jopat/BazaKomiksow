#ifndef READCONFIG_H
#define READCONFIG_H

#include <QWidget>
#include <string>
#include <map>
using namespace std;

/** @file ConfigManager.h
 *  @brief ConfigFileManager klasa obsługująca pliki konfiguracyjne.
 *
 * Klasa ConfigFileManager służy do zarządzania plikami konfiguracyjnymi
 * tj. zapisaniem, odczytaniem, edycją pojedyńczych wartości.
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

    /** @brief Mapa do przechowywaniawartości zaczytanych z pliku konfiguracyjnego.
    *
    * Mapa przechowuje wartości właściwości zaczytanych z pliku konfiguracyjnego.
    * Kluczem jest nazwa właściwości, wartością jest wartość danej właściwości zaczytana z pliku.
    */
    map<string, string> configDictionary;

    /** @enum FileStatus
     * Enum ze statusami wykonania metod z klasy.
     */
    enum FileStatus
    {
        ACTION_OK = 0,    /*!< Metoda zaostała wykonana poprawnie. */
        ACTION_ER = 1     /*!< Metoda została wykonana z błędem. */
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
