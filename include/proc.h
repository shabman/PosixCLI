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

#ifndef __POSIX_CLI_PROC_H__
#define __POSIX_CLI_PROC_H__

#include "conf.h"

POSIX_BEGIN_DECLS

/**
 * @brief Runs a new (child) process in the process address space.
 * The PosixCLI program will become the parent process and can be accessed
 * via getppid(). Execution will fail depending on certain scenarios such as
 * an invalid binary file path
 * 
 * @return true if executed, otherwise false
 */
int pcli_run_proc ( const char* );

POSIX_END_DECLS

#endif /* __POSIX_CLI_PROC_H__ */