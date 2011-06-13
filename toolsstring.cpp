#include "toolsstring.h"

/** @file toolsstring.cpp
 * @brief A brief description of toolsstring.cpp.
 *
 * A more extensive description of toolsstring.cpp.
 */

std::string ToolsString::trim (const std::string &str)
{
    std::string result;
    for (unsigned int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ' && str[i-1] == ' ')
            continue;
        else result += str[i];
    }
    return result;
}

std::string ToolsString::trimall (const std::string &str)
{
    std::string result;
    for (unsigned int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
            result += str[i];
    }
    return result;
}
