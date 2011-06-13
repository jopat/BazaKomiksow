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
 * oraz do wykorzystania informacji w nich zawartych.
 */

/** @brief Config files reading class.
 *
 * A more extensive description of MyClass.
 */
class ConfigManager
{
public:

    typedef map<string, string>::iterator iterator;

    /** @brief Mapa do przechowywaniawarto�ci zaczytanych z pliku konfiguracyjnego.
    *
    * Mapa przechowuje warto�ci w�a�ciwo�ci zaczytanych z pliku konfiguracyjnego.
    * Kluczem jest nazwa w�a�ciwo�ci, warto�ci� jest warto�� danej w�a�ciwo�ci zaczytana z pliku.
    */
    map<string, string> configDictionary;

    enum FileStatus
    {
        FILE_OK = 0,
        FILE_ER = 1
    };

    /** @brief A brief description of myProcedure().
     *
     * A more extensive description of myProcedure().
     * @param aParameter A brief description of aParameter.
     * @return A brief description of what myProcedure() returns.
     */
    ConfigManager(const string& configFileName);

    /** @brief A brief description of myProcedure().
     *
     * A more extensive description of myProcedure().
     * @param aParameter A brief description of aParameter.
     * @return A brief description of what myProcedure() returns.
     */
    string Trim(const string& s);

    /** @brief A brief description of myProcedure().
     *
     * A more extensive description of myProcedure().
     * @param aParameter A brief description of aParameter.
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
