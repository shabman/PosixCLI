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

#include "proc.h"
#include "file.h"

int
pcli_run_proc ( const char* bin )
{

  if ( *bin == '\0' || *bin == ' ' )
    {
      return 1;
    }

  char abs_path[ PATH_MAX ];
  memset ( abs_path, 0, sizeof ( abs_path ) );

  strcat ( abs_path, "/usr/local/bin/" );
  strcat ( abs_path, bin );

  if ( !pcli_file_exists ( abs_path ) )
    {
      return -1;
    }

  pid_t pid = fork ();
  if ( pid < 0 )
    {
      printf ( "%s\n", "Failed to spawn child process." );
      return -1;
    }

  if ( pid == 0 )
    {
      int status = execvp ( abs_path, NULL );
      if ( status == -1 )
        {
          printf ( "%s\n", "Child process did not terminate normally." );
        }
    }

  return 1;
}