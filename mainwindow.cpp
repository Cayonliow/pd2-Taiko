#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QBrush>
#include <QWidget>
#include <QCoreApplication>
#include <QTimer>
#include <QtCore>
#include <QDebug>
#include <stdlib.h>
#include <QKeyEvent>
#include <QFont>
#include <QSound>
#include <QMediaPlayer>
#include <QMultimedia>

/*constructors that every items
(pictures,icons,sounds,musics,buttons)
are declared here*/

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer_to_cbg = new QTimer(this);
    timer = new QTimer(this);
    timer_to_cbg2 = new QTimer(this);
    timer_to_drum= new QTimer(this);
    timer_to_drum2= new QTimer(this);
    Music= new QMediaPlayer();
    ChooseMode= new QMediaPlayer();
    Easy= new QMediaPlayer();
    Hard= new QMediaPlayer();
    End= new QMediaPlayer();
    HIT= new QMediaPlayer();

    connect(timer_to_cbg,SIGNAL(timeout()),this,SLOT(change_BG()));
    connect(timer,SIGNAL(timeout()),this,SLOT(showtime()));
    connect(timer_to_drum,SIGNAL(timeout()),this,SLOT(slide_to_left()));
    connect(timer_to_cbg2,SIGNAL(timeout()),this,SLOT(change_BG2()));
    connect(timer_to_drum2,SIGNAL(timeout()),this,SLOT(slide_to_right()));

    time_30=30;
    y=100;
    score=0;

    ui->Score->hide();
    ui->counttimer->hide();
    ui->word->hide();

    QPixmap pixmap1(":/First_Scene/Naruto1.jpg");
    ui->First_Scene->setPixmap(pixmap1);
    ui->First_Scene->setGeometry(QRect(0,0,1428,897));
    ui->First_Scene->setScaledContents(true);
    ui->First_Scene->setFixedSize(1428,897);

    QPixmap pixmap2_1(":/StartButton/startbutton.png");
    ui->Start_Button->setGeometry((1428/2)-200,(897/2)-100,301,148);
    QIcon ButtonIconA_1(pixmap2_1);
    ui->Start_Button->setIcon(ButtonIconA_1);
    ui->Start_Button->setIconSize(pixmap2_1.rect().size());

    QPixmap pixmap2_2(":Exit_Button/exitbutton.png");
    ui->Exit_Button->setGeometry((1428/2)-200,(897/2)+100,301,148);
    QIcon ButtonIconA_2(pixmap2_2);
    ui->Exit_Button->setIcon(ButtonIconA_2);
    ui->Exit_Button->setIconSize(pixmap2_2.rect().size());

    QPixmap pixmap3(":/Second_Scene/Naruto2.jpg");
    ui->Second_Scene->setPixmap(pixmap3);
    ui->Second_Scene->setGeometry(QRect(0,0,1428,897));
    ui->Second_Scene->setScaledContents(true);

    QPixmap pixmap4_1(":/Press_To_Start/Press_To_Start_Easy.png");
    ui->Press_To_Start_Easy->setGeometry((1428/2)-600,(897/2)+100,301,148);
    QIcon ButtonIconB_1(pixmap4_1);
    ui->Press_To_Start_Easy->setIcon(ButtonIconB_1);
    ui->Press_To_Start_Easy->setIconSize(pixmap4_1.rect().size());
    ui->Press_To_Start_Easy->hide();

    QPixmap pixmap4_2(":/Press_To_Start/Press_To_Start_Hard.png");
    ui->Press_To_Start_Hard->setGeometry((1428/2)+300,(897/2)+100,301,148);
    QIcon ButtonIconB_2(pixmap4_2);
    ui->Press_To_Start_Hard->setIcon(ButtonIconB_2);
    ui->Press_To_Start_Hard->setIconSize(pixmap4_2.rect().size());
    ui->Press_To_Start_Hard->hide();

    QPixmap pixmap5(":/Bigi/bigi1.png");
    ui->bigi1->setPixmap(pixmap5);
    ui->bigi1->setGeometry(QRect(0,0,1428,897));
    ui->bigi1->setScaledContents(true);
    ui->bigi1->setFixedSize(1428,897);
    ui->bigi1->hide();

    QPixmap pixmap6(":/Bigi/bigi2.png");
    ui->bigi2->setPixmap(pixmap6);
    ui->bigi2->setGeometry(QRect(0,0,1428,897));
    ui->bigi2->setScaledContents(true);
    ui->bigi2->setFixedSize(1428,897);
    ui->bigi2->hide();


    /*set the positions of every drums randomly*/
    for(int i=1;i<=7;i++)
    {
        position[i]=((qrand()%11)+5)*((qrand()%800)+1)+2000;
    }

    for(int i=8;i<=14;i++)
    {
        position[i]=-((qrand()%11)+10)*((qrand()%800)+1);
    }


    QPixmap pixmap6_1(":/Drums/D1.png");
    ui->drum1s->setPixmap(pixmap6_1);
    ui->drum1s->setGeometry(position[1],100,500,500);


    QPixmap pixmap6s_1(":/Drums/D1s.png");
    ui->drum1b->setPixmap(pixmap6s_1);
    ui->drum1b->setGeometry(position[2],1000,250,700);
    ui->drum1b->setFixedSize(150,150);
    ui->drum1b->setScaledContents(true);

    QPixmap pixmap6_2(":/Drums/D2.png");
    ui->drum2s->setPixmap(pixmap6_2);
    ui->drum2s->setGeometry(position[3],100,500,500);

    QPixmap pixmap6s_2(":/Drums/D2s.png");
    ui->drum2b->setPixmap(pixmap6s_2);
    ui->drum2b->setGeometry(position[4],1000,250,700);
    ui->drum2b->setFixedSize(150,150);
    ui->drum2b->setScaledContents(true);

    QPixmap pixmap6_3(":/Drums/D3.png");
    ui->drum3s->setPixmap(pixmap6_3);
    ui->drum3s->setGeometry(position[5],100,500,500);

    QPixmap pixmap6s_3(":/Drums/D3s.png");
    ui->drum3b->setPixmap(pixmap6s_3);
    ui->drum3b->setGeometry(position[6],1000,250,700);
    ui->drum3b->setFixedSize(150,150);
    ui->drum3b->setScaledContents(true);

    QPixmap pixmap6_4(":/Drums/D4.png");
    ui->drum4s->setPixmap(pixmap6_4);
    ui->drum4s->setGeometry(position[7],100,500,500);

    QPixmap pixmap6s_4(":/Drums/D4s.png");
    ui->drum4b->setPixmap(pixmap6_4);
    ui->drum4b->setGeometry(position[8],100,250,250);
    ui->drum4b->setFixedSize(150,150);
    ui->drum4b->setScaledContents(true);

    QPixmap pixmap6_5(":/Drums/D5.png");
    ui->drum5s->setPixmap(pixmap6_5);
    ui->drum5s->setGeometry(position[9],100,500,500);

    QPixmap pixmap6s_5(":/Drums/D5s.png");
    ui->drum5b->setPixmap(pixmap6s_5);
    ui->drum5b->setGeometry(position[10],100,250,250);
    ui->drum5b->setFixedSize(150,150);
    ui->drum5b->setScaledContents(true);

    QPixmap pixmap6_6(":/Drums/D6.png");
    ui->drum6s->setPixmap(pixmap6_6);
    ui->drum6s->setGeometry(position[11],100,500,500);

    QPixmap pixmap6s_6(":/Drums/D6s.png");
    ui->drum6b->setPixmap(pixmap6s_6);
    ui->drum6b->setGeometry(position[12],100,250,250);
    ui->drum6b->setFixedSize(150,150);
    ui->drum6b->setScaledContents(true);

    QPixmap pixmap6_7(":/Drums/D7.png");
    ui->drum7s->setPixmap(pixmap6_7);
    ui->drum7s->setGeometry(position[13],100,500,500);

    QPixmap pixmap6s_7(":/Drums/D7s.png");
    ui->drum7b->setPixmap(pixmap6s_7);
    ui->drum7b->setGeometry(position[14],100,250,250);
    ui->drum7b->setFixedSize(150,150);
    ui->drum7b->setScaledContents(true);


    QPixmap pixmap7(":/Final/1.png");
    ui->Final->setPixmap(pixmap7);
    ui->Final->setGeometry(300,100,900,500);
    ui->Final->setScaledContents(true);
    ui->Final->hide();

    ui->Restart_Button->setGeometry(400,400,300,150);
    QPixmap pixmap8(":/Restart_Button/restartbutton.png");
    QIcon ButtonIconC(pixmap8);
    ui->Restart_Button->setIcon(ButtonIconC);
    ui->Restart_Button->setIconSize(pixmap8.rect().size());
    ui->Final->setScaledContents(true);
    ui->Restart_Button->hide();

    /*QPixmap pixmap9(":/Final/mark.png");
    ui->Final->setPixmap(pixmap9);
    ui->Final->setGeometry(250,200,1000,1000);
    ui->Final->setScaledContents(true);
    ui->Final->hide();*/

    QPixmap pixmap10(":/Face/face.png");
    ui->face->setPixmap(pixmap10);
    ui->face->setGeometry(350,y+120,250,250);
    ui->face->setScaledContents(true);
    ui->face->hide();

    Music->setMedia(QUrl("qrc:/Sound/Naruto_main.mp3"));
    Music->setVolume(70);
    Music->play();

    ChooseMode->setMedia(QUrl("qrc:/Sound/Naruto_choose_mode.mp3"));
    ChooseMode->setVolume(70);
    //Music->play();

    Easy->setMedia(QUrl("qrc:/Sound/Naruto_Easy_mode.mp3"));
    Easy->setVolume(70);
    //Music->play();

    Hard->setMedia(QUrl("qrc:/Sound/Naruto_Hard_mode.mp3"));
    Hard->setVolume(70);
    //Music->play();

    End->setMedia(QUrl("qrc:/Sound/Naruto_endgame.mp3"));
    End->setVolume(70);
    //End->play();

    HIT->setMedia(QUrl("qrc:/Sound/Naruto_miss.mp3"));
    HIT->setVolume(70);
    //HIT->play();

    ui->Real_Start->setGeometry(625,400,250,100);
    QPixmap pixmap11(":/Real_Start/Press_To_Start1.png");
    QIcon ButtonIconD(pixmap11);
    ui->Real_Start->setIcon(ButtonIconD);
    ui->Real_Start->setIconSize(pixmap11.rect().size());
    ui->Real_Start->hide();

    QPixmap pixmap12(":/Second_Scene/Naruto2.jpg");
    ui->Again->setPixmap(pixmap12);
    ui->Again->setGeometry(QRect(0,0,1428,897));
    ui->Again->setScaledContents(true);
    ui->Again->hide();

    ui->Real_Start2->setGeometry(625,400,250,100);
    QPixmap pixmap13(":/Real_Start/Press_To_Start2.png");
    QIcon ButtonIconE(pixmap13);
    ui->Real_Start2->setIcon(ButtonIconE);
    ui->Real_Start2->setIconSize(pixmap13.rect().size());
    ui->Real_Start2->hide();

    QPixmap pixmap14(":/Sohbi/sohbi1.png");
    ui->sohbi1->setPixmap(pixmap14);
    ui->sohbi1->setGeometry(QRect(0,0,1428,897));
    ui->sohbi1->setScaledContents(true);
    ui->sohbi1->setFixedSize(1428,897);
    ui->sohbi1->hide();

    QPixmap pixmap15(":/Sohbi/sohbi2.png");
    ui->sohbi2->setPixmap(pixmap15);
    ui->sohbi2->setGeometry(QRect(0,0,1428,897));
    ui->sohbi2->setScaledContents(true);
    ui->sohbi2->setFixedSize(1428,897);
    ui->sohbi2->hide();

    QPixmap pixmap16(":/Sohbi/sohbi3.png");
    ui->sohbi3->setPixmap(pixmap16);
    ui->sohbi3->setGeometry(QRect(0,0,1428,897));
    ui->sohbi3->setScaledContents(true);
    ui->sohbi3->setFixedSize(1428,897);
    ui->sohbi3->hide();

    QPixmap pixmap17(":/Sohbi/sohbi4.png");
    ui->sohbi4->setPixmap(pixmap17);
    ui->sohbi4->setGeometry(QRect(0,0,1428,897));
    ui->sohbi4->setScaledContents(true);
    ui->sohbi4->setFixedSize(1428,897);
    ui->sohbi4->hide();

    QPixmap pixmap18(":/Face/face2.png");
    ui->face2->setPixmap(pixmap18);
    ui->face2->setGeometry(900,y+330,250,250);
    ui->face2->setScaledContents(true);
    ui->face2->hide();

    ui->back_button->hide();
    ui->back_button_2->hide();
    ui->Pause->hide();

    ui->back_button->setGeometry(40,20,100,100);
    QPixmap pixmap19(":/Back/backbutton.png");
    QIcon ButtonIconF(pixmap19);
    ui->back_button->setFixedSize(150,100);
    ui->back_button->setIcon(ButtonIconF);
    //ui->back_button->setScaledContents(true);
    ui->back_button->setIconSize(pixmap19.rect().size());
    //ui->Real_Start2->hide();

    ui->back_button_2->setGeometry(40,20,100,100);
    QPixmap pixmap20(":/Back/backbutton.png");
    QIcon ButtonIconG(pixmap20);
    ui->back_button_2->setFixedSize(150,100);
    ui->back_button_2->setIcon(ButtonIconG);
    //ui->back_button->setScaledContents(true);
    ui->back_button_2->setIconSize(pixmap20.rect().size());
    //ui->Real_Start2->hide();

