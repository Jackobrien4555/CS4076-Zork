#ifndef WORDLE_H
#define WORDLE_H

#include <QDialog>

namespace Ui {
class Wordle;
}

class Wordle : public QDialog
{
    Q_OBJECT

public:
    explicit Wordle(QWidget *parent = nullptr);
    ~Wordle();

private:
    Ui::Wordle *ui;
};

#endif // WORDLE_H
