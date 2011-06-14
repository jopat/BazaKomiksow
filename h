[1mdiff --git a/toolsstring.cpp b/toolsstring.cpp[m
[1mdeleted file mode 100644[m
[1mindex 849a766..0000000[m
[1m--- a/toolsstring.cpp[m
[1m+++ /dev/null[m
[36m@@ -1,30 +0,0 @@[m
[31m-#include "toolsstring.h"[m
[31m-[m
[31m-/** @file toolsstring.cpp[m
[31m- * @brief A brief description of toolsstring.cpp.[m
[31m- *[m
[31m- * A more extensive description of toolsstring.cpp.[m
[31m- */[m
[31m-[m
[31m-std::string ToolsString::trim (const std::string &str)[m
[31m-{[m
[31m-    std::string result;[m
[31m-    for (unsigned int i = 0; i < str.length(); i++)[m
[31m-    {[m
[31m-        if (str[i] == ' ' && str[i-1] == ' ')[m
[31m-            continue;[m
[31m-        else result += str[i];[m
[31m-    }[m
[31m-    return result;[m
[31m-}[m
[31m-[m
[31m-std::string ToolsString::trimall (const std::string &str)[m
[31m-{[m
[31m-    std::string result;[m
[31m-    for (unsigned int i = 0; i < str.length(); i++)[m
[31m-    {[m
[31m-        if (str[i] != ' ')[m
[31m-            result += str[i];[m
[31m-    }[m
[31m-    return result;[m
[31m-}[m
[1mdiff --git a/toolsstring.h b/toolsstring.h[m
[1mdeleted file mode 100644[m
[1mindex 8df3a08..0000000[m
[1m--- a/toolsstring.h[m
[1m+++ /dev/null[m
[36m@@ -1,37 +0,0 @@[m
[31m-#ifndef TOOLSSTRING_H[m
[31m-#define TOOLSSTRING_H[m
[31m-[m
[31m-#include <string>[m
[31m-[m
[31m-/** @file toolsstring.h[m
[31m- * @brief A brief description of toolsstring.h.[m
[31m- *[m
[31m- * A more extensive description of toolsstring.h.[m
[31m- */[m
[31m-[m
[31m-/** @brief Class contains string manipulation methods.[m
[31m- *[m
[31m- * Class ToolsString contains std string manipulation methods, including:[m
[31m- *      - trim:[m
[31m- */[m
[31m-class ToolsString[m
[31m-{[m
[31m-public:[m
[31m-    /** \brief A brief description of myProcedure().[m
[31m-     *[m
[31m-     * A more extensive description of myProcedure().[m
[31m-     * \param aParameter A brief description of aParameter.[m
[31m-     * \return A brief description of what myProcedure() returns.[m
[31m-     */[m
[31m-    static std::string trim (const std::string &str);[m
[31m-[m
[31m-    /** \brief A brief description of myProcedure().[m
[31m-     *[m
[31m-     * A more extensive description of myProcedure().[m
[31m-     * \param aParameter A brief description of aParameter.[m
[31m-     * \return A brief description of what myProcedure() returns.[m
[31m-     */[m
[31m-    static std::string trimall (const std::string &str);[m
[31m-};[m
[31m-[m
[31m-#endif // TOOLSSTRING_H[m
