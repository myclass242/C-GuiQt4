/*--finddialog.h--*/
#ifndef FINDDIALOG_H
#define FINDDIALOG_H
#include <QDialog>
/*Qt中类的前向声明，会让编译速度更快*/
class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;
class FindDialog:public QDialog//FindDialog 从QDialog继承
{
    Q_OBJECT//宏定义，如果类中使用了signal或者slots就要声明这个宏
public:
    FindDialog(QWidget *parent = 0);//构造函数是Qt控件类的标准格式，默认的父参数为NULL ,说明没有父控件
signals:/*声明了这个对象发出两个信号，向前查找和向后查找信号.signal也是一个宏，编译之前，C++预处理把它变成标准的C++代码*/
    void findNext(const QString &str,Qt::CaseSensitivity cs);//Qt::CaseSensitivity是一个枚举类型，有两个值Qt::CaseSensitive,Qt::CaseInsensitive
    void findPrevious(const QString &str,Qt::CaseSensitivity cs);
private slots:/*slot和signal一样也是个宏。声明了两个slot函数，为了实现函数需要用到对话框的其他控件的信息，所以保存了一些控件的指针*/
    void findClicked();
    void enableFindButton(const QString &text);
private:/*对于私有成员变量，只是使用了指针，并没有存取操作，编译器不用知道它们的详细定义，所以使用了类的前项定义*/
    QLabel *label;
    QLineEdit *lineEdit;
    QCheckBox *caseCheckBox;
    QCheckBox *backwardCheckBox;
    QPushButton *findButton;
    QPushButton *closeButton;
};
#endif // FINDDIALOG_H