/*
    QPixmap pixmap21(":/Pause/pause.png");
    QIcon ButtonIconH(pixmap21);
    ui->Pause->setFixedSize(150,100);
    ui->Pause->setIcon(ButtonIconH);
    ui->Pause->setIconSize(pixmap21.rect().size());
    ui->Pause->hide();
*/
    ui->Resume->setGeometry(600,400,250,250);
    QPixmap pixmap22(":/Resume/resume.png");
    QIcon ButtonIconJ(pixmap22);
    ui->Resume->setFixedSize(250,250);
    ui->Resume->setIcon(ButtonIconJ);
    //ui->Resume->setScaledContents(true);
    ui->Resume->setIconSize(pixmap22.rect().size());
    ui->Resume->hide();

}

/*Destructor*/
MainWindow::~MainWindow()
{
    delete ui;
}

/*Game() and Game2() are the mode of playing the game*/
/*Game() is the stardard playing mode*/
void MainWindow::Game()
{
    ui->Restart_Button->hide();
    ui->Final->hide();
    ui->bigi2->show();
    ui->drum1s->show(); ui->drum1b->show();
    ui->drum2s->show(); ui->drum2b->show();
    ui->drum3s->show(); ui->drum3b->show();
    ui->drum4s->show();

    /*ui->drum4b->show();
    ui->drum5s->show(); ui->drum5b->show();
    ui->drum6s->show(); ui->drum6b->show();
    ui->drum7s->show(); ui->drum7b->show();*/

    ui->face->show();

    //timer_to_cbg =new QTimer(this);
    //timer_to_cbg->setInterval(400);
    //connect(timer_to_cbg,SIGNAL(timeout()),this,SLOT(change_BG()));
    timer_to_cbg->start(400);

    //timer =new QTimer(this);
    //timer->setInterval(1000);
    //connect(timer,SIGNAL(timeout()),this,SLOT(showtime()));
    ui->counttimer->hide();
    timer->start(1000);
    ui->Score->setText(QString::number(score));
    //ui->Score->hide();

    //timer_to_drum= new QTimer(this);
    //timer_to_drum->setInterval(50);
    //connect(timer_to_drum,SIGNAL(timeout()),this,SLOT(slide_to_left()));
    timer_to_drum->start(50);
    ui->Score->show();
    //ui->drum1->show();

}

