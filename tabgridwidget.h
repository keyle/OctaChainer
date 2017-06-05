#ifndef TABGRIDWIDGET_H
#define TABGRIDWIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <QShortcut>
#include <QThread>
#include <QMimeData>
#include <QAudio>
#include <QMediaPlayer>
#include "audiofactory.h"

namespace Ui {
class TabGridWidget;
}

class TabGridWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TabGridWidget(QWidget *parent = 0);
    ~TabGridWidget();

public slots:
    void updateProgressBar(int currentSlice, int totalSlices);
    void updateUIafterCreateDone();

protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);

private slots:
    void on_btnAddWav_clicked();
    void on_btnPlay_clicked();
    void on_btnStop_clicked();
    void on_listSlices_doubleClicked(const QModelIndex &index);
    void on_btnRemove_clicked();
    void on_btnCreate_clicked();
    void on_sliderGain_valueChanged(int value);
    void on_sliderBPM_valueChanged(int value);
    void on_btnAddSilence_clicked();
    void on_txtBPMValue_textChanged();
    void on_txtGainValue_textChanged();

private:
    Ui::TabGridWidget *ui;
    void playAudio();
    void createWav(const QString destFilename);
    void updateSliceCount();
    void addListItems(const QStringList files);
    QMediaPlayer *mediaplayer;
    QString defaultPathAudio;
    QString defaultPathProjects;
    QString defaultPathOutput;


};

#endif // TABGRIDWIDGET_H
