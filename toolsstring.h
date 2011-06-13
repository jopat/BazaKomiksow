#ifndef TOOLSSTRING_H
#define TOOLSSTRING_H

#include <string>

/** @file toolsstring.h
 * @brief A brief description of toolsstring.h.
 *
 * A more extensive description of toolsstring.h.
 */

/** @brief Class contains string manipulation methods.
 *
 * Class ToolsString contains std string manipulation methods, including:
 *      - trim:
 */
class ToolsString
{
public:
    /** \brief A brief description of myProcedure().
     *
     * A more extensive description of myProcedure().
     * \param aParameter A brief description of aParameter.
     * \return A brief description of what myProcedure() returns.
     */
    static std::string trim (const std::string &str);

    /** \brief A brief description of myProcedure().
     *
     * A more extensive description of myProcedure().
     * \param aParameter A brief description of aParameter.
     * \return A brief description of what myProcedure() returns.
     */
    static std::string trimall (const std::string &str);
};

#endif // TOOLSSTRING_H
