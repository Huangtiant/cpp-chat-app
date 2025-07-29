#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "logindialog.h"  // 包含LoginDialog 类的头文件
#include "registerdialog.h"
/************************************************************
 * @file       ChatWindow.h
 * @brief      聊天主窗口
 *
 * @author     Tianze Huang
 * @date       2025-07-30
 * @version    1.0
 *
 * @copyright  MIT License
 *
 * @details
 *  - 包含 QTextEdit（输入框）、QTextBrowser（聊天记录显示）、
 *    QPushButton（发送按钮）等组件。
 *  - 初始化 UI 布局，绑定发送消息槽函数。
 *
 ************************************************************/

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void SlotSwitchReg();

private:
    Ui::MainWindow *ui;
    LoginDialog *_login_dlg;
    RegisterDialog* _reg_dlg;
};
#endif // MAINWINDOW_H
