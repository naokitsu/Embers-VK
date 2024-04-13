//
// Created by Naokitsu on 3/24/2024.
//

#ifndef EMBERS_PLATFORM_DETECTION_H_
#define EMBERS_PLATFORM_DETECTION_H_


#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#define EMBERS_PLATFORM 'WINDOWS'
#elif defined(__linux__) || defined(__gnu_linux__)
#define EMBERS_PLATFORM 'LINUX'
#else
#define EMBERS_PLATFORM 'UNKNOWN'
#error "Platform not supported!"
#endif

#endif //EMBERS_PLATFORM_DETECTION_H_
