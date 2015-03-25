#include <stdio.h>
#include <mruby.h>
#include <mruby/class.h>
#include <mruby/variable.h>
#include <mruby/array.h>
#include <mruby/string.h>
#include <mruby/data.h>
#include <mruby/variable.h>
#include <windows.h>

mrb_value
mrb_mouse_move_to(mrb_state *mrb, mrb_value self)
{
  mrb_int x, y;

  mrb_get_args(mrb, "ii", &x, &y);

  if(SetCursorPos(x, y))
    return mrb_true_value();
  else
    return mrb_false_value();
}

mrb_value
mrb_mouse_left_down(mrb_state *mrb, mrb_value self)
{
  mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
  return mrb_nil_value();
}

mrb_value
mrb_mouse_right_down(mrb_state *mrb, mrb_value self)
{
  mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
  return mrb_nil_value();
}

mrb_value
mrb_mouse_left_up(mrb_state *mrb, mrb_value self)
{
  mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
  return mrb_nil_value();
}

mrb_value
mrb_mouse_right_up(mrb_state *mrb, mrb_value self)
{
  mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
  return mrb_nil_value();
}

mrb_value
mrb_mouse_click(mrb_state *mrb, mrb_value self)
{
  mrb_value *argv;
  mrb_int argc;
  int iargc;

  mrb_get_args(mrb, "*", &argv, &argc);
  iargc = (int)argc;

  if(iargc == 2) {
    mrb_mouse_move_to(mrb, self);
  }
  mrb_mouse_left_down(mrb, self);
  mrb_mouse_left_up(mrb, self);
  return mrb_nil_value();
}

mrb_value
mrb_mouse_rclick(mrb_state *mrb, mrb_value self)
{
  mrb_mouse_right_down(mrb, self);
  mrb_mouse_right_up(mrb, self);
  return mrb_nil_value();
}

mrb_value
mrb_mouse_dblclick(mrb_state *mrb, mrb_value self)
{
  mrb_mouse_click(mrb, self);
  mrb_mouse_click(mrb, self);
  return mrb_nil_value();
}

mrb_value
mrb_mouse_drag_start(mrb_state *mrb, mrb_value self)
{
  mrb_mouse_move_to(mrb, self);
  mrb_mouse_left_down(mrb, self);
  return mrb_nil_value();
}

void
mrb_mruby_win_mouse_gem_init(mrb_state* mrb) {
  struct RClass *modzz;

  modzz = mrb_define_module(mrb, "Mouse");

  mrb_define_class_method(mrb, modzz, "move_to",            mrb_mouse_move_to,    MRB_ARGS_REQ(2));
  mrb_define_class_method(mrb, modzz, "left_down",          mrb_mouse_left_down,  MRB_ARGS_NONE());
  mrb_define_class_method(mrb, modzz, "left_up",            mrb_mouse_left_up,    MRB_ARGS_NONE());
  mrb_define_class_method(mrb, modzz, "right_down",         mrb_mouse_right_down, MRB_ARGS_NONE());
  mrb_define_class_method(mrb, modzz, "right_up",           mrb_mouse_right_up,   MRB_ARGS_NONE());
  mrb_define_class_method(mrb, modzz, "click",              mrb_mouse_click,      MRB_ARGS_REQ(2));
  mrb_define_class_method(mrb, modzz, "right_click",        mrb_mouse_rclick,     MRB_ARGS_NONE());
  mrb_define_class_method(mrb, modzz, "double_click",       mrb_mouse_dblclick,   MRB_ARGS_NONE());
  mrb_define_class_method(mrb, modzz, "drag_start",         mrb_mouse_drag_start, MRB_ARGS_REQ(2));
  mrb_define_class_method(mrb, modzz, "drag_end",           mrb_mouse_left_up,    MRB_ARGS_NONE());
}

void
mrb_mruby_win_mouse_gem_final(mrb_state* mrb) {
}

