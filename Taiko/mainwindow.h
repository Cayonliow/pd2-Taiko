#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QMainWindow>
#include <QSound>
#include <QMultimedia>
#include <QMediaPlayer>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QTimer *timer;
    QTimer *timer_to_drum;
    QTimer *timer_to_cbg;
    QTimer *timer_to_cbg2;
    QTimer *timer_to_drum2;
    QMediaPlayer *Music;
    QMediaPlayer *ChooseMode;
    QMediaPlayer *Easy;
    QMediaPlayer *Hard;
    QMediaPlayer *End;
    QMediaPlayer *HIT;
    QMediaPlayer *MISS;
    int count;
    int time_30;
    int x;
    int y;
    int position[15];
    int score;
    int click;
    int mark;
    int mark2;

    ~MainWindow();


private slots:
    void on_Start_Button_clicked();

    void on_Press_To_Start_Easy_clicked();

    void Game();

    void showtime();

    void slide_to_left();

    void slide_to_right();

    void keyPressEvent(QKeyEvent *event);

    void change_BG();

    void change_BG2();

    void on_Restart_Button_clicked();

    void on_Exit_Button_clicked();

    void on_Real_Start_clicked();

    void on_Press_To_Start_Hard_clicked();

    void on_Real_Start2_clicked();

    void Game2();

    void on_back_button_clicked();

    void on_back_button_2_clicked();

    //void on_Pause_clicked();

    //void on_Resume_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
