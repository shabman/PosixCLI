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
  if ( *bin == ' ' || *bin == '\0' )
    return 1;

  pid_t pid = fork ();
  if ( pid < 0 )
    return 0;

  if ( pid == 0 )
    {
      char* const argv[] = { ( char* )bin, NULL };
      execvp ( bin, argv );

      return 0;
    }
  else
    {
      int status;
      waitpid ( pid, &status, WUNTRACED );
    }

  return 1;
}
