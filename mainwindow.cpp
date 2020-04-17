#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QQmlApplicationEngine>
#include <QWebEngineView>
#include <QStackedLayout>
#include <QWebChannel>
#include "bridge.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	m_view = new QWebEngineView(this);
	QWebChannel *channel = new QWebChannel(this);
	channel->registerObject("bridge", (QObject*)bridge::instance());
	m_view->page()->setWebChannel(channel);
	m_view->page()->load(QUrl("http://127.0.0.1:8889"));
//	m_view->page()->load(QUrl(QString("/home/jyl/jyl-work/code/WXAK-V1/qt-app/monitor/views/engine.html")));


	ui->viewLayout->addWidget(m_view);
	connect(ui->pbAlert, &QPushButton::clicked, [this]() {
		m_view->page()->runJavaScript("showAlert()");
	});

}

MainWindow::~MainWindow()
{
	delete ui;
}
