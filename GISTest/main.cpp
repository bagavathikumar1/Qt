/*#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
*/


// Qt Includes
#include <QApplication>

// QGIS Includes
#include <qgsapplication.h>
#include <qgsproviderregistry.h>
#include <qgssinglesymbolrendererv2.h>
#include <qgsmaplayerregistry.h>
#include <qgsvectorlayer.h>
#include <qgsmapcanvas.h>

int main(int argc, char ** argv)
{

    // Start the Application
    QgsApplication app(argc, argv, true);

    app.setPrefixPath("D:\\OSGeo4W\\apps\\qgis\\");

    QString myPluginsDir        = "D:\\OSGeo4W\\apps\\qgis\\plugins";
    QString myLayerPath1         = "<path to shapefile 1>";
    QString myLayerBaseName1     = "Layer1";
    QString myLayerPath2         = "<path to shapefile 2>";
    QString myLayerBaseName2     = "Layer2";
    QString myProviderName      = "ogr";

    // Instantiate Provider Registry
    QgsProviderRegistry::instance(myPluginsDir);
    // create maplayer instances
    QgsVectorLayer * mypLayer1 = new QgsVectorLayer(myLayerPath1, myLayerBaseName1, myProviderName);
    QgsVectorLayer * mypLayer2 = new QgsVectorLayer(myLayerPath2, myLayerBaseName2, myProviderName);
    QgsSingleSymbolRendererV2 *mypRenderer1 = new QgsSingleSymbolRendererV2(QgsSymbolV2::defaultSymbol(mypLayer1->geometryType()));
    QgsSingleSymbolRendererV2 *mypRenderer2 = new QgsSingleSymbolRendererV2(QgsSymbolV2::defaultSymbol(mypLayer2->geometryType()));
    QList <QgsMapCanvasLayer> myLayerSet;
    mypLayer1->setRendererV2(mypRenderer1);
    mypLayer2->setRendererV2(mypRenderer2);

    // Add Vector Layers to the Layer Registry
    QgsMapLayerRegistry::instance()->addMapLayer(mypLayer1, true);
    QgsMapLayerRegistry::instance()->addMapLayer(mypLayer2, true);
    // Add Layers to the Layer Set
    myLayerSet.append(QgsMapCanvasLayer(mypLayer1, true));
    myLayerSet.append(QgsMapCanvasLayer(mypLayer2, true));

    // Create the Map Canvas
    QgsMapCanvas * mypMapCanvas = new QgsMapCanvas(0, 0);
    mypMapCanvas->setExtent(QgsRectangle(-63.50, -28.10, -58.33, -24.00));  // Chaco
    mypMapCanvas->setWheelAction(QgsMapCanvas::WheelAction(2) , 1.2);
    mypMapCanvas->enableAntiAliasing(true);
    mypMapCanvas->setCanvasColor(QColor(255, 255, 255));
    mypMapCanvas->freeze(false);
    // Set the Map Canvas Layer Set
    mypMapCanvas->setLayerSet(myLayerSet);
    mypMapCanvas->setVisible(true);
    mypMapCanvas->setWindowTitle("GIS DSH");
    mypMapCanvas->refresh();

    // Start the Application Event Loop
    int retval = app.exec();

    app.exitQgis();

    return retval;
}