/*Game() is the advanced playing mode*/
void MainWindow::Game2()
{
    ui->Restart_Button->hide();
    ui->Final->hide();
    ui->bigi2->hide();
    ui->bigi1->hide();
    ui->drum1s->show(); ui->drum1b->show();
    ui->drum2s->show(); ui->drum2b->show();
    ui->drum3s->show(); ui->drum3b->show();
    ui->drum4s->show();

    ui->drum4b->show();
    ui->drum5s->show(); ui->drum5b->show();
    ui->drum6s->show(); ui->drum6b->show();
    ui->drum7s->show(); ui->drum7b->show();

    ui->face->show();
    ui->face2->show();

    timer_to_cbg2->start(200);
    timer->start(1000);
    ui->Score->setText(QString::number(score));
    timer_to_drum->start(50);
    ui->Score->show();
    timer_to_drum2->start(50);

}

/*key J and S are set to press in order to hit the drums*/
/*key J hits the big drum
key S hits the small drum*/
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key()==Qt::Key_S)
       {
            //HIT->play();

            if(position[2]>=250&&position[2]<=450)
            {
                HIT->play();
                score++;
                position[2]=-100;
                /*if(position[2]==-100)
                {
                    HIT->stop();
                }*/
            }

            if(position[4]>=250&&position[4]<=450)
            {
                HIT->play();
                score++;
                position[4]=-100;
                /*if(position[4]==-100)
                {
                    HIT->stop();
                }*/

            }

            if(position[6]>=250&&position[6]<=450)
            {
                HIT->play();
                score++;
                position[6]=-100;
                /*if(position[6]==-100)
                {
                    HIT->stop();
                }*/

            }

            if(position[8]>=800&&position[8]<=1000)
            {
                HIT->play();
                score++;
                position[8]=1200;
                /*if(position[8]==1200)
                {
                    HIT->stop();
                }*/

            }

            if(position[10]>=800&&position[10]<=1000)
            {
                HIT->play();
                score++;
                position[10]=1200;
                /*if(position[10]==1200)
                {
                    HIT->stop();
                }*/

            }

            if(position[12]>=800&&position[12]<=1000)
            {
                HIT->play();
                score++;
                position[12]=1200;
                /*if(position[12]==1200)
                {
                    HIT->stop();
                }*/

            }

            if(position[14]>=800&&position[14]<=1000)
            {
                HIT->play();
                score++;
                position[14]=1200;
                /*(position[14]==1200)
                {
                    HIT->stop();
                }*/

            }
       }

    if (event->key()==Qt::Key_L)
    {
        //HIT->play();

        if(position[1]>=250&&position[1]<=450)
        {
            HIT->play();
            score++;
            position[1]=-100;
            /*if(position[1]==-100)
            {
                HIT->stop();
            }*/

        }

        if(position[3]>=250&&position[3]<=450)
        {
            HIT->play();
            score++;
            position[3]=-100;
            /*if(position[3]==-100)
            {
                HIT->stop();
            }*/

        }

        if(position[5]>=250&&position[5]<=450)
        {
            HIT->play();
            score++;
            position[5]=-100;
            /*if(position[5]==-100)
            {
                HIT->stop();
            }*/

        }

        if(position[7]>=250&&position[7]<=450)
        {
            HIT->play();
            score++;
            position[7]=-100;
            /*if(position[7]==-100)
            {
                HIT->stop();
            }*/

        }

        if(position[9]>=800&&position[9]<=1000)
        {
            HIT->play();
            score++;
            position[9]=1200;
            /*if(position[9]==1200)
            {
                HIT->stop();
            }*/

        }

        if(position[11]>=800&&position[11]<=1000)
        {
            HIT->play();
            score++;
            position[11]=1200;
            /*if(position[11]==1200)
            {
                HIT->stop();
            }*/

        }

        if(position[13]>=800&&position[13]<=1000)
        {
            HIT->play();
            score++;
            position[13]=1200;
            /*if(position[13]==1200)
            {
                HIT->stop();
            }*/

        }
    }

}

