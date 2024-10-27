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

#ifndef __POSIX__CLI_KILL_H__
#define __POSIX__CLI_KILL_H__

#include "conf.h"

#define PKL_BAD 0x20
#define PKL_PERM 0x40
#define PKL_NOFND 0x80
#define PKL_DNGER 0x100

POSIX_BEGIN_DECLS

/**
 * @brief Kills a given process ID. Note if the PID is 0, -1 or the same
 * as the CLI, it will be ignored as a precaution. Using PID 0, -1 will
 * send a signal to all processes which can be unsafe if not used correctly.
 * This does not include system processes so it does not risk anything serious
 *
 * @return true if terminated, otherwise false
 */
int pcli_kill_pid ( const char* );

POSIX_END_DECLS

#endif /* __POSIX__CLI_KILL_H__ */