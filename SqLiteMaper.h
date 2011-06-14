#ifndef SQLITEMAPER_H
#define SQLITEMAPER_H

#include <QSqlDatabase>
#include <QString>
#include <string>
#include <vector>
using namespace std;

/** @file sqlitemaper.h
 * @brief A brief description of filename.ext.
 *
 * A more extensive description of filename.ext.
 */

/** @brief A brief description of MyClass.
 *
 * A more extensive description of MyClass.
 */
class SqLiteMaper
{
public:

    /** @brief A brief description of myVariable.
     *
     * A more extensive description of myVariable.
     */
    enum FileStatus
    {
        CONNECTION_ERRROR = 0,
        CONNECTION_OK,
        CONNECTION_CLOSED
    };

    /** @brief A brief description of myVariable.
     *
     * A more extensive description of myVariable.
     */
    string          lastError;

    /** @brief A brief description of myProcedure().
     *
     * A more extensive description of myProcedure().
     * @param aParameter A brief description of aParameter.
     * @return A brief description of what myProcedure() returns.
     */
    SqLiteMaper(const string &dbName);

    /** @brief A brief description of myProcedure().
     *
     * A more extensive description of myProcedure().
     * @param aParameter A brief description of aParameter.
     * @return A brief description of what myProcedure() returns.
     */
    ~SqLiteMaper();

    /** @brief A brief description of myProcedure().
     *
     * A more extensive description of myProcedure().
     * @param aParameter A brief description of aParameter.
     * @return A brief description of what myProcedure() returns.
     */
    int Connect();

    /** @brief A brief description of myProcedure().
     *
     * A more extensive description of myProcedure().
     * @param aParameter A brief description of aParameter.
     * @return A brief description of what myProcedure() returns.
     */
    int Disconnect();

    /** @brief A brief description of myProcedure().
     *
     * A more extensive description of myProcedure().
     * @param aParameter A brief description of aParameter.
     * @return A brief description of what myProcedure() returns.
     */
    int CreateDatabase(const string &fileName);

    /** @brief A brief description of myProcedure().
     *
     * A more extensive description of myProcedure().
     * @param aParameter A brief description of aParameter.
     * @return A brief description of what myProcedure() returns.
     */
    int ConnectionStatus();

    /** @brief A brief description of myProcedure().
     *
     * A more extensive description of myProcedure().
     * @param aParameter A brief description of aParameter.
     * @return A brief description of what myProcedure() returns.
     */
    bool CheckDatabase();

private:

    /** @brief A brief description of myVariable.
     *
     * A more extensive description of myVariable.
     */
    QSqlDatabase    *db;

    /** @brief A brief description of myVariable.
     *
     * A more extensive description of myVariable.
     */
    string          dbName;

    /** @brief A brief description of myVariable.
     *
     * A more extensive description of myVariable.
     */
    vector<string> sqlList;

    /** @brief A brief description of myProcedure().
     *
     * A more extensive description of myProcedure().
     * @param aParameter A brief description of aParameter.
     * @return A brief description of what myProcedure() returns.
     */
    void ReadSqlFromFile(const string &fileName);
};

#endif // SQLITEMAPER_H
