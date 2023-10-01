#ifndef EMOTIONLIB_COMMON_H_
#define EMOTIONLIB_COMMON_H_

#if defined(_MSC_VER) || defined(_WIN32)
# define LIB_EXPORT __declspec(dllexport)
# define LIB_HIDDEN
#else
# define LIB_EXPORT __attribute__((visibility("default")))
# define LIB_HIDDEN __attribute__((visibility("hidden")))
#endif

#endif // EMOTIONLIB_COMMON_H_
