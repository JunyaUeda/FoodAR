#include "app.h"

App::App()
{
	
}

int App::start(int argc, char *argv[])
{

	QApplication app(argc, argv);


  MainWindow* mainWindow = new MainWindow();
  mainWindow->show();
  
   return app.exec();

}
