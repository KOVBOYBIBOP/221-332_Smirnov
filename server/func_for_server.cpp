#include "func_for_server.h"

/**
 * @brief Функция разбора запроса от клиента.
 * @param str Строка запроса от клиента.
 * @param a Сокет клиента.
 * @return Результат выполнения запроса в виде массива байт.
 */

QString coder( QString &message, int key) {
    for ( int i = 0; i < message.size(); i++ ) {
        if ( message[i].unicode() >= 65 and message[i].unicode() <= 90 ) {
            QChar myA = 'A';
            message[i] = QChar(myA.toLatin1() + ( message[i].unicode() - 'A' + key ) % 26);
        } else {
            if ( message[i].unicode() >= 97 and message[i].unicode() <= 122 ) {
                QChar mya = 'a';
                message[i] = QChar(mya.toLatin1() + ( message[i].unicode() - 'a' + key ) % 26);
            }
        }
    }
    return message;
}
QString decoder(QString &message, int key) {
    for (int i = 0; i < message.size(); i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            QChar myA = 'A';
            message[i] = QChar(myA.toLatin1() + (message[i].unicode() - 'A' - key + 26) % 26);
        } else {
            if (message[i] >= 'a' && message[i] <= 'z') {
                QChar mya = 'a';
                message[i] = QChar(mya.toLatin1() + (message[i].unicode() - 'a' - key + 26) % 26);
            }
        }
    }
    return message;
}
QByteArray parsing(QString str, QTcpSocket &a)
{
    int key;
    key = str.mid(0, 3).toInt();
    QString message;
    message = str.remove(0, 3);
    QString our_message = decoder(message, key);
    QString send_message = coder(our_message, key);
    return send_message.toUtf8();

}
