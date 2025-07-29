#ifndef GLOBAL_H
#define GLOBAL_H

#include <QWidget>         // QWidget 基类
#include <functional>      // 用于声明 std::function
#include <QRegularExpression>
#include <QStyle>          // Qt 样式系统支持

/**
 * @brief repolish 用来刷新 QSS 样式
 *
 * Qt 的样式（styleSheet/QSS）在部分控件动态变化后不会自动刷新。
 * repolish 可用于手动取消并重新应用当前 style，从而触发样式更新。
 *
 * 使用方式：repolish(widget); 会刷新该控件的样式。
 */
extern std::function<void(QWidget*)> repolish;

#endif // GLOBAL_H
