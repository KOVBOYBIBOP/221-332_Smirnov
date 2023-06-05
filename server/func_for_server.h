#ifndef FUNC_FOR_SERVER_H
#define FUNC_FOR_SERVER_H

#include <QTcpSocket>
#include <QByteArray>
#include <QString>
#include <QList>
#include <QStringList>
#include <QDebug>

QByteArray parsing(QString str,QTcpSocket &a );
QString coder( QString &message, int key);
QString decoder(QString &message, int key);



////////////////////////////////////////////////


#endif // FUNC_FOR_SERVER_H