/*30seconds to play 1 round(either the stardard or the advanced mode)*/
/*the scores played will be shown when timesout*/
void MainWindow::showtime()
{
    time_30--;

    if(time_30>=0)
    {
        ui->Time->setText("TIME:　");
        ui->Time->show();
        ui->SCORE->setText("SCORE: ");
        ui->SCORE->show();
        ui->counttimer->setText(QString::number(time_30));
        ui->counttimer->show();
    }

    if(time_30<0)
    {
        ui->counttimer->hide();
        ui->Time->hide();
        ui->SCORE->hide();
        ui->Score->hide();
        ui->drum1s->hide();
        ui->drum2s->hide();
        ui->drum3s->hide();
        ui->drum4s->hide();
        ui->drum5s->hide();
        ui->drum6s->hide();
        ui->drum7s->hide();
        ui->drum1b->hide();
        ui->drum2b->hide();
        ui->drum3b->hide();
        ui->drum4b->hide();
        ui->drum5b->hide();
        ui->drum6b->hide();
        ui->drum7b->hide();

        ui->face->hide();
        ui->face2->hide();
        ui->counttimer->hide();
        ui->Final->show();
        ui->Restart_Button->show();
        ui->showscore->setFixedSize(1000,1000);
        ui->Exit_Button->setGeometry(400+400,400,300,150);
        ui->Exit_Button->show();
        ui->showscore->setGeometry(500,100,400,500);
        //ui->showscore->setFixedSize(1000,1000);
        ui->word->show();
        ui->finalscore->setText(QString::number(score));
        ui->finalscore->show();
        timer->stop();
        timer_to_cbg->stop();
        timer_to_drum->stop();
        timer_to_cbg2->stop();
        timer_to_drum2->stop();
        Easy->stop();
        Hard->stop();
        End->play();
        ui->Pause->hide();

    }
}

