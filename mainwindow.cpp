#include "mainwindow.h"
#include "./ui_mainwindow.h"

/**
 * @brief 构造函数：初始化主窗口
 *
 * - 创建并显示登录窗口 LoginDialog
 * - 设置登录窗口为中央窗口
 * - 建立注册窗口切换信号连接
 * - 设置登录与注册窗口为无边框模式
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);  // 加载 UI 布局（若 .ui 文件中包含控件布局则一并加载）

    _login_dlg = new LoginDialog(this);      // 创建登录窗口（传入主窗口为父对象）
    setCentralWidget(_login_dlg);            // 设置登录窗口为主窗口的中央控件

    // ❗【义项说明】
    // 由于 setCentralWidget(_login_dlg) 已将登录窗口嵌入主窗口并负责显示，
    // 所以此时不需要单独调用 _login_dlg->show()；
    // 若你调用 show()，等于尝试把它单独作为一个顶层窗口弹出，反而造成重复显示或布局错乱。
    //_login_dlg->show();

    // 信号槽连接：当登录窗口发出 switchRegister 信号时，调用主窗口的切换槽函数
    connect(_login_dlg, &LoginDialog::switchRegister, this, &MainWindow::SlotSwitchReg);

    _reg_dlg = new RegisterDialog(this);     // 创建注册窗口（预加载）
    _reg_dlg->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);  // 设置注册窗口为无边框
    _reg_dlg->hide();                        // 初始化时隐藏注册窗口

    _login_dlg->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);  // 设置登录窗口为无边框
}

/**
 * @brief 析构函数：释放资源
 *
 * - 删除 UI 指针
 * - 安全释放登录窗口与注册窗口
 */
MainWindow::~MainWindow()
{
    delete ui;

    if (_login_dlg) {
        delete _login_dlg;
        _login_dlg = nullptr;
    }

    if (_reg_dlg) {
        delete _reg_dlg;
        _reg_dlg = nullptr;
    }
}

/**
 * @brief 槽函数：处理从登录窗口跳转到注册窗口
 *
 * - 切换中央控件为注册窗口
 * - 隐藏登录窗口，显示注册窗口
 */
void MainWindow::SlotSwitchReg()
{
    setCentralWidget(_reg_dlg);  // 将注册窗口设为中央控件
    _login_dlg->hide();          // 隐藏登录窗口（非必要，但可防止后续误显示）
    _reg_dlg->show();            // 显示注册窗口
}
