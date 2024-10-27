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

#ifndef __POSIX_CLI_STRUTIL_H__
#define __POSIX_CLI_STRUTIL_H__

#define streq( s1, s2 ) strcmp ( s1, s2 ) == 0

#include "conf.h"

POSIX_BEGIN_DECLS

/* Many thanks to chqrlie */
/* https://stackoverflow.com/questions/47116974/remove-a-substring-from-a-string-in-c */
char*
strremove ( char*, const char* );

/* Many thanks to Dave Gray and Adam Rosenfield */
/* https://stackoverflow.com/questions/122616/how-do-i-trim-leading-trailing-whitespace-in-a-standard-way */
char* strtrim ( char* );

POSIX_END_DECLS

#endif /* __POSIX_CLI_STRUTIL_H__ */