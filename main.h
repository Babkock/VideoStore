#ifndef MAIN_H
#define MAIN_H

#include <QSqlDatabase>

extern QSqlDatabase db;
extern double cashRegister;
extern double profits;

void dbConnect(const char *out);
bool dbReload(void);
void dbReset(void);

#endif // MAIN_H