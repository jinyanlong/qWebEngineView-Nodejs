#ifndef BRIDGE_H
#define BRIDGE_H

#include <QObject>

class bridge: public QObject
{
Q_OBJECT
public:
	static bridge* instance();
	void showMsgBoxx();
public slots:
	void showMsgBox();

private:
	explicit bridge(QObject *parent = nullptr);
};

#endif // BRIDGE_H
