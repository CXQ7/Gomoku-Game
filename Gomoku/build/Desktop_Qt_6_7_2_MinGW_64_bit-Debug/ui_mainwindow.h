/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QLineEdit *five_in_a_row_title;
    QLineEdit *gomoku_vice_title;
    QPushButton *game_start_button;
    QListWidget *background;
    QListWidget *listWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setContextMenuPolicy(Qt::PreventContextMenu);
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 801, 601));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setLayoutDirection(Qt::LeftToRight);
        widget->setAutoFillBackground(true);
        five_in_a_row_title = new QLineEdit(widget);
        five_in_a_row_title->setObjectName("five_in_a_row_title");
        five_in_a_row_title->setGeometry(QRect(160, 200, 481, 41));
        sizePolicy.setHeightForWidth(five_in_a_row_title->sizePolicy().hasHeightForWidth());
        five_in_a_row_title->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("Snap ITC")});
        font.setPointSize(40);
        font.setBold(true);
        font.setUnderline(false);
        font.setStyleStrategy(QFont::PreferDefault);
        five_in_a_row_title->setFont(font);
        five_in_a_row_title->setLayoutDirection(Qt::LeftToRight);
        five_in_a_row_title->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        five_in_a_row_title->setFrame(false);
        five_in_a_row_title->setAlignment(Qt::AlignCenter);
        five_in_a_row_title->setDragEnabled(false);
        five_in_a_row_title->setReadOnly(true);
        five_in_a_row_title->setCursorMoveStyle(Qt::LogicalMoveStyle);
        gomoku_vice_title = new QLineEdit(widget);
        gomoku_vice_title->setObjectName("gomoku_vice_title");
        gomoku_vice_title->setGeometry(QRect(350, 270, 113, 20));
        sizePolicy.setHeightForWidth(gomoku_vice_title->sizePolicy().hasHeightForWidth());
        gomoku_vice_title->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("ROG Fonts")});
        font1.setPointSize(15);
        gomoku_vice_title->setFont(font1);
        gomoku_vice_title->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        gomoku_vice_title->setFrame(false);
        gomoku_vice_title->setAlignment(Qt::AlignCenter);
        gomoku_vice_title->setReadOnly(true);
        game_start_button = new QPushButton(widget);
        game_start_button->setObjectName("game_start_button");
        game_start_button->setGeometry(QRect(250, 330, 300, 60));
        sizePolicy.setHeightForWidth(game_start_button->sizePolicy().hasHeightForWidth());
        game_start_button->setSizePolicy(sizePolicy);
        game_start_button->setSizeIncrement(QSize(0, 0));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Rockwell Extra Bold")});
        font2.setPointSize(22);
        game_start_button->setFont(font2);
        game_start_button->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 170 , 0 , 200);"));
        game_start_button->setIconSize(QSize(15, 15));
        background = new QListWidget(widget);
        background->setObjectName("background");
        background->setGeometry(QRect(0, 0, 811, 631));
        sizePolicy.setHeightForWidth(background->sizePolicy().hasHeightForWidth());
        background->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setPointSize(6);
        background->setFont(font3);
        background->setLayoutDirection(Qt::LeftToRight);
        background->setAutoFillBackground(false);
        background->setStyleSheet(QString::fromUtf8("border-image: url(:/menu/img/menu_background.jpg);"));
        listWidget = new QListWidget(widget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(80, 90, 641, 401));
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Rockwell Extra Bold")});
        listWidget->setFont(font4);
        listWidget->setAutoFillBackground(false);
        listWidget->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 150);"));
        listWidget->setLineWidth(0);
        background->raise();
        listWidget->raise();
        five_in_a_row_title->raise();
        gomoku_vice_title->raise();
        game_start_button->raise();
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Five In A Row", nullptr));
        five_in_a_row_title->setText(QCoreApplication::translate("MainWindow", "Five In A Row", nullptr));
        gomoku_vice_title->setText(QCoreApplication::translate("MainWindow", "Gomoku", nullptr));
        game_start_button->setText(QCoreApplication::translate("MainWindow", "GAME  START", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
