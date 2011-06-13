#include "toolstime.h"

//ToolsTime::ToolsTime()
//{
//    base = 0;
//}

//void ToolsTime::start()
//{
//    unsigned cyc;

//    // The following tests run the basic cycle counter to find
//    // the overhead associated with each cycle measurement.
//    // It is run multiple times simply because the first call
//    // to CPUID normally takes longer than subsequent calls.
//    // Typically after the second run the results are
//    // consistent. It is run three times just to make sure.
//    __asm__
//    (
//           "CPUID;"
//           "RDTSC;"
//           "movl %%eax, %1;"
//           "CPUID;"
//           "RDTSC;"
//           "subl %1, %%eax;"
//           "movl %%eax, %0;"

//           "CPUID;"
//           "RDTSC;"
//           "movl %%eax, %1;"
//           "CPUID;"
//           "RDTSC;"
//           "subl %1, %%eax;"
//           "movl %%eax, %0;"

//           "CPUID;"
//           "RDTSC;"
//           "movl %%eax, %1;"
//           "CPUID;"
//           "RDTSC;"
//           "subl %1, %%eax;"
//           "movl %%eax, %0;"
//                : "=r" (base)
//                : "r" (cyc)
//                :
//    );

//    __asm__
//    (
//        "CPUID;"
//        "RDTSC;"
//        "movl %%eax, %0"
//            : "=r" (cycles)
//            :
//            :
//    );
//}

//unsigned ToolsTime::end()
//{
//    __asm__
//    (
//        "CPUID;"
//        "RDTSC;"
//        "sub %1, %%eax;"
//        "mov %%eax, %0;"
//            : "=r" (cpucycles)
//            : "r" (cycles)
//            :
//    );

//    cpucycles -= base;
//}