/*the backgrounds of the two playing mode will with changed with the time
in the interval of 0.5s(stardard)and 0.25s(advanced)
by using the timer to control*/

/*changing background the stardard playing mode with the time interval of 0.5s*/
void MainWindow::change_BG()
{
    mark++;
    if(mark%2==1)
    {
        ui->bigi1->show();
        ui->bigi2->hide();
    }

    if(mark%2==0)
    {
        ui->bigi1->hide();

        ui->bigi2->show();
   }

}

/*changing background the advanced playing mode with the time interval of 0.25s*/
void MainWindow::change_BG2()
{
    mark2++;
    if(mark2%4==3)
    {
        ui->sohbi1->show();
        ui->sohbi2->hide();
        ui->sohbi3->hide();
        ui->sohbi4->hide();
    }

    if(mark2%4==2)
    {
        ui->sohbi1->hide();
        ui->sohbi2->show();
        ui->sohbi3->hide();
        ui->sohbi4->hide();
    }

    if(mark2%4==1)
    {
        ui->sohbi1->hide();
        ui->sohbi2->hide();
        ui->sohbi3->show();
        ui->sohbi4->hide();
    }

    if(mark2%4==0)
    {
        ui->sohbi1->hide();
        ui->sohbi2->hide();
        ui->sohbi3->hide();
        ui->sohbi4->show();
    }


}

