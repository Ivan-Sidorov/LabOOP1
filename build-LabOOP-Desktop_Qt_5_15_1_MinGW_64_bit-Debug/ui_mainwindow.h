/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *new_file;
    QAction *open_file;
    QAction *save_file;
    QAction *save_file_as;
    QAction *about;
    QAction *author;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QFrame *line;
    QLabel *label_2;
    QLineEdit *line_vel;
    QLabel *label_3;
    QLineEdit *line_mtime;
    QPushButton *but_madd;
    QFrame *line_3;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QFrame *line_2;
    QLabel *label_5;
    QLineEdit *line_rad;
    QLabel *label_6;
    QLineEdit *line_dir;
    QLabel *label_7;
    QLineEdit *line_rtime;
    QPushButton *but_radd;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_8;
    QSpinBox *spin_box;
    QPushButton *but_del;
    QPushButton *but_del_all;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_9;
    QLCDNumber *lcd_x;
    QLabel *label_10;
    QLCDNumber *lcd_y;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *but_get;
    QLCDNumber *lcd_count;
    QPushButton *but_count;
    QTextEdit *text_edit;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuAbout;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(486, 461);
        new_file = new QAction(MainWindow);
        new_file->setObjectName(QString::fromUtf8("new_file"));
        open_file = new QAction(MainWindow);
        open_file->setObjectName(QString::fromUtf8("open_file"));
        save_file = new QAction(MainWindow);
        save_file->setObjectName(QString::fromUtf8("save_file"));
        save_file_as = new QAction(MainWindow);
        save_file_as->setObjectName(QString::fromUtf8("save_file_as"));
        about = new QAction(MainWindow);
        about->setObjectName(QString::fromUtf8("about"));
        author = new QAction(MainWindow);
        author->setObjectName(QString::fromUtf8("author"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        line_vel = new QLineEdit(frame);
        line_vel->setObjectName(QString::fromUtf8("line_vel"));

        verticalLayout->addWidget(line_vel);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        line_mtime = new QLineEdit(frame);
        line_mtime->setObjectName(QString::fromUtf8("line_mtime"));

        verticalLayout->addWidget(line_mtime);

        but_madd = new QPushButton(frame);
        but_madd->setObjectName(QString::fromUtf8("but_madd"));
        but_madd->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout->addWidget(but_madd);


        horizontalLayout->addWidget(frame);

        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_3);

        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        line_2 = new QFrame(frame_2);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);

        line_rad = new QLineEdit(frame_2);
        line_rad->setObjectName(QString::fromUtf8("line_rad"));

        verticalLayout_2->addWidget(line_rad);

        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_2->addWidget(label_6);

        line_dir = new QLineEdit(frame_2);
        line_dir->setObjectName(QString::fromUtf8("line_dir"));

        verticalLayout_2->addWidget(line_dir);

        label_7 = new QLabel(frame_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_2->addWidget(label_7);

        line_rtime = new QLineEdit(frame_2);
        line_rtime->setObjectName(QString::fromUtf8("line_rtime"));

        verticalLayout_2->addWidget(line_rtime);

        but_radd = new QPushButton(frame_2);
        but_radd->setObjectName(QString::fromUtf8("but_radd"));
        but_radd->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_2->addWidget(but_radd);


        horizontalLayout->addWidget(frame_2);


        verticalLayout_4->addLayout(horizontalLayout);

        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_8 = new QLabel(frame_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_2->addWidget(label_8);

        spin_box = new QSpinBox(frame_3);
        spin_box->setObjectName(QString::fromUtf8("spin_box"));
        spin_box->setCursor(QCursor(Qt::PointingHandCursor));
        spin_box->setMinimum(1);

        horizontalLayout_2->addWidget(spin_box);

        but_del = new QPushButton(frame_3);
        but_del->setObjectName(QString::fromUtf8("but_del"));
        but_del->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_2->addWidget(but_del);

        but_del_all = new QPushButton(frame_3);
        but_del_all->setObjectName(QString::fromUtf8("but_del_all"));
        but_del_all->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_2->addWidget(but_del_all);

        horizontalSpacer = new QSpacerItem(239, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_4->addWidget(frame_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_3->addWidget(label_9);

        lcd_x = new QLCDNumber(centralwidget);
        lcd_x->setObjectName(QString::fromUtf8("lcd_x"));
        lcd_x->setDigitCount(5);
        lcd_x->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_3->addWidget(lcd_x);

        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_3->addWidget(label_10);

        lcd_y = new QLCDNumber(centralwidget);
        lcd_y->setObjectName(QString::fromUtf8("lcd_y"));
        lcd_y->setDigitCount(5);
        lcd_y->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_3->addWidget(lcd_y);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        but_get = new QPushButton(centralwidget);
        but_get->setObjectName(QString::fromUtf8("but_get"));
        but_get->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_4->addWidget(but_get);


        verticalLayout_3->addLayout(horizontalLayout_4);

        lcd_count = new QLCDNumber(centralwidget);
        lcd_count->setObjectName(QString::fromUtf8("lcd_count"));
        lcd_count->setFrameShape(QFrame::Box);
        lcd_count->setFrameShadow(QFrame::Raised);
        lcd_count->setLineWidth(1);
        lcd_count->setMidLineWidth(0);
        lcd_count->setDigitCount(5);
        lcd_count->setSegmentStyle(QLCDNumber::Flat);

        verticalLayout_3->addWidget(lcd_count);

        but_count = new QPushButton(centralwidget);
        but_count->setObjectName(QString::fromUtf8("but_count"));
        but_count->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_3->addWidget(but_count);


        horizontalLayout_5->addLayout(verticalLayout_3);

        text_edit = new QTextEdit(centralwidget);
        text_edit->setObjectName(QString::fromUtf8("text_edit"));

        horizontalLayout_5->addWidget(text_edit);


        verticalLayout_4->addLayout(horizontalLayout_5);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 486, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menuFile->addAction(new_file);
        menuFile->addAction(open_file);
        menuFile->addSeparator();
        menuFile->addAction(save_file);
        menuFile->addAction(save_file_as);
        menuAbout->addAction(about);
        menuAbout->addAction(author);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        new_file->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
        open_file->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        save_file->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        save_file_as->setText(QCoreApplication::translate("MainWindow", "Save As...", nullptr));
        about->setText(QCoreApplication::translate("MainWindow", "What's this?", nullptr));
        author->setText(QCoreApplication::translate("MainWindow", "Author", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Motion", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Velocity:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Time:", nullptr));
        but_madd->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Rotation", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Radius:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Direction:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Time:", nullptr));
        but_radd->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Delete Action:", nullptr));
        but_del->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        but_del_all->setText(QCoreApplication::translate("MainWindow", "Delete all", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "X:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Y:", nullptr));
        but_get->setText(QCoreApplication::translate("MainWindow", "Get coordinates", nullptr));
        but_count->setText(QCoreApplication::translate("MainWindow", "Count", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuAbout->setTitle(QCoreApplication::translate("MainWindow", "About", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
