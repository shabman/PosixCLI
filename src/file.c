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

#include "file.h"
#include "strutil.h"
#include <dirent.h>
#include <errno.h>
#include <libgen.h>
#include <stdlib.h>

int
pcli_dir_exists ( const char* path )
{
  DIR* dir = opendir ( path );
  if ( dir )
    {
      closedir ( dir );
      return 1;
    }

  return 0;
}

int
pcli_file_exists ( const char* path )
{
  return access ( path, F_OK ) == 0;
}

char*
pcli_get_pwd ( char* arr, size_t len, const char* cwd )
{
  memset ( arr, 0, len );
  strcat ( arr, ".." );
  strcat ( arr, cwd );
  arr[ len ] = '\0';

  char* pwd = dirname ( arr );
  strremove ( pwd, ".." );

  memset ( arr, 0, len );
  strcpy ( arr, pwd );
  arr[ strlen ( pwd ) + 1 ] = '\0';

  return arr;
}