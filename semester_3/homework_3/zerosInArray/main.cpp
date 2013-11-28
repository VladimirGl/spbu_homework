#include <QCoreApplication>

#include "test_zeros.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	TestZerosArray test;
	QTest::qExec(&test);

	return a.exec();
}
