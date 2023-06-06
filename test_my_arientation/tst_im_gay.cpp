#include "func_for_server.h"

#include <QtTest>

// add necessary includes here

class Im_gay : public QObject
{
    Q_OBJECT

public:
    Im_gay();
    ~Im_gay();

private slots:
    void test_case1();

};

Im_gay::Im_gay()
{

}

Im_gay::~Im_gay()
{

}

void Im_gay::test_case1()
{
    QString params = "ABC";
    QCOMPARE(coder(params,2),"CDE");
}

void Im_gay::test_case2()
{
    QString params = "CDE";
    QCOMPARE(coder(params,2),"ABC");
}
QTEST_APPLESS_MAIN(Im_gay)

#include "tst_im_gay.moc"
