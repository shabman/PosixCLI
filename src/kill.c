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

#include "kill.h"
#include "ps.h"
#include "strutil.h"

#include <errno.h>
#include <signal.h>

int
pcli_kill_pid ( const char* cmd )
{

  if ( streq ( cmd, "kill" ) )
    {
      return PKL_BAD;
    }

  char* cmd_dup = strdup ( cmd );
  int pid = atoi ( strtrim ( strremove ( cmd_dup, "kill" ) ) );

  free ( cmd_dup );

  if ( pid == 0 || pid == -1 || pid == pcli_ps () )
    {
      printf ( "%s\n", "WARNING: Given PID is dangerous! Aborting..." );
      return PKL_DNGER;
    }

  int status = kill ( pid, SIGKILL );
  if ( status == -1 )
    {
      switch ( errno )
        {
        case EINVAL:
          return PKL_BAD;
        case EPERM:
          return PKL_PERM;
        case ESRCH:
          return PKL_NOFND;
        default:
          return PKL_BAD;
        }
    }

  printf ( "%s: %d\n", "killed (PID)", pid );

  return status;
}