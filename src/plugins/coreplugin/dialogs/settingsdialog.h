#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = nullptr);
    ~SettingsDialog();

private slots:
    void currentCategorySelected(int index);
    void apply();
    void accept() override;
    void reject() override;

private:
    Ui::SettingsDialog *ui;
};

#endif // SETTINGSDIALOG_H
