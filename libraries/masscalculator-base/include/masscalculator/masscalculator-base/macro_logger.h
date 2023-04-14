/**
 * @file macro_logger.h
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains logger macros that are used throughout the
 * codebase. The `macro_logger.h` file defines several macros that can be used
 * to log messages to standard error output. The macros provide different log
 * levels (ERROR, INFO, DEBUG), and can be used to print log messages with
 * different levels of detail. The file also defines a `LOG_LEVEL` constant that
 * can be used to control the level of logging that is output at runtime.
 * @version 0.2
 * @date 2023-04-04
 *
 * @copyright Copyright (c) 2023, MassCalculator, Org., All rights reserved.
 * @license This project is released under the  MIT license (MIT).
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_BASE_MACRO_LOGGER_H_
#define MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_BASE_MACRO_LOGGER_H_
#include <cstring> // for strrchr and fprintf
#include <ctime>   // for time, localtime and strftime

// Define inline function to get current time
static inline char* Timenow();

// Define logging constants and macros
#define _FILE strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__

#define NO_LOG 0x00
#define ERROR_LEVEL 0x01
#define INFO_LEVEL 0x02
#define DEBUG_LEVEL 0x03

#ifndef LOG_LEVEL
#if defined NDEBUG
#define LOG_LEVEL ERROR_LEVEL
#else
#define LOG_LEVEL DEBUG_LEVEL
#endif
#endif

#define PRINTFUNCTION(format, ...) fprintf(stderr, format, __VA_ARGS__)

#define LOG_FMT "%s | %-7s | %-15s | %s: %d | "
#define LOG_ARGS(LOG_TAG) Timenow(), LOG_TAG, _FILE, __FUNCTION__, __LINE__

#define NEWLINE "\n"

#define ERROR_TAG "ERROR"
#define INFO_TAG "INFO"
#define DEBUG_TAG "DEBUG"

#if LOG_LEVEL >= DEBUG_LEVEL
#define LOG_DEBUG(message, args...) \
  PRINTFUNCTION(LOG_FMT message NEWLINE, LOG_ARGS(DEBUG_TAG), ##args)
#else
#define LOG_DEBUG(message, args...)
#endif

#if LOG_LEVEL >= INFO_LEVEL
#define LOG_INFO(message, args...) \
  PRINTFUNCTION(LOG_FMT message NEWLINE, LOG_ARGS(INFO_TAG), ##args)
#else
#define LOG_INFO(message, args...)
#endif

#if LOG_LEVEL >= ERROR_LEVEL
#define LOG_ERROR(message, args...) \
  PRINTFUNCTION(LOG_FMT message NEWLINE, LOG_ARGS(ERROR_TAG), ##args)
#else
#define LOG_ERROR(message, args...)
#endif

#if LOG_LEVEL >= NO_LOG
#define LOG_IF_ERROR(condition, message, args...) \
  if (condition)                                  \
  PRINTFUNCTION(LOG_FMT message NEWLINE, LOG_ARGS(ERROR_TAG), ##args)
#else
#define LOG_IF_ERROR(condition, message, args...)
#endif

/**
 * @brief Implementation of inline function to get current time
 *
 * @return char* Current time formated in string
 */
static inline char* Timenow() {
  static char buffer[64];
  time_t rawtime;
  struct tm* timeinfo;

  time(&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer, 64, "%Y-%m-%d %H:%M:%S", timeinfo);

  return buffer;
}
#endif // MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_BASE_MACRO_LOGGER_H_
