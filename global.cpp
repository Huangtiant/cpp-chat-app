#include "global.h"

/**
 * @brief repolish 是一个 lambda 函数，用于刷新某个 QWidget 的 QSS 样式
 *
 * - unpolish(): 撤销控件当前样式（断开 style）
 * - polish(): 重新对该控件应用 style（重新渲染）
 *
 * 使用这个函数可以强制刷新控件的样式，解决 QSS 在控件状态变化时不自动刷新的问题。
 */
std::function<void(QWidget*)> repolish = [](QWidget* w) {
    w->style()->unpolish(w);  // 撤销原有样式
    w->style()->polish(w);    // 重新应用样式
};
