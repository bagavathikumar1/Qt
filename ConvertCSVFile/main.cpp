#include <QtCore>
#include <QCoreApplication>
#include <QtCore/QCoreApplication>
#include <QStringList>
#include <QFile>
#include <QDebug>
#include <iostream>
using namespace std;

typedef struct
{
	unsigned int unTeta;
	unsigned int unYaw;
	unsigned int unGamma;
	unsigned int unHk0;
	unsigned int unHk1;
	unsigned int unVxproj;
	unsigned int unVzproj;
	unsigned int unV0;
	unsigned int unZ;
	unsigned int unD;
}OBCDATA, *LPOBCDATA;

QDataStream &operator<<( QDataStream &stream, const OBCDATA &data )
{
  stream << data.unTeta << data.unYaw << data.unGamma << data.unHk0 << data.unHk1 << data.unVxproj << data.unVzproj << data.unV0 << data.unZ << data.unD;

  return stream;
}

bool ReadOBCData()
{
	OBCDATA stOBCData;
	int nRecCount = 0;

	QFile file("New.csv");
	QFile datFile("OBCData.dat");
	QFile lineFile("line.txt");

	QTextStream in(&file);
	QDataStream out(&datFile);
	QTextStream out1(&lineFile);

	if (file.open(QIODevice::ReadOnly))
	{
		// line = in.readLine();
		//MyList = line.split(';');
		//int iHeaderCount = MyList.count();
		if( !lineFile.open( QIODevice::WriteOnly ) )
			return false;

		if( !datFile.open( QIODevice::WriteOnly ) )
			return false;

		while (!file.atEnd())
		{
			QStringList MyList;
			QString line = in.readLine();

			MyList = line.split(';');

			stOBCData.unTeta = MyList[1].toFloat() / 1;
			stOBCData.unYaw = MyList[2].toFloat() / 1;
			stOBCData.unGamma = MyList[3].toFloat() / 1;
			stOBCData.unHk0 = MyList[4].toFloat() / 0.25f;
			stOBCData.unHk1 = MyList[5].toFloat() / 0.075f;
			stOBCData.unVxproj = MyList[6].toFloat() / 0.03f;
			stOBCData.unVzproj = MyList[7].toFloat() / 0.03f;
			stOBCData.unV0 = MyList[8].toFloat() / 0.03;
			stOBCData.unZ = MyList[9].toFloat() / 3.0f;
			stOBCData.unD = MyList[10].toFloat() / 18.75f;

			out1 << QString::number(++nRecCount);
			out1 << "\n";

			out << stOBCData ;

			if(nRecCount == 11314)
			{
				for(int i = 0; i<86; i++)
				{
				line = in.readLine();
				MyList = line.split(';');

				stOBCData.unTeta = MyList[1].toFloat() / 1;
				stOBCData.unYaw = MyList[2].toFloat() / 1;
				stOBCData.unGamma = MyList[3].toFloat() / 1;
				stOBCData.unHk0 = MyList[4].toFloat() / 0.25f;
				stOBCData.unHk1 = MyList[5].toFloat() / 0.075f;
				stOBCData.unVxproj = MyList[6].toFloat() / 0.03f;
				stOBCData.unVzproj = MyList[7].toFloat() / 0.03f;
				stOBCData.unV0 = MyList[8].toFloat() / 0.03;
				stOBCData.unZ = MyList[9].toFloat() / 3.0f;
				stOBCData.unD = MyList[10].toFloat() / 18.75f;

				out1 << QString::number(++nRecCount);
				out1 << "\n";

				out << stOBCData ;

				char ss[200];
				sprintf(ss, "%d: ", nRecCount);
                strcat(ss, MyList[1]);
				strcat(ss, " ");
				strcat(ss, MyList[10]);
				strcat(ss, "\n");
				cout << ss;
				}
			}
		}
		datFile.close();
		lineFile.close();
	}
	return true;
}


int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    cout << "Process started\n";
    ReadOBCData();
    cout << "End of Process";
    return 0;//a.exec();
}
