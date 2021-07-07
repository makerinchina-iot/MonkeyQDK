#include "settingsdialog.h"
#include "ui_settingsdialog.h"

#include <QDebug>
#include <QPushButton>
#include <QDialogButtonBox>

#include <coreplugin/dialogs/ioptionspage.h>

using namespace Core;

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);

    //model dialog
    this->setModal(true);

    this->setWindowTitle("Options");

    //load settings page
    QList<IOptionsPage*> optionPages = IOptionsPage::allOptionsPages();

    foreach(IOptionsPage* page, optionPages){
        qDebug()<<" add setting page:"<<page->id()<<","<<page->category();

        ui->categoryList->addItem(page->id());
        ui->stackedWidget->addWidget(page->widget());
    }

    //current index changed
    connect(ui->categoryList,&QListWidget::currentRowChanged,this,&SettingsDialog::currentCategorySelected);

    ui->categoryList->setFocus();

    //button
    QDialogButtonBox *buttonBox = ui->buttonBox;
    connect(buttonBox->button(QDialogButtonBox::Apply), &QPushButton::clicked,this,&SettingsDialog::apply);
    connect(ui->buttonBox,&QDialogButtonBox::accepted,this,&SettingsDialog::accept);
    connect(ui->buttonBox,&QDialogButtonBox::rejected,this,&SettingsDialog::reject);

}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::currentCategorySelected(int index)
{
    qDebug()<<" current setting category:"<<index;

    ui->categoryName->setText(ui->categoryList->item(index)->text());

    ui->stackedWidget->setCurrentIndex(index);
}

void SettingsDialog::apply()
{
    foreach (IOptionsPage *page, IOptionsPage::allOptionsPages()) {
        page->apply();
    }

}

void SettingsDialog::accept()
{
    foreach (IOptionsPage *page, IOptionsPage::allOptionsPages()) {
        page->apply();
    }
    foreach (IOptionsPage *page, IOptionsPage::allOptionsPages()) {
        page->finish();
    }

    QDialog::done(QDialog::Accepted);
}

void SettingsDialog::reject()
{
    foreach (IOptionsPage *page, IOptionsPage::allOptionsPages()) {
        page->finish();
    }

    QDialog::done(QDialog::Rejected);
}
