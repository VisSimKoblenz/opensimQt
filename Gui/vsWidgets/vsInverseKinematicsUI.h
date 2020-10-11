#ifndef VSINVERSEKINEMATICSUI_H
#define VSINVERSEKINEMATICSUI_H

#include <QWidget>

#include <vsModeling/vsIkCoordinateModel.h>

#include "OpenSim.h"
#include "OpenSim/Common/MarkerData.h"
#include "vsModeling/vsMarkerTasksModel.h"

namespace Ui {
class vsInverseKinematicsUI;
}

class vsInverseKinematicsUI : public QWidget
{
    Q_OBJECT

public:
    explicit vsInverseKinematicsUI(QWidget *parent = nullptr);
    ~vsInverseKinematicsUI();

    OpenSim::Model *currentModel() const;
    void setCurrentModel(OpenSim::Model *currentModel);

private slots:
    void on_markerFileTB_clicked();

    void on_markerDateFileTE_textChanged();

    void on_trialRangefrom_valueChanged(double arg1);

    void on_trialRangeTo_valueChanged(double arg1);

    void on_coordinateDataCB_toggled(bool checked);

    void on_coordinateFileTE_textChanged();

    void on_coordianteFileTB_clicked();

    void on_motionFileTB_clicked();

    void on_motionFileName_textChanged();

    void on_runBTN_clicked();

    void on_enableAllCB_toggled(bool checked);

    void on_disableAllCB_toggled(bool checked);

    void on_weightFSP_valueChanged(double arg1);

private:
    Ui::vsInverseKinematicsUI *ui;

    OpenSim::Model *m_currentModel;

    OpenSim::InverseKinematicsTool *m_ikTool;

    vsMarkerTasksModel *m_markersIKTasksModel;
    vsIKCoordinateModel *m_coordinateIKTasksModel;

    //IK variables
    std::string m_markersFileName;
    double m_ikStartTime;
    double m_ikEndTime;
    std::string m_coordinatesFileName;
    std::string m_outputFile;

};

#endif // VSINVERSEKINEMATICSUI_H
