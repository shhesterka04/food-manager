#ifndef CONSTRUCTOR_H
#define CONSTRUCTOR_H

#include <QWidget>

namespace Ui {
class Constructor;
}

class Constructor : public QWidget
{
    Q_OBJECT

public:
    explicit Constructor(QWidget *parent = nullptr);
    ~Constructor();

private slots:
    void on_Update_info_clicked();

    void on_Log_out_clicked();

private:
    Ui::Constructor *ui;
    QWidget *parent;
};

#endif // CONSTRUCTOR_H
