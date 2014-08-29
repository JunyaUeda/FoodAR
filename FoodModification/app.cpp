#include "app.h"

App::App()
{
	QString filePath = FILEPATH;
  propertyController = new PropertyController(filePath);
  extractParamManager = propertyController->getExtractParamManager();
  calibrationController = new CalibrationController(extractParamManager);
  mainController = new MainController(extractParamManager);
}

int App::start(int argc, char *argv[]) {

	QApplication app(argc, argv);

  CalibrateDialog* calibrateDialog = new CalibrateDialog();
  calibrateDialog->calibrationController = this->calibrationController;
  calibrateDialog->show();

  MainWindow* mainWindow = new MainWindow();
  mainWindow->mainController = this->mainController;
  mainWindow->show();
  

   return app.exec();
}
