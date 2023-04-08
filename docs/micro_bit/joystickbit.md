# Joystick:Bit
[English](README.md) 中文版

Joystick:Bit为   [深圳市易创空间科技有限公司](www.emakefun.com)出品的针对micro:bit开发的无线可编程手柄，支持micro:Bit V1、 V2; **MakeCode扩展链接为**: **https://github.com/emakefun/pxt-joystickbit** 

#### **[淘宝链接](https://item.taobao.com/item.htm?spm=a1z10.5-c.w4002-21556097795.24.720864faiazDSE&id=650591965479)**

![image](joystickbit/joystickbit.jpg)

## 特点

- 左右双摇杆

- 手柄扩展Micro:Bit A，B按键

- 左右可独立编程按键

- 板子蜂鸣器和震动电机

- 2节7号电池供电

- 1个PH2.0-4Pin i2c接口 

  

## 图像化编程块说明
   - 《游戏手柄摇杆获取 左/右侧 x/y轴 的值》:该模块用于获取手柄左或者右摇杆x轴或者y轴方向的坐标值，其获取的值为数值类型，其值可以通过‘显示数字’模块显示在Micro:Bit板上
   - 《游戏手柄震动频率()》 :该模块用于调试游戏手柄上震动电机的震动频率，其值为0时震动电机停止震动。
   - 《按键 L/R/左摇杆按键/右摇杆按键 是否是 按下/释放 状态》 :该模块用于判断游戏手柄左右按键和摇杆中心按键是否按下或者释放，是返回ture,否返回false，作用于判断模块（如果...则执行...）
   - 《游戏手柄按键 L/R/左摇杆按键/右摇杆按键 是否被按下》 :该模块用于判断手柄上按钮是否按下，是返回ture,否返回false。
   - 《游戏手柄按键 L/R/左摇杆按键/右摇杆按键 是否被释放》 :该模块用于判断手柄按键是否未按住，是返回ture,否返回false。

   ![image](joystickbit/1.jpg)

   - 下面的组合模块的含义:
     - 模块代码成功下载到Micro:Bit上后，Micro:Bit的LED显示屏显示数字爱心，之后持续获取并显示左侧摇杆的x轴坐标。当按下L键时，振动电机以500HZ的频率开始震动，当释放按钮L时，振动电机停止震动。当按下R键时，板载蜂鸣器以500HZ的频率开始工作，当释放按钮R时，板载蜂鸣器停止工作。

   ![image](joystickbit/000.jpg)


### 摇杆图形化块

- 获取游戏手柄摇杆x/y轴值（获取左/右侧x/y轴的值并将其数值通过LED显示屏显示出来）

   ![image](joystickbit/11.jpg)

   ![image](joystickbit/12.jpg)


### 独立按键编程图形块

- 按键 L/R/左摇杆按键/右摇杆按键 是否是 按下/释放 状态
- 下面模块是对按键状态进行一个判断：当你按了按键L，则显示字符串"Hello!"

   ![image](joystickbit/21.jpg)

   ![image](joystickbit/22.jpg)

- 同理，下面两个模块也是对按键的按下或者未按进行一个判断，为真则显示字符串"Hello!"

   ![image](joystickbit/23.jpg)

   ![image](joystickbit/24.jpg)


### 震动电机编程图形块

- 游戏手柄震动频率模块可以调试震动电机的震动频率

   ![image](joystickbit/31.jpg)

- 配合按键使用: 当你按下L键时，震动电机开始工作，频率为137HZ。当你释放按键L时，震动电机停止工作。

   ![image](joystickbit/32.jpg)


### 板载蜂鸣器编程图形块

- 游戏手柄板载蜂鸣器振动频率模块可以调试板载蜂鸣器的振动频率

   ![image](joystickbit/41.jpg)

- 配合按键使用: 当你按下L键时，板载蜂鸣器开始工作，频率为516HZ，当你释放按键L时，板载蜂鸣器频率为0停止工作。

  ![image](joystickbit/43.jpg)


### python支持

- 获取游戏手柄摇杆 x 或 y 轴值

  - 功能语句:

    > joystick.get_rocker_x_axis_value(rocker) # 获取游戏手柄摇杆 x 轴值
    > joystick.get_rocker_y_axis_value(rocker) # 获取游戏手柄摇杆 y 轴值

  - 使用例程:
    > joystick.get_rocker_x_axis_value(joystick.ROCKER_LEFT) # 获取游戏手柄左边摇杆 x 轴值，返回数值范围 0~255，对应摇杆从左往右的位置
    > joystick.get_rocker_y_axis_value(joystick.ROCKER_LEFT) # 获取游戏手柄左边摇杆 y 轴值，返回数值范围 0~255，对应摇杆从下往上的位置
    > joystick.get_rocker_x_axis_value(joystick.ROCKER_RIGHT) # 获取游戏手柄右边摇杆 x 轴值，返回数值范围 0~255，对应摇杆从左往右的位置
    > joystick.get_rocker_y_axis_value(joystick.ROCKER_RIGHT) # 获取游戏手柄右边摇杆 y 轴值，返回数值范围 0~255，对应摇杆从下往上的位置

```
# 获取游戏手柄左边摇杆的x值并将其数值通过LED显示屏显示出来
from microbit import *
from input import joystick

while True:
  x = joystick.get_rocker_x_axis_value(joystick.ROCKER_LEFT) # 获取游戏手柄左边摇杆x轴值赋值给变量x
  display.scroll(x)
```

- 按键 L/R/左摇杆按键/右摇杆按键 是否是 按下/释放/弹起/单击/双击/空闲 等状态

  - 功能语句:

    > joystick.get_button_state(button) # 获取手柄上按键的状态
    > 返回值：
    > joystick.BUTTON_STATE_PRESSED: 按键按下
    > joystick.BUTTON_STATE_RELEASED: 按键弹起
    > joystick.BUTTON_STATE_SINGLE_CLICK: 按键单击
    > joystick.BUTTON_STATE_DOUBLE_CLICK: 按键双击
    > joystick.BUTTON_STATE_PRESS_AND_HOLD: 按键长按
    > joystick.BUTTON_STATE_BUTTON_STATE_IDLE: 按键空闲
    > joystick.BUTTON_STATE_UNKNOWN: 获取按键状态失败，比如未连接手柄等

  - 使用例程:
    > joystick.get_button_state(joystick.BUTTON_ROCKER_LEFT) # 获取游戏手柄左边摇杆按键状态
    > joystick.get_button_state(joystick.BUTTON_ROCKER_RIGHT) # 获取游戏手柄右边摇杆按键状态
    > joystick.get_button_state(joystick.BUTTON_LEFT) # 获取游戏手柄左边按键 L 状态
    > joystick.get_button_state(joystick.BUTTON_RIGHT) # 获取游戏手柄右边按键 R 状态

```
# 判断游戏手柄左边摇杆按键是否按下，如果按下则显示1，没有则显示0
from microbit import *
from input import joystick

while True:
  if joystick.BUTTON_STATE_PRESSED == joystick.get_button_state(joystick.BUTTON_ROCKER_LEFT):
    display.show(1)
  else:
    display.show(0)
```

## 开源许可
MIT

## 联系我们

**技术 + 合作：TEL:  13242991035(WX同号)**