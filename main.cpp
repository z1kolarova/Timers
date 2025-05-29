#include <QCoreApplication>
#include <QTimer>
#include <QObject>

#include <iostream>

class TimerObject : public QObject {
public:
    TimerObject() {
        startTimer(500);
    }

protected:
    virtual void timerEvent(QTimerEvent *evt) {
        Q_UNUSED(evt);
        std::cout << "Object tick!" << std::endl;
    }
};

void onTimer() {
    std::cout << "Tick!" << std::endl;
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, onTimer);
    timer.start(1000);

    TimerObject timer2;

    QTimer timer3;
    QObject::connect(&timer3, &QTimer::timeout, [](){std::cout << "Lambda tick!" << std::endl;});
    timer3.setSingleShot(true);
    timer3.start(3000);

    return a.exec();
}
