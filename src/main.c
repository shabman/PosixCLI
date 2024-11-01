#include "cd.h"
#include "parse.h"

#include <signal.h>

int
main ( void )
{
  signal ( SIGINT, SIG_IGN );
  pcli_init_cd ();

  printf ( "\n%s\n%s\n\n", "Welcome to the PosixCLI!", "Copyright (c) 2024 Mustafa Malik (mm2440@kent.ac.uk). Licensed under GNU GPLv3" );
  printf ( "%s%s\n", pcli_current_path (), ":" );

  parse_cmd ();
}