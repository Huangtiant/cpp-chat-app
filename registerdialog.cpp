#include "registerdialog.h"
#include "ui_registerdialog.h"
#include "global.h"  // 引入全局样式刷新 repolish 工具函数

/**
 * @brief RegisterDialog 构造函数
 *
 * - 初始化注册对话框 UI
 * - 设置密码输入框为“密码模式”，输入字符隐藏
 * - 设置提示标签的初始状态属性为 normal
 * - 使用 repolish 刷新提示标签样式（以应用 QSS）
 */
RegisterDialog::RegisterDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);  // 加载 UI 组件（registerdialog.ui）

    // 设置密码框为密文显示
    ui->pass_edit->setEchoMode(QLineEdit::Password);
    ui->confirm_edit->setEchoMode(QLineEdit::Password);

    // 设置错误提示标签的自定义属性 state = "normal"
    // 这个属性可用于 QSS 中匹配样式
    ui->err_tip->setProperty("state", "normal");

    // 强制刷新 err_tip 的样式，确保属性变更后 QSS 生效
    repolish(ui->err_tip);
}

/**
 * @brief RegisterDialog 析构函数
 *
 * 释放 UI 资源
 */
RegisterDialog::~RegisterDialog()
{
    delete ui;
}

void RegisterDialog::on_getcode_button_clicked()
{
    auto email = ui->email_edit->text();
    // 2. 定义邮箱正则表达式（常用表达式）
    QRegularExpression regex(R"([A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,})");
    bool match = regex.match(email).hasMatch();
    if(match) {
        // 发送验证码
    } else {
        showTip(tr("邮箱地址格式错误"), false);
    }
}

void RegisterDialog::showTip(QString str, bool b_ok)
{
    if(b_ok) {
        ui->err_tip->setProperty("state","normal");
    } else {
        ui->err_tip->setProperty("state","err");
    }
    ui->err_tip->setText(str);

    repolish(ui->err_tip);
}

