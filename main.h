/* main.h
 * Tanner Babcock
 * CIS 152 - Data Structures
 * Final Project: Video Store
 * November - December 2022
 * https://github.com/Babkock/VideoStore
*/
#ifndef MAIN_H
#define MAIN_H

#include <QSqlDatabase>

extern bool debugMode;
extern QSqlDatabase db;
extern double cashRegister;
extern double profits;

void dbConnect(const char *out);
bool dbReload(void);
void dbReset(void);

#endif // MAIN_H
