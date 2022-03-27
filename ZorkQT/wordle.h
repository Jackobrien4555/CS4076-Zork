#ifndef WORDLE_H
#define WORDLE_H
#include <QDialog>
#include <iostream>
#include <string>
#include <fstream>

using std::string;
using std::vector;
namespace Ui {
class Wordle;
}

class Wordle : public QDialog
{
    Q_OBJECT

public:
    explicit Wordle(QWidget *parent = nullptr);
    ~Wordle();

private slots:


    void on_Quit_clicked();

    void on_Enter_clicked();

private:
    Ui::Wordle *ui;
      //static void initWords(string filename);
};

#endif // WORDLE_H
