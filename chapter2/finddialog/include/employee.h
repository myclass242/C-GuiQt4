#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <qobject.h>


class Employee : public QObject {
    Q_OBJECT
public:
    Employee() : mySalary(0) {}
    ~Employee() = default;

    int salary() const noexcept {
        return mySalary;
    }

public slots:
    void setSalary(int newSalary) {
        if (mySalary != newSalary) {
            mySalary = newSalary;
            emit changeSalary(newSalary);
        }
    }
signals:
    void changeSalary(int newSalary);
private:
    int mySalary;
};

#endif // EMPLOYEE_H
