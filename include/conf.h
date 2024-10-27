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

#ifndef __POSIX_CLI_CONF_H__
#define __POSIX_CLI_CONF_H__

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// clang-format off
#if defined( __unix__ ) || defined( __unix ) || defined( unix )
#   include <unistd.h>
#   define POSIX_UNIX_API
#elif defined( __APPLE__ )
#   include <mach-o/dyld.h>
#   include <unistd.h>
#   include <sys/syslimits.h>
#   define POSIX_APPLE_API
#endif

#if __cplusplus
#   define POSIX_BEGIN_DECLS extern "C" {
#   define POSIX_END_DECLS }
#else
#   define POSIX_BEGIN_DECLS
#   define POSIX_END_DECLS
#endif
// clang-format on

#endif /* __POSIX_CLI_CONF_H__ */