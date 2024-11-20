#include <QtGui>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QHBoxLayout>


#include "include/finddialog.h"

FindDialog::FindDialog(QWidget *parent)
    : QDialog(parent)
{
    // 字符串周围的tr()函数调用是把它们翻译成其他语言的标记。
    // "&"符号表示快捷键，下面可以用(Alt+W)激活
    label = new QLabel(tr("Find &what:"));
    lineEdit = new QLineEdit;
    // 伙伴“Buddy”，在按下快捷键时可以接收焦点
    label->setBuddy(lineEdit);

    caseCheckBox = new QCheckBox(tr("Match &case"));
    backwardCheckBox = new QCheckBox(tr("Search &backward"));
    // "&"符号表示快捷键，下面可以用(Alt+F)激活
    findButton = new QPushButton(tr("&Find"));
    // Default按钮就是按下Enter键时对应的按钮
    findButton->setDefault(true);
    findButton->setEnabled(false);

    closeButton = new QPushButton(tr("Close"));

    connect(lineEdit, SIGNAL(textChanged(const QString &)),
            this, SLOT(enableFindButton(const QString &)));
    connect(findButton, SIGNAL(clicked()),
            this, SLOT(findClicked()));
    connect(closeButton, SIGNAL(clicked()),
            this, SLOT(close()));

    QHBoxLayout *topLeftLayout = new QHBoxLayout;
    topLeftLayout->addWidget(label);
    topLeftLayout->addWidget(lineEdit);

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addLayout(topLeftLayout);
    leftLayout->addWidget(caseCheckBox);
    leftLayout->addWidget(backwardCheckBox);

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(findButton);
    rightLayout->addWidget(closeButton);
    rightLayout->addStretch();

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
    setLayout(mainLayout);

    setWindowTitle(tr("Find"));
    setFixedHeight(sizeHint().height());
}

void FindDialog::findClicked()
{
    QString text = lineEdit->text();
    Qt::CaseSensitivity cs =
        caseCheckBox->isChecked() ? Qt::CaseSensitive
                                  : Qt::CaseInsensitive;
    if (backwardCheckBox->isChecked()) {
        emit findPrevious(text, cs);
    } else {
        emit findNext(text, cs);
    }
}

void FindDialog::enableFindButton(const QString &text)
{
    findButton->setEnabled(!text.isEmpty());
}

