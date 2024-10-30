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

#include "cd.h"
#include "env.h"
#include "file.h"
#include "strutil.h"

#include <ctype.h>

static char _path_buf[ PATH_MAX ];
static char _cur_path[ PATH_MAX ];

static void
__set_buffer ( const char* source, char* buffer )
{
  memset ( buffer, 0, sizeof ( &buffer ) );
  strcpy ( buffer, source );
}

static int
__cd_dir_matcher ( const char* source, int max_period )
{
  const char* copy = source;
  unsigned int matches = 0;

  copy += 2;
  if ( isalnum ( *copy ) )
    return 0;
  copy++;

  do
    {
      if ( isalnum ( *copy ) )
        return 0;
      if ( *copy == '.' )
        matches++;
      copy++;
    }
  while ( *copy != '\0' );

  copy++;

  while ( *copy != '\0' )
    {
      if ( *copy != '\n' || *copy != ' ' || *copy == '\t' )
        return 0;
      copy++;
    }

  return matches == max_period;
}

static int
__is_current_dir ( const char* source )
{
  return __cd_dir_matcher ( source, 1 );
}

static int
__is_escape_dir ( const char* source )
{
  return __cd_dir_matcher ( source, 2 );
}

void
pcli_init_cd ( void )
{
  memset ( _path_buf, 0, sizeof ( _path_buf ) );

  const char* home_env = pcli_getenv ( "HOME" );
  __set_buffer ( home_env, _cur_path );
}

char*
pcli_gcwd ( void )
{
  memset ( _path_buf, 0, sizeof ( _path_buf ) );
  getcwd ( _path_buf, sizeof ( _path_buf ) );
  return _path_buf;
}

const char*
pcli_current_path ( void )
{
  return ( const char* )_cur_path;
}

int
pcli_cd ( const char* path )
{
  /* Check for bad arguments */
  if ( strlen ( path ) == 3 && *( path + 3 ) != ' ' )
    return PCD_NOTADIR;

  /* No arguments */
  if ( streq ( path, "cd" ) )
    {
      pcli_init_cd ();
      printf ( "%s:\n", _cur_path );
      return PCD_EXECOK;
    }
  else if ( __is_current_dir ( path ) )
    {
      printf ( "%s:\n", pcli_current_path () );
      return PCD_EXECOK;
    }
  else if ( __is_escape_dir ( path ) )
    {
      size_t _len = sizeof ( char* ) * ( strlen ( pcli_current_path () ) );
      char _tmp[ _len ];

      __set_buffer ( pcli_get_pwd ( _tmp, _len, pcli_current_path () ), _cur_path );

      printf ( "%s:\n", _cur_path );
      return PCD_EXECOK;
    }
  else
    {
      char* tmp_path = strdup ( path );
      char* abs_path = strremove ( tmp_path, "cd" );

      if ( !pcli_dir_exists ( strtrim ( abs_path ) ) )
        {
          free ( tmp_path );
          return PCD_FILENO;
        }
      else
        {
          __set_buffer ( strtrim ( abs_path ), _cur_path );
          printf ( "%s:\n", _cur_path );
        }

      free ( tmp_path );
    }

  return PCD_EXECOK;
}