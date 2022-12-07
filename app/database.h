/* database.h
 * Tanner Babcock
 * CIS 152 - Data Structures
 * Final Project: Video Store
 * November - December 2022
 * https://github.com/Babkock/VideoStore
*/
/**********************************
 * OS: Void GNU/Linux
 * IDE: QtCreator
 * Copyright : This is my own original work based
 * on specifications issued by our instructor.
 * Academic Honesty: I attest that this is my original
 * work. I have not used unauthorized source code,
 * either modified or unmodified. I have not given
 * other fellow student(s) access to my program.
***********************************/
#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>

extern bool debugMode;
extern QSqlDatabase db;
extern double cashRegister;
extern double profits;

void dbConnect(const char *out);
bool dbReload(void);
void dbRepopulate(void);
void dbReset(void);

#endif // DATABASE_H
