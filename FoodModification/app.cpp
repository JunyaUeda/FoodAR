#include "app.h"

App::App() {

	QString filePath = FILEPATH;
  propertyController = new PropertyController(filePath);
  extractParamManager = propertyController->getExtractParamManager();
  calibrationController = new CalibrationController(extractParamManager);
  mainController = new MainController(extractParamManager);
  mainController->calibrationController = calibrationController;
}

int App::start(int argc, char *argv[]) {

	QApplication app(argc, argv);

  
  MainWindow* mainWindow = new MainWindow();
  mainWindow->mainController = this->mainController;
  mainWindow->calibrationController = this->calibrationController;
  mainWindow->show();
  
   return app.exec();

}
