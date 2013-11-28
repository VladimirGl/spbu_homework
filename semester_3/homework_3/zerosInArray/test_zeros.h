#ifndef TEST_ZEROS_H
#define TEST_ZEROS_H

#include <QObject>
#include <QtTest/QTest>

#include "zerosInArray.h"

class TestZerosArray : public QObject {
	Q_OBJECT

private slots:
	void initTestCase()
	{
		mSize = 50;
		mArray = new int[mSize];

		for (int i = 0; i < mSize; i++) {
			mArray[i] = 0;
		}
	}

	void testZeros()
	{
		for (int i = 0; i < mSize; i++) {
			mArray[i] = 2;
		}

		QVERIFY(countZeros(mArray, mSize) == 0);
	}

	void testZerosTwo()
	{
		for (int i = 20; i < mSize; i++) {
			mArray[i] = 0;
		}

		QVERIFY(countZeros(mArray, mSize) == 30);
	}


	void cleanupTestCase()
	{
		delete[] mArray;
	}

private:
	int *mArray;
	int mSize;
};

#endif // TEST_ZEROS_H
