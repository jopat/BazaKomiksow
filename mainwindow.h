#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQueryModel>
#include "SqLiteMaper.h"
#include "ConfigManager.h"

/** @file mainwindow.h
 * @brief GUI main window header file.
 *
 * A more extensive description of filename.ext.
 */

namespace Ui
{
    class MainWindow;
}

/** @brief A brief description of MainWindow.
 *
 * A more extensive description of MyClass.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /** \brief Constructor for MainWindow class.
     *
     * This constructor will perform a prerequisites operation for application, includeing:
     *      -# Read configuration file config.conf.
     *      -# Check if the database exists. If no, create it.
     *      -# Connect to the database.
     *
     * \param parent
     */
    explicit MainWindow(QWidget *parent = 0);


    ~MainWindow();

private:
    Ui::MainWindow      *ui;
    ConfigManager       *config;
    SqLiteMaper         *sqLiteMaper;

private slots:
    void on_pushButton_clicked();
    void on_actionO_Qt_triggered();
    void on_actionCreateDatabase_triggered();
};

#endif // MAINWINDOW_H
