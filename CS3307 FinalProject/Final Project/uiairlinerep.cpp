#include "uiairlinerep.h"
#include "ui_uiairlinerep.h"
#include "flight.h"
#include "flightLoader.h"
#include "aircraft.h"
#include "aircraftloader.h"
#include "flightRequestLoader.h"
#include "uimainwindow.h"
#include <vector>
#include <sstream>
#include <qmessagebox.h>

using namespace std;

uiMainWindow * board;

uiairlinerep::uiairlinerep(string _accountName, QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::uiairlinerep),
        fl(new flightLoader()),
        al(new aircraftloader()),
        atl(new AircraftTypeLoader()),
        frl(new flightRequestLoader()),

        arriveVec(fl->getArrival()),
        departVec(fl->getDeparture()),
        aircrafts(al->getVector()),
        aircrafttypes(atl->getVector()),
        reqVec(frl->getFlights()),
        accountName(_accountName)

{
    board = new uiMainWindow(false,0);
    board->show();

    ui->setupUi(this);
    ui->reqInDate->setDate(QDate::currentDate());
    ui->reqOutDate->setDate(QDate::currentDate());
    ui->reqInGate->setTime((QTime::currentTime()));
    ui->reqInLand->setTime((QTime::currentTime()));
    ui->reqOutGate->setTime((QTime::currentTime()));
    ui->reqOutTakeOff->setTime((QTime::currentTime()));

    ui->reqInFlightID->setValidator(new QIntValidator(0,99999,this) );
    ui->reqOutFlightID->setValidator(new QIntValidator(0,99999,this) );

    this->setWindowFlags(Qt::Window | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
    refresh();

}
uiairlinerep::~uiairlinerep()
{
    delete ui;
}

void uiairlinerep::on_pushButton_9_clicked()
{
    board->close();
    board = new uiMainWindow(true,0);
    board->show();
    this->close();
}
void uiairlinerep::on_exceptInFlightID_currentIndexChanged(QString value )
{
    flight *foundFlight = fl->findByFlightID(value.toInt());
    ui->exceptInAircraftID->setText(QString::number(foundFlight->getAircraftID()));
    ui->exceptInSource->setText(QString::fromStdString(foundFlight->getSourceCode()));
    ui->exceptInDelay->setText(QString::number(foundFlight->getDelay()));

}

void uiairlinerep::on_exceptOutFlightID_currentIndexChanged(QString value)
{
    flight *foundFlight = fl->findByFlightID(value.toInt());
    ui->exceptOutAircraftID->setText(QString::number(foundFlight->getAircraftID()));
    ui->exceptOutDestination->setText(QString::fromStdString(foundFlight->getDestinationCode()));
    ui->exceptOutDelay->setText(QString::number(foundFlight->getDelay()));
}


void uiairlinerep::on_inCancel_clicked()
{
    for(unsigned int i = 0; i < arriveVec->size(); ++i){
        if ((ui->exceptInFlightID->currentText().toInt() == arriveVec->at(i).getFlightID()))
            arriveVec->erase(arriveVec->begin()+i);
    }

    fl->writeFile();
    refresh();

}
void uiairlinerep::on_outCancel_clicked()
{
    for(unsigned int i = 0; i < departVec->size(); ++i){
        if ((ui->exceptOutFlightID->currentText().toInt() == departVec->at(i).getFlightID()))
            departVec->erase(departVec->begin()+i);
    }

    fl->writeFile();
    refresh();
}


void uiairlinerep::refresh(){
    //aircrafttypes->erase(aircrafttypes->end());
    //atl->writeFile();

    //clear text fields
    ui->AircraftIdlineEdit->clear();
    ui->aircraftlist->clear();
    ui->AircraftStatuslineEdit->clear();
    ui->aircrafttypeid->clear();
    ui->deleteAircraftcomboBox->clear();
    ui->newAircraftID->clear();

    ui->exceptInFlightID->clear();
    ui->exceptOutFlightID->clear();
    for(unsigned int i = 0; i < arriveVec->size(); ++i){
        ui->exceptInFlightID->addItem(QString::number(arriveVec->at(i).getFlightID()));

    }
    for(unsigned int i = 0; i < departVec->size(); ++i){
        ui->exceptOutFlightID->addItem(QString::number(departVec->at(i).getFlightID()));
    }

    ui->aircraftlist->clear();
    ui->FlightRequestAircraft->clear();
    ui->FlightRequestAircraft_2->clear();
    ui->cbaircraftid->clear();
    ui->deleteAircraftcomboBox->clear();
    ui->aircrafttypeid->clear();

    for(unsigned int i = 0; i < aircrafts->size(); ++i){
        ui->FlightRequestAircraft->addItem(QString::number(aircrafts->at(i).getAircraftId()));
        ui->FlightRequestAircraft_2->addItem(QString::number(aircrafts->at(i).getAircraftId()));
        ui->cbaircraftid->addItem(QString::number(aircrafts->at(i).getAircraftId()));

        AircraftType *temp = atl->findByAircraftID(aircrafts->at(i).getType());

        ui->aircraftlist->addItem(QString::number(aircrafts->at(i).getAircraftId()) + " " +
                                  QString::fromStdString(temp->getManufacturer()) + " " +
                                  QString::fromStdString(temp->getModel()));
        ui->label_59->setText(QString::number(temp->getId()));
        ui->deleteAircraftcomboBox->addItem(QString::number(aircrafts->at(i).getAircraftId()));
    }

    for(unsigned int i = 0; i < aircrafttypes->size(); ++i){
        ui->aircrafttypeid->addItem(QString::number(aircrafttypes->at(i).getId()));
    }


}


void uiairlinerep::on_exceptInUpdate_clicked()
{
    flight *foundFlight = fl->findByFlightID(ui->exceptInFlightID->currentText().toInt());
    foundFlight->setAircraftID(ui->exceptInAircraftID->text().toInt());
    foundFlight->setSourceCode(ui->exceptInSource->text().toStdString());
    foundFlight->setDelay(ui->exceptInDelay->text().toInt());

    fl->writeFile();
    refresh();
}

void uiairlinerep::on_exceptOutUpdate_clicked()
{
    flight *foundFlight = fl->findByFlightID(ui->exceptOutFlightID->currentText().toInt());
    foundFlight->setAircraftID(ui->exceptOutAircraftID->text().toInt());
    foundFlight->setDestinationCode(ui->exceptOutDestination->text().toStdString());
    foundFlight->setDelay(ui->exceptOutDelay->text().toInt());

    fl->writeFile();
    refresh();
}

void uiairlinerep::on_editaircraftid_clicked()
{
    bool dup = 0;
    for(unsigned int i = 0; i < aircrafts->size(); i++){
        if(ui->newAircraftID->text().toInt() == aircrafts->at(i).getAircraftId()){
            dup = 1;
        }
    }

    //std::cout << "****************ID:"+ ui->cbaircraftid->currentText().toInt();
    if(dup != 1){
        if(ui->newAircraftID->text().toInt() != 0){
            aircraft *foundAircraft = al->findByAircraftID(ui->cbaircraftid->currentText().toInt());
            foundAircraft->setAircraftId(ui->newAircraftID->text().toInt());
            al->writeFile();
            refresh();
        }else{
            QMessageBox msgBox;
            msgBox.setText("Invalid ID for AircraftID");
            msgBox.exec();
        }
    }else{
        QMessageBox msgBox2;
        msgBox2.setText("Duplicate ID for AircraftID");
        msgBox2.exec();
    }
}

void uiairlinerep::on_deleteAircraft_clicked()
{
    aircrafts->erase(aircrafts->begin() + ui->deleteAircraftcomboBox->currentIndex());
    al->writeFile();
    refresh();
}

void uiairlinerep::on_addAircraft_clicked()
{
    if(ui->AircraftIdlineEdit->text() == "" || ui->AircraftStatuslineEdit->text() == ""){
        QMessageBox msgBox;
        msgBox.setText("a field was empty");
        msgBox.exec();
    }else{
        bool dup = 0; //check duplicate id
        for(unsigned int i = 0; i < aircrafts->size(); i++){
            if(ui->AircraftIdlineEdit->text().toInt() == aircrafts->at(i).getAircraftId()){
                dup = 1;
            }
        }
        if(dup == 0){
            if(ui->AircraftIdlineEdit->text().toInt() != 0){
                aircraft a = aircraft(ui->AircraftIdlineEdit->text().toInt(),ui->AircraftStatuslineEdit->text().toInt(), ui->aircrafttypeid->currentText().toInt());
                aircrafts->insert(aircrafts->end(), a);
                al->writeFile();
                refresh();
            }else{
                QMessageBox msgBox3;
                msgBox3.setText("Invalid ID for AircraftID");
                msgBox3.exec();
            }
        }else{
            QMessageBox msgBox2;
            msgBox2.setText("Duplicate ID for AircraftID");
            msgBox2.exec();
        }
    }
}

void uiairlinerep::on_reqInWeekly_clicked()
{
    ui->reqInDay->setEnabled(true);
    ui->reqInDate->setEnabled(false);
}

void uiairlinerep::on_reqInOne_clicked()
{
    ui->reqInDay->setEnabled(false);
    ui->reqInDate->setEnabled(true);
}

void uiairlinerep::on_reqInDaily_clicked()
{
    ui->reqInDay->setEnabled(false);
    ui->reqInDate->setEnabled(false);
}



void uiairlinerep::on_reqOutOne_clicked()
{
    ui->reqOutDay->setEnabled(false);
    ui->reqOutDate->setEnabled(true);
}

void uiairlinerep::on_reqOutDaily_clicked()
{
    ui->reqOutDay->setEnabled(false);
    ui->reqOutDate->setEnabled(false);
}

void uiairlinerep::on_reqOutWeekly_clicked()
{
    ui->reqOutDay->setEnabled(true);
    ui->reqOutDate->setEnabled(false);
}

void uiairlinerep::on_reqInSubmit_clicked()
{
    bool error = false;
    int flightID = ui->reqInFlightID->text().toInt();
    int craftID  = ui->FlightRequestAircraft->currentText().toInt();

    if (!fl->findByFlightID(flightID)->getAirline().empty()){
        QMessageBox::about (this, tr("ERROR"), tr("Existing flight ID!") );
        error = true;
    }else if (ui->reqInFlightID->text().isEmpty()){
        QMessageBox::about (this, tr("ERROR"), tr("Invalid flight ID!") );
        error = true;
    }else if (ui->FlightRequestAircraft->currentText().isNull()){
        QMessageBox::about (this, tr("ERROR"), tr("Invalid aircraft!") );
        error = true;
    }

    string source = ui->reqInSource->currentText().toStdString();
    string sourceLong;
    if (!source.compare("BCN")){
        sourceLong = "Barcelona";
    }else if(!source.compare("JFK")){
        sourceLong = "New York";
    }else if(!source.compare("LAX")){
        sourceLong = "Los Angeles";
    }else if(!source.compare("YVR")){
        sourceLong = "Vancouver";
    }

    int gateTime = ui->reqInGate->time().hour() *60 + ui->reqInGate->time().minute();
    int landTime = ui->reqInLand->time().hour() *60 + ui->reqInLand->time().minute();
    int scheduleType;
    QDate date = date.currentDate();
    int dayOfWeek = 0;

    if (ui->reqInOne->isChecked()){
        scheduleType = 0;
        date = ui->reqInDate->date();
        if (date < QDate::currentDate()){
            QMessageBox::about (this, tr("ERROR"), tr("Date before today!") );
            error = true;
        }else if(date == QDate::currentDate()){
            if (gateTime < QTime::currentTime().hour()*60 + QTime::currentTime().minute()||
                landTime < QTime::currentTime().hour()*60 + QTime::currentTime().minute()){
                QMessageBox::about (this, tr("ERROR"), tr("Time before now!") );
                error = true;
            }
        }


    }else if(ui->reqInDaily->isChecked()){
        scheduleType = 1;
    }else{
        scheduleType = 2;
        dayOfWeek = ui->reqInDay->currentIndex()+1;
    }

    if (gateTime < landTime){
        QMessageBox::about (this, tr("ERROR"), tr("Gate time before plane landing time!") );
        error = true;
    }
    if (!error){
        flight * newReq = new flight(flightID,craftID,this->accountName,source,sourceLong,"YXU","London",gateTime,landTime,0,scheduleType,date,dayOfWeek);
        this->reqVec->push_back(*newReq);
        frl->writeFile();
        QMessageBox::about (this, tr("SUCCESS"), tr("Flight request for incoming flight added!") );
        refresh();
    }
}

void uiairlinerep::on_reqOutSubmit_clicked()
{
    bool error = false;
    int flightID = ui->reqOutFlightID->text().toInt();
    int craftID  = ui->FlightRequestAircraft_2->currentText().toInt();

    if (!fl->findByFlightID(flightID)->getAirline().empty()){
        QMessageBox::about (this, tr("ERROR"), tr("Existing flight ID!") );
        error = true;
    }else if (ui->reqOutFlightID->text().isEmpty()){
        QMessageBox::about (this, tr("ERROR"), tr("Invalid flight ID!") );
        error = true;
    }else if (ui->FlightRequestAircraft_2->currentText().isNull()){
        QMessageBox::about (this, tr("ERROR"), tr("Invalid aircraft!") );
        error = true;
    }



    string destin = ui->reqOutDestination->currentText().toStdString();
    string destinLong;
    if (!destin.compare("BCN")){
        destinLong = "Barcelona";
    }else if(!destin.compare("JFK")){
        destinLong = "New York";
    }else if(!destin.compare("LAX")){
        destinLong = "Los Angeles";
    }else if(!destin.compare("YVR")){
        destinLong = "Vancouver";
    }

    int gateTime = ui->reqOutGate->time().hour() *60 + ui->reqOutGate->time().minute();
    int landTime = ui->reqOutTakeOff->time().hour() *60 + ui->reqOutTakeOff->time().minute();
    int scheduleType;
    QDate date = date.currentDate();
    int dayOfWeek = 0;

    if (ui->reqOutOne->isChecked()){
        scheduleType = 0;
        date = ui->reqOutDate->date();
        if (date < QDate::currentDate()){
            QMessageBox::about (this, tr("ERROR"), tr("Date before today!") );
            error = true;
        }else if(date == QDate::currentDate()){
            if (gateTime < QTime::currentTime().hour()*60 + QTime::currentTime().minute()||
                landTime < QTime::currentTime().hour()*60 + QTime::currentTime().minute()){
                QMessageBox::about (this, tr("ERROR"), tr("Time before now!") );
                error = true;
            }
        }
    }else if(ui->reqOutDaily->isChecked()){
        scheduleType = 1;
    }else{
        scheduleType = 2;
        dayOfWeek = ui->reqOutDay->currentIndex()+1;
    }
    if (gateTime > landTime){
        QMessageBox::about (this, tr("ERROR"), tr("Gate time after take off time!") );
        error = true;
    }
    if (!error){
        flight * newReq = new flight(flightID,craftID,"AIRLINE","YXU","London",destin,destinLong,gateTime,landTime,0,scheduleType,date,dayOfWeek);
        this->reqVec->push_back(*newReq);
        frl->writeFile();
        QMessageBox::about (this, tr("SUCCESS"), tr("Flight request for outgoing flight added!") );
        refresh();
    }
}

