/**************************************************************************
 * Copyright (c) 2015, Guillermo A. Perez, Universite Libre de Bruxelles
 * 
 * This file is part of the (Swiss) AbsSynthe tool.
 * 
 * AbsSynthe is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * AbsSynthe is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with AbsSynthe.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * 
 * Guillermo A. Perez
 * Universite Libre de Bruxelles
 * gperezme@ulb.ac.be
 *************************************************************************/

#include <iostream>

#include "logging.h"

using namespace std;

static bool logging_debug_level = false;
static bool logging_log_level = false;
static bool logging_warning_level = false;

void parseLogLevelString(const char* verb_string) {
    const char* cur;
    cur = verb_string;
    while (*cur != '\0') {
        if (*cur == 'D' || *cur == 'd')
            logging_debug_level = true;
        if (*cur == 'L' || *cur == 'l')
            logging_log_level = true;
        if (*cur == 'W' || *cur == 'w')
            logging_warning_level = true;
        cur++;
    }
}

void dbgMsg(const char* message) { dbgMsg(string(message)); }
void wrnMsg(const char* message) { wrnMsg(string(message)); }
void logMsg(const char* message) { logMsg(string(message)); }
void errMsg(const char* message) { errMsg(string(message)); }

void dbgMsg(string message) {
    if (logging_debug_level)
        cout << "[DBG] " << message << endl;
}

void wrnMsg(string message) {
    if (logging_warning_level)
        cout << "[WRN] " << message << endl;
}

void logMsg(string message) {
    if (logging_log_level)
        cout << "[LOG] " << message << endl;
}

void errMsg(string message) {
    cerr << "[ERR] " << message << endl;
}
