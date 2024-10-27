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

#include "parse.h"
#include "cd.h"
#include "kill.h"
#include "ls.h"
#include "proc.h"
#include "ps.h"
#include "strutil.h"

static char buf[ 1024 ];

void
parse_cmd ( void )
{
  /* I forgot scanf only reads stdin until the first whitespace :/ */
  fgets ( buf, sizeof ( buf ), stdin );
  buf[ strcspn ( buf, "\n" ) ] = '\0';

  char* cmd_copy = strdup ( buf );

  if ( streq ( buf, "exit" ) )
    {
      free ( cmd_copy );
      printf ( "%s\n", "Terminating session..." );
      return;
    }

  /* Command Handling */
  else if ( strstr ( cmd_copy, "cd" ) )
    {
      int status = pcli_cd ( buf );
      if ( status == PCD_FILENO )
        printf ( "%s\n", "Given path does not exist." );

      if ( status == PCD_NOTADIR )
        printf ( "%s\n", "Path is not a directory." );
    }

  else if ( strstr ( cmd_copy, "ps" ) )
    printf ( "Current process (PID): %d\n", pcli_ps () );

  else if ( strstr ( cmd_copy, "kill" ) )
    {
      int status = pcli_kill_pid ( cmd_copy );
      if ( status == PKL_BAD )
        printf ( "%s\n", "Bad arguments." );

      if ( status == PKL_DNGER )
        printf ( "%s\n", "Dangerous arguments given." );

      if ( status == PKL_NOFND )
        printf ( "%s\n", "Given PID is not found." );

      if ( status == PKL_PERM )
        printf ( "%s\n", "Permission denied." );
    }

  else if ( strstr ( cmd_copy, "ls" ) )
    {
      if ( !pcli_ls () )
        printf ( "%s\n", "Failed to list contents of current directory." );
    }

  /* Could not find an alternative to clrscr() (THIS METHOD IS FROM MS-DOS DAYS) */
  else if ( strstr ( cmd_copy, "clear" ) )
    {
      printf ( "\033[H\033[J" );
    }

  /* Not built-in? Look for an executable */
  else
    {
      if ( !pcli_run_proc ( cmd_copy ) )
        printf ( "%s\n", "Invalid command" );
    }

  free ( cmd_copy );
  parse_cmd ();
}
