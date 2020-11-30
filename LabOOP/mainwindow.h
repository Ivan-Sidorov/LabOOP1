#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "rotation.h"
#include <QMainWindow>
class collection;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Ui::MainWindow* get_ui();

private slots:
    void on_new_file_triggered();

    void on_open_file_triggered();

    void on_save_file_triggered();

    void on_save_file_as_triggered();

    void on_but_get_clicked();

    void on_but_count_clicked();

    void on_but_del_clicked();

    void on_but_del_all_clicked();

    void on_but_madd_clicked();

    void on_but_radd_clicked();

    void on_about_triggered();

    void on_author_triggered();

private:
    Ui::MainWindow *ui;
    QString file_path_;
};

#endif // MAINWINDOW_H