/*this two functions are connected to timer in order to move the drums with time*/

/*used in the stardard playing mode and also the advanced playing mode
move the drums to left*/
void MainWindow::slide_to_left()
{
    ui->Score->setText(QString::number(score));
    for(int j=1;j<=7;j++)
    {
        position[j]=position[j]-30;

        if(position[j]<=100)
        {
            //MISS->play();
            position[j]=((qrand()%11)+5)*((qrand()%800)+1)+2000;
        }
    }

    ui->drum1s->move(QPoint(position[1],y));
    ui->drum1b->move(QPoint(position[2],y+150));
    ui->drum2s->move(QPoint(position[3],y));
    ui->drum2b->move(QPoint(position[4],y+150));
    ui->drum3s->move(QPoint(position[5],y));
    ui->drum3b->move(QPoint(position[6],y+150));
    ui->drum4s->move(QPoint(position[7],y));

}

/*used in the advanced playing mode
move the drums to right*/
void MainWindow::slide_to_right()
{
    ui->Score->setText(QString::number(score));
    for(int j=8;j<=14;j++)
    {
        position[j]=position[j]+30;

        if(position[j]>=1100)
        {
            //MISS->play();
            position[j]=-((qrand()%11)+10)*((qrand()%800)+1);
        }
    }

    ui->drum4b->move(QPoint(position[8],y+400));
    ui->drum5s->move(QPoint(position[9],y+200));
    ui->drum5b->move(QPoint(position[10],y+400));
    ui->drum6s->move(QPoint(position[11],y+200));
    ui->drum6b->move(QPoint(position[12],y+400));
    ui->drum7s->move(QPoint(position[13],y+200));
    ui->drum7b->move(QPoint(position[14],y+400));

}

/*all the function below are used in buttons */

/*Press to start and choose the mode want to play*/
void MainWindow::on_Start_Button_clicked()
{
    ui->First_Scene->hide();
    ui->Start_Button->hide();
    ui->Exit_Button->hide();
   // ui->Second_Scene->show();
    ui->Second_Scene->show();
    //ui->drum1->show();
    ui->Press_To_Start_Easy->show();
    ui->Press_To_Start_Hard->show();
    ui->back_button->show();
    Music->stop();
    ChooseMode->play();
}

