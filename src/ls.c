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

#include "ls.h"
#include "cd.h"

#include <dirent.h>

int
pcli_ls ( void )
{
  const char* cwd = pcli_current_path ();
  DIR* d;
  struct dirent* dir;

  d = opendir ( cwd );
  if ( d )
    {
      while ( ( dir = readdir ( d ) ) != NULL )
        printf ( "%s\n", dir->d_name );

      closedir ( d );
      return 1;
    }

  return 0;
}