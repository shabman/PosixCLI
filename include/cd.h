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

#ifndef __POSIX_CLI_CD_H__
#define __POSIX_CLI_CD_H__

#include "conf.h"
#include <stddef.h>

#define PCD_EXECOK 0x1
#define PCD_FILENO 0x2
#define PCD_NOTADIR 0x4
#define PCD_NOPERMS 0x8

POSIX_BEGIN_DECLS

/**
 * @brief Initialises the cd command system
 *
 */
void pcli_init_cd ( void );

/**
 * @brief Get Current Working Directory (from where the executable is running)
 *
 * @return The (absolute) path of the current working directory
 */
char* pcli_gcwd ( void );

/**
 * @brief Get the current path that CD will use after initlisation
 *
 * @return The path CD is currently pointing at
 */
const char* pcli_current_path ( void );

/**
 * @brief Change Directory (from where the executable is running)
 * This method may fail if the following criteria is not met:
 *  - Path is not a folder
 *  - Incorrect Permissions
 *  - Invalid arguments or invalid path
 *
 * @param The path to change to (Directory only)
 * @return True if changed correctly, otherwise false
 */
int pcli_cd ( const char* );

POSIX_END_DECLS

#endif /* __POSIX_CLI_CD_H__ */