/*
 * This file is part of the PosixCLI distribution (https://github.com/shabman)
 * Copyright (c) 2024 Mustafa Malik (mm2440@kent.ac.uk).
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "strutil.h"
#include <ctype.h>

char*
strremove ( char* str, const char* sub )
{
  char *p, *q, *r;
  if ( *sub && ( q = r = strstr ( str, sub ) ) != NULL )
    {
      size_t len = strlen ( sub );
      while ( ( r = strstr ( p = r + len, sub ) ) != NULL )
        {
          while ( p < r )
            *q++ = *p++;
        }
      while ( ( *q++ = *p++ ) != '\0' )
        continue;
    }
  return str;
}

char*
strtrim ( char* str )
{
  char* end;

  while ( isspace ( ( unsigned char )*str ) )
    str++;

  if ( *str == 0 )
    return str;

  end = str + strlen ( str ) - 1;
  while ( end > str && isspace ( ( unsigned char )*end ) )
    end--;

  end[ 1 ] = '\0';

  return str;
}