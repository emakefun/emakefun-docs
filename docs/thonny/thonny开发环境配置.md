# 开发环境配置

## 一、下载安装Thonny

------

Thonny是一个免费、开源的软件平台，体积小，界面简单，操作简单，功能丰富，是一个适合初学者的Python IDE。在本教程中，我们使用 Thonny 这个IDE在整个实验课程过程中开发ESP32。Thonny支持多种操作系统，包括Windows, Mac OS, Linux。

### 1.1 Windows系统

（1）软件下载和开源代码库分享

- [Thonny的开源代码库](https://github.com/thonny/thonny)
- [Thonny软件官网](https://thonny.org/)（请根据您的操作系统选择相应的选项下载安装）

  下载好后，鼠标触碰到下图箭头所示处，会出现Windows官方下载的版本选择。请根据您的操作系统选择相应的版本下载。最好下载最新版，否则可能不支持ESP32。

![image6](pictures/image6.jpeg)

![image7](pictures/image7.jpeg)

（2）下载完成后，鼠标左键双击“thonny-4.0.2.exe”。出现“Select Setup Install Mode”对话框，选择“Install for all users”。你也可以选择“**Install for me only**”进行操作。

![image9](pictures/image9.jpeg)

（3）如果你不熟系电脑软件的安装，可以一直单击“**Next**”直至安装完成。

![image10](pictures/image10.jpeg)

（4）Thonny软件的安装路径。默认此安装路径继续下一步，单击“**Next**”。如果您想选择一个不同的文
件夹，请单击“**Browse...**”进行修改。

![image11](pictures/image11.jpeg)

（5）程序将在下面的开始菜单文件夹中创建程序的快捷方式。默认此文件夹继续下一步，单击“**Next**”。如果您想选择一个不同的文件夹，请单击“**Browse...**”。

![image12](pictures/image12.jpeg)

（6）选中“**Creak desktop icon**”，在桌面生成快捷方式。

![image13](pictures/image13.jpeg)

（7）单击“**Install**”安装软件。等待安装成功。

![image14](pictures/image14.jpeg)

（8）安装完成，单击“**Finish**”结束安装。

![image15](pictures/image15.jpeg)

### 1.2 Mac系统

鼠标触碰到下图箭头所示处，会出现MacOS的官方下载的版本选择。请根据您的操作系统选择相应的版本下载。最好下载最新版，否则可能不支持ESP32。

安装步骤请参考 **章节 1.1** 。

![image16](pictures/image16.jpeg)

## 二、 Thonny软件基本配置与介绍

### 2.1 Thonny软件基本配置

（1）双击桌面的Thonny软件图标 ，出现语言选择和初始设置界面。

![image19](pictures/image19.jpeg)

  Language 选择“**简体中文**”。然后单击“**Let's go!**”结束设置。

![image20](pictures/image20.jpeg)

![image21](pictures/image21.jpeg)

（2）单击“**视图**”，勾选“**Shell**”和“文件”

![image22](pictures/image22.jpeg)

### 2.2 Thonny软件的介绍

### （1）工具栏介绍

![image23](pictures/image23.jpeg)

| 按钮                              | 功能              |
| --------------------------------- | ----------------- |
| ![image24](pictures/image24.jpeg) | 新建              |
| ![image25](pictures/image25.jpeg) | 打开              |
| ![image26](pictures/image26.jpeg) | 保存              |
| ![image27](pictures/image27.jpeg) | 运行当前脚本      |
| ![image28](pictures/image28.jpeg) | 调试当前脚本      |
| ![image29](pictures/image29.jpeg) | 步过              |
| ![image30](pictures/image30.jpeg) | 步进              |
| ![image31](pictures/image31.jpeg) | 步出              |
| ![image32](pictures/image32.jpeg) | 恢复执行          |
| ![image33](pictures/image33.jpeg) | 停止/重启后端进程 |

### （2）界面介绍

![image34](pictures/image34.jpeg)

## 三、 安装驱动

参考[CH340驱动说明](https://docs.emakefun.com/CH340/CH340/)文档进行安装。



## 四、烧录固件

要在ESP32主板上运行Python程序，我们需要先将固件烧入到ESP32主板。

### 4.1 下载Micropython固件

- [microPython官方网站](http://micropython.org/)

- [microPython的ESP32固件](https://micropython.org/download/esp32/)   打开microPython的ESP32固件网址，下载固件。

  **注意：本教程以官网V1.20.0固件为示例，现已更新到“ESP32_GENERIC-20231005-v1.21.0”版本，增加了蓝牙下载功能，后期更新的固件以同样的方法进行烧录！！！**

![image48](pictures/image48.jpeg)

本教程中使用的固件是：**esp32-20230426-v1.20.0.bin** 。我们的资料中也提供了此版本的固件，路径如下图，另外**建议使用 V1.21版本固件**。

![image49](pictures/image49.jpeg)

### 4.2 烧录Micropython固件

（1）将ESP32主板通过Type-C线连接到计算机。

![image50](pictures/image50.jpeg)

（2）确保驱动程序已成功安装，并能正确识别COM端口。打开设备管理器并展开“端口”。（端口号不是固定的COM6，会有不同，是正常情况。）

![image51](pictures/image51.jpeg)

（3）打开Thonny，点击“**运行**” ，选择 “**配置解释器**”。

![image52](pictures/image52.jpeg)

在解释器页面，解释器选择“**Micropython (ESP32)**”，端口或WebREPL选择“**USB-SERIAL CH340 COM6）**”（COM号以你电脑的端口为准）。然后单击“安装或更新MicroPython”。

![image53](pictures/image53.jpeg)

弹出“ESP32 firmware installer”页面，“**Port**”下拉选择“**USB-SERIAL CH340（COM6）**”。“**Firmware**”单击“**Browse...**”，选择下载好的microPython固件 “**esp32-20230426-v1.20.0.bin**”。检查“**Flash mode**”是否选择了“**From image file(Keep)**”，“**Erase flash before installing**”是否勾选。最后，单击“**安装**”，等待安装完成提示。

![image54](pictures/image54.jpeg)

（4）安装完成，单击“**关闭**”。

![image55](pictures/image55.jpeg)

在“Thonny 选项”页面单击“**好的**”。

![image56](pictures/image56.jpeg)

（5）点击 “**停止/重启后端进程**”按钮。

![image58](pictures/image58.jpeg)

现在，一切准备工作都已就绪。

**注意：**由于Thonny版本不同，在烧录的第3步可能出现以下不能更新的情况。

![image53](pictures/image53.jpeg)

![image88](pictures/image88.jpeg)

出现这种情况，点击以下按钮就能出现正常界面。

![image89](pictures/image89.jpeg)

![image90](pictures/image90.jpeg)

然后参照3-5的步骤继续烧录固件。

## 五、测试

### 5.1 测试Shell命令

在“**Shell**”窗口中输入“**print('hello world**')”，然后按下**Enter**键。

![image61](pictures/image61.jpeg)

### 5.2 在线运行

ESP32需要连接到计算机时，是在线运行的。用户可以使用Thonny编写和调试程序。

（1）打开Tonny并单击![image62](pictures/image62.jpeg) ，然后单击“**此电脑**”。

![image63](pictures/image63.jpeg)

（2）在弹出的页面选择路径“**基础输入模块\01 HelloWorld\MicroPython**”下的“**lesson_01_HelloWorld.py**“Python 文件，然后单击”**打开**“。

![image64](pictures/image64.jpeg)

（3）单击![image65](pictures/image65.jpeg)或按下“F5”键，Shell窗口将打印出”**Hello World**“。

![image66](pictures/image66.jpeg)

**注意：**如果在线运行时，按下ESP32的复位键，用户的代码将不会再次执行。如果你希望在重置代码后自动运行该代码，请参考下面章节 **5.3 离线运行** 的内容。

### 5.3 离线运行

ESP32复位后，首先运行根目录下的boot.py文件，然后运行你的代码文件，最后进入“Shell”。因此，为了让ESP32在重置后执行用户程序，我们需要在boot.py中添加一个引导程序来执行用户代码。

（1）打开Thonny，在文件管理框单击“**此电脑\文件夹所在位置\sp32-iot-kit\基础输入模块\00 Boot\MicroPython 程序**”。

![image68](pictures/image68.jpeg)

（2）展开“**00 Boot**”，然后鼠标左键双击“**boot.py**”，使 “**MicroPython 设备**”中的程序能够离线运行。

![image69](pictures/image69.jpeg)

（3）如果想让编写的程序离线运行，需要上传我们提供的“**boot.py**”和你编写的程序代码到“**MicroPython 设备**”，然后按下ESP32的复位按键。
展开文件夹 00 Boot。右键单击“**boot.py**”，选择“**上传到/**”。

![image70](pictures/image70.jpeg)

![image71](pictures/image71.jpeg)

![image78-2](pictures/image78-2.jpeg)

单击“**确定**”。

![image72](pictures/image72.jpeg)

（4）同样，将“**lesson_01_HelloWorld.py**”上传到 “**MicroPython 设备**”。

![image73](pictures/image73.jpeg)

可以在 “**MicroPython 设备**”看到代码已成功上传。

![image74](pictures/image74.jpeg)

（6）按下ESP32的**Reset按键**，在Shell窗口中能看到代码被执行。

![image75 ](pictures/image75 .jpeg)





![image76](pictures/image76.jpeg)

## 六、Thonny常见的操作

### 6.1 上传代码到ESP32

为了方便起见，我们以**boot.py**为例。如果我们在每个代码目录中都添加了boot.py。ESP32每次重启时，它将首先执行根目录中的“**boot.py**”。

在00 Boot文件夹中选择“**boot.py**”，右键单击鼠标，选择“**Upload to** /”将代码上传到ESP32的根目录，然后选择“**确定**”。

![image78](pictures/image78.jpeg)

### 6.2 下载代码到电脑

在“**MicroPython 设备**”内选中“**boot.py**”，右键选择“**下载到 D:\代码**”把代码下载到你的电脑里。

![image79](pictures/image79.jpeg)

### 6.3 删除ESP32根目录下的文件

在“**MicroPython 设备**”内选中“**boot.py**”，右键单击它且选择“**删除**”，将“**boot.py**”从ESP32的根目录中删除。

![image80](pictures/image80.jpeg)

### 6.4 创建并保存代码

单击“**文件**”，然后选择“**新建**”。

![image82](pictures/image82.jpeg)

在新打开的文件中输写代码。

![image83](pictures/image83.jpeg)

单击菜单栏上的![image84](pictures\image84.jpeg) ,可以将代码保存到你的电脑或ESP32上。这里选择保存到“MicroPython 设备”。

![image85](pictures/image85.jpeg)

文件名命名为“**main.py**”，然后单击“**好的**”。

![image86](pictures/image86.jpeg)

代码已经上传到ESP32。

![image87](pictures/image87.jpeg)