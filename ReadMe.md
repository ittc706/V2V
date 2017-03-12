# version_2017_1_17(完成了v2v初版调试)

# version_2017_1_13(赶进度)

# version_2017_1_13(继续赶进度)

# version_2017_1_13(赶进度)

# version_2017_1_12(增加tmc配置文件)

# version_2017_1_12(增加wt)
* wt实现尚未完成

# version_2017_1_12(增加内容，增强结构)
* 新增配置对象，各个对象独立生成，依赖关系的注入交给容器来完成

# version_2017_1_12(增加event、tmc等类)
* 尚未完成

# version_2017_1_12(修改)

# version_2017_1_11(修改)

# version_2017_1_10(将撒点函数挪到system中)

# version_2017_1_10(写了个简单的容器)

# version_2017_1_10(修改)

# version_2017_1_10(增加系统控制类)

# version_2017_1_7(增加了vue的层级结构)

# version_2017_1_3(修改了矩阵类库的命名规则)

# version_2017_2_25(调整)
* 修复了一处bug:receive的pattern_idx没有赋值
* 调整了容器初始化的顺序
* 增加了urban的配置文件

# version_2017_2_25(小bug)

# version_2017_2_25(调整)
* 将global_config中的刷新时间删除，将gtt_config_highspeed/urban中的刷新时间从单位s改为单位TTI

# version_2017_2_25(debug)
* 输出文件的路径问题，Linux平台会有问题

# version_2017_2_28(添加了城镇模型下的撒点以及信道计算)

# version_2017_2_28(debug)

# version_2017_3_5(调整)
* 判断pl的大小来决定是否计算信道响应

# version_2017_3_5(调整)
* 更改了信道计算方式
* 有效版本号：6a63afb

# version_2017_3_7(增加资源选择算法)

# version_2017_3_7(debug)

# version_2017_3_12(增加时分复用)
* 车辆的physics层增加slot_time_idx字段
* sender_event和receiver_event各自增加判断给定tti是否为可传输时隙的方法(is_transmit_time_slot(tti))，其中receiver_event的该方法会回调它所对应的sender_event的该方法
* sender_event增加slot_time_idx字段
* 修改vue_network中的数据结构，存放给定pattern的所有发送事件，而非给定pattern的所有车辆id
* 地理位置尚未更新slot_time_idx字段
* 下一步：将信道更新模块抽象出来(将其与当前v2v项目解耦，便于其他项目调用)，为该模块添加适配v2v的适配器

# version_2017_3_12(增加选择算法)
* 将车辆link_level的receive方法删除，接收逻辑放到receiver_event的receive方法中
* sender_event增加与数据包相关的字段，并删除receiver_event中与数据包相关的字段
* 增加receiver_event中的丢包字段


