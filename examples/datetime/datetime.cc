/* * Copyright (C) 2018 Leonardo Guilherme Lucena de Freitas
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <iostream>
#include "asap.h"

int main(int argc, char * argv[]) {
  /* Setting locale helps with local time format. It is not required. */
  setlocale(LC_ALL, "");

  /* If no arguments passed, its the same as asap::now() */
  asap::datetime d1;

  /* You can pass a string as a date or time. It tries its best to detect the format,
   * it defaults to asap::datetime(0). */
  asap::datetime d2("08/07/1987");

  /* You can also pass a format specifier. They're the same used by strftime */
  asap::datetime d3("08/07/1987 23:45:12", "%d/%m/%Y %H:%M:%S");

  /* A broken down time may be specified, in the order: year, month, day of month, hour, minute, second.
   * Be aware that months start at 0 for January (as most date/time APIs) */
  asap::datetime d4(1983, 6, 17);

  /* Default printing format is day-month-year hour:minute:second */
  std::cout << "d1          ->   " << d1 << std::endl;

  /* You can also pass a format to str(). Consult strftime manual for the available formats. */
  std::cout << "d2          ->   " << d2.str("%c") << std::endl;
  std::cout << "d3          ->   " << d3.str("date: %d/%m/%Y time: %H:%M") << std::endl;
  std::cout << "d4          ->   " << d4.str("%FT%T%z") << std::endl;
  std::cout << "now         ->   " << asap::now() << std::endl;
  std::cout << "tomorrow    ->   " << asap::tomorrow() << std::endl;
  std::cout << "yesterday   ->   " << asap::yesterday() << std::endl;

  return 0;
}
