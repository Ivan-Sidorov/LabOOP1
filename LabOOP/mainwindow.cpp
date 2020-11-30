#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tests.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

collection* inp_col = new collection;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_new_file_triggered() {
    file_path_ = "";
    ui->text_edit->setText("");
    ui->line_vel->setText("");
    ui->line_mtime->setText("");
    ui->line_rad->setText("");
    ui->line_dir->setText("");
    ui->line_rtime->setText("");
    ui->lcd_x->display(0);
    ui->lcd_y->display(0);
    inp_col = new collection;
}

void MainWindow::on_open_file_triggered() {
    QString file_name = QFileDialog::getOpenFileName(this, "Open file");
    file_path_ = file_name;
    QFile file(file_name);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning!", "File is not open");
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    QByteArray ba = file_name.toLocal8Bit();
    const char *path = ba.data();
    ui->text_edit->setText("");
    inp_col->read_data(path);
    inp_col->reverse();
    int i = 1;
    inp_col->iter_begin();
    std::cout<<"\nCommands:";
    QString line = "";
    while(inp_col->cur() != nullptr) {
        std::cout<<"\nElement " << i;
        std::cout<<"\n";
        line = inp_col->cur()->print_params();
        ui->text_edit->append(QString::number(i) + ". ");
        ui->text_edit->append(line);
        i++;
        inp_col->next();
    }
    inp_col->reverse();
    file.close();
}

void MainWindow::on_save_file_triggered() {
    if (file_path_ != "") {
        QByteArray ba = file_path_.toLocal8Bit();
        const char *path = ba.data();
        inp_col->write_data(path);
    }
    else
        QMessageBox::warning(this, "Warning!", "Use Save As");
}

void MainWindow::on_save_file_as_triggered() {
    QString file_name = QFileDialog::getSaveFileName(this, "Open file");
    file_path_ = file_name;
    QByteArray ba = file_path_.toLocal8Bit();
    const char *path = ba.data();
    inp_col->write_data(path);
}

void MainWindow::on_but_get_clicked() {
    std::pair<double, double> coords;
    if (!inp_col->emp()) {
        coords = inp_col->coordinates();
        double x = coords.first;
        double y = coords.second;
        ui->lcd_x->display(x);
        ui->lcd_y->display(y);
    }
    else
        QMessageBox::warning(this, "Warning!", "No commands");
}

void MainWindow::on_but_count_clicked() {
    if (!inp_col->emp()) {
        int amount = inp_col->get_count();
        ui->lcd_count->display(amount);
    }
    else
        QMessageBox::warning(this, "Warning!", "No commands");
}

void MainWindow::on_but_del_clicked() {
    if (!inp_col->emp()) {
        int pos = ui->spin_box->value();
        if (pos <= inp_col->get_count())
            inp_col->del(pos);
        else
            QMessageBox::warning(this, "Warning", "The element doesn't exist");

        ui->text_edit->setText("");
        int i = 1;
        inp_col->iter_begin();
        std::cout<<"\nCommands:";
        QString line = "";
        while(inp_col->cur() != nullptr) {
            std::cout<<"\nElement " << i;
            std::cout<<"\n";
            line = inp_col->cur()->print_params();
            ui->text_edit->append(QString::number(i) + ". ");
            ui->text_edit->append(line);
            i++;
            inp_col->next();
        }
    }
    else
        QMessageBox::warning(this, "Warning!", "Nothing to delete");
}

void MainWindow::on_but_del_all_clicked() {
    if (!inp_col->emp()) {
        inp_col->del_all();
        ui->text_edit->setText("");
        ui->lcd_count->display(0);
        ui->lcd_x->display(0);
        ui->lcd_y->display(0);
    }
    else
        QMessageBox::warning(this, "Warning!", "Nothing to delete");
}

void MainWindow::on_but_madd_clicked() {
    bool ok_v, ok_t;
    double vel = (ui->line_vel->text()).toDouble(&ok_v);
    double time = (ui->line_mtime->text()).toDouble(&ok_t);
    if (ok_v && ok_t) {
        if ((vel > 0.) && (time > 0.)) {
            action* add = new motion(vel, time);
            const action* add_elem = const_cast<const action*>(add);
            inp_col->add(add_elem);
            ui->line_vel->clear();
            ui->line_mtime->clear();
            ui->text_edit->setText("");

            int i = 1;
            inp_col->reverse();
            std::cout<<"\nCommands:";
            QString line = "";
            inp_col->iter_begin();
            while(inp_col->cur() != nullptr) {
                std::cout<<"\nElement " << i;
                std::cout<<"\n";
                line = inp_col->cur()->print_params();
                ui->text_edit->append(QString::number(i) + ". ");
                ui->text_edit->append(line);
                i++;
                inp_col->next();
            }
            inp_col->reverse();
        }
        else
            QMessageBox::warning(this, "Warning!", "Wrong data");
    }
    else
        QMessageBox::warning(this, "Warning!", "Wrong data");
}

void MainWindow::on_but_radd_clicked() {
    bool ok_t, ok_r, ok_d;
    double time = (ui->line_rtime->text()).toDouble(&ok_t);
    double rad = (ui->line_rad->text()).toDouble(&ok_r);
    double dir = (ui->line_dir->text()).toDouble(&ok_d);
    if (ok_t && ok_r && ok_d) {
        if ((time > 0.) && (rad >= 0.) && (rad <= 180.) && (dir == 0 || dir == 1)) {
            action* add = new rotation(time, rad, dir);
            const action* add_elem = const_cast<const action*>(add);
            inp_col->add(add_elem);
            ui->line_rtime->clear();
            ui->line_rad->clear();
            ui->line_dir->clear();
            ui->text_edit->setText("");

            int i = 1;
            inp_col->reverse();
            std::cout<<"\nCommands:";
            QString line = "";
            inp_col->iter_begin();
            while(inp_col->cur() != nullptr) {
                std::cout<<"\nElement " << i;
                std::cout<<"\n";
                line = inp_col->cur()->print_params();
                ui->text_edit->append(QString::number(i) + ". ");
                ui->text_edit->append(line);
                i++;
                inp_col->next();
            }
            inp_col->reverse();
        }
        else
            QMessageBox::warning(this, "Warning!", "Wrong data");
    }
    else
        QMessageBox::warning(this, "Warning!", "Wrong data");
}

void MainWindow::on_about_triggered() {
    QMessageBox::about(this, "Information", "The program that allows to calculate the coordinates of a "
                                            "radio-controlled car based on commands received from the console.");
}

void MainWindow::on_author_triggered() {
    QMessageBox::about(this, "Information", "Sidorov Ivan\nBIV192(2)");
}