/*Stardard playing mode is chosen to play the all the items are ready*/
void MainWindow::on_Press_To_Start_Easy_clicked()
{
    ui->back_button->hide();
    ui->Press_To_Start_Easy->hide();
    ui->Press_To_Start_Hard->hide();
    ui->Second_Scene->hide();
    ui->Again->hide();
    ui->bigi2->show();
    ui->Real_Start->show();
    ui->back_button_2->show();
    //ChooseMode->stop();
}

/*Advanced playing mode is chosen to play the all the items are ready*/
void MainWindow::on_Press_To_Start_Hard_clicked()
{
    ui->back_button->hide();
    ui->Press_To_Start_Easy->hide();
    ui->Press_To_Start_Hard->hide();
    ui->Second_Scene->hide();
    ui->Again->hide();
    ui->sohbi1->show();
    ui->Real_Start2->show();
    ui->Final->hide();
    ui->Score->hide();
    ui->back_button_2->show();
    //ui->Real_Start2->hide();
    //ChooseMode->stop();
}

/*Press to start the stardard playing mode*/
void MainWindow::on_Real_Start_clicked()
{

    ui->Real_Start->hide();
    ui->counttimer->hide();
    ChooseMode->stop();
    Easy->play();
    ui->back_button_2->hide();
    ui->Pause->show();

    Game();
}

/*Press to start the advanced playing mode*/
void MainWindow::on_Real_Start2_clicked()
{
    ui->bigi1->show();
    ui->Real_Start2->hide();
    ui->counttimer->hide();
    ChooseMode->stop();
    Hard->play();
    ui->back_button_2->hide();
    ui->Pause->show();

    ui->word->hide();

    Game2();
}

/*Press to back to the previous scene*/
void MainWindow::on_back_button_clicked()
{
    ui->Second_Scene->hide();
    ui->First_Scene->show();
    ui->Start_Button->show();
    ui->Exit_Button->setGeometry((1428/2)-200,(897/2)+100,301,148);
    ui->finalscore->hide();
    ui->Exit_Button->show();


    ui->Press_To_Start_Easy->hide();
    ui->Press_To_Start_Hard->hide();
    ui->back_button->hide();

    ChooseMode->stop();
    Music->play();
    //ui->Second_Scene->hide();
    //ui->Exit_Button->hide();
}

/*Press to back to the previous scene*/
void MainWindow::on_back_button_2_clicked()
{
    ui->back_button_2->hide();
    ui->bigi1->hide();
    ui->bigi2->hide();
    ui->sohbi1->hide();
    ui->sohbi2->hide();
    ui->sohbi3->hide();
    ui->sohbi4->hide();
    ui->Real_Start->hide();
    ui->Real_Start2->hide();
    ui->Second_Scene->show();
    ui->back_button->show();
    ui->Press_To_Start_Easy->show();
    ui->Press_To_Start_Hard->show();
    ChooseMode->stop();
    ChooseMode->play();
    ui->Exit_Button->hide();
}

/*shown when game ended
can press to restart */
void MainWindow::on_Restart_Button_clicked()
{
    time_30=30;
    score=0;
    ui->Again->show();
    ui->Second_Scene->show();
    ui->Press_To_Start_Easy->show();
    ui->Press_To_Start_Hard->show();
    ui->Final->hide();
    ui->Restart_Button->hide();
    ui->Exit_Button->hide();
    ui->SCORE->hide();
    ui->finalscore->hide();
    End->stop();
    ChooseMode->play();
    ui->back_button_2->hide();
    ui->back_button->show();
    ui->word->hide();

}

/*shown in the first scene and game anded
can press to closse the whole game*/
void MainWindow::on_Exit_Button_clicked()
{
    ui->Exit_Button->hide();
    this->close();
}

///////////////////////*
/// the failure parts i tried to write the pause and resume button
//////////////////////
/*void MainWindow::on_Pause_clicked()
{
    ui->Pause->hide();
    timer->stop();
    timer_to_cbg->stop();
    timer->stop();
    timer_to_cbg2->stop();
    timer_to_drum->stop();
    timer_to_drum2->stop();
    ui->Final->show();
    //Easy->stop();
    //End->play();
    ui->Resume->show();


}*/

/*void MainWindow::on_Resume_clicked()
{
    ui->Resume->hide();
    ui->Final->hide();
    timer->start();
    timer_to_cbg->start();
    timer->start();
    timer_to_cbg2->start();
    timer_to_drum->start();
    timer_to_drum2->start();

}*/
