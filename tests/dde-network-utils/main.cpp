#include <gtest/gtest.h>

#include <QCoreApplication>
#include <QDebug>

#define private public

int main(int argc, char *argv[])
{
    qputenv("QT_QPA_PLATFORM", "offscreen");
    QCoreApplication app(argc,argv);
    qDebug() << "start dde-network-utils test cases ..............";
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    qDebug() << "end dde-network-utils test cases ..............";
    return ret;
}
